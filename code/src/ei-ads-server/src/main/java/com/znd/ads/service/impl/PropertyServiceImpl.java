package com.znd.ads.service.impl;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.annotation.Comment;
import com.znd.ads.mapper.ForeignKeysMapper;
import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.ads.property.ForeignKeysLoader;
import com.znd.ads.property.PropertyException;
import com.znd.ads.property.PropertyItem;
import com.znd.ads.property.PropertyName;
import com.znd.ads.property.PropertyRegistory;
import com.znd.ads.property.PropertyResolver;
import com.znd.ads.service.PropertyService;
import com.znd.ei.Utils;

@Service
public class PropertyServiceImpl implements PropertyService {
	
	private PropertyRegistory propertyRegistory ;
	
	private String scanPackage = "com.znd";
	
	@Override
	public List getDefault(String type) {
		PropertyResolver resolver = propertyRegistory.getResolver(type);
		
		if (resolver == null)
			throw new PropertyException("Fail to find propert : "+type);
		
		return resolver.getDefault();
	}

	@Autowired
	public PropertyServiceImpl(ForeignKeysMapper mapper) {
	//	this.mapper = mapper;
		propertyRegistory = new PropertyRegistory(mapper);
		//propertyRegistory.addType(PRAdequacySetting.class);
		addTypes();
	}
	
	private void addTypes() {
		 
		Set<Class<?>> classes = Utils.getClasses(scanPackage, (Class<?> c) -> (c.getAnnotation(Comment.class) != null));
		Iterator<Class<?>> it = classes.iterator();

		while (it.hasNext()) {
			Class<?> c = it.next();
			Comment comment = c.getAnnotation(Comment.class);
//			String name = comment.name();
//			if (name.isEmpty()) {
//				name = c.getSimpleName();
//			}

			propertyRegistory.addType(c);
		}
	}

	@Override
	public List getNames(String type) {
		PropertyResolver resolver = propertyRegistory.getResolver(type);
		
		if (resolver == null)
			throw new PropertyException("Fail to find property : "+type);
		
		return getPropertieNames(resolver);
	}
	
	
	private PropertyName toName(PropertyItem item) {
		PropertyName pn = new PropertyName();
		
		pn.setName(item.getDesc());
		pn.setReadonly(item.getReadonly());
		pn.setDesc(item.getName());
		pn.setGroup(item.getGroup());
		ForeignKeysLoader l = item.getLoader();
		if (l != null) {
			pn.setOptionValues(l.values());
		} else {
			pn.setOptionValues(item.getOptionValues());
		}
		
		return pn;
	}
	public List<PropertyName> getPropertieNames(PropertyResolver resolver) {
		List<PropertyItem> properties = resolver.getProperties();
		List<PropertyName> names = new ArrayList<>();
		for(PropertyItem item : properties) {
			PropertyName pn = toName(item);
			names.add(pn);
		}
		return names;
	}

	@Override
	public PropertyName findName(String type, String name) {
		PropertyResolver resolver = propertyRegistory.getResolver(type);
		
		if (resolver == null)
			throw new PropertyException("Fail to find property : "+type);
		
		List<PropertyItem> properties = resolver.getProperties();
		List<PropertyName> names = new ArrayList<>();
		for(PropertyItem item : properties) {
			if (item.getName().compareTo(name) == 0)
			 return toName(item);
		}
		
		return null;
	}


}
