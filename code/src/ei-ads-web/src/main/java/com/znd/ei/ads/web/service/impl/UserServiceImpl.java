package com.znd.ei.ads.web.service.impl;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import com.znd.ei.ads.web.mapper.UserMapper;
import com.znd.ei.ads.web.service.UserService;
import com.znd.ei.ads.web.vo.User;
import com.znd.ei.ads.web.vo.UserInfo;

/**
 * Created by wangheng on 2018-02-24.
 */
@Service
@Transactional
public class UserServiceImpl implements UserService {

    @Autowired
    private UserMapper userMapper;

    @Override
    public User loadUserByUsername(String username) {
        return userMapper.getUser(username);
    }

    @Override
    public UserInfo getUserInfo() {
        return userMapper.getUserInfo();
    }

    @Override
    public void updateAvatar(String url, String username) {
        userMapper.updateAvatar(url,username);
    }

    @Override
    public void updatePassword(User user) {
        userMapper.updatePassword(user);
    }

    @Override
    public void updateUserInfo(UserInfo userInfo) {
        userMapper.updateUserInfo(userInfo);
    }

    @Override
    public User getCurrentUser() {
        HttpServletRequest request = ((ServletRequestAttributes) RequestContextHolder.getRequestAttributes()).getRequest();
        HttpSession session = request.getSession();
        return (User) session.getAttribute("user");
    }
}


