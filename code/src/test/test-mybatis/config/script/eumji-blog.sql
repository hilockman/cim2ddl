-- MySQL dump 10.13  Distrib 5.7.18, for Linux (x86_64)
--
-- Host: localhost    Database: zblog
-- ------------------------------------------------------
-- Server version	5.7.18-0ubuntu0.17.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `article`
--

DROP TABLE IF EXISTS `article`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `article` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `categoryId` int(11) NOT NULL COMMENT '分类Id',
  `title` varchar(40) NOT NULL COMMENT '标题',
  `content` longtext NOT NULL COMMENT '内容',
  `description` varchar(500) NOT NULL COMMENT '文章简介  用于列表显示',
  `status` int(11) NOT NULL DEFAULT '0' COMMENT '状态 0：正常  1：不可用',
  `author` varchar(15) DEFAULT 'Coriger' COMMENT '作者',
  `createTime` datetime NOT NULL COMMENT '发表时间',
  `updateTime` datetime DEFAULT NULL COMMENT '发表时间',
  `showCount` int(11) NOT NULL DEFAULT '0' COMMENT '浏览量',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=259926 DEFAULT CHARSET=utf8 COMMENT='文章表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `article`
--

LOCK TABLES `article` WRITE;
/*!40000 ALTER TABLE `article` DISABLE KEYS */;
INSERT INTO `article` VALUES (255544,9999,'开源博客 - EumJi-blog使用篇','>转载请注明出处 http://www.eumji025.com/article/details/255544\n\n## 前言\n\n前面一节简单的介绍了[blog的来源和页面展示](http://www.eumji025.com/article/details/255897)。本节主要讲述一下如果运行和使用eumji-blog以及自己开发过程中的一些故事。\n\n2017年5月19日更新\n由于zblog已经被别人使用，怕被别人请去喝茶，zblog正式改名为EumJi-blog。\n\n## 博客使用\n\n### 运行步骤\n\n1.下载[eumji-blog源码](https://github.com/eumji025/EumJi-blog);\n2.修改数据库连接信息；\n\n3.将eumji-blog的sql文件导入到mysql数据库中(不支持oracle，别问我为什么)；\n\n4.直接使用maven工具 mvn package -DskipTests进行打包；\n\n5.使用命令 **java -jar target/eumji-blog.jar** 运行项目\n\n6.访问 **http://localhost:8080** 进入主页\n\n### 后台模块\n\n **http://localhost:8080/login** 进行登陆\n\n默认账号密码 admin/admin\n\n随后随便你增删改查！！！哈哈\n\n## 技术难度评估\n\n​	说实话这个博客的技术难度较小，技术栈要求不高，稍微懂点spring及spring boot框架技术就能搞定，thymeleaf模板语言的语法也很简单易学，spring-boot也是可以很快入门。对于作者来说最难的莫过于CSS和JS了，各种插件整的头晕。说实话代码很烂很杂，别问我为什么用有勇气放出来，没有打击就没有进步，我也想有大牛带我装逼带我飞。\n\n##  开发过程\n其实当时确实比较忙，我也想写点东西的，一直也没什么时间。\n只记得那时候又一次git reset 操作让我几个小时的成果成为炮灰，从此之后大事小事都提交。\n然后就是弄前端比较久，因为太多东西不懂了，一直都再改。后端难度较低，花费的时间较少，当然存在很多`烂代码`,后续会进行重构的。\n\n## 后续规划\n\n后续的整体计划是：\n\n1.完善当前版本；\n\n2.前后端分离;\n\n3.展示和后台管理模块分离；\n\n如果可以的话前端会来一次大改造。前提是有人支援我。\n\n## 结语\n\n我也不知道该说些什么，感觉仅仅适合入门玩玩。\n如果想部署到服务器请参看[服务器环境搭建篇](http://www.eumji025.com/article/details/252042)\n\n搜索优化对自己来说才是真正的难点，各种不懂，各种百度，google，比使用IDE发布有难度的多，更具有挑战性，可以从中学习到很多新的东西。\n\n总结一点：实践出真知。\n\n与君共勉！！！\n\n\n\n\n\n\n\n\n\n','本篇主要介绍如何运行本项目，其实和普通项目没什么区别，只是打包成了可执行得jar包。非常符合spring boot的特性。',1,'eumji','2017-05-18 20:03:01','2017-05-19 19:27:57',1232),(255897,9999,'开源博客 -EumJi-Blog简介篇','>转载请注明博客出处 http://www.eumji025.com/article/details/255897\n\n## 前言\n\n​	一直都准备做一个博客系统，直到四月份才真正的拉开序幕，之前自己没能调整好状态，越发的感慨要静下心好好做点东西。四月份下定决心要开始做出这个项目，此博客系统大部分都是在晚上或者周末抽空开发的，中间肯定存在着许多的不足和BUG，希望大家能踊跃的反馈给我。可以在[issues](https://github.com/eumji025/EumJi-blog/issues)提出以及发送邮件到eumji025@gmail.com 目前代码已经托管在github，欢迎大家star和fork，也鼓励大家进行二次开发。\n\n面临毕业有点小忙，若未能及时反馈，请见谅。\n\n作品演示站：http://www.eumji025.com/\n\n源码地址： https://github.com/eumji025/EumJi-blog\n\n本站鸣谢 程序员DD | 翟永超 以及 hexo主题 icarus ！！！大部分的前端博客页面都是使用的icarus主题。后台管理界面则是使用一些jquery的插件构成。\n\n2017年5月20日更新\n博客改名：\n原因是z-blog是别人已经投入运营，所以本人就老老实实的换了，意义不大。\n\n## 初衷\n\n​	在做本博客之前个人使用过CSDN，hexo等一些博客，或多或少都有一些自己的想法，一直都想做自己的博客系统，无奈自己前端学的菜，总给自己找了许多的借口去推辞，没能下定决心去尝试。\n\n​	自己学习WEB方面的技术也有很长时间了，一直都是做一些很基础的东西，没有挑战自己，更确切的说是自己太懒撒，觉得前端太麻烦而不愿意花费精力。下定决心做这个博客也是因为自己面临毕业，很多东西确实应该尝试。也是顺其自然应该进行的事情，只是取决于做一个什么样的作品。光说不练假把式这句话很精髓，道理谁都懂，只是能动手的人微乎其微。\n\n​	在编写EumJi-blog（博客系统名称）之前，自己也在担心前端的问题，本来是打算和好朋友一起做的，只是实习期大家都很忙，于是在没有办法的情况硬着头皮自己去做，其实大部分页面都是找的模板，各种模板拼凑而成的第一版博客。只是各种模板的兼容性不佳，导致期间也遇到了很多的困难，而且很多自己前端知识不懂，于是花费了很大的精力去研究。至于为什么选择editor.md作为markdown编辑器，那是因为文档齐全，有教程简单易学。我想markdown是写博客的必备技能吧。\n\n\n## 效果图\n\n首页展示部分\n\n![首页](http://of8rkrh1w.bkt.clouddn.com//2017/05/18/my-blog-home.png)\n\n文章详情页\n\n![文章详情](http://of8rkrh1w.bkt.clouddn.com//2017/05/18/my-blog-article.png)\n\n关于我\n\n![关于作者](http://of8rkrh1w.bkt.clouddn.com//2017/05/18/my-blog-aboutme.png)\n\n后端总览界面\n\n![后台管理界面](http://of8rkrh1w.bkt.clouddn.com//2017/05/18/my-blog-admin-article-list.png)\n\nmarkdown编辑器\n\n![markdown界面](http://of8rkrh1w.bkt.clouddn.com//2017/05/18/my-blog-article-markdown.png)\n\n## 技术栈\n\n### 后端\n\n- spring 服务\n- spring boot MVC\n- mybatis ORM\n- spring security 认证\n- redis（后续准备使用）\n\n### 前端\n\n- bootstrap\n- flavr（弹出层）\n- hexo主题 \n- editor.md (markdown编辑器)\n- 部分jquery插件\n- thymeleaf模板\n\n## zblog取名\n\n其实瞎取的一个，看名字都能知道是瞎搞的。哈哈！！\n\n## 结语\n\n本篇主要简单介绍一下eumji-blog的基本情况，下一篇[开源博客-使用篇](http://www.eumji025.com/article/details/255544)将对zblog的部署和技术进行介绍。\n\n与君共勉！！！\n\n## 源码地址\n\ngithub：[eumji-blog源码](https://github.com/eumji025/EumJi-blog.git)\ncsdn：[eumji-blog源码](https://code.csdn.net/jsu_9207/eumji-blog.git)\noschina:[eumji-blog源码](https://git.oschina.net/eumji025/zblog.git)\n\n\n\n\n\n\n\n','本文主要介绍自己的开源博客相关的情况和使用到的技术，希望有兴趣的朋友可以加入我一起去完善这个项目。',1,'eumji','2017-05-18 19:57:17','2017-05-22 16:29:56',492);
/*!40000 ALTER TABLE `article` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `articletag`
--

DROP TABLE IF EXISTS `articletag`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `articletag` (
  `articleId` int(11) NOT NULL COMMENT '文章Id',
  `tagId` int(11) NOT NULL COMMENT '标签Id',
  `tagName` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='文章标签中间表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `articletag`
--

LOCK TABLES `articletag` WRITE;
/*!40000 ALTER TABLE `articletag` DISABLE KEYS */;
INSERT INTO `articletag` VALUES (255897,9999,'default'),(255544,9999,'default');
/*!40000 ALTER TABLE `articletag` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `category`
--

DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `category` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `categoryName` varchar(20) NOT NULL COMMENT '分类名称  唯一',
  `aliasName` varchar(20) NOT NULL COMMENT '别名  唯一  比如新闻 就用News 代替  栏目Id不显示在url中',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序 （0-10）',
  PRIMARY KEY (`id`),
  UNIQUE KEY `aliasName_UNIQUE` (`aliasName`),
  UNIQUE KEY `categoryName_UNIQUE` (`categoryName`)
) ENGINE=InnoDB AUTO_INCREMENT=10000 DEFAULT CHARSET=utf8 COMMENT='分类表  只支持一级分类  如果需要分多个层次 用标签来协助实现';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `category`
--

LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES (9999,'未分类','default',0);
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `log`
--

DROP TABLE IF EXISTS `log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `log` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) DEFAULT NULL,
  `url` varchar(1024) DEFAULT NULL,
  `ip` varchar(20) DEFAULT NULL,
  `method` varchar(255) DEFAULT NULL,
  `args` varchar(255) DEFAULT NULL,
  `classMethod` varchar(255) DEFAULT NULL,
  `exception` varchar(2000) DEFAULT NULL,
  `operateTime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `log`
--

LOCK TABLES `log` WRITE;
/*!40000 ALTER TABLE `log` DISABLE KEYS */;
/*!40000 ALTER TABLE `log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `partner`
--

DROP TABLE IF EXISTS `partner`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `partner` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `siteName` varchar(15) NOT NULL COMMENT '站点名',
  `siteUrl` varchar(45) NOT NULL COMMENT '站点地址',
  `siteDesc` varchar(45) NOT NULL COMMENT '站点描述  简单备注 ',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='合作伙伴';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `partner`
--

LOCK TABLES `partner` WRITE;
/*!40000 ALTER TABLE `partner` DISABLE KEYS */;
/*!40000 ALTER TABLE `partner` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `partner`
--

LOCK TABLES `partner` WRITE;
/*!40000 ALTER TABLE `partner` DISABLE KEYS */;
INSERT INTO `partner` VALUES (1,'eumji | csdn','http://blog.csdn.net/jsu_9207','EumJi的CSDN博客',1),(2,'eumji | github','http://github.com/eumji025','EumJi的GitHub',1);
/*!40000 ALTER TABLE `partner` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tag`
--

DROP TABLE IF EXISTS `tag`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tag` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tagName` varchar(25) NOT NULL COMMENT '标签名称  唯一',
  `aliasName` varchar(20) NOT NULL COMMENT '标签别名 唯一',
  PRIMARY KEY (`id`),
  UNIQUE KEY `tagName_UNIQUE` (`tagName`)
) ENGINE=InnoDB AUTO_INCREMENT=10000 DEFAULT CHARSET=utf8 COMMENT='标签表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tag`
--

LOCK TABLES `tag` WRITE;
/*!40000 ALTER TABLE `tag` DISABLE KEYS */;
INSERT INTO `tag` VALUES (9999,'default','default');
/*!40000 ALTER TABLE `tag` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `username` varchar(20) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  `enabled` varchar(5) DEFAULT '0' COMMENT '是否被禁用',
  `credential` varchar(5) DEFAULT '0' COMMENT '凭证是否过期',
  `locked` varchar(5) DEFAULT '0' COMMENT '是否被锁',
  `expired` varchar(5) DEFAULT '0' COMMENT '是否过期',
  `createTime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;



--
-- Table structure for table `user`
--
DROP TABLE IF EXISTS `user_info`;
create table `user_info`
(
  username varchar(20) null,
  avatar varchar(255) null,
  nickname varchar(20) default 'EumJi' null comment '昵称',
  phone char(11) null comment '电话号码',
  email varchar(50) default 'eumji025@gmail.com' null comment '邮箱',
  signature varchar(2000) null comment '个性签名',
  address varchar(50) null comment '地址',
  announcement varchar(2000) null comment '公告',
  telegram varchar(20) default '18574406580' null comment 'telegram账号',
  wechart varchar(20) default 'jo__18' null comment '微信账号',
  constraint user_info_username_uindex
  unique (username)
) ENGINE=InnoDB DEFAULT CHARSET=utf8
  comment '用户信息表'
;

--
-- Dumping data for table `tag`
--

LOCK TABLES `user_info` WRITE;
/*!40000 ALTER TABLE `user_info` DISABLE KEYS */;
INSERT INTO `user_info` (username, avatar, nickname, phone, email, signature, address, announcement, telegram, wechart) VALUES ('admin', 'http://www.eumji025.com/image/avatar.jpg', 'EumJi', '18574406580', 'eumji025@gmail.com', '有些东西，看似离我们很近，但却很远，努力向它靠近，也许能触及到，也许触及不到，顺其自然，平常心对待，其他的都交给时间，或迟或早，都会有一个结果。', '中国 - 张家界', '作者原本单纯的做一个个人博客，所以很多的细节比较随意。<br>
                    目前项目已经托管在github和oschina上，准备长期去优化和维护。<br>
                    如果您有什么好的建议或者想法都可以通过邮件或者issue反馈给我，我会尽量及时的去处理。<br>
                    mail： eumji025@gmail.com<br>
                    github: https://github.com/eumji025/EumJi-blog/issues/ <br>
                    oschina: https://git.oschina.net/eumji025/zblog/issues<br>', '19574406580', 'jo__18');
/*!40000 ALTER TABLE `user_info` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'admin','FA5A66466E9006215E3F54BF5B2BEEA3','false','false','false','false','2017-05-17 14:32:13');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-05-25  9:07:35