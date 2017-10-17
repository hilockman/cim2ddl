package com.znd.ei.memdb;

import java.util.Iterator;

public abstract class DbComponent {
	   public void add(DbComponent component) throws DbException{  
	        throw new UnsupportedOperationException();  
	    }  
	      
	    public void remove(DbComponent component)  throws DbException{  
	        throw new UnsupportedOperationException();  
	    }  
	      
	    public DbComponent getChild(int i)  throws DbException {  
	        throw new UnsupportedOperationException();  
	    }  
	      
	    public String getName()  {  
	        throw new UnsupportedOperationException();  
	    }  
	      
	    public String getDescription()  {  
	        throw new UnsupportedOperationException();  
	    }  
     
	    public void print() {  
	        throw new UnsupportedOperationException();  
	    }  
	      
	    public Iterator<?> createIterator(){  
	        throw new UnsupportedOperationException();  
	    }  
}
