package com.znd.event;

import com.znd.annotation.AplController;

public class AplBean {

	
	private String jobType;
	private Object aplObject;
	
	private final AplContext context = new AplContext();
	
	public static class AplBeanBuilder {
		private AplBean apl = new AplBean(); 
		
		public AplBeanBuilder(Object object, AplController a) {
			apl.aplObject = object;
			apl.jobType = a.value();
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



	public String getJobType() {
		return jobType;
	}


}
