package com.znd.ei.memdb;

import java.util.Iterator;
import java.util.Stack;

@SuppressWarnings("rawtypes")
public class DbComponentIterator implements Iterator {

	Stack stack = new Stack();
	
	@SuppressWarnings("unchecked")
	public DbComponentIterator(Iterator iterator) {
		stack.push(iterator);
	}
	@Override
	public boolean hasNext() {
		if (stack.isEmpty()) {
			return false;
		} else {
			Iterator iterator = (Iterator) stack.peek();
			if (iterator.hasNext()) {
				stack.pop();
				return hasNext();
			} else  {
				return true;
			}
		}
	}

	@SuppressWarnings({ "unchecked" })
	@Override
	public Object next() {
		if (hasNext()) {
			Iterator iterator = (Iterator) stack.peek();
			DbComponent c = (DbComponent) iterator.next();
			if (c instanceof DbEntryCollection) {
				stack.push(c.createIterator());
			}
			
			return c;
		} else {
			return null;
		}
	}
	@Override
	public void remove() {
		throw new UnsupportedOperationException();
	}

}
