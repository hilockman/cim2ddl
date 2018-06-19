package com.znd.ads.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ads.property.PropertyName;
import com.znd.ads.service.PropertyService;

@Controller
@RequestMapping("/property")
public class PropertyController {
	@Autowired
	private PropertyService propertyService;
	
	
	
//	@GetMapping("/foreignKeys/{type}/{property}")
//	public @ResponseBody List getForeignKeys(@PathVariable String type, @PathVariable String property) {
//		return propertyService.getForeignKeys(type, property);
//	}
    @GetMapping("/default/{type}")
    public @ResponseBody List getConfig(@PathVariable String type) {
    	return propertyService.getDefault(type);
    }
    
    @GetMapping("/names/{type}")
    public @ResponseBody List getNames(@PathVariable String type) {
    	return propertyService.getNames(type);
    }    
    
    @GetMapping("/name/{type}/{name}")
    public @ResponseBody PropertyName findNames(@PathVariable String type, @PathVariable String name) {
    	return propertyService.findName(type, name);
    }
    
}
