package com.znd.ei.ads.bus.statement;


import com.znd.ei.ads.bus.executor.Executor;
import com.znd.ei.ads.bus.mapping.MappedStatement;

public class RoutingStatementHandler  implements StatementHandler {

	private StatementHandler delegate;
	
	public RoutingStatementHandler(Executor executor, MappedStatement ms, Object parameter) {
		  switch (ms.getType()) {
		  	case DELETE:
		  		delegate = new DeleteStatementHandler(ms.getConfig(), executor, ms, parameter);
		  		break;
		  	case UPDATE:
		  		delegate = new InsertStatementHandler(ms.getConfig(), executor, ms, parameter);
		  		break;
		  	case INSERT:
		  		delegate = new InsertStatementHandler(ms.getConfig(), executor, ms, parameter);
		  		break;
		  	case SELECT:
		  		delegate = new SelectStatementHandler(ms.getConfig(), executor, ms, parameter);
		  		break;	
		  	default:
		  		throw new StatementException("Unknow statement type : " + ms.getId());
		  		
		  }
	}
	
	@Override
	public Statement newStatement() {
		return delegate.newStatement();
	}

	@Override
	public void parepared(Statement ps) {
		delegate.parepared(ps);
	}

}
