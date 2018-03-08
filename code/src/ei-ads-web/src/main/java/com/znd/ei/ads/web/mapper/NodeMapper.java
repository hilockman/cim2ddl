package com.znd.ei.ads.web.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;

import com.znd.ei.ads.web.vo.NodeInfo;
@Mapper
public interface NodeMapper {
    /**
     * 获取所有的节点
     * @return
     */
    List<NodeInfo> all();
    
    /**
     * 根据名称获取节点
     * @param name
     * @return
     */
    NodeInfo getByName(String name);
    
    void save(NodeInfo info);

	NodeInfo getByUrl(String url);
}
