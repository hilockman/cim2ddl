package com.ei.ads.server;

import java.util.List;

import org.junit.Test;

import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.ads.property.PropertyItem;
import com.znd.ads.property.PropertyResolver;

public class PropertyResolverTest {

	@Test
	public void testProperties() {
		PropertyResolver pr = new PropertyResolver(PRAdequacySetting.class, null);
		List<PropertyItem> properties = pr.getProperties();
		for (PropertyItem p: properties) {
			System.out.println(p);
		}
	}
}
