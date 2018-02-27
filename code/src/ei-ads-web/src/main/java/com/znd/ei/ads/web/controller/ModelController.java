package com.znd.ei.ads.web.controller;

import java.util.Arrays;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/model")
public class ModelController {
    @GetMapping("/categories")
    public List getCategories() {
        return Arrays.asList("内存", "缓存");
    }
    
    @GetMapping("/category/{name}")
    public List getTables(@PathVariable String name) {
        return Arrays.asList("FState", "FDev");
    }
}
