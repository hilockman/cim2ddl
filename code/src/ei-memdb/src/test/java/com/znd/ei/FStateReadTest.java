package com.znd.ei;

import java.util.List;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.domain.FState;

@RunWith(SpringRunner.class)
@SpringBootTest
public class FStateReadTest {
	@Autowired
	private FStateDao repository;
	
	@Test
	public void test() {
		List<FState> records = repository.findAll();
		
		for (int i = 0; i < records.size(); i++) {
			System.out.println(records.get(i));
		}
	}
}
