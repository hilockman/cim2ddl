package com.znd.server.impl;

import java.io.File;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.concurrent.ConcurrentLinkedDeque;

import org.springframework.stereotype.Service;

import oshi.SystemInfo;
import oshi.hardware.CentralProcessor;
import oshi.hardware.GlobalMemory;
import oshi.hardware.HardwareAbstractionLayer;
import oshi.hardware.NetworkIF;
import oshi.software.os.OperatingSystem;

import com.znd.model.CPUInfo;
import com.znd.model.MemoryInfo;
import com.znd.model.SpaceInfo;
import com.znd.model.SystemResourceInfo;
import com.znd.server.SystemResourceServer;

@Service
public class SystemResourceServerImpl implements SystemResourceServer {

	private static SystemInfo si;
	private static HardwareAbstractionLayer hal;
	private static OperatingSystem os;

	static {
		si = new SystemInfo();
        hal = si.getHardware();
        os = si.getOperatingSystem();
	}
	
	//private List<CPUInfo> cpuInfos = new ArrayList<>();
	
	private ConcurrentLinkedDeque<SystemResourceInfo> infos = new ConcurrentLinkedDeque<>();
	
	
	public static SystemResourceInfo createSystemResourceInfo() {
		CPUInfo cpuInfo = getCPU();

		SystemResourceInfo info = new SystemResourceInfo(); 
		
		info.setMemory(getMemoryInfo());
		info.setSpaces(getSpaceInfos());
		
		info.setTime(new Date());
		info.setCpu(cpuInfo);
		return info;
	}
	
	public SystemResourceServerImpl() {

    
       
        new Thread(new Runnable() {
			
			@Override
			public void run() {
				

				while (true) {
				try {
					Thread.sleep(1000);

					infos.add(createSystemResourceInfo());
					if (infos.size() > 200) {
						infos.remove(0);
					}
					
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				}
			}
		}).start();
	}
	
	
	private static CPUInfo getCPU() {
		CentralProcessor processor = hal.getProcessor();
		
//		long[] prevTicks = processor.getSystemCpuLoadTicks();
//		
//        long[] ticks = processor.getSystemCpuLoadTicks();
//        System.out.println("CPU, IOWait, and IRQ ticks @ 1 sec:" + Arrays.toString(ticks));
//        long user = ticks[TickType.USER.getIndex()] - prevTicks[TickType.USER.getIndex()];
//        long nice = ticks[TickType.NICE.getIndex()] - prevTicks[TickType.NICE.getIndex()];
//        long sys = ticks[TickType.SYSTEM.getIndex()] - prevTicks[TickType.SYSTEM.getIndex()];
//        long idle = ticks[TickType.IDLE.getIndex()] - prevTicks[TickType.IDLE.getIndex()];
//        long iowait = ticks[TickType.IOWAIT.getIndex()] - prevTicks[TickType.IOWAIT.getIndex()];
//        long irq = ticks[TickType.IRQ.getIndex()] - prevTicks[TickType.IRQ.getIndex()];
//        long softirq = ticks[TickType.SOFTIRQ.getIndex()] - prevTicks[TickType.SOFTIRQ.getIndex()];
//        long steal = ticks[TickType.STEAL.getIndex()] - prevTicks[TickType.STEAL.getIndex()];
//        long totalCpu = user + nice + sys + idle + iowait + irq + softirq + steal;
        
        CPUInfo info = new CPUInfo();
        info.setLoad(processor.getSystemCpuLoad() * 100);
        info.setProcessCount(os.getProcessCount());
        info.setThreadCount(os.getThreadCount());
		return  info;
		
	}
	
	private void getNetworkInterfaces() {
		NetworkIF[] networkIFs = hal.getNetworkIFs();
	}
	
	
	//@Override
	private static MemoryInfo getMemoryInfo() {
		GlobalMemory globalMemory = hal.getMemory();
		MemoryInfo info = new MemoryInfo();
		info.setFreeMemory(Runtime.getRuntime().freeMemory());
		info.setMaxMemory(Runtime.getRuntime().maxMemory());
		info.setTotalMemory(Runtime.getRuntime().totalMemory());
		info.setGlobalFreeMemory(globalMemory.getAvailable());
		info.setGlobalTotalMemory(globalMemory.getTotal());
		info.setSwapTotalMemory(globalMemory.getSwapTotal());
		info.setSwapUsedMemory(globalMemory.getSwapUsed());
		info.setGlobalUsedMemory(info.getGlobalTotalMemory() - info.getGlobalFreeMemory());
		info.setUsedMemory(info.getTotalMemory() - info.getFreeMemory());
		info.setGlobalUsedMemoryRate(info.getGlobalUsedMemory() * 100D / info.getGlobalTotalMemory());
		return info;
	}

	//@Override
	public static List<SpaceInfo> getSpaceInfos() {
		List<SpaceInfo> infos = new ArrayList<>();
	    /* Get a list of all filesystem roots on this system */
	    File[] roots = File.listRoots();

	    /* For each filesystem root, print some info */
	    for (File root : roots) {
	      if (root.getTotalSpace() == 0)
	    	  continue;
	      
	      SpaceInfo info = new SpaceInfo();
	      
	      info.setDir(root.getAbsolutePath());
	      info.setTotalSpace(root.getTotalSpace());
	      info.setFreeSpace(root.getFreeSpace());
	      info.setUsableSpace(root.getUsableSpace());
	      infos.add(info);
	    }
	    
	    Collections.sort(infos, (l, r)->{return r.getDir().compareTo(l.getDir());});
	    
	    return infos;
	}


//	//@Override
//	public List<CPUInfo> getHistoryCpu() {
//		return cpuInfos;
//	}


	@Override
	public SystemResourceInfo get() {
		return infos.peekLast();
	}


	@Override
	public Collection<SystemResourceInfo> getList() {
		return infos;
	}

	
}
