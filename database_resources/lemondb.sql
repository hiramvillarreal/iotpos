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
) ENGINE=MyISAM AUTO_INCREMENT=59 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `balances`
--

LOCK TABLES `balances` WRITE;
/*!40000 ALTER TABLE `balances` DISABLE KEYS */;
INSERT INTO `balances` VALUES (1,'2015-12-28 12:11:06','2015-12-28 12:11:06',0,'',0,0,0,0,0,'',1,'',0),(2,'2015-12-28 12:11:06','2015-12-28 12:11:06',1,'admin',0,0,0,0,0,'',1,'',0),(3,'2015-12-28 12:11:06','2015-12-28 12:11:06',1,'admin',0,0,0,0,0,'',1,'',0),(4,'2015-12-28 12:16:08','2015-12-28 12:16:08',1,'admin',0,0,0,0,0,'',1,'',0),(5,'2015-12-28 12:16:08','2015-12-28 12:16:08',1,'admin',0,0,0,0,0,'',1,'',0),(6,'2015-12-28 12:22:52','2015-12-28 12:25:32',1,'admin',100,120,0,220,0,'4,5',1,NULL,1),(7,'2015-12-28 12:36:21','2015-12-28 21:54:11',1,'admin',100,60,0,160,0,'7',1,NULL,1),(8,'2015-12-28 22:05:11','2015-12-28 22:09:54',1,'admin',100,0,0,100,0,'',1,NULL,1),(9,'2015-12-28 22:10:11','2015-12-28 22:13:26',1,'admin',100,180,0,280,0,'10,11,12',1,NULL,1),(10,'2015-12-28 22:22:07','2015-12-28 22:22:49',1,'admin',100,60,0,160,0,'15',1,NULL,1),(11,'2015-12-28 22:23:17','2015-12-28 22:23:58',1,'admin',100,0,0,100,0,'',1,NULL,1),(12,'2015-12-28 22:32:35','2015-12-28 22:32:40',1,'admin',100,0,0,100,0,'',1,NULL,1),(13,'2015-12-28 22:32:52','2015-12-28 22:32:52',1,'admin',100,0,0,100,0,'',1,'',0),(14,'2015-12-28 22:32:52','2015-12-28 22:34:22',1,'admin',100,0,0,100,0,'',1,NULL,1),(15,'2015-12-28 22:34:41','2015-12-28 22:34:51',1,'admin',100,60,0,160,0,'21',1,NULL,1),(16,'2015-12-28 22:38:38','2015-12-28 22:38:58',1,'admin',100,60,0,160,0,'23',1,NULL,1),(17,'2015-12-28 22:43:57','2015-12-28 22:44:54',1,'admin',100,60,0,160,0,'25',1,NULL,1),(18,'2015-12-28 22:45:56','2015-12-28 22:46:52',1,'admin',100,60,0,160,0,'27',1,NULL,1),(19,'2015-12-29 10:07:01','2015-12-29 10:07:31',1,'admin',100,10,0,110,0,'29',1,NULL,1),(20,'2015-12-29 10:11:16','2015-12-29 11:51:40',1,'admin',100,190,0,290,0,'31,32,33,34',1,NULL,0),(21,'2015-12-29 13:00:38','2015-12-29 13:00:38',1,'admin',0,0,0,0,0,'',1,'',0),(22,'2015-12-29 17:36:30','2015-12-29 17:36:56',1,'admin',100,60,0,160,0,'36',1,NULL,1),(23,'2015-12-29 17:37:20','2015-12-29 17:37:20',1,'admin',100,0,0,100,0,'',1,NULL,0),(24,'2015-12-29 17:37:20','2015-12-29 17:37:41',1,'admin',100,60,0,160,0,'39',1,NULL,1),(25,'2015-12-29 17:38:21','2015-12-29 17:39:32',1,'admin',100,60,0,160,0,'41',1,NULL,1),(26,'2015-12-29 17:40:25','2015-12-29 17:40:55',1,'admin',100,60,0,160,0,'43',1,NULL,1),(27,'2015-12-29 18:56:30','2015-12-29 18:56:37',1,'admin',100,0,0,100,0,'',1,NULL,1),(28,'2015-12-29 18:57:01','2015-12-29 18:57:13',1,'admin',100,60,0,160,0,'46',1,NULL,1),(29,'2015-12-29 19:00:15','2015-12-29 19:00:28',1,'admin',100,60,0,160,0,'48',1,NULL,1),(30,'2015-12-29 19:35:35','2015-12-29 19:35:46',1,'admin',100,60,0,160,0,'50',1,NULL,1),(31,'2015-12-29 19:36:18','2015-12-29 19:36:18',1,'admin',100,0,0,100,0,'',1,'',0),(32,'2015-12-29 19:36:18','2015-12-29 19:37:31',1,'admin',100,60,0,160,0,'53',1,NULL,1),(33,'2015-12-29 19:38:09','2015-12-29 19:38:33',1,'admin',100,60,0,160,0,'55',1,NULL,1),(34,'2015-12-29 19:41:24','2015-12-29 19:41:38',1,'admin',100,60,0,160,0,'57',1,NULL,1),(35,'2015-12-29 19:42:06','2015-12-29 19:42:06',1,'admin',100,0,0,100,0,'',1,'',0),(36,'2015-12-29 19:42:06','2015-12-29 19:49:02',1,'admin',100,60,0,160,0,'60',1,NULL,1),(37,'2015-12-29 19:53:45','2015-12-29 19:54:08',1,'admin',100,60,0,160,0,'62',1,NULL,1),(38,'2015-12-29 19:55:52','2015-12-29 19:56:07',1,'admin',100,60,0,160,0,'64',1,NULL,1),(39,'2015-12-29 19:58:54','2015-12-29 19:59:26',1,'admin',100,120,0,220,0,'66,67',1,NULL,1),(40,'2015-12-29 20:01:50','2015-12-29 21:07:01',1,'admin',100,100,30,170,0,'69',1,NULL,1),(41,'2015-12-30 00:15:58','2015-12-30 00:43:22',1,'admin',100,0,0,100,0,'',1,NULL,1),(42,'2015-12-30 00:54:31','2015-12-30 00:54:31',1,'admin',100,0,0,100,0,'',1,NULL,0),(43,'2015-12-30 00:54:31','2015-12-30 01:22:33',1,'admin',100,0,0,100,0,'',1,NULL,1),(44,'2015-12-30 10:41:14','2015-12-30 10:42:15',1,'admin',100,0,0,100,0,'',1,NULL,1),(45,'2015-12-30 11:10:14','2015-12-30 11:14:08',1,'admin',100,80,5,175,0,'75,76',1,NULL,1),(46,'2015-12-30 11:20:30','2015-12-30 11:22:52',1,'admin',100,60,1,159,0,'78',1,NULL,1),(47,'2015-12-30 12:07:10','2015-12-30 12:15:29',1,'admin',100,0,0,100,0,'',1,NULL,1),(48,'2015-12-30 12:20:54','2015-12-30 12:27:08',1,'admin',100,60,12,148,0,'81',1,NULL,1),(49,'2015-12-30 13:36:00','2015-12-30 13:36:12',1,'admin',100,60,0,160,0,'83',1,NULL,1),(50,'2015-12-30 21:34:41','2015-12-30 21:35:34',1,'admin',100,0,0,100,0,'',1,NULL,1),(51,'2015-12-30 22:01:14','2015-12-30 22:05:30',1,'admin',100,0,0,100,0,'',1,NULL,1),(52,'2015-12-30 22:05:55','2015-12-30 22:06:21',1,'admin',100,140,0.009999999999990905,239.99,0,'88',1,NULL,1),(53,'2015-12-30 23:44:08','2015-12-30 23:44:19',1,'admin',100,60,0,160,0,'90',1,NULL,1),(54,'2015-12-30 23:44:49','2015-12-30 23:45:11',1,'admin',100,60,0,160,0,'92',1,NULL,1),(55,'2015-12-30 23:48:19','2015-12-30 23:48:37',1,'admin',100,80,0.010000000000005116,179.99,0,'94',1,NULL,1),(56,'2015-12-30 23:49:11','2015-12-30 23:49:35',1,'admin',100,80,0.010000000000005116,179.99,0,'96',1,NULL,1),(57,'2015-12-30 23:50:14','2015-12-30 23:50:31',1,'admin',100,80,0.010000000000005116,179.99,0,'98',1,NULL,1),(58,'2015-12-31 00:07:27','2015-12-31 00:08:23',1,'admin',100,45,0,145,0,'100',1,NULL,1);
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cashflow`
--

LOCK TABLES `cashflow` WRITE;
/*!40000 ALTER TABLE `cashflow` DISABLE KEYS */;
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
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clients`
--

LOCK TABLES `clients` WRITE;
/*!40000 ALTER TABLE `clients` DISABLE KEYS */;
INSERT INTO `clients` VALUES (1,'000001','General','2009-01-01',NULL,NULL,NULL,0,0,NULL);
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
INSERT INTO `config` VALUES ('yes, it is February 6 1978',0,'','IotPOS store','','',1,0,1,'0950');
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `credit_history`
--

LOCK TABLES `credit_history` WRITE;
/*!40000 ALTER TABLE `credit_history` DISABLE KEYS */;
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `credits`
--

LOCK TABLES `credits` WRITE;
/*!40000 ALTER TABLE `credits` DISABLE KEYS */;
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
) ENGINE=MyISAM AUTO_INCREMENT=67 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `logs`
--

