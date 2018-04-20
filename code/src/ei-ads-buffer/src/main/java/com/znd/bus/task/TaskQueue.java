package com.znd.bus.task;

import java.util.Collection;
import java.util.Iterator;
import java.util.Queue;

import org.redisson.api.RAtomicLong;
import org.redisson.api.RQueue;

public class TaskQueue<T> implements Queue<T> {

	private RAtomicLong atomicLong;
	private RQueue<T> queue;
	
	public long increaseGood() {
		return atomicLong.incrementAndGet();
	}
	
	public long goodCount() {
		return atomicLong.get();
	}
	
	public void delete() {
		atomicLong.delete();
	}
	
	public TaskQueue(RAtomicLong atomicLong, RQueue<T> queue) {
		atomicLong.set(0);
		this.atomicLong = atomicLong;
		this.queue = queue;
		
	}

	@Override
	public int size() {
		return queue.size();
	}

	@Override
	public boolean isEmpty() {
		return queue.isEmpty();
	}

	@Override
	public boolean contains(Object o) {
		return queue.contains(o);
	}

	@Override
	public Iterator<T> iterator() {
		return queue.iterator();
	}

	@Override
	public Object[] toArray() {
		return queue.toArray();
	}

	@Override
	public <T> T[] toArray(T[] a) {
		return queue.toArray(a);
	}

	@Override
	public boolean remove(Object o) {
		return queue.remove(o);
	}

	@Override
	public boolean containsAll(Collection<?> c) {
		return queue.containsAll(c);
	}

	@Override
	public boolean addAll(Collection<? extends T> c) {
		return queue.addAll(c);
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		return queue.removeAll(c);
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		return queue.retainAll(c);
	}

	@Override
	public void clear() {
		queue.clear();
	}

	@Override
	public boolean add(T e) {
		return queue.add(e);
	}

	@Override
	public boolean offer(T e) {
		return queue.offer(e);
	}

	@Override
	public T remove() {
		return queue.remove();
	}

	@Override
	public T poll() {
		return queue.poll();
	}

	@Override
	public T element() {
		return queue.element();
	}

	@Override
	public T peek() {
		return queue.peek();
	}
	
}