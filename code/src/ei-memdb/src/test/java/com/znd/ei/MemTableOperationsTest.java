package com.znd.ei;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ei.memdb.DbEntryOperations;

@RunWith(SpringRunner.class)
@SpringBootTest
public class MemTableOperationsTest {

	@Autowired
	DbEntryOperations pROps;
	
	@Test 
	public void testCleanPRDb() {
		pROps.clearDb();		
	}
}
