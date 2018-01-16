package com.znd.ei.ads.acp.dfredisson;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import javax.annotation.PreDestroy;

import org.redisson.RedissonNode;
import org.redisson.api.RRemoteService;
import org.redisson.api.RedissonClient;
import org.redisson.api.RemoteInvocationOptions;
import org.redisson.config.RedissonNodeConfig;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;

import com.ZhongND.RedisADF.ADFService.ADFServiceEntry;
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
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.ObjectRefDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.AplManager;

public class DFRedissonConnection extends AbstractConnectionFactory {

	private static DFRedissonConnection INSTANCE = null;
	private static final Logger LOGGER = LoggerFactory
			.getLogger(DFRedissonConnection.class);

	private RedisService redisService;
	private DFService dfService;
	private ExectueDF executeDF;

	// private String modelZone = "test";

	@Autowired
	private ServerProperties serverProperties;

	@Value("${ads.defaultlifecycle}")
	private long defaultLifeCycle = 1000000l;

	@Value("${ads.memdb.lifecycle}")
	private long memDbLifeCycle = 10000000l;

	// @Autowired
	private RedissonNodeConfig nodeConfig;

	// @Autowired
	private RedissonNode redissonNode;

	@Autowired
	private RedissonClient redissonClient;

	public static DFRedissonConnection getInstance() {
		return INSTANCE;
	}

