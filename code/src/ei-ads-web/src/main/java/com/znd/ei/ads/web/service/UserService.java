package com.znd.ei.ads.web.service;


import com.znd.ei.ads.web.vo.User;
import com.znd.ei.ads.web.vo.UserInfo;

/**
* Created by GeneratorFx on 2017-04-11.
*/
public interface UserService {


    User loadUserByUsername(String username);

    UserInfo getUserInfo();

    void updateAvatar(String url, String username);

    void updatePassword(User user);

    void updateUserInfo(UserInfo userInfo);

    User getCurrentUser();
}
