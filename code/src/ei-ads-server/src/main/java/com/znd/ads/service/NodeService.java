package com.znd.ads.service;

import java.util.List;

import com.znd.buffer.common.model.AdsNode;

public interface NodeService {
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
    
    /**
     * 根据名称获取节点
     * @param name
     * @return
     */
    AdsNode getByUrl(String url);
    
    void save(AdsNode info);

	void deleteById(Integer nodeId);

	AdsNode getById(Integer nodeId);

	void update(AdsNode node);
}
