package com.znd.ei;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ei.memdb.reliabilty.dao.FStateRepository;
import com.znd.ei.memdb.reliabilty.domain.FState;
@RunWith(SpringRunner.class)
@SpringBootTest
public class FStateRepositoryTest {

	@Autowired
	private FStateRepository repository;
	
    @Test
    public void contexLoads() throws Exception {
        assertThat(repository).isNotNull();
    }
    
    @Test 
    public void saveAndRead() throws Exception {
    	repository.deleteAll();
    	
    	for (int i = 0; i < 10; i ++) {
        	FState state = new FState();
        	
        	state.setId(1);
        	state.setFDevNum(10+i);
        	state = repository.saveOrUpdate(state);
        	
        	assertThat(state.getMemIndex() == i);    		
    	}

    	
    	assertThat(repository.count() == 10);
    }
    
    @Test 
    public void update() throws Exception {
    	repository.deleteAll();
    	FState [] states = new FState[10];
    	for (int i = 0; i < 10; i ++) {
        	FState state = new FState();
        	
        	state.setId(1);
        	state.setFDevNum(10+i);
        	state = repository.saveOrUpdate(state);
        	
        	assertThat(state.getMemIndex() == i);  
        	states[i] = state;
    	}
    	
    	for (int i = 0; i < 10; i++) {
    		
        	FState state = states[i];
        	System.out.println("update row:"+state.getMemIndex());
        	state.setBalanceCutGen(100.00+i);
        	repository.saveOrUpdate(state);    		
    	}

    	assertThat(repository.count() > 0);
    }
}
