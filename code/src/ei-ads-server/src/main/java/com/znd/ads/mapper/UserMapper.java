package com.znd.ads.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import com.znd.ads.vo.User;
import com.znd.ads.vo.UserInfo;

/**
 * 
 * @author wangheng
 * @date 2018年2月24日
 * @time 下午4:26:26
 * @type_name UserMapper
 */
@Mapper
public interface UserMapper {
    /**
     * 获取用户凭证
     * @param username 账号
     * @return
     */
    User getUser(@Param("username") String username);

    /**
     * 获取所有的用户
     * @return
     */
    List<User> allUser();

    UserInfo getUserInfo();

    void updateAvatar(@Param("url") String url, @Param("username") String username);

    void updatePassword(User user);

    void updateUserInfo(UserInfo userInfo);
}
