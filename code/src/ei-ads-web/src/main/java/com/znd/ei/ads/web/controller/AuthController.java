package com.znd.ei.ads.web.controller;

import java.io.IOException;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.znd.ei.ads.web.exception.TipException;
import com.znd.ei.ads.web.util.Commons;
import com.znd.ei.ads.web.util.WebConst;

/**
 * 用户后台登录/登出
 * @author wangheng
 * @date 2018年2月26日
 * @time 下午3:43:31
 * @type_name AuthControler
 */
@Controller
@RequestMapping("/admin")
@Transactional(rollbackFor = TipException.class)
public class AuthController {
	 private final Logger logger = LoggerFactory.getLogger(AuthController.class);
	 
    /**
     * 注销
     * @param session
     * @param response
     */
    @RequestMapping("/logout")
    public void logout(HttpSession session, HttpServletResponse response, HttpServletRequest request) {
        session.removeAttribute(WebConst.LOGIN_SESSION_KEY);
        Cookie cookie = new Cookie(WebConst.USER_IN_COOKIE, "");
        cookie.setMaxAge(0);
        response.addCookie(cookie);
        try {
            //response.sendRedirect(Commons.site_url());
            response.sendRedirect(Commons.site_login());
        } catch (IOException e) {
            e.printStackTrace();
            logger.error("注销失败", e);
        }
    }
    
    
    @GetMapping("/login")
    public String login() {
        return "admin/login";
    }
}
