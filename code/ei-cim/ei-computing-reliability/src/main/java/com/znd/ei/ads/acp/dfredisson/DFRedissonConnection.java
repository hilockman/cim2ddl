package com.znd.ei.ads.acp.dfredisson;

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
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBMap;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBString;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.ZhongND.RedisDF.messageDF.Listener.MessageContent;
import com.ZhongND.RedisDF.messageDF.Listener.Event.EventCallBack;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.BusOperations;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.MemDbOperations;
import com.znd.ei.ads.acp.StringDataOperations;
import com.znd.ei.ads.acp.StringRefDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.adf.StringRefData;

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

	private class MemDbOperationsImp extends MemDbOperations {

	
		@Override
		public void write(MemDBData db) throws ACPException {
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
		public MemDBData read(MemDBData db) throws ACPException {
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
	
	
	
	public class MapDataOperationsImp extends MapDataOperations {
		private ExectueDF redisControl;
		private RedissonDBMap operation;
		
		@Override
		public MapData read(MapData data) throws ACPException,
				UnsupportedOperation {
			try {
				redisControl = dfService.registry(data.getAppName());
				operation = redisControl.RedissonDBMap();
				data.setOperation(this);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			return data;
		}

		@Override
		public void write(MapData data) throws ACPException, UnsupportedOperation {


			try {
				redisControl = dfService.registry(data.getAppName());
				operation = redisControl.RedissonDBMap();
				operation.LockHMSET(data.getName(), data.getContent());
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to map.LockHMSET : "
						+ e.getMessage());
			} finally {
				if (operation != null)
					operation.closed();
			}
			operation.closed();

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
		public String get(String key, String mkey) throws ACPException,UnsupportedOperation {
			if (operation != null) {
				try {
					ResultObject<String, String> rt = operation.LockHGET(key, mkey);
					if (rt != null)
						return rt.getValue();
					
					return null;
				} catch (RedissonDBException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					throw new ACPException(e.getMessage());
				}
			} else
				return null;
		}

		@Override
		public void close() {
			if (operation != null) {
				operation.closed();
			}
		}

	}

	private class ListDataOperationsImp extends ListDataOperations {

		private ExectueDF redisControl;
		private RedissonDBList operation;
		
		@Override
		public ListData read(ListData data) throws ACPException {
			// TODO Auto-generated method stub
						
			try {
				redisControl = dfService.registry(data.getAppName());
				operation = redisControl.RedissonDBList();
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
			ExectueDF redisControl = null;
			RedissonDBList list = null;

			try {
				redisControl = dfService.registry(data.getAppName());
				list = redisControl.RedissonDBList();
				list.LockRPUSH(data.getName(), data.getContent());
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to list.BatchRPUSH : "
						+ e.getMessage());
			} finally {
				if (list != null)
					list.closed();
			}
			list.closed();

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
				if ((rt =  operation.LockLPOP(key)) != null) {
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
			if (operation != null)
				operation.closed();
		}

	}
	
	public class StringRefOperationsImp extends StringRefDataOperations {


		@Override
		public StringRefData read(StringRefData o) throws ACPException,
				UnsupportedOperation {
			
			try {
				ExectueDF redisControl = dfService.registry(o.getAppName());
				RedissonDBString rstr = redisControl.RedissonDBString();
				ResultObject<String, String> rt = rstr.GET(o.getName());
				if (rt != null)
					o.setContent(rt.getValue());
				
				if (rstr != null)
					rstr.closed();
				
				return o;
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			} 
		}

		@Override
		public void write(StringRefData o) throws ACPException,
				UnsupportedOperation {
			try {
				ExectueDF redisControl = dfService.registry(o.getAppName());
				RedissonDBString rstr = redisControl.RedissonDBString();
				rstr.LockSET(o.getName(), o.getContent());
				rstr.closed();
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			}
		}

	}
	private class DefaultSimpleOperationsImp extends StringDataOperations {

		@Override
		public StringData read(StringData o) throws ACPException,UnsupportedOperation {
				return o;
		}

		@Override
		public void write(StringData o) throws ACPException,UnsupportedOperation {
			throw new UnsupportedOperation();
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
	public MemDbOperations getMemDBOperations() {
		return new MemDbOperationsImp();
	}

	@Override
	public ListDataOperations getListOperations() {
		// TODO Auto-generated method stub
		return new ListDataOperationsImp();
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
					try {
						storage.receivedMessage(eventContent.getControlCode(), eventContent.getEventContent());
					} catch (ACPException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (UnsupportedOperation e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}				
				}
			}, false);
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}

	@Override
	public StringDataOperations getStringDataOperations() {
		// TODO Auto-generated method stub
		return new DefaultSimpleOperationsImp();
	}

	@Override
	public StringRefDataOperations getStringRefOperations() {
		// TODO Auto-generated method stub
		return new StringRefOperationsImp();
	}

	@Override
	public MapDataOperations getMapDataOperations() {
		// TODO Auto-generated method stub
		return new MapDataOperationsImp();
	}

}
