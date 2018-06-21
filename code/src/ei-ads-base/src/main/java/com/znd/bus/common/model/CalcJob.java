package com.znd.bus.common.model;

import java.util.Date;

import com.znd.ads.annotation.Comment;
import com.znd.ads.annotation.ForeignColumn;
import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.bus.annotation.Index;
import com.znd.ei.Utils;

@Comment(alias="工作")
public class CalcJob {
	@Index
	private String id;

	@Index
	@Comment(alias="名称")
	private String name;
	
	@Index
	@Comment(alias="模型",  fk=@ForeignColumn(table="model_source", value="name"))
	private String modelId;
	
	@Comment(alias="类型", tr="reliability:可靠性计算")
	private String typeId;	
		
	@Comment(alias="描述")
	private String desc;
	
	@Comment(alias="参数")
	private String parameter;
	
	@Comment(alias="进度")
	private Double progress;
	
	@Comment(alias="当前步骤")
	private Integer step;
	
	@Comment(alias="最大步骤数")
	private Integer maxStep;
	
	@Comment(alias="状态", tr="running:正在执行,suspend:暂停,stop:停止,abnormal:异常")
	private CalcJobStateEnum state = CalcJobStateEnum.stop;
		
	@Comment(alias="开始时间")
	private Date start;
	
	@Comment(alias="结束时间")
	private Date end;
	
	@Comment(alias="耗时")
	private Long elapse;
		
	public String getId() {
		return id;
	}
	
	public void setId(String id) {
		this.id = id;
	}
	
	public String getModelId() {
		return modelId;
	}
	
	public void setModelId(String modelId) {
		this.modelId = modelId;
	}

	public String getDesc() {
		return desc;
	}

	public void setDesc(String desc) {
		this.desc = desc;
	}

	public String getParameter() {
		return parameter;
	}

	public void setParameter(String parameter) {
		this.parameter = parameter;
	}
	
	public static void setConfig(CalcJob job, PRAdequacySetting config) {
		job.setParameter(Utils.toJSon(config));
	}
	
	public static PRAdequacySetting getConfig(CalcJob job) {

		return Utils.toObject(job.getParameter(), PRAdequacySetting.class);
	}

	public Date getStart() {
		return start;
	}

	public void setStart(Date start) {
		this.start = start;
	}

	public Date getEnd() {
		return end;
	}

	public void setEnd(Date end) {
		this.end = end;
	}

	public Long getElapse() {
		return elapse;
	}

	public void setElapse(Long elapse) {
		this.elapse = elapse;
	}

	public CalcJobStateEnum getState() {
		return state;
	}

	public void setState(CalcJobStateEnum state) {
		this.state = state;
	}

	public Double getProgress() {
		return progress;
	}

	public void setProgress(Double progress) {
		this.progress = progress;
	}

	public Integer getStep() {
		return step;
	}

	public void setStep(Integer step) {
		this.step = step;
	}

	public Integer getMaxStep() {
		return maxStep;
	}

	public void setMaxStep(Integer maxStep) {
		this.maxStep = maxStep;
	}

	public String getTypeId() {
		return typeId;
	}

	public void setTypeId(String typeId) {
		this.typeId = typeId;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "CalcJob [id=" + id + ", modelId=" + modelId + ", typeId="
				+ typeId + ", name=" + name + ", desc=" + desc + ", parameter="
				+ parameter + ", progress=" + progress + ", step=" + step
				+ ", maxStep=" + maxStep + ", state=" + state + ", start="
				+ start + ", end=" + end + ", elapse=" + elapse + "]";
	}

}
