package com.znd.bus.server.message;

import com.znd.bus.message.IDKindType;

public class ID {
    protected String value;

    protected String idType;

    protected String idAuthority;

    protected IDKindType kind;

    protected String objectType;

	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}

	public String getIdType() {
		return idType;
	}

	public void setIdType(String idType) {
		this.idType = idType;
	}

	public String getIdAuthority() {
		return idAuthority;
	}

	public void setIdAuthority(String idAuthority) {
		this.idAuthority = idAuthority;
	}

	public IDKindType getKind() {
		return kind;
	}

	public void setKind(IDKindType kind) {
		this.kind = kind;
	}

	public String getObjectType() {
		return objectType;
	}

	public void setObjectType(String objectType) {
		this.objectType = objectType;
	}
}