LOCK TABLES `logs` WRITE;
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
INSERT INTO `logs` VALUES (1,1,'2015-12-28','12:21','[SQUEEZE] Purchase #1 - 100 x Producto1 (1)'),(2,1,'2015-12-28','12:21','[SQUEEZE] Purchase #2 - 100 x Producto2 (2)'),(3,1,'2015-12-28','12:22','[SQUEEZE] Purchase #3 - 0 x Producto3 (3)'),(4,1,'2015-12-28','12:22','[SQUEEZE] CorreciÃ³n de Inventario: [3] de 0 a 100. RazÃ³n:Adjust'),(5,1,'2015-12-28','12:22','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(6,1,'2015-12-28','12:36','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(7,1,'2015-12-28','22:05','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(8,1,'2015-12-28','22:10','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(9,1,'2015-12-28','22:22','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(10,1,'2015-12-28','22:22','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:22'),(11,1,'2015-12-28','22:22','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:22'),(12,1,'2015-12-28','22:23','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(13,1,'2015-12-28','22:23','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:23'),(14,1,'2015-12-28','22:32','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(15,1,'2015-12-28','22:32','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(16,1,'2015-12-28','22:32','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:32'),(17,1,'2015-12-28','22:33','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:33'),(18,1,'2015-12-28','22:34','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(19,1,'2015-12-28','22:38','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(20,1,'2015-12-28','22:43','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(21,1,'2015-12-28','22:44','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:44'),(22,1,'2015-12-28','22:44','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:44'),(23,1,'2015-12-28','22:44','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:44'),(24,1,'2015-12-28','22:45','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(25,1,'2015-12-28','22:46','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-28 22:46'),(26,1,'2015-12-29','10:07','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(27,1,'2015-12-29','10:07','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 10:07'),(28,1,'2015-12-29','10:11','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(29,1,'2015-12-29','17:36','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(30,1,'2015-12-29','17:37','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(31,1,'2015-12-29','17:38','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(32,1,'2015-12-29','17:40','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(33,1,'2015-12-29','18:56','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(34,1,'2015-12-29','18:57','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(35,1,'2015-12-29','19:00','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(36,1,'2015-12-29','19:35','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(37,1,'2015-12-29','19:36','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(38,1,'2015-12-29','19:36','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:36'),(39,1,'2015-12-29','19:36','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:36'),(40,1,'2015-12-29','19:37','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:37'),(41,1,'2015-12-29','19:38','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(42,1,'2015-12-29','19:38','[ LEMON ] Reporte de Fin del dÃ­a impreso por Administrator en terminal 1 el 2015-12-29 19:38'),(43,1,'2015-12-29','19:41','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(44,1,'2015-12-29','19:42','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(45,1,'2015-12-29','19:53','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(46,1,'2015-12-29','19:55','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(47,1,'2015-12-29','19:58','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(48,1,'2015-12-29','20:01','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(49,1,'2015-12-30','00:15','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(50,1,'2015-12-30','00:54','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(51,1,'2015-12-30','10:41','[ LEMON ] Operaciones iniciadas por Administrator en terminal 1'),(52,1,'2015-12-30','11:10','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(53,1,'2015-12-30','11:20','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(54,1,'2015-12-30','12:07','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(55,1,'2015-12-30','12:20','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(56,1,'2015-12-30','13:36','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(57,1,'2015-12-30','21:34','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(58,1,'2015-12-30','22:01','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(59,1,'2015-12-30','22:05','[SQUEEZE] Purchase #87 - 1 x Paquete1 (4)'),(60,1,'2015-12-30','22:05','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(61,1,'2015-12-30','23:44','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(62,1,'2015-12-30','23:44','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(63,1,'2015-12-30','23:48','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(64,1,'2015-12-30','23:49','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(65,1,'2015-12-30','23:50','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1'),(66,1,'2015-12-31','00:07','[ LEMON ] Operaciones iniciadas por Administrador en terminal 1');
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
INSERT INTO `products` VALUES (1,'Producto1',10,47,5,53,'2015-12-31',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0–\0\0\0H\0\0\05½\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0‰\0\0‰7\ÉË­\0\0hIDATxœ\í}h$\ç}\Ç?*kx&(e”d.®7u\è\í\ÕKu \Ú\Æ4\'“ÀI\Ä!Z,\ê\Û&\à>\Z\ï\Ù49ÙqW‰‹-§p¶œö\ìu F\çrF2Øœ\îs{©`#\âj]rdLs0\Ì\Ðn;x@ýã™™·Õ½\îž\í\î\Ä\î\Î>;o\Ïw~/\ß\ßoF0À\00À\00À\00À\00À\0}\Ý\ì gø¬_›@´˜/\Þ%l¶L6¤Ó—9\Ïõc#ô\ÇEq×¸£€}\ÉBŒ¬_\Ü\ì\ë>üA_·6@¯¡.\íŠýE6×“û\nl]\ÚFJ‰ôú·#‹õñ…®C\Ù@›D? \ßV % ñþ&H‰6Ò“ØžT¿^û€±>Ú¸58\\€¿)!>g 2	¡!nËƒ\Ðh\\\ÚÆ–K:Y\Ãu ó‹‰±n>nðWÀ:£2	¡AN 0,\Ð†p%\Òs‘Ž­\Þï½½/\0=¸\Ä\ê=>\ìð\×Àƒ \È#\0- \rŠHB„\Ð(\äúˆŽ\æ\Çõ$RºH¤”¸m‰\åI\ØQ†G1\ÜY—\0\\$z†…\Ë\ç\Äý-OöœX¹\á\Æ@¾$\à)\àÏƒ\é\ÈL¶@9¼®£‘KÛ–[\ãùVHJ¤”\ê»`™§\Þˆa`\è:\"›Ò¡\Ù2C²&!&²\çó>°XWŽ\Ï\nøðC\n·e \\“† /š\ÐÐ…Ž\ÈB@\Î\é)‚8m—–”¸˜H)Ž5BP\Ð\r\È	\\)‘\Ò\îXªÌž\\\Ä\È\0Ã‚…\É\n†´q% t4\å2=‰Œ\ìc€\ì(\í\Æc`±\â¸UÀ1\àa@$-Ž\"QŒ<º\0¡)\ÒWJœ¶­,M\Û\'N—t\ßE¢!p‘H$=\ÈiTž^@Œ\è\àÁ\ât…c§\ëˆ\\6-gª†uŒaÓ“l:xR¹×Œñ[‹u\Ãqð³À£Á\ÂL\åú°²8B¨÷\ä@ó\'×•Gº˜­x‹“…€<Á{#_`ô\Ð\Åñq\Z/\Ô1µ\ÅÜ™\åpü\âLUÍŒ”‰\ìJ*€‰ªl½²‚+$\Âs9pú¨Ye\á“H¬O÷ø\äùVô‹ \ÖeyDNP\È	DN\Ã\Ðuôaõ\âñµ\ã`\íX\Ê\âxq\Ëµ8$’Ò\ãŒMOQ¸­ˆ\Ö\Õ\ïÚ’ú\Ñ\Z³\'Ã±•\'\æXš™Ez„ñ–¡\ë\á\Ì\Ø-›ÙŸt\Æ1\×\nP¾ÿ0?_ñ×¡2]a¿ðq%–Ü$OfÐœZ]\×\Õ\É\Ï\ÃN[\âJ‰\í8!¡¸€F\Úê€²^•ó!y§+hˆ˜õB]ƒ\î(\\d<ˆoKt=l;\Ô:#\"(\×X\Ø_¢ú\ä<\0\Òñe)/\Ø\Û=}J?\ÊÄºUÀðC\à\Ö\èQË£!\Ðs‚Â°  Œ˜\ÛÀG*²¸R\âî´’)\â\Ø8„r?ˆ\Ð\Z;]G=œ”Å™*®\')\î/ù\ÛQ1ˆ\î“\çIE\"]\ïe\á\ìcD\É\ÒsT\æ\ç\Çm¿Xfò±¹Øªœ‹fì³‹Dx‘S\çD\"S’CÄ‚õ\\$\í%±n\É\ç\Ä\ì\Ôí¥Ÿ\è8H\éb#YÃ™r`ˆ²,\àsÁTH\Ò\"_h}„zž†Ó¶•%\Z\îL¦\Ýv°§÷DRó\Ð\Òød‰¾–\ï¯Rþöd|›º\Î\Â7¦\0\å’\nûöv,cwc¾\ÛL“Jšo5\Ø<·À³“j§\ë\á\×\ÕG”8V\Å{+¡…\Ü~w‹\èžö—°\Þo\Æ~£\á“\Ù\Ó\Ð;cÿ‚½\Ï\ç\Ä_¶<ùO{\Ìu¢\'\ÙÁ8bWó¿\Âm*5f\Ä ÿ™<†\å`^4‘žÄ•.\02¤·\æ_¤Jð2¬Že‰\ÉIr$\ã\'ý\æ$FÞˆY„`ñ\ÞJ°Ejo,«@99Á\ât•\â%*Ot¬\Æ\æ[\r\Z/Ö™[]	\×k\ï\Ø\Ôš£ú´rgª±ý¨©\Ç6c;6†n„\ãƒ}Ž%\æ^s‚¥\é*\ìv+T\Ê4@X@S:™™¡Pò\Ço´[˜}À7=\énhÁkÐ¥\Ä}_™lwÇ¦õ;S	}ºŽ›Èœ†ƒ\"Š\ÓV)º\Óv‘\Ò\ÆlYX-“ÖŽ…Ó¶±\ÚN[‘\ÌEbû–¼t¨\Ì\ì\ÉEfO/1·ºBmUMÀÜ™e&¿7Ka_AeTQ+\"%sþ8ÙT\àÿNbþj+¶øÀÁ²\"Id\Ö4\Ý@š\Zñ±_-\Ç>»H¬„+\Ór\ØH&\ìµ¸\×\È>>¹€\Ûv0\Ð}²\Ê\Èøl#ŒŸ\î2ä†¡\'\Ä2‘ÿ=5öû&\Z`;Í¶…\å´|\Ù)}\' ™-µ|X0þ@…\Ùž§v¦\îJ0ÿ\ÆY\æ\Î,3ñÀ,F>BÏ$\Ä\Þn/= ¬\Åò\æcË²Æ‰œ²&v„ B¨e›o­\ÇÆŽNO§¬\êòó\ÉUv\Ö‰\í‚\×\åDŒe\äÌ­­¤~+=bNt\Ïû™!öªk3P¢ƒ\"ªy\ÑÄ‘Ç‘a0@\èjLñ`™Ú™:µ\Õe\æ\Î,«\àS7;4¶cw23»\ê M\éIŽŸ\Ú\â¾Rjœ¦ë˜—\âñK\é\ÎqR\Ó\â[\æ\ÛyŠÒ‹\Ç\ÅF¾é²£\Ã{O»s\ÑJ_,mIm-ž\Êð\â\ê^Œ\îG_V\Ï\Zý”]Q¨Bªë¸¸\ÒU\ïý\ÃvsP\Ã\Ì-¿6\Zq[NËŠ­wü\È, °.\Æ\'_Œm\Éúk+€`óõ\Õ\Ø÷gŸ~ž\Å\ÉJlYùþ\é\Ô~÷H\é\Õc‡¦ü\Ä\Ý@ó\í\ØX‰¡z:û6Ü‰•òw–\"\Ë\ã\ã’\ëI’qñ\Þj&¹¿°Hx¶= \r\Â\ëÄ¡!öYo4zF,þYžl«4Zz‘«É“L|G«8ñkL\"q–ª“É¸¥\0V;NýHõ\×VIã•¸›8pw™¤\Õ)œPzWd‚Ç\îð­ˆl\Û\ê2b1;A|•\æŸD)™;£¬p\Å×ž\\$õ£\ÇR\ë\Û\Z„IGÆˆÁ\Ä•p½n†­\n: ´Žó©«\ÚøU¢g\Ä*øq‚_)—«˜*~5¹þ\Ä%OHñö´«\n,…™ –²d\éqò_ò\×¹â¥§Hµ:†n ‘,\ÍÌ²8Yeif–³\ÏÕ•Æ• \Ñ|£‘C•\ÛLo¿³_·\Î%+sH\ÒM&±43‹ùN¼óe\ìÐ¤\"4ñ€œ@\Ë‚±Z¤\Ã\×ö\Ü\Èu¢g\Äð®›ö¦\Ñ\Ü\Øb\âA\åâ¢˜8\ê“%h,§[M\ï³`\ìS–Nˆ¸%\É\Ú3qe{þÌŠ÷E•5\Øz+ž\íÉ41\Ê3\Êr\Ø;YJ!\áB)!#\É\ØKF	^Wžy3¡e¸«’RÏ©’•¤C&%Õ¸\àø=DÏˆµ†st/REE\Ð\æ…²\íŠ¨x\ç(@*\æq}U<¶¾¶žø\Ì+\Þ_ó\ÂF\ê+\×KwÌžZ\Â\Èb“Ù¼°žúm\ÆmŠÀ\æ;ñ\í\Ô™cq¦\ZjT\Ö~òl|¹.ûŒš\àð\ÉŽ^f\â*k\'c\à\èL%V*\è\Ê\ÅKÏq=\ÕmaK‰žG/{0×žKÂ–£^Ãºd§¼v\Ëb\ë\Õ’Ùžl«  \Ë «ºÊºÁ\Ô\Ã5Š£÷ºþºR\Â5\Ï®¦\ÆÏž\\\äÀÁ‰\Î~¶[©1\æV3t\í€b­sq\ë$\nI\Òlÿ[š¬Y1’‹ŒH+p\àë“ŠD‘ø0\èÓŠ\É7€Äµa]vw\Õ7=½ý+~‚²{ƒ@Py|>ÛŒº@²y\îl\ì\ÆHQ\Å	7r\ìô2µ7–™||NmOg]¥»#BeN°þj<>JZ€\É\ï\ÍRü\ê˜q¤%‡•§07\"ñŽ?aV+.€¿<vY\É!ø}Ö¸¤H\ZX%ó½Ž;Œe™II!B¦~\ä†=%V4p\Ô\àh9P[¥ZC°\é[‘\0Ú° P:[6ùÀa%¸~q„\ß\ÃTøb˜\ï\Æ\Õò<™\n¼53\é¬kò‘Z\ç\"É¶±—:Î„N%ºK\æV<VÊŠ©\\V\Æ\'\ÖÖ›‘óIŠ\nû‹è¾šŸe{žß°\Z?¤.6\Ë\èT\ã­D\æU{¹ž*¿<†‹¤µ•M1¢&±ñr¼\×\ÜXO\ÕÕŸ,\Ä&P\äJh>³§ž\ïºÿf¢<#»X£nÁx\Ò\"gAC`;‘}÷ü$f+}_D\å\Ñ\ãL>Rƒ¶6ö›Z}¹ZMX\Új	ÿ\Ó\æ¹\åC“ª;ó\n}¿†`3Q“#\Ö%‹\å(Wh&DTû’Eý¡xi¤pG)\Ó5-N\Ç-WP ¶/¥u«\ä>ô¼ ië–…V‚˜\Ý`¾¿jk\ËÌžZJ[~\æÇª\0­n+\ìEªžiY=\'V\Ðt—|\ßù¬–•\îž@:!.‡\\v!!XþÁ<\ÖEU›L)\èßžJ¯\Ë/jÏ¯\rKIó«g‘QúHg{\Å}¥”u*ß§²3¹/\ít_\Üv|œ¦g»\ÍÆ‹qdº,ŸôµS/a\ÜV¤|´šº:ûþ$ó\Ë€žË‚Çƒ8«\ÛU\ãAè¯›>!\âd¡\ë,\ÎT÷L´³:¹:Pn![;j^ht¬Š\ßÑt3\Z‚\×\âŠþ\äc5\\\âsñ J¶7\â_\åû\Çy\ßX‰—a˜Nœ£X:R\Ë\\\ÞxuÅ·\Ôpú\è‹÷VX9± iâŠœ¤¯u\Ý\Ðu¢§\Äj!OB\'ˆ:ùAšP²ùöz,; \Û\Z‚\æ»W.9\ì™uA¬{3Àú««©e›o\Æ	\ÕHEPbrv:RD \Â6’Ci¼¬H+e(\Øf¡x\×h\×xŒ¶;0\Z¯,³t¤\Æ\âL•fD:‰ž\Ã\è\É\\XBüq\æ\Ü\0ô\ÚþoðFÒ©”ª¼±òÔ‚\"Ñ…¸\ä\à\"\Ù\\¸…|¶\äDRr\0hœŠ»‰Äº”ŽsR\ÊöWË™’D\n\èþ>©.‰øF\ãÍŠä”¥¶;ž\é%Œ·.™4\ßl¤\Üh\0Íb5¡š“ƒsJ‹\ËvT\\úþ#™ø\Â\É	®¶\Í\×\Ò\'¶õA|\â•\à(³ƒ\é’\rz\0›¿LX’ý£)\ë6õýZX0/•Hõz’Ã¹\ËKQòl¾Õ‘X\\$‹\Ó–\î­R?zŒ\ÆsõÔº®\Z G\Å\Ò\ÄE(†/s\ã\Åu\à¦\ÞL!„†ð\\uÿœ²Š³n\Â}•\î.sö—h½³…ñõŽ:n\èy\\\Ç	\'lý\ËTN\Ä	’œð©\'\æ¨·¦\ã[’\Òx¼\ë`\íÅ¥TKL€Prð\×!Q\í3KGjaûð^õ?¸²\Z\á^¿ ¾Rfû—\ëa¼HJ ç´žJ}Ö±\âP®@KY­(´,“\í\ë8›‰.‡ G\ßW x\ç(\Í÷\âk\ì›qM:ýRAð›ë’…\Ëö¬KŸ+\ë¢yJ¹_ºW\Õƒ±´\åeI \×B*‡\âWÆ¨>½ÀØ¡	\\ ø\åQu¹\à\ê\à»?=§©§\Öôý°X¿>\Ó\íK³ebä‹ˆ6¡\ÕJº¥ñû*4~žh\Ãõ%7•\î.‡¥\ë3\å\n\Ë÷U\Ø|³¿EËƒÊ“ó¬œX\È\ÜÇ•\'0\ß3C®~¤\ÖõŽ\ë…DªB´we\ä¾p\Ú8Y\ÇjYJ\êh\'/LeeÃŠGj:ý°X¯wûNC¨›)r\êS€\ä$}{Z\éR#+ƒ€I¨\Ì+1¬£›o®Â°@¶%\æ;›l®žEC¨>,¿aqFõc™\ï5‰Þ´\Ú\íõZ,\ÎñSK4l‹©g9¿kSo¬3‘aU÷:‡†n¨Š…\'iž;\ËÆ«\Ëº\ãÍ¼:%„ež\à\Ò#‘´\ç\Ä2‘ÿ¼\×÷p#7\0¨{y³\Ë!\Ö\Å\í\Ø2gOr¡½c³þú\ZõG\æX˜V\"i\ã\ç\Ë,NV¨©±òÌ³´~ÕŒ¹$È¾ÿðJÝ™D†ûw\ÜWÇƒ\ï\'¾Sa}\×U\Â\ì\Ñ*B\×9ë‹Ÿ£\ÇYX]¾\"X¼£D\íL\íw7UMu‰\â\Ýe¦Ÿ˜gô¾\nµS/ù²Œ>D\Üú[ø³\Ën\è\Z\ÐW¸\èW\Ý\àx.…=,VPok0q¼\Ô´ŽX›4\ß^§ùöV\Ë\ì\Ä8À\é‡\æ\ÂI\î\×Dƒ\"v°\ê\Ã5j\'\Zb\í7¿¥ñú*¥»\Ê,=1ù\ëM$\ì~ñ\å!\Ù\'\ç©û\îWC\Ðxõ4ó‡g)\ìÛ»i1\ØÇ©\Ç\æ°wl*\'\æ°ga|¾€¹±Nsck«I\ë¢Iiÿ(N\ËROŒ\ÂO”Š#úß›;\Î\×.»Á«\ÄM\Í\ncd\Ë\á\Ç2T²e \ÑøYy¡Á\Ú\ï[lÿru¼rk“S±‰&ûzcŸ¨t\á\â?¬°‡\í\Ý]6\Î5\È*£cŒš¤<¤a “¿½\Èó©Lt}×¥òùó\ÅNk³Çž^`úÁY\ê\'ŽjRüñwk¸k”õw7\ÐS®5Ø\Î8\Û:±b\á‹%š\ëlžk„#\Ì<(\Þ^D·\Óy„¿—\Ò\Ä_\\ó	\Ú}y>V	±¼O*Ác$\Ï(\Z²\íú7¤‚ôŸ¡\0Wï’®þ7jo´a\ÛV\Ë\Î\ï\Úl]\Ø@7k//³ðÜ³@\í\á\ã¡e2\Ð9ÿ¡\Í\Ø-C,­g~R\Õ\×w]æ§«Œœ`ýõU¶.¬s~\×F:F#_Hõ\Ïw\ÎN\äþ\0\âYu·K$\ÚD<Å¯‰DŒ\èü8S=ð$¹E.s§u\Ãyp\Ó\n%š\Èuz´¢)úµ\"\Z\ëqT¬±\ê\ß \á\"©>zœ\Ú\Ó”‡´0…_zlž\åg–TÒ70m›\Õ\ëŒ}‚¹‰)WW˜›®@t¬‹&\çwm\îù´Á=C\Ã\ê\ë§C\ËS\ÒÂ£\rH•¬\ß]®¹%+œˆ\ïTù\Ó-\äo\ØiÑŒ”šPWù\Ï+<}×…›n±l$\ÚHžRNC´ÁiwzŽ®W0\\\ßu)iö©¿Ó \\(°pò%–NÌ“\ÏÂ’\Íú®²Y÷©\ß6l‹)£\ÈñSK<{´\ÆùmÊ·Hœ”›u!$À\Ñcƒ\ìDEty\ïÀ)ùS Cž(úB¬\"b·[ðn¡”\á#ô68Ž}\î,\í\n\Ïh\ÇlryHcõ7\ÛL|ñr!œ\×w]\r±½»Z-\É\Ôwªœ}e9#¨‡n.+x,Ižä¹ˆ|þ/+\Çß¶<ù/Àÿð\'\Ï^¸©\Ä\n,–‚¢^  \ÕÍ¡v—¾ï«µXÕ‡k¬þ¬Ž\ëÁú®\Í=Cgm“	£€6RÀ\Ú1\Ñý@!\Ù4\Ýù”EH÷—e½p\à5ù”„ÿ Rœÿ¤¢_Äº( Õ¢\ïºO¬¢‡ÿ´™k/qdY;HZ›`\ëik\Ó-¦»`\Â\ã-\äË¨\ÇS}l­Í@_‚wùlñ\Â^cœ\à	D\îFG:s\é4ºµ\"ËºA#}7Qô³›ò\\}!–„XOII\â–z\é¢ù\ÏÌº²\Öÿ4yœPy\Ê~~A€ÀúdY	\ïXÈ¿s\à_ù\à²z…~\É\r¿\r\"˜‚\Âoø\ë@—J\n\è´gY³<QM¦[\ì“e}\ä\é=úE¬AY*…L=YUõ\Ð5l,Ÿ@Q•9@\Ö\r\ê5N!ù1J\Í?‰\è»@*Pª°\ë“KcX\Çu$nNbJ\'$R40ŽZ X\ÈÅ–\'Ÿ,\äùH¡o\Ä*ú\îO\"b\ÈQ2ƒ™“¸þÿ\×3:ö\ç÷vŽJ\×Iüó½>þS\Ç®}µX*%W„0*Ø–.\ÛmG\Ê—p‡\Z!\ÍMþ\×\\úv3\Å6\ÐÃ»t$\ê>?}X£%\åuH5À\'}½KÇ\íòE\áñø\Ö\æ}*Œ0À\00À\00À\00À\00À\0Dñ (`¬WS\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(2,'Producto2',20,53,10,47,'2015-12-31',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0h\0\0\0–\0\0\02„\Í\È\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0‰\0\0‰7\ÉË­\0\0 \0IDATxœ\ì½}Œ]Gv\à÷#§Z>\×û˜\ÔušÎ»AsÁ7¡°z„\èU#cHGk©9­#¶1df‚5\Çj\ØR\ÅL\ì15\Òxw\"a[ô$6Hc= x \našò\Ê&¦–-„\ns“\Øûbv|kÍ·º\ÇT¹;\Ôýz¯?9\Z\ïþ\ã\\²\ßý¨s\ê|Ö©*ø;ø;ø;ø;ø;ø;ø[¾\×Zk­ ôDŸ˜ûQw\å2\ÅH\Ùý©\ÙG\ì¶\È.¿£#…Ž¥;\'=\æ\Ï\Ïÿ±t-\Ã\á;ö¡>\ÞY­ü}Ÿž}|ðþ\Ét÷ñ\ìöÿÕ¾\Õkö?\Ô<¿¢^IŒ`MDZ€\ç•\ÜC<“©¾“<Ø¯ë¼°\è\ÞŽt\ÕúþcÃ–c\Ì.g\ï/°2ñBdš¿\ÃS{^}!\å{\êA\ËwžE6F:[\\:\È0ˆ\n\îE6¢X\È\Å(QGn¾¿žR(D\ÓQù\nñ´ #¥¨ši ò\á(\Ë\Z`\"\nP\0hQ¿™ˆ\nb\Â:R˜\ér\ê\Û\ßIfº\\ÿ¸¿³G”ôB\ÝyŽ¦\Ìv\âEö?1÷8nˆ»“ÁH¡,G:$¢¾‡)\ÛU\á0W@9ô\íÁ–-\'D–¿6#\Ú*FŽ\àœ«Ÿ\é\Äwbš\áK¢ˆ:1ø™D’\í1‘@z)\ri\Øn°ÿ-\"¨WD‰…a:$eÝ\ÈÉ´E½6\ß{À‰„\ßU»EÕ’’ª¨‡\Â\á¹\ÃL ù¶\äJª~š¦}\ÚUûK<ªDðRø\æ\ïª\r²Mp¹kp7\ê<ôö\Å-f’8\ÇB\ï‘éµ”d&F¬U\èD\è0ˆ2%—”Ç„\n“]	L	\îz\nQhAÔ‰\È]N\ä#lQ\'¡÷\Älhô¢\Ã\åy@\Æ\èG¸ª\nZŽº\ì6[#¢·§OÏ—\ÜR!|Tvô#\È\Z\ÜU°‘”\ï*²M\Êû‚x\rƒ \Ð@´j”«‚úE\Z	!‚+	\\\Ì+\Ö\Æ-b•÷\r\ä£0¸ªûb@¶	˜\ÙVŒ1n\ÚrØ°#X»w&d\Ã<t°	ñL‚\ä‹\nZôô®\"\Û,|¤¨S$±$3Ih\ÄÐ/ˆºI¹ee…+ÿ¦@\ï(ñƒI@J\É=bc˜ø¨\ÑÙµ”hÚ®¬3Ë»¦!^U_>tD¦\Ñ?U_ pZ …o)F‘\È]\ë]4¸0„O¨\ä$‰ˆD(|I¹N\èC#\ç \Ô\åALÇ{¼6DjqS\èCPÅ¢\ã\ÇÞ˜\"\Îv‚øReL4U\â@¤A#FHfbì´…m¥VRH/\rjñS5.n!¯¨X6,\ìtŒ\ì¡…\"nÑ…iø&pª\Ôbª‚\ÈF\0\Øi[sª‚S\ÔT’A}›´-\ÄM<³\"™#-ŸB\ÕbÁv$\è\'Šú;±1\êrò‘’©\â|¥©¿•\n—¥ºˆJó\Õ\ï\Òz½}³:qË–\çŸ9p~Nó\Ç\Î/Œ}T#µBH\ë^TU\Ú*¸!lË”ð\ã\ïQV^5¿20¢\Éw|Swƒ V[L0´*Ã´\Ú\Ý*«ð0TW—U½“µÄ’L<« +­¾ª\rI©gºF‚^6\Í@Ì½\â:Ì–\ï\å­r»%·ª‘UÝ•ªˆEHJ\è\í\é“.8òþ`\Ë€SŸ\ê/÷\ì‘]IIo¤\ä•%\Öj *_\rªn®†°j$WÆ†Rq\Ä\"«dšo†\ê\ê\Ñ[•_\×Y\Êð\Ø\È*®[!Ë²›¶R‹òª¯\ê®ª@\ÝÿJ¿•u\Çe™U}“¸p^k\"µ\Û¶,#lG\é˜Þ£}¢ŽP8\ÇðzÆ©÷œƒ-\àòûz{úA¿8ÅºRz³\Ôò	»j’±	¬[¨‚Š¨5G•¿\nª‘¬$Æ¶/\å\ßQ…’–\áR–#Ü¡t;Á\ÈZ\í­EKÛ²4\Í ¨9\Æ~\\\È(JD\èO…!¦\ÔHKDµÊ¯¤\Ô\Ï[\í\èHËº\è\î)	3\nzgx+\ã\êi]¯H=\ÎYK\ï\Ñ\é%ˆFE•üD‰½W£³V„Š52Ö\ê\ï±Q\Ü*+±µ@\æ]\Ý\ÍÀ…Ç•\ã P\ë¥\Ü+¹†\ïM[\\Vm’qñµªÈ­J-	‹4m­ú\ã\Ã\ÃJ\Çh‹ûiµw‚Ë§c\â\Û\è™Ò„—í–¸›”F‹¢£—9²RR¯h\×þ]h^ò\È,\Ã\ë)\Ý{D¡·¯O±˜3‰J…+•’ó”\Ê0°j\\Šš\Z!cV\Ó8\È\Øý’„^pc\Æk…VY©¿\ÆP!&pNUV[1¯t»¤k\ë÷j\í«ü(Å“\ë§. °¬I\Z\"B4ûI\Õ\0‹\ÊwD6i*\Õ`ùe×‡\è\í¼\ÖS—þjÓœ~\ïW¯~ý\Üÿ&Ö‚A \ê\Æôfb\n§è¨€».P¤$£@4U\rVV[¬µlx\ËdÜ¡[\"@\r\Ä> 9ttU´Ž!±­d\Å\Ö\Î+\Ê\"$\"cs›8HË©4\áw\ä)MU@¢ñQ‰Ì²¼X£\ÐBÿ\ã*BR¨n\çT)\Ì?R$’Z‹‰(|\É\éªä£œl\ân‡\0@Q¾\çToB+÷<,\'b‘Ž\Ï\ÄtKdã²‘Z*¸ V\nW w\ê”lT £\à´\Æ-Y\\w®\ÕY‘õ\ãžð\ZdjË\Ð~Í·U(\Æ\nI\í2dS)û¢õg´1×ƒY^!U¢\Ò\áFˆ$¢ð!!U\éÂ†3¤ŽR÷Dn”\ÚÏ¢\"JUˆ	8@‚Ø½zþ2\Î\ÒUƒ.S%Î–´™À¡#\ÅÍŒ\á\í±CzO\í\ç+z\rNh\'\nœ|±l/cah|\Ô\Ö\Ä	F‡•¸!\\›UZb¢\Ño¶	£TþPÔ¼\âw\Ñx,«¬?\"¢°\å}_À¶Ú¨­¿+Ÿ¦rb+¢›Rµ£a\Ç\Äne\é–\Ø+ëª«J_A\n\rD*c~ùbNº\èˆÍ¸”™”8c’\Z1A\ævwtaÑ…\ÑXŽ€\Ü\ç!„2±òQ\í\ê	\ãjÄ©¶¼~\êM%j(#Q$M¬ª\Å}A…x\ÞXD\0@¤\Zø«Be*T#¹m•Jû\ÃVyÁi9Æ•Ž­\Ú\ÔB~-ñJ¡šk¬p;\Ì\È]\Ù£$ûú!šb¾\Ú~`\Û÷l7‹¼jj[$˜&VhA\".-°2ò@\"TR±¤¼_9oÈ¸¹[\ÅÉ¢¨\ìø6‰ˆ” Z„\Æøh\ä\êÿ\ÉA\í86ˆmŒ‰F\é\Ëòt¢¬	‚\Ôw+û²ü]z\ÕÚ‡*FEˆf”¢…|X\Ô•m*(£U¹•N\n§B°›\0øDÕˆ¹\'\ç‰og™Vˆ˜Z†\âß\àC¥¸›w-*\ÜÛ‚÷\îyü‡0ú0\Èþmx^ðóö–ª\áo¶\Z\Ø\nl5\ÑV˜ú„0õ‰\ê>ð@„lc¦0€\Ù*S•2@\Æ\Ì‚\Ù\nÆ˜Ð†Ò°ðexò@¸WJ`d\ÉcŒ\àñ¡\Î{eo\Ë2jX¢l˜­PQ\Ôl­¬b…%÷ÿaA¡£€‡‘c4¼‹ù0\àe\ËVšÁUös\ÛDx\à\î_\Ü\Å\ßóLmõlY\nu\Þ]òlÀð/\Õ×žÁØ„Ý‹F–“RdD\"tw&M\ïTQGPŠ£¢ôžCðPK\ï_}\à:g„¥8ñr‡\Ú9#X	~S)\ZFf£j.(Ed“£y¿~O\'”VXýmKWUŽs\íh4}YTQ-(Tq·hÑˆÐªÜ‰¿C\\3ô1_lt•–\\4ôJ\nÌ·\è2®òJo¹[\é\0¯ -sµ\"\âÃ»¹Vw\ãxŠi9³\Ï-Â‰MD\×1`;–¸\Ò¾\Ò\íic ”¿u…I#\à\ÝX|¯¡p%óK\äH\ëY5T#P\Ç\çsª¶WúsŒ\à\å¼\ÑbŽ\Þq\å ¤6N¤]nm4„²DA¦u:^OÉ€.\ãð‰ö¹gÿñÎ©\×1[\r\ÑVƒ‘³5°+\n¾Â–ÿˆ1ü÷ø&ŽµZ\Ó\Ù\nƒ{ŠWeúc\Îý\åˆ},yþ\â‡þ\"&õ½0X¶|\Â\à—<fÉƒŸ\nu,•\r[ò\ÍÿK>\Ü_j\ß¶–=õ¶V\í,/ù ¢\ïi Î½²OÕ³{T•»µUw9ôõž\ç\î_\ÜÁ¥C\Ô9Œ\×Z\ÖW)‘½)\Ëx\00S3…_ò\ÈD€g¤Eªxt	\î\Þód\Þÿg\Úþbú¡~»ª}EN\Â\Ë\Ö.«*=±\Ø\é¨q¾”:?f¡P \nE\éW¸\ÖH<^Ž\âÞ®ûfi\Î\Âû\Z\á¬WNø\ÆÙŒ+k¬R\èw-²]¨¦\Ä×…I˜ü½Ö½\ÉûmHaš: hœØ–X®\æ‹V@5Ÿ\ä[b¯TºX\â\Ì|eª¤%WŸ \ÉJ={à¼œ¿ð¸\0I\'nf3kgŒZ”A\Ùß®°	X^8\ç\Är\æ!!\ßñù·²\ØA#\ì÷`•„j›ü´\ê\Z³¦MDÔ‘€ŒKGÆ‘\Ýþ\Í*÷[b¨\È:º…ª\r-‡ºg\Òü®T›\Êcˆa\àR06ñ§\å\ä *d#e0rv[\á¸\Óõ	pjº»œ«\Ò\ë4aŒ\ÊPS€-\'«öƒ\Ô.*\áx<<<\Ý\åµgc\ÒK\Êñ›\çLºe/#u(?„pVk\Ý÷‚ƒª+\îAí‰˜Vˆµö‘hˆ\Ô\"T4\ÕzgÒi\á¢ð\Z\\I\rZR\çH«\Ù\æ‡ûÿ\â\äƒ_l·jLUp\äG~øWü0c`$‚­-¯(µu¼\í¦\Õ¿_\nù3‚l½õ€\á§\ïM±\çO\ß\ä\Ð\ßû3’3\ä\ÂR_‡o¿‰\'\ß\n;\î\Ù<Uš\çm»yšE„a»ò\n\î[ù\ÛLÁÖ©\Æ\Ü\ßZþn\Ã\Òøe\Úzjk\É[ª\ï\ËVV8\Ú\Ú\\Y¿5\è%]òd#\Å{Ï£Ó–_ý\Î\í}“½\Ø:y\à\Ð\Ûó[b#õtU=‡R]¬Ä”Tq+3‰>^\n%\ç¯\Ý,\àöY\äŸ^\àØ•S¤O&œ˜km]\ÎE¯¼€’•ÁO§\ãÞ¿N\\\ãµ®˜`¡V—´¯ªýŒÿ½\Z„h½Ÿh„\'èœ¶YÝª{Lg(\\a²/8¨qgõZW%4\Öum.·›Y)2\ã\Ï*Ý±\Ö4Á\é/\n?¦ç°§¯ò\â[G<37m\Ç\ä÷K(¯¡d\ê\Èu|\âp¬õ­9¯\Û\Æ\êÈ—Uþ–U®qó¹uµ‰ˆ\×r\ÚE›²+öo]UŸzV 7ùl-X7³ô\ÌtwY:b%\Ä\Ã\Úú§®¸±\ì\ÂDóaž¾š\n¾`\à¬otÑ©ß›ƒDAcx\ä`\á\Ú+¸/\Ïó\Ú[\'” Ò‚WM¥ŸB\Ö\è\nø[\ÓWkÀ„^ª«P3pø\ÕÉ¡c„|¤\\\äD\ný®p\èƒáª´X“ƒ Š7?Á¦\Í|JÏ‘f\æÒš0^žý-‚žUeøµ˜žcø“óg¡¿v\í\Ç~õ/ž\ÞKöl\Â1+cõœW†“t¨E0\ï\ËX]¼ü‡\0%\Ä\Û\â®`\\\ä)+\ÚW%\Õöº!¹¬j$T\Ðû‰·½›\ÃOoû~\ÃT¥\ì(\ãT”4*´P·¯!&†Á—Î¤.\Ã\èž\Ç{Eÿ­\çÀ\Ï\àú\ï|“\äF,¾u“ú?0S†ù‡»‘Ÿ\ØÃ0\â\'>œ\â_\rA\ï…8\ï•sK\Ê½\ç™\Ú\Z\ê\Ð%TŠ}\Ý!\×À¤	±\ÚF\å{0µµù¶qj³fü’\Ç\ßó°%H—©\ÖK\×¦–\Û\Ë\ÄÝ¯®V\ç†\Éó§¦»Ë½™x\ì\ÞX¬¸öW\Ê\îbD(Nƒ¨«\Ä\àsUÎ˜µ_Ù‹{##y;CÕX\Z\åø£	ý]‚<fÃŒ\ÅM\Ç\Âieÿ\ãþ“5Â‰rº¹n—!ˆ¿–¸kg\Ó|\ÏaR¬N˜\ß\ÕóZúLU‘xóRNoZH$\è\ÎCï¥«\Òb]H~\â\Çÿ\Ýÿ\Í\è¿5&„b\Ø*˜*:ý\0\áC`#\ç\Ñ2tc˜\n¡|ˆ8ƒ­·\äñªü£K½ÿ!\áú\ß\æJ†¨\ç·þ\Üñ\Ò\åE~\ë­Ež>¿…x¦Cò\ß	\Çd‡®~k\Â3º\ä9·¤,\à™]‚\ãK#ö\íÁlõ˜­S5Q\Örö7„*d³\Ö5	K4Æ€‡\â\ÃMªŸ-Á\Ô\'Àþ \åÆŸ;†ˆ)½¿:q`´s\çÎ\'uK\ZM\ËøœN«\Õw\Ã1™\ë\í|Q\'\n<§Aù\ï\ëv™&fþO/º\ÕeL9u„\Ó	ò……¯\ç\ì¿=¤	\ÂQ±\\@9FÈ±ŽD\èšheR\äý\Âý~_X½6“o•!!›¢mpõV0V\àó\×V7`“\ëƒNMw—»&\"\ê¶r‰[±(ô–ŽGi©\ìü@ \ê\És¾$†\ÙS=¸£$\ïeM„y˜˜Ÿ\é!O\ê\à\ÔÅœ\ç†Ã±wlé¿½Zº±l©„¿k1w?Dªò|kv´eT9\0S„\è\Âk\ÎÍ¦#}­\â6¥R3¯}A±¨\åZ—òÁT\ãY\èHWL×†ùŸ¨„\nðª±!N•\ãiðlÇ²!Xð\ßL‰¾6\àÔ»GfbòO÷\Ë\Ô\Ú\0®\\uñy\ï8MÈ›sZ„|mVN)7°š\ßTCi$÷œ¤® u9\ébpNU•õˆ›$Rem\èb0*Á.\ÜõÀu„¡¥ «<\îfYÌ•½:y-ƒE˜“¹gR>·\èˆ\ßðÂµŒ%\\x¨W?«–„Ì«òyu\ä^™Gq>*o!°vD\'#Ñ†IGw­¿+C¦\âVõjA¦Õ»R»!vR]¬Š¸\Çüñùö·\ÏWHŠtÅ–k†¦Ê…X%«\ÄrkBfM¹/B‚aù\Þ\çK]Ô›\éò¦D\ì¾Ñ¤»ŽÍŽ®kˆN„ˆð*Q\á\Õ\ÒqL&r\ïb\ÓJòýX:k<ý2÷A×¹n>ÌœV‘˜8©nv¨¬\ÉE\èùOÏž—÷ONc\à\äL\ØZ\Ò÷/®ÚŸ\íÇ-M\îp{ÁÀk%‘ò]=\âk)÷ r\ÎÀü\n\"2¼.\Â\ç½òf)ZÕƒ•0œª9©aµ\Ñ?>02\rój1\Â\ä )€\Ô\ë;§Gú\ÄZµlH ;²\\\ÏÿxH½\â€ùr”¿þ\Ôn†5=“`„Yqr”s¶Ý¼Ü±Xf_ŸóÊ¬RÓˆ¥MÁýŒòÒ¢\êa\à›i\ï;B\áó#Ç›\Ö\Öq1+ñ¦\êh¨*W\ë_“ùfZ#\à°!Tµ\Êã¥‘[“6#B(Œ\ÖiT\Î3&^\ÉaÿSHoV˜\ØZ\ïbýû\ÂLŸý\Ã]#*söŠ° aaØ™\é„C\ÃMp\ÒZ\Ü\n|«\Û\ç\È0\åh\Çò\ÒhX\ë„A9\æ\Äò\Ê\Èñ\Ò(\ÄfN‰\å5U&!™h \ïzz£!\ÒØ›¾ý´y§\Êù^6$5\å\êoz\ÑF¢šóúW_Ý¨\0^û\ß_ƒ_zŽ³\Ó	ûKB¼YM\Z\ÝqÚ°\Ê‘¢\ì~rö\í‡/§[¢iˆr¹(8tø|ý,\Ç:\Âe…#¥˜=%–\ãÞ± \áogV\Ú{!R\Ñd\'\ÖzŠ±ˆ{µn¨\Ê¯xLŒt¤16 À†\"\î\ê\Îþ²¶”v:R.»Œ—Ê‚»;ûdƒ\Ë3^\é–-t0,¹H€#b99r\ì\á\âj\ân5Ã¡²}Pü\0¯w^\Ú\Ó\ç[\ç\Þ\Éý\ZÖ¢,´\\zü\×^\"ýò\Ë\Ë2\çU±e[†u=­\ì¡Ò¢;el¸89Ž\'lBo\ÑA|8‚Ž;¾8\ä(Ár\ëu„D\âr\Zì¿¹v$a\Ò\\\ÆV¢)”iRÎ«#s¸XN”ñ¹Bz;{c\ïdYFoG³\ã\Ôt—£^aÃ=¸1h•QŠ\ÆÛƒq\"x¾\Ó\å7D\r¤%2l˜2·§ª²{\ÏnÒ›«s\ås?{”\ä‹\'\Æ\î9§¦Ž»Œ´\ì{\r^y\Ùö8\ä2\æôUy­´»,,§¯’ò[m×‘\ã\Ø\n?¯‰f®·Â¦\àò\Îþò\å]ý\å\Ë;û\ËfúË¯\Û\îò1\Ã2\å%\Ý\îrh=«®c¿øüòòG\Ë+\Þ;1\Ý]Æ°üòt(\ã\Ô\éSË“p\á\â…eh•G¸¾5\Ó[Æ°|õ\Ê\Õ\ßT\ï¾ø\Åõ\ïµ\à\ê\à\ê2F–»F–»\"\ËY~ý·__ñ\Þ\å+W—Y>j\í2\"Ëˆ,kgo¹»³×¼ô\ÑòrQ\Ë\Å\Ýb¹\Èó\åË—.µù,?/²üútwùL··ü\æL¸\Ö\Ãÿ†\"\îò®~m\Å^¸œ#\Ç\éJ¼\Ø.Å¬)p*\ÂzÅ•\Ïm©\'\ã\"\æ…_>Î…\ßx…WJ}\Ô~¶\Z\ìž\Ý\Ëþ)\'G.Xd(\Ë\Åòª2 \é}’,ýN«M[\Ö,pmÀ\î={\Ã\Ë\Åú±†-QDŸ\Ë>d\âý\Ò:­’<Ï½{CŸû\ì/3q{b\Ã\Ê\nBaG†k\Ç\â6Œ$\ä-T\ÏX\à3Ü›œ-di®$Î‹Œ„Ž~\î½® Nz#­/·\ØÌª^]¸\ÌÉ‘\ãL·‡§NŸ©\ëYø`€[tc\ïOB\ÓW\Âp\èpÎ‘t@±];†\ìÁ”ôf¸\Ú\å.©„•}m\Ñ=¸‘2É†\Ù0#f:ø4$ˆ·§\ËÜ¿jzDi¢\Z\ëÁ\Æ:¨L¹-jke30nnBP\â\Ïý\Òsû§\ÇB\Ë\ÇgÎ¾Ùª>\Ùÿdý7@~·À–	EQEa\äþÉƒõg/ÿú	NÿÁ\éúwwf\\\çDq4\ÎE^‰·7z0¿\ÕHUewwó®\ìzJw¦[¿myñð‘ú•þ\Î[¶Ecm8§Áð©V¥K•Œ³IÝ³!)+Œc¨Ÿ\ä \ÍB©ð>s\0œ³%\ÚÂ«¶K\ß=\Ît{\Äq.\Êng«Zs¼:\Ý\ß\ê®$\ÎZpÀX^Ÿx{H´-¬3ý\ÖN\Ëò\Å\çY>÷<\Å\Ï\ì\ç\ÇÛs®Þ¯\è•/¿<ö\íò\Ý*§\Þ\ì6\Ä?„\Ô&v«g%­„	TFg+BU«°×ƒ\ÚÁ[-É¤\r«ð\ï‹CRB\Ä\â\Ð\â÷6ü³\â]ŸŸ¨£²ª\Ä+/8\Å}\á,<ñ½o^\æ\Ô\â8I¸zý*°Ò‚…°\ëUv=\å\éa6DU\Zu°qˆ´MG³\'s\Ój\Ø(¨Y\Z	ñj™8kÀ1»Áô\Ã*„hwº½›Ôš°f»öW\êqù\Ê\Ë\Ø?zýµ9Ž\ï\è“\Ü\ÌX.ŠÚ¨¸\Ð\í³%Š\ZB•°Ö’\ßÉ¸pñ2\n¼\à]³Ô¤\ê\ÙmJ\Äi\Ùð*ü~F@…\Ì.\ã\Ôïªo\'6^\ãxeq¸~(þo1{\ç\égž\æµ+óô.½\Ãyôð\Ó\ìþò€—†®1\"\ÊúO¹Œ7»	Qó\Òo¼‚›0Dz3AÌ‰‡3°bc\Í¹MpPQ‹¸Õ‚økN\r´–Á\ËÀ+‡?s¸~œ-f«|D4Ÿ¶døªu~\\0\ã\è\'û»y:Ž¸üØ·ŽÁ/\à~ö\"\Ñ7\Òr.§\Ý÷&(úô0\ãùŽ\å\å/\'\Þ1\Ñf\Ïÿ\âóµ–…µ‚Á\èð	$­Ý\Ö\âž	„\rýø³“^Wø!{\Ý;ö»·+(k.\ì\ì“s2.\ê¢uò\Ç\îw:»;\Ýe\Þ+—gú\0œÑœ7¿\ÚG\ï‡7N1ü‚#~?£\ÛM-kzž—»B>_JWFŽ\Ê\â–dðW¿MS\Æd|=Ø@2mk³pEa«l±\\,T”ÿ/‡k\Âù\ÓQp\ææŒ„\àeõ\íG\Ëù\Ùc\ì¿=\à\Èb\Æ¯lqÝ……\Ë\ß;ñf \Ïrö\Þð=f¿”„>¾q\á—\ÉÍŒ7ÿ\èsOÎ‘<¶Ÿåš>ôvN\Ù};\rý,\n–ï†«\ÈÇ§]Ný\áÎ\Z\ã\à¾\Ô›™õ\Ø\ÑCogU¦\Út¢ªU\"Ë“\Þ‚µ¯3¯\n_?\Í\égž®\Å\ß\ë_}•×¿ú*q’u\"^+òp8\ä\ÐÁ§\ë(\Â$lä¡š\î±e*bù£‚ôF\Ê\Ð9ògP|u6æŠ¢\ï*û\ß\Ï(5A<u`¬\ê•(Žù\ÎLO\Þ^\ß\Ê\ÌGƒ€rK²\ÒrŒ¨ûJq6eÅµ%,¶	²q\Ò):Rž~jŽOö?\Éa±õ\Z›\ç;]Ž|\îHX\×\Úu°0€Â‰/\'½=$Ù‘ð\æt¯œt[	ñB\î\Èb\n(ñŽ„§Ÿyš\î\Ïb\î—XT(ú–¿—1P\åÕ¯¼¼\âû\áp\ÈpqHÇ¼9°û\æ€3§O­xOUC€V•Oö?É‹68·/˜*qF6·M<n\Ì\ëfO7­7€¨b·\íÆœ1¯œ}\ã,G>\ÄØ‹\ËKN«ã°‡\Ó^\r\Ùg„¨ô\Â\Ïü\á\æ›\Ãv½£\\\í&|²—pP,O—>‹õo™_µ\ÔüÆ€xªyn	\á&t8\äòÿCl\á–\ÂMÐ¡·¶\0{\îžc\î\Éa\× w9ûŸœ\Ã\rC¨\é\Äb†\Z\áµ\ß|\×~ó$m.\Èó‚…\Âls·\Ç\ç‡\ãqñvò\ÌfÕsvö\Î÷\\ñx•´Ÿ©#CyE,\âa\ÖTDl¦“\çL‰=\î$Á!40k„cFHGŽ8W\åŠyx³\Û\ã—q\Øû\ÔŽ\\œ\çÀ®˜ø\Û)ºa6vlB´Vð¢ŽÿB/\ä®]\ÙIî¢’LLI¼9\Ý\ã\Ä(«®\ã6\á\éa\ngº	m¢u;€žD¤\n\Ç]Sæ«¥±	\Ëð	I4®\Ä\ÑñÅµ§¼7$Ð‰\'\æ\Îw¯\\}¼J¨\ÈM\Ø	1÷\Ê+\Æ\ÖIzk‚WŽY\ËQ×³•y›i¹P‹¡Jx±\Ó\å¤w¤OõH/\å\ì¾=œ(—M\æ`G8õOz\0wk e\ï\íŒt\Âw\é¢Ô«©ó9”ùIµ</B\ØýÏŽ‘}ù$Rf96O „®%ºR\åˆE$!ñ!#®\ÊñEHR4\Íj\í:ü^BlÂ¦\á¹§$„--w”Œ°\äiC\È\'0a“×¤cG\ã:j³H:l…“_\ì‡\r7®—\"m \Ä\×2&…\Ì\áŽeN\Ç\ïÆ­}2u\ì›\èS»=‚\Ð3Bd„þ_@G\Ê\Õ_;S´\\„\É\\…õ`\Ãn^þøˆ‰\r\ØzÍŽ\Ôs\ÍJ³Öˆ[§T‘t@}D\æƒ#\Ü\íP®£Qz8k\Âßƒ+³\Ï\n\'ðœcmÎ™¼o„\ËÓ–þd:F\Ïg0¬ˆ³\Òúzµ\Ó%ö`;¡}cüS–;\ÛY%ú1!\â*V®`˜±÷‰ýp%]þ\Ñô\Â\0\0 \0IDATa\ÂDTc}\Ã{C+.NZnÚŠ\í¸>ˆ	È¨1zF`¿õÎ©\ÑŽt\Û\ß*Ðº\ß!ÿT\Â\ì\ï\íF\í\â\Ü´\Zq\æ\Ä\â\ÈJ\âl:V?™¼ò\Ö<º0@/-\à\Þ87ö¬^7i	¯;ª]\Û4T6Q\è}°••˜ˆ\ÐkE.øÀ­òS2¶ýZðºµ\\þRûû \é¡g\Ð°0\È\Ç,µ²vŽu,Gº‘¬Ð½_\Çr\ÃoMxP%ô¯µž·‚\r	ôo®§\ï\Ô¶\Ûoç¨ÁY±al\ï¶\È4–\Ï@„…7r¤c9\ÕY\Ã÷\Ð!\Û\Ù\ã\è\Å#\ÈÏ¿\0—.£¿{=¯\ì7eÿ\ÆÈ°\åJôSb\Ù_§\Úfysiñ\Õ:zdŒûJ\ÂHu\ÙòÿK \Ì÷µ~4\ÞðXŠ\ì&\Ä\ÎF ‰‚•´W\\Ø´h®¯ºŸ\è‹VH?Û£{ñ\ì<\0o¼Š.8\Ü\ÛÊ‘÷S\Ê\"œ\ìg¹k\Z\âÀfEÚ†3b\ãoU8+‰D†\Ú$\ç¯÷7\î\Ë)[\n\r£À\Ë\êV\Í}B£4\'`\äh\ê°?\Û\åù‹)/µR¯.w»\Ì~¥Ïœ¾~½\âp\Ü\ÈX˜h\Ú)	‡ðˆ™Hš/a°Ë†ýK;’xôC4 ?	›ƒ~)‚s…\íBÿŠc~&¤§\rGJoGxž§Ž½U\î_M	{$,\æ\ßô\Î;\ï¼SO{W–Ò”Ô›¤\Ö\ÜôqÁ¬w5d;»d\çž<\Â\Ñ\é\àhö:ˆsñ9xö˜>8^tœûýŒ\Ù?H\ÇBüb‚HÖ…VÄ™¬\íð»—\Ñnƒ\ç\æ9mÁ‰pð›8øGóœ[\ÌHùs?ÿtÎ¼¿ÀÁs85L9öö<^yq\á2t\æ~ö9zŸ;X\Ö\Íq´¥\ËS\åõÐ²\É5\Ñ\r\Ç6ª7\äûø$\n\Øq1W%ü\Í\ßV\æ¯eÐ™£÷\ë–\ï\ìJø\ÎWf™½•\ÂÌ‹@\np\0÷\åžûÚ€C.Œ\ä\n^\ËIc±eúò\äTô$¼ùû§Áùµ”}\×/sò±\Ý\èµ©Wüü1^ø™£ô\Þ^\à…2¼t\â£:–ü\Ú\0Œpõ\ëg±O\äÄ—_©E\Z	G\ÐT›–›\á¦^ÿx=¼lz\Ê;¬ÿ\×Õƒ¤\ß#\Ó{ò`\×F®\Î^x…\Ñ\0ž<F\ïÀg/zŸ\Â\×‘~\Íq\â\'\ÐFXÎŠ!µ	½¨¦\Ý\â2j\ïž8@v\'#/­\È\Ã_8Aþ\Ï\Ê\ì¤?9\Çñ©¨y\Øÿ¥—Á@o¤H‡`\rT¡CkcÂˆ·þ\Ñl›[£\Ú\í.[\"z;-²½\ÚK»(3IB\Ên\Ø\"’•þÀ},+\Ñj¹F©\ÓNy\rÛ™s\á[¿{\0ž=3þ\Ío\ìf\á÷r^½6\ä¬Ø±J‹\åi +ñ˜!°¤˜fô<¤\åû\nôd&a~˜2kmÍ\ÖUŽu{Ì»”X!šQŽ>Ü‡m¥•ZG=¤·\Âb®Ï¯±ü¾‚ûû#…x|^~\ÜGŒl=(\ËA*]5‚{k€}¶yGg/§¾”q\Ú9\æ@‹8/Še7‰›!N\Ö	\çRô§-¢})Ø«—¥ ñ9p \ÛCLX\Â9 \è–Xz\ÓIx\æ\ár\Ëj“\çTrµ\Þ<\ÙC¯#|\ìE\Ä5BFl>¡ë»uŽ¡*ƒ‹\Õl¥¢¿¶›ÁÛŽWœc\Æ\æöOTÄ‘`l\\¿\Êþ\Ïd\î³GX¦»ž’Ž\nŽ¥ó·SŽ¦\ßa\î³‰\å¬À±ÁUö\æ \Ùp\Èó×¯2÷¹ƒ\ì?|“Ž.\\eÿ³Y0\ÂÀ\ç\ÍT\ê*\ê`\î¡\ä¿\ß\0%›ƒ*¯Kó\ÒÄŽ¤9\Î\ì{	†2®\Ê~]lXÏªÊ…\ÛCö}\ã\Ç|1\åäµ”“\È\n\Óüu±Ä„¥÷›\áœ6¼òk¯p¬Û£¿«F8|7$¶T†Kÿ‹/ó\Êö„\çû¡ÿÅ—™û0i\×ÿ_\Ã$\ß\áN8 ¡ÿ\Ë\'\è¿u’~7itLúÊn„Žû¯Uó?º²”–˜“z¾hc-BL1¾,£,ï²‡‹_ºÊ«×†œÆŽP\ÇHˆ§}b¶û“˜¡Ÿ¦<]ûf–‡\ã?õ4ùtDÿ\ÙÃ¼öSO“‰D¼ô¹CX\à\Ø\ïža\î³G9ý3G¸ê•JX\Ñ>\é\\+uy¶=¾^›\î¿¥! >d_Ö•®	›;P\Í×W¶r¡cyõ\æù\é.TóC%ñ^K\ÄwOœ\×>M\\x\ã<:‹]t\ìý\Ô,¯üø~\â\é˜W\Ê\çñµ”“‡¡>X{²§‡-\r¡CIÄg\à¼	CV\\)“©	´\Ñ\àÝ”w¦Ö°XB0RM;T:\Ã#]¹Y\È*sBRNf\éø®¢Ÿ9\êÍµ\Û£Eœ\îw!\Ö*\È=õ\É,‰„iÄŒÿ\ï\Ù\rwrò\ÅLD2c\ÉM\ØNPú½pt§KA,‚\ÃVVR\ïSšeasøBC]Oð±VØµ ]\nT…—Dø˜%×°¦˜+\ç‡\ÚðzÇ–h|<\â@Ø¶7’­|¦\ÊÈ¨¦!\ä‰Y¸«t]Nô`\ÚM2\Ê\Ã\é.·\È\ìñ7_ƒm–\âV\È\è¡\Å5E¹&·\Ø÷T\Ý^y\ä‘Gt8¤Ú®/$Y6\Ûô¯™\nü1ò×š´¤¦œ9‘¦ôŒðb9i˜ˆ\ËÊ˜\Ú\ß\è\ïž-MfA¯, \ÛÎ†¬”  \×Ï…\ç£òýJ\çh™¨4\ç\"y6Ü¢hC3\Û\Ú52Ù«Õ¦þ\ï”>D\Û@>\\\Î\Øˆc\Â)’ÿ!‰S›\É\"Ð¡\ÝD%q\êgF\Â)\'¢­PÐ»¥\Ô\ÒCU¹i¨”7´\n6­¤‘µ\Ä\Ý}‚\0\ÍÁ.Z—ý¢±ô|•S\îeðñ«\Û<LGZWõ¨Ž§»F\nõ‘>õ!…,ŠÛƒþZÿz\ÕûÍ¡•ð\ÝAµ	S¯x¥Gia7\ï\ÎZ»/h•Žˆž N\Å=m´½;%\ÚT)Š\à\è«™\ÍÆ«¼7$\Ð\Þ^òx[\ØuŽ¶Ö£\áo„&\Ñ\ï¸zKTn\Øô·Ô¨¡\nÑˆ€-­\æN¸¢*R]\'\Ò\Î)F4*£/wË¿+‚AC\Ä\rª\ßx}Ð­lc1²	Yz\ßP\Ï6J¹Ã–\ÜwV\æÇ­¿ž\ï £MDºœkSb¾m”…‚•÷‹I\\}\\$ªÿ\é\ÚO«h\Â÷t\â\ï°ýJ<¶µ\åZ\Äi\Å6VÀ}·²6\\QN”Ä™Œ\ÔftÙ€\åQh´\ÔbA6\Zh¨¿=y„\á\Z{ŠVûº`}¤F§¯]\Æj¯VOò“`“.La\Ñ2ø\Ê*\í-\âˆPGVx¶‰S‰µ\ÒZ«	\Õ\âšû\åü\rQ\ën¥´×µ+¨G\åñ6\æªI¢¬\Úh¿ú÷ÒdÈ£\å\è¿n\áA`&†\Å\ÙÕ¥wÀ\àk«m\âl\'N´\ç\èˆrŽL\Æ,6õ\ßÝ¶/v\îÁþ\ãÙ¥…ñ›-®;[n˜$Â†#i½–µ\Ìz™\ÞÏ\\ˆw\ÝaŸè†³_o)\ì€Á7\núOE(ŠL\'á¬¡H\àn\n½\æ\Ï1\ât(\'Ú¤\Ñ;f¼þ¢E \Ú\ÈAUjk®\Ñ9\æt¥O?¶\Ô:\ì\ï¾\\˜h|÷)ˆgAF@·\â#\ë\Âú\ÙT¨@/.ô?“\ÃmE#\Åöú\à]¸\0]\Ðr;»\êT”Z\çl#”?©o˜ LEœj\ßKt|C%Zª¿\×Ë‰h\Ã\Ær\Ã& ºJ¡õ3³òCL\é@\ïs »\Ê#Ê†qXzðE:z-…EA`¶Gö\É\r\á—]9÷†bŸ²Ø	z\éˆÃ¥ ·„LË\éM ©\Ô~Ž\Ô\Ó\Ô–\Æ,°–µF1ñ»4¹«\ãg”F¼U¸ûž¨¨¶H1\ì\Ø\"Š®˜	\'\ÏzÈƒ‚L+\É>£è»„Q|	\äKs ½uFÃº-:\ÊáŽ ·À~®\ÈH\Ä\ÂbŒûzŠÜ’\Ñ#F®¸°ùö»„UV¹ðœpŒwp€¥g²\n\çÔ¡›Êœ.7jNöx|Ã¥ûq°7|U6ú¦¼·’3t|uCs·~wö4Ý´ƒ\Û\å§ð-ó\ÚR¸Cð\Ö-š\Î\Ã5Ao\rk\çTT‘\åž7_s\èù…r\ZY\Ô*¸ûXx¾ÿ\Ù¢\à\Ò\ï\";#\Ôe7•\Ó\ßH\É}\Ì\Ç¡DQ´’8¾Em…lj¹%c\ÄYM\ßÖ¯\Z|ºj\Ý\ïzpyq\ÂJ^I>³§{°§\Ó	‡\Ð§\èE\Ð;\0=Ÿ¢© £òð\Ü0C\Ðƒ!8št¥.¸ô\â\'Cµz\ÜGþu…;A\'Ø§æ¥û³³\È\Î!\Ä=d\Z\âg-™†2	Û‹\åf\å\æ\ìu\Èf¤\èHÑ»e\ÛJ\ç³&\Ü*œSe\Õh›i\í2¼|\ìhV\Ûd\ÓG€tAzF)\ì\è\Â E\Ó¶\rÁò˜ ×•¿ž\Ç w!\érp\ÜÀ\"\áˆ\ÌiB^°d‡\ï\Ðt7ò\×ö\'1—o\å$A¯\'\è\ÎCòiNX1À•\Ë\è¢rü—\ã~M…‰\Ú:¥\áŠ\ê°»-\ÎómV\Ì:·…§+­S\Ç\æW…\ïŠ@ue•¯\â	ºƒqÿ¦÷SÀLŒ¾5¢‹2£\è\"pSa\Z²aÁ\Þ\'Âžm:\Òp.\Ã]À:¢7Afn*ö3=t˜\Â\r…‹¡2½¦ °ÿ@Œ^Q\æ~¦Æ¡Š^ùŒEo(²+Foƒª\ã\Âù|Œ0b‚\ÕI3%\åÄš*$OXºOöPr·@GŠûÀ\Ñ}¸\Çü\çtõ\í\r(\ÍI\Äß\é´iI\ØkN\ãQV:“cc\éa7€N ›\Ì\Ù%\Þòˆ C\è}:\Ä!O@\ç\Â*¸K‘¾%_,O·º¥\È]ô\Ú\0F]\Î~sÀ}12;‹e›X˜D¨FË£@\Ç\Â(Af-:X¸+\áÜ—Òš{*\Ózß£\ÂÞ™8p\\\Õ+\n½²\ï·\ÂB H<|d\ÙûKC.9”W‡•Mc½i‰™@ž°_X=°¿W\n;ÿVc£@\Ûs1«†{\Þ\í!I\nÍ¢o,<\nÒ·È¾9\Èp\ßHc\Ñ+a\ç`\ÙC\ÇÁ(LC\çR\"\èÊü&D3Ž³1²\Ç\";2\Ôö\àFÓ	Œ\n\Äi‰»@öô\Ñ\ëÀ*t\n\Îþz††¸k\é\è?\Z“\á@©E\ë\é\ì\Ã\Å\ÔSþ‰9\Ð== wÀi‡ý…ˆ9GµM[µ¶¶¹‡\Æ/jóÐª‡ù\Þ?\ÇT¢·!J¦™X[q_Wú\æÁ™<?¦³÷†\"‹g!‡\Ü	¼\åˆ÷	RÀðv\Z|†‘#\î@\Ü-\Ç\\¯G¼£€»ùÍ«$\Ó}ôn\é@›<,¾žD>–€M\á —!D¸w!¿‘«#y°K\Ü{\âJ\áw€k‚{\×Á#FŠ\\\çh:\èJ™½P\'Á\Ä]°‡g\Ñ\ì\Î\æ8Nÿ\n\í	˜-´4V%DøUŽ½_­\æCYc\ë\nJß¨ð\à.:l¿\ÅyÐ‚‘$G\ïB~M¡\É3=\Ü7R\èB±X–¹³<&\Í8\ä†rðbK\Ò\ß\ršÂ‚¢}A‡\ZD#`wR„O+\Ü\à\Þsd\ïœ»öm\ëö ·3¦;Rd–°\Ñ7\Ê\r9v\n\Ý¼\Í\æ\á&È§,\ê’Áðl\é‰v€E3„÷•‹\ï¹ú\\%+QÐ>ló¬\Õ4D7„aoe5ÂÃ†G¤ýt§ó+\ÕY4ŽüZ¿T\êØ­˜\"jÎ«@±\Î\Ìù¿þl\Ä\ßÿÁm\È?°\È±\r\ï2\Ðæ±˜\íûb¶,{F\ç‡ØŸ\î\âoŽ\Ø\"°­o\é<ø \Òûû˜\ï3ø¥E\Ôu0÷š:ü=ýûò}#ô/<z	\î,ðWSL-yü\ßóøÿ\Çc–\Ã3úw7òd^‘­¶\í\Ø\Æ\Þðl\ë\nöñ=ø¡\âÿR¹{\Û3\Õ\ë`\äòý\Âõ·FL9ÿÿ¿$#L\ì\ãÿ\ï!¦\ã\á/\àø/P<\Þ(ÿÄ°\ÍFð\0\Üù°À}X\ç{\ÞzlYòt0l{`\n³N»\Õ8\ß$(+\ç2 á¢¶ø+h\æ•3_p\Ôöƒ‘*ò èŸ¤\èö™ó²Ÿé¢·C$Ø½‘aC]Š¾M\ÐKVaÚ†ýun;×‹ ¾\\Ž‹\ÔA|‹ ¶¶ö\Ó1\Å\×S.\ÜqÁLS¥;*(FN\Ð;!|4‚\ä\Ñ\ÐSFõB\ï±.zeˆ:È\Ò{†\çR\ìö\àp¿ö•A\\:Bd\Ã\Z õ4›ûùRIøñEp\Î+±6<¯|sŽ\ê*MeW\ê\çE\ë^“=\Ù\Øt\Ù5‡\æû\ì,š9ôNxG¶²glS»•w:\äÀ\èBHd,Ð€¨·:ûL»#‚\íE\Ø\ÃZ>\Ù…é…¾E\î8Ts7r\ØV:\0Z\æÀ\ÝUôƒ½\Ís7@öõa— ûö¢‡\ì;+ôöatÁeŽlQ\ËÈ·`­ q\"dy1\æGE%\îªÿ«\ÈD¦\ëû@°ò-BL@\Û0Ks¢|¡\ã\î\ÛÙ·2Ž>\Ú\Ã}#l4„»\Ã\â†\Øw@u´\0]\ì>@#\ìO\ÎbÕ‘ý~+±µhúAØ·\'y8Fo\åÄ±„0\Ñ\í &\ì“	\ãnf¤¹\"±\ï\0\ë‚/] \Û%wŽ}E¯¤\Ðôü\0\Í‰\Í\Ù|º\×Rd‡\à\Ê\Ë_Kk\â\ÄVˆ\ã\Û	}ºf\ã\ÝIÜµõµó\Êpƒh\é\Æû$lô”dŽµ\âv“ßžüb\Ê\àÝ\Ðk{ÁÉ³OI\à.Bþm(†Š^\"{º`R\ÜB\Ê0Ë±Iy¶·@ž\ÚG\ÔylI\ìÈƒ?\Ý\Ï\ÍÁm\ÅÝ¸\Ê\Õ7òpb\"D\"\Ì\Î\Ä\ÄOX$Xœ’<ñ®2N8t¸‹.<\'L_È¾¹,b,Œ,/ÿfEˆ¬`c	\Ä1!&\×\íV\Â	\'¶<L`\ìØµ\n·{có¸G&VJK™\ÕÖŽ(´\á\ÂŽþ“I’Î€^\n¢\ë\ÌÅŒC{z¸;9\äÙ˜\áo_$_,Ho)½c°C\ÜoÉºöº\0ü<\É#Š\Æ	Œù‡.\ã\éMäŠª \Þ1÷•ýtA\ßJQ#\ØG\Ønq§/‚\ÜEG~’O\ÖÂ´C/	\\º\0CGúnÁ\Éó\Ã&\Ú\Ý	Ä‰;Q“h\éCº°j;³\\Z\Ó1Z\â­|´6Lž?3\Ý]yè¡N®ˆU?|\Øi\Ðùp\ÖC{\â6|¶O¼+ qXwC±O„Î¨·d—w\Ý\Ñ}¬×†D[\Ò÷2º;PW‹‹\ÂC\ä-öŸ\Äuq/’_‚sWRl_\Ðú{,»§#¤#d\ï)\ÉS=\ì“=\Ü\ïÍ“}\0\ÉCÄy¢\Û=«!\"a,\'7%sZO\ä\Å¡\Ç\á\ä_F=ò\ÅS\åÀ­\Æ!“nÉ‘Åµ\Ïn\Ø8«§_m$\Ë\Äÿ\áø\ãrƒ?UªU“\Ã6œ}cÀgz\å\áµ»pÛ‘¾«è”\ä\Ñ\Ù#pc\æQv\Äô¦\\hÓ´El)2\è8$Þ‹¦@-\Ù(\Ûð\ß‰…^\'Bvb{\Ä:@\È\Ðóù\"\ÄÓ€W¤\ßE/)˜½˜¢‹Š\í\íC\ï¦\è¢\ât\Â\0Š;‚\ÝVn÷ßšŠ¨R¬B\ÄÚ·¬\â3nd&ll\Åù†\ÕÕ†¨dõzY‹\ä²n¾B¼01\Ü%:ô’?Ö£÷T‹aË²xºKô0H\'§¸Hˆ*º’~¤ös³\à²·s®¾›±p}\Ì\Ý\ÛJ,at\Û}}X \ÛJñˆ\Å\Ýh>lJ\é\Ù`@x X@\ßwœû½,ôS\Â\Æ\é6*ó\Â\ËhwtW)r\Æ#\Ýet\Z‡¿¨ò¨\Î\ÃX\ßJØ@Žµõ\Ðx>2c\ÜR)\Åh\Ål+uƒOþó}?%»’\Ãí°§¨Z°dHò°…}‚ª£xŸ¼\Ô\Ð*AÐ›\ïf\Í2t\á\"\ÃE8·0$W\ÈGJ·+\ì8Af\Í\é]G\ä\ÉÝ°sˆ˜uq\ß\âÎ»°*k\ä`ºOq_So\å\\¹@ˆ\Õ\Ä\î\Ò$\'–xh/-‰MåŸœ/Rò\r–7lI˜û¡e\ÛbŽ\Ù:~dyöK\Ï3µT¶l	\ÔOÁ’>\ÙVƒ_¢þ­PG#\0.½;b\Ç&l\ß3…‰À>iñb\Ð?Uø\Ï|\æñ®x\ë‰=\Èöÿz;øEÌƒ¶ø0‘ûg\à·(\×ÿô.·R\åÖŸ+^`\Û÷\Ãÿ\Ãib³c<¦P¢\åff\Èè”;\ï\Ã\âbA\ï\Ùù\ÅEü=.Adzþ6\înp¸\çÿ_\Ç\Ô0e\ZÎ±[Cgü]0üÍ”øRQŒ™b]2(Š!\àdQG,z¸´\ä×Œ$l\ÈAi’ü‹t‚\r\ë\ì—+\Ï\Û_D¦u+¸\ÉC~\èX\ä‘úž’ý¾CMS\Òó)E’§zð\í·0À‚¯„\Û/\àQH9ùu¸üC£¶k;\Ó+Mfp©\Â§Cp7ò»Jv~H4L\æd\Ö\â.iðµ¤ \ÍK£ :^F\Ê>Tµ*\ØZqN«k\ê‹2\Î\Õ3%3WÔ¿Ö†\r	ô\Ê\ç~1œ£P„\ÆMKÅ¾1(a½Ä¼\ê„\â\Õ\à\âw^q\ßN\ÉRex§€]\é	½Ÿ\Ù’I:)zIÐ·¡Xx\×!Ÿ\ê\Ã(\Î\å\\§šy	\è\íK\è\í£Nvj!{¿ÀQ\ß\é	ñŒ`û€*\é[CH„üNÁüGZ}k@¦„\ØGaqa™¿\"id¨\æÑ„°e¨ú¬ÀÀ\Ú_\\ÿ›\Û\n\Æ+©*Q\×R-E\Ô\ÉUŠo•\ï«$ø\Ú\ÐX\ÅvLÓœôRAz¥ wJ¾\èBe€‰œ/\Ð].¬\ë|&Ažø`\0E\Ö&\\~¯\Üd²lKz1ƒ”jA¸<j)†€\è\íKˆ{‰…\Âƒ·\n²QLöÓ‚~\0¶;> âªŸœS¥Vñ\ÂÄºŸð¼¨q—8<,ñÿ¸\î7E Wf\Êö˜j…÷Zyr\ë9^­\à#ó\ï9Ò…`I‰‰\0VÑ…vô\î\Æ>\Õ½f`-òP½W\ß-˜»urd©”\ï+š;\Ü\0DA¶÷‚Ÿ#T±Á\rAC|¡‹Jv>ln[%¤\nòQ,\ÈQAˆI•â«ºZ8XOp\Å2Žf­%G\ÖyuóY=!m6\ìh[gýO$Z´\Ä\ë\Ù\Â11(\r‘&“5aHŒ‘§º\è7¼E\Ï;ô›)ÿü2LCzPE\ß’\Þ(\Ð\\C\à’ñòxù7R\n£\Ø_:ˆ¦)ÑŒ\à†Ù•œh‡\Ò{8&\éu±6¢÷T\Þ3]¢¤\å&Õˆ=0*À!\Ãh´R\Ä78XÛ»©\çÓ€^¹qz¯#kiS\ê?y\0ñB¶R”ˆÇ¼¢ec\Ìj#I\ê>	Ã¡\"û\"b£\èC\Ø)\à²= ¢ûpB$<\"	\ÎÃ™w‡\\xr…Â¸Ç–\Þ,poŸ\Å\r•ôfNž>‚\\\È\Î\çé‚¦)\Ùõ!\éµ0CZYe\âƒ3­¦ôŠÕ‰Ä­–h\ëÿv}-\r32‘ü\ÞÀ¦”½=Ol@‡\Z.-]\åÖž¥«Š¹õ\âL«‰:\à\ìof\ÈCv\nö\ç„(÷\0!ŽµLf\ÏIß‚«\ï\ì\Ý9¹\Æ9¡b \Únþ-Gv^\È\ßmœÑ˜ öˆ\"\Î\æ¤\Î|=cø~AZhM€\Úbk\çÁ­\Ò?]\åmK–¥[”1¹úØ…uœù\r	tô\ÙÿS°<@¬<\Ö#~°Û¤,Uhž03×“Á\Õ¿“‘‰¢¼ò›n*\îÓ¸òo+²]\Èo)’(z-Š\îrepM\'Ê®\Â,\Ô\Ì\ÈÀ\ÙwS\\P$€\ÌZ\ä\Ñ³‡cöŒ\èO[Š\á@§]~c\"Õ°j -œ\çlû0o´^*ð†Ž\ê\Ñ\Ûw.²\Õ\àQ\Ü\È\ãþü\Âx€\à”:EµÀWŽ*S@Á¨åŒ®”¿<&8º´¥¶²ð’ô·k?RFZ\àÿ\í\ßÿ}ÁGž»Ùˆ\Ñ_Ma>×¿\Óo\Â`ÊcŒ\ê\âiØ¾Ý„¼¼\á\ßpóo\Ñy \"\êv—©)¸t·´\ï\ÜùP\ÃÔ½²\éeŸªžXu˜û±þ7ß¨\Îü\ß,y\î¨?`ð@\ÇûG®xÿ¯\î‹@¯~z_.¹(\àQ¢\Î{t4\"º7…ƒÿ«»u$\Ý\Ô\Í\0½\×&L€‚Š|\Ì°\ÕÀ’gKýf\èú\à\Ú\"ý=\ÛþKË¶\Î6¢.°M°{¢‘Â¿þ\ÓEF6\åG˜\à¯TzÎ”\å?\"‹#Ï£ý˜8™\Â|(<x8!þo¶\ãÿz‘\ë\êY¸§p/|\Í=C\ç^Ù…%ƒ÷Uf\ÆJ¤û¥\æ2K0U«\nša\Þ\r¸¼‹g¨Šƒ_2˜%}\è\Ý{+#\n\ëG³?\ØÊ¬n\ïZ\å\Ô\ç$\Ú¨jþG(•a\Éð“É­cöÍª\éHR§NÐ»Žbq,\È\è\Íw]Ho+\ê\Ãl&4–a\ØÕ½Y¢¯Šª5F9·s ‡\åó]…ÑtPPEK´\Ì(•6Ó¯:ý¸:´\Å\ÜZýngúœ£×±¥¾\\©6œn¨¬™j&06B\ï±\Ýwrô¦CµX\Ñôö\æI…Óƒ%(\åb\áñ&ž;Ÿq\Ôö\ÂTÀ§\Üd`!½©dwŠ6Û¶z\Ô\ÚôVªò#¢©2‡\Ï@¼/dœb »R®œV¤Ú¢eŒ8\Íÿ\Õ:¢û†\n­CžªVW(±‡§\í§Ý³\íO\×q¯>\Ô_v¹X\êÁ`¶\n\Û?\Ã\'º8BGw;{ð[\ÃsŠ¥õÌ·\n„\ØnûÿÛ»š9Ž+ü­©5¯\Ãªa\Ó ƒ\Ð.XÂ¬ˆ‰´\àC\ì“rQ$ø¨CrtŽ¹\Z\çH0‚Ž¶\ä Ø•/\ÚCm  $¤u\é9tA\Zú!\Úª^uUu\ÏJ\Î9û3\Ó?õóª\Þû\ÞO½B1+°ý5§\Ø\ç\n6\áõÇªW·}h°­	Í¿§×®U>\ÜK½¢ ^¶iPN\áU¸ÿ·«\\€;FùÔ¢}¸\Æ\ê_@½j\Ñ=\Ýžº~\Î\è.\èt‰b¶-UÀ>u²cû+\ì¶\ç\ÖoÁ±\è¬E÷\Ü:ph-€O\í\åc›²¹ž¼û7\ÎÚ¦…Y¹]Dýuò[ý¼f\ä\Ñ>\çó\ÛB4\Ó	\åN\ê¶r¨¨÷;\Òü°yÀ€ùœ\ë®Â€\0\0\n…IDAT°’(‹\è}\ä\Û\'Að b0\èn#“~–­iAfþ/Á™Š\n¿wýe}¾./Á \Zž!4£\îÄ…Tyþ#\æ„&ló»ß»°‹\æo×\Û#cLÄ‡¼„ñðºŸòmD5”3B8\0\ÂËŸ‘þ±–œ=\ÖO8±ZHº˜0ˆ*ûñR]œeÀ #¸,¹u\Â@o{¶H€.œ5Á:¹$m\ÌSJ\'„\Ë&\Z\Í\nh¯ðrØ•*0~1\×\íG+²\0N\èö\Íw?n\î\Þ\ÇbÝ‚;ƒ\Þô\à\Þ%Ížx€û\r‡\ÞÝ ‡&\Ç&6¬©S“\ÚT\Ô\Ù>:L*7±\è\">\Ïú°\ÏTÀ€Šxz\ÕO\îB(f@o\àˆ¤°Œ^\r\à&\0#¹žP  B\É\ìd¼/­ÊµI4\ïI\Ñ_?`EX\Þ=u\Ù¥²ø);ü\ÙZ<¤dý¹\Ú3{d\"£b³`1V¸\á}I\ã6\äv=\åWµ*€g¡¦”8b\çp\Ë@º}\nò)Ÿ8…¯·˜úŽÃ¸p\ãJˆ“¼C&„. ;†V.ö4†\Û`I`²Û›¼v?\ÉÊ‰\È\Úó`²Hˆ£\\\' \Äß£\ç>ø\ä{öQ0a3ú\å\nY\"¢{¹&r2\É\Ñ,<Fm~‚¸öpö½{X<‚»b¾¡@°T\ÈV‘õ2“eˆr¥µÀþŒ>\æ\Ý\Þÿöþuœ‡>²ó9n…³‘­úqb³\Å&»¼®\Í/9Apy\è¦<ùC²#;±¬Ã‡a!s F“€\ØÑ†ü\áQ“EùÅ¥¦\Ùl°Ÿ\Åc+1ZM\â\rÁ\ép;%\Ø2tÇ‰µ\ìø\0?&ôž\å£F\Z1#—qC*\ÊX[N\0¢±ù=>\Âs`\"ç•œ Š¿óz“„z\r\ì-U&s¶’¬–\ØÀ!“\"5‡¤\×\'ô-i‘“4º^(š–\ËQ\Ñ;^Œ\"4Ñ½ñz¨>9\r‚·\Ø)Æ•>?ˆ†\ê;\ÅI7\Üÿ_µÈ õ·ˆC\Ñ\Ê	«7\æ\ÃLh8-\í­BmZQñ½þ3~\ç9¯±Œƒ¦A¦F¥7>#\Ê‚¾TA?rYƒ§Fh\Z$xTD\'¾Óº¶T¯WhM\ë\à·\È!\ÍDG§\Ø\àye´A,qŽùzšPƒS(‡­c)C–\àä©—.°\å-’v+ ·4€y\Ö0ðZò.ÀŸ\Ñ>\à¡$Cõ\á[W\êÕ‰ói­#ö1a‡²\Î/Ä†eð…%b“£’£³¸•Q3\Â|ó<Ÿü{C=q˜\ÙmE´\Ò66²¬Y¾X‚Q\ÅyÀ9#³wn*a\"n€\n?Á\nô\ÆgÀP@\ß9¨A3\Ýw®¢þ\â>Øš\ÑQ	V\'§—\ÄVT\Ì\Ë@\ÊÌ¸2sz\îƒ\æÿ\â.C9/$8þ>\ì Á\è\è^\åˆb\ÈI\í‰\"Ÿ§Ž`“À\Ì\Ör8ÿG\ÂyeS€\Éd£#Sq$\n{\äžK‹ý\0\0ôb‹£h\×>Áú¸Ú´*Éª;’7\0\0·÷Å¬fm^¸}bS\á\è÷¸\îwŸµ.\É8,\n)s 8\ÛÁT?i&#n&\Û4R»\åPW\îTtß•O	ðe…ó,9LÁ E 7nÒ«\Â\å\Òp\å‡\ï¡ý\ãghŒX(|P[ü:‚ƒ\Õ\åjX=R¶\Ã\0ÿ‡\Ñ<nµ_\Î/]É²@\ÇT†9 0®a\Ø*æ¸†@ha³²\Ê_Dœ´\Ö\é\Ï\Â3[h\ãý„¢c—Sˆ\ÈY\Ó%;°<%“ž¦©¡{\Ø\Ý\ßEstŠ%3v‰~Vw<\è\Ö\Í\ïÿ„¾ø\Õ\Ì)PÁ;ð¾\ïpÔ\Z\×Nyt^\"òO)³ùµ\àÃ‰:?Àt$~)]\ìUrN]yÉ¡þ7¿—²Ï£µ·°Î• ;F©\0½£Qì” ¥Š93˜[,\Þ>À\Þr…\Õ\ã\ZMÇ—€Èšý>pvpc\Ô\ì\Þúš¿?,cñ\Î\Ê\Å.–¿ûOÁ]ú\æN\ï\âÚo¡}R\ãþ\Ý\ã\Ð)ù‰÷¬Jgb¶±±ƒÀ4¶T)\ÑbbNXNY›\ãúcõ1&\Êfæ»¹\äÏˆ\ÑT\ê)!”¸=­\Õ\ë \0´.Q\ìh\è\ç£:ü\ígø|½\Â!°•\0M}±\×e”¯U\à¦AA¥³o\èõ?°&T~cR\Ûüù\îñh`\â02\ÃLt(¶þ\n;•L\ÈOAÒ—)9q¤Þ©À­ó\Ø÷TÝ¹;\Îf\Åp2®÷ªHo\0s²„\Þ\ÑÀ%¹‰Aó\n‹ý=ÐŸV\0¢ô¡¢³«o_¾Ty(\è\ìJ¦c4uƒ¦kQ?^¡¼8G\Û·Q\ÖCñvm&”Jü]Þ™M\Æ\ÂøùMed\nŠ¾ø\áo,Ç¦\ÞT½ÿË¤\È\ß)u\Ü{…o, +\r¢…&|úû\Ïñ)°ô­Ïª7Ð¥[n\Ír‰\'5V’\Ú\Ñw\"ö\Ä,bj€\ÇX\çü†\ÇzG’\ÇFM9yw´\êbY!¦ÿØ°\êŒG\îml\'l‚QÙ´#n\Ó\êŠ9Á\Ë\Ûô\î¹\"T;\Z\Õ\ë¨,aš·O–7¶\0\àö\å\Å\éûßºò&ˆð\à\è§k4Áp™ú\áG‘‘p\Ê^<\0e\Ë{ø\ä†À\ç83”\ÔU\Í\\\Ôj\Ó9\â¾\ÓNûRög‡÷h8{\Ãóx\"6X\ìT\ÐÁe\"\èŽýi$=sš¹8‚ðšRf´\ÞlSªÁ“+}(\äü!\é\"§\Zu\ì|j\Þò\ßúv\Ê\îºx(`¡5vo\\\Å\'_\Þ\Û€;—g¤5œ,±²‚7!\É\ê!\0\"\ìzSyp¹\Ü\Òu;FcZ@ªy\émuÞ•\Ý1Ú®\Ç\â’û^PšaF\ëƒ6jcP\ÂT(\n„ò\Ù\rü@²\ÏB\ìŽ\×,A{tDŠ\ÂI¿°pm‘þX†P±ÀÒ²›`! c¨\Ê\Í0I&lk\Ýõ\ÚvXjpƒ„ r\ÓHÎœ€\"4«¥v›šz\àg@õZ…;]þaKk­¥\Ð\Ö\Æ\àT «®\Í\çøÁþ\ÕÁ)×µ`LkP?iPwŒ¹ŸI2»]!oaYYƒ¦\Û\ãöft1¸†\Ø\ï\r¦!˜ö“ƒ;\'/\Óð¦aE‹J\à&V+WW\í­SˆŽ\0,\à„<G\ï\ÕYŸ\ä^)q\ÈÙˆýG}k\à@¥€ýù{óóª\Â/üt\ë\Î[»g\0ððo©¼‘d,C“c9€@EB9#,;\Z\'\Ð:\×À\ËHÉöþ:\Ñp m¹‚CmJ\Ô\Ãnˆó\ÌLAVªAZŽ\ìÆ±‰\Ç_eSL´\\¶0€9\Ü\0OÉ²xH‹9ö©	\Í\Ê`\ë¶Â™ö\äÙ•\ì\ë‚nu´v\01j\Ëa+\ëË”öžó\ãX\Ø\'‘¢U:¥ó\Ämˆg{¾R¦\Ðó@@þnÀ­\0cST8\Õo\í¿\×pÇ½\è™vÉ¦˜\Ñú§\ZG ´QY³¼Ù¼W.¢´\ØC®ÿ\Ä\Èn²ƒ¹\Ókƒ\ÆOÙ‡Rk`VB\Ï\ç °ù\á\Ñ\á=P\îh\è‹À@³ª±2Œƒ\×	\0\Úü¤A½6\á1 ™r‰L!\Ï)6•øEè®”ºU>¦,{\\-[¥Î¨´\Ñ\0–\çh,\ßÓ»Wqxtø\å\Þ\å\êu{¯^›{\íù°ÿý\ë«GK,.V\×\ëGK´¼{\ã\à»/²¨~	¸Uø_Wp÷Ì¹)\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(3,'Producto3',30,61.768000000000015,15,38.23199999999999,'2015-12-31',2,0,0,'ÿ\Øÿ\à\0JFIF\0\0K\0K\0\0ÿ\Û\0C\0		\n\r\Z\Z $.\' \",#(7),01444\'9=82<.342ÿ\Û\0C			\r\r2!!22222222222222222222222222222222222222222222222222ÿÀ\0\0}\0–\"\0ÿ\Ä\0\0\0\0\0\0\0\0\0\0\0	\nÿ\Ä\0µ\0\0\0}\0!1AQa\"q2‘¡#B±ÁR\Ñð$3br‚	\n\Z%&\'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyzƒ„…†‡ˆ‰Š’“”•–—˜™š¢£¤¥¦§¨©ª²³´µ¶·¸¹º\Â\Ã\Ä\Å\Æ\Ç\È\É\Ê\Ò\Ó\Ô\Õ\Ö\×\Ø\Ù\Ú\á\â\ã\ä\å\æ\ç\è\é\êñòóôõö÷øùúÿ\Ä\0\0\0\0\0\0\0\0	\nÿ\Ä\0µ\0\0w\0!1AQaq\"2B‘¡±Á	#3Rðbr\Ñ\n$4\á%ñ\Z&\'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz‚ƒ„…†‡ˆ‰Š’“”•–—˜™š¢£¤¥¦§¨©ª²³´µ¶·¸¹º\Â\Ã\Ä\Å\Æ\Ç\È\É\Ê\Ò\Ó\Ô\Õ\Ö\×\Ø\Ù\Ú\â\ã\ä\å\æ\ç\è\é\êòóôõö÷øùúÿ\Ú\0\0\0?\0\çd`D	¹—$¹\çú\Ñy±\Ú\åÀ\Î{WX4€·N±D_\à\ëW[\Â\é{n\æSþ ¾Ÿˆ¯S”\á*\áoJWm]>\ä.1Ì£ÿ\0k÷b›N=ùù¿†g\ÙrAÁû§ó¯@\ÜÄ¬¤ð®•k\Zm3n8\Îjb$„3¬»\Õxùº\â¾70\á\ÜW²sŠ¿]?³\Ä\Ø^!:s³}ÕVŽ9#òÂƒ\êq\\^¯á©­o\Úÿ\0L-¼œºŒ\Z\é\í/C\är:Õ€\á=\Í|½*\Õa-7\Úß¡Ô±\n:³+K¹k¸\Ã8hœ|’F\0ÿ\0†*È…LÁð00)“¼QN€Ž?[+”q¸üŸ+Á8\í^\Æ\ZW\\Ý™\ëa±‘\ÄÁ\Û}Ÿõ\æ[I\áVaiÝ’yöü:\Õ{©KY‰À]„\á}¹âœ¨ªØD{G$®\ÇOñª³0\ZdÄŒüŽ}ú•\Õõ\ÜEJñr•\Þ\æoB4eNIZ\Öùh¦\âhÃ–Tˆô=p}*î¡­¶Žc;G!Ú’ $\é\í\\þ‘|v\0™\n¹\ãWJ.’\î\ËÉ™2={ý+†x5f\î­-\ï}\ß\Ü|}<Ú¥R…uxvZ}Ì|DŽõºù\ÛÀ¬‘\Z† ô\Ôw-1e°9\îk\ÆXH9Y#\èñ\ÊQ´:—›_\Îp~´Ñ®0;‰ ‡9®:ö\â{™XX\Û\Ë&\ÞE\ÈC¬¨\ZH˜u¯{	—N0\çQ•¼“>_”J«\æu\"»&\Òq\Ù7ˆYH;¿ZzxND~^[°®*Ar¿òÍ†z\rµkMgF•ŠHq\Ë`µµ:*\Õ\äRjûYw\rÔ«YB¢|½_‘±¨\êÒ‰ƒJ\î†R3\Øz\ÑY¤K\ç\ÆiùÂ–ž™õ\âŠúXG’*1\Ù¨R\ÃÒ¥N4\ád¿®‡eu–ñ-Íº\å3‡#¦OµFš†ôô\ÇCŠ¹\à€\n§–z©\\\çŽõÁx»I\Ö,L—\ÚL=ˆû\ÈÔž\Û}ûU\ä\Ù\Å`¨\ÔZ­\Ì3\î­Š\Ä{zO}\×õøüŽÅ®‘ø\ì8ªM\"\0\Ì\Äµ\Âi>!Ô¥mþ\É$\Ï\Ó)c^¥h³$~~¤UŽx2qõ\Í{Ÿ\ÚxhÅ´|V3%\Ä\áj¥U:&¬\Íw,ò\È!°f\Ì{†X§j\è\ä²x\Ô>\ì›qšÑ¨S·¿\\uüª•\Ìê‰†\'§ð\Ø\Ì=Q\ÔpJ\ç­Â²´/ts÷s ™’O—jô\Ïz›J\Ô\æS¹ùŒzzÊ¹\ß«À±0{©þtÿ\0y‰­E—m²F\çõ\ÇNj:/ò>\ã)ÁÕ‚X‹\ÙIj¬wnŒ¡”l\çœ:Uy²\å9,>\ìv¢GX€_™wry\ëô§®M0¾y\r•8ÁÔ¨¥õ‹>\ß\ä}.Šý\Î´ú|¡‘\Ø\Æü©ö?•h¦«s.7\ÈÀ}zU8%ýü°Ê£b’6I \Z\Î\ÔL–SyD6\Öû‡Öºqx9/z›\ÑþˆÈ°\ÞÓ™CSV\çYû8\á²kSJ\Òn.]_\äŽ nq\ï\\ÿ\0‡tÁw¨}¢ð©÷ýÜœõ®ýdû+m£ý\Ó^þI‘Ó„Uz±»{/ÕŸŸñnkõI<GöŸU~‹õ&‹Oµ·\ËE@GEPC:Cc°c8Ï½T½¿*]:1\ès\Æ+’\Õu¿+#\Ìb\ÝÓžõô\Õ\'Oj²²\ì|–_—\âñõmM=÷\Öÿ\0?\ë\æt3\ÝÁ’‚4Ýœc¾k\Z\í|ùrH8p=©šB\È\Ð\ég“)>\Ïÿ\0^­\0© ’rþI$*õ\äc®~µó7UjJ½¬ž\Ë\Ëþ	û¶S„x,<i\É\ÞIjú¶$H\î\á·\î\îË€>˜\éE$P\È&d†Gr\Ãw\ÌNqÀ\ë\éEc*ð‹³==w:¸n·EWRsœ\çù}*e¸\Û&#85›£\èW\ZV—7FY¦\Þ\0\Æ9«^f\Íû\É Á\ã\Ïùô¯Œ¡R|´\åª\í\äxw„\Óqw.Z\Û\Ù\Ã4³[D#–C—û\í\ëM7Ÿ¼8Êœü\Êx¨’WŽ8ˆÊ†\ã‘\ïK:<\ÊX\ß(;Wû\Þ\Õötò¼J\ÃF£z\ïo\ë©ùfu˜ak\ãeJÓ½›\è\ßõò-í½²y…Žq\Íp^#ñD\Ó\Ê\Ð\Ûna\Î_*\Ó&\ãRœ	þT\ìƒú\Ô\í¥\ÛÊžQzsÀ¯­uf©(\Þ\îÞ¬ú<—)§\n‘ž!s>\Ý?\àœÞ‹¤=ê›‹’V.\Äÿ\0­I\ni\×L±¨\Ë\Æ\Æ\Ïz\é-4ˆ¤‹\Îgh\ã\Æ4\0Uu%\Ìr4S¸f^À9ôÁ\ìÆ¾ŽžSjWQ»>¡ñQ‡\Å}RµD¥³\Ñ\Ù?7²,®\É\Ò7B3òõ\é\Ç?L\ÔöŽ<¦F#Ðƒ×š\ä´Ë¹´‹§jq´Ž\è¤c¹}6ñÛ½m%Ð¶>`‘»ŸZùÊ°•\Z\ÊM[¹\éÊ”dŸ³—2\è\Ö\Ïç±Ÿ©AµôË»æ˜™1\á\'üj­ò¥Í£‡e2/Ì¸õ¤ÕµumEG\Ä{I\'‘\É\ïUm\ç\ß2[€\Îs‚N+ß¡Z3‚=HRŸ²R–ö4´9z`2/$ý\ÑÔŸJ\ÝûUª\Ä\Å\Är3`Ž£§\Þõœ‘\Åi”\Ï\Z0bW,²’Aü3ø\Ô-)fM\Þb»\åÂª’\Ó\Ðð{Ÿ ô\Þ&§*ŠvIW>jžEƒugZ¤§6\Ûm_ä¯²ü\ÃT³ó$S\á$\ç=ÇµVƒ\Âk¨Ì‹!)\n6]±\×ýš\Õ\Ó\Ð\Þ\Í.¿\Þ?\Ý\íúWS1\Ã–ª09\é\×Þ¾+5\Ì\å<[÷¹šØšp§—I\ÓÃ«/#ž¼´·²E\'.ªHsƒŸÆ²®.…™GxY¢e\Ú=þ}\ë \Ô\'›\Æxx\Æ+˜ž).§ ;2!$.x\í]Ô³‹Òµ¯$º#\Ú\Â{\êó\Øg‡®L:­À\Î7GO\ÔQYwKK\×1±V\Æ3\íEpª®^ó\êt\Ö\Ã*³\çg®Ìª23Š\Â\ÕZ(ƒ\å°q\×4šßˆ­¬\îb\\ôQ\Ô\×=¤­Çˆ/\r\Å\Ã7\Ù\Ôü±ôýzð¨S•¹–Šú?òÿ\03\ä¡µ“±r\ÇQŸ\í9\ÏÈ¬Y~^¹­¬—~—\Æ\Þ*œ±Am*ª¡TSƒù\ÕÀˆ‘`¶\âz\ØW\êyeõ\Ì7,¾8hý:3ò\Þ\'\Ë^\í\éü\Õy2½\ä;\ÃÜ¢\ß\Æ\0ÏµPPKœ0°\'º{Ö¸\ÉCm„u…|V\Î\á£óÉ²TŒ\Û?•aŒ\Êi\Ç±pû¼ûÿ\0]O¬\à|\Õb_\Õk¿}-<\×UòFÅ•\ä3C·+ò»Ÿþ½Z\ÈFC\ZŽ\ês\×üûW{u=µ\îm\çh¥>\êŽ;søVÆ‡\â/µ\íŽ\ëlR`\r\Ç8c\ÎMv\áó\nNJGgÓ³ÿ\0‚sqOb0\Õ%\Ã{Ð“»_j-\ëó^kU\Ô\Ù\Ôl\"¾³x\æ]9\ã®\rr²xRu2-…\ÙT#)„œœr3\îz}k®ó›y9Xt\ÎÓž½i¬\è.\æ+ÜŸzí¯‚£‰V«ùõ>o/\â\Ã)i\á§\î\ßX½Sûöü\åW0]\é\Ò\â\ê\ÞXN\å¢Ÿ¦zÖ¿†^j\Îø)fL\î\Â\î\Ïö\ê]\íý´Ð›køRh3»\"\äžÕý™•bñ\Ø\Æ#óÎ¹\É\Ú3\×=}?ó_=W)–jjW\â~¹‘q”s˜Jƒ¦\á4µê­¦Ï¥û0›É»ºX²°\"¯;Øœp	\È\ã=9\ÎsL¤yŒ$(€Bü\ÃolŒ“\Ï\â*ËŒ[µÇ’\êB\à©\àF0x=;úVÅ±ýó8þ&\'©9\ç\Ôòk\Ï\Íq¯G\Ý\Ý\ì{Õ­J?#v\Â1jž\ëBY•\"+\Üõ=«:\ÚEe\0š&šY1\Ò\Ì\Ù(‹Œ‘\ëšø8\Âu\'¦\ìùŠõ’“”\ÌMQ0ùp!\Ìò’°õ5¿\î\áÔ’\á\Ðg\ëZcÀ·3Jo.5ö¢2\"1\åG§ÍŸ¥T’g\'\Ù\æY\âÂ²“‚I\ïø\×\ÚeXÐ‹RÝž\Þ0\Âbi(P•\ä·_\×B˜²Š[†yr¼d\ÑNšo,€\0Ž\Åž#+rª\Ü‘\é¥6®Œ;&\ÔeŽ{™2§²Ü·°¯G·’\íDV\Å·Ž=«•6\ß\è\ÃË€EChRx\ê}\Ï~µ*^[\ØO<‚uš%\ëG\Ê`\n¬^\Ù\áù£¬—õ¡\ã\Ç-„i»;\Ëwý]\Í]Nò8L÷2**÷\'­Kex—z|E7,ˆ\r\Æß¨ëŒ·µ¹ñn²nfV\ZtL| F_\ÌWk*$ª ·\0j8j½,6-Ò«/zk\å}\Òõ>‰ðÒ¯„ý\Ú\Ö/ð\Ø|¤\ï8+\é\Ær}\ë\Ä\n\ë£\Ë$d\ïB\ëƒúU\Ù.ŒNÄ±P¤H\é“\é\Îk6þøN¦%9œŒt\ÎÈ¯¼\Ç\ÉS\Â\Îý´óoo\Äù\Âb#›Ñ«»¦ž\Ý:œ¼o+N;KÃŠÖµ\ÓB[+6rG@*\ï\Ø-%(ò\ÂU÷`\'_J²cP¡\à}\îÂ¾†ª\í9h½n~½\Äy¥J\nQ´vùœÖ“¯\Ëi,ö·,\Ò(r1%“··µu0^	¢ý\Ä\Ë&\ÒyCšó\çU\Ön•_#\Îlþu\ÒxcN¾¼\Õm\ÖÙžcË…\ÈU\îpx<v\ïÒ½LyW	\Z¾ôx9\ß`³\ZY£/g6¯¢\Ñú®\Í}\Çua–\àn£Oó\Î}«Z\Ýó™pª\Ã\\ó\Ô\\ŸÃ¥w\Ñ[‹[e€r02@\'\ÏÖ¹\ÍF3o›\î\'\Ì/½pâ¸“\ë8‹\ÅZ;%¥ýNŽ\Ë\ã•Rä“¼¤\î\ß%\èr–W&@#ft\Üûƒ\ÏO\\}*ðF¶\áÁ?)\Ç³D¦\ãS’f\Æ\Â@\èa\ßüšÛ“Ê¹²{Ir”ƒ÷O­pceO\ä\×S\é\ç\Z³››Z=—‘\\k1B\ÞX\0zV\îŸ·\06©#©¯0»‰ »xFZEl.\Ñ\ÉôÀ®‹@ŸP\ÇúM•\Ìx+\É(o\Çr\Ò\Ã(¯w\ï>o>\Ê\êÖ¥zO\äz$wŠ\ÊH\Æ\á\×=Mr¾.¼‰n,‹\íƒo`A\àþ&Ÿý§?8p\Ã=¸õ®?\\Õ›U\Ôv m©¸c\êÏ¥va\êJ}O+ƒ2\ÜR\Í¦šŒS»³\ê´:X<™úüôõ\Çcþ{\ÑUt9mKný\é8ù¾\è\çùQ_KN*Lýªp›Š1U]¬BG \Î\Òs¸u\ç\áY\"\Ö]Z\äZA,°ó\à\ÜsQy—\ZÐ·µ\"F^Š¼¥w\Ú‹‘h¡±¿«\Zù\Ü\×1´yc±ÉŽ\ÇBŒ](»·¿õù–´\Ý:-3OŠP\0\\q\íSGi\æ#ò¸\àõ4H\×2¶\Ò6ó\Z¾Tµz_%\êN÷ÿ\03\æ¥}ú³˜½Ò–Ffr\Ãñ¬–´K[Ø€³óŽ¹\àZ\êµ+¤µË•b8aÉ®eL’3oG\Ù }8\ã×°ü=\ë\êòXV­W\ÚÔ“qŽ\×o}½4G«–QP½NT†\Î¥F\Û\'\ÊËG\0õ\é\ï\Í6 |\ã¸\çŽAÁ9\çÒ¨\\\Ë4Q\Æ#“o˜69À‡© Žžõ·¤hó\ê$\Ì$a‡+\É\ëÛ¥wf¸¨\Æ\Ñ8ø¢2–\Z+¹;ú%\×\ïv8[/‹\Íjiþg2\\³$c¡«\×4M!4\ä2:*\ÊF\0\Â*å†•e¦#XBÄ³’\Ç\×54²\ázŒ€x¯”\Æ\ã%9{®\ç›G\Û8þöWü‘ÄTŒð\rp\Þ\'Ô™\ãx##jò\äw\éô­cSLd=\Ça\\^°qp[|\ÓJ\ØØœœwÏ \é\Ís\à(\ÊS^}_(Æ¢r\Þx\Þ\ÕX¤€ÀšÞ´\Ód1¹\Ìqö\Ú~r~=j=F\Z=º<ÎrNCˆ1\Ñ}~µµ<¨‘‡/…#Ó¿û\ÇùW½<,©¶¦¬\×s\Øx\èVW \îŸ_ò!K[hdY#·„L9óp7ŸCœgùS\ZWV@º\àò*G¼Hö\à0\Ü$®xü1úö¬ù5UI7t÷/S\ëS)B-7\"!Nn\î\Ä\×\ZtŒ\íù›\åsÒ¹mr\Ò+]FÊ«2²ð9%y­K\Ï\Û\ÃI5\ÂÆ„ò­Œý:×Ÿ\ê¾!—Q\Õà»µKbq¸›=W£‡Œ*K÷k\æD³(`\Z•I|ºùþa§ˆ¤\Ý2c\æù[ÞŸÒŠ-#š\æ½[)\"i\n:œýh®õŽ¡vSI¯3\×Ui\ÖJ¤%£ô:}\'L²Ð—Ê‹il»ŽM]:™s°9óX(\Ï=kö\à‘²fùaXw\ãY‘kRY\êq:\î‘c`IÀ\Î\Üóø\×\Íc©ûG\Ëø•e[\ÅT\Òíž¥Q\Û[¬`ƒÏ¹õª\×À¬ò6Ñž¾Ô–·K}g\Ìj\Þ[®@aƒ\\®¥y;\\²»•›{pzv®¯,e_ÝŒ~ó\êð˜GRM7°ûëµ¹‘üÀ	C´ ly|½sžzú³\îo\æ†\ß\åG&3³\ä\Â\í\èF8\Æ:©I\ïBù‘(o1\ÆA<‘Œ\äu\ç“Ó¶¥c\Ý\ß,p€4\äaX \à÷?¯_Î¾\Úu)\áirAZ\Ûó…<=\'R§\Ã\ëñ\'kƒöÇŠ3¼ö¹c“L×£\èwP&\Û\Ê\Æ``z÷ýk\Ët¨™¢\Â\ã\Ï9É­1=Í„l`˜ÇŸ¼\Æp+\å±ôjbU\Ó?<\Å\ç\Þ\×)\ÔZ=’þ·=:kø\ÔJ\í\Ç\Í_øš\"Œ–Œ¯!\àœŠç­´\Ý[S	%ü\Ï)\ë\ËcúzÖ¤z¨i3Ž¡Cg½aK*©\'y~G.#:…= Š^kH\Å\É-#\Ç?\\U\Û+QŸh••\'t\Ú\Ìq…\\ô÷\ÏúU‹[eFiq¤\ìƒõ\çµ+¯\Ê\áUƒ÷›8\Æ;óÖ¾ó\"\È\áB\Õ\êo\Ñvóõ>0ÏªW²ƒ²{ÿ\0‘\Ú$\".\Ãü[‡#µS[°¬\âwMŠ¸\Üxù\r-ÉŠ\Î2óJ±\Æ@;€PO\æ÷^\"Ôµ\ëÀ°Ž\Ñ\n¸\'qõ5\égx:\ér¥ûÇ·ü·‡3LN\Z³|ßº[\ßô:½K\ÄemŸ\Èj ÷®*K›\ë·-=Ä§\'¦\ãøVªX\É>\ß8–\ÇOA[\Z6ˆ·w\Éƒ·\ï1‚¼jyLpT%^½´W~G­˜qñõ£F…\Òü\ÎO\ÐnuËµµ‰‹3œ–nv_\Ã5\è¾ð›¤\Æ\Æñ\äù\á¤PT}j\ê-,-\ì\áT‚5E^€Q5ÁPqÖ¾/žJ½\áG\Ý_Ÿõ\Ø\ï\Ãayu“»+Î‘¡\0`¨\à(¨\'bÿ\0+”W—\È\å©\ë\ÆqJ\Ì\ànu9u)¶[’-»ñÖºÿ\0xZ9\íw\ÈLyù\"n7{ŸocX¾°‚\ç\\†Pb\nX©\0ƒ€x5\é\ÛB`‚½<\ê¬ð\Õ}Œw\îs\àq1Ž0¢¹nµ\î#mX‚ª€ª0\0À\0W!¬#FóHŒ©\Úry>˜üù÷®ž\êB¨H®:ù\Ú\âr®N\éš\ãÀ\âªQŸ4>g«€“‹l\çs´¬\Ýùž¸\É\ëY:°t\àö®®HQG°õ(U\îÚ½HbgRw›:jVxºœ³ø{t\"\Òu6S)h\ï3¶Ðª\Ø\ÞOlö¯C\Ó|7…e¾ò²ƒ´üÊ‡¾9\ç\ë\\\ï…l \Z¾ò€˜\ã,¹õ$\n\î\Zv\ÆG^œf½*SQÚ¹ù\ÏÂ†\ì\éF\Ý_\ÌQˆ,FQxù@/©ªSòDI_Œ©\ä`sÒ¬™\Æ-\ÈgÖª\Û\Æ^òwwfÀô\Èüó^¾YIV«yt>;\'o6Gp \Ù\Z\Ã\å?ýzwöt\Å¼ªe=°sžjÖœC¼\àŽ\ä\äúÕ—bòn<×™gðÕ\ZI$¼¯s\nu(ª\ê\Ï>ñ§†<E­\Ú[\Ú\Ø\ÃÀt¨f\n\Ù\ì~lqô\'ô¬»O	\Üi1*Ig$drN2	úŽ+\Ö!a<€0\ÇA\Ç\ãK*®GË2\0\'=\Íc…Íª*ŽµH©~¯7‡T¢\ì—\ã\êy²Ú®>\åhøz[hõy!,¢_+;{\ã5\×]\é¶S€\Z\ÝT‘œ§\Ês\\\ÅÇ„\â\Óu©\Ú\ß\\‰³\Ñð\ÃµvgŒ1x\'Jµ÷6\Ë0Î–%Tœ´[I™òqTn\î­\í\ã2\Ë\"*Ž¬\Çª\í;ü\ê†©-ªjN¦\ç\çU8	ü?•~S\Zq„Ÿ7C\î\é^Q¼LmCQ\Ôui\Ê\é\Ë*À¯ù\Í\ÞZ\Ø[Á\0ò/8\àbŠõœ\Ò\éù1Æ¥•š?ÿ\Ù',1,1,1,0,'','',1,0,0,'',0,1,0,0),(4,'Paquete1',79.99,1,39.995,0,'0000-00-00',1,0,0,NULL,1,1,1,0,'','',1,0,1,'1/3,2/2,3/0.333',0,1,0,0);
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
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stock_corrections`
--

LOCK TABLES `stock_corrections` WRITE;
/*!40000 ALTER TABLE `stock_corrections` DISABLE KEYS */;
INSERT INTO `stock_corrections` VALUES (1,3,100,0,'Adjust','2015-12-28','12:22');
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
INSERT INTO `transactionitems` VALUES (4,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(4,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(4,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(5,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(5,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(5,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(7,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(7,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(7,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(10,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(10,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(10,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(11,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(11,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(11,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(12,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(12,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(12,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(15,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(15,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(15,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(21,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(21,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(21,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(23,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(23,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(23,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(25,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(25,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(25,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(27,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(27,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(27,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(29,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(31,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(32,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(32,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(32,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(33,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(33,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(33,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(34,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(34,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(34,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(36,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(36,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(36,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(39,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(39,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(39,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(41,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(41,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(41,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(43,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(43,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(43,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(46,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(46,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(46,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(48,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(48,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(48,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(50,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(50,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(50,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(53,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(53,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(53,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(55,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(55,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(55,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(57,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(57,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(57,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(60,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(60,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(60,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(62,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(62,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(62,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(64,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(64,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(64,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(66,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(66,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(66,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(67,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(67,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(67,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(69,1,1,2,0,'Pc',5,10,0,20,'Producto1',0,1,'',0,NULL,0),(69,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(69,3,3,1,0,'Pc',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(75,1,3,0.5,0,'Kg',15,30,0,15,'Producto3',0,1,'',0,NULL,0),(76,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(76,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(76,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(78,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(78,2,2,2,0,'Pc',10,20,0,40,'Producto2',0,1,'',0,NULL,0),(78,3,3,0.3,0,'Kg',15,30,0,9,'Producto3',0,1,'',0,NULL,0),(81,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(81,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(81,3,3,0.6,0,'Kg',15,30,0,18,'Producto3',0,1,'',0,NULL,0),(83,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(83,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(83,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(88,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(88,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(88,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(88,4,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(90,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(90,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(90,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(92,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(92,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(92,3,3,1,0,'Kg',15,30,0,30,'Producto3',0,1,'',0,NULL,0),(94,1,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(96,1,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(98,1,4,1,0,'Pc',39.995,79.99,0,79.99,'Paquete1|  3   Producto1|  2   Producto2|  0.333 Kg Producto3',0,1,'',1,NULL,0),(100,1,1,1,0,'Pc',5,10,0,10,'Producto1',0,1,'',0,NULL,0),(100,2,2,1,0,'Pc',10,20,0,20,'Producto2',0,1,'',0,NULL,0),(100,3,3,0.5,0,'Kg',15,30,0,15,'Producto3',0,1,'',0,NULL,0);
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
) ENGINE=MyISAM AUTO_INCREMENT=102 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,1,2,500,'2015-12-28','12:21:00',0,0,1,17612688,2,1,'-NA-',100,'1/100',0,0,0,'-NA-',0,0,1,'',0,0),(2,1,2,1000,'2015-12-28','12:21:00',0,0,1,17612688,2,1,'-NA-',100,'2/100',0,0,0,'-NA-',0,0,1,'',0,0),(39,1,1,60,'2015-12-29','17:37:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,24,0),(4,1,1,60,'2015-12-28','12:23:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,6,0),(5,1,1,60,'2015-12-28','12:23:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,6,0),(7,1,1,60,'2015-12-28','12:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,7,0),(21,1,1,60,'2015-12-28','22:34:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,15,0),(29,1,1,10,'2015-12-29','10:07:00',10,0,1,1,2,1,'',1,'1/1',0,0,0,'',5,1,1,NULL,19,0),(10,1,1,60,'2015-12-28','22:10:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,9,0),(11,1,1,60,'2015-12-28','22:11:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,9,0),(12,1,1,60,'2015-12-28','22:11:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,9,0),(46,1,1,60,'2015-12-29','18:57:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,28,0),(43,1,1,60,'2015-12-29','17:40:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,26,0),(15,1,1,60,'2015-12-28','22:22:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,10,0),(27,1,1,60,'2015-12-28','22:46:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,18,0),(23,1,1,60,'2015-12-28','22:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,16,0),(25,1,1,60,'2015-12-28','22:44:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,17,0),(31,1,1,10,'2015-12-29','10:11:00',10,0,1,1,2,1,'',1,'1/1',0,0,0,'',5,1,1,NULL,20,0),(32,1,1,60,'2015-12-29','11:49:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,20,0),(33,1,1,60,'2015-12-29','11:50:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,20,0),(34,1,1,60,'2015-12-29','11:51:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,20,0),(36,1,1,60,'2015-12-29','17:36:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,22,0),(41,1,1,60,'2015-12-29','17:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,25,0),(67,1,1,60,'2015-12-29','19:59:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,39,0),(48,1,1,60,'2015-12-29','19:00:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,29,0),(66,1,1,60,'2015-12-29','19:59:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,39,0),(50,1,1,60,'2015-12-29','19:35:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,30,0),(53,1,1,60,'2015-12-29','19:36:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,32,0),(64,1,1,60,'2015-12-29','19:55:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,38,0),(55,1,1,60,'2015-12-29','19:38:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,33,0),(60,1,1,60,'2015-12-29','19:42:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,36,0),(57,1,1,60,'2015-12-29','19:41:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,34,0),(62,1,1,60,'2015-12-29','19:53:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,37,0),(69,1,1,70,'2015-12-29','20:02:00',100,30,1,1,2,1,'',4,'1/2,2/1,3/1',0,0,0,'',35,1,1,NULL,40,0),(76,1,1,60,'2015-12-30','11:11:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,45,0),(75,1,1,15,'2015-12-30','11:10:00',20,5,1,1,2,1,'',1,'3/0.5',0,0,0,'',7.5,1,1,NULL,45,0),(83,1,1,60,'2015-12-30','13:36:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,49,0),(78,1,1,59,'2015-12-30','11:21:00',60,1,1,1,2,1,'',4,'1/1,2/2,3/0.3',0,0,0,'',29.5,1,1,NULL,46,0),(81,1,1,48,'2015-12-30','12:21:00',60,12,1,1,2,1,'',3,'1/1,2/1,3/0.6',0,0,0,'',24,1,1,NULL,48,0),(88,1,1,139.99,'2015-12-30','22:06:00',140,0.009999999999990905,1,1,2,1,'',4,'1/1,2/1,3/1,4/1',0,0,0,'',69.995,1,1,NULL,52,0),(87,1,2,39.995,'2015-12-30','22:05:00',0,0,1,3791600,2,1,'-NA-',1,'4/1',0,0,0,'-NA-',0,0,1,'',0,0),(90,1,1,60,'2015-12-30','23:44:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,53,0),(98,1,1,79.99,'2015-12-30','23:50:00',80,0.010000000000005116,1,1,2,1,'',1,'4/1',0,0,0,'',39.995,1,1,NULL,57,0),(92,1,1,60,'2015-12-30','23:44:00',60,0,1,1,2,1,'',3,'1/1,2/1,3/1',0,0,0,'',30,1,1,NULL,54,0),(94,1,1,79.99,'2015-12-30','23:48:00',80,0.010000000000005116,1,1,2,1,'',1,'4/1',0,0,0,'',39.995,1,1,NULL,55,0),(96,1,1,79.99,'2015-12-30','23:49:00',80,0.010000000000005116,1,1,2,1,'',1,'4/1',0,0,0,'',39.995,1,1,NULL,56,0),(100,1,1,45,'2015-12-31','00:05:00',45,0,1,1,2,1,'',3,'1/1,2/1,3/0.5',0,0,0,'',22.5,1,1,NULL,58,0);
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

-- Dump completed on 2015-12-31  0:09:13
