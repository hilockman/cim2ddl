package com.znd.ei.ads.adf;

public class MemDBData extends DataItem<MemDBData> {

	private String entryName = "";
	private String area = "";

	public String getEntryName() {
		return entryName;
	}

	public void setEntryName(String entryName) {
		this.entryName = entryName;
	}

	public String getArea() {
		return area;
	}

	public void setArea(String area) {
		this.area = area;
	}

	public void clear() {

	}

	@Override
	public boolean isEmpty() {
		return area == null || entryName == null || area.isEmpty()
				|| entryName.isEmpty();
	}

	@Override
	public boolean canClear() {
		return false;
	}
}