	public DFRedissonConnection(RedissonNodeConfig nodeConfig) {
		INSTANCE = this;
		this.nodeConfig = nodeConfig;
		try {
			this.redisService = ServiceFactory.getService();
			ADFServiceEntry.getADFService();
			this.dfService = redisService.getDFService();
			this.executeDF = dfService.registry("acp");

		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}



	public class MapDataOperationsImp implements MapDataOperations {
		private RedissonDBMap operation;

		public MapDataOperationsImp() throws RedissonDBException {
			if (executeDF != null)
				operation = executeDF.RedissonDBMap();

		}

		// @Override
		// public MapData read(MapData data) throws ACPException,
		// UnsupportedOperation {
		// ResultObject<String, Set<Entry<String, String>>> rt = null;
		//
		// try {
		// if (operation != null) {
		// rt = operation.LockHGETALL(data.getKey(), defaultLifeCycle);
		//
		// Set<Entry<String, String>> set = rt.getValue();
		// Map<String, String> m = new HashMap<String, String>();
		// for (Entry<String, String> e : set) {
		//
		// m.put(e.getKey(), e.getValue());
		// }
		// data.setContent(m);
		// }
		// } catch (RedissonDBException e) {
		// // TODO Auto-generated catch block
		// e.printStackTrace();
		// }
		//
		// return data;
		// }
		//
		// @Override
		// public void write(MapData data) throws ACPException,
		// UnsupportedOperation {
		//
		// if (operation == null)
		// return;
		// try {
		// operation.LockHMSET(data.getKey(), defaultLifeCycle,
		// data.getContent());
		// LOGGER.info("LockHMSET : " + data.getKey());
		// } catch (RedissonDBException e) {
		// // TODO Auto-generated catch block
		// e.printStackTrace();
		// throw new ACPException("Fail to map.LockHMSET : "
		// + e.getMessage());
		// }
		// // RedissonPubManager msgBroker = executeDF.RedissonPubManager();
		// // String strMessage = msgBroker.setMessage(data.getContentCode(),
		// // data.getKey());
		// // try {
		// // msgBroker.pubMessage(strMessage);
		// // } catch (RedissonDBException e) {
		// // // TODO Auto-generated catch block
		// // e.printStackTrace();
		// // throw new ACPException(
		// // "Fail to RedissonPubManager.setMessage : "
		// // + e.getMessage());
		// // } finally {
		// // if (msgBroker != null)
		// // msgBroker.closed();
		// // }
		// }

		@Override
		public <K,V> V get(String key, K mkey) {
			if (operation == null)
				return null;

			try {
				ResultObject<K, V> rt = operation.LockHGET(key,
						defaultLifeCycle, mkey);
				if (rt != null)
					return rt.getValue();

			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();

			}

			return null;

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

		@Override
		public <K,V> Map<K, V> getAll(String key) {
			try {
				ResultObject<String, Set<Entry<K, V>>> rt = operation
						.LockHGETALL(key, defaultLifeCycle);

				Map<K, V> m = new HashMap<>();

				Set<Entry<K, V>> rt1 = rt.getValue();
				for (Entry<K, V> e : rt1) {
					m.put(e.getKey(), e.getValue());
				}

				return m;
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}

		@Override
		public <K,V> void putAll(String key, Map<K, V> content) {
			try {
				operation.LockHMSET(key, defaultLifeCycle, content);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		@Override
		public boolean isEmpty(String key) {
			return hasKey(key);
		}

		@Override
		public <K> void remove(String key, K... keys) {
			try {
				operation.LockHDEL(key, defaultLifeCycle, keys);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		@Override
		public <K, V> void put(String key, K hashKey, V value) {

			try {
				Map<K, V> content = new HashMap<K, V>();
				content.put(hashKey, value);
				operation.LockHMSET(key, defaultLifeCycle, content);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

	public class ListDataOperationsImp implements ListDataOperations {

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

		// @Override
		// public ListData<V> read(ListData<V> data) throws ACPException {
		//
		// if (operations == null)
		// return data;
		//
		// try {
		// ResultObject<String, List<V>> rt = operations.LockLRANGE(
		// data.getKey(), defaultLifeCycle);
		// if (rt != null)
		// data.setContent(rt.getValue());
		// } catch (RedissonDBException e) {
		// // TODO Auto-generated catch block
		// e.printStackTrace();
		// }
		//
		// return data;
		// }
		//
		// @SuppressWarnings("unchecked")
		// @Override
		// public void write(ListData<V> data) throws ACPException {
		//
		// try {
		// operations.LockRPUSH(data.getKey(), defaultLifeCycle,
		// data.getContent());
		// } catch (RedissonDBException e) {
		// e.printStackTrace();
		// throw new ACPException("Fail to list.BatchRPUSH : "
		// + e.getMessage());
		// }
		// }

		@Override
		public <V> V lpop(String key) throws ACPException {
			ResultObject<String, V> rt = null;
			try {
				if ((rt = operations.LockLPOP(key, defaultLifeCycle)) != null) {
					V str = rt.getValue();
					return str;
				}
				return null;
			} catch (RedissonDBException e) {
				throw new ACPException(e.getMessage());
			}
		}

		@Override
		public <V> V blpop(String key) {
			ResultObject<String, V> rt = null;
			try {
				if ((rt = operations.BLPOP(key, defaultLifeCycle)) != null) {
					V str = rt.getValue();
					return str;
				}
			} catch (RedissonDBException e) {
				e.printStackTrace();
			}
			return null;
		}
		
		@Override
		public <V> List<V> getAll(String key) {
			try {
				ResultObject<String, List<V>> rt = operations.LRANGE(key,
						defaultLifeCycle);
				return rt.getValue();
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public <V> void pushAll(String key, List<V> values) {
			try {
				operations.LockLPUSH(key, defaultLifeCycle, values);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}

		@Override
		public boolean isEmpty(String key) {
			Set<?> s = findKeys(key);
			return s == null || s.isEmpty();
		}

		@Override
		public <V> void push(String key, V value) {
			List<V> values = new ArrayList<V>();
			values.add(value);
			try {
				operations.LPUSH(key, defaultLifeCycle, values);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		@Override
		public <V> void bpush(String key, V value) {
			List<V> values = new ArrayList<V>();
			values.add(value);
			try {
				operations.LPUSH(key, defaultLifeCycle, values);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}	
		}

		@Override
		public int getSize(String key) {
			ResultObject<String, Integer> rt;
			try {
				rt = operations.LLEN(key, defaultLifeCycle);
			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return 0;
			}
			if (rt != null)
				return rt.getValue();
			
			return 0;
		}
	}

	public class ObjectRefDataOperationsImp implements
			ObjectRefDataOperations {

		private RedissonDBString operations;

		public ObjectRefDataOperationsImp() throws RedissonDBException {
			operations = executeDF.RedissonDBString();

		}

		// @Override
		// public ObjectRefData<T> read(ObjectRefData<T> o) throws ACPException,
		// UnsupportedOperation {
		//
		// o.setContent(get(o.getKey()));
		// return o;
		// }
		//
		// @Override
		// public void write(ObjectRefData o) throws ACPException,
		// UnsupportedOperation {
		// try {
		// if (operations != null)
		// operations.LockSET(o.getKey(), defaultLifeCycle,
		// o.getContent());
		// } catch (RedissonDBException e) {
		// e.printStackTrace();
		// throw new ACPException(e.getMessage());
		// }
		//
		// }

		@Override
		public <V> V get(String key) {
			ResultObject<String, V> rt = null;
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
		public <V> void set(String key, V value) {
			try {
				operations.LockSET(key, defaultLifeCycle, value);
			} catch (RedissonDBException e) {
				e.printStackTrace();
			}
		}

		@Override
		public boolean isEmpty(String key) {
			return hasKey(key);
		}

		@Override
		public void decr(String key) {
			try {
				operations.LockLongDECR(key, defaultLifeCycle);
			} catch (RedissonDBException e) {
				e.printStackTrace();
			}
		}

	}

//	public class StringDataOperationsImp implements StringDataOperations {
//
//		@Override
//		public boolean isEmpty(String key) {
//			return false;
//		}
//
//		// @Override
//		// public StringData read(StringData o) throws ACPException,
//		// UnsupportedOperation {
//		// return o;
//		// }
//		//
//		// @Override
//		// public void write(StringData o) throws ACPException,
//		// UnsupportedOperation {
//		//
//		// }
//
//	}

	// private class BusOperationsImp implements BusOperations {
	//
	// @Override
	// public void sendMessage(String contentCode, String content,
	// String appName) throws ACPException {
	// publishData(contentCode, content);
	// }
	//
	// }

	public interface MessageSender {
		void sendMessage(RedissonPubManager sender, String message)
				throws Exception;
	}

	private void sendMessage(String contentCode, String key,
			MessageSender sender) {

		if (contentCode == null || contentCode.isEmpty()) {
			LOGGER.error("Null or empty contentCode");
			return;
		}
		RedissonPubManager msg = executeDF.RedissonPubManager();


		try {
			String strMessage = msg.setMessage(contentCode, key);

			sender.sendMessage(msg, strMessage);
		} catch (Exception e) {
			e.printStackTrace();
			LOGGER.error(e.getMessage());
		} 

	}

	public void publish(String contentCode, String key) {
		sendMessage(contentCode, key,
				(RedissonPubManager sender, String message) -> sender
						.pubMessage(message));
	}

	@Override
	public void request(String contentCode, String key) {
		publish(contentCode, key);
	}

	@Override
	public void inner_publish(String contentCode, String key) {
		sendMessage(contentCode, key,
				(RedissonPubManager sender, String message) -> sender
						.pubMessage(INNER_PUBLISH_CHANNEL, message));
	}

	@Override
	public void inner_request(String contentCode, String key) {
		sendMessage(contentCode, key,
				(RedissonPubManager sender, String message) -> sender
						.pubMessage(INNER_REQUEST_CHANNEL, message));
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

	public AplManager aplManager;
	

	interface Register {
		void register(EventCallBack c)  throws Exception;
	}

	private void registerEventCallBack(final String eventType, Register r) throws Exception {
			
		EventCallBack defaultEventCallBack = new EventCallBack() {
			@Override
			public void CallBack(int number, MessageContent eventContent) {
				LOGGER.info("Number: {} ,收到{}, cc: {}, content: {}", number,
						eventType, eventContent.getControlCode(),
						eventContent.getEventContent());
				try {

					aplManager.receivedMessage(eventContent.getControlCode(),
							eventContent.getEventContent());
					LOGGER.info("Finish process cc = {}" , eventContent.getControlCode());
				} catch (ACPException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (UnsupportedOperation e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		};
		
		r.register(defaultEventCallBack);	
	}

	@Override
	public void register(AplManager storage) throws Exception {
		this.aplManager = storage;
		final String appName = storage.getServerName();
		registerEventCallBack("外部事件", (EventCallBack c)->{dfService.registry(appName, c, true);});
		registerEventCallBack("内部事件", (EventCallBack c)->{dfService.registry(appName+"_inner_publish",
				ConnectionFactory.INNER_PUBLISH_CHANNEL, c, false);});
		registerEventCallBack("内部请求", (EventCallBack c)->{dfService.registry(appName+"_inner_request",
				ConnectionFactory.INNER_REQUEST_CHANNEL, c, true);});	
	}

//	@Override
//	public StringDataOperations getStringDataOperations() {
//		return new StringDataOperationsImp();
//	}
//
	@Override
	public ObjectRefDataOperations getObjectRefOperations() {
		try {
			return new ObjectRefDataOperationsImp();
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
			List<ResultObject<String, String>> rt = executeDF.RedissonDBKey()
					.FindKeys(pattern);
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

	public AplManager getStorage() {
		return aplManager;
	}

	/**
	 * Get remote service object for remote invocations.
	 * <p>
	 * This method is a shortcut for
	 * 
	 * <pre>
	 * get(remoteInterface, RemoteInvocationOptions.defaults())
	 * </pre>
	 *
	 * @see RemoteInvocationOptions#defaults()
	 * @see #get(Class, RemoteInvocationOptions)
	 *
	 * @param <T>
	 *            type of remote service
	 * @param remoteInterface
	 *            - remote service interface
	 * @return remote service instance
	 */
	public <T> T getService(Class<T> remoteInterface) {

		RRemoteService rs = redissonClient.getRemoteService();
		return rs.get(remoteInterface);

	}

	@PreDestroy
	public void beforDestory() {
		try {
			dfService.unregistry();
			dfService.unregistry(ConnectionFactory.INNER_PUBLISH_CHANNEL);
			dfService.unregistry(ConnectionFactory.INNER_REQUEST_CHANNEL);
			
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if (redissonNode != null) {
			LOGGER.info("Redisson node shutdown!");
			redissonNode.shutdown();
		}
	}

	private RRemoteService remoteService = null;

	public <T> void registerService(Class<T> remoteInterface, T serviceImp) {

		if (redissonNode == null) {
			// 启动计算节点
			LOGGER.info("Redisson node start!");
			redissonNode = RedissonNode.create(nodeConfig);
			redissonNode.start();

			RedissonClient redisson = redissonNode.getRedisson();
			remoteService = redisson.getRemoteService();
		}

		if (remoteService != null) {
			remoteService.register(remoteInterface, serviceImp);
		}

	}

//	@Override
//	public void waitForContent(String contentCode) {
//		RCountDownLatch latch = redissonClient.getCountDownLatch(contentCode);
//		latch.trySetCount(1);
//		try {
//			latch.await();
//		} catch (InterruptedException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	}
//
//	@Override
//	public void notifyContent(String contentCode) {
//		RCountDownLatch latch = redissonClient.getCountDownLatch(contentCode);
//		latch.countDown();
//	}

}
