package com.znd.ads.exception;

public class CustomError {
    private String errCode;
    private String errDesc;

    public CustomError(String errCode, String errDesc) {
        this.errCode = errCode;
        this.errDesc = errDesc;
    }

	public String getErrCode() {
		return errCode;
	}

	public void setErrCode(String errCode) {
		this.errCode = errCode;
	}

	public String getErrDesc() {
		return errDesc;
	}

	public void setErrDesc(String errDesc) {
		this.errDesc = errDesc;
	}
}
