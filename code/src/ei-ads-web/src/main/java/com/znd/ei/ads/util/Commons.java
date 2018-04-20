package com.znd.ei.ads.util;


import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Component;

/**
 * 主题公共函数
 * <p>
 * Created by 13 on 2017/2/21.
 */
@Component
public final class Commons {


    public static String THEME = "themes/default";



    /**
     * 在管理员页面退出登录返回到登录界面
     * @return
     */
    public static String site_login() {
        return "login";
    }
}
