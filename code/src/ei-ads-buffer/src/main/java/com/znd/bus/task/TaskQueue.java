package com.znd.bus.task;

import java.util.Collection;
import java.util.Iterator;
import java.util.Queue;
import java.util.concurrent.TimeUnit;

import org.redisson.api.RAtomicLong;
import org.redisson.api.RQueue;
import org.redisson.api.RedissonClient;

public class TaskQueue<T> implements Queue<T> {

	private RAtomicLong left;
	private RQueue<T> queue;
	private String name;
	
	public long decreaseLeft() {
		return left.decrementAndGet();
	}
	
	public long leftCount() {
		return left.get();
	}
	
	public void syncLeftCount() {
		left.set(queue.size());
	}
	
	public void delete() {
		left.delete();
		queue.delete();
	}
	
	public TaskQueue(RedissonClient client, String id) {
		left = client.getAtomicLong(id+":left"); 
		left.set(0);
		name = id+":queue";
		queue = client.getQueue(name);
		queue.expire(1, TimeUnit.HOURS);
	}

	@Override
	public int size() {
		return queue.size();
	}

	@Override
	public boolean isEmpty() {
		return queue.isEmpty() && left.get() <= 0;
		//return queue.isEmpty();
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
		boolean rt = queue.addAll(c);
		left.set(queue.size());
		return rt;
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		boolean rt = queue.removeAll(c);
		left.set(0);
		return rt;
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

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
}