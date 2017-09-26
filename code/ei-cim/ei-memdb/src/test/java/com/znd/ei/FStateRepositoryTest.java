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
    	FState state = new FState();
    	state.setId(1);
    	repository.save(state);
    	assertThat(repository.count() > 0);
    }
}
