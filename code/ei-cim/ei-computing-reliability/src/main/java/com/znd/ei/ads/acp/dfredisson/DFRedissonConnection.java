package com.znd.ei.ads.acp.dfredisson;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisADF.ADFService.ADFService;
import com.ZhongND.RedisADF.ADFService.ADFServiceEntry;
import com.ZhongND.RedisADF.rmdb.RedisMemDB;
import com.ZhongND.RedisADF.rmdb.Impl.RedisMemDBException;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.Service.RedisService;
import com.ZhongND.RedisDF.Service.ServiceFactory;
import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.exectueDF.ExectueDF;
import com.ZhongND.RedisDF.exectueDF.ResultObject;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBList;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.ZhongND.RedisDF.messageDF.Listener.MessageContent;
import com.ZhongND.RedisDF.messageDF.Listener.Event.EventCallBack;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.BusOperations;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.DBOperations;
import com.znd.ei.ads.acp.ListOperations;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.RedisDBData;
import com.znd.ei.ads.apl.AppTemplate;

public class DFRedissonConnection implements ConnectionFactory {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(DFRedissonConnection.class);

	private RedisService redisService;
	private DFService dfService;
	private ADFService adfService;

	public DFRedissonConnection() {

		try {
			this.redisService = ServiceFactory.getService();
			this.adfService = ADFServiceEntry.getADFService();
			this.dfService = redisService.getDFService();

		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private class DBOperationsImp extends DBOperations {

	
		@Override
		public void write(RedisDBData db) throws ACPException {
			if (dfService == null)
				return;

			RedisMemDB memdb = null;
			try {
				memdb = adfService.registry(db.getAppName());

			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to adf registy : "
						+ e.getMessage());
			} finally {
				if (memdb != null)
					memdb.closeClinet();
			}

			try {
				memdb.uploadModel(db.getName());
				memdb.pubMessage(db.getCode(), db.getName());
			} catch (RedisMemDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to upload model : "
						+ e.getMessage());
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to upload model : "
						+ e.getMessage());
			} finally {
				memdb.closeClinet();
			}

		}

		@Override
		public RedisDBData read(RedisDBData db) throws ACPException {
			if (adfService == null)
				return null;
			
			RedisMemDB memdb = null;
			try {
				memdb = adfService.registry(db.getAppName());

			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException("ADFService.registy : " + e.getMessage());
			} finally {
				if (memdb != null)
					memdb.closeClinet();
			}

			try {
				memdb.downloadModel(db.getName());
			} catch (RedisMemDBException e) {
				e.printStackTrace();
				throw new ACPException("RedisMemDB.downloadModel : "
						+ e.getMessage());
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException("RedisMemDB.downloadModel : "
						+ e.getMessage());
			} finally {
				memdb.closeClinet();
			}
			
			return db;

		}


	}

	private class ListOperationsImp extends ListOperations {

		private ExectueDF redisControl;
		private RedissonDBList list;
		
		@Override
		public ListData read(ListData data) throws ACPException {
			// TODO Auto-generated method stub
						
			try {
				redisControl = dfService.registry(data.getAppName());
				list = redisControl.RedissonDBList();
				data.setOperation(this);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			return data;
		}

		@SuppressWarnings("unchecked")
		@Override
		public void write(ListData data) throws ACPException {
			Map<String, List<String>> objMap = new HashMap<String, List<String>>();
			objMap.put(data.getName(), data.getContent());
			ExectueDF redisControl = null;
			RedissonDBList list = null;

			try {
				redisControl = dfService.registry(data.getAppName());
				list = redisControl.RedissonDBList();
				list.BatchRPUSH(objMap);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to list.BatchRPUSH : "
						+ e.getMessage());
			} finally {
				if (list != null)
					list.closedSyncControlClient();
			}
			list.closedSyncControlClient();

			RedissonPubManager msgBroker = redisControl.RedissonPubManager();
			String strMessage = msgBroker.setMessage(data.getCode(),
					data.getName());
			try {
				msgBroker.pubMessage(strMessage);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(
						"Fail to RedissonPubManager.setMessage : "
								+ e.getMessage());
			} finally {
				if (msgBroker != null)
					msgBroker.closed();
			}
		}

		@Override
		public String lpop(String key) throws ACPException {
			ResultObject<String, String> rt = null;
			try {
				if ((rt =  list.LPOP(key)) != null) {
					String str = rt.getValue();
					return str;					
				}
				return null;
			} catch (RedissonDBException e) {
				throw new ACPException(e.getMessage());
			}
		}

		@Override
		public void close() throws ACPException {
			if (list != null)
				list.closedSyncControlClient();
		}

	}

	private class BusOperationsImp implements BusOperations {

		@Override
		public void sendMessage(String contentCode, String content,
				String appName) {
			ExectueDF exetueDF = null;
			try {
				exetueDF = dfService.registry(appName);
			} catch (RedissonDBException e) {
				e.printStackTrace();
				return;
			}
			RedissonPubManager msg = exetueDF.RedissonPubManager();
			String strMessage = msg.setMessage(contentCode, content);
			try {
				msg.pubMessage(strMessage);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				msg.closed();
			}
		}

	}



	public ExectueDF createControl() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public DBOperations getDBOperations() {
		return new DBOperationsImp();
	}

	@Override
	public ListOperations getListOperations() {
		// TODO Auto-generated method stub
		return new ListOperationsImp();
	}

	public DFService getDfService() {
		return dfService;
	}

	public void setDfService(DFService dfService) {
		this.dfService = dfService;
	}

	@Override
	public BusOperations getBusOperations() {
		return new BusOperationsImp();
	}

	@Override
	public void register(DataFieldStorage storage) {
		try {
			dfService.registry(new EventCallBack() {
				@Override
				public void CallBack(int number, MessageContent eventContent) {
					LOGGER.info("Number:"+number+",收到事件:" + eventContent.getControlCode() + "  "
							+ eventContent.getEventContent());
					storage.receivedMessage(eventContent.getControlCode(), eventContent.getEventContent());				
				}
			}, false);
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}

}
