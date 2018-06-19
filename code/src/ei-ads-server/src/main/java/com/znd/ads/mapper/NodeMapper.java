package com.znd.ads.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;

import com.znd.ads.model.po.AdsNode;
@Mapper
public interface NodeMapper {
    /**
     * 获取所有的节点
     * @return
     */
    List<AdsNode> all();
    
    /**
     * 根据名称获取节点
     * @param name
     * @return
     */
    AdsNode getByName(String name);
    
    void save(AdsNode info);

	AdsNode getByUrl(String url);

	void deleteById(String id);

	AdsNode getById(String nodeId);

	void updateNodeInfo(AdsNode node);
}
