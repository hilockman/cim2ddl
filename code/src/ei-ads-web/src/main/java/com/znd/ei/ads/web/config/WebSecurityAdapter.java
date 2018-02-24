package com.znd.ei.ads.web.config;

import org.springframework.context.annotation.Bean;
import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;

import com.znd.ei.ads.web.auth.CustomAuthenticationProvider;

/**
 * 
 * @author wangheng
 * @date 2018年2月24日
 * @time 下午3:56:37
 */
public class WebSecurityAdapter extends WebSecurityConfigurerAdapter {
	   @Override
	    protected void configure(HttpSecurity http) throws Exception {
	        http.csrf().disable();
	        http.authorizeRequests().antMatchers("/","/blog/**","/tag/**","friend","/login/**").permitAll()
	                .antMatchers("/admin/**").authenticated()
//	                .and().rememberMe().tokenValiditySeconds(3600)
	                .and().formLogin().loginPage("/login").defaultSuccessUrl("/home").permitAll()
	                .and().logout().logoutUrl("/admin/loginOut").permitAll();

	    }

	    @Override
	    public void configure(WebSecurity web) {
	        web.ignoring().antMatchers("**/js/**", "**/scripts/**", "**/css/**", "/vendor/**", "/image/**", "/admin/lib/**","/admin/plugins/**");
	    }


	    @Override
	    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
	        auth.authenticationProvider(authenticationProvider());
	    }

	    @Bean
	    public AuthenticationProvider authenticationProvider(){
	        return new CustomAuthenticationProvider();
	    }
}
