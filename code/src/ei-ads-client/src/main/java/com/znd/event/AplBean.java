package com.znd.event;

public class AplBean {

	
	
	private Object aplObject;
	
	private final AplContext context = new AplContext();
	
	public static class AplBeanBuilder {
		private AplBean apl = new AplBean(); 
		
		public AplBeanBuilder(Object object) {
			apl.setAplObject(object);
		}
		
		public AplBean build() {
			return apl;
		}
	}
	
	
	public AplContext getContext() {
	
		return context;
	}


	public Object getAplObject() {
		return aplObject;
	}


	public void setAplObject(Object aplObject) {
		this.aplObject = aplObject;
	}
}
