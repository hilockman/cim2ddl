package com.znd.ei.ads.acp.dfredisson;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;

import com.ZhongND.RedisADF.ADFService.ADFService;
import com.ZhongND.RedisADF.ADFService.ADFServiceEntry;
import com.ZhongND.RedisADF.rmdb.MemDBContext;
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
import com.znd.ei.ads.ServerProperties;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.MemDBDataOperations;
import com.znd.ei.ads.acp.StringDataOperations;
import com.znd.ei.ads.acp.StringRefDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.adf.StringRefData;

public class DFRedissonConnection extends AbstractConnectionFactory {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(DFRedissonConnection.class);

	private RedisService redisService;
	private DFService dfService;
	private ADFService adfService;
	private ExectueDF executeDF;

	//private String modelZone = "test";
	
	@Autowired
	private ServerProperties serverProperties;
	
	@Value("${ads.defaultlifecycle}")
	private  long defaultLifeCycle = 1000000l;
	
	@Value("${ads.memdb.lifecycle}")
	private long memDbLifeCycle = 10000000l;

	public DFRedissonConnection() {

		try {
			this.redisService = ServiceFactory.getService();
			this.adfService = ADFServiceEntry.getADFService();
			this.dfService = redisService.getDFService();
			setRedisControl(dfService.registry("acp"));

		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private class MemDBOperationsImp extends MemDBDataOperations {

		private RedisMemDB operations;

		public MemDBOperationsImp() throws ACPException {
			try {
				if (adfService != null) {
					LOGGER.info("adfService..registry");
					operations = adfService
							.registry(serverProperties.getName());
				}
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException("Fail to adf registy : "
						+ e.getMessage());
			}
		}

		@Override
		public void write(MemDBData db) throws ACPException {
			if (operations == null)
				return;
			String key = operations.createMemDBKey(db.getArea(), db.getEntryName());
			db.setKey(key);
			try {
				LOGGER.info(String.format("uploadModel:%s", key));
				operations.uploadModel(db.getKey(), memDbLifeCycle);
				// memdb.pubMessage(db.getContentCode(), db.getKey());
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
			}
		}

		@Override
		public MemDBData read(MemDBData db) throws ACPException {
			try {
				System.out.println("read db : "+db.getKey());
				MemDBContext context = operations.resloveMemDBKey(db.getKey());
				db.setArea(context.getStrArea());
				db.setEntryName(context.getStrDBEntry());
				operations.downloadModel(db.getKey());
			} catch (RedisMemDBException e) {
				e.printStackTrace();
				throw new ACPException("RedisMemDB.downloadModel : "
						+ e.getMessage());
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException("RedisMemDB.downloadModel : "
						+ e.getMessage());
			}

			return db;
		}

		@Override
		public void close() {
			if (operations != null) {
				operations.closeClinet();
				operations = null;
			}
		}

	}

	
	public class MapDataOperationsImp extends MapDataOperations {
		private RedissonDBMap operation;

		public MapDataOperationsImp() throws RedissonDBException {
			if (executeDF != null)
				operation = executeDF.RedissonDBMap();

		}

		@Override
		public MapData read(MapData data) throws ACPException,
				UnsupportedOperation {
			ResultObject<String, Set<Entry<String, String>>> rt = null;

			try {
				if (operation != null) {
					rt = operation.LockHGETALL(data.getKey(), defaultLifeCycle);

					Set<Entry<String, String>> set = rt.getValue();
					Map<String, String> m = new HashMap<String, String>();
					for (Entry<String, String> e : set) {

						m.put(e.getKey(), e.getValue());
					}
					data.setContent(m);
				}
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			return data;
		}

		@Override
		public void write(MapData data) throws ACPException,
				UnsupportedOperation {

			if (operation == null)
				return;
			try {
				operation.LockHMSET(data.getKey(), defaultLifeCycle, data.getContent());
				LOGGER.info("LockHMSET : "+data.getKey());
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException("Fail to map.LockHMSET : "
						+ e.getMessage());
			}
			// RedissonPubManager msgBroker = executeDF.RedissonPubManager();
			// String strMessage = msgBroker.setMessage(data.getContentCode(),
			// data.getKey());
			// try {
			// msgBroker.pubMessage(strMessage);
			// } catch (RedissonDBException e) {
			// // TODO Auto-generated catch block
			// e.printStackTrace();
			// throw new ACPException(
			// "Fail to RedissonPubManager.setMessage : "
			// + e.getMessage());
			// } finally {
			// if (msgBroker != null)
			// msgBroker.closed();
			// }
		}

		@Override
		public String get(String key, String mkey) throws ACPException,
				UnsupportedOperation {
			if (operation == null)
				return null;

			try {
				ResultObject<String, String> rt = operation.LockHGET(key, defaultLifeCycle, mkey);
				if (rt != null)
					return rt.getValue();

				return null;
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			}

		}

		@Override
		public void close() {
			if (operation != null) {
				operation.closed();
				operation = null;
			}
		}

		@Override
		public Long getSize(String key) {
			ResultObject<String, Integer> rt = null;
			try {
				rt = operation.HLEN(key, defaultLifeCycle);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return rt.getValue().longValue();
		}

	}

	private class ListDataOperationsImp extends ListDataOperations {

		private RedissonDBList operations;

		public ListDataOperationsImp() {
			try {
				if (executeDF != null)
					operations = executeDF.RedissonDBList();
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		@Override
		public ListData read(ListData data) throws ACPException {

			if (operations == null)
				return data;

			try {
				ResultObject<String, List<String>> rt = operations
						.LockLRANGE(data.getKey(), defaultLifeCycle);
				if (rt != null)
					data.setContent(rt.getValue());
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			return data;
		}

		@SuppressWarnings("unchecked")
		@Override
		public void write(ListData data) throws ACPException {

			try {
				operations.LockRPUSH(data.getKey(), defaultLifeCycle, data.getContent());
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException("Fail to list.BatchRPUSH : "
						+ e.getMessage());
			}
		}

		@Override
		public String lpop(String key) throws ACPException {
			ResultObject<String, String> rt = null;
			try {
				if ((rt = operations.LockLPOP(key, defaultLifeCycle)) != null) {
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
			if (operations != null) {
				operations.closed();
				operations = null;
			}
		}

		

	}

	public class StringRefOperationsImp extends StringRefDataOperations {

		private RedissonDBString operations;

		public StringRefOperationsImp() throws RedissonDBException {
			operations = executeDF.RedissonDBString();

		}

		@Override
		public StringRefData read(StringRefData o) throws ACPException,
				UnsupportedOperation {

			o.setContent(get(o.getKey()));
			return o;
		}

		@Override
		public void write(StringRefData o) throws ACPException,
				UnsupportedOperation {
			try {
				if (operations != null)
					operations.LockSET(o.getKey(), defaultLifeCycle, o.getContent());
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			}

		}

		@Override
		public String get(String key) {
			ResultObject<String, String> rt = null;
			try {
				rt = operations.LockGET(key, defaultLifeCycle);
			} catch (RedissonDBException e) {
				e.printStackTrace();
				return null;
			}

			if (rt != null)
				return rt.getValue();

			return null;
		}

		@Override
		public void close() throws ACPException {
			if (operations != null) {
				operations.closed();
				operations = null;
			}
		}

	}

	private class StringDataOperationsImp extends StringDataOperations {

		@Override
		public StringData read(StringData o) throws ACPException,
				UnsupportedOperation {
			return o;
		}

		@Override
		public void write(StringData o) throws ACPException,
				UnsupportedOperation {

		}

	}

	// private class BusOperationsImp implements BusOperations {
	//
	// @Override
	// public void sendMessage(String contentCode, String content,
	// String appName) throws ACPException {
	// publishData(contentCode, content);
	// }
	//
	// }

	public void publishData(String contentCode, String key) throws ACPException {

		if (contentCode == null || contentCode.isEmpty()) {
			throw new ACPException("Null or empty contentCode");
		}
		RedissonPubManager msg = executeDF.RedissonPubManager();

		String strMessage = msg.setMessage(contentCode, key);
		try {
			
			msg.pubMessage(strMessage);
		} catch (RedissonDBException e) {
			e.printStackTrace();
			throw new ACPException(e);
		} finally {
			msg.closed();
		}		
	}


	@Override
	public MemDBDataOperations getMemDBDataOperations() {
		try {
			return new MemDBOperationsImp();
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
	}

	@Override
	public ListDataOperations getListDataOperations() {
		return new ListDataOperationsImp();
	}

	public DFService getDfService() {
		return dfService;
	}

	public void setDfService(DFService dfService) {
		this.dfService = dfService;
	}

	// @Override
	// public BusOperations getBusOperations() {
	// return new BusOperationsImp();
	// }

	@Override
	public void register(DataFieldStorage storage) {
		try {
			final String appName = storage.getServerName();
			dfService.registry(appName, new EventCallBack() {
				@Override
				public void CallBack(int number, MessageContent eventContent) {
					LOGGER.info("Number:" + number + ",收到事件:"
							+ eventContent.getControlCode() + "  "
							+ eventContent.getEventContent());
					try {

						storage.receivedMessage(eventContent.getControlCode(),
								eventContent.getEventContent());
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
		return new StringDataOperationsImp();
	}

	@Override
	public StringRefDataOperations getStringRefOperations() {
		try {
			return new StringRefOperationsImp();
		} catch (RedissonDBException e) {
			e.printStackTrace();
			return null;
		}
	}

	@Override
	public MapDataOperations getMapDataOperations() {
		try {
			return new MapDataOperationsImp();
		} catch (RedissonDBException e) {
			e.printStackTrace();
			return null;
		}
	}

	public ExectueDF getRedisControl() {
		return executeDF;
	}

	public void setRedisControl(ExectueDF redisControl) {
		this.executeDF = redisControl;
	}


	@Override
	public void deleteKeys(String... keys) {
		try {
			executeDF.RedissonDBKey().BatchDEL(keys);
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public Set<String> findKeys(String pattern) {
		Set<String> keys = new HashSet<String>(); 
		try {
			List<ResultObject<String, String>> rt = executeDF.RedissonDBKey().FindKeys(pattern);
			for (ResultObject<String, String> e : rt) {
				keys.add(e.getValue());
			}
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
		return keys;
	}


	@Override
	public boolean hasKey(String key) {
		ResultObject<String, Boolean> rt = null;
		try {
			rt = executeDF.RedissonDBKey().EXISTS(key);
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return rt.getValue();
	}

}
