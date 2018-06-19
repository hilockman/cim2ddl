package com.znd.ads.property;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.znd.ads.annotation.Comment;
import com.znd.ads.annotation.ForeignColumn;
import com.znd.ads.mapper.ForeignKeysMapper;
import com.znd.ads.model.dto.ForeignKeyValue;
import com.znd.bus.reflection.Reflector;

public class PropertyResolver {

	private final Class<?> type;
	private final  Reflector reflector;
	private final List<PropertyItem> properties = new ArrayList<>();
	private final List<PropertyItem> groups = new ArrayList<>();
	private final Map<String, List<PropertyItem>> groupListMap = new HashMap<>();
	private final Map<String, PropertyItem> propertyMap = new HashMap<>();
	
	
	private String name;
	
	//private ForeignKeysMapper mapper;
	public PropertyResolver(Class<?> type, ForeignKeysMapper mapper) {
		this.type = type;
//		this.mapper = mapper;
		
		reflector = new Reflector(type);
		
//		String[] setNames = reflector.getGetablePropertyNames();
//		String[] getNames = reflector.getSetablePropertyNames();
		
		Comment typeComment = type.getAnnotation(Comment.class);
		if (typeComment != null) {
			name = typeComment.name();
		}
		if (name.isEmpty()) {
			name = type.getSimpleName();
		}
		for(Field field : type.getDeclaredFields()) {
			String name = field.getName();
			Method invoker = reflector.getGetInvoker(name);
			
			if (invoker == null)
				continue;
			
			Comment comment = field.getAnnotation(Comment.class);
			if (comment == null)
				continue;
			
			PropertyItem item = new PropertyItem();
			item.setGetInvoker(invoker);
			item.setSetInvoker(reflector.getSetInvoker(name));
			
			item.setDesc(name);
			if (comment != null) {
				item.setDesc(comment.alias());
				item.setGroup(comment.group());
				String optionValues = comment.tr();
				item.setOptionValues(optionValues);
			} 

						
			String group = item.getGroup();
			if (item.getGroup() == null) {
				group = "";
			}
			
			List<PropertyItem> groupList = groupListMap.get(group);
			if (groupList == null) {
				groupList = new ArrayList<>();
				groupListMap.put(group, groupList);
				PropertyItem groupItem = new PropertyItem();
				groupItem.setDesc(group);
				groupItem.setType(PropertyTypeEnum.p_group);
				groups.add(groupItem);
			}
			
			item.setName(name);
			item.setReadonly(item.getSetInvoker() == null);
			Class<?> fieldType = field.getType();
			if (fieldType == String.class) {
				item.setType(PropertyTypeEnum.p_string);
			} else if (fieldType == Double.class || fieldType == double.class) {
				item.setType(PropertyTypeEnum.p_double);
			} else if (fieldType == Integer.class || fieldType == int.class) {
				item.setType(PropertyTypeEnum.p_integer);
			} else if (fieldType == Boolean.class || fieldType == boolean.class) {
				item.setType(PropertyTypeEnum.p_boolean);
			} else if (fieldType.isEnum()) {
				item.setType(PropertyTypeEnum.p_enum);				
			}
			
			ForeignColumn fk = comment.fk();
			
			if (!fk.table().isEmpty()) {
				final String table = fk.table();
				final String valueColumn = fk.value();
				final String keyColumn = fk.key();
				item.setLoader(new ForeignKeysLoader() {
					
					@Override
					public String values() {
						  List<ForeignKeyValue> fkeys = mapper.getValues(table, keyColumn, valueColumn);
						  if (fkeys == null)
							  return "";
						  List<String> strs = new ArrayList<String>();
						  for (ForeignKeyValue v : fkeys) {
							  if (v == null)
								  continue;
							  strs.add(String.format("%s:%s", v.getKey(), v.getValue()));
						  }
						  return String.join(Comment.OPT_SPLIT, strs);		
					}
				});
			}
			properties.add(item);
			groupList.add(item);
			propertyMap.put(item.getName(), item);
		}
		
		groups.add(PropertyItem.NULL_GROUP);
	}


	public List<PropertyItem> getProperties() {
		return properties;
	}
	

	

	
	public PropertyItem getProperty(String property) {
		PropertyItem  item = propertyMap.get(property);
		if (item == null) {
			throw new PropertyException("Fail to find property :"+property+", in "+type);
		}
		
		return item;
	}
	
	public List<PropertyValue> toPropertyValues(Object obj) {
		try {
			return toValues(obj);
		} catch (Throwable e) {
			throw new PropertyException("Fail to parse property:"+type, e);
		}
	}
	
	private PropertyValue readPropertyValue(PropertyItem item, Object obj, String pid) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		PropertyValue gv1 = new PropertyValue();

		gv1.setValue(item.getGetInvoker().invoke(obj));
		gv1.setName(item.getDesc());
		gv1.setReadonly(item.getReadonly());
		gv1.setId(item.getName());
		gv1.setPid(pid);
		ForeignKeysLoader l = item.getLoader();
		if (l != null) {
			gv1.setOptionValues(l.values());
		} else {
			gv1.setOptionValues(item.getOptionValues());
		}
		
		

		return gv1;
	}
	
	private List<PropertyValue> toValues(Object obj) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		List<PropertyValue> values = new ArrayList<>();
		
		
		//int groupStart = 0;
		List<PropertyItem> groupList = groupListMap.get("");
		for (int j = 0; groupList != null && j < groupList.size(); j++) {
			PropertyItem item = groupList.get(j);
			PropertyValue gv1 = readPropertyValue(item, obj, "-1");
					
			values.add(gv1);
		}
		
		int i = 0;
		for (; i < groups.size() - 1; i++) {
			PropertyItem g = groups.get(i);
			PropertyValue gv = new PropertyValue();
			gv.setId(""+i);
			gv.setName(g.getDesc());
			gv.setType(g.getType());
			
			values.add(gv);
			groupList = groupListMap.get(g.getDesc());
			for (int j = 0; j < groupList.size(); j++) {
				PropertyItem item = groupList.get(j);
				PropertyValue gv1 = readPropertyValue(item, obj, gv.getId());
				values.add(gv1);
			}
		}
		

		return values;
	}


	public String getName() {
		return name;
	}


	public List<PropertyValue> getDefault() {
		Constructor<?> c = reflector.getDefaultConstructor();
		try {
			Object obj = c.newInstance();
			return toPropertyValues(obj);
		} catch (Throwable e) {			
			throw new PropertyException("Fail to create instance :"+type, e);
		}
	}





//	public List<String> getForeignKeys(String property) {
//		PropertyItem item = getProperty(property);
//		ForeignKeysLoader loader = item.getLoader();
//		if (loader != null)
//			return loader.values();
//		
//		return null;
//	}
}
