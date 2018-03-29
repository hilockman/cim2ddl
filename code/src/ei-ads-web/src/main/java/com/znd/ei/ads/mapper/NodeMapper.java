package com.znd.ei.ads.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;

import com.znd.buffer.common.model.AdsNode;
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

	void deleteById(Integer id);

	AdsNode getById(Integer nodeId);

	void update(AdsNode node);
}
