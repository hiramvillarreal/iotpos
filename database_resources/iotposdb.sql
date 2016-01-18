-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (armv7l)
--
-- Host: localhost    Database: lemondb
-- ------------------------------------------------------
-- Server version	5.5.46-0+deb7u1

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
-- Table structure for table `balances`
--

DROP TABLE IF EXISTS `balances`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `balances` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `datetime_start` datetime NOT NULL DEFAULT '2009-01-01 00:00:00',
  `datetime_end` datetime NOT NULL DEFAULT '2009-01-01 00:00:00',
  `userid` bigint(20) unsigned NOT NULL,
  `usern` varchar(50) NOT NULL,
  `initamount` double NOT NULL,
  `in` double NOT NULL,
  `out` double NOT NULL,
  `cash` double NOT NULL,
  `card` double NOT NULL,
  `transactions` varchar(1000) NOT NULL,
  `terminalnum` bigint(20) unsigned NOT NULL,
  `cashflows` varchar(1000) DEFAULT '',
  `done` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `SEC` (`datetime_start`,`datetime_end`,`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=94 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `balances`
--

LOCK TABLES `balances` WRITE;
/*!40000 ALTER TABLE `balances` DISABLE KEYS */;
INSERT INTO `balances` VALUES (1,'2015-12-28 12:11:06','2015-12-28 12:11:06',0,'',0,0,0,0,0,'',1,'',0),(2,'2015-12-28 12:11:06','2015-12-28 12:11:06',1,'admin',0,0,0,0,0,'',1,'',0),(3,'2015-12-28 12:11:06','2015-12-28 12:11:06',1,'admin',0,0,0,0,0,'',1,'',0),(4,'2015-12-28 12:16:08','2015-12-28 12:16:08',1,'admin',0,0,0,0,0,'',1,'',0),(5,'2015-12-28 12:16:08','2015-12-28 12:16:08',1,'admin',0,0,0,0,0,'',1,'',0),(6,'2015-12-28 12:22:52','2015-12-28 12:25:32',1,'admin',100,120,0,220,0,'4,5',1,NULL,1),(7,'2015-12-28 12:36:21','2015-12-28 21:54:11',1,'admin',100,60,0,160,0,'7',1,NULL,1),(8,'2015-12-28 22:05:11','2015-12-28 22:09:54',1,'admin',100,0,0,100,0,'',1,NULL,1),(9,'2015-12-28 22:10:11','2015-12-28 22:13:26',1,'admin',100,180,0,280,0,'10,11,12',1,NULL,1),(10,'2015-12-28 22:22:07','2015-12-28 22:22:49',1,'admin',100,60,0,160,0,'15',1,NULL,1),(11,'2015-12-28 22:23:17','2015-12-28 22:23:58',1,'admin',100,0,0,100,0,'',1,NULL,1),(12,'2015-12-28 22:32:35','2015-12-28 22:32:40',1,'admin',100,0,0,100,0,'',1,NULL,1),(13,'2015-12-28 22:32:52','2015-12-28 22:32:52',1,'admin',100,0,0,100,0,'',1,'',0),(14,'2015-12-28 22:32:52','2015-12-28 22:34:22',1,'admin',100,0,0,100,0,'',1,NULL,1),(15,'2015-12-28 22:34:41','2015-12-28 22:34:51',1,'admin',100,60,0,160,0,'21',1,NULL,1),(16,'2015-12-28 22:38:38','2015-12-28 22:38:58',1,'admin',100,60,0,160,0,'23',1,NULL,1),(17,'2015-12-28 22:43:57','2015-12-28 22:44:54',1,'admin',100,60,0,160,0,'25',1,NULL,1),(18,'2015-12-28 22:45:56','2015-12-28 22:46:52',1,'admin',100,60,0,160,0,'27',1,NULL,1),(19,'2015-12-29 10:07:01','2015-12-29 10:07:31',1,'admin',100,10,0,110,0,'29',1,NULL,1),(20,'2015-12-29 10:11:16','2015-12-29 11:51:40',1,'admin',100,190,0,290,0,'31,32,33,34',1,NULL,0),(21,'2015-12-29 13:00:38','2015-12-29 13:00:38',1,'admin',0,0,0,0,0,'',1,'',0),(22,'2015-12-29 17:36:30','2015-12-29 17:36:56',1,'admin',100,60,0,160,0,'36',1,NULL,1),(23,'2015-12-29 17:37:20','2015-12-29 17:37:20',1,'admin',100,0,0,100,0,'',1,NULL,0),(24,'2015-12-29 17:37:20','2015-12-29 17:37:41',1,'admin',100,60,0,160,0,'39',1,NULL,1),(25,'2015-12-29 17:38:21','2015-12-29 17:39:32',1,'admin',100,60,0,160,0,'41',1,NULL,1),(26,'2015-12-29 17:40:25','2015-12-29 17:40:55',1,'admin',100,60,0,160,0,'43',1,NULL,1),(27,'2015-12-29 18:56:30','2015-12-29 18:56:37',1,'admin',100,0,0,100,0,'',1,NULL,1),(28,'2015-12-29 18:57:01','2015-12-29 18:57:13',1,'admin',100,60,0,160,0,'46',1,NULL,1),(29,'2015-12-29 19:00:15','2015-12-29 19:00:28',1,'admin',100,60,0,160,0,'48',1,NULL,1),(30,'2015-12-29 19:35:35','2015-12-29 19:35:46',1,'admin',100,60,0,160,0,'50',1,NULL,1),(31,'2015-12-29 19:36:18','2015-12-29 19:36:18',1,'admin',100,0,0,100,0,'',1,'',0),(32,'2015-12-29 19:36:18','2015-12-29 19:37:31',1,'admin',100,60,0,160,0,'53',1,NULL,1),(33,'2015-12-29 19:38:09','2015-12-29 19:38:33',1,'admin',100,60,0,160,0,'55',1,NULL,1),(34,'2015-12-29 19:41:24','2015-12-29 19:41:38',1,'admin',100,60,0,160,0,'57',1,NULL,1),(35,'2015-12-29 19:42:06','2015-12-29 19:42:06',1,'admin',100,0,0,100,0,'',1,'',0),(36,'2015-12-29 19:42:06','2015-12-29 19:49:02',1,'admin',100,60,0,160,0,'60',1,NULL,1),(37,'2015-12-29 19:53:45','2015-12-29 19:54:08',1,'admin',100,60,0,160,0,'62',1,NULL,1),(38,'2015-12-29 19:55:52','2015-12-29 19:56:07',1,'admin',100,60,0,160,0,'64',1,NULL,1),(39,'2015-12-29 19:58:54','2015-12-29 19:59:26',1,'admin',100,120,0,220,0,'66,67',1,NULL,1),(40,'2015-12-29 20:01:50','2015-12-29 21:07:01',1,'admin',100,100,30,170,0,'69',1,NULL,1),(41,'2015-12-30 00:15:58','2015-12-30 00:43:22',1,'admin',100,0,0,100,0,'',1,NULL,1),(42,'2015-12-30 00:54:31','2015-12-30 00:54:31',1,'admin',100,0,0,100,0,'',1,NULL,0),(43,'2015-12-30 00:54:31','2015-12-30 01:22:33',1,'admin',100,0,0,100,0,'',1,NULL,1),(44,'2015-12-30 10:41:14','2015-12-30 10:42:15',1,'admin',100,0,0,100,0,'',1,NULL,1),(45,'2015-12-30 11:10:14','2015-12-30 11:14:08',1,'admin',100,80,5,175,0,'75,76',1,NULL,1),(46,'2015-12-30 11:20:30','2015-12-30 11:22:52',1,'admin',100,60,1,159,0,'78',1,NULL,1),(47,'2015-12-30 12:07:10','2015-12-30 12:15:29',1,'admin',100,0,0,100,0,'',1,NULL,1),(48,'2015-12-30 12:20:54','2015-12-30 12:27:08',1,'admin',100,60,12,148,0,'81',1,NULL,1),(49,'2015-12-30 13:36:00','2015-12-30 13:36:12',1,'admin',100,60,0,160,0,'83',1,NULL,1),(50,'2015-12-30 21:34:41','2015-12-30 21:35:34',1,'admin',100,0,0,100,0,'',1,NULL,1),(51,'2015-12-30 22:01:14','2015-12-30 22:05:30',1,'admin',100,0,0,100,0,'',1,NULL,1),(52,'2015-12-30 22:05:55','2015-12-30 22:06:21',1,'admin',100,140,0.009999999999990905,239.99,0,'88',1,NULL,1),(53,'2015-12-30 23:44:08','2015-12-30 23:44:19',1,'admin',100,60,0,160,0,'90',1,NULL,1),(54,'2015-12-30 23:44:49','2015-12-30 23:45:11',1,'admin',100,60,0,160,0,'92',1,NULL,1),(55,'2015-12-30 23:48:19','2015-12-30 23:48:37',1,'admin',100,80,0.010000000000005116,179.99,0,'94',1,NULL,1),(56,'2015-12-30 23:49:11','2015-12-30 23:49:35',1,'admin',100,80,0.010000000000005116,179.99,0,'96',1,NULL,1),(57,'2015-12-30 23:50:14','2015-12-30 23:50:31',1,'admin',100,80,0.010000000000005116,179.99,0,'98',1,NULL,1),(58,'2015-12-31 00:07:27','2015-12-31 00:08:23',1,'admin',100,45,0,145,0,'100',1,NULL,1),(59,'2015-12-31 00:39:12','2015-12-31 00:39:45',1,'admin',100,60,0,160,0,'102',1,NULL,1),(60,'2015-12-31 00:55:42','2015-12-31 00:56:04',1,'admin',100,60,0,160,0,'104',1,NULL,1),(61,'2015-12-31 07:43:24','2015-12-31 07:59:07',1,'admin',100,0,0,100,0,'',1,NULL,1),(62,'2015-12-31 08:03:14','2015-12-31 09:00:11',1,'admin',100,0,0,100,0,'',1,NULL,1),(63,'2015-12-31 08:21:31','2015-12-31 08:52:59',1,'admin',100,0,0,100,0,'',1,NULL,1),(64,'2015-12-31 09:16:53','2015-12-31 09:17:09',1,'admin',100,60,0,160,0,'109',1,NULL,1),(65,'2015-12-31 09:25:18','2015-12-31 09:26:37',1,'admin',100,140,0.009999999999990905,239.99,0,'111',1,NULL,1),(66,'2015-12-31 10:11:40','2015-12-31 10:15:28',1,'admin',100,140,0.009999999999990905,239.99,0,'113',1,NULL,1),(67,'2015-12-31 10:15:47','2015-12-31 10:16:13',1,'admin',100,110,0,210,0,'115',1,NULL,1),(68,'2015-12-31 10:50:15','2015-12-31 10:52:26',1,'admin',100,60,0,160,0,'117',1,NULL,1),(69,'2015-12-31 10:52:40','2015-12-31 11:04:10',1,'admin',100,60,0,160,0,'119',1,NULL,1),(70,'2016-01-01 16:09:43','2016-01-01 16:10:32',1,'admin',100,140,0.009999999999990905,239.99,0,'121',1,NULL,1),(71,'2016-01-01 16:21:55','2016-01-01 16:25:43',1,'admin',100,70,0,170,0,'123,124',1,NULL,1),(72,'2016-01-01 16:25:48','2016-01-01 16:25:48',1,'admin',0,0,0,0,0,'',1,'',0),(73,'2016-01-01 16:26:41','2016-01-01 16:27:24',1,'admin',100,90,0,190,0,'126,127',1,NULL,1),(74,'2016-01-01 16:29:22','2016-01-01 17:24:27',1,'admin',100,120,0,220,0,'129,130',1,NULL,1),(75,'2016-01-01 18:03:51','2016-01-01 19:01:22',1,'admin',100,200,0.009999999999990905,299.99,0,'132,133',1,NULL,1),(76,'2016-01-01 19:01:53','2016-01-01 19:01:53',1,'admin',100,0,0,100,0,'',1,'',0),(77,'2016-01-01 19:39:22','2016-01-01 20:10:32',1,'admin',100,200,0.009999999999990905,299.99,0,'136,137',1,NULL,1),(78,'2016-01-01 20:17:16','2016-01-01 20:17:59',1,'admin',100,0,0,100,0,'',1,NULL,1),(79,'2016-01-01 20:21:35','2016-01-01 20:28:54',1,'admin',100,160,30.00999999999999,229.99,0,'141',1,NULL,1),(80,'2016-01-01 20:29:45','2016-01-01 20:29:56',1,'admin',100,50,0,150,0,'143',1,NULL,1),(81,'2016-01-01 21:37:45','2016-01-01 21:38:54',1,'admin',100,130,0,230,0,'145,146,147',1,NULL,0),(82,'2016-01-02 12:53:34','2016-01-02 12:55:30',1,'admin',100,90,0,190,0,'149,150',1,NULL,1),(83,'2016-01-03 15:10:38','2016-01-03 15:18:57',1,'admin',100,60,0,160,0,'152',1,NULL,1),(84,'2016-01-03 19:49:53','2016-01-03 19:53:17',1,'admin',100,150,0,250,0,'154,155,156',1,NULL,1),(85,'2016-01-03 19:54:55','2016-01-03 19:55:58',1,'admin',100,60,0,160,0,'158',1,NULL,1),(86,'2016-01-03 20:02:51','2016-01-03 20:04:53',1,'admin',100,60,0,160,0,'160',1,NULL,1),(87,'2016-01-03 20:11:48','2016-01-03 20:12:00',1,'admin',100,0,0,100,0,'',1,NULL,1),(88,'2016-01-03 22:11:13','2016-01-03 22:27:40',1,'admin',100,0,0,100,0,'',1,NULL,0),(89,'2016-01-03 22:11:13','2016-01-03 22:40:16',1,'admin',100,198,0,298,171,'164,165,166,167,168',1,'1,2,3',1),(90,'2016-01-03 22:41:04','2016-01-03 22:54:31',1,'admin',100,0,0,100,0,'',1,NULL,1),(91,'2016-01-04 10:18:59','2016-01-04 10:19:28',1,'admin',100,60,0,160,0,'171',1,NULL,1),(92,'2016-01-04 16:27:00','2016-01-04 17:09:33',1,'admin',100,133,1,232,10,'173,174,175',1,NULL,1),(93,'2016-01-05 10:51:58','2016-01-05 11:30:29',1,'admin',100,60,0,160,0,'177',1,NULL,1);
/*!40000 ALTER TABLE `balances` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bool_values`
--

DROP TABLE IF EXISTS `bool_values`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bool_values` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bool_values`
--

LOCK TABLES `bool_values` WRITE;
/*!40000 ALTER TABLE `bool_values` DISABLE KEYS */;
INSERT INTO `bool_values` VALUES (0,'NO'),(1,'YES');
/*!40000 ALTER TABLE `bool_values` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bundle_same`
--

DROP TABLE IF EXISTS `bundle_same`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bundle_same` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `product_id` bigint(20) unsigned NOT NULL,
  `qty` double NOT NULL DEFAULT '2',
  `price` double NOT NULL DEFAULT '2',
  PRIMARY KEY (`id`),
  KEY `SEC` (`product_id`,`qty`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bundle_same`
--

LOCK TABLES `bundle_same` WRITE;
/*!40000 ALTER TABLE `bundle_same` DISABLE KEYS */;
/*!40000 ALTER TABLE `bundle_same` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cardtypes`
--

DROP TABLE IF EXISTS `cardtypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cardtypes` (
  `typeid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`typeid`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cardtypes`
--

LOCK TABLES `cardtypes` WRITE;
/*!40000 ALTER TABLE `cardtypes` DISABLE KEYS */;
INSERT INTO `cardtypes` VALUES (1,'None'),(2,'Credit VISA'),(3,'Credit MC'),(4,'Debit VISA'),(5,'Debit MC');
/*!40000 ALTER TABLE `cardtypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cashflow`
--

DROP TABLE IF EXISTS `cashflow`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cashflow` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `type` smallint(5) unsigned NOT NULL DEFAULT '1',
  `userid` bigint(20) NOT NULL DEFAULT '1',
  `reason` varchar(255) DEFAULT '',
  `amount` double unsigned NOT NULL DEFAULT '0',
  `date` date NOT NULL DEFAULT '2009-01-01',
  `time` time NOT NULL DEFAULT '00:00:00',
  `terminalnum` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `SEC` (`date`,`time`,`type`,`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cashflow`
--

LOCK TABLES `cashflow` WRITE;
/*!40000 ALTER TABLE `cashflow` DISABLE KEYS */;
INSERT INTO `cashflow` VALUES (1,7,1,'Pago por Credito 1',100,'2016-01-03','22:34:21',1),(2,7,1,'Pago por Credito 1',37,'2016-01-03','22:38:10',1),(3,7,1,'Pago por Credito 1',34,'2016-01-03','22:39:44',1);
/*!40000 ALTER TABLE `cashflow` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cashflowtypes`
--

DROP TABLE IF EXISTS `cashflowtypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cashflowtypes` (
  `typeid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`typeid`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cashflowtypes`
--

LOCK TABLES `cashflowtypes` WRITE;
/*!40000 ALTER TABLE `cashflowtypes` DISABLE KEYS */;
INSERT INTO `cashflowtypes` VALUES (1,'Normal cash OUT'),(2,'Money return on ticket cancel'),(3,'Money return on product return'),(4,'Normal Cash IN'),(5,'Cash IN Reservation'),(6,'Cash OUT Reservation'),(7,'Cash IN Credit Payment'),(8,'Cash IN Debit');
/*!40000 ALTER TABLE `cashflowtypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `categories`
--

DROP TABLE IF EXISTS `categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `categories` (
  `catid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`catid`),
  KEY `SEC` (`text`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `categories`
--

LOCK TABLES `categories` WRITE;
/*!40000 ALTER TABLE `categories` DISABLE KEYS */;
INSERT INTO `categories` VALUES (1,'General');
/*!40000 ALTER TABLE `categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `clients`
--

DROP TABLE IF EXISTS `clients`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `clients` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `code` varchar(13) DEFAULT '000001',
  `name` varchar(255) DEFAULT '',
  `since` date NOT NULL DEFAULT '2009-01-01',
  `address` varchar(255) DEFAULT NULL,
  `phone` varchar(50) DEFAULT NULL,
  `phone_movil` varchar(50) DEFAULT NULL,
  `points` bigint(20) unsigned DEFAULT '0',
  `discount` double NOT NULL,
  `photo` blob,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clients`
--

LOCK TABLES `clients` WRITE;
/*!40000 ALTER TABLE `clients` DISABLE KEYS */;
INSERT INTO `clients` VALUES (1,'000001','General','2009-01-01',NULL,NULL,NULL,0,0,NULL),(2,'666666','Credito','2015-12-31','C credito','555 55555','555 55555',0,10,NULL);
/*!40000 ALTER TABLE `clients` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `config`
--

DROP TABLE IF EXISTS `config`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `config` (
  `firstrun` varchar(30) NOT NULL,
  `taxIsIncludedInPrice` tinyint(1) NOT NULL DEFAULT '1',
  `storeLogo` blob,
  `storeName` varchar(255) DEFAULT NULL,
  `storeAddress` varchar(255) DEFAULT NULL,
  `storePhone` varchar(100) DEFAULT NULL,
  `logoOnTop` tinyint(1) NOT NULL DEFAULT '1',
  `useCUPS` tinyint(1) NOT NULL DEFAULT '1',
  `smallPrint` tinyint(1) NOT NULL DEFAULT '1',
  `db_version` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`firstrun`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `config`
--

LOCK TABLES `config` WRITE;
/*!40000 ALTER TABLE `config` DISABLE KEYS */;
INSERT INTO `config` VALUES ('yes, it is February 6 1978',0,'','IotPOS store','Calle 5 #500','555-5555',0,0,1,'0950');
/*!40000 ALTER TABLE `config` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `credit_history`
--

DROP TABLE IF EXISTS `credit_history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `credit_history` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `customerid` bigint(20) unsigned NOT NULL,
  `saleid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `amount` double NOT NULL DEFAULT '0',
  `date` date NOT NULL,
  `time` time NOT NULL,
  PRIMARY KEY (`id`),
  KEY `SEC` (`customerid`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `credit_history`
--

LOCK TABLES `credit_history` WRITE;
/*!40000 ALTER TABLE `credit_history` DISABLE KEYS */;
INSERT INTO `credit_history` VALUES (1,2,164,18,'2016-01-03','22:33:09'),(2,2,165,27,'2016-01-03','22:33:33'),(3,2,0,-100,'2016-01-03','22:34:21'),(4,2,167,18,'2016-01-03','22:36:21'),(5,2,0,-37,'2016-01-03','22:38:10'),(6,2,168,108,'2016-01-03','22:39:11'),(7,2,0,-34,'2016-01-03','22:39:44');
/*!40000 ALTER TABLE `credit_history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `credits`
--

DROP TABLE IF EXISTS `credits`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `credits` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `customerid` bigint(20) unsigned NOT NULL,
  `total` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `SEC` (`customerid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `credits`
--

LOCK TABLES `credits` WRITE;
/*!40000 ALTER TABLE `credits` DISABLE KEYS */;
INSERT INTO `credits` VALUES (1,2,0);
/*!40000 ALTER TABLE `credits` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currencies`
--

DROP TABLE IF EXISTS `currencies`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `currencies` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(512) DEFAULT NULL,
  `factor` double NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `currencies`
--

LOCK TABLES `currencies` WRITE;
/*!40000 ALTER TABLE `currencies` DISABLE KEYS */;
/*!40000 ALTER TABLE `currencies` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `departments`
--

DROP TABLE IF EXISTS `departments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `departments` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `departments`
--

LOCK TABLES `departments` WRITE;
/*!40000 ALTER TABLE `departments` DISABLE KEYS */;
INSERT INTO `departments` VALUES (1,'General');
/*!40000 ALTER TABLE `departments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `facturas_cbb`
--

DROP TABLE IF EXISTS `facturas_cbb`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `facturas_cbb` (
  `fecha` date NOT NULL DEFAULT '2012-01-01',
  `folio` varchar(100) NOT NULL,
  `folio_num_autorizacion` varchar(100) NOT NULL,
  `folio_fecha_autorizacion` date NOT NULL,
  `valida` tinyint(1) NOT NULL DEFAULT '1',
  `nombre_cliente` varchar(100) DEFAULT '',
  `rfc_cliente` varchar(100) DEFAULT '',
  `direccion_cliente` varchar(255) DEFAULT '',
  `transaction_id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `subtotal` double unsigned NOT NULL DEFAULT '0',
  `impuestos` double unsigned NOT NULL DEFAULT '0',
  `impuestos_tasa` double unsigned NOT NULL DEFAULT '0',
  `descuentos` double unsigned NOT NULL DEFAULT '0',
  `total` double unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`folio`),
  KEY `SEC` (`nombre_cliente`,`rfc_cliente`,`valida`,`fecha`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `facturas_cbb`
--

LOCK TABLES `facturas_cbb` WRITE;
/*!40000 ALTER TABLE `facturas_cbb` DISABLE KEYS */;
/*!40000 ALTER TABLE `facturas_cbb` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `folios_cbb`
--

DROP TABLE IF EXISTS `folios_cbb`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `folios_cbb` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `pool_id` varchar(100) NOT NULL,
  `numero` varchar(100) NOT NULL,
  `usado` tinyint(1) NOT NULL DEFAULT '1',
  `valido` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`numero`),
  UNIQUE KEY `numero` (`numero`),
  KEY `SEC` (`pool_id`,`usado`,`valido`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `folios_cbb`
--

LOCK TABLES `folios_cbb` WRITE;
/*!40000 ALTER TABLE `folios_cbb` DISABLE KEYS */;
/*!40000 ALTER TABLE `folios_cbb` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `folios_pool`
--

DROP TABLE IF EXISTS `folios_pool`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `folios_pool` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `fecha_aprobacion` date NOT NULL,
  `num_aprobacion` varchar(100) NOT NULL,
  `folio_inicial` varchar(100) NOT NULL,
  `folio_final` varchar(100) NOT NULL,
  `cbb` blob,
  `cantidad` bigint(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`,`num_aprobacion`),
  UNIQUE KEY `num_aprobacion` (`num_aprobacion`),
  KEY `SEC` (`fecha_aprobacion`,`num_aprobacion`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `folios_pool`
--

LOCK TABLES `folios_pool` WRITE;
/*!40000 ALTER TABLE `folios_pool` DISABLE KEYS */;
/*!40000 ALTER TABLE `folios_pool` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `logs`
--

DROP TABLE IF EXISTS `logs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `logs` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `userid` bigint(20) unsigned NOT NULL,
  `date` varchar(20) NOT NULL DEFAULT '2009-01-01',
  `time` varchar(20) NOT NULL DEFAULT '00:00',
  `action` varchar(512) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=111 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `logs`
--

LOCK TABLES `logs` WRITE;
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
INSERT INTO `logs` VALUES (1,1,'2015-12-28','12:21','[SQUEEZE] Purchase #1 - 100 x Producto1 (1)'),(2,1,'2015-12-28','12:21','[SQUEEZE] Purchase #2 - 100 x Producto2 (2)'),(3,1,'2015-12-28','12:22','[SQUEEZE] Purchase #3 - 0 x Producto3 (3)'),(4,1,'2015-12-28','12:22','[SQUEEZE] CorreciÃ³n de Inventario: [3] de 0 a 100. RazÃ³n:Adjust'),(5,1,'2015-12-28','12:22','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(6,1,'2015-12-28','12:36','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(7,1,'2015-12-28','22:05','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(8,1,'2015-12-28','22:10','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(9,1,'2015-12-28','22:22','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(10,1,'2015-12-28','22:22','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:22'),(11,1,'2015-12-28','22:22','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:22'),(12,1,'2015-12-28','22:23','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(13,1,'2015-12-28','22:23','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:23'),(14,1,'2015-12-28','22:32','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(15,1,'2015-12-28','22:32','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(16,1,'2015-12-28','22:32','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:32'),(17,1,'2015-12-28','22:33','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:33'),(18,1,'2015-12-28','22:34','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(19,1,'2015-12-28','22:38','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(20,1,'2015-12-28','22:43','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(21,1,'2015-12-28','22:44','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:44'),(22,1,'2015-12-28','22:44','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:44'),(23,1,'2015-12-28','22:44','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:44'),(24,1,'2015-12-28','22:45','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(25,1,'2015-12-28','22:46','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:46'),(26,1,'2015-12-29','10:07','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(27,1,'2015-12-29','10:07','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 10:07'),(28,1,'2015-12-29','10:11','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(29,1,'2015-12-29','17:36','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(30,1,'2015-12-29','17:37','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(31,1,'2015-12-29','17:38','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(32,1,'2015-12-29','17:40','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(33,1,'2015-12-29','18:56','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(34,1,'2015-12-29','18:57','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(35,1,'2015-12-29','19:00','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(36,1,'2015-12-29','19:35','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(37,1,'2015-12-29','19:36','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(38,1,'2015-12-29','19:36','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:36'),(39,1,'2015-12-29','19:36','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:36'),(40,1,'2015-12-29','19:37','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:37'),(41,1,'2015-12-29','19:38','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(42,1,'2015-12-29','19:38','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:38'),(43,1,'2015-12-29','19:41','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(44,1,'2015-12-29','19:42','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(45,1,'2015-12-29','19:53','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(46,1,'2015-12-29','19:55','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(47,1,'2015-12-29','19:58','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(48,1,'2015-12-29','20:01','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(49,1,'2015-12-30','00:15','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(50,1,'2015-12-30','00:54','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(51,1,'2015-12-30','10:41','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(52,1,'2015-12-30','11:10','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(53,1,'2015-12-30','11:20','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(54,1,'2015-12-30','12:07','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(55,1,'2015-12-30','12:20','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(56,1,'2015-12-30','13:36','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(57,1,'2015-12-30','21:34','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(58,1,'2015-12-30','22:01','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(59,1,'2015-12-30','22:05','[SQUEEZE] Purchase #87 - 1 x Paquete1 (4)'),(60,1,'2015-12-30','22:05','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(61,1,'2015-12-30','23:44','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(62,1,'2015-12-30','23:44','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(63,1,'2015-12-30','23:48','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(64,1,'2015-12-30','23:49','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(65,1,'2015-12-30','23:50','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(66,1,'2015-12-31','00:07','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(67,1,'2015-12-31','00:39','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(68,1,'2015-12-31','00:39','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2015-12-31 00:39'),(69,1,'2015-12-31','00:55','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(70,1,'2015-12-31','07:43','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(71,1,'2015-12-31','08:03','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(72,1,'2015-12-31','08:21','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(73,1,'2015-12-31','09:16','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(74,1,'2015-12-31','09:25','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(75,1,'2015-12-31','10:11','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(76,1,'2015-12-31','10:15','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(77,1,'2015-12-31','10:50','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(78,1,'2015-12-31','10:50','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2015-12-31 10:50'),(79,1,'2015-12-31','10:51','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2015-12-31 10:51'),(80,1,'2015-12-31','10:52','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(81,1,'2015-12-31','10:52','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2015-12-31 10:52'),(82,1,'2016-01-01','16:09','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(83,1,'2016-01-01','16:21','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(84,1,'2016-01-01','16:26','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(85,1,'2016-01-01','16:29','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(86,1,'2016-01-01','18:03','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(87,1,'2016-01-01','19:01','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(88,1,'2016-01-01','19:01','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2016-01-01 19:01'),(89,1,'2016-01-01','19:39','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(90,1,'2016-01-01','20:17','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(91,1,'2016-01-01','20:21','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(92,1,'2016-01-01','20:29','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(93,1,'2016-01-01','21:37','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(94,1,'2016-01-01','22:03','[SQUEEZE] CorreciÃ³n de Inventario: [1] de 0 a 100. RazÃ³n:sin'),(95,1,'2016-01-02','12:53','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(96,1,'2016-01-03','15:10','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(97,1,'2016-01-03','19:49','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(98,1,'2016-01-03','19:54','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(99,1,'2016-01-03','19:55','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2016-01-03 19:55'),(100,1,'2016-01-03','20:02','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(101,1,'2016-01-03','20:11','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(102,1,'2016-01-03','22:11','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(103,1,'2016-01-03','22:34','[ LEMON ] Entrada de Efectivo [100.00] para Pago del Credito 1, por Administrador en terminal 1 el 2016-01-03 22:34'),(104,1,'2016-01-03','22:38','[ LEMON ] Entrada de Efectivo [37.00] para Pago del Credito 1, por Administrador en terminal 1 el 2016-01-03 22:38'),(105,1,'2016-01-03','22:39','[ LEMON ] Entrada de Efectivo [34.00] para Pago del Credito 1, por Administrador en terminal 1 el 2016-01-03 22:39'),(106,1,'2016-01-03','22:41','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(107,1,'2016-01-03','22:41','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrador en terminal 1 el 2016-01-03 22:41'),(108,1,'2016-01-04','10:18','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(109,1,'2016-01-04','16:27','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(110,1,'2016-01-05','10:51','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1');
/*!40000 ALTER TABLE `logs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m2m_category_subcategory`
--

DROP TABLE IF EXISTS `m2m_category_subcategory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m2m_category_subcategory` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `category` int(10) unsigned DEFAULT '0',
  `subcategory` int(10) unsigned DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `SEC` (`subcategory`,`category`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m2m_category_subcategory`
--

LOCK TABLES `m2m_category_subcategory` WRITE;
/*!40000 ALTER TABLE `m2m_category_subcategory` DISABLE KEYS */;
/*!40000 ALTER TABLE `m2m_category_subcategory` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m2m_department_category`
--

DROP TABLE IF EXISTS `m2m_department_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m2m_department_category` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `department` int(10) unsigned DEFAULT '0',
  `category` int(10) unsigned DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `SEC` (`department`,`category`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m2m_department_category`
--

LOCK TABLES `m2m_department_category` WRITE;
/*!40000 ALTER TABLE `m2m_department_category` DISABLE KEYS */;
/*!40000 ALTER TABLE `m2m_department_category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `measures`
--

DROP TABLE IF EXISTS `measures`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `measures` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `measures`
--

LOCK TABLES `measures` WRITE;
/*!40000 ALTER TABLE `measures` DISABLE KEYS */;
INSERT INTO `measures` VALUES (1,'Pc'),(2,'Kg');
/*!40000 ALTER TABLE `measures` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `offers`
--

DROP TABLE IF EXISTS `offers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `offers` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `discount` double NOT NULL,
  `datestart` date NOT NULL DEFAULT '2009-01-01',
  `dateend` date NOT NULL DEFAULT '2009-01-01',
  `product_id` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `offers`
--

LOCK TABLES `offers` WRITE;
/*!40000 ALTER TABLE `offers` DISABLE KEYS */;
/*!40000 ALTER TABLE `offers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `paytypes`
--

DROP TABLE IF EXISTS `paytypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `paytypes` (
  `typeid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`typeid`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `paytypes`
--

LOCK TABLES `paytypes` WRITE;
/*!40000 ALTER TABLE `paytypes` DISABLE KEYS */;
INSERT INTO `paytypes` VALUES (1,'Cash'),(2,'Card'),(3,'Internal Credit');
/*!40000 ALTER TABLE `paytypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `products`
--

DROP TABLE IF EXISTS `products`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `products` (
  `code` bigint(20) unsigned NOT NULL DEFAULT '0',
  `name` varchar(255) NOT NULL DEFAULT 'unknown',
  `price` double unsigned NOT NULL DEFAULT '0',
  `stockqty` double NOT NULL DEFAULT '0',
  `cost` double unsigned NOT NULL DEFAULT '0',
  `soldunits` double unsigned NOT NULL DEFAULT '0',
  `datelastsold` date DEFAULT '2009-01-01',
  `units` int(10) unsigned NOT NULL DEFAULT '0',
  `taxpercentage` double unsigned NOT NULL DEFAULT '15',
  `extrataxes` double unsigned NOT NULL DEFAULT '0',
  `photo` blob,
  `department` int(10) unsigned NOT NULL DEFAULT '1',
  `category` int(10) unsigned NOT NULL DEFAULT '1',
  `subcategory` int(10) unsigned DEFAULT '1',
  `points` int(10) unsigned NOT NULL DEFAULT '0',
  `alphacode` varchar(30) DEFAULT NULL,
  `vendorcode` varchar(30) DEFAULT NULL,
  `lastproviderid` int(10) unsigned NOT NULL DEFAULT '1',
  `isARawProduct` tinyint(1) NOT NULL DEFAULT '0',
  `isAGroup` tinyint(1) NOT NULL DEFAULT '0',
  `groupElements` varchar(1000) DEFAULT '',
  `groupPriceDrop` double unsigned NOT NULL DEFAULT '0',
  `taxmodel` bigint(20) unsigned NOT NULL DEFAULT '1',
  `hasUnlimitedStock` tinyint(1) NOT NULL DEFAULT '0',
  `isNotDiscountable` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`code`),
  KEY `SEC` (`department`,`category`,`subcategory`,`name`,`alphacode`,`vendorcode`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `products`
--

LOCK TABLES `products` WRITE;
/*!40000 ALTER TABLE `products` DISABLE KEYS */;
INSERT INTO `products` VALUES (1234567890123,'Hersheys',10,76,5,124,'2016-01-05',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0–\0\0\0H\0\0\05½\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0‰\0\0‰7\ÉË­\0\0XIDATxœ\íh$\çy\Ç?*kx\Ç(e”d.®7M\è\í\ÕKu \Ú\Æ4\'“À\éˆK´XÔ·MÀ\'|4Þ³ir²;\â(®[\×\Â\ÙrÚ³\×\Ã\éÀ\æt\ï¤‚HªuÉ‘5\ÍÁ,D0C»\í¼\àõwfv~­\îÎ§Ý³“ýÂ¡\Ý\ÙwgÞ÷;Ï\ïó\Ì0À\00À\00À\00À\00À\ÇC7{ôŸ¾V€G§ò£wI­&\ë\Ò\éËš\çúqú‹¢°c\ÜQÀ¾b!F\Ö.oôu\Ð×£\r\Ðk\è\'†‹;b\r§‰\ëIŒ}&›W¶R\"½þMd`±>¹Ð’€\ã3\äè·›´\Ô\ß\ß\0)‘\ÂFzÛ“\êÁ\ß>`@¬7nŽ\ä\áo\'\Ð?k 2	¡!nÏƒÐ¨_\ÙÂ–K:Y\Ãu óƒ½Ä€X7·-\àG@HÁ(‚€LBhHt€a#Ü‰ô\\¤c«×»\ïó@\Ï®±z[ýÀ\ßxy ¤AI\ZfN \èh>q\\O\"¥‹ô@J‰Û–Xž„mex„Ã}	ÀE¢g[¸û\é±r\Ã\Þ@¾<%\àÏƒ\å\È,¶@9¼®£˜ˆÈ¥mËˆ­ñ|+$%RJõY°\ÍS¯D„00t‘ƒ\r\é\Ðh5C²&!²\ç\ë>°X×Ž\Ï\0\ß\0~ ÃŸB\Çm(×¤!\È&4t¡#ò†óGzŠ NÛ¥%%\îM¤”@\Ç\Z	!0urWJ¤´;–*3§0ò&\0bX0?YÆ6®„Ž\æ¡\\¦\'‘‘9ÈŽ\Òö‹\ÇmÀq\"iyt‰b\ä\ÑM¸R\â´mei\Ú>qº¤û.\r‹D\"1õ<\"§Q~z1¢ƒSeŽŸ­!rÙ´X˜®`\ë\ÃMO²\áX\àI\å^3\Æo,Öž\ãTð:#\à\Ñ`c&r}XY!\Ôkr ù‹\ëJ‰#]š­x‹“…€<Ák#o2zh‚\Âø8õ\çk4¾\Éì¹¥pü\ÂtE­Œ”‰\ìJ*€‰*l¾ºŒ+$\Âs9pú¨Ye\áw‘X·÷ \Èó—\Ñ‚X”\å9™ˆœ†¡\ë\è\Ã\ê5\Ä\ãk\ÛÁÚ¶”\Åñ\â–\'jqH$\Å;\Ç›:Œy{1¬«\ïµ%µcUfN/„c\ËOÌ²8=ƒô\ã-C\×Ã•±[63?\îŒb® tÿ\Ö_^ö÷¡2]a¿ðI%–\ÜM‚<™AsN`@h}t]W\'?G;m‰+%¶ã„„\n\à\Zi«\Êz•OÎ…\äY˜*£!b\Ö	 t=º£p‘ñ ¾-\Ñõ<²\íP{\èxŒˆ \\£¹¿H\å\É9\0¤\ã\ËR^0\Û]}J?\ÎÄº\r8ü@¨\×!¢–GC \ç\æ°ÀF\Ìm\à#Y\\)q·[HIqlB¹DhŽŸ­!„.\Ê\Ât×“öý\ã¨	D÷\Åó¤\"‘®wÈ€²pö¶1¢\ä\é9*óó\ã¶õW–˜|l6¶+\çr3ö\ÞE\"<È©s\"‘)\É!bÁz.’ö’X·\033ûG \à ¥‹\ä,\Îa`•ˆ²\\@|6X\nIZ\ä­P…§\á´me‰†;‹i·,\Ç\é\Ä=‘\Ô<´4>Y¢K÷W(}k2~L]gþ‡\å’\Ì}»;–±»\Æi¾\×H“J\Zo\ÕÙ¸¸\nÀ©\É2Õ³µð\ãÊ£?LüV…{Ë¡…\Üzo“\è\Ì\ÌýE¬÷±\ïhødö4tÀÎ˜_döüË®?\æÑ“\ì`±£ù‚Ÿy»J1\È:a94/7‘žÄ•.\02¤·\æ_¤Jð2¬Že‰\ÉIr$\ã\'ý\æ$FÞˆY„`\á\ÞrpDªo,©@99Á\ÂT…ÂE\ÊOt¬\Æ\Æ[u\ê/Ô˜]Y÷ko\Û\Ôš¥ò´r¦+±ùT\Ï\Õb‡±C7\ÂñÁÜ‚\ßs¯9Á\âT†v»*e\Z , !\Ì\ÌPAù?M)ÿ0û\ï\rz\ÒÝ°Ž|]\0º”¸\ï+“\ínÛ´~\ÓTBŸ®\ã\æ2§á ˆ\â´UŠ\î´]¤´i¶,¬V“Ö¶…Ó¶±\ÚN[‘\ÌEbû–¼x¨\Ä\Ì\éf\Î.2»²LuE-À\ì¹%&¿;ƒ¹\ÏTUÔŠHÉ¬?\ÎEv\'øß“4¾\Û|\à`I‘$²jšn KõøØ¯–b\ï]$VÂ•i¹Nl$öZ\ÜkdNGN\Ï\ã¶tŸ¬22>Áˆ¢\Ð?\ÕeÈž¡Wm3ÿ=5öûM4Àv\Zm\Ëiù$²SúN@2[:jû°`ü23\Ï?Gõ\\\Í\'”`\îÌž[b\âŒ|„<žIˆ\Ý\Ý^zAY‹¥\ï\ÏÅ¶e9eM\ìA„P\Û6\ÞZ‹šJYÕ¥\'æ’»\ì\ì\'\Û—1–‘7™]]N}Wz\Äœ\è\Ìû™!öŠXQ›—›8R\â82¦]),Q=W£º²\Ä\ì¹%|\êc‡&\ÃÀv\ì®q@ffW¤‰ =	\ÃñS[\ØWL\Ót\æ•xüR¼sœÔ²ø¤ñN„Dž\"‚ô\âq±‘73]vbx÷ew.[é‹¥-©®\Æ3P^\\Ý‹\Ñý\è\Ë\êY£Ÿ²+\nUHuWº\êµÿ³\Ý˜£c¸@sÓ¯FÜ–Ó²bû?:¬\Ëñ\Å#&²-Y{}lœ_‰}~\á\é\çX˜,Ç¶•\îŸJÍ»°ÿ@J¯;t\Ø?H\Ü4\ÞYu‘ª÷ 3·\áN¬”¿³\Ù—\ÜO’Œ÷V2\Éu\äùÂ³\ím^\'\r±‹Èº\×\è±ldø/\Èòd[¥\ÑÒ‹\\Mžd\â\Û*XÅ‰_c‰›È°TL\Æ-°ò\Ø	jG«¬½¾H\ê¯\Æ\ÝÄ»K$­Nñ\à„Ò»\"<~ôHg€oEd\ÛV¿ #³\ÄWi>ñE”’\Ùs\Ê\n—}\í\ÉER;v<µ¿Ý A˜tDaŒL<P÷\ëfØª B\ëH1·^\×Á¯=#–\é\Ç	~¥,Ü®bªø\Õ\äú—<!…/¤]U`)š	b)K– ÿ%_‘+^zŠQ«c\è\É\âô“§g¸ðlMi\\	\Í\Õ\ë)1T¹\Íôñ;ó\ê¼t®X™C’n2‰\Å\éš\ï\Æ;_\ÆM*BA\0\È	´\\ ‡[¿¶\ëAn=#V\ç=73\ì\Í»¾\ÉÄƒ\Ê\ÅE1q\Ì\'K\"þ\ÐXN+¶-š\ÞgÁØ§,qK’\Õg\â\ÊöÜ¹e?\î‹*k°ùV<Û“\Ûib”¦•å°·³”$BÂ…RBF’±›Œü]~\æÍ„–u\à®bHJ=§JV’™”T\ãäŽ•»ö\Z=#VŽ\íFª¨Ú¸TG¶ýw\îH\Å<®¯Š\Çö\×v\ÂŸy\Åûûo\\ZO}\äz\éÎƒ™3‹y3¶˜Kk©\ï&aÜ®\Ü|7~œ\Ú#³,LWB*À\êO\Åw\ë2`\ì\ÐGN\Ïsü\ìTX=¹\Ë\0G§Ë±ò©+/=?\ÆõT·…-%£9ý\ØU\Ì\r —w\él:(òh\Zd2»e±ù\Ú2\ÉlO¶U\neU]g\Ý\àð\ÃU\n£÷ºv^)\á\Z‚\çŽTR\ãgN/p\à\àDgž\íVjLs³ºv@	±À\æÅ¸u…$i¶þ=MÖ¬\ÉEF¤8ðõIE¢H|ôi\Å\äÀ	\âÚ°ˆ.»»\ê=BOoÿŠŸ \ì\Þ ”Ÿ\Ç6¢\î\Æl\\¼û†1RPñDÂ?»Dõ%&ŸU\Ç\Ó\ãYWñ\îˆP™¬½’\Ö`ò»3¾:\æ_i\Éaù©yš\ë‘x\Ç_0«@_»ª\ä|?k\\R$\r¬Ró—w\Ë2“’B„Lý\È\r{J¬h\à¨Á\Ñr ¶Jµ†`Ã·\"´aY<\Û6ùÀ%¸~q„\ß\Ãd~±\0Hš\ï\Å\Õò<™\n¼5ó\Ó\é¬kò‘j\ç\"É¶±—ú	Jt—š›ñX)+¦rIXŸX›oF\ÎW$)2÷\Ð}5?\Ëö\Z=¿a5þ“º\Ø,£S·™Wõ¥Zª8\\øò.’\Öf6qÄˆZ\ÄúKñz\\c}-TW~<[@+¡ùÌœy®\ëü›‰òŒ\ìbº\ãI‹œ\r\íD\æ\îùI\Ìfú¾ˆò£\'˜|¤\nm7l\ì7µúr\'´Z°´\Õþ»‹uJ‡&Uw\æ5ú~\rÁF¢&G¬+K\ßW®°™Q\í+µ‡\â¥óŽb¦kZ˜Š[® @l_I\ëV\É9›z\Þÿ¡ië–…V‚˜\Ý\Ð|7~!UW—˜9³˜\Z·ôÌTZ70o7w#UÏ´¬ž+hºK¾\î¼WÛŠwO WC.»‹,}ë²ªM¦ôoN\ï\Ë/jÏ­^KIs+\0‘QúHg{…}Å”u*Ý§²3¹/\ít_\Üv|œ¦g»\Íúqdº,Ÿô\Õ3/b\Ü^ t¬’º:s\àO2?\Üô”X›\ÈÇƒ8«\ÛU\ãA\è/\Z>!\âd¡\ë,LWvL´³:¹:Pn![;j\\ªw¬Š\ßÑt3\Z‚õ\×\ãŠþ\äcU\\\âs\á J¶\Ö\ã_ù{\'y\ßXŽ—a˜Jœ£X<Z\Í\Ü^mÙ·\Ôpö\Ø,÷–Y>9¯iâŠœ¤x½\ën½¶X§¡\ÄŒü M(Ù ù\ÎZ,; \Û\Z‚\Æ{\×.9\ìšuA¬{3À\Úk+©mo\Æ	\ÕHEPbr¶;RD \Â6’Cq¼¤H+e(\Øf¡p\×h\×xŒ¶;0\ê¯.±x´\Ê\Ât…FD:‰ž\Ã\è\É\å\Ï\ÏúgN`\Ðkbý_ðBÒ©?<(1Tycù©yE¢Kq\ÉÁE²±p\Í|¶\äDRr\0¨Ÿ‰»‰Äº’ŽsR\ÊöWK™’D\n\èþœT—Dü ñfEr\ÊRÛŽ\Ïô\Æ[Wš4Þ¬§\Üh\0Íb5¡š“ƒsJ‹«vT\Üúþ#™ø„‹\\m¯§Ol\ëƒø\Â+ÁQf\Ó$ô\06~–°$ûGS\Ö\íð÷ªaÁ8@¾X$\Õ\ëH¯.9DÉ³ñVGbq‘,L•Y¼·B\í\Øq\ê\Ï\ÖRûú(\Ð\0=*–&.B1|•/n\07õf\n	 4„\çªû\çü“Uœu\î«xw‰ÿ¼H\ë\ÝMŒ¯w\ÔqC\Ï\ã:N¸`k¯,Q>\'HrÁ?1K\í;UEß’\Ç\ã]Ÿ\0«/,¦Zb„’ƒ¿‰jŸY<Z\rÛ‡w«ÿÁµ\Õwû.\098ð•[?[û\àEŠP=§õT‚è³Ž‡r\0Z\ÊjE¡e™l_\Ç\ÙHt9-8ú>“Â£4~·XcßŒkb\Ð\é—\n‚\ß,XW,ôX¶g]±¨¿¬¬‹\æ)\å~ñ^U\ÆÒ–W%U €~R\Ù8¾2F\å\éy\ÆM\à…/B¨\Ë\çP\ßý\é9M=µ¦‡\è¹Å²¿- >\Ý\íóf«‰‘/ Ú„V+\é–\Æ\ï+S9Ñ†\ëKn\"*\Þ]\nK7\ÖÍ”+,\ÝWf\ã\Ízü-\ÊOÎ±|r>sŽ\ËO\Î\Óüe3\Ô\ájG«]o\à¸QH¤*D{\×F.\á§õ\Ó5¬–¥¤Žvò\ÂTV6¬xô¡¦\Ósb9pÈ¬¤k,$2\Üc’\ÑõŒ}kŠõ——U—hÐª\âe[·(T\æ‡\ÖÑ€7W»o\n\Ùr°\Z[l¼UGC°8=\Û\çGqI\×óg™¸o’S\Íñ\Ã3Ï±yi\ågŸcý|÷\0>y\r\Ý`\ëòx’\Æ\ÅHOb\è\ËQ÷H\æ%´„:»ù¨T¡Ç­D’¬½B?‚÷\Ý\íC¸‘\0Ô½¼\Ù\å\ëòVl›³kS\\\Ú\Û6k\çW©=2\Ëü”I\ë//±0Y¦v´\Êò3§hý¼sIp}¤Jº3‰\çw\ÂWÇƒ\Ï\'¾]fm\ÇU\Â\ì±\nB×¹\à‹Ÿ£Ç™_Yº&X¸£Hõ\\­÷6TMu‘\Â\Ý%¦ž˜cô¾2\Õ3/ú²Œ>D\ÜúGø³«\è# ÁûF _uƒã¹˜t2”\ÔIõ\êÍ‹u&î—Z‚\Ö\ërƒ\Æ;k4\ÞY\Çj5;1pö¡\ÙpQ£ûXP\ÄŽSy¸JõôcCC¬þ\ê\×\ÔÏ¯P¼«\Ä\âs4±ƒ\Äô\Çþð•)\ri\Ì<9G\Íw¿\Z‚úkg™;2ƒ¹o÷¦\Å`Ž‡›\ÅÞ¶)Ÿœ\Åþ…ñ9“\æú\Zõ5¬\Í­\ËMŠûGqZ–z\"`\çkýƒôö¾›ô¦f…1²\åðc*\Ù2\Ðhü¬¦y©\Î\êo[lýl\ru¼rkó“‡c,ö\Æ>Q\é\Â\ÅX`9[;;¬_¬“7\rÊ£cŒš¤4¤a “ÿB\çS™\èÚŽKùs(\ä\ÖfŽ?=\ÏÔƒ3\ÔN\Î#Õ¤ø£\ïT9p\×(kï­£§þ`;p¶.ubEó‹E\Z\ëkl\\¬‡#š\ÛxPøB\ÜN\ç~_JS\ÏÿE3\"\î\îúò|¬\"b\'xT‚-$\ÆHžQ4d\ÛõoH\é?C®\ß%]ÿw\Ôl´a\ÛV\Û\ÞÞ±Ù¼´ŽnV_Zbþ\ÙS@õ\á¡e2\ÐyûC›±[†X\\}›¹IU#\\\Ûq™›ª0vp‚µó+l^Z\ã\í\é8L&F\ÞLõ\Ïw\ÎN\äþ\0\âYu·K$\ÚD<Å¯DŒ\è˜~œ©x’<‚\"Ws»µ\ç<¸\é‰M\ä:=Z\Ñý£\"\ZûqT¬²\â\ß \á\"©<z‚\ê\Óó”†´0…_|lŽ¥gU1;oÐ´mV^¨1þõ	f\'³°²\Ì\ìTr` c]nòöŽ\Í=Ÿ2¸gÈ€aX96´<¥!-üµ©’õ»«5·d…Áw›\È3À?m\"\r|Àv‹F\Ü\Z\Ýü\×5ŸÀÀM·X6m$O1§!\Ú\à´;=G7*®í¸”†4\Ì}j\ï\Ö)™&ó§_dñ\äù¼–l\Öv”Íºg\ÈH}·n[6\nœ8³È©cU\ÞþÐ¦t‹\ÄI‰±YB²\0ým¨ˆ.¯7}ò\0ò|L\Ñb;Ý‚w¥1\Ñ\Û\à8öGtgiWøö‡v\Ì&—†4V~µ\Å\Ä?Ï‰\'\ç\ÃÀym\Ç\åÀ\Ð[;;¡\Õr‘þv…¯.eõ\Ð\Íe“’E\És¼·\à¿[È¿~\nü/sòì†›J¬Àb	!(\è&¦T7‡\Ú]ú¾¯\×bU®²ò“\Z®k;6÷\\°›L&Úˆ‰µ\ÝD÷\0E„d\Ót\ç]a \Ý_–õ\Z`ù:ððŸô@7ú¸¡/\Äp¹€HµhÁ»\î«\à\á?mæ£—8²¬$­Mpô´µ\é\Ó]@XG>¼„z<\Õ\'\Ö\Ú\ìú¼K8<¿\Û\'x‘Û‹\âH‡`.F·Vd[7h¤\ï&J\Ä9ò\\ú•\ÆzJLM·\ÔK\ÍfÖµµþ§\É\ã„\ÊSöó\Ö\'\Ëò4‘\ï:ð÷À¿ñ{\à²z…~\ë\×ASD`\"ü†¿t©¤€N\Ûq–Õ‘1\Ë\Õdº\Å>Y\Ög@žÞ£_\Äú”¥2P…\çdß£†z`ˆƒ­\n\Ó\ÄU\æ\0Y7d¨¿q\n5>A©ù\ï\"ú.\n”*\ìú\äÒ…À\Öq‰›“4¥)\ZG-\0\È	6=gx°\çc…¾«\à»?‰ˆY cD\ÉÍœ\Äõÿ=Ã·?ò·œ~\n‰ÿ|¯ÿ©\ã\0×¾Z,?¾y\Ô—¶\ÕvhIùÀj\ä€4Ÿtô\ífŠ- ‡w\éH\Ô}~ú°FK\Ê?\"$\Õ\0\\ò°s}§€\Ø\É\ÃpøÁÍž\×\00À\00À\00À\00À\0ðû‹ÿm>\Zö5\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(987654321123,'Doritos',20,4,10,96,'2016-01-05',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0h\0\0\0–\0\0\02„\Í\È\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0‰\0\0‰7\ÉË­\0\0 \0IDATxœ\ì½}Œ]\Çu\àù#]­97yœ©›iÎ¼; >…\Ñ#ÄŒšˆ“m¤\Îj¢ 	\'0	{1‘  &G\Ú`aq½‡ò\0\ä,¼’$¢½›€&) ‚(À‚›N”†\éaK-¾Ü\È}ö\æÖ¸\ßøž¥\Ê\ÝûGÝ¯÷ú“’=óp\É~÷£>Î©:\ßU?ŸÀO\à\'ðø	ü—-?†2-ðð(@¿\ÛýE]‚‡ƒõ\ê\'=û\êù¹o©V\Ëüpø\ç\0\n\ß*\Ëù\Ö*eS•[ý\ß\ë\Ú_,\Ïlÿ£ù\íõJbk\"\" \Ð<8¯\ä\â	\'o¦ß²²N\êù\Ö:õý…-\ÇšY\ÎÞ\'6`d\â…\È4‡§:ö¼úB\Ê÷Ôƒ–\ï&<‹lŒt$¶¸t`\"0	.Ü‹lD±‹P¢Ž \Ý8|=¥Pˆ¦£ò9\âiAGJQ5\Ó@\ä\ÃÿP–5*ÀD \0\"Ð¢~\'2\"Ä„?t¤°£\Ësyñ[Q\Ò.(Ÿ\ã<ô;ò‹x\å\ÄÇ<Š\â\îd0\Òú=\éx¨õ­)\ÛU\á0W@9ü\íÁ–-\'D–¿6#\Ú*FŽ\àœ«Ÿ\é\Äwbš\áK¢ˆ:1ø™D’\í1‘@z)\ri\Øn°ÿ-\"¨WD‰…a:$eÝ\ÈÉ´EKd5W@Hø]µ[DP-)©Šz(|žû0\Ìšo\ËYI\ÕOÓ´OÛƒ j‰‡B•H^\n\ßü]µA¶	.w\r\î¦B‡ß¾¸\ÅL§š1‚\Ð{¨Gz-%\Ù#Ö‚*t\"t˜D™r–”Ç„\n“\Ý	L	\îz\nQhAÔ‰\È]N\ä#lQ\'¡÷\ØLhô‚\Ã\åy@\Æ\èû¸ª\nZŽº\ì6[#¢··OÏ—³¥B, x¿\ì\èû ‘\r4X\ÔÀV#)\ßUd›”÷ñ \ZA¡h\Õ(Wõ9Š4BW¸&˜W¬[\Ä*\ï\ÈGapU÷Å€l0²­\"c³i\Ë\ÃrŒ`\r\ìÙ•\ró\ÐÁr$\Ä;D _PÐ‚¤Ÿ ‹Šl³ð¾¢N‘Ä’\ìHB#†|A\ÔM\êiÂ•S w”øþ$ ¥œ=bc˜x¿\ÑÙµ”hÚ®`¬\rkiFk¨#:\"\ÓÈŸª/fZ …o)F‘\È]\ë]4¸0„O¨œI‰Pø’rÐ‡(F:>ƒDP—0‡\Ù\ãµ!Rk6…>Q,8~\éõ¹À\âl\'°/U\ÆXS\ÅD\Ê4r`„dGŒ¶°­”J\n\é¥A\Í~ª\Æ\Å-\äË†E€Ž‘aFh¡‚[p¡C\Z¾	3Uj6UAd#\0ì´­gª‚S\ÔTœA}›´-\ÄM<³\"™#-ŸB\ÕlÁv$\È\'Šú;±1\êrò‘’©\â|%©¿•\n—¥¸ˆJò\Õ\ï\Òz½ý3>qË–þŽ\îù—ú½G\ç\ÏÏ}T#µBH\ë^TU\Ú*¸!lK•ð\ã\ïQV^5¿R0¢\Éw|Swƒ V[LP´*Ã´\Ú\Ý*«ð0TW—U½“µØ’L<« +µ¾ª\rI)gºF‚\\6\Í@Ì½\â2Ì–\ï\å­r»\ål\nT\Ã\rªº+Q‹<\Ð\Û\Û\'pô\ÝÁ–-\0§~¾¿Ü»¿Gv%%½‘’WšX«J¨|5¨º¹\ZÂª‘\\)J5› i\äX…$\Ó|3TWÞªüºÎ’‡\ÇF\ÆPÍº,±,»i+5+¯úª¾™U\Õ\0¨û_É·²\î¸,³ªo\ÎkM¤v\Û\"‚\"\é2\Ó{¸O\Ô\n\ç^\Ï8õ\î€s°\Å\0\\~w@oo?\È§XW\nC¯cšZ>¡bWMR 6a\êVª \"j=£\Ê_\ÕHVc[\ÈŠò\ï¨BIKq©@\Ë\îPº d­öÖ¬¥­Yšf\Ô3\Æ~œ\É(JD\èO…!(¦”H‹EµÊ¯¤\Ô\Ï[\í\èHK»\è\î-	3\nrgx+\ã\ê{i]¯H=\ÎYK\ï\á\é%ˆFEÿD‰½W£³„Š52Ö\ê\ï±Q\Ü*+±µ@\æ]\Ý\Í0«W*ŒƒB-—r¯\än¾7mvYµI\Æ\Ù×ª,·*µ$,Ò´µ\ê+£­\Ù\'H«½³|:&\Þa9Sªð²\Ýw“RiQt”\ã2Gö^J\ê•9ø\ß\ë\æ%\Í0¼žÒ½¿G\Ôzûû9\ÃÁ¨¸R	9O)\ÃTKVS#dLk\Z»_’\ÐnLy­\Ð*+\åW»\0#Ä„™S•\Õ\Ì+\Í\î\é\Úú½Zû*ûJödÀzÁ©#õZ«‚\Ô8¢\éx\ÜNªXT¾c ²IS©\Í/»>Do\çm9õo¡tõˆ\Èo?\çù_ö}¬c0E+õXG,º@ýQø]ø`§¨o\äN\Ý\á5f\ÑjHü]É¼–]­cß­V¦óA‹²FHD\Z¶Æ„R\Ý6­Ë·\n–h|`\Ô®üP\ËþúW’’@u5S%3_‘Hj®#„‡‡|”“\rR\Ü\í\à\0\È=\Ì{\å\\I›\Ú÷,\'b‘Ž\ïˆ\é&–\È\Æe#µp­®@\ê”lT £`´\Æ-^\\w®\ÕY‘õ\ã–°\Zïƒ¶\ì]a\Ç\Ð|[¹b¬ ‘vJ—M%\ì‹\Öw\ZŒ\ÑF]jy…T‰Jƒ!’ˆ\ÂwT%›™!µ—\"˜\'\Zp£\ÔvÍ«B\Ú®ž¿Œsa¾Tƒ.S%Î–´™\àÀ¡#\ÅÍŒ\á\í±CzO\ì\ç\ÂTô\ZŒ\ÐN:!9ùB\Ù_ú\Â:\Ñ\Ûhˆ”+qC¸öTi±‰F¾\ÙÆR\ÙCQó~ð\ßEã¾¬²þˆˆÂ–÷}\Ûj¥¶þ>®lšÊˆ­ˆnJI\ÔöT„c»•¦[b¯¬«V®*ye)4©ôù\å9\é‚#6\ãa’;ŒHj\Äž\Û\ÝÙ…Fc92\0rŸ\Ê\ÄV\ÈGa´«S4®Fœ*m‡bå²©XB\r¥!Š¤ñUµf_\ä	þ¼1\0€H5ðW…JU¨Fr[+•ö‡­ò‚\"\Ó2Œ+[µ©…ü\Ú[\â•B4\×\ÆX\áv˜‘»²FIö÷ƒ7\Å|µYp\Ûöl7‹¼jj›%˜\ÆVhA\ã\".5°\Òó@\"TR±¤¼_oÈ¸º[ùÉ¢¨\ìø6‰ˆ”ÀZ„Fùh\ä\êÿIAm86ˆm”‰F\è\Ëòt¢¬	‚\Ôw+ý²ü]z\ÕÚ†*FEðf”¬…|X\Ô>*\ÛT Pz=ªr\ßh­\Ê\Ð\àª6~¤nªµý\Â˜VŸ‰˜Z†\â?\à¾¯¸›w-(\ÜÝ‚÷\îzü`ôƒÀû·\áy\ÞG\Ì\ØWŠ†n5°\Øj0¢­0õa\ê#\Õ}\à¾\Ù\n\ÆLa\î³U¦*A~Ÿ ÷Œ1˜û³Œ1¡\r¥b\á\Ë:ð\ä¾p¯\äÀÈ’\ÇÁ\ãCw\ËÞ–eÔ°D\Ù0[¡¢¨\ÙZi\Å\nK\î*þ…ŽFŽ\Ñpóƒ€—-[iW\Ù\Ïm?\áÅ¿]\Ä\ßõLmõlY\nu..y¶\ßg8y\××–ÁXÀ\î#\ËI\É2\"º»’¦wª¨#\ÅQQZ\ÏÁy¨¥õ¯>\Ì:g„%;ñR‡\Ú8#\ØJ‹™jT\Ñ029PÏ‚’E\Ö>9š÷\ë÷t\ÂA9¡…\Õß¶dUe8W\Ðö6@Ó—5AÕ‚BwË\r­Êø;ø5Có…FVi9‹†^I¹]\ÆE^i-w+\àTZ•i—‰\ÞÍµ²¸\ÃSLË˜xvNt`h\"º&°Û±Ä•dð•<hwH¡ü­+T\Z\ï\Æü{\ã\n|C•Ö³*T#P\Ç\ã9U\Û+ù9Fð2n´£w\\9©•i—[+\r¡,QiAŽ\×SzD2 \Ë8|¤ý#µf\×/x2[\r\ÑVƒ‘³5LW|…-þcø¡÷øÆµZ\Ó\Ù\nƒ»ŠWeúÅœû»q.yþ\'\â\çþ6*õ\Ý0X¶|\Ä\à—<fÉƒŸ\nu,•\r[ò\ÍÿK>\Ü_j\ß¶–=õ¶V\í,/ùÀ¢\ïj \ÎÝ²OÕ³»T•»µUw9ôõ®gño\ï\à\Ò!\ê\Æk\Í\ë«\ä\ÈÞ”e\Ü˜)Œ™\Â/y\äg\"À3\Ò\"pU<º‹w=™÷(p>|»ª}EN\ÂK\Ö.«*=±\Ø\é¨1¾”\Ú?¦¡P \nEiW¸\ÖH<^Ž\â\Þ\îûgi\Îü»\á¬WNø\Ê\êž\ÜJI	\ÊUDÜµ\Èv¡\n‰¯“3`ò÷Z÷&\ï·Y …iê€¢1b[l¹Š­€*ž\ä[l¯ºP\â\Ì|eª¤\å¬>;A“Ú¿«{þ¨\ÓGH:qÍ¬1jVeg|»\Â\ÆayA\àœWË™„|gÄ§\ß\ÊVh`‡ŒpÀƒ5BTª­òÓªkL›6QG‚2.\rUGvû7«\Üo±¡\"w\è0\Èª6´êšIó»\"P­*\ÃÀ¥`,ð§epP²‘29\n{¬p\Ü\éú85\Ý]\ÎU\éu\Z7F¥(Œ	À–‘U\ÛA\ê\Â,*\áx\é<<2\Ý\åÕ§c\ÒK\Êñ›\çLše/!µ+_Œ¬\ÞøðT]qjKÄ´\\¬µDC¤¡¢©\Ö;“ŠL…\×`JjÐª:GZF›\ÏþW\çùl»Uc2¨‚£ÿ\Õ/ü¶flŒD°¢%ð¥¶Ž·Ý´Z\â—À\ãñK¡#\ß!ð\Ö[÷~\å\î{ÿ\êMÿôwHþÃ÷uJy¾ýž|+\ì¼xóT©ž·e\î\æi†\í\Ê+˜o\åo3[§\Zukù»\rK\ã—iË©­\å\ä\ØR}_¶²\Â\Ñ\Ö\æòx\Ì2ø­A.\é’\')\Þ{ž¶ü\é÷uÿd/¶N\Þ\08üöÜ–\ØH®ªc(\Õ\ÅJLI\å·2\ãž\è\ã%Sr\Îñ\ê\ÍnŸEþõŽ]9EúxÂ‰i°\Ö\Ö\å\\ô\Êó\çi¦Š\Óq\ë_\'®qˆZWL\ÐP«K\ÚW\Õ~\Æÿ^\r‚·\ÞO4\ÂdN[­n\Õ=&³H®\ìj\ÜY½\ÖU	v]«\Ë\íf–DŠ\Ìø³Jv¬&8\ã!ý\ÍS\á\Çô,öôU^x\ë\Ä\ÌN\Û1þý\"Ê«(™:rŽµ³¾¢5=\çu\ÛXù²\Êß²\Ê5®>·®6‘\0ñZ†]´)»šþ­«\êS\Ï\nYG›|¶¬›Yzfº»,±üamùSW\Ühv!Q\à|ˆ\ÓW¡\à\ÎúFú£YH4†‡Ž®½Œû\Ò¯¾•qB		*-x\ÅTò)d®€›¼Z&\äR=X…zWŽ_:F\ÈGÊ…AN¤\Ð\ï\n‡\ß®J‹5gTþ&ò\'¦i}I\éÏ‘&riMW£\ç@‹ gU~m¦g~|Ž\á\Ìaô\Ã\îØ¯œ\à…\ÓûÈžN8felF=\ë•!A%j\ÔûòVg/ÿ9@	þ\Ã6»+gyÊŠöUIµ½nðA®«*	\Ìmõöð}\Û>¶\í§S•°£ôS\ÝWÒ¨4\ÐB\Ý¼Ÿ_\Z“¸l£»\ïý\ÏÁ_;\Èõ?üÿµ±ð\ÖM~\îÿ˜\ÇL}ó\Ï÷ ÿr/ÿÙˆùƒ)þýôns^9·¤\ÌbÐ»ž©­¡]òH%\Ø\×r\rLª›¡mT¾S[›o£–1m\Æ/yü][w™j½t}¡`jÉ°½ô@ü\é\Ðý\Û\Õ\ê\Ü0yþ\Ôtw¹·#»7\æ+®\í•Òƒ»J\ÓÀ\ê*6øl•3f-Å—÷\á^\ÏH\Þ\ÎPu –CF9þpB· \Ø±¸\é˜?­xo\Ü~²F8Q†›\ëvûk±»v6Í&\Ù\ê„ú]=¯¹\ÏT\åù‡7/\åô¦…D‚\ì<ü\ÝtUZl¼ºÁðo.?2ó{¼_zqÛ‘þ\É•|\Ô Q}2mJ+ùe -‘ü\Í]üVg>?\Ï\éI\ß\Ða\Î&ô>na/\à”ÁWrö\Ývc„\ê\á9„(\'Œ!X	Z\å‡&\Ê•kð_Q)-‚E\Ø–³\çS¬~ou\âÀæ–Ÿ\ìúf·—F\Ó2\Óiu¢º\ãn8&s½/\êDA€gKee·\Ë\ÜS1sod<¹\àV\ç1%‚Žu„\Ó	ò	…ù¯\ç¸=¤q\Â3b¹€rŒc‰\Ð5\ÑÊ¤\È{…{ý¾r°zm‚o•\"!a6E\Û\à\ê­Àa¬À§¯­® À&\×š\î.wMD\Ôm\å·|Q\è-÷\ÒR\éù@Õ“g}I²\'zpGI¾›5\æu`F`nGyLP§.\æ<;Ž½cKû\í•\Òˆ`K!ügÔ½©\Ê{ð­\èhK©r\0¦\Þ„\çog€w\×*nS\"5ó\Ê\ÐZ®u)L5–…ŽtE¸6\Ä¢\Ú*À+Æ†<:UŽ§ÁN°Ë†``\ÞC|3%úÚ€S\ïd\Ý“¬_¦\Öpåª‹O{\ÇiBÞœ\Ó\"\äk³2¤üA`5»©†RI(&\î9-H]A\êrÒ… (JÖ¿&q`“Rª¬\Í]\Ê@¥’ˆw=ÌŠ\Ú\Ã\ÐUw³¬f\Ë^¼–Á\Ì\ÊÆ³g’>»\àˆ¿;\àùkH¸ð@¯~V-	™S\å\Ó\êÈ½2‡\â| T\ÞB`mˆNz&¼\r“†\îZWò±š­\ê!Õ‚L«w¥6Cì¤¸X6\Ã\â}A\ä|¨< º+¶\\3$0U.\Ä*X%–[2k*\ÈK…¡z\ïÓ¥,\ê\í\èò¦D\ì¹Ñ¤»ŽEGWƒ5XŽ\0\'‚Gx¯‚ðJi8&¹w±i%ù~(™5ž~™û ƒÂ˜v^kÅ¡\Ò._tn]·!ú\Óöü¡‘>:\"\ÆÀ\É=bkIß½¸®k¦#7¶T¹\Ã\íy¯–D\Êw÷ˆ¯¥\Ül€\ÈYs+ˆ\ÈðšŸöÊ›%kUV\ÂpªbR\Ãj£|`d\Z<\æ\Õb„\ÉAS\0§ûV\n­UË†z¡#\Ëuü\Ç5\Ùs\å(\í‰Y\Ü \rkz&Á3&\â\ä(\çl\éºy©c±>D_ŸõÊŒRÓ°¥MÁ½ŒòR£\êa\à›°÷¡‡ð\é‘\ãMkk¿˜•ˆxSu´	T•«õ/„\É|\Ö8lU­òxq\äÖ¤Ã†Íˆ\n£u\Z•óŒ±ƒ—s8ð\ÄA\Òƒ*¶Ç¿{±þ}aGŸ\Ã]#.sö‰0¯aaØ™\é„\Ã\ÃMÌ¤µf+ð\ÍnŸ£Ã”g:–G\ÃZ&\ÊÁ0+–—GŽGÁ7sJ,¯ª’˜8tZ b¢5œ¾\ëÉ†Hcoúö\Ó\æ*\ç{=Ø@Ö”«¿E\èIDwT056ˆj\Îk_ye£b\0xõ{~óY\ÎN\'(	ñf4º9\â´a•\0‘¢\ìy|ö€/§[¢iˆr¹(8|\ä(|ý,\Ç:\Âe…£%›=%–\ã\Þ1¯\áogV\ê{ÁS\Ñd\'\ÖrŠ1{µn¨\Ê¯\æ˜!\éH£ l@\rY\Ü\Õ]ýem	\ít¤\\v/Vÿ®>\Ù\àòFÅŒWºe]#\ËY$ÀQ±œ9ö‹pq5v·š\âPi†>~€×º	/\î\íó\Íso†\ä~\rkQ–\ß_®?=þ;/’~\é%†e™sªØ²-ÃºžªRGRO[\'.FŽ\ãÀ	›Ð›@t`_Ž \ãŽ/y† ¹õ:B\"q¹\0\r\Ü\\Û“°	n.c+Ñ”\"D™.¥\È.”a‚\Ò?WhAoWo\ì,\Ë\è\íl–`œš\îòŒWÁpWnZe”¬ñö`œHž\ëty\Ù\rQi‰\Ì_\Z¦\Ì\îí£ª\ìÙ»‡ô\æ\ê³ò\Ù\Ï<Cò…c÷œ‡S\Ó	\Ç]FZö½¯¼d{v³úª¼Zjƒ\Ç]–\ÓWIù­¶\ë\Èql…\×x3\×\ÛaSpyWùò\îþò\å]ý\å;úË¯\Ù\îò1\Ã2\å%\Ý\îrh=«®cŸ}nyùý\åï˜\î.cX~i:”q\êô©\åI¸pñ\Â2´\Ê#\\\ß\Ü\Ñ[Æ°|õ\Ê\Õ\ßT\ï¾ð…õ\ïµ\à\ê\à\ê2F–»F–»\"\ËY~\í^[ñ\Þ\å+W—Y~\Æ\ÚeD–Yþ\æ®\ÞrwW¯y\éý\å\å¢(–‹\Åb¹\Èó\åË—.µù,?\'²ü\ÚtwùL··ü\æŽp­‡ÿ\rY\Ü\å\ÝýZ‹+¼2p9FŽ\Ó{±]Š;YS\àT„õŠ+Ÿ\ÛRN8\ÆY\ÌóŸ;Î…\ß{™—Ky\Ô~¶\Z\ì™\ÙÇ)\'G.hd(\Ë\Åòª< \é}”,ý^«M[\Ö,pmÀž½û\Â\Ë\Åú¾†-QDŸ\Ë>d\âýR;­’<Ï½sÃ‡žû\r(3q{b\Ã\Ê\n\\aG‡kû\â6ô$\ä­)¨ž1\Çg¸7-di®$\Î”„žù\ÔQ.z]AœôFZ_n¡‰ª^¿\ÌÉ‘\ãL·‡§NŸ©\ë™o€[pc\ïO‚Ž&Xñ\Ð\áœ#\é&€b»vÙƒ)\é\Ípµ\Ë].\nR	+ûÚ¬{p#e8’\r3²aF:\Ì8|\èIJ`oO–¹UxDi¼\Z\ëÁ\Æ2¨L¹-jme30®nB\â\Ïþ\æ³û\×\ÇB\Ë\ÇgÎ¾Ùª>\Úÿhý7@¾X`Ë„Š¢(ˆ¢0òŽ|üPý\ÙK¿{‚\Órºþ\Ý\Ý1.ó\0¢8\ZŸE^‰·7r0¿\ÕpUeOOó®\ìzJwG·~7\ÚóÂ‘£õ+ý]=¶l‹\Æ\ÚpNƒ\âS­J—*g“²g\Ã¤¬t0Ž¡~rmJè©ƒ@˜9[¢-¼b»ô\Ð\áL·G7\î¢\ìv¶ª67??\Ï+\Ó]ðð\Í\îJ\â¬\åµ\éñ÷‡·‡D\Û\Â:\Óo\î²,_|Ž\ås\ÏQü\ê~\é‘8\ç\êýŠ^þ\ÒKc\ß./V9uðf·!þa¤V±+X=+i%lL \Ò;[ªZ…½\Ô\ÞjI&mXeþ>¿0$%x,/üh\Ý?+\Þ5ð\é‰:*­J¼ò¼S\Ü\ç\Ï\Âc\Ï\Óû\ÆeN-‰“„«×¯+5X€\"\ÏÉ®§<9\ÌÆœ¨J#6v‘6°ioödnZ\r95K%!^-g\r8f7?¬Bˆv§Û»I­	k¶»\à\È\'rõ—¯¼„ý³7\Ñß™\åø\Î>\ÉÍŒå¢¨•Š\Ý>[¢¨!TI\0k-ùŒ/£Àó\Þ5KMZ®ž\ÍÌ¢M±8-^%‚\ß\Ë¨y\Âeœú£Sõ\í\Ä\Æk|\0//\×w\Åÿ³wž|\êI^½2G\ï\Òk0œC<Éž/\rxq\è\Z%¢¬ÿ”\Ëx³›\Å1/þ\ÞË¸	E¤·#°9ñpVl²&·‰T\Ô,n5\'þš¡\nÁ>„£^9ò‰#õ\ãl![\å#\ê¤ù´\Å\ÃW­óÃ‚\×@?\Ú\ßÃ“q\Ä\å§À¾u^÷™‹Do¤e,§\Ý÷\Æ)ú\ä0ã¹Ž\å¥\Ï\'\Þ9\Ñf\Ï}ö9ž±–ùµœÁ\Èð	$­ÝÖš=úñg\'½®°Cö=¼o\ìwow\Ö\n\\\Ø\Õ\'feœ\ÕE\ë\ä\Ýk8»;\Ýe\Î+—wô8£9o~¥9\0¯ŸbøyGünF·›Z\Öô</w…|®\ä/•\"\Å-\Î\à!®~›¦ŒI?øz°!d\Ú\Öj\áŠ\ÂZ³¤‚\å¢`ùý¢ü9\\ÆŸŽ‚17k$8/«o\ß_\æ\ègŽq\àö€£¼r¨5\ë.\Ì_þÑ±7y–³\ïö€\ï\í\ê1ó\Å$ôñõ¿\äHnf¼ùgg˜}|–\ä‘,¿\ßô¡·+Ì”=·\Ó\ÐÏ¢`y1\\E>v9õ§g87j”ƒ{l&ê±³‡\Þ\Î(ª\nLµ\èDU«x–\'!½=-j[gN¾~š\ÓO=Y³¿×¾ò\n¯}\å\â$!\ëD¼Z\n\ä\áp\È\áCO\Ö^„I\Ø\ÈB;5\Ýc\ËT\Äòûé”¡s\äO¤ø\ÊL \ÌE\ßQ¼›1Pj‚|\â\àX\Õ+Qó½=>z{}-3Þ›\Ê-Éª\Ô+ªÁ¾\Ò^œ„Miq\í\Âc	‹m‚¬CœôFŠŽ”\'Ÿ˜\å£ýrDl½\Æ\æ¹N—£Ÿ:\ZV\çµöC\Ì`§p\âó\ÇIoIv&¼9\Ý+ƒn+!Þ€\É]H%Þ™ð\äSO\Òýõ\Ã\Ì~.…¢o)ñw3ª¼ò\å—V|?.‰\â˜7§ö\Üp\æô©\ï©jpÐªò\ÑþGyÁ\ãöyS%\ÎÈ¦ñ¶‰Çz\Ý\ì\é¦õ•ï¶½qÃ˜1æ•³¯Ÿ\å\è§{¡cy\Ñ\Ãiuñp\ÚÀË£!û•Vø™?=\Ã\ì#³ØŽ w”«Ý„ö‰\å\É\Òf±\â-î«–š\ßO5\Ï-Á\Ý$€‡\\þcˆ-\ÜR¸	:T\â\Ö`\ÏþÆ³\Ì>~0\ìš\ä.\çÀã³¸ap5X\ÈP#¼úû¯ò\êïŸ¤=ò¼`þ½ùm\îöøôp\Ü/\ÞNžÙŒ¡ºqNBG\Î3öQ!L\ÍL\Ê\Ëb3¦\"bNnŒ3%öp¤“ƒ\ÐÀŒŽ!9R\à\\•+\æ\á\Ín—]\ÆU`\ß9zqŽƒ»c\âo§\\\è†h\ì\n\Øk­\à+ÿ^\È]»²“\ÜE%™I¼9\Ý\ã\Ä(«•®\ã6\á\Éa\ngº	m¼u;€žD¤\n\Ç]S\æ+¥²	\Ëð	I4®\Ä\Ññ…µC\Þh¦\Û=\Ìóh•P‘›°bî•—­“ô\Ö¯³–gL\\G+õ6\Ór¡-B•ðB§\ËI\ïHŸ\è‘^\Ê\Ùs{8Q.›&Ì¡Žp\ê_õ k e\ß\íŒt\Âv\é¼Ô«‰óY”¹Iµ<\'B\Øó[\ÇÈ¾t)³‡›\'\Ð\ÆJB\"W\åˆE$!ñ!#¶\í\ÊñEHR4\Íj\í\Úý^BlÂ¦\á¹§$„--÷Œ”Œ°\äiC\È\'0a“×¤cG\ã2j³H:b…“_\è‡\r7®—,m \Ä\×2&™Ì‘ŽeV\Ç\ïÆ­}2u\ìŸ\èS»=‚\Ð3Bd„þžGG\Ê\Õ\ß};S´L„\É\\…õ`\Ãn\Î\ßþ¹\î=\Z°õš©c\ÍJ³Öˆ[§T‘t@}D\æƒ!\Ü\íP®£Qy8k\Âßƒ+3O\'ð¬c\í™3y\ß—§-ý\Ï\'\ÈtŒž\Ï`Xg¥öõJ§K\ìÁvBû\Æ\æOY\îLg\ï\Ç‹«LX¹2€aÆ¾\ÇÀ•t…\nQqŒõ\ï\Ç\á\Øv—²qR\á=€Hˆ\ÈKoEOQ°­zj4dFbŽvcž½\í\Önq\ë~_„%\Ø/ô \î¢_‡Û \é\êÄ™ˆ#+‰\ÓH\Ö\r`/ú\Ö\\\ãs»4?ö\ê½$ôo¬f—…)¬X÷²\Þû›…ŠuVZb\"B¯\åA¸\à\Ãl•_–±\è×‚×¬\åòû\Ø)E@\0\0 \0IDAT?>I=;Þ€ùA>¦©•µs¬cy¡+\É*\Ý{5,7üÖ„UBÿZ\ëy+\Ø\ØY:\Òo\Õ¶\Ûo`l›\á‹\rc{·E¦\Ñ|\"Ì¿ž#Ë©\Î\Z¶¸ë‰²]=ž¹xùõ\ç\á\Òeô«\ÐóÊwR\Üh”[®D?%–%qªm–7G–Z‡›ŒIª’0R]¶üÿ\Ãh\Zkx,Evlg\ã’\Ç+n¯.¸À\Úfûñªû‰¾`…ô“=ºÁ®ƒðú+\è¼Ã½­}7e0\á¨<(\Â\ÉN0–»¦!l\Î6Ù˜Œ>·\ng%‘\èÀP›\äüõ\à\Þ\Æ}²¥\Ð0\Z\0¼¬®\Õ\Ü#4BsFŽ€¦û™.\Ï]Ly±•zu¹\Ûe\æ\Ë=x\ê ðõg\Ð+\ç\à\àŒù‰¦’p˜‰¤ù»mØ¿°ƒ!‰‡A?xúƒ°9\è—,8W\Ø.ô¯8\æv„ô´\áH\é\í\ÏóÔ±¯\Êý«‰#a„…|cqÁ\æfÐ·\ê°w¥)MI½Ij=›>,˜ã®†lW—\ì¼\Â\ãGyf:š½Ž\â\\|ž¾\0&‚÷N \çþ8c\æO\Ò1¿˜À\ÒÄ„e‡q&k;ò\Îe´\Û\ãÐ¹9N[p\"ú\Æý\Ù\ç2\Ò\Ïcö×Ÿ…nÂ™w\ç9t\î§†)\ÇÞžc\Þ+/\Ì_†n\Â\ìgž¥÷©CeÝŒG[²üÕ›\Ão­‡–{cq\Æ6ª7\äûð$\nŽ\Øq6W%ü\Í\ÝV\æ®eÐ™¥÷»–\ï\íNøÞ—g˜¹•ÂŽ€þ\ä \îKó<ûµ‡]\É¼&–“\Æb\Ëô\å\ÉPô$¼ùÇ§Áùµ”ý\×/sò‘=\èµ©Wþú1žÿ\Õg\è½=\Ïó¥{\é\Äût,ùµ\á\ê\×\ÏbŸ8Ä‰/½\\³4:Ž ©67,7\Ã(¾^6ò\ëÿuu\'\é\"€\ÆÊƒ=^¹:{u\àFxü½?9Ÿ¼@\è}\n_;Lú5Ç‰\×œD µiÇŒ4‹W\Ó\ÒVƒ*\ì—^{÷\ØA²;y©Eùü	ò\ß*³“þòÇ§¢\æ}\àÀ_½‘\"‚6P¹b­	£\êx¶5askT»\ÝeKDo—E¶W{ie&IH\Ù\r[D²2™ý–•hµ\\£”i§¼†\íÌ€ÙŽðÍ¯„§ÏŒó{{˜ÿ£œW®\r9+vl‡’#by\èJ<¦¬i\æ†=iË¼\è)ÈŽ„¹aÊŒµõ\ì´F¨r¬\ÛcÎ¥\Ä\n™\Ðì°ˆòÌƒ}\ØVj©%q\ÔCz+,\æúô\Z\Ë\ï+¸·±?Rˆ\Ç\ãò+\à|d\ëAAXR\èª\Ü[\ì\Ó\Í;ú‡û8õÅŒ\Ó\Î1gZ\ÄyA,{H\Üq²N8—¢?m\èKÁ>¸,‰Èƒ\Ýb\Â\ÎA¶\ÄZ00Ð›N\Â3—[Z›´fN\ÅW\ëÍ“\â\Ã.\"®2bó	]\ÖQ8†ª.V\ÑJEgƒ·/;\ÇŒ\ÅöOT\Ä)÷!\Ø¼~•Ÿ<\Ä\ì\'2?L9v=%K3\æn§<“~\ÙO\"zx†³\ÇW9ð‰Cd\Ã!\Ï]¿\Ê\ì§q\à\È!N\Zxfþ*ž>Ä¼>oB©«ˆ1ü÷ dsP\åui^ªØ‘4Ç™ý(ÁPúõBÙ¯‰\r\ëYU¹p{\Èþ7~‰ÁRN^K9‰¬P\Í_KLXz¿™™Ó†—\çeŽu{ôw÷ÀGCbK¥¸ô¿ð/oOx\î^ú_x‰\Ù?A»þÿ‚|G:á€„þ\çN\Ð\ë$ýn\Ò\È˜p \ÌtøÅ‹kg,\0f\ä5 ðý\ÊK¥+Ki±9©\ãEChbŠñeey—=\\ü\âU^¹6\ä4vL€’8F‚?\í°\Ù\î\Ç2\'B?My2	²ö\Í,,\ÇùIò\éˆþ\ÓGxõ—Ÿ$‰xñS‡±À±¯žaö“\ÏpúWr\Õ+•°¢}Ò¸Vj\'ó‰zþÒ·\×\ß{7JE@}È¾¬+]6;P\Å\ë\ÇNŠ+[9ß±¼rs\È\ÜtªøPI¼\×\ÄñÁ‰ó\ê¡\'‰¯Ÿƒ‡g°Ž}??\Ã\Ëÿ\â\0ñt\Ì\Ë\åóøZ\Ê\É#‡Q´=\Ù\ÛÃ–Š\Ð\á$\â\àSq^‰„!H\Ë®”É‹\Ô\ÚhðnJ‹;\Ó\rkX¬	.©\Â•\Ìð„ck&\é°JLh#P\Ê`–Ž\ï*úé‘£\Þ\\»=0Z\Ä\é~\0¶VA\î©OfI$„A3þ?@¼w\Ü\É\É20\ÉKn\Âv‚\Òï…£;]\nb¶\Ò\ê”zŸ\Ò,+¸\ÑP×“\ë\ì\ÕsoÝ©X—\ÕF\ák…> ¢\Ödse|¨\r¯ulØ»\áC‚Ã¶½‘le3UJF†\Çf`Qéºœ\èþ<°‡d”‡\Ó]n™Y\âo¼\n\Û,Å­2\ÌÐš5E¹&·\Ø\Äì©º½<\Ô>±-$Y6\Ûô¯™\nü!bFMZRSÎ¬HH\Ó\"\ìpõB4LDˆe¥O\í\ÇúÕ³¥\Ê,\è•yd\ÛÙ•\Òôú¹ð|T¾_\É-ó•\æ\\$Ï†[mF\Í^=“½Š¨6õÿè ´!\Ú\nò‘2b{Pl Ž	§Hþ\ç$N­&‹@‡\Úu•Ä©Ÿ	§œL°¶BAK;¨%‡6ªr\ÓP	ohlZI#?¢h«\0\ÍÁ.Z—ý‚±ô|•S\îeð\á«\Û<LGZWõ¨Ž§»F\nõ‘>õ!…,Š»\ÇxPÍ¡´„õ¡Ú„©‚—½\Ò#°´°\È\Ó\Ö\î	Z\å‡#¢\'ˆSÍž¶\ÚÞ¿bmªE0ôU‹F\Íf\ãU\ÞvQDm3›j3 AQ•\Ú\Çô\ã\0¡9uø¸º¯šø÷cEm¶f\ÇgNTyªŸ9E=kJ\"-¶þ®²†ªô¡\ãA~\ãu›\á¥÷u´Q\Ê¶äž³2?lýu¼K€Ž6\éŠ85bJÌ·‚ò¢PŠ–‹¬˜\ÄÕ‡žA†°ö\ÓM\ç¼l\Zt\â\ï°ýJ<–	³qZ¾pÏ­¬ga–D”¡ƒ’8“ÞZ¦ž=\á(4Zj±‚ \r´\r	Ô·Ý‡\Öþ\Ò{½>R£‰Ó…\×.cµ¿W«\'ù8Ø¤\ÓCX°¾¼Š#¬EJ\â\È\ê\Ï6qFÔ¬LiÕš5÷:ó7D­ªkŽ}™¨ •c\Ä\ÛxVMe\ÕFû\ÕÏˆ¸$ûA.Gÿu÷;bXˆ\Ý]ú‹_›\ÈXmg\Û8q¢\rfŽŽ(cd2¦±©ÿ`Û¾l\ØýW;øh6‘x×ž5cgË­“D\Øp$­×²–Z/; ÷k \×bÁ]w\ØÇº\á\ì\×[\n;aðFAÿ‰E‘\é$œ5	,¦\ÐkŽð#N‡2\Ð&\Ü1\ãõ-\ÕJ@ªRksÌ™P§+yú¡\í \Öa÷¼€ø\Ã\ÂD\ã»O@<2º\å	X\ÖÏ¦ŠX`\è@z	t¡ÿ‰n+\Z)¶\×¯\èüè‚–\Û\ÙU§¢\Ô2g¡üU´\Ô1\ÂTÄ©ö½T@\Ç7T¢õ¨ú{½œˆ6lL 7l¢«Z?3+\ßù0Ä”ô>Ò±°»<¢l‡¥X¤¡\×R\Ø!° H\Ìô\È\Þ\ì\Ô\àÿØ\ÃPq¯+ö	‹Ý• —.€8\\\nrKÈ´Ü™\ÞšJm\ç´LˆKc\ZXK[£˜øM˜A\Õñ3J\Ã\Þ&MƒM ¢\Ú\"\ÅLL\ÇQtE$tœ<\ë5B: ÷2­$ûŒ¢\ïFñ%/Î‚8ô\ÖU\r\ë¶\è(‡;‚\Þû©>tb #1\î\ë)r.üeF8¸\â\Â\æ\Û\ïV9X\å\Â9\á\ï`\0K\É\ÎVµ\ï*\×M¥NŒ+5\'{<¾\áÒ½\Ø+	NyS\Þ[93t|uCs·~w\æóP¯Œ˜vp»|\â°e^[\nwÖºA\Ó9¸&\è­a½‘ž¨\";\Ë=o¾\æ\ÐóóÁ\å4²¨Up)ö‘ðüÀ\Ó=DÁ\Í;¤\ßEvE¨\Ë(n*§\ßH\É}p\Ì\Ç¡DQ´’8¾Em¹lj¾%c\ÄYM\ÞÖ¯\Zlºj\Ý\ïzð]=«\ÃÊ¹’|fN÷`o¦0¡NÑ‹ w\0z>ESAG\å\á¹#`Av†\àZV÷\ra\â\ÇCµz\ÜGþu…;A&\Ø\'f‘]¥û™d\×\â2\rñÓ–LC™Î„\í\År³rsö\Úe3Rt¤\èbÙ¶\Òø¬	·\ÊÌ©ˆ²ª·Í´v^>´“¦­2\É#@º =£vva¢iÛ†`yD\Ð\ëÊ…\ßÍ‰cEHú‚\Úw°@8\"sšl\ÙiÁ;4ä„<…Áõ‚I\Ì\å[9\Éû\Ð\ë	ú§sƒ|\ÌsÁ\0W.£\Êñ\Ï\r\Æ\íš\nµvJ3+ªÀ[3gÌ¶Y90\ëL\ÜžJ¬´N=‹¯\nˆ@ue•­\â	²ƒqû¦÷\ËÀŽ}k:D\"d‡¢ÀM…iÈ†û{¶\éHÃ¹‹€t0Do‚\Ì\ÜT\ì\'z\è0…\nCezMA\àÀÁ½¢\ÌþjŒC\ç½ò	‹\ÞPdwŒ\ÞvÝ…óùa\Ä­;’&%e`M’\Ç,\Ý\Ç{(Y,Ð‘\â\Þst\ìB\Ç1÷)]ýD{JsñQ6M ñ\â›\Óx”•\Æ\ä\ØXzPÀ\r \È&;„\ìŠoyH\Ð!ô>–@\â\Ç¢ƒsaÜ¥‹Hß’/”§[\ÝR\ä±.zm\0£.g¿1\à\àþ™™Á2M,L\"\Ô¥\åa ca” 3Ì‡¸;\á\Ü\ÓzöTªõþ‡…};\â0\ãJÏµ^Q\è•}¿5\n8\0A2\Âv\ä\ï[öý\æ\Ë_\n\å\Õ&½i´7-1\Èö«öŠ@a\ç\ßjlh;³ª»G\ám\à\á’¤ðÀúú<\É\Ã }‹ìŸ…l÷FŠ‹^	;\Ë\î:F!K‰ +Cò›\ípœ‰‘½Ù™¡¶7Š`˜\îJ`T NK\Ü\r²·^¿\0V¡Spöw3\ì4\Ä]K\Ï@ÿ\á˜DJ-¸ h\\wH\äP.¦ .¨òÍ‚f\è\é¹N;\ìoD\Ì9ªmÚª}°µ={h\ì¢öZõ0\ß{\'P˜1\ëmˆR€ik«M\ÜÁ×•þ\Ãy0&\Ï‚\ê\ìÁ½®\È\ÂY\È!wo9\âý‚0¼›a\äˆ;w\Ë1\×\ë\ï,`1\"¿y•dº.–´\É\Ã\á\ëi@\ä#	\Ø\ÞzB„{ò\Û¹:’û»\Ä]°· ®~¸&¸w<da¤\ÈõA0Ž¦ƒ¬”™uL\Ü{d\Í\Îq\álŽó\áô¯Ðž€\ÙBKEaUBˆ_\åH\Ñ{%\Ðj14ž…±i]Ai\ÜE‡\íw¡\"÷[°1’\ä\è\"\ä\×:<\ÕÃ½‘BŠ…²\Ì]\å1i\Æ!7,ƒw[’þ\Ð\æ\í:\ÔÀ\Z»\" |Z\á\Î\0÷]GönÁ¹[aß¶nz»bº#Efû½QnÈ±K\èþw\Ðln‚ü¼E½C2ž--\Ñ° `†ð®rñ»®>W\ÉJd£\Û<k†h\ã†0ì­¬F¸qX÷A€_\ét~»:‹\Æ\àñX¿T\ÊØ­˜\"jÎ«@±\Î\Ìù?¿3\âgÿ\Ñ6\äŸY\äŸlÃ»´ƒy$fûþ˜-Ëž\Ñù!öWºø›#¶l\ë[:÷ßô~ó÷~iu\Ì]ƒ¦Fÿ©ƒü½ú·½w\nøþSKÿ\Óÿ{Ì²\àoxFÿ\Ñ\ãFž\Ì+²µÃ¶\Û\Ø÷3žm]Á>º?Tü\ß)‹·=S½F\î ?%\\kÄ”óøÿWñK‚1\Âô¡>þÿ\Zb:þŽn€\âñF\éü}\Ã6Á}p\ç\î\åp¾ð\á} Ç–%OÃ¶û¦0[\á´[ý€Á€óM‚²2–\Í,j³¿‚\Ö\Ñh^9óµ\Ï\Ø~°#RE\îý\Ë½#`À>|^ö]ôvð»\×3¬q¨KÑ·	r\É*LÛ°¿\Îm\Ç\àz\È6r®G\Å\ê ¾E`[\Ûû±˜\â\ë)î¸ ¦©\ÒH#&\èù\à>\ZAòp\è)#‡z¡÷H½2D\äN\é=\Ãs)v{0¸_ýò v®F!²a\rzš\Íý|)$üø\"8\ç•\ØGžW¾9Cu•@SÙ•úyÑº\×dO6:]vÍ¡¹\Ã>=ƒf½Þ‘\í‚\ì\ÃÔž@\å]y0:4 \ê-‡ŽÀ>\Õ\Ç\îŒ`{ö°V…÷AvG!¼Ð·\È‡j\Î\àF\ÛJ@\Ë¸EE\ß\ËÐ‹A\Ñ<wdv² šq\È^°3Bo/a\Ö\ÈA\\\æ\È´ô|\Ö\nG B–cvTT\â®ú¿òLdº¾\r›™A¾Eˆ	h+AciN”/t\Ü|;ûV\Æ3÷po„†°`wZ\Üüû\Î<ˆ¢n€ ‚\Ýh„ýøV\Ùgð [‹& \ï…}{’côVNKp\Ýb\Â>ž\01\îfFú>+ñN°.\Øð\Òº]r\ç\Ø\ßQôJ\nA\Ï\ÐL‘H\ÐLýÀ\Çúp-Ev\nn ¼ôµ´&Nl…8Ž±\å\éC×¤	L\â®-¯W†xK7\Þ\Ðo£ $sfQ\Ëo7ù\í\É/¤\Þ		½¶Œ<ûXÐt\0\î\"\äß†b¨\è•!²·&\ÅÍ§³›t‘§{p\ä‰ýD}Gf‘$Á\î\0¹\âG û©Y¸­¸W¹úzBL„H„™1ñcI\0§$÷C¼»ô\î¢\Ï	\á\Ù?R¬…‘\å¥ß¯ˆ‘l,8&ø\äºÁJ8\áÄ–§‘	Œ»V\áöCol¾\Ñì‘‰•\ÒRfµµ=\nm¸ðž£ÿxœ¤;@/\Öu\æb\Æ\á½=Ürˆl\Ìð.’/¤·”\Þý1\Ø!\î÷‡d\Ý{]\0~Ž\ä!E\ãFŽü\n\È—qóŽô&ò2û\È;f¿|€n\"\è[)jûP\Û-\îôE0‚»\è\ÈoCòó€µ0\í\ÐK—.ÀÐ‘¾Spòü°ñvwq\âN\Ô$Zú.¬\Ú\Î,—V8FK¼•6 Ð†\Éóg¦»+=0Ô©Àq¢\ê‡;\r:\ÎzhoCÜ†CO÷‰w\ä!‹\àn(ö±\Ðõ–\ì’\â®;ºt\áÚ\èAKúÝŒ\î®\Ô\Õ\ì¢ðy‹ýW1D]\ÜÅ‹\ä—\àÜ•\Û4…þ^Ëž\é\é\Ùw•\ä‰öñ\î\æ\ÈÞƒ\ä\âÀ<Ö…íŠž\Õ\à‘0†Ž“_MÉœÖ¼¸#ô\â8œ|\âK¯G²xª¸\ÕfÈ¤Yrta\í³6“\ÕCe¨\Ö÷&þ\Ç—ü©R­z˜t¶\á\ì\ë>\Ð+¯Å€\Üß…ÛŽôE\ï¤$\Ç\È^\ÃG\ÙÓ›r¡M\Ó±1Ì§\ÈP \ãxš^\0µd£,l\Ã$z\Ù)ˆ\í\ë\0!C\Ïg\äO\Ò\Ëú]ô’‚‰Ñ‹)º \Ø\Þ~t1E$§P\Ü\ì¶r»ÿV(¢J±k\ßZ°ŠÍ¸‘š°‰¼¸†\ÕÕ†¨œ\êõ\n²\É#d\Ý|…x7`b¸)0J u\è%%~¤G\ï‰Â–eñt—\èANNq‘\àU8t>%ý6H\ì§fÀdo\ç\\}\'cþú0¨»·•X\Â\è¶ûû°0@¶•\ì‹»4\Ð|\Ø”Ò³Að@1¾\ë8÷GYè§„\ÓmTæ…—\Þ\îhQ)r\Æ=Ý¥w\Zƒ¿¨ò¨\Î\ÃX_KØ@Žµ\å\Ðx>2c³¥ŠÑŠh+uƒOþ»}7%»’\Ãí°§¨Z°dHò …ý‚ª£x—\à¼\Ô\Ð*AÐ›\ïvše\èüE†pn~H®”nW8ð`‚\ì4s¤‹ %\È\ã{`\×1\ê\n\â¾ÅwaU\Ö\ÈÁtŸ\â¾¦\ÞÊ¹:r8&\'ª‰,\Ò$\'–xh/-‰M\ååŸŒ)ù\Ë6ô$\Ìþ\Üý¿½m!\Çl\Z»_yý’\Ç\ßõL-•-[õS°\äƒM¶\Õ\à—¨+\Ô\Þ€K\ïŒ\Øù…\í{§0\Ø\Ç-^úW\nÿ8Ágÿ×Š·žøðýlÿo¶ƒ_À\Üo`‹\Ü\ï€ß¢\\ÿ«En¥Ê­¿V¼À¶Ÿ‚_ø\ç\Ó\Äf\ÆxL¡D\ËÌŽ!£\×S\î¼½§{\äðw=º‘q\èùÛ¸\Å`p\Ïý?Ž©û`\Ê43\Çn\rñ‹`¾|Ÿ&$¾\ÔB”c¦Ø†G—Šb8Y\Ð.-ù5=	\è‚sö\ç\àc\Û[‹›\ê\ì—\n\Ñü\Ö\Ò!T6n\ä›!´¥\ä{º\äƒ2\Ó\îÀLw„lGö$\èw\Ù#¶Œ<~iÄ­ÿaþqDò\ÄNx\ï£¿2R\àn\î*Z\àÿADz%\'À…«`\Ûß‡\î´pÿLŸøz¸\ë\r=F•\Ñÿ\Ü\í‚;ÿQ1\ßÿ!\Ûþ	Lm¶?lq—>÷·\×s\Åm5°\Õ :?m\Ø\Æ\æ.A€|L•—°4NõYò@\Ä\ÔV\Ïh\É\ã1ŒP½G—”KK¬I Y\ÜH?\ÎQ(‚ò2-û–Ç „õóªŠWƒ‹\ï9\Üy\Å};%K•\áv[¤\'ô~uOH&\é¤\è%Aß†b^\à‡ü|Fq0.G\à:U\äò!ôö\'ôöS\'»ˆµ½[\à(\ÈAzB¼C°}@•ô­!$B~§`\îŠ#­¾5 SBì£°¸°Lˆ_‘4²\nTq4!lª>¤+ðª\ç³\ë\ás[Áx%U%\êZª¥ˆ:Ù Jð­ò}•_+\Z«\èŽiš“^*H¯\äN\É\\p¡\ì01ƒóºÛ…uO%\Èc\ï\r £\è‚\ÃÚ„\Ë\ß-7™,Û’^\Ì\à=¥Z.[Š!`#zû\â^Db¡0\Âà­‚lT Ó‚ý˜ \ï\íŽ¨¸\êg•\ÍS§J­\Z“&\ë~\Âó¢\ÆA^\âðPGþ‡õp¿)¹2{T¶Ç¥Âšyr\ë^\Õ,Z1\Ì}×‘\ÎMJDH°ŠÎ§°» hö‰~\è\Ý0k‘º\è¸úNÁ\ÜÛ­“#K¡<xW\Ñ\Ü\á \n²½\ì± Š\ínºü{ø]P²óas\Û*!8 U÷£ AŽ\n‚Oª(ý”\Å8A\ÖqAX¨ÀŒµ<c“‡\ÖyuóY=!m6\ìh[gýO$Z´\Ä\ëh\á”†H“\É\Z·G$÷\Ç\È]ô\ro\ÑóýF\Êü¿»Ó^T\Ñw†¤7\n4\×\à¸d¼<^ú½”\Â(ö7¡iJ´CpÃŒ\ìJN´S\é=“ôºX\Ñ{¢G\ï©.\Ñ\Òr“Žj\Ä\Ç\àŠa4Z\É\â¬m\Ý\Ôñ4 \×ä¼¯I¤M¨ÿøA\Ä\Ù|JQ. CòŠ–1«$©Gø$‡Šìˆ¢¯a—€s\Èö€ˆ\îƒ	‘@òDð$8g\Þr\á\Ý\É\n\ã[z³À½}7TÒ›9yør!;Ÿ#8¤š¦d×‡¤\×B„´\Ò\Ê\ÄcZ\'T\é+ª‰[-\Ñ\Öÿ\íúš%\Zx\ÉÚ‰\ä÷6E \ì\í9b:\Ôpii*·ö,]•Í­\çgZ\Õg?C°°K°¿v0x¹\ï\0q¬e2{Nú\\ýnÁ¾]“kœƒ*ª\á\æ\Þrd\ç…ü\Æ	l(bþlNz±\à\Ì\×3†\ï¤…\Öªs\í<¸Uú§«ü¯m\â›yU”>¹úØ…uŒù\Í\ìúûo‚\æb…\ä‘ñý\Ý&e©BsÕ˜‰†®\Õ¿“ž‰¢¼ò›n*\îõÓ¸òo+²]\Èo)’(z-Š\îrepM\'Ê®\Ü,\Ô\Ì\ÈÀ\ÙwR\\P$€\ÌX\ä\á3GböŠ\èO[Š\á@§\Ö\Z»ü\ÆDj\án\ç9[#\ä>Ä\ÖK\Þ\Ðz\å§\ìE¶\Z<Šy\Ü_\ßA\Ø÷ô~§¨ø\ÊPe\n(µŒÑ•|Áã·‚\ÇC—6\×V\æ\ßS’þvb\í\àG\ÊHü\ßüøgy³£\ïOa>×¿\×fo\Â`ÊcŒ\ê\â>iØ¾Ý„¼¼\á¹ù\ç·\è\Üuƒ\ï,25—Ký÷.\È]\0j˜ºKc÷µzb`\Õa\î\Çú\ß|£>ó?\\ò\ÜQ%¾\Ï\à¿Rø÷÷D \ì\å\ÛG*\àQ¼\Î{t4\"º;…ƒÿþb\íI7u3@\ï¶	  \"_\0³l5°\ä\ÙR¿º>¸¶@oÄ¶j\Ù\Ö\ÙF\Ô¶	v_Bô¾#Rø‹¿Z`ôƒ¦üˆ`LVGÀˆ)Ë¿/xFž‡û1q2…ùpÿ‘„ø¿ÝŽÿÿ¸þWžù»\nwƒ\Ã\×\Ü5t\î–]X2x_ef¬Dº_j.³Sµª ¶\áÝ€\ËE<CU¬ü’¡¿\Õ?ð\ÎÝ•…u½\Ù\É\Í\ÜVju{\×*§ >\'Ñ†AUñ¡†å„ŸLn\ÓoVMG’ú;u‚.:ŠÄ± ;@o\æ¸\ëBz[Q¢™\Ðh†‘Z*©¢jQ\Î\Í\ç\ì\Åaù|Wa4$¤Õ¦eF©´\'ý=d„¶\Ù\ÜZýngúœ£×±¥¼\\)67T\ÚL	Œ\Ð{dÅ½\éP-V4½½y\ÒF\îô 	J¹Xx¼‰\ç\Îg<c{!ðó	\îO2°\ÞT²;E{Ú¶z\Ô\ÚôVªò#¢©2‡\Ï@¼?dœb »R®œV¤Ú¢eŒ8\Íÿ\Õ:¢{†\n­CžªVW(±\Öðºó<\ÝþtM÷\Êýe÷w¥Œðf«°ý£1|Ä #t´¦s\é‹A‹¥õÔ·\n„\Øn#\êDLýT°ü’Á\ã\Çxý\ÅkŽä¾©25\n¦¬ý2u!´ªL÷2[\rf+L\É˜ ‡¸ð÷x\Ú #%¾\ëÉ¯.0ü¤Ãœ\Ñ\Ý)¸ûÿ—w6!rW\0þV\Ô:¯aÕ°i@œ\àX\Â	L$\âCr±$ø\è‹\ï¾\äkpC 8c\ç`\â‹@’/\ÖEh¯I#ˆ ²\Ð\ri\èBj\ï\æP?]UÝ³RrM‰\Ñ\ìt\Ït½ªWõþ\ß+;Î…œ\å¬.8«KŠ\Å.;ª`xly\Ç\î‘\â\É\Z~>Ž—‚3\Ð\r\Ö.\×aù’.ŸQ/\ÜR2·Õ“÷\Ù÷oœ4uC»±Y\"‚þª¸T?ƒ92\ä\Ñ>V\Î73d‹h¥\å^ê¶²RQ\ï2\ÒÜ°yÀ°\\\ne=O|>)Fƒ\î.iœô“lO{\ÉÌ½\ÖTT¸¨ƒ\×_ŽNwÀ\å­÷„\ß…@\Ý\Ö]‹w!UNÿ…1	N¶n\Øú\ï5ûß¹\n\ÆFó7GµÍ‘iÛˆ9\ã\Ä\ë~Î·õP.„p\0„\ã?ý)\"-9y\\?2‰\ÕÂ—‹	“¨²—\ã\ê\ÞY#L\Äe_[\'(DM\0\0\nIDAT|ú¡§Š\Ô	9\0º°Ö„Áò%c^R:A\\¶\ÐdQ \Â_øÃ®¨0¼¾ ùcNF˜G^\È;õÃš\ÕQƒ\éZú¶\Çô\Ö(I´z\â	\î·z\Ö\É%:K\åô½ƒJZ`\Îs\×]Ÿ\ÑaR¹\é\È(\'DtŠ\'}\È3õÂ€G”˜©Ð«~6¡X@\ßb‘¤C¯F\á&Fþ~\ÒPPˆP\Zcy¼k\Í\0¥I«‹\Í\"è·Œ‚\Ã[¶º¢\ï,þ\Õ0¾\Çd-žRÜ¹\Ú\Æ™È¨˜\Ä,Œ‡ny^\Ü$†!·\ë)·«UOBO)r¼U œ\Ã\í\'\Ò\æ)øOù\Â)\\¿\ÅB\è;\æ¥À\ÎCŒ(œ\ä~A\è\Ý´²õ³\çe¸mº®3\åôm\0—E‘N‚\'C.û,\ïÀòO.˜ñJR|D\ÎDsM¦$Ž1\ÌvüD©u`kŸc2Z¾¯|1){K‚\íó%ìš„Ì¹]\Ú\àx¦¥Z\Æ\Ô\Ë\Æ\Î\å;\ë\'š®½©¸S¹ »r¯aiüÁlú‰O=6[l]ý\Û\î\Ç‡³UõOþ\è_*d\á\Ó\å%Y@“\ä\Âx‡šQ(ˆûLP‘j\ß\Ó1\Ìô\ëß\ÏlzR³\ÛmZlD\Ò\0õ¦fÝµ\Ô»0À\'7¡ñ\ç/_º\ã*\"\ã\Ù\"	±o\äHj¶o’|Cd¦\Ï_¼%28\'	˜ RXr\äf”\0÷-\ÉD’Nø\ÔR\å\Æ4’¸œ\Ì~\×ùŒŒM\ï	¥²¯¸ÅŸ&\ëc}ÿ 0\Þb¯H,\Ö\É/üCˆV¨”\Ó\Ë#°N3Ÿ\Î7\Ïgz|\â­]•…\"\Ô3\á^€$¢ù\È;\Ãbˆw$	–\åm$6\Ù\Ý¤\Z—\ß\Õ~~l´Œ<5j}\ë*¢œô…\ný…­\Zü\Ì<(\Ä\Ï\ìš\0¬@õ|E\Ó6Vüö+Ë£ff a\"ŸQŸ$ˆ%\Î\Â)‰Ij˜T”ŽcË˜\Ç*ÁÉ¯ž¹i4+Q\Ý\"·‚~yUømk\à|Aùu\à/†(xl\ÉT½vn¹öÃµ\ÖÑ¶±C\r\Ö/dZ\ï\×0A|j‹$ÀIË¥³\ÊŒ°Þ¼\ãž\èI©16q°\"­§õþû\Z(1Tqp\"gdö\Ìm-,1£FR¸VÐ·®†‚¾³\ÎYhö_½\ÌúOŸa†vr\ÔA‚ \ê\Ñæ‚·\Ë2 F23®_9½\éyz¦\Ë\ØN	Ž¯‡ò‰}WY$Ä“jR;¤ø\ÏsG$øÀ\Ìf0\áüÎ›(›®\Ïy“id*Žìª½\É).Î•Vgz\è\í€zµ\Ï\ê\Îš#W`}\ÚmÚ•¯ª;\á7\0\ØÜ—ö\È\ÐµOMŸ\Ø\ÖLôÿûŸA—Tö\n©1\á¹@3:tù{µ\ï}0¡¯Ü©h¯M•O\àk¡\æ»bu2Uƒ0J—VvÑ«\Â\Ö\Ò.ý\è»4øºm=<o¿LŒ¥W\ág%|\í\ây”©¥ÀZÝ¤<0ÿ6üóoÿ¢3X>u2Œ3ˆ\Ú(\Î\áÔ™XP²ÿ\Ìñ€a€3ƒ3¢\Ú\æý.>HÒ™\é›\Ú.\"\ê\ä\ä0Ç‚d¬*y¯;†/]`bw\ìœñ\ßXx¿|<0<vB\Ës»\Ï)\ÔsÀ±\ÆÝ¯J\í²{†c\Ãbõ\r\Ô\ã†ö\Ñ\í0 ð\Â~\Ãùª…U ‚w\Ê\ïk„\Åô°þ¢¶q]žo\ÃF¬\rA3H‹H‹ÿŽ$÷FÁ\Ãû¥\Ú\è~ ¯!§ô•·\\\'\Ë\ßó\ïJöy\Ò\"x‹Áºtg(\è=M±W\"Isc0¦aõ\Ê\r.n\Ø<\\c\à\Â‘¢úœÜ¸~\é[ö_¿Iý\×\Ïa0¬^½A¹\Ú\çð·¿\æó{˜®G¾y‘ƒ[·¹ú\ã\×i­ù\ìÖ½0(ÿŠsVý`b²±u€0¿%UŠ´Ø˜#$\æ‡s\Ö\æ¸ÿ\Ø#e;ñ\Ý\Þò\ßxk‚\ï§\ÄPbsZ«\çWP€\Ö%ÅžF\ïY\Õ\í\ß|\ÈGGn\ÃN\"h\êsfm¥Œò|…©k\n)mE]²þG\ÑB\å“š®\å“[÷&\ï€\Ü37 \Ø,2Q}Ë˜üœHú,-GŽ\ïw.p+G\Þ\æúÎ­\Øq5+ƒ\åq½SEú\Úû‡\è=\rü—²¬X]¹ˆ|l¥é°ƒ\ÞVrrù•K\è•­&\Üv†z]Sw\r\ë‡\ÊsKš®µ‰²NoŽ\ÚY€òI‰¯\åƒ\Ùf,Œ¿­MLA\Ñõ)ƒ\ßÇ”\çy	o®\ßÿeQ\ä\Ïô}öŒ½BÁ\ê\ÅºÒˆ”Zx\ïwñ\ì½«õIõ\â\n]\Ú\íVò\àþš/\í\èû?b17ÁSY\çtÀc½#©c£æ‘œ<;³©ù\ï{›\\lXd´t¶VÜ¶¶-#n\Û\îŠ)Á\É\Ûö\ì¥ª=Mõ|…”%m]sóþ\áõ€KZ\Þû\Þk/!Âƒ;÷8x¸¦öŒ›\Ô?‰Œ\Ä*{ñÄ¶¥WÃ€‘oxñ9®\åûª6jµ\î¬b¯i«ýÃ¬½¬\04B\íòa\ívBkZV{:¸L¼g\Üi$=­1i\å\âH„×’¢ 5†Æ™mJ5zrý\nŸ¢\ãÇ£ÄªF±>5gùoœ>».<¬´fÿúen~pû\îÀû/¬NDk\Ü?d3˜¼\á%$¿{X‰°\ïL\åÁ-,bkK;\É\Ät†ºm@	Õ²t¶:\ç\Ê\îM×³º`¯{)­5†\Æm¬Û–gzW\åª¸‰ôn{¼f©\í¤#QNúeÀ\Â\â\Ç3Z\\€\Ê\0‡ƒõ! cœ¨\Ê!­5&\èH~Á6ƒ½¿v“v§\Z\Ý !HD\ì2*\Ôx½\Þ4”\Ú&5#z\Ì¨\ÎWü\àƒO~¿\èw÷t³n[¼Èª\à\êr\É¯\\r]ƒ1\Ð6-\ëG5\ëÎ°t+É¯n[@\È`½·°Á\ï¬QSŽ\íq\êªyƒkˆý\Þbjñ\Ónq˜\Îò\Ë4¼i\Ü\Ñ^%°\ÎV+\Û\×\ÚY#\æ$:VX&o¢\ç\êlLþ»¾%þ.\Ò­\Æn€JÁ•å’‹Ë’eUñ\íoÿt\çý—÷O\0>ÿK\Êoü\njƒKrÀ‹ŠB¹»6\0\çE\ë\\/#\Û\Ú,³w÷E\Æi›\È<:ôR¤Œ\Ù§™™¯T#·œØc»ó¦i9o1À;Ás¼,„NxDÁja\Ý¢…zÓ²ó¦\âD»Ÿ\âÈ•\Ï\ëF„\Ý\Í0\n±Ô–‹­\ëM[~-g¼±·4g\Ö\á{\Ñ.\Óyb\âÕž\ï”9ô4! 6\Ø\Ð©T87n\í®k\ìqo…€^h[l\Ê\Z÷«zÀ\"(*Ë™\Í{e#J›ˆ<\äúO,\Ù\Í0S@·iü’}(µ†E‰^.w°ù¯\ïÜ¾nWù”LÇ„o^¿qM\0š\Zó¨f}Ô†g\ÆÍœKdNòœ#S9‚Ÿ&Ý•¾o•/†9Ëž	®–·EN&®f÷wM`ynÉŸ6w½d½\Ù|\êxN?\Íýÿ¼]\Å5¿V\Ë\å·ü\Ím\ä\îp³ù\Ôÿý\ïc1òv¢Nš\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(1234,'Neon candy',30,27.369999999999997,15,72.62999999999998,'2016-01-05',2,0,0,'ÿ\Øÿ\à\0JFIF\0\0K\0K\0\0ÿ\Û\0C\0		\n\r\Z\Z $.\' \",#(7),01444\'9=82<.342ÿ\Û\0C			\r\r2!!22222222222222222222222222222222222222222222222222ÿÀ\0\0}\0–\"\0ÿ\Ä\0\0\0\0\0\0\0\0\0\0\0	\nÿ\Ä\0µ\0\0\0}\0!1AQa\"q2‘¡#B±ÁR\Ñð$3br‚	\n\Z%&\'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyzƒ„…†‡ˆ‰Š’“”•–—˜™š¢£¤¥¦§¨©ª²³´µ¶·¸¹º\Â\Ã\Ä\Å\Æ\Ç\È\É\Ê\Ò\Ó\Ô\Õ\Ö\×\Ø\Ù\Ú\á\â\ã\ä\å\æ\ç\è\é\êñòóôõö÷øùúÿ\Ä\0\0\0\0\0\0\0\0	\nÿ\Ä\0µ\0\0w\0!1AQaq\"2B‘¡±Á	#3Rðbr\Ñ\n$4\á%ñ\Z&\'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz‚ƒ„…†‡ˆ‰Š’“”•–—˜™š¢£¤¥¦§¨©ª²³´µ¶·¸¹º\Â\Ã\Ä\Å\Æ\Ç\È\É\Ê\Ò\Ó\Ô\Õ\Ö\×\Ø\Ù\Ú\â\ã\ä\å\æ\ç\è\é\êòóôõö÷øùúÿ\Ú\0\0\0?\0\æ¤ •\Ç\æ:ä³‘Ž­-\ÔAk—Qœö®¸\éc\íXŠ\"ø\'Z¸\ÞK\ØB\\\Êc?\Ä\Óñ\é\â2¼%\\-\éJí«§Ü…\ÆY”qÿ\0\í~\ìSiÇ¢ÿ\0?#˜ð\Í\ÎËƒ\á?ze;±\Ó\Â\ÚU”iƒ6\áÑƒŒ\æ¦\"HC:Í½W›®+\ã3.\Å:NqW\ë§\âv\â8§‹\Ä\'Nvoº±°\ÑG$^XP}N+‰\Ö|15® Ú†˜[y9u5\ÕZ^‡þ^GZœ8`[¹¯–¥Z­9i¾\ÖýÅˆQÕ˜ú\\\íqgF‹$‘ƒÀ?áŠ³ \Ü	ˆŽNñE8b\0F88þuc{:#‚H\Ù\ÃÁ8\í^\Æ\ZW\\Ý™\éá±‘\ÄÁ\Û}Ÿõ\æZ†\î%–Höò\Ù\'‘ŸoÃ­Au\"\É\ÙPa8_nx§*aD¢=£’W\0\ã§ø\ÕY\r6c \Ï\î\Üûô=+·ë¸Š•\â\å+½Ì¾§B4eNIZ\Öù\èr]K%\Õ =\\J»¨\ë‡GX\Å\ÜN\ÑHv¤ˆ	ú{W9¤_€&B®x\ÇÒ‹¤»²òfL‚^ÿ\0J\àž\rY»«K{\ßw÷!O6©C¡]^–Ÿs|DŽõºù\ÛÀ¬Šƒ\ÐsPÜ´Å–Àç¹¯8JnVHúlG²”m¥\Ö\×À9\ÎÖš5\Æq$\Ð\ç5\Ç^\ÜOs+ydÁûÈ¹ˆ\"\ÕUI‘\îµôXL®q‡:Œ­\ä™ò˜Œ¢U_3©\Ù6“ûŽÉ¼B\Ù·\ëR\'‰\äG\å\å»\n\âd*Õ°\ÏA¶¬i\Ìûg±I°\Æ\0\ëZS¡R­^E&¯¹Õ—p\ÅJµ”*\'\Ë\Õù\Zº¶·8¹\0\È\à•Œö´Vd\Ï$WÍ—Œ§\ç\nXzg×Š+\ê\èºt ¡‘ú¦\rF•(\Â1VKú\èv÷0\Éoj·6\é”\ÎŽ™>\Õj~bl\Æ1\Ð\â¯AtŒªyª•\Îx\ï^}\ã+X°2_i24\Öc\ïDÔž\Û}ûTd\Ù\Å`¨\ÔZ­Ê³\î­Š\Ä{zO}\×õøüŽÑ®‘”†|vU&‘\æbZ\àtŸjrÄ¶ÿ\0d’géˆ”±¯DÒ´9’??R*\Ç<F™8ú\æ½\ï\í<4b\Úg\Ä\ã2,NªUQ‘¡\èú\Ü\×r\Ï,\âlÇ¸eˆúv®šK\'@Y÷`tÛŒÖŒ…B½ú\ã¯\åTngTL1=8¯†\ÆaèºŽ£‚W=hf•¡{£»<\æI>]«\Ó=\êm*ù\î§(®w\"OCùW1\â;å¼¼·ºŸ\çOð°‘5¨ƒ;m278\ì¨®*rQ\Ûü»\Êpu`–\"öRZ«\Ì\Ê\ËPKg<\àðqÒ£\×û&S’À#\î\ÇaŠl®©Q•\Ý\É\ç¯ÒŸ\Ã\é†\Ï!²§#Ú¢Š_X³\íþG\Ðr\è¯\Ü\à·O§Ë¹%cò¤c\ØþU¥«s;\rò°^•ŸkpGITl\É	$\rPÔžK)¼’k}\Ã\ë]˜¼—½M\èÿ\0ñ\Ús(jk]kŸg\r‘ZZV—qt\Õù\ÞH\â\çõƒ\á\Ý0^jh¼\0ª}\Å?w\'=k¾Y>\È\ÛC(ÿ\0t×»“dt\á^¬n\Þ\Ëõg\çœa›ýRO‡\Ñý§\Õ_¢ýI\â\Ó\í`b*:*€*\Òƒ\Æ}\ê\íù%\Óvô9\ã\È\êºß•‘\æ1nƒi\Ïzúz“§‡‡5YYv>?/Ë±xú¶¦žû\ëŸõó:;‹\ÈpQcM\Ù\Æ;\æ±.\ÔO&\Ò@ÁÀ\ã\íL\ÒFŒ^\Ì;e#Ó¹ÿ\0\ëÕnD—ü²HU\ë\È\Ç\\ýkæ®ªÔ•{Y=——ü÷¬§ðXxÓ“¼’\ÕõlHa%›vý\Ý\Ù\\¨ú`qEö\ì³2,ŽÅ†\îrN8}(©u¢´=5}Î¶	ÀYHe\ÎsŸ\åô©\Ò\ãkb3€p3YúG‡®ô­.8.nŒ²\'M¼\01ŒsS£ye÷’Aƒ\Æ;Ÿó\é_B¤ùi\ËU\Û\Èð¯	¦\â\î^²¶³·šIm¢	4‡.q÷\ÛÖ\Þþð\ã*só)\â¢Iž8¢#*sŽG½6uy”°¾Pv¯÷½«\í©\åx•†Fõ\Þ\ß\×Sòœ\ï0\Â\×\ÆÊ•§{7Ñ¿\ë\äM-í½²y…Žq\Íyÿ\0ˆüS4ó46Û˜s—\ÇÊ´É¸Ô§•; þµe´»y\"\Øc^œð+\çkc]YªJ7»·«>›%\ÊiÂ¤gˆ\\Ï·Oø\'-£\ér^ÿ\0¤\\)v\'øj\È³®ö,k—žõ\ÓY\éI\Ü;´q\ã	\Z\0\0ªš—†áºŽG†\á\ÖB¼+€s\éƒ\Øÿ\0}<¦Ô®£v};\âL£Šú¥j‰Kg£²~odZ]“¤oÐŒü½zq\Ï\Ó5=£Åµ‘ˆô õ\æ¹\r:\âm\çû;S\0aº)\î_M¼v\ï[\ÝGfL\Ñ~õ[¹=\ë\æª\ÂTk)5n\ç§*Q’~\Î\\Ë£[?ž\Å\rJ\Ú+MA\ã\Ýó>d\Æ?„Ÿñª·Ê—0¸vR\ëó.=iºÎª%Ô•B¡\Âm$žG\'½V·Ÿt\Â\"£s3œ\à“Šú\Z£8#Ö…)û%)ocWC”Ç¦‘y\'îŽ¤úV\â\ÝÁ\ä1‘a‘\Ûu\àtû\Ã#Þ²\Ñb´·\n\Ï\Z9c´\nJ’Aü3ø\Ô-)B¦B\ÅÀ¾\\*© }=¹úY\âjr¨§d—õs\æ)\äx7VuªAJsm¶\ÕþJû/Ì“U³ó$S\á$\ç=ÇµVƒ\Â\Ë}:,„¤(\Ùv\Ç_ökWL¯G\æ—\Þ?\Ý\íúWY\Ã–ª29\é\×Þ¾6\Íe<[÷¹šØªp§—7O¬¼Žj\î\Ò+X”œ•R@Ûœþ5‘qv,\ÊnFde\Ú=þ}\ë£\Ôf)Mª\Ã<¼c\ËK]Nr\ì\È	 gž\Õ\è\áó‹Òµ¯$º#\×\Â{\êóØƒC¸0j3«t1\äõVu\Ñ6÷LS;ˆ\Ç\áEps\Ê~÷sº¦5%\Î{$Ê£#8¬-U¢‰_-Ž:\æw\ÄV\Új\ÌL‡¢Ž¦¹\Í%.<Cvn.¾Î§å ÿ\0\ë×ƒ†¡+s-ô\åþg\ÈB-k\'bÍŽ£?\Û3Ÿ‘X²ü½s[Y.3ƒ\åñ·Š­-¼Òª¬EPeN\çVG–‹°¶\âz\ØW\êyeõ\Ì7,¾8hý:3òŽ*\Ë^\í\éü\Õy2½\ä;\ÃÜ¢\ß\Æ\0ÏµP>YC1\Ãù`N;t÷­|’6†\Û\ìGQXW\å,\çxüÁ²\ã%AÀ³ùVÌ¦œqk»Ï¿õ\Ôú\Þ\ÍV%ýV»÷\Ò\Ó\Íu_$k\Ù^Cu\0\åxw?ýz·•B†$9\Ô\ç¯ùö¯>º¾ž\×6Ò˜¤?„p\Ø\í\Ï\á[Zˆ>×¶;­±>\0\Üs†<\ä\×vI\ÍQ¨\ìúvðNN)\à\ìF\Z¤±øozwk\íE½~k\Íjº›:„W–OÑ«§<`õÁ®bo\nN¦E±»*…r‘HI\É\Ç#>\ç§Öº¿9‘‰\á‹™Áús×­#<fe\È*:“\ï]•ðq*\Õc>§\Í\å¼G˜e-<4ý\Û\ëª~ßƒ<®\æ\Ö\îÁ\Â\Ý[\Ë\ÏIŒý3Öµ|6‰u¨K;Ÿ’Ì™Ý…Ýž3\í\Ôþ»\Ûûx/a6\×ð$\Ð»\"\äžÕ†t¨4\ËvŽ\Æ1˜>t\ÎNÑž¹\ë\éø\çšð*e\Ã\ÍMJñüO\×r>2Žs	Pt\Ü&–½U´\Ùô¿f6\å\âž\íbÈ…y\Ë3Ž9g§9\Îi!=Ç–À\í ÷†\Þ\Ù\'Ÿ\ÄþU—®¼’Cœm<\È\Æ§JÜ³f.;±=I\Ï>§“\\®5\á\èû»½ «J?#~\Â1jž\ëBY•\"+\Üõ=«:	€\Ñ4\ÒÉˆ`F–f\ÉD\\d\\\×ç±„\êT\Óv|\Ýz\ÉI\Êfˆu‡Ë…Nn=‡©ª\Ðþ\á£©‘\Ðg\ëZ­\à+›§7w:ûQò£\Ó\æ\ÏÒ©Int\Ù\r¼ÁZDÂ²“‚I\ïø\×\Ü\åXÐ‹RÝž\Æ0\Âbi(P•\ä·_\×B™²‰¤/ \ÎG4T’O\å¸\àc8¢Š¹t9\ß.Ç§\ï½L;&\Ôn#ž\æL©Ál·-\ì+\Ò-§-V\Û·Ž=«’6{ \ÛB(bB“Â©÷=ú\Óà¿‚\Æy¤Wú\Ðv†ŸÂ§€öx~h\ë%ýhx\Ñ\Ë\á;;\Ëwý]\Í\ÍNò(÷2**÷\'­:\Êñ/4ø.ŠnYP¿P;\×miu\â\Ýq\îfV\ZlL| F_\ÌWo<I1lv\à\íG\rU¥…ÅºUe\ïM|¯º^§\ÃqV\ZUðŸ»Z\Åþ.w¥x\ãŒ\äû\Ö7ˆ•\ÛG\êC`}pJ¹%×•3\ÅB	#¦O§9¬\Ûû\å•J«dH~r1\Ó9ÿ\0\"¾\ë%O\r6ûi\æ\Þß‰ñ\Ü+„\ÄG7£VwM=ºu9Ei\äšC„Ã’G\á\ÅmZ\é¡-•›9# w\ìv2ªK,EN\ì$\ë\éVZ8\Õ\n\Ç\Þ\ì+\à±\Øj®Ó–‹\Ö\ç\ì<GšT ¡5Go™\Íi:ü¶’\Ïkr\Í\"‡ 3Y0{{{WUmy\ëû¹–ERyCšó\çU\Õ\î\ÕN|\ßÎº?i\××ºº\Û3À\ìyp¹\n½\ÎŽ\ÝúW±„\Î\ê\á\"£WÞ\â;\áŒcO\ë4e\ì\æ\ÕôZ?U\Ñù¯¸\î\ì\ãW;|ÊŸ;\çœûV´Œ\æ•p¥†0¸\ç¨þ¹?‡JôŠ;U\È*@\É\0œc?Z\æµ[slny„|Á±\Âû×›‰\âO¬b/hì–—õ7\á<¾9U.I;\ÊN\í÷ò^‡\'cpdÂ³:36\àÀs\Ó\×J\Ó\Ö\ÜHùN85’%\ê’;ci t°\ïþMnLð\Ïdö“d))\îŸZ\â\ÆÎž\'É®§\Õ\Î5e76´{/\"\í˜ao,H‡€=+sO\Ô#\à\Ãu$u5\æQ5½\Û\Â2\Ò+avŽO¦t^ŸP\ÇúM•\Ìx+\É(o\Çr\ÓÁ¨«\Ç\ï>oˆrºµ©^“ù‰\â’H\Æ\á\×=Mrž1º€\Ï`e\n7\ÞÀƒÁüMIý§?8p\Ã=¸õ®?^Õ›U\Ôv¨o.µ7}Oùô®\Ì=IA\ï©\âpn[ŠY¢”\ÓQŠwv}V‡Ilc’=ÿ\0<¹é³®;óÞŠ§£J¿f\'qÝœq\Ðóü¨¯¨§4\â™ú=ZmM¡Ò”Š-ŒBF\ã!I\Î\á×œ…eCe.§r- \Æ\Â\Ã\ÌaÀ¸\æ¢\ßq©]{C\æ2ðdU\à}+\Ðô-=\"\ÑCcV5óy®ihò\Çc—…ºQwo\ëó.iºtZnŸ* \0¸\ãÚ¤Ž\Ó\Ì&G\åqÀ=\êh•®%m¬6ó\Z\Ò*\í^€`W\ÆEº“½ÿ\0\Ìù\É_~¬\åot•‘™œ°ük{Eµ»A9?1\ëžõ®»R¼KX\åXŽrk–V–Yz’\0ÿ\0@N8õ\ì?zûŠ«Uöµ$\Ücµ\Û\ßoM\ée´T/S•!“„iQŽÿ\0•— Ž\ë\ÓßšH\Ç<r	\Ï>•—y+¯—“oš6¹À‡© Žžõ\Ðhú<ú“™„Œ!bp\åy={t®\ì\ã\Ú\'FR\ÃS£w\'Dºý\î\Çe\á\Ñy­M?\Ì\æK–dŒt#uzþ‡£¦œ†GEYHÀøE]\Óô‹--Z\Â–%˜œ–>¹©e—)ò‘ò9†:S—º\îyô}³\ïe\É\r¸\"‘ž®\Äú“4odm^\\Ž\ã>•±­\ê`)‚\"L‡¸\ì+‰\Ö[ˆ\ã‚\ß\çšV\Æ\Ä\ä\ã¾}NkŸ-\Ã\ÊS^}g(Æ¢ro<ol¬\Ò@`MnZi²:‡»\ÊG\Ûiù\Éútõ¦\èzz]²=Ë£\ÜÇ¢t__­m\\Jˆ¡Ù±ÿ\0\Þ?Ê¾‚xYSmMY®\ç­<t++\ÐwO¯ù\Ågm‹\"[\Â&ù¸Ï¡\Î3ü©#\ï*À3uÁ\äS\Þù#\Æ\rÀƒƒ•\Ï?†?^\Õ@\êj²\è;\åzŸZ‰Ji¹Ó§7wbk:	Fvü\ÍòŽ9\é\\¦¿kž£\neUŠ²ð9%y­k\Ï[[\Æ\Ó\Í:Æ„ò­Œý:×žjþ!›Q\Õ\í\î\íW	nN7óg¯\áŠôðñ…I~\í|É–eR©/—_?À\ë\ì)¡3È˜ù¾VÇ·¯ô¢io%Ý´w‹a$L\ãN~´Wwö•*^ä¤®¼\Ï]V¥[÷‘–\Ð\êô2\ËB_*-¥°r\î95{ûSÌºŽ\ÙN|\Ö\n3\ÏZÂ½¸$l™¾EV\Çø\ÖdZÔ–zœN7H±°$\àgnyük\æqÔ½«\åü\Êr¿­\âªiv\ÏX‚(\í­\Ö0AÀ\ç\Üú\Õ;‹˜\àVyh\Ï_jK[¡{c\Ìj\Þ[®@aƒ\\–£y;\\²³•›{pzv®¯/–2¯¿\î\Æ?yõxL#©&›\ØuõÙ¼÷€U\n†Ç—À\ë\×9\ç§ÿ\0«6\çR–>TÉŒ\ìù0»zŽ1Ž‡\êG\ãNKÝ¨b]\Þc‚y#\È\ë\Ï\'§lJÉº¿T„\ì§#\n\Å¹ýzþu÷S©OK’\n\Ö\Ø÷\\)\á\é:•>ÿ\0_‰0¸\"\íâŒ‡=®X\ä\ã\Ó5\éº\ÔI¶ò±½ÿ\0Zò*&hð¸\Æs\ÎrkT]\\\Ø+&1\ç\ï\0qœ\nù,}\Z˜•t\Ï\Ïq|C\íqrE£\Ñy/\ës\Ôf¿A$¨\Üq\\\Õÿ\0‰c(\Éh\Êò	Á8®r\ßMÕµ0’\ß\Ìòž¼¶1Ï Ç­iÇ¡A†“8\ê6{\ÖT²y7y~G.#=…= Šf\á¥bä–‘ŽãŸ®*å•¨‚O´LÊ“ºmf8Â®z{\çŒý*Å­²£4¸\Æ\ÒvÁúóÚ•\×÷nX1y³Œc¿=k\ïr<Ž-^¦ýo?S\ç3!©^>\Ê\É\ïþDk|ˆ»ñnŽ\ÕL]\r\Î\'tØ«Ç€x‘\à\Ñp\ÑY\Æ^iU# \ÎÀ¨\'Šó[¯\êšõøŽ\ÝR;H\Û\n¸\'qõ5\égx:\ér¥ûÇ·ü¿†sLN\Z³|ßº[\ßô:\ÝK\Ä~]´¾B¨F=þƒÞ¸©¦¾»K‹¹N\ã÷wÂµ\ã\Óüù\íLÍŽž‚¶4}/u$·Á\Ù÷‰‚¼jy<pTe^µ´W~G±˜qñõcF…\Òü\ÎoNðõÖ»v¶±1fs’\Í\Î\Ñ\ëøf½#\Ãt\Ý67ˆ/\'\Ï\r\"‚£\è;WWcaog\n¤ª*ô‰§*:W\Äc3Ê•\ï\n>\êüÿ\0®\ÇvË¬\Ù^t\0QÀ$QPM)-µ‡J+È³g¯Ì–‡ž\\\êr\êSl·$[w\ã­v~ð¬r¯\Úï˜óòD\Ün÷>\ÞÆ±</¦Á>¸¸(\×qR †À<\Zôñ€À¯[:¯<5_«\Ç~\æ~.+«®Xµ¯puU‡j¨\n£\0\0qZ\Â4sM \n>S´\äò}1ùó\ï]…Ó•Œâ¸½BCq.\×\Î3\Ó5Å—b\êQŸ4>g­€n-³˜6ó;‡–VnüŽO\\dõ¬­X:l\np{WW,(½`jq«\Ü #µ{4±3©;ÉU*¼]e?‡·AºN¤\È\Ñ[¥£¼\Î\ÛB«cy=³Ú½Mð\Äb–ø#\Ê\Ê\Óó*øçŸ­s¾²u­\Å1FÎ¹õ$\nî¤¸`7	½8\Íz1©\ZQ»W?5\â8P\Ãb=(Û«ùˆ\"\åˆ\Ê/(\åõ5Ns’\"L‚üeO#ž•l³l¹ºtÏ­QK\ÞN\Î\ì\Ø\0ž™?žk\×\Ë)*\Õo.‡\Æb$\í\æ\ÆL’J\Û#S‘òŸþ½\'\Ø%\Ã•L‡\Ø\ç<\Õ\Ý0\îds\ËgÞ­Hr\áºVùžuWUÒŠI/+\ÜÊ†š*£z³\Ï|i\ákv\Ööº|0¼·J†`­ž\Ç\æ\ÇBJË´ð…Æn¡\ì\äŽA\É8\È\'\ê8¯Z·\ÅÌ€0\ÇA\Ç\ãK _3rF	\ÏsO	šTUi\ÅKð=x9\Ë©A\Ù/\Ç\ÔóeµY[qZ\Ððô¶©­K	eùY\Û\ß®\ÂóK²‚5º©)¿r|§5\Ì^x6-\'Q:¥®¡r&\ÞF0{WNw˜C‚t£_s£*\ÂJ8\Ä\å-\ÇTf@¼œU»«{xÌ²ÈŠ£«1\Æ*¹ð\Ã<Vz[¦§\"›Ÿ™T\à\'ðþUù5*1R|\Ý¼…ùoÿ\0Q\Ôu‹‚ºrK\ä\'FU\ëþsEwöšeµ¼ $j;p1E{\éi\Ëùª.\Çÿ\Ù',1,1,1,0,'','',1,0,0,'',0,1,0,0),(4,'Paquete1',79.99,1,39.995,0,'0000-00-00',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0v\0\0\0h\0\0\0${ú\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0\0\0\0šœ\0\0 \0IDATxœÔ½Œ\×u\çùa\ë6}J®–o\Ù\ÝÙª1™°¼¤W+eôˆ\Èk6VÔ†l¸µr`™Œ\Åu‚¸“\Å\ÆTL¤\Éfbn xhc\áˆ\Æ7@&˜ñRÁ\ÄC\nÁ-ÀFZ3«l·g\è\é§\rµ|\Ü%‘\"–­ñ%uW]a7¯\ÚûÇ­÷ºIÑŠø\ïuuý¸÷ž{\Îùž_·vðc\ÖD\ä\'Pý)b˜\Äc\0ü`tN¤tx»\ÜEÞ›\Äò^œF\ï‘w;¢XŒµÑ¤V\×+§;Dd‡¢\n\ÜÀˆ\"¢®vÿoUk“X{Ÿ™\Ò\Ú\í\ÔZ\ßeE\Þ%\"\ï\Âë»’½ùd¶;škˆ¢\ä­òü\êu­õ‚\çûˆ|_½®—µ^‹ö\æ\×\Êaõ†\ÓQõú7\ÎóW€b¸øž	{E$C„\×	<¹\'2L\0÷\0÷\àõ±©\Éö\ä\ï®ÖŠŸ(ƒ‹;þ§\Ì¶£\Îý\Ûò•¥O\æ\"ˆ‡\È$P¥R%\Ä\ê·\ßAÁ\"B2`wY$\ÜU‡\Ö\n\"\04ª\àTA\Ú+#a3‹6P\r\ÑhIiCS;hû µ’\í\ÉÁ3~v\ã\Ðö>ºA\Ä	*\×üMY»¿+š\Ø,V«	1Ñ½Ù´¢%¬ aœQøVb@Ua]‘)a©tÿ\æÇŽ°iú1\ìK&]bAlB\ÔV=TWJ\Ä@d“0ù\íy\ÐN\èb…$\Ë+¨*Mþ¡ª+XWˆ$\Ð\Û‘XA•ðÿvb¡ýK\Ü@Tm–B®ª0£þH»ð¼\"úP©°3‰“vµm¿¡=6j^Ç‹hù\\\ïÿø±#\ì\Ói:d0x_gW\Úr QË©6$\Ó	’Ø–ƒ#\Ð-Î‹\âˆF›0Ñª¨s\0dÙ•n=H•òR	µƒØŽŽ	w\ÓbV¸²\å\ØÐ¡­\É÷\ã+±V€p\r\ÚYI\"`\"\Zø†(N(]EY\Ââ‰¥•NJ$vÌ¥\"‚DA\Þk\å#”\"?~¢x\á\Î–ÿx0\ÉH¯4\n‘	!±aÂœB\å‰	ò/Ì¥ \Ûo:š8‰h\ïˆjC£\Z&\Ì+cŒ´z$‚¡¾¯Tœ\×ñ=!ô§%5\ÑHÌ·\Ü\ì\ÚÇ‹¬l:¯­di\0X ªm]K- OS:\æœ,ÿ³\áÇ¬]ðü§…‡;ÿ8)•þ÷z4\èHu\á\Ú\É”\Ò)e;s#q\Ø@\ËI\á\n…ñ±¨V¬*b\Úc€\ë°ÀZBC\ÚJ¥¡7­X62\Ï\ÖoK*U\r\ç¶÷*\ÛE¡FÇ˜@½b\r‚¢D>ôK\Ù\"¦%,–tOF\Þ\É\Éö¤ô^\éÑ¿\\lü\Ø¶”¯\\˜{¬‹x(_ï‡‰\0¥bô;4k\'‹‘ñÊ†±ÀD<T^)Q*¯ˆ\ßJ`K¿Z+n‹\Z0AŽt«ÁJP#`5~ž‡¦%¼ú e@@\Õñ3AÛ¾	‘\È™±±Q¸7Aò\ØNN¶+C\ëŠþwzœy½ðW?v„u^ÿ²¥|+ÿžÜ“\ì 3-¢u*V¡T·MtIXõ~›ek\Â1!D-(Òž›H¸ö¦fÂ„Ã–¨À\ZÁlC\è˜À\Å\ÐJ€“5£«\Âs#ˆw^q^C¿\Åbm«¤U‰´\00‹¬\ÅÚ„òrAÑ»À\àJQ%ü»;p(MÿýÁ\à#\Ý\Ç’\ì\É \Z:\Ð& \ÑkuJ9lQ+l™\Û5#c«Z+-gnq\Ñ\è\Üð™Àm#}—˜ Ÿñ\ÍMç¿\ÄD[\È6j\ïz\ãf\Ó%py4`\Ú\ïV\"¨o\ïGA_¡ºRPô\n\Ô)JXv\ß1Çžž¿¡\nÆ¡¦¦S \á%•\í©Pª…\ÌC³i \Í!ˆG&C	\Þ!\nŠ\ÓðhŸ¢‹\ç É’÷WƒÅ«}\\¿ }p?\Ù\Þ\ç2luW…¢%n&#óñ&\"m×‹±\Ý\Ù\ê¸@(\Æ@h\ì\ni‘hGtdË„jF„mÍ—pl­–°ˆ´\"9p\"c½¼µ8´V´Vš\ZT+ô\Æx} ¢T¨%½Wz@0\ÇT!™¶KÝ£gî˜°»|ô€Ý›‡\Î].ÀGô§+þ\ïi%GÈœbG&B\0’\È\ÙeQ:%80\Zf\ÞqN\å4‚·DjÉ¦%P\\ª\È\ÛAVk›V\è..˜;£&3‚•­+\n™Ü·\\fZÛ´\å<&\Ûikõc„@‹’oj·€£ñ³b	œˆ\Ý:xqo!4aAÀQ@\ì­9¥#¢6\èºnÙ¿\nZ7Á$\ê*º¾\Ãò:’\í<(Ù‡î˜°vW;XŸ\ÐKa9Vú±ÀTB\×À\ßÇº°\Ê*c\ÑÚ¡®Eš\Ô$\í [!)2™Ñ \Ð8 Á¦9s9Š\ß\r\0$L(\èÀ\ÑTº\æPmÀFÁ»4Bœ4<¯³À¼´º\ÏHˆ“²E4‰¶ˆ&[\Ç\ÅgB°õfo\Ö@m?·hõ-±ü6‚Ž®0ÚŠý\Ð\r^´\n*E]³µ\à	¨˜uE’	µu”\ä>g\à\Ýúƒ\'\nqrRX2ûq±\Å\Æ	ƒúe\"¯t×Š°&%plt\rt]ÀC\ãGXµ	4ÀTÒ®\â(`R!\Îa2#Ÿ‚\Üô8û3\ß\í“\\7P·“Xƒ\Ö\Úr£ª’·œxè›ˆC(™¶6/g¶q¨¹…¨-\'\Ý\n¾¶ú=j~K\à\í\"\Ú&\ÒGnÀ° ¶8Yi9uX¢\ÖA¬\É\Ò^«\á·j³!B)U)€§\ãÝƒ\ê!Å\ÔN\Æ]N\'+\Ó)\Ä9–(xd¦„šc½`¯ž\"QG#Ž(¼Ð¬A´ £iEt°\Ïl;]AhºÖ&¨)`½ \Ëì¡Œ3\ß\í“\ÔJ3òBù\0.DÁ©¶žœ`+\ÎXFYTe\Õ&\Ìú†Ž@.\ÊþZ8¸ƒD‹aG¤\Ü\ÞF¢ô\í\è™\í\\=ºGû?n–\0uES;t]\ÇzZ\â(ø“G\Ü\ê\Ó µ\\½õœÈ¦S\ìUE×Š;\'\ìS>zi,$N 1\rV\n\ß!ºQ‘]\é\Ñ.…N\ÄÑ„\æRA“GZ”ˆ‚\î\"_ƒVwX0yÙ¬¶¶jFúPCU\íH}–ðh\â|@”v\äNôŠóz¥k`¥v0p\Ök9J\×Ã¼òX\Ðm&F\0@@®m(hû;²:o!¤¿ul»Îƒº†¦® iõ\'M¯DÝ¢\Û#\àc÷©¨cl\ÏV-r\ï\Øý\È\ågô\Î	K\Öi;l\ß\ÚhqðÚ¸\ZŠ$§ˆsr\rÿk4\ß!ÒŠ\âR‰\ÄH-\ÄM\ëÙ‘`L¶p#A¢\í€\Æ\r\Zü\Õ.+¿³2ö™Âˆo¢0l€Tqg=¬\0É°\âD7\á\ØÚ€‚°â—½rX…9<P:ò8µ÷\ZVZóH¤\ÕÕ´‹PZvs\Ó·\ç©uÑšFqt ‹¶-ž\ÑÀš\ÉñB°\Ð(¸6p1?\ÝAS3ù¶#B?¿­¨³8Hª\é\Å\'ž\Æ\î\ÊÑ¼ƒ‹3D\â–I\ê.÷U*\Û_“\'Qky\0Ë¤ \ä(}¢O\ß	H1‰ƒXknÑÒš3\Ö\Î+ ú\Î\ÑÙ“ó—gŸ\æ\ØOs\âµ\à$\Ê2\Êa/!fZ²µ“…†-\ì½Õš\í³i¶]7j­‡lD@¡\î\Ü,ºG÷\Ð1’ŽZ\"7mDC$B‡\ÎZðF­ˆS\î\ØAñ\Ü\ï¯þ\àX\ÜmA†’\ÔB‰’OCwJ\È\×[w·\à¬`\ÛÈ³\Z°dZ]\"\á4K¤¦\ÕZ4J‘\0Ú”0i“£fœ\éØ¡üƒEö\ß\ßÙš¤‘ó|XQm(U¯ôœô\ÊA+,\Ë`;¾~Œ\ç¾r‚k[c›7\Â!#\ä€•n#\ç-\ZFNZ	q›¹sû\ã\ãû\É\Ö\'jLÁ±!\ã¡´„mÇºr©¢(öv™\×ýˆ\ÖE\Ö\ïyg²ý\í\í\ß>2ýì¹³”÷z\ïh\â˜|ºf\ßL\Ì\Ì}%†\èý1\ç\ïŠ{\rf´†µ\r\èOÀù.e1:ó U4Ë”¢¿~/A4o\Z¸\'Áo^\Ã\ßSSKM=±†\"ø#ü\ßÿÆ·;\Å\äÎ–&‚lœ4~K2nzvLx†›žø_7=—\Õóñ«\ìþø\ÏÿW\ác¿þóü\â{Ö©ÿ\Ó%z\×=—6=\ßö\Ê\ïÙg\Æ \Â0‰2y\Ówh\í·3ñöOû¯\Û~F„\Z}OnÀ0›cL€÷\à\'<\ÑN¡\Þôô\×?m-¿ÿ\0S÷\îføfÉû&7î˜°\Çñ\ÏF×§8—vù˜\É~\n~z\nœ\Öîƒ«\å\è\ìPð›Áˆ¹´©¼{®m\Ö¯Tù\Ý8Àµ7¯\â7/1c<ñu\Å\àqŠnz\Ì=6\Ýôø‰w\Ç:¡þ‹KL¥	l²m\rL&\'<xÇ ›0µ\éa\Âp~\ÓS\\¾\Ê/Îƒ{\îúú%²_û8Ÿü\ï÷ñ³\ïö\\\ë×œ¯•Þ¦\çÜ†’l\Z>8“[ŠÔ˜–\0\Û?w\Ú<Ln3<`&\rxð›\Ê\ä\ÈN\Ã\Ú_yª7<»rŠ\ÙÉ`6Á\Ôß‡\ëþ\Î	û\ìcS\Ï\æ\ÕU®¾ÿf\n~râ‰¼!Cé‹§¿\Ó#†©\Zt\'\Ô÷Â¤÷…É‰˜\áua¸	—b(#\á-\Ý\Ïúÿ‘™z\0x#8\Þ²£ƒ~\ÝQ³¾y‰º²#ßy©djzj\Ü/™\0³S0;\rÆ€\ê\Ï[›†\Ê+»\ÅMOq\Ýó‹\Ù$;\ÞlxðŸÿ)ƒ\ß[dßŽˆÎ§3~þ\Ð·†\é9_+K^)¼\'\ÅÕ°\é1LM^1\\DøûGùøm\ç{³õ›\Íö³ð›¿\ái~¸\Ù\Ã\Õ7\ÖI&É½3\ìK>‚\Ö@?xÿô] ì‘=kvõ\Æ~þõ{g¨#\ÜkHv_7p¯Á\ÕýkOf2\î:\Ô¿i¨6A\Û\ØM˜\Ù	\æž®ü\ï}û˜C½º©\á\ã\êM&r\"\ÉøÀ\Æn\ä\Ê\Z^‹.\Ù	~Â o*lNbŒ\Çy\È6\rõ\\\Úô\ÔeÃ“ÿ0\âü®\ã\ÕZù¯\\\â\Ü\\\"r\Ê\Çþa\Ì\Â\Ç3>òSœûËšs×•?\ÝP&ñP{%Þ„)3\ÉnŠx30¹\Ó\ßv\í\æ¶\ï\r\Æ6ù$¿\Ç0¼¾ƒ\É7=yüA²ü`ˆN~°\É] \ì\ã{–\éŸ\çøý\éYy¤®‰òjl¨f®†Z\àò\È&d„Nº7õ†\ÔÀ>U’\rÏ¤7/]\åÜ¿?\Ç_‡D\ïò\éc3ô\ÝÄ¼\ë\Ô~¿iñ›	jJÌ &Z½†\Ø$\è³	`\'˜w¾öè°‚‰ \'7¡òž\Ìx¾\í=½a\Ío\Î$\Ô\Ê\Ê_`r\É{þ\äuÇ¿øÖ€\áÿYó³\ïŸ\â\èf|H\"VþZYº®,o(õ\\ñÊ”÷dþ\ï\"Š”s\Ûsšš1¡\'&\rC·N\é`\Î€µ\î›\"\Îsn¼{ò\Î\í:\â“\îÚ€‚”Á4*\àBF@5vŸ#›³(/1 ^IB\0‡ Rj}0\çÀcObÞ\ÚfUª\">\Ç\ÕT\Íp\0ÀAn±­=9²‡Žˆh[-¢òJ†0\'°¤Ê©óóqÂ‰q\ÂJh8q\Ñq\â¢c\Î\nOßŸñge¬ž¾\âXlÝŒ\ßòp\ØW!‘\è&ôû¶¨Ò¨\Ý\êŠü¡“¾\"\r\\[\Ô\rÍ°Á\ÕJw\×,\"$\Þ+-\nÞš\î<}<{–{§`_‡)q\ÃœA7 ÷†ø0ü\èuX\ß0|ŠZ©Á{ƒªarüº\á\Úu¸o³oj\È/~vžÙ\Îò\Ö{=jÖ¸6\á‚X\Þt\Ô&wFÈ»„µ²þ·:\Älp#IŒÔ…C\ßX\Ç\îœ\ÄN]2&´\Þðd¾\í•\Õ\r\Ï{\ß§\ßT¼¿Õ ­P\ÏkŽýÿ8>xo\Ì\'­Ox®ªgˆ\çÜ¦r~\Ã3¹\é±À\æ$“\Û\Ð\ï\í\Ð2\ïüñÀfXC\ßPª§\Þ \ÔLx~’òÿ\ìAx·`\Þt˜÷\Æ\è\Ì\Ô]\ÅµÏ²\é\Ì|€î„’üµ\ã\Û:C2a\r0\×®\×ø7\×\ê\Z¢\ïÁx\Þ\à\ê\ïƒ\Þõ$\Ôoô\ÉEù\äc3Ì¤—(6VÑ5n\Ô{Ø©x\Z¼÷\è\æ$\Þ\Ã\ä\äSÿ¡\ä\ê\ëk”Z\ã\\Mmvpþ\Ý1\çÿ²d\Õ\r\èo‘Yl\ÂU<;€x\Ó0³\éÁÀ\Êu\Å\î&7gFÜ¶¨=,¹š?}³f\Æ\ì„\Çû\àc\à\Ç +š\Äoz¦&&ƒ(ý;¡fÁlú\à¿ðp\Õ{j¯Ô›õž\Òû\Ín\ÌL›¡\ß7\Þ7uD±\r¾K{­V™ÛµŸ#…¥s\å\Øs¡¨6d»s²6ª\Ö\â´\Í\Ô\Ðõ(±™2·+A\Ê5\Ð8ü•†\\…¤=‚\ÇI|H\è\ÒóA„: \ï•Õ‹™XJUœ«\ÛZt\æD8Œ\ÐCYrŽ\äo›‘\í\â\ÓÃ’S¬2¯!ù\r°}Uúªˆ…®2ù\Ø\Ýy³‹\ãí¡…[µ\î\Äö:õ!…\Õ\ÅÒƒ.õ\ÐaEº\'‡Ay\ç.E-\ÔôP)‘=püœc½%N[&‘i¼¸’@™“\ì\Î)\Ó<\\_W\àK$v\Ì>˜\ÑÝ›\"&„\àDº$¢”u±\ÍE\Õ6·p\ÕÑ¬Uµ©\n\äµrø\Ë\ÇÁ9¸\ÑÀdR9\Ë–œþ\æY–U9l o}½¥W\æDXz\'®½¥ÍŠ ^(\Ôaiã¢±Ð¯•\åZ©$`‰‚ErÐ„\ïQ>\ÔVT\ënô[¥±¯\Ú7!zôPCˆ\Åz¥ˆ!‹-:¬PWœ(w\Ø\Ä9 S€\É(Š—9þ\é’:^ø£Ó”*ˆ\Í\0E®\n\Ù\îŒ$Nq1\Èt„\ìK9\Ð\É9´+UJ(\ZUª:pZd\ÂBÀ‡¿£¨¯hp°\0Yœ±\êJ¾U;œ‡/ü\Ú\Ñ\Ú÷\'¿\×\ãK¿²À™\×z8 ÷!Ê“x%…q¶\ã\ÛHÜª\à(\ê×Ž\çþð4\ÇÓ”\ç~ý)\Î^\ì3û\éžytŽS_>\Î\Ò\ë}2”*÷oy\Ø\ïTŒ\\‰–¹X˜“§Ê’6,»Á-0Ž\à÷°\ÈEH­%1Q­\È\îœ4I\à\Ú\Ôß…°¸¦-\Z—ˆé€À­\"&\áø\'qd*\ç\ä\×NQ®Ud6\"w\nW\é?“sð‰\'‰™%œ\ÊÁJ‰\È,b²0t…\Æh\ë7EA}\à\ÐFKp]\É`:§¢Bð©CG>m)®!\'\n@„\îý\æ~¦Ës\Ë~ð\0KûT²=9\Ò\í0W–\èå‚¢VúµC+|H~`vOF(´¢h\ç¡Ü!ksÝƒúô“\äÝƒyl[+½Ú‘·Ñ¥Aš’JÄ n(†VVb¥TÇ²‡\ì\ÃÉ²¬M€þ\îþ+K\àCMR\ÈLDb©\Â\"G€™h{>À´\nt‰÷«m8ÊYAj\è<v„\çvuYü\ê	ôõe,\Î\áSù/\ÌS=\ÔA\\ˆ\n\rŒ¢±¥1JcJÐ’„$ˆX:8*\Z3\'›)Ž¬`{G†´q\×r\ì$o\Æq\Ñ_;É©\ß=AN üÜ§Ÿ\ä¹u\nk„§¿ö<\ÅüG©¼\Âóÿ\ês@‡UÎ±ô\âNý\Æ3ô\Ûûvba\ák\Ïsø3X+¯õxúW²ð\Ù\æ>|ý{;ý\Õ\0º÷\ç\\¸ZòË¿p„\â/ {r\Î|\å9ºÍ‘ˆP\ÕJ\ï•%Žÿ\Æ3œ¾R`…öžûòñ›fyñ\åE¿¼|@›\ÕQ¡Tkýž\Z®¼€\ì\Îî‚ŽõQ›{[\ï\0E—qŽ\ê\"R(Ò™\çÐ¯/Pü¡e\Ñ/S|>\'yl1H´¡ªW(\âŠ\È\ç¤&c\à\\›ÁWW!•\Ä&t\ÈÑµ„\Â,ƒw$\Å*öUGö\ZÐ¦ŠVmn®\ÂMa°‘\r\Ü\',\ìSüišqü«\Ï1÷\Ø\"B\'\Í8þ\å\ãc¸’\ÆB\Z§t~\í(ùžšû(\0G¾ú<¿´0¾wQ–<õ¹§xò3Or\ê/Ð¿xf\ëÁ-\Ø*\×,½ºLg[!ÿ¹Ct›ã£»3ll\ÇD\Õ:\ät)pò\ë\'Q tÄ¶©4!\È~`—E†%\\\î#q‰ÞŸ\ß—õz2\ê¬u@ˆ\É“#T`¾…+Ž,‘ÿ\Ö<~\ç)\Ü\Ã	=¨/ ~€\Úô\Ì\Ëv™‚\ë\ÄRG\á[P(†}.øU*-ˆ.] {Ù‘¿¾µl\Ñó(©e‹°[8stt\åÅ³\ãsKky\æ«\ÏcE8û\âYd–/}\ìq~ù\É#œcþ\Ñ9\æ>uˆ\n8ò™#\0|\éŸ‰#\Ïr\ê¿{j\ÐË¦-‹/-r\â\ë\'\è½\Þ\ãý,¾²\Äó_{žÎ®”¥\ï®ðøü\ãœøüaŽú(+¾Bn-‡þ\É\Óhšûy\â÷Nò}`¡³}e	10/vœÀWù† YŠ\Ç=0Á]Ð±‘\0	h‚r\Ä\æmrY5\âKF©\Õ]3\ÇÓ®`¹¾ÀÀô¨¬€$dt(\âü€HR,Q‹\n#¬¤D.b•UJYdvE‘—H¢:¤Š6\Ü.ü=ŠÉ¾\Ó <tö\ä\Ìœ\à\Øo<CÿrÁ2Á|\êœ\å\è¯…]\Î.X^Yfñ{+Aßµ·J\ÚR\È~?$h­û¤Àü\'\æ8ùµS,¾¼È‘\à\èKgp¿ÿ<¿üKG°Ÿ] RÅ©bE8úK4\ë+_?I¡\Z\Òg·Q¬:C©+¤!rÆ°¼A¦4¿\Üf+€ºAMJ¬˜—\nº\ÖCÎ¢Ó¿À‘j?i]\â\\ŸjXÁ0c •w„¼ö\Ðz\0Ã‚¼(™}© óÕ‚\Ù!\01”vtnK\Ä\í\ä›·\éysK\Öþ¨n¶¬R£Ò¤\Õ\Ó!Mt\ëN™\r9\Ä\åö£ml<\Êr\éymVW¸_\Ýpt¯\å\ÉO#N9ö\Í%\ÒO=\É\Ü#s\è\Å>‡3P\ÅN[Žñ8§¯Ut\î•\'¸0·™b\r`*…\r…i‘“»@XŸ}Tû\à,a\í:´.À\0p\nhÈ’ÀŸ·ˆ\\,™[\Ï\éÔ–\ÂõX5K83hAAEU;J-¨üœ[¦ºtš\ì¥ò\ßW¸-†€m›Ÿ\äoIE\Ù\ÖÆ™ýl¥tx\ìñv·œ«!½n®%Ns×¿÷o·hF­\Ùö\Üoõ,ý\Þ}`Àó\çŸÁ}\ç[\ì\ïayz?Ç¿rœ$2 xy‘…\Î~N|ý$\Î9R\Ï}\í$L[z#\Ñ\Þ7ñÐ«—	\è¡]|z»ò\ê*øˆI\Û	*C:‡fˆŸG\í,BŽGq‡b\×a\Ó.\æ\É\å³\Óó$\ÞÂ A† R;uÐ£9wz‹\ØAA\Ò¢\'€\'@\î“z0²­w([œ±}\Êu\Û*O€\'Ÿ˜\ç\Ø×ž`\é•%ú¯õ\Æ\ïóg)€Žœ\ì\Ù\Ðz\Ó\"¸Iðßª\ÔZž¥)\ÙtJ,~\î¹;N÷³–¥\'Ÿ\'û\Üô# ¬Z\ïšªµ‚g>ÿÇ¾€Tb-\î\ï\ÐÀ–ýK`£þ´\"¢A(\àî‚Ž]\í+›|\ÒÂJ\Ý	wP\çB\Ì\Æ\æ\ÐzfŽ{”\ÕKaBøR 7u\n5\Öw‚kP’¯¬’]\Z`\r$]ÀB¦1Žª€l“§‡\é_zn«¢\í¦\É\Óÿô\çŸf\î\ÑùQÚqð¡.£yø\ÒoCk\å\Ì7Ï°ð+œþ“3œü\Æ)\Ê\Ï?Å‘û»úÔ¡0ñ¯.3?½U\Âm›½Q¢\Ù(ut\ä\Ë÷\æ\Ìz\ä\Õ|\ás	XË—9\Ë)\Íyþ\ÛF¦\Ê\\«{—þ\èJ\à\è¿:\Å\ì£s0¬\Æú¼\Z:VC‰d(\ânŸwx*Œ\àŒ\"14\Õ]pPô\àl¤$A\\õ ˆa\ßÀô~\Ô4€ fžU;Ç™H(\r¸8¬¾\ÂCž\å\ä\î\åð4jú\ä—z‹dNÉ¦\Ý#/€\ÉP\Ét\Í¸Ö¼im»qÒ¨lW>ž\à|\Äym\ë]\ìs\ìsO±ô\Ý\0¾ôù§\Èö\ä\Ì?6\ÇÓ¿z”¥aIÿ\Ë\'X|­\Ï\ÒKg).ö™} K_•Ž\ÈXDG@Õ¦€–\ë•?>\Ë\Ùù#\È\Êþ,_\ïÀyø\å\ß]\áT\Ú\áÕ…›úr\ì\ë\'Yü\Æ)Ž<6\Ï\ÑO?¦Á,R\à\äWŽ\ãœ#7[@\r‚ô)4RÄµ\Å\Ñõ]pPtž°Ø‡3\\\î *‘aœ W‰3tÇ€\Òf9›gÉ¶™ð&øK€J\Êó\ä…\â.!\é+i\r\ì\È‹\rE]ˆK\Z…”ƒ0\ì0*\ã\0\Ú*ðˆˆ8õ;\'\Èwe¡ž§%C\ãVVV8ýÇ§QU\æ	\ZªPe\áce\áWr\à±9ú&¢k…SO<\ÎòZA¬^)xª{\0¡\\+`oŸü\ícœüý\ç\Ñ\á€>‚»Ü§û™9Ž}\nl\'A_TŽ¼Tp\ÖÃ¡N\ÆÒ‹g\ÇùÀg^:\Ã\â7\Ï\Ò*^øƒSTÎ«¿\ÅòŸ‡\Å7\ç·Š‰\Æ\àOc¶²Ûª;N?mzs?º¡0‘ \×Àº$9¬w \êQ\Ä\r‹\Ó\ÇX\î\ÎsVBgr¸p&\ì¿\ÐQ˜uP½|„\ì\êtca0\Õ4t|—L¡Œ{€’\Ô9w9|I§.=Ot¹\0\à‚8ÙŠ«±ñ6m˜‹-«\êxà¨§§Ì¦<¿\ÄÁ\á+Áw»=h.l9ò·\ë\Þ8ñDÎ“	\\ú/;¯¤Oðõ‰¿b	õG?¤-\ì\Í9dTˆD”4T9ô°Ð™v¸B\Ñ!4\È](Ê¢À\ÅeðUÖ 6Eqh<@]…½& )j2Š¸¢tb¥_[¬Qr\Òoy…t\ZºŸ8¯(\ê\Îb± p\ÓB4,‰\Úzœ\ÜDÖ»P÷C!¯÷±\Ó	bsž\ÑP:‰µ\ãJ4!8*\Ñ1Á<(|\Ã~,O{¥\ç•U ”n@¿N9º/\Â]	£Xq{\âÌ‰púŸ\æ¤ZxE9ûRÉ‘µA«*\à B\ÞJ)\ã_\å•\Þ\È\Ék¶\ÕÑ«\Òy¨\Ë\\’p\à¡.z¥ Y[m…%¥Q\Ñö\ï.”x\Î‘\ï`\Üd‚³hùƒ}=¤”•õŠ+ \ÏlOÕ¶L÷&†\å\Ú\ÑX\Ë\á\î)\Üù\Ö!É¼††’H!Q°W#X@±ø@—¿¶\0\0 \0IDAT²vk<f½EFõ<Û¢1@\ë¥\n\"1›•«\r™W\æT9ã•³À\É5\ÇÓ$<½\×r\âò\Ö&]7µöþ\ÏÿL\Ê\Ñ/\î\Ø\âŽ/}§\ä\ØHbx\ÒXž!\ÝVw;\Î\îg\äÿ¾\Å|Ò†$Nhv¥¸\Ë‘$\áZh\År´.4A\r\Ý9\Ç\Z‚\È\ÕxGc\Ú\âý¦±PH¥\Z\n²VR‘\ãpD²GpF(];\rÓ¯\ÊÔ¢\Õó¤\Ãöûep <°\Þ—Â´›Pt¦\Óq½,&Ô´ŒvYOþ8¦{3¯ð‘ˆR{eI…*…Wžy4„\Ý\ÞZ‚vSÿ¤K÷·g\á\Õ>|eÀ‘ï–¼0.‘„c9*\Ê2n\ã\Þ\Æ l§ŠŠP^,\Ð\×Z°%´.Eiw{‹$Ck‡ø¸‘\Ý;Ö™n˜ðx	DFƒh0„ø¬t©,D±#¿öz\å4ýa ¸mAUð\Ze\Ú\Ö\Ø¥\'Ê…|—ž\n~PÓ£j\×r6uü`³\Êü\ë:•„‰žº%Ž:\â\ØwXÂ£Éµ€mkdS²+\0/5¤\n‡\Ò\Ö\Ô\Ù&ŽÆ°ú\'t¿º\0\ß\é3ø­\ÌþyKT]¾ –…XBY$@]…× S[\à§uu\Ó\æ^£\ßø&\\k“v³F\ÚB.Qf¡™—M»»\áR\Ì\Õ\Ú\n¦,‘?@4Ù¡añ’\Z¬+\È\Í)\æ\ËS\\ƒ2‚¾ƒ¢¢1ó„{\à¨–\r,\í‚\Õ\Ýóö(SB\ÕûA\Ò*+!<\ès+=\äF\ë\å¹ö‡oCð#Ê¤q\Ã\ÖAALh\Ò\Òe»žyd\ËÐ°À™ÿ\Úò|\ïüÜ“ð\ÇgYù\íef_w¬´ \é¨XŽ‰\åqI\Ú#8m`o÷\ï…\Í\Ó©Å¹\nö\æ\Èýy°hõ¹µ°7G%lj€!T\ç%€€#D“Ð£\É$0ö.ˆ\âÑ¾H\ãŽ†&döø2¼\àR\è\Ë\ãv8\Î\nmh\Ë	‰@\'†e«h\rVƒ\ZxX¨¦“—I´G^\Î\Âe\Ðûcaè ¼@>,‚;\Ì\rAZ\Ñ=\æ\Üa´#±\ì|»I°4Tp–ƒŸII¿\Ù\'ÿ\é\éW\Î\0ü\Ña^ør…ËŒA\Ò\Är¸-\æ\Z\ÞA‰|b÷™\Ã\à¡ùƒ\Ód¿t„\âü*\É\ë}ôWXüúsäŸš£³¯^)«’\ä\à,Í«\ËT¿{’\ìþ°\Õ1h ¢\í¶9jJ\Þòz8Ö¸°%—\à§ôø%ªõ%\"z\ÞRœ±`g\à€,1×¬z\Úì¯¶Ï·¹	¤Á÷F”þnKÿ¡STU—ôr»L»»Ì¥\n’„\èZ±•G,Q@\Û<4?J›1&\Z\Ço­	ù\ÎK¯:xdŽ¥G…\Õ?ù\éWþ¨\à\ë\å\Äo÷8²¨\Ç\ÅrD’@T³uoõŽÎ§S®\\xe‰\äWŽ ŸšGwç¤¿´@ùú*Y¯ û\Ùx\ä\0noŽó ƒ\n	\Û7ˆ•1·V¦Í—ºQ…T¡\é‰s¨\í\çÿ\æSöY¿Qa6<\\W\Ì\ß(;Ô¡\ÎSüË•ÿ\rxŸ’tÁ\ïN\Ñûf\Ø=‘\rk\Ö6sŠ÷\Ï\à&”jÓ°o&g­­õ‰\Äqm\Ã\ÓG¸4“‘wó¡?\ëÁûf06Â¼\á1;\Ð<gP÷©\×\nf\Ò¢÷L†\Ü\à\0½Uˆ\í2þayÃ£¶c3¤{N\â\éùP¡·{X2÷\ÙfŽþ&ü—?õ\nûOX\ãKoŒüObù¤$!g\"¨O\0Fþ\Í!k÷\nõ×ˆêš¢v^\\$®\Ã7J’ŸÚ\Ö5ƒsÿ‘sÿ\ËiÖ¯\\\âÿù)7=WÿÍ¿\ä§\ßk0\ï‹\à\Þ ¦\Ë7=SÆ°\ïýs\ãÑ\Z½\æ;\ïFú©N-\Åao€…\æ\n}\è_r\ät‚\î™Ç™|W_ \Õ>s6\ìé»ª\n1d*!\É2nS-k²¼kp{\ç\ì\î‘E\ë\È@\\®\åŠZAo)õ\ßf{\Â;d\æoûŸôh\×@\ß\ÃÊšB¯„O\Ì\Ã`‘Á\ç³ð¢²\Ø^g[N“\ä¶Nu|xŽfWFõ\ê2\Ñ\Ú\0ç—‰$B÷\åTMCñ\ê2Y\'§\êõ\é\ì\Îp\×*Š\Åo\Ñ\ì\Ë\Ã|Ì´{R\Äa<\É$”^`:ƒºB´·&\ïB%À±_ÈŸõz»®\è\Ð?\ï9¿\ný\â÷ÀO„\ä\'s\Ô~Jp—h6w_\Í\ÔõL\ì#‰±W	Á2C´i¨7”\È\Ç$„\Ìý™\r…w¼Ì°m€QCm<õfM\\{†z\r÷f\É\Ô\ÎIÄ˜°÷ö& £¿©m\Ý,mI\å\í›\'dÙ«÷x<Ñ„\á\ÛJ	üòÿ\ÔŸøYŽü;\ÏJ{M\Úr\êGdko\ä·-œ\ë5ò\åcœ}•\äû\ß\ç\á/\çÀ?‹}d–Ý‡\Óû\Þ9>ò\ß<Nò\Ñ9Ü d\î‹\Çù‹µ5>ø¡<ø~‘ÞŸ/‘q;=…o“Ö‡oz¦d7:&<¾®ñu½q\Ç:Vý2\é%ßƒ3¯Â™\×a\ÙÔ›¤`÷\0q‡¶^ALIRGdk\éð\àH<$\ZQ´g\0#4(©y˜\Ýw\ê–\îï ½‚b\Ó4€&\ïP¶™†\r9n\×þ95\ÚÞ \"¸=ó6¿huq‘¥\Ï\áñ\×F\ÑÏ\ÑpB,³-Q\Çf\Öö\æ8!\ëvIj\È÷v(¼²|¥Ó†hW\Z‚»rÊ¡£*\nÊ¢$Û—\ÓXKq­Dp¤©Œ}\ìxhZ÷·\Ûå£Åš»\ày*”~× †¨8²:‘d!\ÊÛi!%d(Å‘\è\"NŸ¤¦¸4 Q«J\ÔFO\n¢?˜0¨\Ò\Ã\âƒf\ïÏ‘k%r\rn\ÞÁ·\ÇF\ÆQž·;)\ÞI·\ã2‘*a\ÎÀ)\Ç.\Îµ®Ž‰¥\Ón:òC\ïØº3—\ëe,Tû\èKgpµR\ì\Í)^]![¯\è\ãT‰:z/¾@ue™N\Ð\éœD4Ø±¾]·µ†L‚\Ýo¥W-\Üs7Æ«—…\ã\Ò>3±`s{a®k‘\é¨\ï´\ë\â =\ÊiÀCJEÕ†¢F{!\ÚX(%\0„¤VB\ëy–\É)\Îw\è¾t$A\ëu\Ò.«¿µl™/\ïLÆ··¨]\0¥\Ûn™\×s[¤\ÃF˜7¨ú£Ì¢\ä\ÅEr\Ú]UG{W½VP}¯G÷\×\àJ‰Z‹}`w¹ý\Ì¢º¢Xc·ýu\Í1²B\Ê\â\è &â­™ô\Îul<cžŒ¡Ž=+\ï\r\å\Ï\äb¦3t\ãƒÀn\ê\Íó\Ô\ÚGT0›5C3d=öD^p›3TSB1\Ì\ÜkˆRƒó\Â6A6\r\Åuex_[\àµað›\àvB~\Ùq\à›ÿ³\Æ+\Ã\0ƒ\á€xg\Ä$c<LŒ\Ýð°Ù²\ë¨zmó‘±!œSmxvO„¨Ïš÷tŒð¬‰ùˆ‰\É\â3ñ¶Ìš\Û6¿\éI\â);ƒ\ìœ\Â\ìÜ‘)$ž$yo†\\÷˜ž\Ä\Z&©™±J4\é1õU’5;´¦®=Zƒ¾©¸\nÜ›6\áÀ}ûño*C¿’˜{~r\æ\ÎQ±%\è\Å0\ç`ÁÌ9\Î!q\ç/€YF1 ¢ALÐJ±v\'O\åi\ØFH\Ã~½¿Àn­/õŠ\Z¡¿·qnLŽt3š\×{18?\Ú\ê\ï\×\Ä0\Þh:!\è\Ó\ã\"Xöþ»J‚\à(\Ùv…o ^\Ñ\Ë\Â.9\ÈFP_€8Dq\Z\ßú\Òkh\Ö[Ž­5\ÌAÇ¢d0Tlœ°^7w\î \È\Ó0g,\Ï3O^w¡\Î\Ñaµ &\Í\ÈH[·\Äe–_p”uÈ“r\Z\à»J(§hLË¶%Ç…L\Ð4%$¨7Á³\r¼\è\è\Ç\ívHû[ü:u\\R2Iþ^D½m3a\\b@\ÒÙ yB´++`30–Æ‡è–º€\ÔAS‡¬\Õw¾UHmbyk\í.\ä<UÀA—ó¸Dt\à”s=\Ø;JS)±&ö®)H«oéœ°ô\Íðò…\Ü÷)en\ì\Ð.k%‘ >>U­4X\"\åƒ	r¥.¶b7eûŽ£¯f#\Ð9c\É\ã-ûøm\áµÛµ6kr¼!\æ{†f\Âw\ÔÚ©\ã÷µ»¸\ÑrhSµ\Ü:ZUš‹½°c\Ú\Ãs¸µ\n\ì]ð\çW\áðôA\ì0‡«M…»A/–¨®b?Üƒ}9j1\ÖÀ\êŠp\ê¥\0”Ž<b\'k¥4B^d]H\0Aùˆ%@úúµEk!W(S\È²¨‰P-\ÆY†·Nnhw‘<^™\Ùh\ë¾w8_GQŸ‘«T‚\Ã^[U\"ñ¶þ´\Ä\Ì2\"j¼¸•¨\ê@¯µ¿µ\Ù\ê‡•´€¢ û\Ò;\'\ì\á\îQ¬i£–dv®57rXë£»+l›A·xQ8ñrØ¹óð£pð1(lƒ8G§¡°\ÙµÕ­\Ç\Îq:l	¸Í…f\×*\Í\nc®hZ.½\Ð\è\ïÒ¶,\Â-nK\Ì-¢·%\ÞM9\Ì\Ú>?\Ù\"—\Éý‚\Íw\Ê\ï¸ðj˜÷Ž85i‰oõ¼\ág¶jÖŠ°\Év	k¶?w”Í¡\nW\ndO\Â\rIîœ°\éôz9¸øˆ‚S@\×ÁN’€Ÿ\ÅjRR\\†\ßQª5aþ \Òý0™Efý«uJ\Ï(\Ç;>l\Ò\\9E½„*tQ¢Rp\ÃjWÁ\'$\Ã…c[rD\Ù6ð\Û	\Ï\Ñül»fûÙ˜ g\Ù\n™ne&N¿Èˆ+e7D»€\Zl·\r>ØXI\n¿ø¦n\ÐÞ–µ-•µ\åöfd²]#lF\Ýrýh1m´€B÷€\ÌyK\ïBjŒ¾\Ò#L\Ú\Ì×ý£´XF^Y	\ã\ç+‚³…Õ«\Ê\Â.8\Ü\Ý°²õ=\æª(“9ú2h6jZq\èÙ”\r)2…À–\ÇÉ‡`µƒ\\\ÛŠ‘T¡Ý±e¬\ro	×½\í\å\r\í9\ã\Ð\Þhb\Íöw\Ð5\Èý2i\Ñ^A:Š¾/ŸµtAöd\à\Zô\â\05±I°¯›jZ¢&-Qã›‰ÚŒ\Ñ_KÔ‘>/Ð›\Åp8\ÞÕ§6	b\ÚÝmm¥Aò´õ®Y,\èùqeHAq€F,]U0·?ªtö\nýÉŒJJ\ì5H\ë3\ä¤t\å™gU`($Ó >Eû\á•+¹ö§˜ó‹tú‡À d\Ä\Ä8\Ú\í},¢Lû–«ð£\Ö:\ì4~ñ\àˆûHÁF#kiMqµ£\è)\Ìt\0²7‡zIqÃŠ¦tD\ìAp½U\äŠ\âJ\å\Â\ËlqwB¿µ\Ýj¶-(­u¶\0Sû¿µõy³\ÔöW6‚6\è«=$¿\Û\Ú\ÊLtª\ÍBúdo¹¸:ôHY_‚k8YƒL\ÃñŽ *\åtFv£œ©8\æ\êX§ô\ãP\Z\âZ\î\ï\'dZ2[¥ëŸ£³f\ä¬B¿B\Æ\ï \Û*¿¸Y·\äu ¶Á>!»…h\0™\ä!A¼¢=¥÷\ç\r\ËWSt„Œ¾¯¸0\ì3÷ˆE{.phBØƒc2\èB\n‘Sô*h¤\ÐW–^­X¾\â\ÈwY:qBÖŠ\ßí›”¨\"T\ë\Z\Ì\Ä·I+,\ÐñËœL\èc\"\Äf¨¿	\ã\\­pS•ZqÁ™±!º®\Ëô¼R\Æp¤ô¦sHR¢j°¥\0A™›>M®}ŠÁ\"®Î¨j%¯\n,–\Ìõ\é\ÔK\ìEôI˜\éÀ7v·‚\ãc¾¼\Ý\èœb\ì·ò\0Z\Ê Ut-L¶»¨”ß©(\Ö#úÃœ(¹$”¾aùrŸ\Ì\n\Ò\ròÔ½\ÒG× 4FdO¤¤ƒ^q°K°\Ó	ƒk%‹W\\[~\âHo½\n”\Ö.½uÅ‘jH™1#\"¶cñ\ÍX÷‡ca+]\ÑV\ÜxÂ«\\†wC\ï/4\ç\àZY@\Èz­D†=\Ü.Ë¢p$?(\îO`*E|Dufñ\à¼Ž\Ë¹.‘—}\\,T¦qdÀ\"±’]\ßû4vH}‹³¿ý}“\Õéƒ˜“BQW\ÅQ]RÜ•†²[¶>Xk\"¢½9§µ ¿V\ÐÝ¦•«Z|s€”P\r@µ¨xA_À\Ã ¥0T¸\è8óJIIð78\ß\æe™ð\Î­%˜r»\Ú7yµ&À­\èÍ™•·|l{|ôö‚\Ñ3E¹v,^‘6\ïE3‹3%²®ˆö`oÁI\ç …#)²KpS‹¶\ÑL¶˜\'†d0!\\G\\b\Í(\Ý\Æ\"±`x\0|\n\\\0\êx`„lƒ°\n‰\àŒ_\nXúvc®‹|^\ÈM\Ò<\É8\éMb\é\à.,MC1,Ç¯ž\Ýe!t´$\r\Ûaƒg¥\Øc\Ñ\É\0Œz/—,¿\æ\è\ì‚l—\Ð\É,ùtD\Þ	&*0\rv/\á÷€PF@\ïŸ)\ÕkÙ­+†÷ö\é–x„NÀ&!˜[\î\Éî‚¹C¥0eêˆƒ\Ý)Wˆ+V\\A9G>l±»a0-T1$5D\Ñø\nmB§%É8¥ªD¦/_b\ÈÁôÁ\\€:Au‘ˆÁ`•7¾`eXRj  ¶z\'‹C‹HBb\à@\ë\ç\Í$A}xÁ\á`XR\n” .c\É\Ó\Ús\Ým¼\Íú`†ü\\\n¯ôG\ë^A:9\Ô=_°øY\nó§\è&\ØG.)ƒW\é€}\0ô\Õð9˜¡¯¨fØŽE’^\Èhl\ßc\çhÞ–o9WA\×\Ê\à­\Z:\Þ\â.\èXMI´_À¥™nPzô\\\ÉAž\'vu©’~X\Ù*i\Üp¨\nv&#‰\Û=ÿIÀd0™ƒ©(\\Á…K«¸¡R®9\\‘S^9‰ú††·µ’Øœ\Ü\'^\Í	P¬TªÈ®œ\åµ>JCY;\":\Î\"©Ekeõ¥Et­Owo—D„A}³Í¨@YVp©\â\ÎkpH\ä­N`¥d\é*`ö±œý\ì4\èùp>y\n\Ó.8:½\nôJ´R\ì‡-zÉ±ôj‰ˆÅ¶l•»EÕŒ¶	’„ÿ¯¸ó‹‘\ãºòó\'¹œ\Úm\"·´C¤\n.X•¨		\ÑÌ®\Ï ¢	ü l€\ä*€DØ€\ÍØ€-\Å+\Ú\ØH´\Ù8’d\Ó¡$ ô@z 4BdˆT¦‰%—M/¹¨Ys’[\Û[7a#u²jIy8U\Ý=C\Ú\ÙM\Év\×Üªº\ç\ÞóÿüŽ\ÖÈ°\á:ú·ÁŠƒXÎ°®A°ˆÕ¨`\ÍÁ\âœ0—):\ãðYQ\Ñ\Ô\É\æP·-¬…p\ÛÑ»¢…Rl|©ø[¦ B\"B*‰\ä–\Ô=c)«m\å#%\Å+©\Òüh:k_\Èf3\Ü\ì~‚\Â\â\×-\åS\×\×9ò\æk¸=\Ö\Â-\î8º/rò;G	e\Ù¯\ïÅºG%\Æ_6[3‰€]Y5¬èŸ¯\è\r•dF\È;>ž‚=UR!{\Ì!\á‚\"3\æ|!8d·ƒ­‚/÷X°¸W\r·©\Þ\ÞChl‰\'Bš€\äpµ°$ƒ\Ñß†\çÉ«¾Q Ì–¬iA‹B÷A%\Ì\æQ†¿±\ß,(oŠ­þø\Â À¨!‰Y\ë²ù(7C¾}‘ˆ„\âf\ß\È\ÔG\Õüž¸”ôw»„²DD8ü\ÌQÜƒ9\ëož`\íƒUŽ¼ù\ZÙƒ]\Þûñq\æ,*\Ï\â3\Ï\âòœp£@:Ž0,˜ÿ\Â2ýs«ô/¬@”\ÚFa»Á(~VS\Í\Ê²;&Š˜¥\îXò€ˆ”òB \Ö\ärp1:ðÈž¦\Ü4³ÁWþ}Á\Ú&d)$©;¡»2\ÇS„\ÊQ©€B7ƒ]@a9ÿ÷2öò¤ž^§dePp\r 7 \ìUð„7\Ù+‚D)I\ãD\È{)ŒÀu¨P\Ì¡‘C#¨´lÖ–6{¸\Ëüƒ]4”l\\X\åÐ·_\"l‰„|®\ËÆ¹UVÿ\è‹_~\Ö\äpoƒµVÑ¡\âoÄ‘Aù\ë=\æ.ƒBq¥\ÏÆ¹÷8ô\â1\ëA»/‡\Ö=R\"\ÓdÝ”¤U Ù›\"¥®*s\î\ïd_Bñ~A¿Rb¬8,q½¨·€™\ØN®V\èEb\'S\ÓM¶”õóž3\ç\Éä³ŽtOb(2aªñÔ¨U)†§Õ³<r\ä\Ñ\"Am\Éì¸ˆŒ\äw\ípQ\áƒæ»¿ü¶À?\ÄLò°\Íø[O±Š\ßÒ¦¶½|*Ž¬“Z i\ã\ÕtŠl\Õ—Pi×’d&\'|‰¶_\æÆ¹\ÂHYþ\Ê¤¸\Ô\ãô¿~•C/c\î‰%zVÙ¸°ŠÛw»ø¢À÷Ay½\ÏÆ»g\è>¾D>7O&Žª¬\ÈN©ž•7^\ã\Úû«\Ì}q™¸‰õ?XU²½]ò¹9\ÖDk\îö\"Û‰uO8\æFPœ7¿§›M(/xV\ßõ¨*\ÏÌ±ôˆ }…½9\ÙlmÞ³Ý¬½‰9t\Ä\ì÷b=pòT‰\Ì@¶×‘\íIÌ¥9„T\Ä¤)oš\r³]\ÏD°zica®ó›C%rðÅ®¸?\È\\\ÖMR\ç¤“L\Ù\èk\Õc„H\Ä\ßþ`¦AÓ±±­Ï£¦Š,Txñ°$›[GÎ–E™‰qiN¶\'£\èõ\éoY®\ß\Ü\ç8üý\×œ&\ëN-òú‹G\Éòœü±\Åñnõ—6Hó||~Šõ\r\æŸ\\UN¼x¿\Õ\'¨R\\Ú ûù%\ÜlN¾°ˆV\É)\Ö{¬mö­Y\Ã\ë\Ý]X s)kgOS…\Ê0ÛŠ„v\"Ñ„\0:PôF Ù›\á\ÂÕ‚µSe\Çp \æ÷\0j\Ø=\èg<m\à\ß-\ä°7†\ë\Þlð\ëp\æœG\ä{…<kL±!\Ä*\ä\åp]4v‘F&\ßOJ\Î5I\ØxüÝŽÀU+£\Ìce\Ò[£ž‡r|7%w›Åœo ïŒ·[C\"T—†\åX\ëŒ\è8²´‹¤\É\î7“°ú\ÖI–¾r˜ùË¶PIB\âõ0püKG\è\ß\ìó\Ô7ŸGb!Ü°ú› ž\î“K\Ìý¸Kqiƒ\ê\Éb\Üg\Îo•\Ì\âI\ä¾4£¿#\èÀ\ÔÌ“\âR½]!»Ò‡º\æhB4Ys«\ÍÒ°Ž%fù\åcÿý\ç9ó\Î\ÛM4\Í!“¨õo\ßò7”d\Òg»\àÅ©/J=R\æ2kn\0±.ôñW+²‡ó8\Í\ÆPVvHº+§6è«’\î\Ün‡1È\0õmµˆ15õ8”\Ø:_<°$\Ê\â³s,=\\\ãu°\îWø\ã6 L¨¨o7ú¬\r\nü°\"¯¥jE iûrúÁ“?±Ì¡õO}û%*”…/\æè»§9ò‡¯rø\åcz\åÙŒAñeynûQM\å=D\Â\â3‡\å\ÂTõþ\Å5N¿ü\ê8`ž\ÌfhÕ°]±m¦[¦ùJ\ãf3ü¦i‚.I\È\Ú\ß2(Š\Í>\ÅU³3ónŽÛ“¢w\ê1V…\0\ë\çß£º\åaT\Ó]X\ä¹7~´\Í!a\Í\ïöh=\Å=ƒSŠ76X¹XR”jgH*H\×\áž\è\ÚÝ”É¿b\ì[½\ÒÿqŸ\Õõ7+$»L„\É«.lˆŠ\Å\ÈÚ¸ð”‡*sž¥GO\0ŠF9\ê„û®+”B‚4»\Ç*ü0P£\Ìn‰\Ø9¾v„Îž\æð›¯‘D\Â\ÜK,\ç(ŸBÂ–‡‘=û¢À_¹†ŠRn\ÔCsu­þ\ä½w­0\Âe©i¶[Þº>\ÅeË¯O\Ò—\ç\ÆE\Z\Å\Ë\Í8ü¦·4’4³\îw,˜ ‰k¸‡±\ß7\Â&³9\ÙlŽ6\é­4\'\ÒJN¾|Ù w*º‹ý\éIœM`¼­]m\ÖQ°hŒO\0*ô\Ý½JQ\Ú÷óed\n\áJ˜¤óô’\Z\Ç0×¸¢e ºª¬­W0#\ÞÕ‰­;vP¸\ÝôC\ÖÆØ„3±§i¹hA–Å®€O„d$\äÁª\í´@0—U…i¨-šµ¢¸=)®“À\È²Ëªªû—\Öð7K$\ë8ª¢O=jø\Ã\ã¼úÅ§(6‹1j¶\ìN(.õX;u†X„dÆ²\çƒ7¥\'›„þ\å¾w<h5A!\Ë2´ô\èÛ¯.Ï©F0\èíŠ¹\Ë{û4\ß8Œbò\×ìº†8jö-K\Íz¬s\â\Ï!qŒ\Ö\é#]Ž¼ñ£&\ç(L\ÉW³S\çH:±¡Ámzÿ¡¦_\ÚBwqt\ç\\S?\Úô|þzEd\ÎN\êuE=¬ûŠ\"R’Ž\ÆM\ç\Ü\ÛöC`›¬Ô„‘y¢²\È:¯J\ÝQò\Ï-\"Jjñ\ÔQS\Ñ.ðs€0\Åt¦‘\Ì4\Ë\Ü,¨Õ¢(\Î%\Æ\Æ\0‰…toF\Øô\èE’½£”\Í\Õ\í\n­\í\ä\å\ÍÁª\Û™\É@„ê¦§F\É\ÌYú\ÚN¼x”c\ËÿŒµs+¶°uMðž¹§rðû\Ç\ìä©’4ð°ui•\à\Ùl\ÎÂe\æŸX\Â\Å\Õu|ÿ\Z\âœIÉ»\Òdl1W\ß_\ç{_8hÄ¨*ö?¾\È\â“©\Ð1<_\Éx³³\ÃÀüÁ×¶lˆ?·W,ž\Z)~\ËþI·‰\rþfe~_µN&ˆ\à>+$Ql§j\Ðu‡÷pL‹Q\Ý4qÎœ‰{¸\n\\e®Ñ²\Ó*Ü¬Ñ»\æj#	ŒÀ‰k\ä‘-P2›Ê’\Î:\Érªa@‡•¹ùºù8,”¥aÿc,Ö‡‚P’\Ý—fô.¬Ø\î\Ô,}ý¿tdP©e³\Ðd6gþA½S\ãšHR¸]\âvg„8ó\Êë¬½s\ÚDP^\é#‰qLC\æ\Õ(5J\âR–ž£F9ñ­\ç\í»\ÈlE/ŽTš®\Î\è°&„Š¢¨Y;[Ql†ñ{n¼\èý¤À\ír\È\\nY—\"¤©±\Øb]-\ØôOj\'Ä£¦E:¨›~\ì\íÓµ\ë¿\ÕÕˆk~\âdà ¨\ÐQ¢”d”#¡!l\ÕôÀ©Ÿ–°‚P\\Ú ¸Ú³\è}\Ë³T„öÿ{­y¯6()IM\'€†\ÊN½*\éƒ9KO?‹›q\\[_#l\ÃÀ\ê›\ÇIòŒ\à=K¿ÿG¾ý\0>xªaÕ¤™Vz‚ª´!ÉŒ¬\Ú,ˆÀH9ù‡\ÇXy÷m\Ú:ò¢\×k\Ì¡\Ö\Ô\Z¶½\áò‹G9zö4Ï¿qœ\âfŸ\âr\ÏÀ¿\ÚTŒ‘n\ë\ÛZ\r­OAQz=\ãqm—Ž`\åb‰>Ò©)6+\Ê\Í\n’Y!M!{D †þ¦AŸ8°>¨\Ç\ìw¢¼M\è°óÀU#\ZWk\Ìúy±™$6·\ã°!l€?mUú/|ò\ê\rð\ÇCy“¬\Ün¯\É7˜Ö¤™Ý°ô\Ô!?2\Ï?=É¡\ï¾J¥Áÿe!\Î\0\0\ïIDATˆQ\×$³9‡^9†\ìJeI\Õt¾8ó\Î	\ÞûÁ\ëd{rô¶g\éË‡9ü(a«\Én\áô¿ù\Å\Åudw‚Ì¸‰Ò¦fe\é\Ä\Æu@ñþå¾\é\Ñx«h\â!öÞ¡°Mã²¤9:®u\r£V\ë€jhù\Ï\í½b„,|€•{”g\ÂmNL\"‚\n\ÅE\Ï\Ú\åŠkU 50,\Ð>\å.´;\Õ\ã\Ó\Ú*P\Êv4VA}\É6 kÀÉ¶\à–\Â_\ÔMˆj\'qEb’™xªA…Þ©\È\ÙÏ‘\ï¿f9°U…\Ûc™þÁW\èG¶È‹O.3·¼lþ\Õ\Â#»,\\¶qv•²\ßgñÀA}\ã\Ú\å>þ\Ö	~ô#&ƒ¼gá«‡\é\Î\äøÞ†]\ã—JÓ¾eWB2“\áo™\r.—¦S;\\¨Fj\ËÌ«d&!™I\ÆXª°¿u3Ž8rø­\Â\ìõf“\Ì=¹L÷\Ñù	[œ\Þô»]/™›t\ã*7!K\r5þz I…ü1¡º¥ô¼,\Ð7™\Û\ÒY·)M;>›R\æ\ê‘\âG5Yˆ).Ó ¿*Ú™Â PøO;Üˆkþ^\Ùe¬5\Ü*mY:Žù§\âf\Z\ÉL† Ôƒ\Ùev\éÉ—ñö‹GmQ\Ñp\Îq\æ•clœ{\Ï\ä\Ï\\A\ÈÒœ\å\ß] ¼\Þ\çä·Ž\ÑQ¹\Ù_4¶\ë.!\Íð…›@Ù¾œ°Y w*$Óœa\03¿lcdVO;5Â–\'Ž*Ï¾ù\ZsO.SB\Ó÷GÙŒ<OqmÀ\ÔŸ×‘­“`Áz”k^I\Ó©!\Ù\çpsPœ+(0–.*H“P·“­^3þl¬\ìøl\Å0 £š\ê\Ò\Ä\íXGS\0^5\Ül_¹=µ\ÛJšFf%W¥GbAU8ý\â1’½9sO>\Ô$®µ‰š‚wN³1,\Í}74Y#»\ÜLFð&s\ã(&\î8¾øó±qö=Žó_\à¯$YNœ$T7\n\Ó6DH²œ\â\Ò\ZZ›W\É\íI©\Þ7+\É2\Ülf\rÒœ°\å	#¥\Z4Ÿ…\Ø%\ÛN^}\ß\ï“u»¸<7g»½ó«›\Ùf1\É?\ÞA€Z¬‘‘DMb™\Ä\rœPM‰RŽ`\áñ–\Â%\Ï\Æ-uˆC\Ói\\Œu4‹;5ÿôýZ†<1\Ö\ì\Z?Tb\\= \r;Ÿ\n\Û)zC*Æ $6ES\rF$H\'1yK\ÖN­\í\ËYzö0µŠ\é\Þ6\rV\â„|až\â¼9#*\ï\ÑZ‘]B2kµ6u“Ÿ#„[T\Äcl\áV	¤³ÆŠõNmNŠ\Ù½ hPd—i\Ê\0Õ B¼gÿ\ãK\Ì~	™qœø\êó\\\Û\èÀ;‡tb\\6\ÉdLpT\ÃÀ‰oe\é›Gp3)\Zý‹«lœ[Aú\ç×¬»\Ödi¼^–O,b\Ï\Ü.X,d\"ˆ*…Bw\ÈzEÿ¢¢.!i\ì\è$ŠA\rY­V‹ \í$\î=GK&\ÚÂµ¡²_¡ÒƒÈ¬kÓ„µˆ›b)#ct¢\È\ÒEŠK=|ðduw<ùþ\Ï\Í\ã7\êa°\Ó4“¾{ó3c\Å:¬$\Ã\ívø[\Å\Øi\Ä6Š›I\Å_¿f\åf¨ªA¨\'	InM†ª\Ç\í\ÉHsc½\ZÉžÙ‹C\\L2›ÁfŸê–§X_§\ZTø\Å6Ÿo‚Ã—\'^>f	\ér\ä¦«u¦]\Úlø1tÞ¨Fi ZX@ÀW5+@\ê\Ú\å AQ³ti0E›\n:5;d\Z\àºM>\"-³Ž;bph_°vj§¾Ö¥·®\Ûû\çX?\Ãû\'º¶ø.&Lo®ƒy~$Üž”\â\ê5´nNÓž´ñD\Õv2g\ÚH¥o¼@ 3	\Üj”±\ì\Äp«$Ž„0R}÷U$qTƒ€t•\êaE\ì\æ\ÈdpÔºZ…Û–pV\\\Ù ™\Í(z×¨%!Tø\ë9By½Ï¾|d,Z&§¶%\î´ü\Üþ­8|Ô¤\ÍEÆ‰\Ä\Õöö\Ù	\á\Û\ìA»\ÉUj”%¦\å\å8\Ô\Ö\Ø\\ˆ\r»+fw÷&Ñ‘ø¬\ÉS\Â!¿\âÙ¸P\à{\Û\í*üW™°6uº\ÙÁâ¨´$”Á2\îcƒõ0LN\ÓlfA\ä`Ad·\Û\äi\ÔÕ–\'\í\æ${2ŠuU…\Ë2º/²ú\Öq\ê\Û—$\Ì}Ñ Ô“Gqa\Í\Z—Áü\ÏWû\Ä\"¬þôý‹«MðÜ±ö\Î\Ö\Þy{›ö\êhZ·4\Û4Œ?»{´\×\å³]\Ë\ÒoÂ“\å\Õk\Ô\ÃÒ”£6\ÅNlYƒQ[¢Q£\ÅS€&ukOÿÕ‘ŒÏœð§HÖ””\ÔMÁ6\0#¡fR2\Ý8B©q.&X\ãB\ÊR)®ñ\î\íyÅŸ*|8MXÁ„½\Õt%FTŒ@!\àöd¸=vi]z\Ès\Ë\Z5\n–X“„\çÿ\èi·\Ëñ¯Á_\é1ÿ…eòG\çXûw§A•\Ø9žú\Îsô/®òú7pø\ÅcV‡2TV/¬²vö)\Â\Ê^UªQ ÁÑ¿¼N\ïòúXso7b\Ò|R\Ð6~0ÿ®HL¶/\Çoyüf15S# \Ì?\Ò\Å\ÍffRE\Ð¿´[\ÜhÛ¬ahˆÛœ“\ÈMt¦9±Sdi5\ÝvÎºU\Ð\Ð)\â¢\Ô#c\Ïq$c\â\Öj¹_©sƒ²± =xwj\Ì/þ\Ñ\ÎW#53#t\à.Ij2¢5\'’¦\Ë\Ó6y\×\\š‘daà©‡\æ¬\ÐXyó8.Ï›ù„\âz}ù‰sT!\ÐF\Ö	õ°lNœ¬öôM¬“š[“À‘gŽ°±¾\ÆòWw„k—úy\å%¾÷õ\ç\éoö\ïIX‰E„€\ê–Å†».€*aZ™#C&ª‘’6\'k<F¯½\Õ~GÍ†¸ëŽ“yÀ+-°\çX~‘\'¥“\r\ZNƒ®š¸„tPN\á\æ(K\ì¨Ý©\Ñÿ\ìv\Ü^š‡\×\æŠ¢·+\âŽ#\í\ÎYT§dûòFV$½\r’½9þ\Ê\Õ  ¡¢ºQJ\Ï\ëO¢\Z\ØFð?+ÐŸM\î“5²®Ê‰Ÿy¬\ÎÀ\â£l4a½—¾û*\ë\ç\ÞC¢˜\å¯?K\ïü:2\ã8ù\Ã\×\íû·ÿ-«o½\ÍÊ©\Ó\äûrú\ëk$ø\Þ\Å\ÑÍ‚\äÍ‘\ìÉšŒÅ„*Ttæ­‚\í\ì\êø0‰1.÷\ÜF¶¦`Y\Z»RFw\ÝlÇ§\æD\Ç5´wY\'má¬²3²\ÒS-Wxhn;a6w\Þ4f\â\Êj½*KªAi\Zf\'¦a•“\ß:Jy£@C\ÍÚ©3¬:3E’‰~\á5Œ\åŒ\ÃbÀÁ\ê~0Ö¿ô\ènwBq£ \ïv	·=éžŒü±E\Ò<gþñE\Ëð”¼ðƒ\×\è_…Žws–¿p\"aå­·	Á›­\Ú\ë¶<\'^|½\å›\Ä4\Ýnð£Ôƒ’xw)~«@ËŠ\Þ0˜w\Ç%\äE³Éµñ\rOŸ”qq\Õ\Ð\ÒE½ªùt#J›\Ö2½\êS,ºut¶i¹ˆŽ‰\Û\Ú\×V7«È«\È\ë\Ò}8§ÿ¾õÀõ7•š°k[³¿—!§ZB´7ó\Ì\Ïd¸A3\'\"ð\Ã\ÒlÁ©€\ß\Î7/\âG¡±\ß\â„|\ß~ú—7HÓŒ¥¯¦¿¾Á\Ésg8r\à ‹qô•c<÷\äA¿rŒ•·N\"ý‚,\Ïð·+²]1k\ëk J¾¯\Ë\ÆùUaÿ#]Š¢`\ãƒu–XWj°`Ú¤½Ê½‡m@%£)ž³\Û;V\èP¯ö-3,ø­#«\Ò\×a\Ó\êtŠè±­­¥£FµsüzÛµÅ\ÆDŠ¬w^ªœz‰|_—÷~r’3¬}\î§Kn#¬À?É‘‹;	[D\Ê\âLŽ5^-Xh\'X\î)«¦‡…\Æÿ\åó$»-½v~…\ç~ð\Z\Ç¦\Ø\ê³ñé§¬Ÿ]\áðW³<·\ÈÁ¯\æÌ¹÷È£V}³•—ž>\ÈúùUV/¯³ð\Ð¨²¾ÙŸp¶ûs§M…xj]ó[›lsˆZ¢ŽG$Û \ÚZ\Úi_q¥Œû\ê\Õ:	¥¶÷M¦\ÖQ¦~Z\Í\\\Z\âÁD	„íš»‹¬7l\ìb\Ä	²K\Æñm·\'cÿç—¨û\Çx‚°‡w¶gy$GþdzGŒ=Î¥9ùŠ¡onü\×ð’0©¿>yeƒd&aõ\Ôiú—z,=ó,~«`\í¬\Õ\Ò&.Á÷¯±ry¥‡\èv÷sú\Ô\ÉmÁÿ¶9`B\Ó$‚‰™2ý<Bc\ÖD“…œö¦µ¢`Z;oˆ\êd’k\åœ4Ÿ\éÈ”\Ê6;?ì˜§©º?•L}ÇŽß§Ÿ\î6\Ç\ÚÏ™s$.Ff.\ä§)ùcól¼³Â‰ó«¬\Â;	»7GŠ\é‡	~`w&§;‚2Tw-\ä¯ö\nKOd\íü*.\ÍLm–º\é·<ý\ÍþÔŽ6–i2ø\î\Ñ\ÞW°^­Nb²G¾\'³\ÂQMð¿U\ì5OXQ†ñ“LŸ¦¿mD¿\âóvž~\ãm\Ï8;7“\Þ\ão¦O\ïôœí˜ž;kDHSG2›á²„\ì¡.\É.Ç‰\ç\Ä \ÜE\Ø8G¶hZQ\n`.\Í\éŽ,\Ù\íoFX\Zn{±\é;gšb›üð‹\ZýsB\Ñ[\Ý4ýC°ü\ç	7®\ávg\èG\ÖÃ¼\Ø2eÇ—¥ÕŒFP;Ç½žþ^Ž‹ÿý»ýú9Z\î6ý«õò{\Ïy¯y[™E––”wSòG\ç).÷9vvõw2ž\Z(ú@Óš—kS{\'7 \ß9&\á\à\ÉÎœ<\è½Us&ðKLßª¡Pô¦\ÂQô\Ï>n\ï|õù\Ùü·\ÕG¯lPmzV\ß]¥\Ø2[®%a\r–\Ù\ÍD¦µ‹<M\æ\é\Ål\Ù\ç\Î1>\Õ\íj\Ý\ãý§Y©½\Ûö“Z\Ý\ãši=`z…ÜŽë¦Ÿ©½¶³\Z)\×n\ä›ûoºs]S÷\ïr7\×\è/„\Å)–H„•;4¸½\ã\\Z–2‘w;\æj?¿\áLþ¢†¿ÀˆW”h#Ü½6\é¯\Z÷-FúO»Ï³q¡\Ç\ê\ÍÂºN±\í\å2QEœXn\Ñ\Ä6n¸\Èh\ÊeÚ±H\rLds¥vM\Òiº\ÐuNF˜	‚œV\ÑJÚ†IÍµ\Õ\ÐZ•M§\ÐHk§Ò˜“Mî˜´ó\Ð*kñX®·ök­5AÕž‰ç«¸j•¥\Ç\æ?½‹°\n·rdÁ£ô\ZÂ¤k¸6ôô§\Ê§v\à\Ç1òaC¼5zK\áOJ5Àœð?ÿ\Äû•ca¶»\ä\Åk—ûj8½.±=\îB¥Œ\è2	:ªA­M¶kÌ†ªq¢[¥_³\ÐS5n\ìÓªub‹8v0Y:2sÏ‡\Ú«æ™­NW›gh\Øñ”6\Í!\Ùý\êÑ”G*²­\í¶\î\ä{*i6£™t\ßEXAnV5ß¶\'\Ë$¡xŠ‘þ\Ü\ÙW}–\ãZ\ØN¼ÿO	ö\×‡ºÝ—Šó–\Þu\ÎL–F<xU|h*„GÚ´9»›\ÍÁYA1°«&§\n&\"fZÁ	†,3•x¶S!›V–\Ú\ï¦\'údB´\ÉÿeÛµ“7Ø©p¹©“žDÀP)6·WÛµS}¬L\Ò@’Žs#ý\ç\n§Ê»ÿ\àÿ\éP|&X\æ{œVŽ¶{“lL/rûünÇ›·ì¯¦‘‡ÝšD\Ò\Ö-\îS ñ	ð\étC‰øði\rQ5lº½s\ë\à‡q¡WK¸Ö‘\Ñv¶ÞˆÓ¢¥Í­L™\Ø\Æ\Ð(Q#c\ßa¨m\Û]w6À,\Ðß¶\àU\rõ¿\ë°8©py\çµÿ?†¯ôO~S‡a\\\Ã2\Þ\Ï\çªôCÐK³\Û>TB!ò)\È\'Œ\Â\'DòI1\âH\Ç\\ô\Õ ü%p\Âýq$WCý%‹\Èýq\Ç\ÝW\rB\Ð5÷K$÷\éH?RøD\à¾Ö¦‹\Æ~\"‘ü†t\ä\ïjŸH\ÄŒø,p2“>€\ê}:8\ç~¸/„€s\î>:rÿ\êVI6\ãî—ˆû4>ƒ‚t\ä>A>“\Íf3U\é£RMB$|6KPý80¥F\Ü_•þ¿C-ÿ±››»La\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,1,'1/3,2/2,3/0.333',0,1,0,0);
/*!40000 ALTER TABLE `products` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `providers`
--

DROP TABLE IF EXISTS `providers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `providers` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL DEFAULT '',
  `address` varchar(255) DEFAULT NULL,
  `phone` varchar(50) DEFAULT NULL,
  `cellphone` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`,`name`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `providers`
--

LOCK TABLES `providers` WRITE;
/*!40000 ALTER TABLE `providers` DISABLE KEYS */;
INSERT INTO `providers` VALUES (1,'No provider','-NA-','-NA-','-NA-');
/*!40000 ALTER TABLE `providers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `random_msgs`
--

DROP TABLE IF EXISTS `random_msgs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `random_msgs` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `message` varchar(512) DEFAULT NULL,
  `season` int(10) unsigned NOT NULL DEFAULT '1',
  `count` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `random_msgs`
--

LOCK TABLES `random_msgs` WRITE;
/*!40000 ALTER TABLE `random_msgs` DISABLE KEYS */;
/*!40000 ALTER TABLE `random_msgs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reservation_payments`
--

DROP TABLE IF EXISTS `reservation_payments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reservation_payments` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `reservation_id` bigint(20) unsigned NOT NULL,
  `date` date NOT NULL DEFAULT '2010-01-01',
  `amount` double unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `SEC` (`reservation_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reservation_payments`
--

LOCK TABLES `reservation_payments` WRITE;
/*!40000 ALTER TABLE `reservation_payments` DISABLE KEYS */;
/*!40000 ALTER TABLE `reservation_payments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reservations`
--

DROP TABLE IF EXISTS `reservations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reservations` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `transaction_id` bigint(20) unsigned NOT NULL,
  `client_id` bigint(20) unsigned NOT NULL,
  `date` date NOT NULL DEFAULT '2010-01-01',
  `status` int(5) unsigned NOT NULL DEFAULT '1',
  `payment` double unsigned NOT NULL DEFAULT '0',
  `total` double unsigned NOT NULL DEFAULT '0',
  `totaltaxes` double unsigned NOT NULL DEFAULT '0',
  `profit` double unsigned NOT NULL DEFAULT '0',
  `discount` double NOT NULL DEFAULT '0',
  `item_discounts` varchar(1000) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reservations`
--

LOCK TABLES `reservations` WRITE;
/*!40000 ALTER TABLE `reservations` DISABLE KEYS */;
/*!40000 ALTER TABLE `reservations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `so_status`
--

DROP TABLE IF EXISTS `so_status`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `so_status` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `so_status`
--

LOCK TABLES `so_status` WRITE;
/*!40000 ALTER TABLE `so_status` DISABLE KEYS */;
INSERT INTO `so_status` VALUES (0,'Pending'),(1,'In Progress'),(2,'Ready'),(3,'Delivered'),(4,'Cancelled');
/*!40000 ALTER TABLE `so_status` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `special_orders`
--

DROP TABLE IF EXISTS `special_orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `special_orders` (
  `orderid` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL DEFAULT 'unknown',
  `groupElements` varchar(1000) DEFAULT '',
  `qty` double unsigned NOT NULL DEFAULT '1',
  `price` double unsigned NOT NULL DEFAULT '0',
  `cost` double unsigned NOT NULL DEFAULT '0',
  `units` int(10) unsigned NOT NULL DEFAULT '0',
  `status` int(10) DEFAULT '0',
  `saleid` bigint(20) unsigned NOT NULL DEFAULT '1',
  `notes` varchar(800) DEFAULT '',
  `payment` double unsigned NOT NULL DEFAULT '0',
  `completePayment` tinyint(1) DEFAULT '0',
  `dateTime` datetime NOT NULL DEFAULT '2009-01-01 00:00:00',
  `deliveryDateTime` datetime NOT NULL DEFAULT '2009-01-01 00:00:00',
  `clientId` bigint(20) unsigned NOT NULL DEFAULT '1',
  `userId` bigint(20) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`orderid`),
  KEY `SEC` (`saleid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `special_orders`
--

LOCK TABLES `special_orders` WRITE;
/*!40000 ALTER TABLE `special_orders` DISABLE KEYS */;
/*!40000 ALTER TABLE `special_orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stock_corrections`
--

DROP TABLE IF EXISTS `stock_corrections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stock_corrections` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `product_id` bigint(20) unsigned NOT NULL,
  `new_stock_qty` double NOT NULL,
  `old_stock_qty` double NOT NULL,
  `reason` varchar(255) NOT NULL,
  `date` varchar(20) NOT NULL DEFAULT '2009-01-01',
  `time` varchar(20) NOT NULL DEFAULT '00:00',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stock_corrections`
--

LOCK TABLES `stock_corrections` WRITE;
/*!40000 ALTER TABLE `stock_corrections` DISABLE KEYS */;
INSERT INTO `stock_corrections` VALUES (1,3,100,0,'Adjust','2015-12-28','12:22'),(2,1,100,0,'sin','2016-01-01','22:03');
/*!40000 ALTER TABLE `stock_corrections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `subcategories`
--

DROP TABLE IF EXISTS `subcategories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `subcategories` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `SEC` (`text`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `subcategories`
--

LOCK TABLES `subcategories` WRITE;
/*!40000 ALTER TABLE `subcategories` DISABLE KEYS */;
INSERT INTO `subcategories` VALUES (1,'General');
/*!40000 ALTER TABLE `subcategories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxelements`
--

DROP TABLE IF EXISTS `taxelements`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taxelements` (
  `elementid` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `ename` varchar(50) NOT NULL,
  `rate` double unsigned NOT NULL,
  PRIMARY KEY (`elementid`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taxelements`
--

LOCK TABLES `taxelements` WRITE;
/*!40000 ALTER TABLE `taxelements` DISABLE KEYS */;
INSERT INTO `taxelements` VALUES (1,'Exento de impuestos',0),(2,'IVA',16),(3,'Impuesto al tabaco',5),(4,'Impuesto a las comunicaciones',2);
/*!40000 ALTER TABLE `taxelements` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxmodels`
--

DROP TABLE IF EXISTS `taxmodels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taxmodels` (
  `modelid` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `tname` varchar(50) NOT NULL,
  `elementsid` varchar(50) NOT NULL,
  PRIMARY KEY (`modelid`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taxmodels`
--

LOCK TABLES `taxmodels` WRITE;
/*!40000 ALTER TABLE `taxmodels` DISABLE KEYS */;
INSERT INTO `taxmodels` VALUES (1,'Exento','1'),(2,'General','2'),(3,'Cigarros','2,3'),(4,'Comunicaciones','3,4');
/*!40000 ALTER TABLE `taxmodels` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactionitems`
--

DROP TABLE IF EXISTS `transactionitems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transactionitems` (
  `transaction_id` bigint(20) unsigned NOT NULL,
  `position` int(10) unsigned NOT NULL,
  `product_id` bigint(20) unsigned NOT NULL,
  `qty` double DEFAULT NULL,
  `points` double DEFAULT NULL,
  `unitstr` varchar(50) DEFAULT NULL,
  `cost` double DEFAULT NULL,
  `price` double DEFAULT NULL,
  `disc` double DEFAULT NULL,
  `total` double DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `payment` double DEFAULT '0',
  `completePayment` tinyint(1) DEFAULT '0',
  `soId` varchar(255) DEFAULT '',
  `isGroup` tinyint(1) DEFAULT '0',
  `deliveryDateTime` datetime DEFAULT '2009-01-01 00:00:00',
  `tax` double DEFAULT '0',
  UNIQUE KEY `transaction_id` (`transaction_id`,`position`),
  KEY `product_id` (`product_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactionitems`
--

LOCK TABLES `transactionitems` WRITE;
/*!40000 ALTER TABLE `transactionitems` DISABLE KEYS */;
INSERT INTO `transactionitems` VALUES (4,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(4,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(4,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(5,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(5,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(5,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(7,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(7,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(7,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(10,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(10,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(10,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(11,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(11,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(11,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(12,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(12,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(12,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(15,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(15,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(15,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(21,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(21,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(21,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(23,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(23,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(23,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(25,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(25,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(25,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(27,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(27,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(27,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(29,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(31,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(32,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(32,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(32,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(33,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(33,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(33,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(34,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(34,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(34,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(36,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(36,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(36,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(39,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(39,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(39,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(41,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(41,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(41,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(43,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(43,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(43,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(46,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(46,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(46,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(48,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(48,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(48,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(50,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(50,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(50,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(53,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(53,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(53,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(55,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(55,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(55,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(57,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(57,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(57,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(60,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(60,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(60,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(62,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(62,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(62,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(64,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(64,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(64,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(66,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(66,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(66,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(67,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(67,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(67,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(69,1,1,2,0,'Pc',5,10,0,20,'Producto1',0,1,'',0,NULL,0),(69,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(69,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(75,1,3,0.5,0,'Kg',15,30,0,15,'Producto3',0,1,'',0,NULL,0),(76,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(76,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(76,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(78,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(78,2,2,2,0,'Pc',10,20,0,40,'Producto2',0,1,'',0,NULL,0),(78,3,3,0.3,0,'Kg',15,30,0,9,'Producto3',0,1,'',0,NULL,0),(81,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(81,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(81,3,3,0.6,0,'Kg',15,30,0,18,'Producto3',0,1,'',0,NULL,0),(83,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(83,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(83,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(88,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(88,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(88,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(88,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(90,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(90,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(90,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(92,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(92,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(92,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(94,1,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(96,1,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(98,1,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(100,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(100,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(100,3,3,0.5,0,'Kg',15,30,0,15,'Producto3',0,1,'',0,NULL,0),(102,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(102,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(102,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(104,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(104,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(104,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(109,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(109,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(109,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(111,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(111,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(111,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(111,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(113,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(113,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(113,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(113,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(115,1,1,11,0,'Pc',5,10,0,110,'Producto1',0,1,'',0,NULL,0),(117,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(117,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(117,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(119,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(119,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(119,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(121,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(121,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(121,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(121,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(123,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(123,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(123,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(124,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(126,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(126,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(126,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(127,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(127,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(129,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(129,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(129,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(130,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(130,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(130,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(132,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(132,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(132,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(133,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(133,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(133,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(133,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(136,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(136,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(136,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(136,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(137,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(137,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(137,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(141,1,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(141,2,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(141,3,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(143,1,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(143,2,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(145,1,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(146,1,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(146,2,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(147,1,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(147,2,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(149,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(149,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(149,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(150,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(150,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(152,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(152,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(152,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(154,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(154,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(154,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(155,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(155,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(155,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(156,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(156,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(158,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(158,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(158,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(160,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(160,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(160,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(164,1,1234567890123,2,0,'Pc',5,10,0,20,'Producto1',0,1,'',0,NULL,0),(165,1,1234567890123,3,0,'Pc',5,10,0,30,'Producto1',0,1,'',0,NULL,0),(166,1,1234567890123,3,0,'Pc',5,10,0,30,'Producto1',0,1,'',0,NULL,0),(167,1,1234567890123,2,0,'Pc',5,10,0,20,'Producto1',0,1,'',0,NULL,0),(168,1,1234567890123,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(168,2,4,1,0,'Pc',39.995,0,0,0,'Paquete1|  3  Ninguno|  2  Ninguno|  0.333  Ninguno',0,1,'',1,NULL,NULL),(168,3,1234,3,0,'Kg',15,30,0,90,'Producto3',0,1,'',0,NULL,0),(168,4,987654321123,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(171,1,1234567890123,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(171,2,1234,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(171,3,987654321123,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(173,1,1234567890123,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(173,2,1234,0.3,0,'Kg',15,30,0,9,'Producto3',0,1,'',0,NULL,0),(173,3,987654321123,2,0,'Pc',10,20,0,40,'Producto2',0,1,'',0,NULL,0),(174,1,1234567890123,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(175,1,1234567890123,1,0,'Pc',5,10,0,10,'Hersheys',0,1,'',0,NULL,0),(175,2,1234,0.1,0,'Kg',15,30,0,3,'Neon candy',0,1,'',0,NULL,0),(175,3,987654321123,3,0,'Pc',10,20,0,60,'Doritos',0,1,'',0,NULL,0),(177,1,1234567890123,1,0,'Pc',5,10,0,10,'Hersheys',0,1,'',0,NULL,0),(177,2,4,1,0,'Pc',39.995,0,0,0,'Paquete1|  3  Ninguno|  2  Ninguno|  0.333  Ninguno',0,1,'',1,NULL,NULL),(177,3,1234,1,0,'Kg',15,30,0,30,'Neon candy',0,1,'',0,NULL,0),(177,4,987654321123,1,0,'Pc',10,20,0,20,'Doritos',0,1,'',0,NULL,0);
/*!40000 ALTER TABLE `transactionitems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transactions` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `clientid` int(10) unsigned NOT NULL,
  `type` smallint(5) unsigned DEFAULT NULL,
  `amount` double unsigned NOT NULL DEFAULT '0',
  `date` date NOT NULL DEFAULT '2009-01-01',
  `time` time NOT NULL DEFAULT '00:00:00',
  `paidwith` double unsigned NOT NULL DEFAULT '0',
  `changegiven` double unsigned NOT NULL DEFAULT '0',
  `paymethod` int(10) NOT NULL DEFAULT '0',
  `cardtype` int(10) NOT NULL DEFAULT '1',
  `state` int(10) NOT NULL DEFAULT '0',
  `userid` int(10) NOT NULL DEFAULT '0',
  `cardnumber` varchar(20) DEFAULT NULL,
  `itemcount` int(10) unsigned NOT NULL DEFAULT '0',
  `itemslist` varchar(1000) NOT NULL,
  `points` bigint(20) unsigned NOT NULL DEFAULT '0',
  `discmoney` double NOT NULL DEFAULT '0',
  `disc` double NOT NULL DEFAULT '0',
  `cardauthnumber` varchar(50) NOT NULL,
  `utility` double NOT NULL DEFAULT '0',
  `terminalnum` int(10) unsigned NOT NULL DEFAULT '1',
  `providerid` int(10) unsigned NOT NULL DEFAULT '1',
  `specialOrders` varchar(1000) DEFAULT '',
  `balanceId` bigint(20) unsigned NOT NULL DEFAULT '1',
  `totalTax` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `SEC` (`clientid`,`type`,`date`,`time`,`state`)
) ENGINE=MyISAM AUTO_INCREMENT=179 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,1,2,500,'2015-12-28','12:21:00',0,0,1,17612688,2,1,'-NA-',100,'1/100',0,0,0,'-NA-',0,0,1,'',0,0),(2,1,2,1000,'2015-12-28','12:21:00',0,0,1,17612688,2,1,'-NA-',100,'2/100',0,0,0,'-NA-',0,0,1,'',0,0),(39,1,1,60,'2015-12-29','17:37:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,24,0),(4,1,1,60,'2015-12-28','12:23:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,6,0),(5,1,1,60,'2015-12-28','12:23:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,6,0),(7,1,1,60,'2015-12-28','12:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,7,0),(21,1,1,60,'2015-12-28','22:34:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,15,0),(29,1,1,10,'2015-12-29','10:07:00',10,0,1,1,2,1,'',1,'1/1',0,0,0,'',5,1,1,NULL,19,0),(10,1,1,60,'2015-12-28','22:10:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,9,0),(11,1,1,60,'2015-12-28','22:11:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,9,0),(12,1,1,60,'2015-12-28','22:11:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,9,0),(46,1,1,60,'2015-12-29','18:57:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,28,0),(43,1,1,60,'2015-12-29','17:40:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,26,0),(15,1,1,60,'2015-12-28','22:22:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,10,0),(27,1,1,60,'2015-12-28','22:46:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,18,0),(23,1,1,60,'2015-12-28','22:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,16,0),(25,1,1,60,'2015-12-28','22:44:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,17,0),(31,1,1,10,'2015-12-29','10:11:00',10,0,1,1,2,1,'',1,'1/1',0,0,0,'',5,1,1,NULL,20,0),(32,1,1,60,'2015-12-29','11:49:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,20,0),(33,1,1,60,'2015-12-29','11:50:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,20,0),(34,1,1,60,'2015-12-29','11:51:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,20,0),(36,1,1,60,'2015-12-29','17:36:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,22,0),(41,1,1,60,'2015-12-29','17:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,25,0),(67,1,1,60,'2015-12-29','19:59:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,39,0),(48,1,1,60,'2015-12-29','19:00:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,29,0),(66,1,1,60,'2015-12-29','19:59:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,39,0),(50,1,1,60,'2015-12-29','19:35:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,30,0),(53,1,1,60,'2015-12-29','19:36:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,32,0),(64,1,1,60,'2015-12-29','19:55:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,38,0),(55,1,1,60,'2015-12-29','19:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,33,0),(60,1,1,60,'2015-12-29','19:42:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,36,0),(57,1,1,60,'2015-12-29','19:41:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,34,0),(62,1,1,60,'2015-12-29','19:53:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,37,0),(69,1,1,70,'2015-12-29','20:02:00',100,30,1,1,2,1,'',4,'1/2,2/1,3/1',0,0,0,'',35,1,1,NULL,40,0),(76,1,1,60,'2015-12-30','11:11:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,45,0),(75,1,1,15,'2015-12-30','11:10:00',20,5,1,1,2,1,'',1,'3/0.5',0,0,0,'',7.5,1,1,NULL,45,0),(83,1,1,60,'2015-12-30','13:36:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,49,0),(78,1,1,59,'2015-12-30','11:21:00',60,1,1,1,2,1,'',4,'1/1,2/2,3/0.3',0,0,0,'',29.5,1,1,NULL,46,0),(81,1,1,48,'2015-12-30','12:21:00',60,12,1,1,2,1,'',3,'1/1,2/1,3/0.6',0,0,0,'',24,1,1,NULL,48,0),(88,1,1,139.99,'2015-12-30','22:06:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,52,0),(87,1,2,39.995,'2015-12-30','22:05:00',0,0,1,3791600,2,1,'-NA-',1,'4/1',0,0,0,'-NA-',0,0,1,'',0,0),(90,1,1,60,'2015-12-30','23:44:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,53,0),(98,1,1,79.99,'2015-12-30','23:50:00',80,0.010000000000005116,1,1,2,1,'',1,'4/1',0,0,0,'',39.995,1,1,NULL,57,0),(92,1,1,60,'2015-12-30','23:44:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,54,0),(94,1,1,79.99,'2015-12-30','23:48:00',80,0.010000000000005116,1,1,2,1,'',1,'4/1',0,0,0,'',39.995,1,1,NULL,55,0),(96,1,1,79.99,'2015-12-30','23:49:00',80,0.010000000000005116,1,1,2,1,'',1,'4/1',0,0,0,'',39.995,1,1,NULL,56,0),(100,1,1,45,'2015-12-31','00:05:00',45,0,1,1,2,1,'',3,'1/1,2/1,3/0.5',0,0,0,'',22.5,1,1,NULL,58,0),(102,1,1,60,'2015-12-31','00:39:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,59,0),(111,1,1,139.99,'2015-12-31','09:25:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,65,0),(104,1,1,60,'2015-12-31','00:55:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,60,0),(109,1,1,60,'2015-12-31','09:16:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,64,0),(113,1,1,139.99,'2015-12-31','10:11:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,66,0),(115,1,1,110,'2015-12-31','10:15:00',110,0,1,1,2,1,'',11,'1/11',0,0,0,'',55,1,1,NULL,67,0),(117,1,1,60,'2015-12-31','10:50:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,68,0),(119,1,1,60,'2015-12-31','10:52:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,69,0),(121,1,1,139.99,'2016-01-01','16:10:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,70,0),(123,1,1,60,'2016-01-01','16:22:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,71,0),(124,1,1,10,'2016-01-01','16:22:00',10,0,1,1,2,1,'',1,'1/1',0,0,0,'',5,1,1,NULL,71,0),(126,1,1,60,'2016-01-01','16:26:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,73,0),(127,1,1,30,'2016-01-01','16:27:00',30,0,1,1,2,1,'',2,'1/1,2/1',0,0,0,'',15,1,1,NULL,73,0),(130,1,1,60,'2016-01-01','16:29:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,74,0),(129,1,1,60,'2016-01-01','16:29:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,74,0),(132,1,1,60,'2016-01-01','18:04:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,75,0),(133,1,1,139.99,'2016-01-01','19:01:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,75,0),(143,1,1,50,'2016-01-01','20:29:00',50,0,1,1,2,1,'',2,'2/1,3/1',0,0,0,'',25,1,1,NULL,80,0),(136,1,1,139.99,'2016-01-01','19:39:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,77,0),(137,1,1,60,'2016-01-01','19:49:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,77,0),(141,1,1,129.99,'2016-01-01','20:27:00',160,30.00999999999999,1,1,2,1,'',3,'2/1,3/1,4/1',0,0,0,'',64.995,1,1,NULL,79,0),(145,1,1,30,'2016-01-01','21:37:00',30,0,1,1,2,1,'',1,'3/1',0,0,0,'',15,1,1,NULL,81,0),(146,1,1,50,'2016-01-01','21:38:00',50,0,1,1,2,1,'',2,'2/1,3/1',0,0,0,'',25,1,1,NULL,81,0),(147,1,1,50,'2016-01-01','21:38:00',50,0,1,1,2,1,'',2,'2/1,3/1',0,0,0,'',25,1,1,NULL,81,0),(150,1,1,30,'2016-01-02','12:54:00',30,0,1,1,2,1,'',2,'1/1,2/1',0,0,0,'',15,1,1,NULL,82,0),(149,1,1,60,'2016-01-02','12:53:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,82,0),(155,1,1,60,'2016-01-03','19:50:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,84,0),(152,1,1,60,'2016-01-03','15:10:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,83,0),(154,1,1,60,'2016-01-03','19:50:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,84,0),(156,1,1,30,'2016-01-03','19:53:00',30,0,1,1,2,1,'',2,'1/1,2/1',0,0,0,'',15,1,1,NULL,84,0),(165,2,1,27,'2016-01-03','22:33:00',27,0,3,1,8,1,'',3,'1234567890123/3',0,3,10,'',12,1,1,NULL,89,0),(158,1,1,60,'2016-01-03','19:55:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,85,0),(164,2,1,18,'2016-01-03','22:33:00',18,0,3,1,8,1,'',2,'1234567890123/2',0,2,10,'',8,1,1,NULL,89,0),(160,1,1,60,'2016-01-03','20:02:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,86,0),(163,1,1,60,'2016-01-03','22:27:00',0,0,1,37201216,1,1,'NA',6,'1234567890123/6',0,0,0,'NA',30,1,1,NULL,88,2.1408614505e-314),(166,2,1,27,'2016-01-03','22:35:00',27,0,1,1,2,1,'',3,'1234567890123/3',0,3,10,'',12,1,1,NULL,89,0),(167,2,1,18,'2016-01-03','22:36:00',18,0,3,1,8,1,'',2,'1234567890123/2',0,2,10,'',8,1,1,NULL,89,0),(168,2,1,108,'2016-01-03','22:39:00',108,0,3,1,8,1,'',4,'1234567890123/1,4/1,1234/3,987654321123/1',0,12,10,'',8.005000000000003,1,1,NULL,89,0),(173,1,1,59,'2016-01-04','16:27:00',60,1,1,1,2,1,'',4,'1234567890123/1,1234/0.3,987654321123/2',0,0,0,'',29.5,1,1,NULL,92,0),(171,1,1,60,'2016-01-04','10:19:00',60,0,1,1,2,1,'',3,'1234567890123/1,1234/1,987654321123/1',0,0,0,'',30,1,1,NULL,91,0),(174,1,1,10,'2016-01-04','16:29:00',10,0,2,2,2,1,'***************9999',1,'1234567890123/1',0,0,0,'-999999999',5,1,1,NULL,92,0),(175,1,1,73,'2016-01-04','16:57:00',73,0,1,1,2,1,'',5,'1234567890123/1,1234/0.1,987654321123/3',0,0,0,'',36.5,1,1,NULL,92,0),(177,1,1,60,'2016-01-05','10:52:00',60,0,1,1,2,1,'',4,'1234567890123/1,4/1,1234/1,987654321123/1',0,0,0,'',-9.994999999999997,1,1,NULL,93,0);
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactionstates`
--

DROP TABLE IF EXISTS `transactionstates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transactionstates` (
  `stateid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`stateid`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactionstates`
--

LOCK TABLES `transactionstates` WRITE;
/*!40000 ALTER TABLE `transactionstates` DISABLE KEYS */;
INSERT INTO `transactionstates` VALUES (1,'Not Completed'),(2,'Completed'),(3,'Cancelled'),(4,'PO Pending'),(5,'PO Completed'),(6,'PO Incomplete'),(7,'Reservation'),(8,'Internal Credit'),(9,'Internal Credit');
/*!40000 ALTER TABLE `transactionstates` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactiontypes`
--

DROP TABLE IF EXISTS `transactiontypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transactiontypes` (
  `ttypeid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `text` varchar(50) NOT NULL,
  PRIMARY KEY (`ttypeid`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactiontypes`
--

LOCK TABLES `transactiontypes` WRITE;
/*!40000 ALTER TABLE `transactiontypes` DISABLE KEYS */;
INSERT INTO `transactiontypes` VALUES (1,'Sell'),(2,'Purchase'),(3,'Change'),(4,'Return');
/*!40000 ALTER TABLE `transactiontypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL DEFAULT '',
  `password` varchar(50) DEFAULT NULL,
  `salt` varchar(5) DEFAULT NULL,
  `name` varchar(255) DEFAULT '',
  `address` varchar(255) DEFAULT NULL,
  `phone` varchar(50) DEFAULT NULL,
  `phone_movil` varchar(50) DEFAULT NULL,
  `role` int(10) unsigned DEFAULT '0',
  `photo` blob,
  PRIMARY KEY (`id`),
  KEY `SEC` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'admin','C07B1E799DC80B95060391DDF92B3C7EF6EECDCB','h60VK','Administrador','','','',2,NULL);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `v_groupedSO`
--

DROP TABLE IF EXISTS `v_groupedSO`;
/*!50001 DROP VIEW IF EXISTS `v_groupedSO`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `v_groupedSO` (
  `orderid` tinyint NOT NULL,
  `name` tinyint NOT NULL,
  `groupElements` tinyint NOT NULL,
  `qty` tinyint NOT NULL,
  `price` tinyint NOT NULL,
  `cost` tinyint NOT NULL,
  `units` tinyint NOT NULL,
  `status` tinyint NOT NULL,
  `saleid` tinyint NOT NULL,
  `notes` tinyint NOT NULL,
  `payment` tinyint NOT NULL,
  `completePayment` tinyint NOT NULL,
  `dateTime` tinyint NOT NULL,
  `deliveryDateTime` tinyint NOT NULL,
  `clientId` tinyint NOT NULL,
  `userId` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Temporary table structure for view `v_transS`
--

DROP TABLE IF EXISTS `v_transS`;
/*!50001 DROP VIEW IF EXISTS `v_transS`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `v_transS` (
  `id` tinyint NOT NULL,
  `userid` tinyint NOT NULL,
  `clientid` tinyint NOT NULL,
  `date` tinyint NOT NULL,
  `time` tinyint NOT NULL,
  `state` tinyint NOT NULL,
  `itemslist` tinyint NOT NULL,
  `terminalnum` tinyint NOT NULL,
  `itemcount` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Temporary table structure for view `v_transactionitems`
--

DROP TABLE IF EXISTS `v_transactionitems`;
/*!50001 DROP VIEW IF EXISTS `v_transactionitems`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `v_transactionitems` (
  `datetime` tinyint NOT NULL,
  `id` tinyint NOT NULL,
  `points` tinyint NOT NULL,
  `name` tinyint NOT NULL,
  `price` tinyint NOT NULL,
  `disc` tinyint NOT NULL,
  `total` tinyint NOT NULL,
  `clientid` tinyint NOT NULL,
  `userid` tinyint NOT NULL,
  `date` tinyint NOT NULL,
  `time` tinyint NOT NULL,
  `position` tinyint NOT NULL,
  `product_id` tinyint NOT NULL,
  `cost` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Temporary table structure for view `v_transactions`
--

DROP TABLE IF EXISTS `v_transactions`;
/*!50001 DROP VIEW IF EXISTS `v_transactions`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `v_transactions` (
  `datetime` tinyint NOT NULL,
  `id` tinyint NOT NULL,
  `clientid` tinyint NOT NULL,
  `userid` tinyint NOT NULL,
  `itemcount` tinyint NOT NULL,
  `disc` tinyint NOT NULL,
  `amount` tinyint NOT NULL,
  `date` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Temporary table structure for view `v_transactionsbydate`
--

DROP TABLE IF EXISTS `v_transactionsbydate`;
/*!50001 DROP VIEW IF EXISTS `v_transactionsbydate`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `v_transactionsbydate` (
  `date` tinyint NOT NULL,
  `transactions` tinyint NOT NULL,
  `items` tinyint NOT NULL,
  `total` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `v_groupedSO`
--

/*!50001 DROP TABLE IF EXISTS `v_groupedSO`*/;
/*!50001 DROP VIEW IF EXISTS `v_groupedSO`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `v_groupedSO` AS select `special_orders`.`orderid` AS `orderid`,`special_orders`.`name` AS `name`,`special_orders`.`groupElements` AS `groupElements`,`special_orders`.`qty` AS `qty`,`special_orders`.`price` AS `price`,`special_orders`.`cost` AS `cost`,`special_orders`.`units` AS `units`,`special_orders`.`status` AS `status`,`special_orders`.`saleid` AS `saleid`,`special_orders`.`notes` AS `notes`,`special_orders`.`payment` AS `payment`,`special_orders`.`completePayment` AS `completePayment`,`special_orders`.`dateTime` AS `dateTime`,`special_orders`.`deliveryDateTime` AS `deliveryDateTime`,`special_orders`.`clientId` AS `clientId`,`special_orders`.`userId` AS `userId` from `special_orders` group by `special_orders`.`saleid` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `v_transS`
--

/*!50001 DROP TABLE IF EXISTS `v_transS`*/;
/*!50001 DROP VIEW IF EXISTS `v_transS`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `v_transS` AS select `transactions`.`id` AS `id`,`transactions`.`userid` AS `userid`,`transactions`.`clientid` AS `clientid`,`transactions`.`date` AS `date`,`transactions`.`time` AS `time`,`transactions`.`state` AS `state`,`transactions`.`itemslist` AS `itemslist`,`transactions`.`terminalnum` AS `terminalnum`,`transactions`.`itemcount` AS `itemcount` from `transactions` where ((`transactions`.`state` = 1) and (`transactions`.`type` = 1) and (`transactions`.`itemcount` > 0)) order by `transactions`.`id` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `v_transactionitems`
--

/*!50001 DROP TABLE IF EXISTS `v_transactionitems`*/;
/*!50001 DROP VIEW IF EXISTS `v_transactionitems`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `v_transactionitems` AS select concat(date_format(`t`.`date`,'%d/%m/%Y'),' ',time_format(`t`.`time`,'%H:%i')) AS `datetime`,`t`.`id` AS `id`,`ti`.`points` AS `points`,`ti`.`name` AS `name`,`ti`.`price` AS `price`,`ti`.`disc` AS `disc`,`ti`.`total` AS `total`,`t`.`clientid` AS `clientid`,`t`.`userid` AS `userid`,`t`.`date` AS `date`,`t`.`time` AS `time`,`ti`.`position` AS `position`,`ti`.`product_id` AS `product_id`,`ti`.`cost` AS `cost` from (`transactions` `t` join `transactionitems` `ti`) where ((`t`.`id` = `ti`.`transaction_id`) and (`t`.`type` = 1) and (`t`.`state` = 2)) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `v_transactions`
--

/*!50001 DROP TABLE IF EXISTS `v_transactions`*/;
/*!50001 DROP VIEW IF EXISTS `v_transactions`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `v_transactions` AS select concat(date_format(`t`.`date`,'%d/%m/%Y'),' ',time_format(`t`.`time`,'%H:%i')) AS `datetime`,`t`.`id` AS `id`,`t`.`clientid` AS `clientid`,`t`.`userid` AS `userid`,`t`.`itemcount` AS `itemcount`,`t`.`disc` AS `disc`,`t`.`amount` AS `amount`,`t`.`date` AS `date` from `transactions` `t` where ((`t`.`type` = 1) and (`t`.`state` = 2)) order by concat(date_format(`t`.`date`,'%d/%m/%Y'),' ',time_format(`t`.`time`,'%H:%i')) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `v_transactionsbydate`
--

/*!50001 DROP TABLE IF EXISTS `v_transactionsbydate`*/;
/*!50001 DROP VIEW IF EXISTS `v_transactionsbydate`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `v_transactionsbydate` AS select `transactions`.`date` AS `date`,count(1) AS `transactions`,sum(`transactions`.`itemcount`) AS `items`,sum(`transactions`.`amount`) AS `total` from `transactions` where ((`transactions`.`type` = 1) and (`transactions`.`itemcount` > 0) and (`transactions`.`state` = 2)) group by `transactions`.`date` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-01-05 13:54:11
