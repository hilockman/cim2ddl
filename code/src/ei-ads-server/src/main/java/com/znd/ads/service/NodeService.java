package com.znd.ads.service;

import java.util.List;

import com.znd.ads.model.po.AdsNode;

public interface NodeService {
    /**
     * 获取所有的节点
     * @return
     */
    List getAll();
    
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

	void deleteById(String nodeId);

	AdsNode getById(String nodeId);

	void update(AdsNode node);
}
