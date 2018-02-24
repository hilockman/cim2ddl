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
INSERT INTO `user_info` (username, avatar, nickname, phone, email, signature, address, announcement, telegram, wechart) VALUES ('admin', '', 'admin', '1', 'admin@gmail.com', '', '', '', '', '');
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