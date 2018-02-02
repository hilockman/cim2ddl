package com.znd.test.mybatis;

import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface BlogMapper {

	Blog selectBlog(int id);
}
