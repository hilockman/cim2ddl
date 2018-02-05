package com.znd.test.mybatis;

import java.util.List;
import java.util.Map;

import org.apache.ibatis.annotations.MapKey;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface AuthorMapper {
	  // (Author) selectOne("selectAuthor",5);
	  Author selectAuthor(int id); 
	  // (List<Author>) selectList(“selectAuthors”)
	  List<Author> selectAuthors();
	  // (Map<Integer,Author>) selectMap("selectAuthors", "id")
	  @MapKey("id")
	  Map<Integer, Author> selectAuthorMap();
	  // insert("insertAuthor", author)
	  int insertAuthor(Author author);
	  // updateAuthor("updateAuthor", author)
	  int updateAuthor(Author author);
	  // delete("deleteAuthor",5)
	  int deleteAuthor(int id);
}
