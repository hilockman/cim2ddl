package org.redisson.test.mapreduce;

import org.redisson.api.mapreduce.RCollector;
import org.redisson.api.mapreduce.RMapper;

public class WordMapper implements RMapper<String, String, String, Integer> {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1999434204321L;

	public static int count = 0;
	@Override
    public void map(String key, String value, RCollector<String, Integer> collector) {
		System.out.println(String.format("WordMapper.map index = %s, key = %s, value = %s", count++, key, value));
		
		String[] words = value.split("[^a-zA-Z]");
        
        for (String word : words) {
            collector.emit(word, 1);
            
        }
        
        
    }
    
}
