-- MySQL dump 10.13  Distrib 5.5.43, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: iotposdb
-- ------------------------------------------------------
-- Server version	5.5.43-0ubuntu0.14.04.1

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
) ENGINE=MyISAM AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `balances`
--

LOCK TABLES `balances` WRITE;
/*!40000 ALTER TABLE `balances` DISABLE KEYS */;
INSERT INTO `balances` VALUES (1,'2016-01-16 09:18:35','2016-01-16 09:18:35',1,'admin',0,0,0,0,0,'',1,'',0),(2,'2016-01-16 09:34:55','2016-01-16 09:34:55',1,'admin',0,0,0,0,0,'',1,'',0),(3,'2016-01-18 21:51:59','2016-01-18 21:53:57',1,'admin',100,200,0,300,0,'5,6,7',1,NULL,1),(4,'2016-01-19 13:38:41','2016-01-19 13:38:42',1,'admin',100,0,0,100,0,'',1,NULL,0),(5,'2016-01-20 10:43:42','2016-01-20 10:44:42',1,'admin',100,0,0,100,0,'',1,NULL,1),(6,'2016-01-20 12:33:59','2016-01-20 12:33:59',1,'admin',0,0,0,0,0,'',1,'',0),(7,'2016-01-20 12:39:47','2016-01-20 12:41:33',1,'admin',100,80,0,180,0,'11',1,NULL,1),(8,'2016-01-20 12:45:47','2016-01-20 12:46:29',1,'admin',100,0,0,100,0,'',1,NULL,1),(9,'2016-01-20 12:49:16','2016-01-20 12:49:27',1,'admin',100,0,0,100,0,'',1,NULL,1),(10,'2016-01-20 12:49:51','2016-01-20 12:50:17',1,'admin',100,0,0,100,0,'',1,NULL,1),(11,'2016-01-20 12:50:36','2016-01-20 12:51:50',1,'admin',100,0,0,100,0,'',1,NULL,1),(12,'2016-01-21 12:00:26','2016-01-21 12:00:37',1,'admin',100,0,0,100,0,'',1,NULL,1),(13,'2016-01-21 12:22:52','2016-01-21 12:24:17',1,'admin',100,0,0,100,0,'',1,NULL,1),(14,'2016-01-21 12:40:34','2016-01-21 12:40:56',1,'admin',100,0,0,100,0,'',1,NULL,1),(15,'2016-01-21 13:46:30','2016-01-21 13:47:27',1,'admin',100,120,0,220,0,'20',1,NULL,1),(16,'2016-01-21 13:57:40','2016-01-21 14:16:10',1,'admin',100,0,0,100,0,'',1,NULL,1),(17,'2016-01-21 14:01:42','2016-01-21 14:07:54',1,'admin',100,0,0,100,0,'',1,NULL,1),(18,'2016-01-21 14:02:47','2016-01-21 14:07:43',1,'admin',100,0,0,100,0,'',1,NULL,1),(19,'2016-01-21 14:04:35','2016-01-21 14:07:34',1,'admin',100,0,0,100,0,'',1,NULL,1),(20,'2016-01-21 14:05:42','2016-01-21 14:07:48',1,'admin',100,0,0,100,0,'',1,NULL,1),(21,'2016-01-21 14:07:01','2016-01-21 14:07:40',1,'admin',100,0,0,100,0,'',1,NULL,1),(22,'2016-01-21 20:32:33','2016-01-21 20:32:53',1,'admin',100,0,0,100,0,'',1,NULL,1),(23,'2016-01-24 22:25:31','2016-01-24 22:26:24',1,'admin',100,0,0,100,0,'',1,NULL,1),(24,'2016-01-25 13:07:48','2016-01-25 13:08:28',1,'admin',100,80,0,180,0,'33',1,NULL,1);
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
INSERT INTO `config` VALUES ('yes, it is February 6 1978',0,'','IotPOS Store','','',0,0,1,'0950');
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
) ENGINE=MyISAM AUTO_INCREMENT=30 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `logs`
--

LOCK TABLES `logs` WRITE;
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
INSERT INTO `logs` VALUES (1,1,'2016-01-16','09:28','[SQUEEZE] Purchase #1 - 100 x Herashey bar (1234567890123)'),(2,1,'2016-01-16','09:29','[SQUEEZE] Purchase #2 - 1000 x Doritos Nacho (1234567890124)'),(3,1,'2016-01-16','09:30','[SQUEEZE] Purchase #3 - 1000 x Coca Cola (1234567890125)'),(4,1,'2016-01-16','09:34','[SQUEEZE] Purchase #4 - 1 x Paq 1 (1234567890126)'),(5,1,'2016-01-18','21:51','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(6,1,'2016-01-19','13:38','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(7,1,'2016-01-20','10:43','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(8,1,'2016-01-20','12:39','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(9,1,'2016-01-20','12:45','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(10,1,'2016-01-20','12:49','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(11,1,'2016-01-20','12:49','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(12,1,'2016-01-20','12:50','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(13,1,'2016-01-21','12:00','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(14,1,'2016-01-21','12:22','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(15,1,'2016-01-21','12:40','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(16,1,'2016-01-21','13:46','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(17,1,'2016-01-21','13:56','[IOTSTOCK] Purchase #22 - 100 x Raw (1,234,567,890,127)'),(18,1,'2016-01-21','13:56','[IOTSTOCK] Purchase #23 - 0 x Unlimited (1,234,567,890,128)'),(19,1,'2016-01-21','13:57','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(20,1,'2016-01-21','14:01','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(21,1,'2016-01-21','14:02','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(22,1,'2016-01-21','14:04','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(23,1,'2016-01-21','14:05','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(24,1,'2016-01-21','14:07','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(25,1,'2016-01-21','20:32','[ IOTPOS ] Operation Started by Administrator at terminal 1'),(26,1,'2016-01-24','21:40','[IOTSTOCK] Purchase #31 - 100 x Pretzel (1,234,567,890,129)'),(27,1,'2016-01-24','22:25','[ IOTPOS ] Operation Started by Administrator at terminal 1'),(28,1,'2016-01-25','13:07','[ IOTPOS ] Operation Started by Administrator at terminal 1'),(29,1,'2016-01-25','20:22','[IOTSTOCK] Purchase #35 - 20 x Neon Jelly  (1,234,567,890,130)');
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
INSERT INTO `products` VALUES (1234567890123,'Herashey bar',10,88,5,12,'2016-01-25',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0R\0\0\06\0\0\0TIÎ×\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0\0\0\0šœ\0\0}IDATxœí›i˜Õ¹Ç§ªzïéY`€A#‚\"(QrAcâI4.‰AePQŠ8 ^Ñô1ñzo4Q£qÁ0‘(\"8îÆõê…‹JŒ»AD4¸°3[÷ôRÕµœû¡º«»º‡˜¹Ñä™?OCªS§Þó?ïzª€>ô¡}èCúÐ‡)œ4î|šÞø‘ãä¤Ä`Yy]û2„úgÂ‰áAãŽØÿ µx+esûNR9½ª_‘½`4µu\rŠò½aN¸mÀð<°y‡†êˆ†#llßÑë=â,ãW‡„ë÷‹ÎÕÉðýT]ÖÆ©¾?÷}ú.{ö0„*`áZµD­—dw±ÿ¿´FJÍˆ­dn´Q~Xœh\r*\rO=Z\"H _-\0f(€iY\0X¶E0“ÝDQè$åŽ1EžgŠíj\"ÇÒÝªv—³í;5Ä~\0!¢¨$ÐŒrd¬‰P}‚þÁ(Z<J@s§œÌ¤Éê:)C\'Í’7ó¤ô,ŽåHÄkh¬o ª‘ª‚´%¢Ì€»óÙ;àŸˆÈÑÔÖm#3ÇëÂâh4 ÎðÀ\0ô¯£®iÑp-Ä2ò$3i:SIrºNûî]|jYXŽƒª(ì3` ºaÊ¤Ñóy²2Ï÷.$ŠFùÍñ§#x4JÂvå°Ëˆ¢P.çWÂG®ßo§ž¾ÈB^îêº„h@cÿp‚µ%²LËÂ´,’™4]©$Y=‡nè¦‰íØÞ¸ŽtP„‚#\0&ÎžÎÐ£Ž¤möO8wÙB¤í`Yy´@°J¦»ÏšÍ€úÚ“7:¶Ñ`«Ô úú¬#íñ÷ÑÈ±Ø®…¿•±ò­ Œ*>8„BA oqh(Á XýëêIÄâT¬¡“Ê¤Ig³l×Ó|öÑ&Ò¹¶c{ä\0 iÙÍaÂyÓÉë:\r_Û—`8@kóL\0FL@ZÏ\"‡%-—2ãw·õ.t,HVÏ„QËv ŒHQ¡ƒ7\"ËýUÔ¬.T8úÅkiÆ©«IÐ¨õÈÊ:=™Y=ÇÇ[?Ç²í*Í*bÔ	8bò©Äû7pëä30dSoºÎ\'‹\Z°àôiÌYq/\03ÝÆ’ÙóªdÎu¥¼ãP,ÊÍ\'Oáâ¶%\0L¾f>Oÿìâ¶ûì<þ<€YjW9)2èÂ®ÜÎ{Þòusq±Û1ÎÏ#¯w½‚D+¬Ìv:¨±UàÀÆÁë?hÈÕÓ¶HeÒätŒžcÛ®|¼õs¬\"QDŒïÌA0\ZåñëoFC!Ú¯ŽéÀ­ÍSˆÕ×©M`›šª±ãÓ«r,a—4&ZWë»nb’îìBŠw.ŸÍ%:öó\rLéÊ\nÑÍLÕsÊ¡MŒ”C÷Ý\0;æ\0\'BÇú[Gêî:vÙjìN i\Z¡`Û¶QU•P ˆeÛäÍ<©$©Î.Öuv¹c–i@V¦hl\ZJ~÷n„,M¶¥m±¯ßÅmKhmžIgÇVïÜ£ÆòÞs«{ê)\0×r>k~{oi2¡ ~tHW^5 a›RJï@€\0ËZ.÷=OJé-h$QÃ\'o¯Ã±Œ|ž\Z[S¤]\n*AUõk¤–ÎÓýÁ_\0¨9Œ#&G¢i{»;;zË0¸ƒ„C!TU%“Í¢›fYŽtHÙ]Œ÷=¾yæ–µ\\Îœïu\'SwŸýo^½ï!fÜs{Õ5€WÞÍ¢³.ðÚZÎãž‹æ”ˆýÖ>\"-#‚\0áN·mþ5œ~Ý5\0DûÕõúŒ\"Ù\0³îÿwM=¿ªO\\\r°Û‡ ®+ŠàÄð qÏè;_PÒ¸$„Qèøàcré[·oã/í»èHvÓ‘J’1tÓD7MºÓivv¶Ó£g9è»G3åöë™óÈé0÷±¥´´-æŠ¶G˜8w6ñ†zWØ`uå\00úûÇãH‡X¡”€¢i8eÖØŸ¨HxíP4ê»~ÚñÑgÞñ¬{–Æ-3é[\'Ÿék —<¹‡’vZ…$Ý¶¬\nù;í¼çœCS¯ªE£X&uîØIwGí™$YÃ-Î›o»Ó±˜µr³V.òÌpÜŒsI4ö÷V4›LQ	4™‚™<ñ‹ÑBþt£gw»¯Œ¸¾U:ŽÏ$Eõg›H‰\ZØ{Ì,^Ë—m4Ó\"E(„Dˆµ÷¯ô®™,=r#tÓDÍÛ¨ª‚…K®†Àq$‘HäXO6¬®[¶L’Â&•ÎÒ‘I£›¹‚³ÔÔ¸Âg¢±†’¹(Báõ‡óÚ­Í3¹kêùDE‚Å-¥ˆ9rÂ1,hž^šh<ÌÓ¿.¥ 5MtnÛA(%W±0Že÷JÜ¶÷?ðŽ[Ú3û»zÔ\0–Ï»r¯$±á©U,hžáµmÓ¢å{\00mÅ´°m›\Z‚šD‚h\"îCyÌ¡²]¥8˜™,†mzú3ÏE\náxÌ»Qª’OÞ^çµS²‹??·Êkë¤q¤ƒ#,#ï?èèoƒQò©ãgœÍžÍŸxíi·ÞÈ²–Ë¹ã”³X:û2 ¤¡E¢Š\0`áðÊò¶*rÿÑ\0H~¶Ów^á%éå?\r…Ö©çùúž|µûüˆP‰¡¢«‡Ñ• ª¢)¥¼RèÄ$Sð•6Šë°³à+&Ï›#^m{¸4Ûâ•ûK:|4–ixí#Nù‘g>\Z%Ÿ¤…‚^0\0h\Z9¢L@@Ë‹ÉKËóSzOºŠ¨\"$6o|»tBµ÷¯¤íŠÿð?³8¼\"|¦]ô—&&ßœzªÏG=bŠPP•!Mû¸Ã+#¯ÓÝ•$§çüD&…M›€P!Ð˜Ž‰BðÌ­®£~ãÑ§¼=ûLölü‹×>éŠK	‰×žpÞtoµËa›gÞv½×^~ÑOXpÆŒR\'á¦?&&ŠPØü§×¼K¹dŠ·ÒkŸ1¸(¹-ä½\'_€B:ãH‡5÷ÜW\ZZU«4²¥m1—´-ãðÉ?ôÉjyé`;6	Û\r8=–I6›#£ëôäK~×ÕH™ß“-8ÒPÐ\ndØRrâ¼9œÓzfª””3ý,L»”HEê>Ò,#OKÛbæ>¼„JÔ\r\Zäë¸Ú¦¡¸ÚP„/i[†#^YY²„\\*ÅK+—yíQ“¾ãHån¤ˆ\rO•\\Ž¯¨3„ð4V:®üBQ|]$¦îŽkä\r,$‰p$£©­ƒ‘Ê±zH¥@b1_²lþã«|üÚë>“Ìtuû’hQè_œB‰µ·È:¯íA_»uêLµ4‘Ëž}ˆîŽm^»aÈ¾U)P¹\\ETš®O¦rÓFø²ÊX\0pÔô)¨H@bT¤[\rŠò=(ù=›ŠˆJ7ÄG·oy½TzIª‹Ž+\\¹FXfžÕ¿½„ÀÎ—DkóLB±è^Çj=£ä§r©qŠ¢ú4¿˜U¦T•Á¤•¦ýáÚW¼k—<¹‚\\ª§4^\\r?ß¿l.û8ÌKŠèÄjƒ’‹GEx«Â5oA `â#ÇS5átgW•¦}øÇ?yÇ¿Ÿv!›^z\r¤äéoñÎë¤ÙôÒ}íŸ<ÿ(-m‹ii[Œ#ŒLÉ”áXv¯\ZØ½c—o¼JD5½Žðòïï÷ŽLÖw†Â™7ü‚×^ÍÎ¶ø6/ÊÕÊ#ÒF’“n€	 \n6%\Z\" xàŠŸ«/9öe-—»+\n!\rÞyòY¯m–£¾S\n\'ÎžË“7•ÊÂ¦!±ö¾^;M’õ/¬.I)„ÏÜ‘ÒGÀÛO”Ðe>ä-JÑ„·mØè]·ðGmE(Ü=ëbßx;7Äm\'6£…G¯ºÎhFA#%nÉ¨ÕJ\"]˜Ä&](†4±HMUÉ¦ÝU.ÏuÒ¼¼¬D\0àÛih\Zì	\Z¦”ÀrÂ$_Jtò•—³vyÉWyÂyçéç}ÄU€^{Ã;N“ä­çž*ë^Ò•¢ù¾¼d¹wnÔqãªLßLehmžéýûÙ/«\\C\r* ‰ƒW~\"sXÝ‡=ÒÂ@\"MQPòî*®j½ÛhØ×Ç²yí«^û¤y%M9õš+{õQ•æ™Ðß·…5iÎ|ÿ²¹^[\'í«^LLÞzè	¯=úèã|¥4„lÛXºgûúMI›V­­ÒÈ/ú!%\rÁ(ªª UìpPMŒ@¡ÂñˆŒiá‹Ç—T›ÎtÆÝñ)dñå•Â)W]NOW§×~Ì·½d aŸ&zCe\ríXîŽ·(›ÏéìsðHïz˜¸¯z?c\ZŸlX‘ÉðÎžáã7×QwN>—…S~Ì®½©×çi ÖD0¤AãÈ¡®\"A(o	GèQ%vM„¨Ä¹\nà©ANcEÐâWåj>7Óìì‡¦ºD–çŽÁXÔ—„KGú6ò9ÝK‘~Ý|Z•ÀBQ¼Ü-4 …Í3½\Z·ˆÖsg¡…=l¡uêyÞB…Dˆ%çý;PÔÑkÚ*­¤\'Í»˜Æ†±ü¢ŸR7¸‰÷7¾M¬EEº©QÅ#ñPjFx\Zù¾ÞõYå€A‡dH«6i+“ÛJM+Ç×†ìT\0ëž~-dÏ–O¸OHéóS­Í3}uy¹¶ÿ-0¤[²Þ¼êqV;L¸àn^õ¸g]{ÃóOO{;&&Ÿ¯[O£¨\'P(uC!Wq¢Z!Ýà®¿«:[­€dìª·@É©‹\nMðƒtë\\ËÌ3dÌhn?ýnmžâÕ³¯,icÁ©ÓxøÊÿâ³w6|‘(UÈJ7‘žxÎéÌ½ãW8HÎ¾ö\'ž_žùŸW“—Ó\'Žç‘à¡»î`øèÃÈÙÆ^}á±³¦a\Z:^{)²2ñXú¸“.½\0E(Â%Ði˜Žƒi;´Àx‡“•«¾‹<”Ð‘J0÷±¥^âÝÚ<“ù«ÿÀžO>åýU/òêò‡ù{cÄ¸#ÙôÒk¬‘Ý˜†ÁwÃY#»9T©ýé±»°°ij:G·¬çøHY™âUéf•öýÆÁ|öÎ^Ðwñæª¹ê¤)þ‡Rrö7±ãƒM<sçíÔÕ7‘É}ÚØþþF6­ÿ€Áƒ²ÙÎÕÜhµLÃð³vQ©!|&Ô…I ±±v”ŽdÓ±Ðe/JV¢·²ì¯!+ShDÑpµâwo®&L1gâDÚäFÞ3F¸Á\'Lœ}Fà¢›~ÁÕ\'Ou7%d7Üy.žÏ\ZÙMOg7\'\Z†jUøB!°¥ëÇóHL$&îÎwñ“‰$\\ðº5¨ô\'HV8lI†Œîr’ìÆ,”¾¦c÷N$¸A¦Hf‘ÈoÊ\ZvwuVùÉÞÐ«#i`XL:w\n³y-gì{‘úFwšÕN\'¦ap|Äò«N&*\rI?>r[^_Ç\Zé~³4AÔAHeRóiüÏÒ=m*¢˜…ÌÃÂ-8,TDáOq_Á¯(ÌY\"é‰·tåÄÒ·Ø‘­šÇ^ÐëN‚;`	Ùl=\ZGSÕ¿‰ÈÞ°Foç”ÁÃ™¿hçÿE(}Ê	¬^æº‚¥7ÞÂÙE?j9\\Þ”’	á~.‰o¼‹\"—Ü‚d¶aóÄÒÈã K§@^i5Ü€é¾_W¨…¿¡6\ZÓm¶¯ïíµ3¹½ïî\r><ˆvŠ»ã]XˆX„¯Ç\Z¦tzô/^¤ÞL{µÓÉÛÿûc¾3Žo’ï:Úy~Ew\\úST§IÜ×§6îëà,vÁýD©e\Z®ˆQZ ðrJ•ÓzËFþ?à#òpQó`VÚg\0P0qØIžp,ÆÁõ©ïÉ{ç¯¡7Ó.’ë }~ªœ¤â†@ñc%ÒF3€ZøÄÅbQ^2¿üûÄ/>ÓÞ-íâp¸«[ù™F0DUþ6ó.÷Sl,é~hP>¦«ý®fÅP©+¼æ\"±ðÍ¹Œq}¯dí}7ïKƒÈF²ïåˆEå(jyŽï]nÄv(ÖžŸ’näËa£ãjYáû:#$†Š†B¨-2=\ZŸfäÛ_èÕOeª_í~•QU*FLöAé°“­ÄcqþÍŽÒ£Ø|šM’/lnB¡\r\r(*Â‘HErä³épàÂ”Ÿú2Qµ‡¥Vj¼L7µhÄcq®ÈÖí;Øí¸%W•z4(…ºÈÖÏÿLf7€Çoñßêÿ\0ð/‰*\"ß#Ã1Ôb#éÆb@¿ÁlìØE]P²Cï©Ö¬¯ ¿ú2PE¤Í2‘ä²lÏ$Åö/Cº>ô¡}èCúÐ‡¿;þ©X“Å‡¤Ë›\0\0\0\0IEND®B`‚',1,1,1,0,'chocolate','',1,0,0,'',0,1,0,0),(1234567890130,'Neon Jelly ',200,20,100,0,'0000-00-00',2,8,0,'ÿØÿà\0JFIF\0\0`\0`\0\0ÿÛ\0C\0		\n\r\Z\Z $.\' \",#(7),01444\'9=82<.342ÿÛ\0C			\r\r2!!22222222222222222222222222222222222222222222222222ÿÀ\0\07\0R\"\0ÿÄ\0\0\0\0\0\0\0\0\0\0\0	\nÿÄ\0µ\0\0\0}\0!1AQa\"q2‘¡#B±ÁRÑð$3br‚	\n\Z%&\'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyzƒ„…†‡ˆ‰Š’“”•–—˜™š¢£¤¥¦§¨©ª²³´µ¶·¸¹ºÂÃÄÅÆÇÈÉÊÒÓÔÕÖ×ØÙÚáâãäåæçèéêñòóôõö÷øùúÿÄ\0\0\0\0\0\0\0\0	\nÿÄ\0µ\0\0w\0!1AQaq\"2B‘¡±Á	#3RðbrÑ\n$4á%ñ\Z&\'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz‚ƒ„…†‡ˆ‰Š’“”•–—˜™š¢£¤¥¦§¨©ª²³´µ¶·¸¹ºÂÃÄÅÆÇÈÉÊÒÓÔÕÖ×ØÙÚâãäåæçèéêòóôõö÷øùúÿÚ\0\0\0?\0³oiw­ÙÌ×ßºÇ”\0Éþ|vªŸð‰]\\E0\"¶xf8^=…jè73[Ïs8D¯û•éÓ œûÿ\0J¹«® öË>\"{¬\rÑHØÇcÐ7±ëüù°Ù„e^tó>dµ²Ñü¿áÑ×:ºy}\'•ÊQåwå»³ù?=z\'¸Y¬šE¬V÷ˆÿ\0O_LƒEÅ¥¯Úÿ\0´a>\\ÛpÄt‘}øÓl,®µ}ÚÄq³îÜÌ?Ú>žÝj/êºu—‘\ZÇÄb$ŒÀv¯+4ËpÔêª¸Y»uõò<ŒoŽ©WÙTïéý3U$UŒ´d/›ê	Æ\n¨o!‹WMû·<*qœw9?Ê³´¦“M‘.×‰7)“´ÿ\0×ªšì2Iy”\nÚùÇÌ	ãõäV\nœëMÃumÿ\0#íkà*c(ºiòMë4™u˜]ÐjdkÈw\0{ã’ú¶¬òŸ\"	¥‹þzcoóëT4+yo/^[Ñû¨Õ„à‚þõ³­kïa¤Pê9@§8ÅzÐŒ\'ÔÙiýz#ä3yÖ–\"8\nt½¬Õ“vi^Þ]z½t*¦³ªý G\'™\Z¹Ç#=€Ï§é—2¾¢¸vd|ç\'¯ ÷õÏJ¬És$%Ôd¾70#;xÎNÿ\0jè4K`ºr\\Rd^£·ôüë¯©àŸ2×[üº[¦–+ž£*ŠÏ®ëUòÖßy™.‹³<žNw1lãÖŠÜK…Ø¸8âŠðêq76Ôž_‰„yžžeyì¥¹ˆZiÈ*íWÆOÇŽÔ÷³—L´ŒIrf1 \r#Œd×ùU½G\\ÓtóH¨ |¨9g>ÃÖ°,¯\'ñæêí„ViÌvàó\'[ü+ÌU+V›©kÅ={÷·©-)«E.ÆœÏ%Í±kYWÌÇîÙ¸È÷Ë>Õ‘iq¨$÷Úã8óXó‘Ôr§…jYËnÂT‰Ð˜¤Úá{gZÄ×æx´jù”™„Žùüý+îç…¡ˆ§K0¦­“qÙW>/‡jU†iW.©;U—7,÷wµõùko—bõÖ›5Ø½±‘œù¶îÃæê§¦~½yäf¹ý[^9‚Þ{i!`†•\n‘ÛŽ}G^œUû-zâÎxõ;%\'l„ŽàåŸÿ\0]jJ–ú­£E%´sÃƒ.GGòÈ=é¼.‹ÃÏ•Ç{þ«üWŸæyn.ž0§í”Ÿ,d´o¦gó³¶æE¬‚+(œ6Ù®?zYA|åx#Ž¼fº\r\Z×r¬÷;Yaxè3×õ®|º\\ÞÈÂ<:ža\0áã^ýŽükbÇS·•¾Ì&PÀ|Øç¾k;ÄÕ“\n^­Ÿ[šW…*Mím_—_Ô¥«²]ÞI\n‘òòäû€OcÇùâ¯xzy Òâ†|e2-Û?þªf­aa§Ú%Í»°/ _;‰îIïÛ:t¨-\"Üd»¸Úª:‚8>ý\rEB!.f´~žEá1t1ø(Ô¤ýßÆëë±Ð…°PbqËÑYk`åAÛqÈþïÿ\0ZŠóþ¬Þ¾Í~${\nÌs·Úm½Þª×·/º8ÎQd6?§µ8}¦æým,-ÃàþíOV9?\\ò%·³½¿·sä¤`Hè&—•#<m^¤ËËSIZ\\‘ÙBçÍ™Â¼òusþxÇÒ½:øˆÒÁÚ”wZžeÇ	¡-9sTk__?Ñ\Z6ú2ZØkP #srYSŸZÄ¹·xçxç’9hX.8úzñÛÒº½JþvT#(¹Ç(õ?çŸÖ¸SPŽHÕY7K+˜HrOLLß«É«b–ºÒ~Ët»¿.¶ü/¨ðX=:¯0«š_õå§~ªésë«imf¹\"`X È\n	éÉõÅvÖ:m§‡tmr	•Éå˜ÿ\0õ°+?Kñ.—a¦Ãkó‹’¹(#$»§#×Ò«ÝÞÜêÓÈÑB9ÇoS^UO­ck*tbÕßêxñÌ(Ñ‹s¨”[rKµÝÿ\0\rŒ›)$ÔuY¤¶V,å’\n¼‘Ÿ~OëSŸ[­×Ûât˜¶à‘`(õ#‘Ÿ§éO’æ\rÊB yyd n\'‚O¹éú`q\\Æ¥â[ëÒ\"ÓÚÇïžIôÇl×»_\'Äá¥\Zm]µÓeþG©Cˆðª¨Ý’Ñ¦µçøscÄ6ò2Û¬·ƒË2\0ŒdãóÍ6ââáÖH2“°†;Wdg¸ú\nM;Á—wî—~#½™•9Ke`0}IN}ëVõ,l>c²5-Ç~žûÿ\0Zæ§ÃÅû­÷iè¾}OK.ÌhBŸ²>X­VË}îŒV½ÖQÙ~Ón0qþ¬ÑT?µxKÚ8tqÿ\0|š+·›ßñgwöÆ\\´æ_sÿ\0#¦Ôuà  RÇ»Œþ¾ÑÛUêZ‘WDl$?Ã‘ëê9ü~J+<¢¨`TàÝÜ¬~cÃÕkJÛÛ~¥ï2ÌZ(²€[Ðg<W=µÑÕ¢òv<§“¿ø‰8É÷¢ŠñðuêJ1ƒz#î§.|;§=cÊÝ¾G£Ûi¶Ö\n¹îJÏÛðàgñôã\0¹“nY‚ì{àbŠ+ìpp§Z¬wŠÓÈücÜêrËk™zßƒã×Lö©\"ŠÞb\n\n¿¦z1ŸÆ³¿á¸ÒžÞd¶K„ŽE,QÀÚ òyÇOj(¥…Ìq)J3wæM=5ìva`Ÿ%þËýMë›Öp#‚0ó1ÀüMgÂ+,¬×7—açaü«ì=¨¢¾þÆ“¹úg$“Otc68b1Áô¢Š+ê£¢Òv3ö²?ÿÙ',1,1,1,0,'','',1,0,0,'',0,1,0,0),(1234567890124,'Doritos Nachos cheese',20,988,10,12,'2016-01-25',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\09\0\0\0R\0\0\0î+|\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0Ä\0\0Ä•+\0\0 \0IDATxœíœi˜]Gyçµœån½·vK–-K²åE¯$€lIØ²œÂ„$!d x2LBHÌ$„e2„11a‹	Øf €!6^–%ËÚ—VK½ß¾ëYªÞùpn·Zîfâ™óL=Ïé{ï¹çžSÿªwù×û¾ÕðÿÛÿMýŸ\\<{êØ®·_·s×Ï»õ…Ç¿õ\0›~â†]ãß{h÷Ú-[¸øÊÌþÑw®{ï»v_ö3¿´{á7_û«?Ùõá÷ÿñ®›o~þÍÁÃMŽ_¼£V¡_I\'e¬Ó¦ÒWÙ=Ðpß™ÈÛ»ßS¯ïþñ=ø¿ù‡QER<\Z…4ý6 6ÚÇ¹³Ó àE´¦lŒÒØ0 ,ƒ—ŽÒ¿j˜ÓO%,ƒV¥p¹Ck\r\" ÕÁ>žzê8%k(•\"Jå—f¨ÄWbò,\'Ž#º­.Y’ÑNRæZmŒÑ”J!A†ÚhL‰\'”Y’„–,I)ÕÊkp^°E+ÅÜs‹zwX«…AqÍ-×0{z‚õ«èÖ›Œ?yš¡‹‡)÷UÈêÖïÜÊüÙI$w´šmG±•˜òà\0.ÍÈ“%‚÷‚R\nï=Zk‚r\n\ZSˆË/¸Ô¡”­¢ç<y’’tÒvŠËrâZ‰4ÉÐ!¨ÄdÎ†!6°˜À•KˆZi’¤KT.“g)Aá½cßOïVŸÜ¼QNŸž$Ô†\\Š…R\n£¡Òt½C+Ed,(…U\n£4J)´RT‚- Î9žÔ9ŒR(Šû\0X­Á*O[¹s¤Î!^HrGæ<VkD„Ì\'ò[Ã\n\r—±¾R£lB¦:-Žtê`QŠH[Ú>#è3emÑÀu/¹žôê·¨÷¼ø–~j]ÿ®}_ú§“^<MÉ±Ê {T\núLX€¢\0iQ4|FÇç¬ª=à\ne4“6º*ñŽÔ{Ö•*DA€(˜ê¶±¬Ñ„!0í¢ ÕMi\'í<#¡éRºÞ3ÆÚÐñYÑÑ$.£îsm2!}#5.½árl)æñûâõ¥\0¾öòH¥\\áè7÷’e]É™M»ÌøŒ–w¬21ýAH \rJÑ(¼Ý<g*Opâ	´Æ*ÍˆL1H^„Ì{ÆÓ6¡†„(Fã2qhÐV¡IæH³ç<8ÐPŠ‰N‹©¬CIY4ƒ6,ìG0¼aˆÚè\0TWVË4&¦8¶çi¾;6Îg½/@þAX’çÝz-ÕZQ7;$õÍ‰yÎžFrGl,ª¸B\0Q`”Fš$ËAH}!vK›V\n0—¥¬*WBƒÏ=Ö*D	º¬Ñ±Ám-&0Æ¢Å†!Y7ÃÆ!>w(/ˆ`¬!ÓP\Z¨¡ƒ€¤Ñdÿ·öÒv9§M¾*(Pw)G¿÷£}\\ñ3Ï£­¦±¥êP&¶œGçŠÁ ,FP[”Qq€\06ÈÓç<\"‚2š –ct`QVã½G¼@æpyV¡­-Ø0@[‹y\'%êïCCXª\')®“‘5Ûdíssó¨LÄ!Y§K¨û¾ùCñ8 è\r°˜Ï =Õ ;9…«·È»)í4!ªEÅÌÔLãp…¢V\n1¥€0ŽPºÐEÝ3ó*0˜ Àe9¶ƒb‚ Îƒ5(­ÑZ£ŒÆ%) (SžR‚-+”Öø4G²6’¤¸N—ÆÌ,I3!og´ÎÌc´&Ïý[Fh¸«%m(kNÐ\0ïà_R”£tzž¼Þ\"o0¿ÿ,É™yôDßÈÈ»)ovšV	êF\në<Fk‚0 ˆ‚8$‚0 ÜW¥ÔW£Ô_ÃjM`-aÙ€@c1(‚(\"Bí@‰ç1äZ{Ä§di‹¤3Osl7Ó€F‡Rl±F—#:“\rj6ÀLd	Ÿq¢`	ãyOT‘m•~Ö\\º\né:Òé6â<s™xZÞ‘‰çÚQe0í²ºó[µ€u}5‚0À„Ú\ZèÍ^Š\'èÂÝˆ\0â=Êh@A!Þ/~¯loF-˜P“¹ŒÙãcHšõ~/x\'H¾#ä©ö—˜9=Ï\\·Ë™¤Ãi‡û{øìÈZ)$Á·2Tî1ª`:¥˜Fš’tsfÓ„÷*Å{Ïœâò®ä‘Çöó_åe™P5«KeŒÒTŒ¦2T¥rÉ(*4((ô“ÂŠ*)ï’{´5@>÷ ¦9³‡Ç<#(kL¬0«¡gÓ|.Pñˆ×dYŽ-®åt«Ës*îoµ¸\0ä;çfÕ}Ã²!É±Ö ”Ækˆ\"ðB#KÉz¹äè9>rÕ\ZnÚ?ÉCdà2>ØÌY]ªP3!éÝéf13K­Z.÷¥‚€*®ÔA1sx…ª€6`ŒB…”yæPh\\3£<l8ç„ø@«µø ìüÚR‰Ì9ŒQ‘%\"«	´&¶†á¸ŒQðÓÚp÷äÏùÂí¤só•MCØ¸Ä»Hy}g–óuš^È€LA&\nY`R„B+…hM®5^k´Ò„ZhE 4Å«q\nÕUÐ¤t<*´¬â’AÇ`+šòPHÇu£#º¯¥~ùÜiå’o&ÐØÈD64ôG1ƒaH¤\r·y‹ Üù²Cò/=°—Îø=üÏKGQÆò;¾ËÛ[Sœé¶Z§\n€¢N)r¥p=ÐLÉè‚*\Z4F+¬Ö¥°h¯Ð©†¦À<ø†@G®/•L¤1eCš	WW~<H€–sÅÙHc#CPˆªQ5 ÒšÁ¨TtZà‡&PgOò¦‘u½ê7xÑÝ»H¿}]_cÌ9Þ”Ìs¬Yg6Mi;‡UÌVX­zôÐª…Œ‚\0…QàU±p0€Î´R_ÕUd×õX\'tÇöõ„›G_¿Ó2yäÏÿôSé]Ÿþ×J Ô\Z%\n¥.sÌÕI¼ãXs€—·Ø»m_<{Ž÷Ïg”jý<ñâU¬E?ùÙ6#ÿéI§À\'£~Bcè³ýA°Èž\n_ðc¡0HôÎ‹ó¯º8-\nÄ\n¦ÏšAXÖ8×f$yÕcÇ.Àµâ¢ù»—_.A_„¶š@´@rjžf7A€ñn—zÚå7³&qµÓÏeäGo(\n6YØûê­ÂàgRT­!á/ƒ\Z—kX­z‹€¢-x5µ~ã…æJ¨P“æ9©L(Cßªˆ½üÆÁSÿ2È¬“+û(­©bz‹Ï™}g0(ºÞs²Ý¤‹çmÉ<WofõþÓH–!Ï¸»~¸yk×Ä¬þþÑÞ$)þ8ª±ÁDÇ!±6˜…®,¾ôÞ,S(UøÖ@‘ä¯`N2ŽgJ¡å-\'Ï,Ã´\"È?(U$@±md˜ÁÍ#Lí\'I†Ã˜á(B‰b\"í2‘tø·é<å¾VÅÇÏM^r	PzK¶O­ëãõg\Z…ÜQˆñHƒÀHb•^ò›n°ØDA.BÛ;Ž¤*åX§Uý0˜{ÏÙsƒÿ[cO>þsw^÷“÷¤.çñ,ápuˆŸß´™“ÇŽã)ÄçÎ­øxØOî=oÍŒ]²™õG!ráÍzú\'‹S«bËDâýá¿«Ôx‘)“xÇš¨D \\Nq½Òjq\0ÈÅÓÏ¡¤CÛ;Ú’“zO&žÔç.ÀeyFûÔÍ·ÞSBbKÆ[úFøÅ½,\ZŠ…vÉÖíôµîž<E(šËŽä† â‘,¡ÇÙ\r\"ˆ%TAçþ¬º–_ïžBw®ãµSã+9Ê3þèä­±1¬‰bÊ\0&³”™4Å‰§ã[ó´\\ÊpTf°\\¦éógBZòç¶]A:5OÛÁ©ñ\'{á›RŠc‡\"\"Ü?8BÚš§24È#S“|jô\"æsÇoÍ³0ôì\nküöÀs8^sêccã¨K6“uëûÚr…çØ€¯vÚüj6Å[«CÜ—øëF“lMó7ñ\0oIæx]¥ÊÇZMD\n®ë|âùí<cG³*Œ`vzYŸ/hO¿ñÍòè¥WË×Ö_&·[%Ÿ]·Eœsâ½eùÉrU”µ’¦©xïåcŸø¤`­(kÅ{/\"\"Þ{™˜œ’7ô‰Zò÷^œs¢‚°¸_ïuáÐQ,ß»x‡l¸xóçm\\*ŽRY¼÷’e™´[-™™ž–¾ ¥µ¼«T•Ï­Ý$_Ýxé2³°ÌvuË¥ÝN<“i›–œ÷‹ß­ùç´p#X{\0¿ö+¿Œ\\šƒtè0Ggdxˆ?>rˆ—E}‹ß={ŽééòÞì-m3³³(^•ÏsòèŽŸ8ÉÑc\'\0HÛÑN›\rD„3ããŒŸ=ÇôÌó\"üaTa4.Óöž3I²ìÞË@V®ÞA+O™Ïz«bQ¬–Ž^`K)Í«_ýZ”R”ª5öîz	¿þF\0††ùz§¾xïõ7òÙ×-Óo€Uk×¡cüä	¦gf¸lûv6|7ïºx¨üfa‘E„þþ~¶íØÁñ—¼Tƒš\rèˆ§íÝ¿²9ÝøN[Nz*%,®óÛ’apûë_‡ˆ¦	hÏ‡ægùò?|€ì€Þ>;¶¬íuý…åoÌ7yóàz´Êû?ô<Âr…¹z°\\pÒR179Áäý!ïê_E–;òÞz4_îÄ–ƒlÏ=µ»ë¹ïQè¥,N€‚ßœ`ìLñºpÝ¯œ[¼V©•Vª\'?>Cñ±›¯å/N|šù;þ‰Òk¿½(®\0q­ã\'Oð’Û^ÄëÜ‘µiå)pþY€¼éý#O3Ë°\n´-.Y˜Mc\nSî³b•¾ó¹ÏåÍoùM\0î¼ó¿‚Àê0äçög¸:Œ—Âù,Fz`·lÙÂkªýÔ_w%øèvžÜñ&ÞÔÝâµOxª7FŠ×\\Ã—¿zïâo»\"‹\0÷lfR)µ»“;\"e”Âf±Ci»EÚn-|úða^Âå§N“;ÇÛÞòf\\–²û\0¶í¸’7VôKØRp&.Ñív¹hì(7½»†]¯¹êõ?\"ùÂ=|î3w‘uÚ>rŒ½èE|ðƒ¤;_§5;ÃÏ½âå4\Z\rb`]h	µYŒØÿ‹ 2ç©Ú€rXDá²,#M3Ò,#Ë2~÷¿‡vl¿œuYþ¡ÓäÛ_ŽB&&§øÓSè dòéCäÃAÌHXb@ŠÇ\rÃAÌ (bç™ºå\Z¾ò»—Ñþû6ý>ÄÓÝŒ}ûžàôØ~þ‰+w\\Á×Ölàþûïã%/}?ýŠWrñÖílÞ¶.ðNS¦jJZ÷Hþ3&n%ŸY/VÁ’IþÒÔði‚8×ÓGEž$¼ep˜çgš®sìiOò¨R<Ü³¾»†FùâH•‘§¿©<ãiJcaþÏ¶ãŽ;š_î°îØÉe3½ØÉ…ÏÙ2ÀyÏgo¸‰äÀ!V‡1’q*Køƒ©sÿ{Z°±Tfd°ÌN³ŠÛ;9’{È|//¢è&…ß#€T„Á0ä¹iÊm9îÆ±{fû²xú<8YBÔþaã0/ýÄÕ´î:É×¿7Ï¯œ˜D)EŸ1|\"du!@ÅZ¬RLd)õ<#4†óÂèO\\Åšç>ŸÉã…±‹EÃr²2H£¦l!D©Å‘+DáBÅ•bCT\"P\Zà­I‡wH‡¹=)_Ú6Ê«žš\\­hÍ;®$~ÅÕ4?økþþ]çA)>]\Z¤f6Å¥óº¥\nš¾&ˆXF£ÉEp\"äenÏ,\nÀP`æ»Ëð¬¨“ˆ KÊ*”íEºY|æ2û¥¡  4†á¨Àßœ8ÍO¿aôÂël@ò·Ï¥üö7ÐúËG¹ñ¾“@à¯â‚Qi™ñX|Þ’%çb$A)ŒUØHQîWv9¤A¦\"˜Ð¢KÅ¡ô’À0++r 4%m?®4H|Û+¹aÓ*\0[»Ž|êÓØ—¿•¹7~”Õ7ÎÁva¥¿PeK©Ì†(F)xòÒž¾¢ ƒ—÷^¯åÑÐ£DxduÄÁK8¼ueA— QLHNµ¶\\8WéDÐQ€²Ytd/˜É•šÊ¶\0ùçå!žš©“<ôMîé¯ÐþÐU\\{òø.õþ%«î=G·ÕdÈþ¾o›Je†m°x¯_ÛýC×^ÏnéðÑ<É‰n›¯}ó{HêØ~t_Úó#~æ¿|˜W~é>t	Ì Ø!Eb \\6Ëú¶¢NvEïÑ‘Ÿãl‘äñôBúÏ\0» N‘.r’%q?ü›qnzô0›Éï½Ãÿ<ËŽ<¤	/­Ôx£©°>Š{!ËÞ½TÖåÖ;>À­w|€“ýýü òü·V“™/üØ¶ƒçÚxû|ÿÿµa…éWä%…ŠJ°äÊâŠN·ðY^„÷u±{¦2.Öz‡<BÐ£V³ÿ˜Í4?øÞýçŠ?Ý‡¤]ÞWà­A•\rQ|>×Ù;vžÚa	•xúKwsÅ;‹÷ÍÍâÎŽ1ôê7rËÁ\'¹£Ù$}üažûÎ÷\"ý ûRêùÈ9Ç™‹Ð:ÓÀ5S|æóKÃKC‡Ušx©^Úa\ZwÞÈÍÿq?zrÄóßãAnË¬¢Þïå‚›(møá†m ÂÖ_{·ÿÇ?á=×_ŽÙx)ï½qß|Ã¯RsÓ.þè%×S2PÖdÞ	Yg¹YQ\\QyÁurÔ‚>.$iÔyp‹¡ÄÞ{«\n¿Öv9r{£Î5âxVï_Çƒl(W4Á+” ¸Û¦%F3¨ŠZ€1—ñÆÐÒVÂÉ}Oñw÷~žÊ a6wèk¯B¸n†ïz²ådeŠÂÂúÔá{y‹E¤R°µÄÚžª¨\ZËÔÂyï9~ô$o*÷qƒ3l*Wé7v\n}¾½uÍeç\\ï¹ƒ·ÿ,õÏ|Ý#¿÷6ü‰Çñ	üu¿Dûþ?!oætfyÇC²Ü4®<“6ïdš:¦µ\"_Aö!ÔšØXÚy\nþ[4ˆÍeµ¢BÄ/™µgþúÈ…ñdî®Àô+ÂÕŠôë…é3¨Pá¾ñ!\\+\'©{ÚsŽ¬íQù³©€!wž +êlt/œ-ê¼Nª°¥Ý4(*ÆÒÊ3>\r°¦TbÐ…é]ê{9®…‡-€^È}-~«(t`8¢°}…Ï<®éÈêB2ëhLçä]!æÿÇÔJáDðR,‘ŒÑK¨ÎBdÑ^,‚ì}(õÖœJelxî²Âû¥³¸ J)´]`‚Á\"=§¬BrÁ·} \'›º÷Ér[ä¢Y\\îQÚ/šáÂº.ÑE¹P/ÚÆr•š1€àYp3½ëR±\\ú{µ$ø€®*ì*†¦¢Q‘FR!o9Òº\'™ô¤ÓBÒô¤™/üø\n\n¿²¸ª\"ÝßE½@oVY*Xˆ2È²¿PÒ†·º4)%K†ãò·\0e”(?ÿ\"˜m2ù‰qN?ì\nÎ\\»\nÂ!…­)×rø²™b“i!íxº™\'A)õ³ÔI£\n½qÞã´ÂdEà¸yÁ\nV¶7HJÁŽwVÐCs¨ÖF¤5KûŸº”nŠ°[¶à\Z\'iŒuˆ²ˆ|ÿQ\Z¹C4¨Š\"…hHaK…å]ÁµÁ7Ù4dóà!wBÇ{E%g¶BŒgHÙõ•—â\\Š<¾Á‹\\ [òp«^Xfõ2òï®›Óÿ¾ËI?€ÛßBWW‘®S¹ýùè5’Ñä‡OsæÛs¬Ýn™ÿò´Ç2ü§&CFb‚‹‰À{)À4!›5¯ð¢(Â‰º\"™y¡hÜ\nÊe ô/vi¹ø‚E 8ñ‹©5A¨îÔl}MLpÑ&’§ÇqÇš˜+2ÚßÊ°!D/ õ©ý<ö`‹ëoYE°Ã#£}tvÙ†ê6¡ú‚²QE.]‹ßŽ|ñ0R‚a‰ˆÖÐZœƒ¬+d\r!›|l®ñÒsq^HR<¢…RhüYÌd4ÐÿÂÃâRBÞ	ªWs³jgB÷‡žäðü4¬8u§gär(½néga¨Ìs^\\3KçþA¦÷Îr¶o-kÛÓH7 ý}DW§¸#ghN$ä1è() Ï„¼K´Ñ°õ_ç¸†â”`Ñˆ.\0vM¡¼3TË™ê2ç¾óE@¹àºi/`ku!›ªÒV¨Ñ~²½-‚­„×¦\\úÊ\ZÊµÈž8‡ÓS˜°Ì™BßÁ€þ«#6üÎ\ZÖNvñõ7î¬¢G×¡ÔŸúØWyîÍý\\»k+›Jó¸C)ºßb¶[hCk:@Ü$ì|[~¤ŽQŠ<æÒœ´g¢÷+ÐñegŽíÛ™ô\nsñ$Þ“/ñ‰i[°[Ë„Ã}”®_…š“wÖ©ÿ]JãÞ9ö}n•÷“·J¬Ûd¨]5Jpí’Ôéì%ÙßD\ZÌÚõø±:OÜõ£C5¶š~6¥“˜‹[ÌÎd²	b©]“ÓÙ{–ÒË_Äç>t’†ÉI«Ð.{šä8ñxçÉ2OÙ<yîñ¾\0å2ñtÄÑiêyÆÝ¿5iŠ®6(ßTcý¿¥36‰ï*¶Ý:J°ÊÏéÃiO~jš|ì­Ç&ß×`îœ\"Or²ƒLýSG¦\ZèH±}g‰àºõ¤öQÞ2ÌàµÐÜ¯¬?fÉÂœÆ§¿Îáö,“QgÓ”Ìy²Ü“fŽvžëgR‰x‡‘Â±æR˜èÌ;:ÞsºÙ¤gL=ÒÂåšßfòãS¬ÿ½M¾ãVâŽôT™ãŸ9Lgr€ÖTŒWœ}Rxxÿ©S¸é~Ü\\Êéc9ºªÙ²)†³)ùž3|æûgü©‹ŠP»Ù¢T„´ÛT.ŽyÿGŽY†6”1ý†ùvŠÏ=:÷ˆ÷Ì&ÉŠd`È\0Eæ=IÊh\ngÞô®(ŸNáKŸ9Îìýè~Åúwl$Ù;ËÌ;wSß3OéØô[ùÌ·~Èð/m#Üº5Ï‰Øuëáeå¶ÓÉÇyìØ,ñŒã¦«F‰n[Kç¼æ\'VáOÿˆ¹¿Kðc9¥—Ý†œÌ¹ã÷6^2ÌÐHÌññ&6`€€ª¶””!@s`~~Èe†Ç\0–¢4,ÐŠ’Ò„J¡Ð%ÐH<Âçï?Ço¬7L?V§á<ÓcŽ-×ösêÏ÷pf®Í¿zíå<ùÙGØ¸«FÅèŽŽ}e7ÿøÝIÂj…Ÿûí~Ü·ZÄ·]Cþ3”·ÒG+ýêjÎü÷§à®¯²wBŽZGk¬­æŠËªÎÍti‘ãŒàt1…z…DÒ²™\\sËOP5†’Ñ„½\Z·(4„ý%œµ ìUü>óŸ£vã\0½ºÊÕ¿»Žù\'¨8`ÃHˆd†þr‰H¯\'Ù—P›\r)­À§vdþK‚£5²²GgjÂ‘Ji§\rò#ãŒ¾|3R©ñõ\'OQ©°i´Ÿ8Õ¸Éœ|Â1à,ŠÜy\"5µRò%Üùœ;è‰¨l5@—²n†ÒšHkúÂ¨X©P¸™î=ÍÙ/5ð\'¦ÝXed8%äß®3¸y5ºÙ¢ÙèûÕ-øðüõÐ>;ÅK_q1jHÓÿWb.×Ø’\"^oÐ%…\Zlqêoòçw\"Y;P¥æ4L9äœÇµŠ¥à 	(kCâ=‰Ž·›ÿ2Èïß¿Ï÷Ra66¤¹£ÛÎð\"`‹¬˜€Š-<’Ø÷½&{j_¿™É\'[tóCùe²áid`–U/krèž}<õt›¨iØ¶c=ÉáõÍÑxä(O¼Î|õ£)µËÖLzNu‚j@\\b˜\0¦<2îÈ;‚sç7`r/4]ÎTò,#èóxj›\nþš:ò…Ê¼ÃõÌW-)™\"þãœj±ï#yòp“ ®øÐó°Yu¢†m;´‹	BÍÞCu”À·EÄ5aðÖQýh†¤£	\"Ï™9g›åô”=.¡1¬Ò12åÈÎ9\\Ç“»‚©øžõÏÅ³&Œ˜Ë~aÍEÏäDÒ¡¼z/‚hEÖs¶.÷ˆîŸ•¢D„½=¢`Ïž9†ú\"œI˜úðCä5az|½e€cŸËøÛÿq­Z+þìm‡`d!CÆ4j­ã²«#Ò9aÍŽ€QÓ‡òÐçôŒ\'Ÿð¸Ž\'óÅb!“bG‘!õžé4ÁÄÁ2<+‚¬¢™Ø{’¨†Ó‹ñx€i÷;tJ&XÌ]ŒI¹âê˜¨/¦²=`r§6Ze~Ï4ŸšY\\+G„„Êpç¿y”™=už>3Ï¦VŒkÔ\'Îp×Ãã¨TˆÛ\n?ã‘®às!!Í‹š†\\z¡ã¡Ö+†?–‘²6_ˆ±q€äB–;œ/Fl!«$‘±‹,Ã#Lv=Ýé&Í$%l*t©Éƒ÷58q°¨&±ªÚ2`Š4ûìã9WWñ1ëX¿Åò£o4ðmGµcQSR™¼˜1\'Ít3Ù;—yÏê°¨—ÿÏýƒ ]ò“«f;Îqdb†ÓÆÉSGÖJH¥H8ñøÞúraY2–°w«»??ÆìÙ\ZÕ—S½j«_z[wV\"ü)Kl-åRH\\	¸ÿà,—^\\&ê¯`¶ÆìùF›“Êa\ZÎ(\\»Ø9à}aœÁ*ß{ŸöHŠO’;öÏÎºÿed ÛÛ‚T±—<og9‚…¦Ø	çjz–x¤Àú­¡\\2¤Þqß§yí&…]pì3\'¸ïÞ:}ý5¢ ` •-º¢é¡m=¥+†ˆwŽrüËÇ8=P\"˜pDóÉ\nýð\"Ed/bh”\"‡bë„/h¨E‘zÇ¡¤Å&_¾\0Ó¾óÞ¯–£ÎÐÉ3®¸r#¾“‘Ìt0I«w»¸…XO/ð;0ÚWÔÏ8Ï|’PO»8\n+ü‚#|wï$\"Š@jQL­\ZöYtÙ@¬hºŒnžS\n­¦ÃwÓ…²¼Ô³—\0\0zIDAT·”‚\0ƒ\"í’µSô’ÊÉ…½_©w8ï±ÆÒr{š38Š|éIi¾`&Ïç\'_ýb&Ÿ>Fëì,ÒÎQR/4“Îù\\ŠRÔúËèÈ«^,È9Œ€8¡“§x„¯?<šb§@`ÐZ $°‚Ë‹…€O³õ”¼å UBD;ÒTÐZ¡\"Ê5.ó ½Í§=]T½ðžÏªÑ~âæ,õÞì/´ò\\ÏWö}íã¤Ín±]W+œ÷Ì5šE…–­\r¥jLn ËIšCêI]N–9\\êh»Œ4wÅƒ<b¨•‚ŠAÇ\no¤Ø	ë<.u¤­œö\\×t„‰Æ8çq¹ÃççªWÙás·Ü6Z£kw}«jdõ„)—ÒðžÛÖî}x¾õÔ¢áùòïÿÎŸ%ÞCh0ÕS	!2ÌLÏ£¦„ÀZ¼æšmê³MÚóm²f—f»C·â³bÃf•bïság!ŒAÅ¢\"å‘,\'ïf$­”îlŠÌä”›šJb°™‡Ì‘\'9I\'£ÓIiwR:IJ.\"S0/Å\"9±h¼x²Ì±®Z£T(ÇÇ&î¹`&k>ü?MÀêM#˜Ð¢ZÑ™nQ¨ y±5·å2Z.§Û+ÔËsau½|&\Z\Z¢($î³ØØ€-¢o^ÀåBÖñä\r‡kyÄôJ£Å3-B±‡«·0Î{Ò±PË`ŒAi…wÛ”á’›·sîè9&}ŠRŠÂèd-Ž·.Tö—V×˜;W§Ó¶@ë´R´¼ÃPìj/ôUëm´U„¡A‡ºˆ¹Â\Z­q¹\'B»‘2ÝìòD’ÛLÈ (Ù\0Œêíç*\n¥`!‹;e£rHØÀ`•¢;Õ&k&Øj…MÕ>Í¶‹	A–”bíåë1½:¥5y7er|–†ËH½/RÝê|žr1ö*Òº°}ÆjÀ\Ze\n\ZØîää¾ˆv7:)T˜wŽùÞÂÜ\\Jä3Ê©¢Ô´%TÅb£t±€WŠÀ{ò†‡\Z˜ØT#F«´\'\ZdÞñâß#O½û?ód–œ)\"ÿ—R&\n°¡ÅˆpìñƒL¤Åt›GŠh˜‚®äÅ~‘Âg)ˆ`ZÖL®1¾0ù,§‘9RíÜÓõBÊù%@ ¹\r„i ëR\" ÚÛ	¤(v·šÞo*i“¡zÌš5o¥¼v€$I˜={šŸÿ…3þùûA|òÍÆ»õæ«	û¨­^E21Åc_{„Õ¯|>¶›òà½ß¢!žÐí…*-‚Š*Òr®·}Py0½¦ïåQ¤·A­+õ:i{¯¦\'I!Š¶‚Ddq»®ƒ\"óÜãË®gT<EÆ-òM¢“M6žgµ-±]+Œµ_²™Ÿºìî>x¸\0¹1(c‚€þ¾>öÜómöMM1‡0ý…ûè\n”UÑ™©¢S\nH€´\'®¶Pá‚\r	/‹N»Ð©¢wPe!ß1š¨7`+Á’Rx Da=¦Õû~!îèóé¾SÞÑÌÚL?ôkâ£ìxAM7îà§NžšU\0½îUòøƒ?à›GNBµ÷\r:À¬÷ô+Å°Öô™ªiKÎÙ¬[<T¢\Z*ElëûkŒÍ7YU)“;O\'Ï±Rˆð°.q¤=Ç¦¨Ì{®Þr.÷$Ý”F³Í©z’µ‹¡•Árç­nJêƒå¥8ÂE•±š¸¿ÄäÉiæšmf³.Ó.)¤Dà²ÑQ6mÛ„ºïÕ¯zü›Ÿ¿wçCyÂÍ×ðË?y#ÝzƒN³Í?ï}Šš(º”¶“>¥†¢%ž¬—BXø[«ešyNêUkÔS+Šuq• 877OÇçh4ÃADÇåÌù”†Ë¹¸\\ã@§Éœ÷$@†°][Æ¼£‹°Vµ·MUD¥w]Npsx;Ï¦rÌ«®¼ŒZ­‚ú÷A(‘6ôÕÊÅh\'4|Îl–rÄ»žî)*\njÄ8UEždAG2/8U¼QÄZõtL‹ÆBt«ÐE×ÃAm™ð9­ž\ZŠÎ—z¬za[aH¡Ë°ZêÞ1%B¶˜ä-Š¤®bV×úh%	õ¤ËŒÏ±MŸÓôŽæ\\Nl,‘2”Ñ˜ †<eÂ;¶ÜpÇ?µ{õ×çøîÝ»ïn¹Ý<³É’7+älóÙ\n\'Ï§Ÿ¿ç®oÿÅ×üúøÃ]{îý\"e1/|pÏ¸~×®]ù£ß\'k\'¬×†ªR„J‘Ì6[¤ÿÇD„ÿ—þ¥£Œ“Ã\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(1234567890125,'Coca Cola',10,988,5,12,'2016-01-25',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0R\0\0\0R\0\0\0Ç,ƒ›\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0Ä\0\0Ä•+\0\0IDATxœíœ{”UÇ?÷Vu÷ôÀLÂSOH2¯\náaPuAä E!\\yˆdu=¬+tìJ@u“&!1!Hä)ä!\0’0“™a†ðH„dz23Ý]¯{÷[UÝ=3äjÎN~sjºëÖ­[u¿ý½¿×½U°GöÈÙ#{dì‘‘!b8.²dÉ][[ËèÑ£©­­%›Íà8ù|žÞÞ^\n…Åb×uQJ¡”Bk\r€Ö\Z­5J)‚ Àu]<ÏÃ÷ýx‹ŽH)±,‹‰\'žzÁ<<}´‡ã\"­¿ZDUM\rA&MµÂéî&èïG¹yå£”HYÇW³‹­±…@¡‘„ÖHJk­ùÌµPZcY_²·?Ï\'-›î\'Ÿš||€<yÒdRcF“ª­Eh…Õ£˜ËQÌpU@ 4¾Ö\Z2DD—µhMZH¤\0œÀ\'“Jqâ9ç`¥Ówôò‰Ž.ÜíïcmÏ±½¯÷_ŸGrÅœóË²HY6BHj¤Äµ,Òv\n•ò¾Ä·¶Ok@c†”4ŸhH\n°… -¥)³m¤Žƒ•NÓùì3¤SÂN¡S6cÓé¤»‹L²ñûgÍ²öK¥¥F§¤ zÒ$@ Ñˆp8!ÐB`I%%ZR–@#\0s)B -‰ ¤¹y)%^o/\0Å×[@J„”¦®¬˜}¾Þé\r~„’(¶Æ—J!U€PŠ½56ndòÍÿV\nKk£ïÂ:\n(„Rh„2Çm­B*‚°=¥5¨€þ®7Í—±ÕY$ •‚@1&Ñ–$±Ë,=cú¶O(žžð=DàcŠŽ+®âð_ß‰t=¤ë\"<éyÏEx.VøÏÅŠÊ|é™º–çc».–ïcû]÷Þg:£4ÒWìŸJ#}Ó¦íúÜ3ýÌÄY™˜Žå«}í€”ÈTŠ*?@»J(ÇeÃys9âþ%<}ÆYøZ¡´&Ð•FiM¤\"‘„fÐ‰lÝ\n€|´ïAà1FÁ{NíLÐ*©n–î+‰F÷ÙÙŽ‹[(â‹¸Å\"Âqñ×q÷ãëðŠE\0¿ùF¼B·PÄ)âíËz¯X¤î;ûLœB§PÄÍp\nE¼bÀqð\0ß3×ðßu±¿X$Ÿ/pýQGw&Ñ×Hado.wIo&cAia>ÙT\Z¡|¬L†—¿sNwŽÜKë}äôæº	´ÆÓšrîLò1Þ}öYÿÖ·yñWw0wý‹4y)–¤„@X>\0ý=½hÏGçzp»»Ñ½½ôy.®´•wÆ\'Ñ×Had¾\'G1×C!·ƒB®‡bÏz{rôõì ·e+Ç._J_OŽg¿w\0v\Z}Ý¹x=e\n«Î›kŽM›ÆÜõ/ÒpÞyÜ9¾Ž“›ï#Ÿë¡?×C_®‡BO…ÆjûZ‘ïë¥oGý=æxu¾€ß×GPÌ\'ÑÕX2%$i!H-£-Û¸:’>þ¥“9uý:\n¡nk]¼„ot¶ÇçxôQL¿w1‹Æ×±h|\0ŸYðC.éêàSNã‚767XB°í•W9hÚg@ƒV\Z+i,¡ÙK\nR*Y=™ÄT¸Ya¸\'„Ù\0^ù—Ÿ0£u#‹ëš\0øí„zæµµ ~ñŸ\0\\ÚÕÀ¢ñu´?¸\Z€‹Û[˜ÓÞz™FžÿÉO™ð•Sýw`)_³ç“J8­Ã[Ê®(ûÿöªÕl¼ívæv´Ò4÷\0în˜ÄWîZ31óÑï\\Æ¢ñKm‰Rk\"¼ffÔ(tøgê€Û¶©•É:”‰»«»4ºìÿ©/¯ãË¾Ëš™s˜ö³ë¹(Úkæ_ZÁD0`^ÚÕDðÛ	õ\0ÜW×Tr•„ùá\0´6›‘Ncª¡*“I´ŸÃâ÷¼È\'§ŸÿÅ—øýÄ\0æ‡€-\Z_Ç)wÞFsGft<|NG«á¶HLøXxï=¥JagyòC%ë“S\0e$\ZŒ“®¼€åM‡ÄÇ\"¦aàW]Í·ºÞ@@…ÑªMK„´-}\0\0Y¦U¡@°=‡]¤¤$1 +ÿJ]Yy¤$w¯ã7‡Nà¢×^J:2:ð—y—p_]\"L§E:rÛ†\rX¶ÄIa™ÍbëÔ¤$1 Ëo[—•Nùñu\0<|ÄQqrëëõç±ïÒ®Æ45†¹\'Þ}g©ýÐÐ€ò<¦Ì»¸ä\Zhv‚Þ¾wôÑË°$v\rkŒ\'™=ð\0Š[¶„à‰ŠîEYq€;\'0Ïz`)LÊìGÖT´9»£•\r“\r…@câò}=KH¼¸MNUŒ@?r(‰üÈW®û	ÏÍ½r†”û—;/éìà’ÎÖÝr+\0ãâ´ý)$Â²ÌüM4-Zma%Ë™Ähr¸¿§‡û3\0¿ûÏ_ÿo¹+¡«4ëÑ5ÜUf|\0Þ^û4wO¨\'% -$¶¤„4LÐ&l[†:¾v8´ƒ\0Th?‡…‘¢Œ7‡ÿìz\09òh^û÷˜¶ð&ÆtR¯`éI§0¿³=Þ_û¡}Ÿyíõ\"Ý&Ð±„ÄïÏ£”Š]#mÛˆL&v…’’a2Ê#\n¬lkO:…“_z!àù«¯áíGãko´•\0ÞxèO|³³y›X·ðVÆÐÌY¿Žòé_KHl)yçÉ\'P½)„™Ò@kÄÈl¢Oã½úƒÿè\Z?òÎhÙ·xbßèØï?ñíïÒ÷Î;)C&šòæ#ŽŠñ¨MXR‚€­Ï>˜™FAé€ù%”Dudtë½*`ÆQŽâà‰ó¿ÉC“ã˜›n\0!øëÕ?@HYáo6îjÆÌÌ\'Ÿàâ²ìÀŒöV7ƒihðúú©ª­Åß²%f¢ùqÍœµˆ·îgŸcâ·/E\0ë®¹–ç~ðCF54ðû‰\rñ xúésíúº6sOB”hhK!c‡[\nÁ\'|KÃ%,‘N£ýnlÊ³3‘hýÉO8µå5\Z/º‰ ·­4|g<º†\\Kën¸Ì~f-íËWð‡‰\rÜ[×ÈW_ÃÊ†ÉFFm‡L¶-ÉÁgŸf.Â÷Ðþ\rËEA€a‹u×SSàS×-`ÂŒ³+ÍÊSNãìGÖ”¬øqÇóôUWÇé­å+J?PlTŒ3jK»¶Æ$ÓB·(é„£Õî\rüÐñ±»òÈdW³ð&æ”\Z3/|£Ë¬ùâ‰\rõ*Ø.„Iä†Ö9ˆ4´mƒmaUgícòC;~æ3òKßW6NŽëÎ}£-Ö£ÿS×—­¬¼¹¾‘³Ú[bk]§K)õ†Ø—”–…¨Ê¢\\$eØ)€>¥ÂaX6õ€`yÃ¤¸îW;6ñÕu‹ë\ZYúÕ˜‰¶#n¼!fw²%ÑQ®{‰ö<T!ú¸èH/Ë+ciË¸ég°¬¾‰þÍoÅçÌíØÄÜ¼%u,©k¬`ß\'Ï™QÑF4½¡µÆ}V6¯\rÂN>73,±vô)„ _)Ò”À8ú·pô/ná¾ºFp~Ç¦øüÊ¾ç6¾ÎèCJª bhlájš\Z)lýÖH×MÜ!O„‘ZëžòýòûZWìàeCàë\ZéZõà vËAÜþüßÊbî+µÖ¼ÿÌ³4^q9 QZƒÒh/Y™#=À¨Š¢ˆzE% Çu&Ëë›*†î3—_É3—_	Àye¬x¨ar¼N²œñ‘*l~‹½\ZêÍÔ¬SŒ—´$)‰\0)`#ÍU­-qËŠ¦Þr3So¹™æL€9í­ÜWoæ¼£O‰™3ÏYa®ËY¥ä\0³®2•¥ÒJ §%žÄnl\\Â%—¨<Á;«½•9á€ûê›âïC6ý•G7TêÞØ¢œ% u‰‘•PÁ¨È‚èØ&¡\\ÃÓ9í­Lž?ûC0êT€“[7”NÞ	F\n…ò}„#uQô*	ýG‹r÷§„ÁYm-<pÈî‡ñ§\\Ãì‘³0óÔMy´éÐ²6JHFÃ\0-¶…H\'›ùÄ€Ô…¡JGÛ©!‡Øƒat33ìþú¦Ð]–²vu´êÂ@»I§È“q„pË÷wE;E.ÐìöV¦\\ñ=€Ì–»îŽëÕÖ²óFÂY´\ZíûhZŒÄ¹fÐÐeÙƒtÝÀmYÜ¡—}—Ùí­{ã\r´Üu7“æÏ¤kŸ_òOíÑÆóÚïŸ¾„È¤ÕÙ;;ÈÔXÍÓ7½ÎÔ[rn{+ÍõM<>s6\0fžË¤ùó†<§æÐC•EÚíÿÅ/PwÅåè  (:ˆÉÈbí‚ëñâUWSÜú\0¶½´žæÑ‘Ç®X6¨L…zpÿŽ ³ÿ~\\ËÂªÙ{wo{·$ …¨ÇìÂäü™m-¬þìñe˜CúXÓ¡ƒÊ”6!afì>\0XÙ,hKŽLcÃÎ\"›ÈêÐjŸÛÞj×—Is}ûO›VQöø1Ç\rÙŽÒ:\\ÖWº¢_,âïØ1Bó‘C›“•¡ÕžÙº‘Yí­Øeíÿ¾¢®—Ë\r}ÙÈò2&yídCÄaYDµ«²¬¾‰sC_rÆ«/ïòyf~Æøþ@ Ñ)Fæ-K:r(CsØC«˜²|i¼ú¦×9³­…sÛ[é\\ºŒ¥eÓ¥mÑ]C_“‘t¡°RæiÙ„ud\"ŒÔÚŽÌ`Bã=wóÚiÓ9ì¡U¿áÖ„FceÃ$<­©»ðkÌÜôúN­ö†›šìOt­ðŸÖfé\Zøˆç\r]þKB‰Ý’Ž¬\0¤ŸË¬;æ8Öú©¸üÌ¶jêë8ò_Ls}ÕÄ¬D1ß¿²òz˜ã•ÖìóéR›Êu±m+•BôÕhöW|ŸÃV¯¬(‹¬ö—ÿüpÌÄü»ïÒÜ0‰YC¤Òê¾uIÅ¾y¶ÆšÆ¹sãr?ŸG¤3¤F×&¾>2 ÓÁ‡[í#×>Y±YíYí­|þžßÄå÷ÞÏ§\\³ÓvJ \Z eªXÐŸ×E÷öÐõ‘ÙÒéz™É0uåòŠò(Ö>à„ã™ÕÞÊ¬öVêÎ›=(L|ú´é@Y¶L›×4´Øï?÷Ò¶±ª²‰›a}<$’¶þ\0Õ\rõ|yÃ+Ç>,4èÛÔÆÁ}Ýì„Ëœ•Vd:¨¢^û¯ƒ°-DÚF¦RÍÍïDòÒŽŽÚëÂèDØ6§oz½âXs}S¼=õõ‹†·ñZ3Ü5ffÒST©òo¾i¬yÑE#qhï¢´ÚUì?¨ÎÖµOïô|Òhæ@‘€*Q}}æ	Jâ@ÕÁrYS–|8ý¯k‡´Òå”MCg\\_kÔŽ¿%V6‹U]½Û÷½»’8ù]`Âê‘Ldh¬Xekr†‘žV|¡ùÞ\Zpóž‹„gµ‹»˜™^Ù0‰ •bÆÆ¿ÇeçlxuÈºZk›<K”ÖxC¬ìl^Š-Riðƒ›F‹ewî_¹.ÍõM¼ûä_>°^ÇßÇÕšÏ¯x`P¶;;“AÖÔ@ÂòdYþH×nÈÚyóãïŸþÑµ4Í»€÷ÿöOŸ?—Løº\Z\rJ“=ð€Á¸RHd8.­‘šF«*ƒV\Zd´Äd÷A}ùç7ðòÏo\0Ìð±ÃEö\n3Ä½0ÞN¥‘ázI‘I\'nµRÌT¡}Ÿ~ËbL8‹ga`)&Vz(&\\b\"„yÑ€([–§\0%¾ÖÌhÙÀ@	‡TU•y4Ä÷Ð¾…Ö:Ñ¥‰ék\r}}HÛÆ³m„m™\'´6Q†”Èt\niYæÉÖ @*eæ¡•Nf2¨ðEK²ª\n…\ZåFGîdÍãæÕA>mYÈtJ)f¶·$\ZÚ$¦OÛ´Q¬:éjs&¥ÜíÛñ»søÝÝ&?ø\rãB ­ÊóÐA\0Z™ÐÏqÌ«g”ŠÕéŒ‰f¤ÅÌ!Ø°åá?“©­áµbž¥GOí?ú¯ÿ—¬ïCÂÆæ¶Ûn³\0{áÂ…^gg§:ñ­w½I[¶f´çæÁôhiž\0™JƒV(ÏaŠ)±öª6 ÷õ™¬»:äÛÜÕ¥~+uŸ&¬\\±7¯¬/&ÙÇH’þ¥ö{ê©§6k­éîîæwÞ¡««Çq`ËVÿ¸ÎÍV•ç	åÑÒ\"(é42[ß½aÛÈêjÐ\nÑÛ‡´,¦._Ê=7Ýäo5ÊªÞ{oqðÁ3vìX2™Û¶mcÕªU·.[¶ìàM HÔÚ$\r¤j)étzÚí·ß~ó¾ûîËØ±c)\n¤R)vìØA?Žãàº®1RRâ8{íµ¾ïS,ñ}¥ŽãÉd;v,Ùl–T*…RŠB¡@OÉ•üò—¿lmoo¿Xüx£€)ÀáÀøÃ;ìäqãÆš:uêÞûî»ï˜l6›ª®®Ž]¾t8Ÿ7Ï]ËðHÅb¥ét\ZÏóâgß~ûí¾%K–lúÛÛÛŸÀ°ï=`3Ð\nt;á@\n ì~ŽÆ°4K‡›ÍfGÕÖÖŽ³,«&•JÕDÉØ vxž·Ãqœm===o>à.Pò@?Ð‡r;·þ°~¢1bâÖ,¼†yßp\Z^€á1³5^ÅL©óAø=7Ÿ˜>àP¶¼<Î´%-Ãdùµ¢ë•¿®§b	xYxM=e³\n”ÀÑCì¬?l2œ@~ìî};P{d˜äÿj—­E%Èv\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(1234567890126,'Paq 1',40,1,20,0,'0000-00-00',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0’\0\0\0–\0\0\05êÑ˜\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0Ã\0\0ÃÇo¨d\0\0 \0IDATxœì½Œ×à÷nq÷Õ¡¹÷j3ÜíÂQ	K‘öØŒx§Øg`n¢1´\r¡4Œˆ	G6²\Zz‹\\!+q„;Ò:RlÒÆi5vb)dŽ;\ZÖiˆDÎŒ93º£ÂfŽŒ‹Wåd«rj\\}cÖròÇ{õ£{z~ò.Ö}¥f÷ÔW¯Þû¾ïï÷ýÂ\'ð	|ŸÀ\'ð	|ŸÀ\'ð	|ŸÀ\'ð	|ŸÀ\'ð	|ŸÀ_ÜÍMZëßPŠßôD\Z:c?\"ì¬7H’ßR¨ ^0èÿ’\"Ô÷ø¿	r³}-ZK3p•å¯Fÿ·ªiùsA}DÝÿ·.·àiýë~Mý½Td\'ù\r~“êuý[® Püz*‚¯=¤£\0P¨ÄüD„?×u$‰ÿB÷VÜIÿ\\jîÏ•ÖÿOk%ü?ÂŽ\\ŽkªÕ^M®üâ†´?¨šú»º¦|\Zq;¡\rßÿ«~æ_\'4h×ÃªÀõ”R\Z´$2 <\0•¸€rd‚@9qd¦±â¸S>ÀôP5…ò5¤Bt=2\'\0×XÒ¢É„¼=USxÚEÕáõ¨š‡›·ï˜k¤#e›Rž£“bznþN³´è—ë¸\0k8æ\\ì¨ëIGþMìðç×ÂájE”ñ/ýºR\ZAHÛRÿ\0öhüCâ„TÀs3P5US5µ‘_QJý:™àºÚ#”döý˜øIkÇÝOÛß<p\Z»ýÇü+­O)JÄL’“#\nvÂU9i‰T‘\0A,’Ùß(”2÷à\05{­çìRÈGf¶E…Ÿ)p’$¤™™xW)”2PJÑ<8„$1IlîUJ!\"ö9\nE9I¶Çˆ£Ì1ÓÉ,¢¦¤..Ê/“ÀSPÏÀßS˜Ì¼“H\n’‚ºîYjªPx\n…®(Ç$_\n{LÒbœþ¶ãÇÑA()‰ù6ˆàïõŠÕ®jv\0êñjðözæ˜c&QkÚí!IŠÄ‰9—±ó(x÷ø¸uƒX’$¤bî\'v[dÌ(ÃöIQ5`áY©¤ˆÊW;)°\nI\rÂkW›\'ßTÇÎx>‘9%u”¡šŽ¡À¾£a§‚[®¥Â·Ìµj§írñ´“|ÑHIMÝ|¼2@IyˆAÎ¿eàÐ‘ºBá:P¯ûH\'.#ºìHÚ	ñJŒ·ÇC9\nÿþ\0RADð›`;í®R¸{Ô=C5,²$Q„Þ­\ru²2’ôÑ®ÜTß[Âó=òC†6åËÝP¯¡@&ÄíÈP›énaÉó‚ßŒQ»ÜøæšNjØpÎ\ns„±OSÊP·æ¯Ä¨š‡7¨\rl\'H\'EIJ¼ŠyÆå*”vq•&ÁíˆE¸òÜÒpþö!Ò@óÆ¡‰•è±ì‰n9()vð’–K&%£çª÷ÙÁt@Õ\\DL[’VvI³²Íê=ù}…Ä£\\K±zîC,{­@&›.´,úÛã®cÚò•*žïÕ\\$ƒ¨JRPËØö¥ ˆÅx”¿µÓ5\"xJÑ|xWkF¾3{WŠÎßT\0v¼ûØè_J^	‰:å4HV\"W’I1`\n…‹™ØœiyŽ\"ÍJÛsÊ)“R+°kÇÊ[ù*+›«‘BÎ*Ymþ\\ó¯[™8ˆEº‘ÇÞ\'ÐÅÆr5!¡Šn‚A€œNxhûœüXÁfmËI–¿—ˆT —vÌ)¥ðïó©>®Ö\\~o™ùk!çïRcþ›\n\0Ó5µ6úøt„ðâ’™«QpÏdYÈÙb>ñåqRP1Ÿ™ìõ\\gb\'¡û8PhŠ)†ZQW\n(ä»BQ(Ûp+Í”KÄöKŠ÷ËF\"¥ØEQrÙÇ)Ûª¶Sj¥,%­¹xußŒf\'B»ráÃæþ–!’Ù¥¦Ð{}Ò+¡ÑXÈWµRªþ9«S=”A­kÞ@ÎÂ\\òÕ/D*³¬”\nåé¢>öùÖì\0vÀLX9‘ªòKæŠõY}kÌó+ýV€(«MV¯·P¥„^ñÛ(%æ§*Þµ~`n0ÊF\'%º›÷Wüï}Wå/18\0²7øËèjø+úï~å{$—BDR£Ue%ùíj®“³¯MÈé&÷;´ˆé#D™ÊéIÑ×Qëd\nºÚQ…l’d¢\nYYdÈYn®Iì­r+Ó©i+,Ð™¢MBœIAƒ\nÏQh¥pëna’À1·+G¡Üüo× }—´¶B$‰‰Å<{	Žms~~i`\0`x_câÐµðŸÕ5þÀhù@ˆÃ^*ˆ•]2ˆWãB†Úˆ­;q¹­*­\nõÙzyc£ûÁ\"˜Éí¥<ÅµeƒJ•†É‚\"Y¡ºªê+eM\"¨šGÎør•]Ù¾‚1)°³´—åÚ¹M­.¶+ÅPþ˜…ø‹­†ë—	€ÖJøþ($‚{£vê¸ºÔ²Ðh‹PŽF‰ŠB:y+†õÈ‡à¢Ìô²?åæ:6\ZËFÌÿ¸ÔÈ\nC	óû+Ø¥ë(Eà*£!Ý²È˜•ÔMrê#bîÍ)”cù¡c\r¤9\"9nÅZnYc~\ruÃÒ;9R£eæ»U±ueé\\Q+$nÇAÎ¦ù9ÉMÓß|p\0’Žü+±«=^‰IÛ)‰n7P5t¤T½Ý^i\\KDRDÀS^EÖ(-@JQ¬Ðâ‚\\0¥bèt€ÚØ <fÕ+ó·[P…›	dJcg,ÍÒBŽ3æ!·‹TƒŠœWe«ù§jd$3H$H*%òf¹øoLi\",}â9Ý¦ˆX†ÿ¸½Á|üÒB1dèâÅÅPƒD’ÚÁâ´\Z¯¦ˆ\0œ”˜•¹Ö\'gÎ+k+lO¸;U÷“Àq×«ÚŸz¨šùVë]\ri\r­£‹Ju?Ï^\\Õ2ówÏŸKnO³v¨Lˆ;1|dÿ1ÙÊ‘¹Œ¥ö™k}¥ŒƒµÙ13þ;þBuŠÖr —ÈŒ|D’Ôèš@ƒ4.’¥Ì£¤x9•@Ð¨‰Ö=U¹Ýí¨\nUÈ)Y~½TXHÑN‰ªÑz\r«=P¥HòP.¨ü=òÅ$¶MIR°¬Ý­\">å5¹“¤|v¼¾¿üP¼^¼¯ñ_\'×Â§ëNEãˆc³Ò:VŽY‘k¤Ô	$-†{Ù9\\š\n&í\'€Îª²R·H½!kÉ…øœšÕÔ:+5”+½ÚŽˆ”¬¦Ji2)¬×\\!¹5½[ý‰ŒÜÌÝ1ö^»¨¤§IŒóØ˜7ŒýlÝuË 0Š)¥Ü{üÿW­Ä;µRøuþaÂ1,\"u,eÊRëiWÖÈXNÚñ¼Áš‡&eZ¹ˆc\r‰x»¬É 0 V4*Å¨ÊH–­®Óéz¨I¯é¡zMÎžJ„*ï]\'?ÙëDRâ°]1PR8{¾èŸ¥VzÐ#Y‰­‡ É¤ÐÖ‡>Ÿñð¦3òK\n]ÖÕæÞ`äp;úŸëJãº¥z,˜•Vñ‹™CF—LHÈ©‚â86¼Ãz»\'”â-Çe’ß£)¥ðjÊ¨ÜùDöÊJwU$ì÷wN÷·\0i#7R¥úpÎ¼½’ÊQ •ÒÆ‡(«)©¯H„–e—óJýýDä_}¬wû\n]Ã»|=\\˜°,$¡ÙhR®åû–lÇJ\"h‹L3aJ	gE˜$B;\n±F=¥\\”V¸ZŒ§>×²¶û½Bwï½›P:ƒ)i\"Eè‹R=÷ììio\'¨\\»´–ìÜNUAsä¬ô/¹ºÍ·ú¥ƒuþž3÷‰´ã¿Ôºæ\ZÒ/{ºd’Žq]FRÊ/çhÙ°SƒpMØnQ–c(F0ÅÜÁÛË’Š¿ÜZŒ	CñT— ÞéúQ%\0R$âU±šWj}Ûžª RþÙYu¹¨\nòZù\'\\EûÑI\"±}WªÐ8]§ê•³æ‰,×\nÍ±u¿·=‹(½•®;¾Ýö”£˜oþ\\üñâ¼ýX7\'VãÆ)‡M†A š½Ê\nŽ]!Xv–)´mÛá‰NXY#¸ü¥:gO\nç2XNÛ˜E˜¦õ2Ù>¥¤‰ UH¯oô:¹ëµ{â6F•O²E€Ü8ª ÷»˜ÖrªäØ³ö7v™Sû\Z4î	zÚ_¿øòwìU6¼çN`#¤Ézªâ‘(æQ)öAmñÇ‹wüØuˆ”$IäÖ Ÿ’4_UÕÀqÒ.ûQ–Pg*9ÅØÅ6‡—¡•”†Ý£(ÆÄXÃu;ÝÚýânøw×n‡Uæï–#••\nÔì§yVÚû\'Ó ¼ŠÅs]Ç°Ì4•BÆ„^JQ*E|wyf[\ZßFc%€ò}ö?1Qh§Ñ¥%ÂŸ.£µ6^	ŒO1ºþÆ<²€¾¡§l~¬DÿøÚz¶ÁÒ´Ÿ«´kqXöfÎ/`¨ÀÒ§š‹?3x‚Å\'g8×Î&Òµ‚NaØqnÜiµy,T„fE×t÷…êù®k;‹º=^XKË¸\0i¦ÝÀ«y(­Q»ÌÔH&è45®’Nb¢3í¸¥•@¼;ž¹>P˜Kl7so„ë@¬}Æ^;S\\»üÆyÂÅüÝ>|d£b“„°sê½…ÃËíöì<»ïN†ã,?\0 2K‰òjºq”ºÅ\n2‹žC7Û©9±’B²$°ï(Ãï·8suŽèñ€±Á:ªf,ÑÇŽf	óYBØég3rYO*P1\nV¿7µÁïbÑˆýtìG0+ÈZ¶Uåú¤ÖÀsJ%!wZG¥{§bëª^³ôQ‚ÖµQy£…Ê*œ ¾¡”	N­,—R?8ra‹¬ƒ\r·Ä(Ç-;¶™èPtË8£ö{A¹x\n²ùÎ8È(Eý•)fò83¨ÌKY˜É„!Î„Dò¶»#¸»ûÂÖƒ·õùÜêù1,è•òº)ÕHóþ$ÏPbU1÷}¿|Üs¨ØßÄ¶Q¶YÞãb»êØN¥”óò¾9\0îºwØüÊF\'Úû‚ÿåþ¤óŸy5—½rË¯‚ã@¶øUv8ÈÏÅ(8ŽƒÜ†ìv†üˆaÿ{1þ~‹Õo^ãüßÍü·x»o Ÿ›`èèÇÿ½x—„u€Û‹·3~	BÆ=?‡ÀŽŒŒ‡ÆíÙ»~‘;Åò÷½\rîmóMVùv [sÈnQ­‰¯váXÇA¹;q…s;Ãù¹íw–áÜÎ€8·3vÀNûÉv˜¶ÀqœÛÅŽƒ³ÃË\0Õó78xd·Í¢ÎvÀ®0°Ã!»í˜ù»qÏÁßÁ±¢ÊÕ·€rw±ëW2Ôøy·3víÈÿmç£ð/’mKÝ\"Rø¯Û×²ß¾ÿÿüÜíl¼˜ VÜ¡`‡}AÇÁÙ‘‘upvì„·3²,Ã´ãpéçó;þÁÅˆÆÑßfè¿ù§‘0óî*Þ…Ü~	ïï)~çÉ{ù/þ}‡‰¿³‹™!Ë2®ÞÎøÁmáþÛÎÏ3þò¶C\'ËpœçöÎuÈãb¬ý¹m?yû9üÜ~g)\ZÏóqÛ—\nõ«üÚ.¼°óß½ŸÎÿÂ¿s>ËÈncE% ËŸQAàv”Ïvr%àvù·sÛ\"âŽ²ÿyWwÚ—‰°û?úÔàn\0V/þOdî.ÜebÚÌ Ó°Ï?úî‡—þ«ð£6]Ãs,ÿ3•orª+kŸŠï·$ÑŽb$7Æ%	“A9)ÃöòvGxæZÂþwB¼Zœ~j	n@ð˜&>ðÖÞº1j/e	Ïd	o‘ð–µ[…nŠ-¤§ÍaC6ÒçÚJpQìh’ÝAìÖ«Ñi«Eð¥I\Z¯AV¢Â\0Úeÿéq½¬3°ö^ÛçœÛïùU™1ãêª€_«°°öíÍzý?e›°%3ˆWëÄ”Ò•¡ŒÅ6síµ]ä¡¯@—/«Ýd1aŸ	Ž\'	‡ÞYþj7`ôYŸð±ÀÊ¦Åó\"ìŽZÿ^”	’¥…†ò×Æñ+»ƒ\"<¸\"}\0àZÂWO#+mü\'Ûà@{iEÆrÉþc~ºd·²?’ÄÝ’ƒp÷µ¥yb¢±ÿ¿Üîˆl‰H¡¤¤«R„L°d§qäJ[\nŠ`”^O©\"@þ”£ÓÁÙ‹1S{4º–ÇÑµ\Zç;ÂÈJ÷k-†^XfábLúx@|ÐçÅAsÏ	IL˜CxFŒ†JL,)i×Pl¶„ëLø&AB*§2=B¸›\Z¬>ŒúGž8¹#ØÆ;õèïú“›TL„²Ç•éJX¾Ê\"^Ýu×÷C„­Øîn‰HI&k¡¤Ä‰ «R¸r-CÚ¥i¿ª%hÇEçQÀ‘šA¦í„Àq9œ[Ì7V‡ÚmÜ7Z-†øÄŒY’<gkG³„g$¡•	mII²”8£?•Ú@uVYU‡êÒ}Ök^™6\Z&óIn;Ë(X–Ê¯Î ½…1z´žš@?6Nó½w‘0,\rž½HpŸ´¸Ÿ.ÓEõ\0ÈÕ‘T•\nÝ²›B³´‚ˆ¦3ÞÜz¦¶H’™½^‘˜Ð±ûà“LH>KÖÓ€ÜÒG¶1H(6²p¸‹¤nÝÕ0ƒ£í„ÉK!§öú4û¸æ‹ÙýÑÊ!EèfyŠ\nÂTYó&Ï_g“²“¥¬¨d\'=ß·ì\'+}_¶Ëvw{öÞ6 LÒçØ†”ª©lp²Ú\'T<ì8)Ü®öÒL”\Z®×¿ÔtJØ‘ÒLâLhu„…$âò•˜h%!âDˆ2!ì—;1‘¤eŠ\ZŒ³2—!ŽdŠie¨ÒD’r¨*\Z÷¸^º^²çøl\"ìÿ0dY„†ã=øtTNt–D˜±gæ“ïvXY?Èj|¨ˆ&va¹Æ1›f©qIt$‰a\'´¿3@sî-Ò0²d>\"•ÏG‚Ä1C\'O\\m•í÷^S9–Ç—§™ù)	Åf™‰«¬mÂ\n\nCQS)‘ÒN4öŸÝjl6§Ž9Ÿ“õ¶‹Òf!_ê×Â,\"_›E8,	Ëö·v¬Œ„I0¿ÚfB*^ô­&6ëßÓVf>ùs’¬dB/‰QÆXÆXlËz´ãâmkªXjDJáebØ}[8‚§RÈTá¯s?=Dý‰#ÐN ®Y;„ªèGFñŽ_i™NªÒd@\'Af˜ñ«?cù«\'h½9‹ÒÆ\Z-í„#W/›ãß;äVZnž Ò70éf\\i_Êù‹ÌÚ®ŽT@n¥ÈN M©+õ¶Eþ×FjSŠ¤\n¿6…	ŒÆ6…K¨ Ì„0¢Œ®Oà(&µÆGq4+IjÓ©ZùUôn-ÓcÖ\"žXáVgt0Ôáh&hà‚ˆIá`d(îÎ·•Zöœ¦©•)R¸•Re-Å–p¥5ÉY|tŒð[g	¾z‚è½y\0üGÇ‘J;9‘œÊU:Ø<9ÍØçˆ¯ÙJ\rjæÆÓ<9Íèk¯“´.[ëujµXû¹•’Þ¢¤|9ˆTØ¯íwfžYd½³, Ðz|³qÙtÿùØg‡Ÿù õ]°¾(K8¼>pøÒzPoÖÞn•íL\nÐ‹5]0“%œPšã«íÙ[6A¶µæt’nš60YSœë$ä^±×•¦å³™0í¬ï·r,µ*Ü9˜…’HJì˜…¨«••Ùô »KAMÛ°axör¥Åü#‡HV\"ôƒMÆÞ_\0àìÀ\0jO~V0éÄ~{Žúg†»Ž/í,K_?tbd5¡ñØ8c³8=0@°7Xï¬¶ù®$ÆÞ[0HøùÃ¨ºoìOI\"¤Qd¶—ç–%¦ÌIü/fW“7\ZÿM)’«£ƒ>£Ú|\Z5»w­ßî\r ¾¥†–Ñd0Ó1\ZÖŠã«mN\rÖ×#Qçf¯ÁMª¦Y»µÆôÍ˜à&\',b¯ÝJy=Žñïk\0†õÍNw„I’0ÑIÌ·ýî$œ•˜PR\"1¾¾…NÄñNÌñNÄ™LX°J¬§hâ¬G‡TYi£ö5zåJ+dµºOaè¹ãÈjÔu_²\ZáíkPÿÌ0/\r ‡kó+SL†?câ¢AÆðí9Î÷rlmèzHš¬ß¨\"\0J]œ/Úñ¬Fräc­j69ˆÖ¸JÔ¼ß^×h6E¤¥ªÉ÷äW’J@×o€p¥Mx=,>ív»+·cÇ<Ó‰VŠ6ÂxM1òÂqN½rŠè‹“]Ï­)\Z=È\Z xQ×‹û8ÿæ,CÃ#´>\\æøj›v.Îƒcv³4­–v&¦ìNß^Þ£8ÜI˜èDœHBDy,‰à0ôôÁ¡uæb³eŸ%·¦˜x”ðg©?>Nã«Ó†=åãöÎ<ÑûKL¥)í•°Èù„:0ArÍ§\'9ëûœ |{®¸W?ÐàØÚ\ZS7cRfG?ÇÔÚ\ZC/œX·0¦ªß±÷oNñüº£Œ5<T–þåf—o­þ;E™.U¶Ž?Œ{ï¿·øŒ<4ÊÌçŠóZk.œ?Ç¨µ\'µŽ<q„ÆƒMN½<ÍÒòKËKL}åKJôx¹ÇjŠ—’6Ó_fmm­øˆGµÛüìjd(TZ\n­õzµ4%\nË¸¦8+Âècc,¼7Ïåå%Þ½8Ï©—§9‘$L[cé\"Šé$B”âÝ½Ë™WÏpè±ñ¢OýìMý@ù>­WOÐøò#_?ƒ\\iàjå7Î#IÂð—§¶aóJk¢÷Ïtìµ×Í«=ufï0‰½·€šbbqÉâ@ó•\ZZ8 +f”ã–óØé\\eó;Ù„®ò6ƒ6gmäöY³úãLˆ³Ê™Šð¦C5Š¿¯‡„ÏŸ`ÿýÅ±ñÇÆy)i3¬§“6ÁÞ€±‡M°IóÁ&Í›œyõñÍˆoÏQGq¤¦™ªÕi}zˆµ[k¼øÇ/–´°vk(üY‘2°/Ø¾\0OL°–¦\\ø³f˜Æ\rF?;Ì±¯cíVÊ…½¾•å4§¾y†´âZ(‘¦â{¬ŒA_P\nuÀ\\ÃŒEãËS$7\"Zß™!Mbêõ:3¾ßlrlm¤¡´‡¬Æ$×BpàÅµ5‚‡¡jŠsÃ#¼40@ë{çËGjÆfË0¢¡“Óëú ‘A$·^ï¾{ÁÊIž*´lr-[S¤Û’‰ßÄUë5BvK­L8Ýi\\XŸ\Zamm\r€ðZH²Z&.Í½áÏãªÉyI8ÛióîÞ-VW»ÝfùÃ­Þ•‰icö‡%ùo¯´™ýþï/±(¦_g¾n\"»ŸKÁŠ—Þ_âÜùs¼ÔI˜|ºd»IÚÅÆÔ¨8“yn6¸¹Rx”ÆÓ“&ÂjU÷™þ§8f)ª$	gï¿·hiì»¯3ögH’=Xgþùcœõ<–¿vzÝS›ü¢±]õöÆóÕ}€t6q&å ƒ>~M³iÈ*[!’SÚeÄÚ¯7ÆË´ïŠ,ä\nœþÚ©âw’$€w€w€¹\nÌWäâúÕÿŸ¡æ~ö7÷¯;/’pxüPÙ«,åðçsøó‡\0áØWLj¢¶µòºžËÀ.Ï÷˜üƒ£Å}c­kÛ÷=NœœÞ¶Š>HVBš_fîÑ²‡Þ™ÇÛ×ÀdíuÑõ:sŸŸ`by	ý@“úž€ÅçO×2üÅ)ƒ|–=Í=wÜ°Äê8\\Ë}‰Õþ:ŠäJ¥½uçº°3m5:I¤×BÕ›#R&·ò¼EG6zî&g¥‡,ª	@»04<Äá¬t—j‚g¾ð`,çÍ›wd‰>RÓ=	»º§wÚ’üðJÏ÷‘Þ­kÒhs¯L~ú^î=°ŸsV¾kWÜ\niœrìËÇéj²å»OO<}„ñÖefï1”¦þÙaŽ\\ºÌè×Ï’\\Mìûâ\"sŸ?Ìä¥%Üz¥ïÍ0ÿl‰ä£¯áØÚ\ZûŸB:	º¦™ñ}’[´¾vš³;]f›CÐk¢\0cP½8ßl¢jåù´r(Ìj·ÙÌàêµ\r^ØŽ°M·†Ô…=ê8œÛ2x«“qGÓ¡+SC×Ù;@¸ü	SZ1úÆ„1È½y‚Ï]‹9urš‰\'\'\0ð}Ÿóoœ/Úöƒz_ª¼•AD®†4_.å–ñ?ãô@)¿slm±oÏÐ^	‰¯†¼40À‘÷PÚ#|{ŽÓ´R-ÿÑ1Ž­­1yµEðØ8K/OÓøÊ1¦n¥¤S0E­Ë¨½‘“z!C»óEn\ZŠT÷îwœº™¸U»»Ž»}Ilï]g·0lnîÀ:ì\r~ Áô“|ê8òÕ	æ^½L¬ã•FÜQ¥˜øÂdïlœw7c¼O7»µ¾u=XgñKG»ŽŽ1úG/’\\Ñ{fÇ1±¸`™÷œ{h”^Põ:c³=_jÉÞÞîýu]cc‘Líö+{=\rÝqß8êchm·Ìnˆ\\í—-W^a8t`ØQÌ$É&\\¶v¡×eòW§ÿÉi¼çGYx5@!ùÝÜo„L®$ÄQ·r0Ÿ	£p=ÏýÞ¡»på(¼O1<Û½1cùÙ£¸5—ð9ÎÐz£ÔÀ†_žæØÚ\Z£¯LÓz{Ž…¯N3>÷Éµ]7ö¤³]H°Æº„iU¥Ö9u} ±q9Õ<ƒTJý›=oa»ü™öüMÏ6d2PŽÐt(B<EX»U²ÖöJ»‹ýÔë†ûÌ‹0ZÓÌw„CaÔu õáò¦]Ü\nüºFkeýo0ºÛcªvýl\0×BæŸÃ{/dTåþ:EéL¦Â7§žÛ@FÚ\0Ò(¤ùÍr?™´fƒ{Q÷•“¨ö,<wŒó†hW,Ï\'ŽðâÚšvWBŽ­ž›%¡\0\0 \0IDAT­Ñ¶”J)—Ó,ÿã—ú?¸Ó£üT£VswNsÈøàú-ŽÜHÛ‰MHÉÇRÿ3nå1=ÒKªá¢À…óçXú(5Ÿ4eí–1–*{‚øŒ×4‡LÍ¬ÝZcáfÌÐÁ.Ô=Þ—#O`êùcëõí@uõ)¥XZn1Sƒôdƒ…¯7@ ùÃÏ¼r¨³–®q!ŒX³ûæ“Õ„Öµ/Ö4#GHÓÔ|>J™ùfÿˆŠ46ïÀP×ß³y‹^Žã’v.|~‚óÍî{F_;cL\"L-/‘Xc£Þ°ôÍNÐúÓÈ`þÏ°øìQfì·ÂvÍM)äzˆ\ZÔH’öï»S\\l¿7xAw¼g½ekh]	ñïñ¨£˜“„Ù7Î3ÿN¹òTMñúk¯Á¯‡Ì¾yžæøõr­•Z`{¥Íòâs\rMu\'–…‘#f1ÆF‡.ç³d0ñô$¾§^9µÁS¶ºY‘2Êý ¥\\¢[Ì}á¤âJ@)ôƒMÔ`½Ë¢÷Ì}éqž…oEí	Ö·_	â+}w,Ô|1¡&›;ø·Ø–S#…kãqòlî±\'¡mýoûÜË˜Ò´­³eJk}Žóoœ7\'3u§Wcô÷/pâO^âÞÆ~Né:Ëvå¶>l±üA‹°Ý-Ã°üÁ2Ë,Ùs³„w€åŸ.?:ÂØµèƒ\n™Ü7CBàÜwKáÔ(&	áµ?ðmÇ]Mhìkt“ÝIP\\þðHñçÜ!T}sÙ@×}¢‹óÌZG\0¦nF¼h5<·¦HV\"”£Œ–þŒc¥ˆ¥ZŠõ¬Ëu\\â\"ìvO‰ô›²†-EGS¢A!³Õ¢6÷6‚#ís\'m¼Î„3³VkXxvŠ‰§›{dœù$!z àð«ÓœÑ>GWÍËŽÕ4Ç+2¦4sbÚs\'–šLîLEãü|^A²‡/†ÌwLêÂ&Š‰§3ñ…Ê\0f0¦LLvl\'Àõº\rwMG1¹…•·kRrÖ’lí,­ôEi4I8=0@ãñ#=w´+¤$xdŒà‘õ†SjŠæ\'h}{†$±ÔN\rzÆèØNåƒG6¥Hw¦ƒ8\nåX\n!)G”îã¯É‹í_øŒ$4Å¨£ÇÄz„œM&µ69….ÎÔóS«ºAs¤é{wØ¸Šq_’\"˜N2!Ì`²¦ï°¢išöaãE:ÂÒÂlÀ–Ö%Ó)¢?Í}É{‹(­ï\\æËŒzßzó<ág9|q~]|R?ž8Bë›gLîÍ>oMrµîHy¸m§Þ¶D$S€Æ€?èw„©,a^TŸœ‡¡šX%ÓQeBAŽ×â,¥-&£G3ShIH2hab“À´ÓT\n>Æšî;áúÎl	Š¥}\Z¿gà*È¢p*‰y©ÝpC™°Ô–+¡u`XFXÎLˆn•º‚	E™Ü.Uq i…Ô÷5+‘ý®«fÉÉjÌÈÉ4žœ$Y^\"|gŽsÃ#Œ?Gã‰#´ºLýSÍþmö³jW ]msÂýÉõ°È,U@Í„¨Ýž\rÑÝü·D$Ïqñã£QZÑ4Th²\Z˜ÔÛš•«ªmx5\0—835LhfBS\"à¼Ë\"Ì]‹ÄçX]qzeû«7ÐŠ¥\'ô#>r%†E!j	÷^YçT½RÃÄ–>µ}Ïi©””®!qî,¿qøÆõÇÆL4ânŸdy	I#+m2úÉõÆGh~ågwy¨=et€¬¿Ú™OáaBN†žœ øüª¦ˆ/µXüÒäæò˜¤ÈÕ^c?ÉÛó}Îcæ1ŽóðáM}mÛbm}H\nÚNˆl\\ªšƒï˜”+uLxì‚c“ƒ§WJjµYOj¦=ôçä½n\nû¯¬<x±¦Q€o‹–Áiå»)Œ³¹ØÒ\\Y B¼‘e»§\nˆmTã¤	I~ºLtqžå“ÓfÕ+wCÓ\Zô\r©“@Zo´ˆ–—™\\¾ÀþÏŽ¸dLß8ËåïœÃUŠ4Iðöl%Ô»Ä«	~˜’›aÂ6æwÛê¿ê\ZuÖÙ‘¶+må“¨cãð•\"¨iŽÚÆ/d°´|^•®•MÚ¾ü@À¹ó#ïŒ#Cä=!Y¼Â|oØHîsªÎŠ@¹h6\"Öwga/‚åw–ï	°ÿùÒ€y~`€¥ßŸ\"¹ÔâÈG1ãËË¤×CSNµÔ`ðûçŒÃôJ)ôž€ö•(ßœeø…cLÝˆðŽ˜ØAUsq÷øÜU+”Ëõ½¯ÑŸ«XÍ\\yÆi›ç°Ú¶?ýy2ÐêUAõÁsÌžDŒ|P·IJÛŽb6I8Uƒ™û–?\\ÏžÞ\ZÔŒ>î£^ž‚÷æïÌ!…Ñ÷£b+ÀG±œp4uåVê¬mò®½°E4×H%ä¶¼O°üÔ3 1ãáÏ˜A:	³»}¤æ2¹¶áì.µ·Ô‚UÍEÜäÒeÚ?^$¾aØÝìØ!Â·çÐ{ê 0úÚYF^>Å¹ûïÅïõ±mð~nMAn\"¦1”Y8Ésª[§­d²iý”mQ¤¼Ò¢²uDzëÚÞ-(JËk±RDX\0$&\r½VY­™A¸èá€±ÖYÔ«ç`qù~Hò¡ÑƒD¯+Ía¥™V%}¬^÷	î¯B_†×‰i¾rŠøjˆ´Û4NNñ@\n³‹döàSkkF%¯„3«šÇÙÝFÕ©v˜ÆGh}kÆ\"Q\0¸Ps™ÿÒK/¿ÄÔÚZ±]©tW¼T¥Û£ª‘å÷æÜ \' JmJ.¶oÙÎWJNòz©Ó]@oÓQK•\"G!¡ ÖLè\nIuàÜ ¦þÊ8Ôš…È!Q[8u=¢-UíJ™RYT·•T<ªëâ\rj¢AM‚I>iˆ¡QÝj¤ñ¼³™‘ÁS,=9IðÅI†¿ùz±kÄß}°Œ$	Í§\'IzÔ”ÖÝþ·ßŸ$øì°q“äÜ æÒ²;x÷?9Ù,b ¬í¬ª–íž°ê~°x¤ÒóÂ”¼r¨MÂC¶Ë0\naþ·T®Ý–ÞŽáÑã4¿ê£kšsZ?Ñ`4œ‡NÀ;G‘oœ`îµˆý#N¯–/:®4ÇMÝqñú±3F/Î3³\Z1º¼ÄB\'fty‰ù{<ÞÊb‚7Î°ÿOg˜mG„\rŸÑ÷—E^™¦QqÀ®«¬‡â9~Ç\\|å’ÄÌÝs/Þ¾ýŒ½¿Tì&ñöÌx£ß~ñž(Uó¸0vˆ°9:þÞÇÖÖ#Y	‘ÕooÀlsˆáï¾ÎÄÍ¸o˜mïä\\ÀÔ]¦‡n{XÕ–¶1lËE’b].yÑ>ƒP¿pJªTU&,vÈ|xršpØçÈôw/ƒÓ€ï¦ý^ÌéWB·¥ËÈwNi;Š ¶9+k-/áç¶¥‡G‘$áø·Ï1ôÅ)êŸeé·˜r<ÿá‹F[{¤Éù¯^géûŒ\rO®ªŒ^Z†,eá©	–O¾ÄäÚ\ZþÁaÒÕ¥Ëÿø%‚ÇÆ‘vØeYVuŸù§&L \\…2Œ~ÝDJNE1ÍçŽ1þžÙç¦5þC£]âG/KV˜¼²šÙ,•²ªxþì¼Üª9öbmýàÀâª=Rùf«—A¢¿>Ê†]tæHÞ‰8õ­eÎe”NEà˜Ò(L®îMÑ\\)’ŸÌ”êÐÉœ}eš™WOÑ¼Ç¨ÍÁ§Fˆž›ßG>X„ëñòÒË†j°NòS\n£êõ\"<%úÞ9Z_;ÍðwÏ1qi	ÿà/N™›ú=C{èzóÃ#ëÏÕ/OuY±ƒ/NöeG…›ëmG(Ï/÷ÓAÅg*•ßlº¯mË’ágë·Çð¨7+;bøH )3pTj»®€83{ñ%3LôëòjšËÏ¨?Z*/nÏÐzü%N|2›uóõi¥i8ª°mgÛ!cºÎ|ÒF;Šý5MC¹œm‡4”¢%Æ×6¬4Ë’0Qxk5ÂU\n]S4TI™\náÔÛmòl›ÕìB–\"­WO¡mtcë«\'¿wâë!îÞ€æ³S„ç‰.ÎãÖýb÷««Íg§Ž_\r	¿dµMðÙá‚õ…fw{èAcøtm]µÛ‡º‡Ò&dXá*Åå—Oãbj²¸™)J$\"Æ­“$,À¿<~¥õ7zÜQ¤%†njç¼3¨N|Ý®ÆP„å?‹àú $Ïïgù©—˜¼1+H¤Qœ³Hl‰Âf@ðöŽ¼2ÍÂØ×O1qò‘#´ž=Â©å%\Z/£>¨9sõg~o]¯3þŒã‹fÃàFýwúknêž€%»¡ qr\Zÿ‘1ÈÊØåož%iµpsktãjÍ‘K—	ßž\'Z\\À­)&o˜\0·æ—ŽòÒÀ\0s¿{ˆÖ7ÖÇH-þÞ!cÐìÆ ¬³ÛD‚¼˜Y\'lo2¨lÇ×f¿S@R1eÉûvëîÀ¥tI€ÉÍ}Œ\\²*Èûs(i³ðNÌÜµ6‹Y÷ó§mñÝ±¹¨‡F™øô:ƒ¡=uã&xì­$aòÁ!¦\Z†êuf_>Á[oÎâuù`‘ãŒÑ¨Ä:õ…\r˜»\' ùÉ\"Ú:\\›ß<ÃÒ·ðîëA!IÂþ\'[þá,Z)B.¿qŽCoÎ<y„ñ$fîŽ¾3GôÎÁã¸5Eüa‹èâ|wL’Óó?\'ŽQƒÚ8o?ªdts¬Ôà¨ÂºlM‘\n«mGL¢ï[ÝÞàmí€r\\rZ2ê(»cW˜OZ\'8=<ÍÄµ„³J8Š×•Æ·”hkC£Ñß?F#ƒãõ€æ£‡i½¿DýÀ£ÐŒã^#M°tqÞ8“kšé\'&xýfLp°ŒRã¾¦;´P®béÑîÌ0“kkÈõˆ´­£¤ª¦‰Þ7l}ø‰#(­ñö¸Êå­\'Æ9;0@Òj™\'ç/þpŽÅN°ðÇi}{¦`[UdÕ„¶èŠ!ÓÜªWØþ9›À¶Y›€-LÅëßwaáÎ	jÕžô¢•7æ•æìµ6ÓJwíòUŠi§D¢;¹g\'úÊ3«!¡ÄD?]fö•iØã3ûÂQFŸžD9p¹2ôèaSÞëàûçìï}Ž(Ù|ÙäÔ¹‹u÷Ì¹.á·fŠcGn¥L\\ºÜ•XÀôˆ~j¶ž?Çè«§A)â•×qñö„oÏ1³ÓEÚ“·ÖHWÂ¾›T]°1õÝ}Ä¡!Qö¯·àgbä¼m([\nÛçêõ5i¢\0lR¥°ÁZR¤˜«ÆõÜIÜ\0±¤D*÷LŸ8£:pÈÑŒ:(oã½öwß¡ÿÜÀ%½áh¾·€ûÐªÿxŽ¹×.t	Û@YÄ°æáz\Z­=Ó¦¤FS“Ê/AV#†^›¡þhwPÚÌ.SÙÜí¡&GÂŸuýÝúÆYNNãæ%¥ñÄÍWOq~`\0}_c½-Ï—¾ÛGÕ}¤fD‚d%dø»çÌæÊ/š¸ðT¯¦‘Nb„íÕ„‡ÿíø•Ö§6\Z¾»Tÿ+!§}¶¹Ü)ä¬`3ÚÒpÇ•fØÁdËýE\"Qµ/¤W­íg—6ûÐ(é›géª…Û{_å÷V»Þ”öXªl€ÈáÐ;óx4¡’‡3¾®K´ÞøòûŸ8\\iÐeÉîÿ×ŸjšÄ›ö°V¶Tƒ^÷N‘¬\"ññÒÚT¡•¬ÁìyëwÅâ¬ßÍ¶?U)r3æ(Ž¡Ð™Iãëß!;»Swæ‰_›Afg‰ß˜!ýÞiãä|ó\\í»S¼ÃöAíñ9¿³û=êŸf|y‰Ñïši\'ÆÛpv—KøýîªWÃ_?ÓÅ½ûŒe{ìý%†ÏÏléÒÈs9)(¢0»r\r‰ö‹\"<‘zª1nS¼S#e¯œÔ´íSš	Gá)EPSøÛÔÎîœžßÊF;x 4¦Š¦û½us.ätÉY0‘{Î°ø¥gº®©?<ÊÔÚ\Z‡ß[ ]‰ðö,þÁg˜ê™bÂ»œ´È‡&;KðÄ‘u™FJß~¨J¹Þ9-(ÒÖ/}W¬M*Ti#¸cŠS²8€¶cŒP¨÷½µaÿJÀ<˜§¨mÛ‹µ¨LÊf·ª=—ÿt¹Þ^wNïkpè¬ÖÅ»/ üÞ³GY|î8r=dè‹S¤ëW«©ÉüJÆ“MÁÁ”µ —»ô°¹-àŽ©Ü~´Aú]	Š”£ŠÎ°FFÃÊò],eàXÄ©a(‘g~»öC:sl;É6—–¤Ñ|e\Z¯^g¶°øüñuí×crmÑï¾N`wËÈõðÍYf‡Gß<‡gSÔ¤I¹K¥ñü±nVe¡j<³Hå†ÝQ¢ueŒ-kÛiÞ{+KÒ–ˆÔ5yÕ¦>–ñ¨?¸yÑ9§”…¼\\ü«ydé-HìÌÍY™²=Ù~\'zÙ%}‚ÁG\"†¿9Cø½sÌ¸.Ë²~vý¡Q†¿ýºAª·çÐOORh5è#’¢\r$gAí	Ù`mO?óÜJ®õ3\ZsE´Hý¼i`Û]ë>lêt—à€›VVEžêw?ÊTÕÞÝ3„©²³ü;ÂvdÃÕ?\\$KûÄ…¯‡àé#,>7…·×gá«\'ð?;Jý!c¯´h/.¶B¢ë!­å%ÂvÄ»E	:)ê¾n“t’þšmŸc©emjÐƒ0Ï=i-Ú®kµÆ¹©èXå[å¿²ŠåsÃ)ÞºÍR{ómmØº¾Ù+å€ÿ¸Bû ±\"ü^²	Šp	Ìž+G¡,rósU3‡X£ì@>*ý(ªªû´^8Aã…¥iÁúßæŒ·ÛDºÿ@ƒðJËŒnÝgézXÆc÷Ëq„\'§M&‘^è6œS$} I{ÑXÓ¥Êî\"éÇ&«°5\"U30”Ù&UªÞ³Q—\\¸+ZÕêÁÛª	ªÒRè##Hh¬½Zß«9óÎÔŒf¦ŠÒ$²ï—\ne‘äM (ë^™°$+kÞvw\\ÑúÖY–¿qÖì˜­hGK‰‹·w˜¤­k-†ö¤™0ÿá’1½@_¤\0H~²HøÆCazÁö­´À+»YÒkÑÎÎ–ã“žÅ¤™lê\"ÙEª SšUâ«7	ŠïeI½¿·Ý›ŠQL\Z¼AïìYãZ™	®tt#,çÕÛ2ªËVì’Ð€§Œ|D÷»¥UVÖ1ÔH¶<,vÜ:ÝT(²brh‹µcâÏŒ ×BÞzs³÷#EÕ}Ôíˆù[(¢¶a9Õ1ºH`À²š~g†ÖóÇQƒõþH+ÈÎ©`©MGÐŸj’ælð?7sŠ´¹âð±ìÃ‚†­òØÆ¤|Û`\'O\0µGáíT\0ÔëpÍP	Xõ†›bd“½\Zu-XÁd.EÁ»Ù2¯|Y “Ûè•#B‘\r¿º\">Úú¥úÑÓ¨#ÄqÊ|»]V,ê¤€BýØ°Uø¿ü½>K«­N¹ñ¡wA*`öñ	š\ZF¸‘|¸lœ¯w.Q‘›sÄä”Ôü[åB+Ò¬°lŽHŽÍkÛÃ¾ÒžÎ¬Å;@\"Ûvýa…wÀúðö)ÄLþMÀ>íJb^,õ°o^ºí\"Iˆjj’÷Û°º¡HV4HK`ÂˆI½Zc¨¦JÁÚö\'§D’³³[ö…:ù‹Uâv0±S­NL$BëZ‹°âÒh 2­fd¬LÕm&´š2ÙisóFÑjL²\r]$)A«L­öôA¢~¬Uï?âQöwWtdî¤–ôc%‘\0›’•V™]ÙÈGý† ~Pá75Ô“’Ä¸O”\"yGàªÀ“6>\'¢6ø\Z²m+õPÓT`t\0Á=\Z	…øð\"\n%½/ÅäÏ½¡h%øJ¡v¹ëÃ„«$&þ*l›r¬aGXè˜¢‚9X\\4á½\0Ž¢áhF=´2NR¯æ!vnSDÒ¢ÆZ*	’¤ÅØ*eJ¸êšFoCöL6»&‰q÷í‡•°Æ[·øŒÂT-Ö¬<C•óÔØyü•óqÒÚl&dojÐ|ÞÞ¸Ç¶wMlñ.\rxÈ%#«=ö:IaUKV0¾” V(ß3pQà¾\\Ø#$—@û@ ñ]8«‚\Z®ãÕ@Å$D\nvëUå„\n%’LX¾—WcÂ–maÃ*»ö)\'P\ZOy¨šÂ«)pÜ2‚2/š,BÚ1œ“Žå®$ƒ$‰IíüxŽ†,¯ähŽ©Jáå~ãutfš	ÁóÇ	_=…ÛOsë‚œU\\:ýeß»§HÊé¶ŠlÐ‚$W\roÁ×d\nõé!äÍyCVÚjd%Aí’7BÒŽpõÓ|Áõ\"kø³rŒ¼\rê@]£îk#ïò~ì6¯”hÖ¡&ày¨0&Ò0óý6(ˆ0»´’^Iˆ*‰³<ÛoÂÃP“‘š‡Ö\Zå(c=V¥D˜Ø¼Š\")I’µ³Ä÷zÐÇ³åV£Õ‘”&–6Œ<2ÎÈp™Dkîä)¤c¨|¾ë5úLtTŠ+D\"_$r=ÄxÔD-l•”½Ôt‘\Z9úø¡¶Žê‹H¹ê™¯—™ò×\nžV@AÞ›7fãÈ²3ymEêÞ…:hö–Ë`Œ´Ø­ ô›È!ÜLE Brb­P®êÓuXl^¢aîía¬Œ¬bù»TÇP\"É†2TóÐZ™rR5ÏTývs¢h¨Fl‘$M–WÂ²2”¤\n.Š˜¯¦q÷ú„?½ÌØÉãŒìñ	šM&ìçÔÞBïöHnTé^¼8Ç‰GÆH;m´¸¸Ž2µÔ6uÙã$etî-ôÃ£Ìí4Áo›Îpõ~‹´®ï_Špk6÷U¾yr³Ì¬­ŸÉ°[ÐìkÚ§áÃ6J)’\\â_µç4¨A\r>øû¸A¢\'GU T]!«!`\n÷©è€ºOáyÂåÚIÊÂŸµXZÂU!ùaÙ)²c|xŠ@yø6¸ËÓØ¬$‰\räŠW#$âNbå\nÄI\\”E³dò\np•˜„ÉWNáÙ”5gŽLÐxtŒ$IÅT²T5vuY•í‡¾8É…¯6®š*ÙÍ6AÚm´-´qnó>PAUÊDå9³£fÓ0’-X›¥HÌÝ–œt%Am¨J’÷1¤@=Ú@>ˆA‰1> D“PP{Ñª®³ÏGFJ„Ðbjþì.A×Q9\Z=èá+Rà*\"\ZK’W\nè$´V£\"‚Álƒ*—ANUÃæÜA¯|‚á&þ¾ý\\ø“iü=“oÌU´£k!3ÏE€ÆC£$aHÜ6ŒGn&(¥h]\\`â§IV£¢’¦ö}äfl4&†Ÿš º¾³`d%Ç-¶m’™ÜÚ\0íïÏÁV¹*»¨Q‰xªî–ìPIž)½{_›RjäÔ&_VËp6Êë#´¾­h<gYYjŒ~²¢`Ÿýt‰Å¹D’Ò’·®%]%* l­—ºÒ4µgd•š2å&·(“™kBqGh­†P‘}ªH\"]2…_@à4\ZÎ½p‚©o¾Îþƒ#ÄQT‰¿2÷ú{–¯·Lm\\›ÍÃß·Ÿ¢ài1é–åïRÈÍ”¹WO3þò‹åBÐšãG˜zùÁgFÕ¹|zˆÖç¡–«ãyk[,àN\\ìP‰ß›ßÂY«º=vÏ€j4Ì(åFÉÝÆ²|Ö6ô@cH®µ»ŽÄ=KImužœLÇ™ÑÚ®G$/CìÀ¼E\0~X†qo)ö+¶j²®éÂ¦’[˜MVÝ”Ä\n€q’ZÄ©®ªÔRƒ€ÚÈ*hË’&^>…w_€r~0e++MýéLù>°Öû‹øûöw•ÿÌ¡qp„Öõí•’¢•2e¸ìv¤ä¦­¾¤5³\'§	Û!íåîÁ‘A´£/µ>cÒ÷‰Á¾†A~Ë^L1ç\r&ÈQ6Œ|»ÜP ›Ô!) ÚfÈÅ¢´loZÔf#DÚ &¸ÒþO:)#¹Ši_.Ÿ°$KieF\nE˜«¹\0\\³}d=…QR\ZhŸ@kÃ†,ä¦ÛY[9º¿ [\n¸uF;„ a4¥sß:gGŠråñMƒ	˜ç9XÕBVã.ùD2›‡Û¯a¼ìÑ•þ}\rÃ¦:	Á¾&‹,÷‰u),ýpŽ¥Î¡QÄ«	A>†™àÕ|¤õ°+ƒeFuQ$…¦èM­“R¯döU5}g^…jñBß7FS›ÆËÎæ[b€:êäè ÿ¼;XÿµB…÷=ôG WB.´#kÙ8¢80äÔ-¿ÍË\\¦à¸x6þ7µÈÐNŒÜÒ^h·£n_ž©žr~=\0¥¯-ãQÆs§\nN]\\Bâ¸k%z{FŸ:ÌñaC¢Öå\"\0L2…§ëHÒ&YMÊ	²÷Â÷[$ív!7èAÍ‰ßý\\Ñ¶fîåSLÍ^(\nÄŒ~a‚Ö”•‹Ô.sî¹ãÅž½$Ë2\"4%|gÁÚŸLžïTlá×¬\\€¥_l½{#”oµmdÒ¼Ÿ?LôýYkT,¯í™™ëâº}\rT¯—Ou[¬MþN²\ZÿZ²jÐÄß× ¾!Ú#x¨‰w# •˜v’”;\Z2#+ë°‹vJûGl\rpæåã.Òœb}ev°4\nW)ê÷„´8ô‡SÔïoàÕ}“vîPae~às¬9T°¯öÉõ»&”Éˆ‘GÇYøá,íK-¼|s£$øÍ!Â‹sÄí?L3cŒÛ!ñjŒoó0Š¾ºRÅÄ’B3@0<Bp_ÃThLø(¥HroáòO¯½hª\0£OOrü®‹@Ñ\0\0 \0IDAT{3)‘eJ8¶žˆ˜VõkæeÛOôg†Í~µMî*ÅêÚÚ­”Ùu3.íG[j;l£WóÎi ]iÙ\"‰	;I!¼¦Ö*’Ú,ø¦<©tbI‰“Øø‰’˜Xâ,1eL©”+p~½AãSÃŒqŠ‰“Óyõ“ß9‡ Ôƒ€ 9d0ŠŒjû@&DWC}ùXA¹´ß=XjÐ/G (×Wå”Mº.7“Ò/›‰õšr³;Sœ®wO–’•vù¬L4‘,E‘ÒDƒ`ì1…»)‰}Äì¾5òœ.¯4/¬§%ëØVUè‡s¤¹p{ò(­+±Zù.wëÿ{çÇyæ÷½ä†º¼s ïf\n	ÕÜÉW/k¡&q¢E…Ö4|€)Ø­%8€E¸@Â$E,%ÀÙŒË±)àÐm‘H> \'ùPÄ¾\01(1$6ÄqCµÐ<T.iT*W¨t7BEtö*æf\ZíeÞØsfÿxßwæåò‡7ÿÔ@ìrwv~>ïóãûüÊà?Ö>í¦:ÿH¯Ç,uâµÙZJÖuF)I‘‘t;$]­Ís­\'\'8üÇ™xá$g®¬‘ ˜Y\\`âÅ“ýÚ4£ÞáK•$ø\rÉò›ó¨;ª†UÑÈcG±ßu•RLŽµXxµ*Ý	öGøB’´Wj¶@¸¯‰â«+ŽÑ¬ˆF´×_uæåŠp¤>’ÊC2ÿÊlÉl9·Ò‘éjŸ£â¿X ØS\r¶ûÂ$§—œÅfY÷dkÄyŸ÷±tÓ7.TyUôa>»ßè]Œ‘\0\ZBOG”Ê·4»lÎö_jÑªÃ‚N\'¦s3&)Y–’¨¼Â\\Œ<y””Œ£ÿz†“‹KÌÌ/0³8ÏñïÏ’¡h=~„æÁáîôvRv‘íÄ1n\'ù²6®Áï5Iâ¸.F…`þ•Y9ØÕŸ#mDÊ1åP€$×+¦ñeHpo“ÎÕ¸ÆHÑþa¼AIÒn×>—¦Ê5¹×%Û^ÝFØþ¬\\œ«N)ÂÝ!Y×8}‚‡àå¯Mqöë35IÖ¹3si$5†R=÷UÏ«µ›:=‡Šÿä×În›Nb/wµ„)„ËØÛ$RurÕ(­ªÊK¥˜X!ÍC&¡Ê45Wk	™[	ÚN°7Kz¿=-éd\"‡B­&º\n•ezúµ½(!Xxó<K¯ŸÓóUÑ’Ç—Æ~q÷gÚÚ(gØ ø¡O®²šB ýÚ¶€F¥A7WpÏ3K)è9ÁÔdy¹/¦ºý°@°tqy·_EýÑjüØs3uDÚ‰q)*GÄÚRö¼S—ÙnÆ´¿>½3&2ÇØ0(¹ÄhDýu*)AÑÁdo\r­\0µšRUÕú’›1vÑ$ï´K·\Z¥¡YÑím,c\\]ÓT4»Õ©VTCpæ3Lµ8ý¹	â«m’N¬¥„½1[‰¯´QwŒkÝU„÷éã¤k®-£×Qr#FîÑ^žö¾¤¾\"Ï	HI42BÒ‰N„<lj–¬Õ§TûAÈÉùf.Ísüü,)Áü+çj#ºìuå·ûû·ž1¦Ol!¥¬1¡„Ì¼5_Wsýº®	\rÌúƒº¿@âl²ðÈÑ\rÛoEJ)“œåœ£Å‘º™ƒ¯îÀØpÕ\n¸ÞSWª±vwÉOHâ+Ëu;ÅHµÄ-ø+ :8ªm·—*_(FÓø‡khÖì¥ï!¹Ö&¹f¬AÓØ8‹Õ„ÉlMÇºŠ©‘af=Ìé9É‚-w~*½#Ëh=9ÁôÈœ†éµFZ=.¯•ºBhµê!PE¶QúØÆ­[PˆdjüAò,­9Y’püÅ—JéãŒûßÐ^®Í¥xdÃg×Ú°iƒ­òJÊwy?¬$‘nÔïAƒ\"Upê©	›Ÿ†¢õÄÁ¾ÕIIœ¦êvJ8//•x(TÙ\'‰Û5QéÑ†{Þ¾´P=p º_‡ ²[I‰¥„û›€`ñÕÙ€\rmËÌ\\ZÀ”%²mÐlµn÷h×ZÕ¨ƒ~uT”Rj•èû•ôGÐ¾¸±ÀÖý¸•‘hpê©Ïóü#ãµÎúáþášÇ9}”†¸êæ¨\"\'-TY	\"v ÒÜ\'Ü§o\Z4D	·èÔàUl=f«Rm\rþËVÀz‰X£oÞÂ«³èÀ^V†\0³\Z=m{8bÛ3Ñv•©šM\"ï–:©Ë=–ãªt¼\n ]i¦_R•!üzË?•$ûæI’š\'¤áŒt1±ûr%­‚å×ç˜ýú4gž˜,ÝrA|uyCŒ Ý$Ðj%M¸¯Iëá#DCI–Õ§†![|®–\n¬j ìbþ Yø}\Zr”™£e‘„G?Â¥’‘:…úaêÜº\n ëOi_[ÖçvM×GÍ&ª“8.tt`”0H;ImÕ„÷5‘{CR²ÒîH×’º}²;¢õÐM34!˜ÿö\nÉ©G&@ˆÚ9xÒgæì¹ÒÞðÚcìQWéZZSMª›šAÊ¥*hÀÒ[stÞn“Ýˆë@ãÅy„«ã±ÁX/ïÃý#LÏ_`ò›\'ûìD	+$o;ÇR9¾UÌÍf* êl»šj©Ì¿P[{6vv+Õ¦º„nŠBmksK¶ofðck\"ÚÕËP®¡Üzü˜f¤v\\³-¢C-Rq{©òL%r(,ÞÒ†Ëã_9Îô÷ÏqfyÅtÞW¥‡z…ŒéÎŠ6¶Û7ÛeÊ¬ZK™~ôpy³ío0}þr¯¶âwÚ5hA…œyêóºÅ_yYµýu÷á*ü ;=d¤>ø¥è¿ã«mm\n›3Ø™NÝÁîk–R*ïªra•=°@üú9óýÎ£lªÐ*6~¡ÊÙ»U‡Þ0B\"…k›C_uòCŸÈô|Îz¤Œ‚È:UÙ°\0üÈ<ˆ<¯©Ÿö°R7jÝ{ÚE]ÍŒüÞÁš=\"yùéãÎ\n\r`?û9™ûÔTNnÔmÝÃò-ÐU„²of¤@ÜhWæWž`½aK ÈjªÛBÂÄ+lÉóµ­–’i`q‹œ$f6{ì5ù\0PxaÃÜI³U]UÕ¸mA5FÊPÿÁâ‚Ê`ì§æÔmÅì³Ó:¤ÒíÔts¸¯ÉK——8òÕgª…Gt@ç(»“h OT)Èó\n¸ì‰Ÿ©®ªÔW¡˜üÓ3LüáLýÁ®)¦ŽÒ^tŒõµoˆ¿;\"¹Ù®´R\n|\\©ƒ’ÍC:­#¾¼\\1lTÆNZ^)Õ¦RŠ0Ú\\zÅ—«Þáá^½ˆô9TÛE&´3ñÜ#ŒÑº_ãvý(=7!åŽÂ\"–Q‚û6J¤Üz\rª\näml¯\Z#)](dß—©–\\fZy{ž‰ç¦Á\"Ìµ“Tdq\\Ï‹Q924PÇh,j_m—F¹\\\n)9ù¹	¦=L`Pv+!:0R†drccœûãS´/9êª«h=qLÏ²]n×>G†õù8ªY†!¹ÑVB66¤í6Ê„D¢û››\Z¨É­\neR2ùÂc_9^¹&P*Ì½p\Zo“ö;‹È¡`SŸ:F¿r–ðV90g+RiÓƒ!º_’•lÖNÚ†={ÛÚlºqï-ñF›KÛ&Í@\n(ÔöDÒ£2†$/e’Ù§Ow²6%H)E8hP®MV†7(‰ö59úågý\'c,|g¶æê{ô±UæÞde U;Oúø¿Ú*Ï\'Ëêx’ìcÄ–ÛÞ¬$¸ê*Â½MšŸ®fÓŠFëK²Q3B¹å”ÇEvi92º¥\Z¬\'ö\'å¨²Òæ*¶T¿ÃF[.ö¢]Ž\"Mü!#!Ü)ˆB°ôæsß},¢T	¼%7Ã»|’ÕN	Jæ(âÅÊPG)„™ŠXV_\n!µ1õÆ9žycŽ‰oždä‘qš‡Æˆ»\Zbí»14×k¼×¤–:F¸Üšà­‹É»}2(=LWÍ$¸ÞÓqÈ/Ã-.ùH’NŒ4¨¿MŒ³v“*@î	Yº¨GüL|õ¸ð½³Œ=<Nb×Àè¿yŽè«„Ü×Ç€v~§ÐÌâ÷ÄØÊín\'”4#\'t*îÎp$‡~ªí$W½ÕUB_Z@îÖŒ’ÞŒI°øú–~0W»lu\'ÕªíJ›ÌÜ8ºû¼³Ar«Þ3ºy`ÔDÕë¶“0ça›E¨®Žàë:šQ]«íšºŠöë”[Ü 0Ú›cˆ›í³$áä÷Ïé\0õ¥Æ>;Yg¸ž—C¢ý\'`ûè|m„ÐjTJäž1(I;	\'¶J0õÂ·NÑþóyæ^?«ï•³ÛK,(Ù€è©ã}‹³}ÞM‘ú7ŸWe¹±ŸnS€°‘2øOú€6H[‘@Ça|sc‡\Z#[ÕØOr½•RD†\rÆä<xó°’›q-âÆâ,%WÛÚp4¤‘ìº®²”pwD|µØe¤©Å²¶Xyî»´dIUVá„±É’â®r¢Íéj¼-Vk	Y’6ë¨||e;ÿÕ¢ûG75Ž}$3fêP‹™ß?Ì‰ƒ£L?ÈìÓS„N¨ÍÉM,.Õ@÷øºWÒZFôN_É~T€\'CÂM¦äk©ÉQ:ù_K¤-Sm70Rÿ½<I0†líÔ5ÒÙ\\øãS¤k‰Î+îq_å›*­\'ŽùÆ&q?×‰caÏQT=È*t†ôZER¢îdµcca™íÖŠNåãqÊ>Å Ù6« \nU(<“§žu³¾v™@Êž¾PY†ô}’Õ˜ù×Î¿³´ñ‡ù{HÃ0›åˆZÖà ÝJß{á‘]6“6É>°$£°¶P«‹0ÒÇš¦õ_¾Më¿>Iý¨¶_ôCMtJ•ÒöDCÜÖ~Š¯,×öã[ íF=¬\Z:~ÇI(+áÁ>®u^±p¸¯It“8n×6	£ˆøZÛsVŠñ\'&‰îsT‹Ê1M5ë!Ã¬ÉõaW©\\L®Äˆ»Cy9¨£õéZÊÒ[ó,¾v¾Ê{B’ÜŒ™:Ôâå/ž`îk\'i¿9¿)c”‡7±ÀÍ¶s%š,´Ù£¥B/!%Ò¤ÐÄ¯ß¸“3YŠð¡ñÛª“ g.nõúÁjÿ¼mm£>ß™TÂÓ+×Z÷«&*nVBt`_êàmëñ#%\Z¸Á[[©\0„AÄBÍ¬£´Â÷ñÃHHm}:0òð8óožgéõŒ>~´ÄŽ>6^æLå†DYw¿¡Ç(„\" ¹²‚z/\'í$tâ˜tM«ìåWÏ±ðêlMÉ÷æb[ÚŠ!¶£²™ÄP¨÷öFdÁP asWDÃLÈV˜–8º-Ž:D\\^Ò¹ç‡Z¨ë½¹ì9’|-EöÁ\0²åeÔjvÈMLóöÜDbÓævíf¦fJ£¨`|Œía°”¼uªD<#NÕZýsq·Vy]á‘dÚJR¹B¾Ò\n¯Ä¨BÓ„sáçûò‰C)í5ô*^~}®T#y‘#„®ð—— 1³_™¦s­MZè}ûTH¶[¹òÿ‚<!ˆ¶Hã10|°ÅÊ¥…r1Y¸|bƒ¦ŒÝ0…öÜ\"¥nqo³d$W0l‡y§×Úú¾wMÆß•úÅK¶û‘ân‡hw³òŠ\n\'v	²Ž¢ýMÚo-ÔÊŽ-:œv’Úçáî™ý\0áyLj‘\\mÝ?b’ÿs¢Qß­\'U–Ñzhœ…·æxù©ãÿÎ-}rž Ón3ÿÚ,K?8oT1œq:í»Ò¥c°¿ÇØÝŽÜ*IB¦¿;L¾·÷P¡¶ÙR\rï‰ˆÛZ\Z¥f‘¹6Y­¿S¡‰Y–	¯•$¹¢i™……x°Ç”&©´èM+wi#A°—Îæ¿h¦ÉÐRÉMÍb£2”Bîòˆ>=ÂÂ[sU‰TÁGÂójq§Ké*¢{GH®·i>4¦Wå.pŸ¶»Úç‘{²N¦Ud®hîm’]Ó6J¹?L¹¢d\"øÅ¤‹­Üµd™\'Cqúü9†÷ì‹`e}ç¿x‚•KÄ×ÚÛ2cŽŽàûA@z3\'Y‹I^i#†¢¡¥bëá#Ä—´ò/ï˜N8ÓÔ€å&Ž vús•×@Y@W»|fã@ò:¯´uê­5Ö­—¼ñ¾‘F¥ÿ™xFªH^i‡´t‘Ö+{„ç¸ä†\\WºVåZž‘Žíø÷è†ã¾”dI¢åº:lîßÔ—J•5÷V²ÔÕÑ³Wl×{}1Š\0íTDADÒIÊïGhÑzdœãOOáII°/âÔÓS(`ñ\ZLôÃøZ»ï±z)Ü±ò–.&ˆîk¢d«	ã_:RÚw\"ðuS‡š²2TèâUi*nÅ`OÌÍxvùÍí#Ð‹ØFþ)LE©msÀ70R3K§û\ri²dKˆÓ\"ß0þ3]M¦ï³ÊRÂ}‘	‰8©¬wûÎmð@hw3¾Ö&¹¾Br%&ëtt.vs¯ž-EÿB–ÑéÍŒÛ­< û]bRù-£÷FL~}š¹Wg™{ó<Óß>Í±/§}u™ÉZÌ^ü1­æoäýäÜæ¾ó2KWV8¼˜•õuÔšeÓi11~Øô¤ÛZú¥dŒ=~Œxq™pÿ(ÙZ†…¨6È}ÆÐôHãØ\\s9­¨\n³X†ixzº6\Z-ï×}Mm7 ›\"(¦Ì…Ú:D²‘²NgWYê³		tÊÒø3µ½¸ »z˜‹òCÍTíÅ%ÒÕj-!‰ãRÝLµœ}Ö™Â+çó‚lv¤Dî´kþâi^?ÏÂò+·×‰oÄd·bŽ?z˜©oŸdâ÷$\ZŠ8}ö£´ö8ý½Yîäœý–ž‡›¹GÂŒïTJÑÜ‘­e|xœs¯¼ÌÒÅyf¾y’ävÂ¹oé{\rvŒŒBq\nÈ¤òB‡Mººë¿\'©\0‘)¢Ý‘Nö/*ûT€îàì?»¼´!û1¢ÏÔÇ¡Ö(SUEIc³ÇÙù¸ö`Hî=¼–ÅyC°ìØ>.)L^·”´\Z¾i¦©AKO€òIWíz×yBn\"û/J½mù™iu3þ…IfÍÃÎPZBtÃ»<.\\Zàð¡IÂÊ¥%Æ\' N½qgŽeòßÎpâÙ)Æ>n­0q¨Åì¥N}eŠöâ2/]þ1ñÍ˜©C‡ñÉÊÛË¥§iUl¥Z+[Ð½wî«{m¶%³™Z‡@”-“cÑ¾ˆ ÉÒ”Ä\0­ªGÚ¤*\'1Òqd´ÊQj Sp²Œñži”.u^?ÏÊ×gt>”Ð¶®uròfüoÎ¯užÛì·5‰6Ä?Ô£Â›aJ@%6Ó›Z)“W-6Àü”ê]ÒªímÖB‡Ÿœ`ìñq><Îì·ž§L>9ÉóÇ&8÷êY\0æ4ÏR’\"I\"1>ÐšZ,ŠÉ¯>wÏ>C´ËãÄ¡5==Å™?9E€`âžQ–o,#Ä«Êi›£¦ßRÚs¾Û¹Û–i”£v%†øäàãGñ£€ñÇŽ\"¤äü«gyùÅÓ¤‰o´´M#Ñ=UÆAzµØ[Ï@ØZ9AÚÎ*Ð»SE´Õ©)¼Ï’ÅÕlÛÇ¯„1qL§‘_³d‹0§^8ÍôÓ\'ûôA0õÂ)’›1óß¿ÀÜ+gu«>Ç¿9C|e	o`€ÐsXã«1Ù˜ñ=!­‡Æ99w`€8M‘ƒ’ÏjÑB0<0@($§¾1Í0’öŸ/Ñ\Z\0a’ö¶‘>\0‚ØaÛ£šåT‘èó>Ù€ÑAßÌ_A?nÂãÈòRß\\¡#OãÈ“Ç¶¼‡‹ÝÀDÙÍ˜èK›s’‹óeó²Zò¿þËX[©Ú‚!yßÑµì¿É†ï‹8óN\\^x//&èÀhk0D(ÈTºs¼d´BF²¾ÎÙobü³“Ì¿vŽôVÌÑg§˜<ØÂ’¥wI€d}éÏ}ž™?{I3ƒíRòâKDû‡™<Ô*ãTy¡½¼^uë§Ýˆ:lìÅÔK½Ÿ ”4!£aHdÔwL¡©üHíjZK*Óý†¿tœƒ/œÜèÆ÷¡ìZ›ùæ0boT÷Ž öDŒÍ]Ø9œ»gØtâ5^š2±L¥8¹\Zÿáù,û÷›ý¶ÜmØÿðMñUi½LT»ØF•†»ÿ ”­v8öÕgX|sŽæQf0”:žuüÏf™‚Ùïè,g¾û2Ñî¨T¦>’©§>¯ªµ§\nUJ—qÜB Þ9Š½¶Ó€™-×DÒc$÷„zÊ6h§«{\r}{$¤>+z†ty‰Ñ¯M#Œn:\r){{™ùGÆ‘ûš}>2¾3øÙæØ7ôóÝ)•›Žù/†ÍˆÑO\"}	oŸÚöÇyA”3û0(äî€p`\08·¸Àü›çyþ‹\'P\nžÿÜ¤•\0ÃŒ\"9ûp$õ<­úÙ,ccµŒè«Šô¶Ú Ž¤äÈPXw¯Ñ/vù•4øî‹¿7Bu:,<u¥rr\'£¡:/4)LuŽ‘(åb¹ÓüòÖj\r¥êRÏvþße°ÂÆÖI%#eWÛ¿>úØ8Â¨;ª×dW³DÛH(j\r§>ò‘üöÀ\0ÃFšLlá!¹ðYïSÚW²jhÅí¿ÔC–QüM$‹Àô«,ÕŠú]S\n”ÖG£.‹m—µ’>ÄÅ¥ñ=Ä`ÿ^#AzÀÃèñ-\\~CKø¡©qµv™¶Èï¡C`··9=M²¡;­Š!•l‘eÈ>Da.àÃUn‘#]”q¯íQ¶“.°¹\Z²N¹çn³û®Î æÕæ@9aŠúk‰äª‹Âì¹¡œÿ? ÕÔc•ÇPDOl±”ßŒ+w}Ãy(ÒBÝÚö4)\'‚Î•eÈ:å‰¸7ßïñR˜èsµ]½û\']¡Ž­¸LÒË*ön-í\\Ì{=\nBá7l\"›–\Zª4nû“{Þnšq?Élƒ¥ÞP¨›0Ø}¡‘òª¾¢ZnÓªf9ØS–TN¢´{5&x¤îQIJÑ¹¼¬çÖ%¹Ž—¾‡3~L°ÜU?Üj\r€	éÿ°õÀ4ó¯Ï±d ~û¸Z%IPµ‡!L²X™\"b>¯÷¶Þè	¹\n¡WºTª¨N‘Q#´T(²B6Á $SŠÈxJ\0eÇ3Ýlœ¤«}sÜiOú+§@)¥“÷\ZèIE&öfº¥}¯Ø²Ÿ†Æq¼]:GK7cÍMeŠ§%ŽÙ°¹D€01,åz6VÍZif=>Û]ÖR9ÞÁþÆÄ­”+êF›‘_b;ê¼½LÞIðºªª3”Fµ‰œ“7ã§¶ÛG`tß™{uNwµÀ&ûëó¶c–k­¾y¾‚´‘šÞJjƒ4©K5QS\'öÕk	…Àûx˜ìn[TßatžÆ¶~®“\ZûI9U¹}\ró;÷:|S?æ7Œ$²¿+ U:©>±Ÿ“?%%â±£øí%Z]Ê\n‚µ%ÂœK9ïiþ^¶|.Tep=2°T£ÕïjßY¦3RW@ÓäÁïÍmƒ9¤——ôÔM)wr®r–¶’ß}ùïo»skîŠo&+…Òî¼„R\"×t¬\'7A€ÄaÑø\ríOÑc5S‡Ñ*&©\0:×+ò…NÅ\\°©O-§¡\ncÄŠ†(ó±u&¦(<˜¹=ŠÐ´[È†î5”8¿I-iE¡½Å²S¬Ù_ÔÐÌ–Ôá´›áwS8r”soÍ3v;!,L~U£’eÎ•p›J²8†¹ÂH=+‘`ÛJlü®!´T+(¥—”¨kí1€ºk³«XPÙûí†¸«yìè»SÏNý£í\0xæ‰#ßˆ..L×š4`nM!ÌêHÑÝÜÚ‡\"<’µ¤d0ßamSeQÞˆ:•%áö¡Û/zâ|Ê~Ö°ÊÍ/HÐÇ‹,Jk¥¤~æúfêªEa%Zí»ûš~n†…«KwÉRF³LÛhïåå‚¨•cZ+6(­d8ËŒJék„ê}T†\nPk= GA`<Z„Œ]úñæ7ÊP–eïŸ<6QdB¤Aø±Ö‘ŸN?;õ/²µì?£ë-»Xj¨’µ¬\ZÙ€^‰²ÐÆõ(’¶Q[Ô€e\\ä¨Êî±‹\\²*®œKu,0<•JsUHiCô\ZÍ®2°³hí¾TQ§ßyõû¼Àj“ùì÷ÒýýÕ6çŽ%¼·Éä+³Ä·bæ;	IW¡nÅDYJX@p½­¥^O÷;÷úÊ*c+Ùª×ZcR›ÚÑ­ŒU`\ntÆ®¯Ôv½®ÔúÏ³Œåå¥÷hßŒ¡á\rD÷Dw~vòãBÂ0\\=0ê¿avü.;e$÷×FÐ\"^•væÆyBj#²›2fÔL¢ê!.Ãöƒ$K—ü dååÿª\nÖ­Áé5Bú,ÝŒ/{\r=7Mùxƒ’øfüWi–ý6bÍ~»êŽ=cÑp&	ñIÑà.£*>í‹ö«5!ÞÈ;2Í}Ñ=¾”ŸÊ•\"[¹wd„B\r¨nFÖIIlv&uÆtIõ¼÷{	gŠ7Ã0DJI³«h\n’,#.r>Q7EtÑíì}ºé€¥d£ôúº «t9•™NrÎê*„¨ŽªŸRˆN‚°æ;õl-eiyy}yyi=Uj ë¦2ï\Z94F(ýr¬–RŠéç¦ß\0~×\\Þ»h–Ý²ÉÒV•Oð½’³3X•ƒò6…:×Qêùàÿ\Z\0>ŽRƒÀÏþWžçxN]¤wR²µL7¶ÏLe%º.”Ò‰ö*_º;Ë\0…Z÷r È\\u_»¼õî¯÷ˆ\0\0§IDATÜTx¨†XWƒb@	O3w–ø{#¤–4„C¡Îu2^mÇ ä¹Êñ„G0ðàï?øÏŸ¡…ïÿ4¯ï±©´e‰ÉG´-\r˜¿¿ü&š™~WJùÏÎ|ûÌ¿ª‡gcXBàýš1jêöÊ~®êr0%U˜:;ëí¹Å N¿G+­…õ}R…*¡Žd-!IæßšÿëÅ¿X¼ü%ð7Àÿ\0~‚îL“²Cõö#ýrdÉ~­íþ!ð[cŒ}9‚ßÞ?ü© ð„çÄà¨íYœÊUo½Öf¢G­7*¦ªEû­måþ¦PäÝœøVLûZûçí+íN¼\ZßV]õ°ŠVaÿø+4}$‘~…déhuð€=héô1àSh&”Rþf„CbPx¾ï2Úýº”ò.!Ä]þÝþÇ…%cy6¾aÔCK	„¤*Enæï*¥Š<Ï×ãÕøN§ÓùYš¦?oÄ?É²,î ™åÿ ä}tãOÑæÞ\Zð×hõöóÙû|ÄH¿\Z@3Œ‡f(ó¯_?Ž¶›<´|øºLþ.ó›à“ènîŸg^ï~¬S=ÐwÍëÏÍ_6íÿÖPþ;*Fx×üo‘ÍL‹fœwÍû¿5¿ý¹Ù~G^ÛGŒôáÐ\0s|Í0Ÿ bžO8ßURå!ÚßÚT\rËdýžÏ:s¬S=ì÷Í{÷Ïz]ï™¿¿C3Ì{hF±ß½kÞÎþ\\ÆÝÑ\røˆ>º‹Š¡\ZTÓïý€yÿ1óê2â@ÏÔÁõž?—‘Þwþ·Ìd?³ªÌ†ÝïÞwþÜãì˜>b¤ŸÜ‡ßËsÞ»Œ‡óÚû—Ö{ÞoÆ\\P1†ýþý>ÛºÿïÅîG1Ò¯†zïóf÷½ßçîgýôfÿƒ~þKÑÿ5ƒâÕ%\\Iß\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,1,'1234567890124/1,1234567890125/1,1234567890123/1',0,1,0,0),(1234567890127,'Raw',18,100,12,0,'0000-00-00',1,0,0,NULL,1,1,1,0,'','',1,1,0,'',0,1,0,0),(1234567890128,'Unlimited',150,1,100,0,'0000-00-00',1,0,0,NULL,1,1,1,0,'','',1,0,0,'',0,1,1,0),(1234567890129,'Pretzel',20,100,10,0,'0000-00-00',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0R\0\0\0A\0\0\0Bnó®\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0Ä\0\0Ä•+\0\0fIDATxœíœy”\\U½ï?ûœS§æîê®žÓI	$ DÂÆ‡‚hÊuÀ{½WÄ	\rzŸ¢x/£Š÷ª }N<ô¢ \"„QÂBÂ&dìN:Ýžªº««kžO³ß§Šj0 uÝåo­½NUwÕ>{Ï÷7ìßþí‚¿ËßåïòßPÄÑºÑÄÓ÷w(©£¡Á8™Ñ=„F&1È¦“Oº¸ä?qAð¼+®É­ñn9â@–Æz¬þ?ËÃ[·aOd<2Aƒ×AäÙ{ˆûg£&QtIÊÒñv>÷ôKÿéÖÿxäHëpË²ôÜ²ïåíHÏ4dç©•]48!²y-Ç.¿’?}âtÊ¦‚·YÁT$è‚I­•dÝñ/ÝþäÓËŽäØ·1 ó«oùL‘|V\n,ÁÝÔÌ¶U÷Ñ>wã[žgrûËè\rÄGÇÐL‰aeYgV`·9›Çvõª€¬´¿iQŽD§Å\'?+ÍÐz4=O¹ãLúÿ9\Z9Ê}ÏÒõÓ›‘¦Ið½ÿ“d$CÙ#%)Æ$¥’ Í¥’‹Yf˜«–,0+c<\"ã<œrØYºw†Ô.}ŠÉß•ì1_`×½ßcìµ-$Ç\\t	[W¯b`\\Áç“¤³-ê\n‚¶é\n¹ž2güñAÖ\\ûqÂYIF…pÞÅ³90ëï½æÎ6>»ñf3¡\\ˆcfc¬¼¾‘¢V\'j±Ÿ/>wøç}X;,‡Öì6ÔYó#÷|•‘ñIB[^¥P”ìÛW\"0w&;öa˜àr@&/pÖ›(B¡Cxð9`uŸdq‡ ƒJLªO©ëœþôÊ]ƒÊü¹š‹Û?Æ².œ±.1ô:Á3¾Ä@w?n§IÿºÕ˜–‰hnÅØ÷øçÐìç•nálÿÓ\r/Œ\\|¸æ~Ø€,>ù+?vw¶g7ž~Ÿ?žçáÒçsÜ÷^õ¸ÓX¿f#Š	É‚­§—Dñ@AJæ5C9-hv*O{FãœeöôZ¸ÚEµ1C\0*63«c—û~ð™ÏOâôxÙþÌ³$D;ãá¦wxÉÅ³Ô]ø¯¸vÿÓ{Í3§Xü16¯º“Ðàfú£*woŸí‘#w;¼c$v>Ë#g¹‰N”¸ç4ÁÎˆ kíFË‚ÙÓ%ÍíoPJfÎT)ÕC°]âÒÌÔçžµ‹÷\\s9Á:h÷»ùp«Kbƒ\'\0ñÉsMßù>ifÒ°ø2º»vI(lÛAmñ1’Ê2œ\0C&è\ru²£k#Û»ŸÔžuøÌA\nû²=*tz{ÇôËÓ½?¼Oze&r&[o?ãÃG\0¶JÆ‚¦f‰K¯äé^%û|¿J@[]­\'¾æ?m`uŽùg/!3:‰ésà*÷01&yv38çL#^²~»ª7üòáËäÄÈ>ŒÅßEu¹Xû«ï±ç¥µ8Z%Á¥W°å¡?àR¡^·ˆ\'Tš\nKþÇ\"\"ãêê¼LŒÇ‰N†8ù‹·rï¾EZiúçÇv‡~s( ­ÜFYzèjöîNØ‡gþR†žÛÈºìdf³-\ne¸ñ9*Àå*­€­ª&PüÝR.i8Xz×s¼ðõ+ÈDÆ(8uÂ™”ææg¿ù7ü3ÞOlï6ÜÓñ‡œLÙ-èII*D‚:§‰» ê‚%ËfÑ·±³U£½¹}}1,ÝdÁåŸcõ?c8_Çêè!a¡*ˆR>¯™ÅÙ7Ä»73ÙßÍ®ÉE0¼‰}EH¦x pãZvy 	L‰Êë4Š7]Û¹¸<b°wóæ}üß\\³’ú?qAƒ(ã	8Éì~¿K\'±ö\'D\nNž|h=IS0QT(JHZàTÁ¡AÚý’`0‹CWð˜‚D¦5gÏ˜IlïF$’‚¡¡š·E’©ƒVóC¶‘å±ìˆx|>…‚F9Y¦½°Ü¤“|JAþzÉ¯_ƒØì‹Ñ\n±\n˜1 Œ_úƒÑßFÆŠ´?Í¿¾Ù—bZ@Î@/B9—¡«;ÉàK?ç0{º\Z ”…¤!‰dÊdò^§…U§ñLÆÜV(\rGËhAA>oQ§±à4sZTò	a9q”\nÌUÓú_\rHmóM­e÷Y¨3ÏEoõâªWé‰ä³—¬²Â@FF+ E‰)@Fq`êÈM§j¦µó7œÃ]¸ÕÇ:Y<WÇ¨w ª‚öãN`4fÑþ¹õ<³K!U¤,A4ÒVø×ƒÖ†{w”ž™,°åî=Ö#ÿú¢yŸÚà`î‰í³Ž»î	¦MwôÂDRâr™@#iîÈ¡­iR®!£ÛIõ¥1²Ý9\\u 9‰­ÒY CÍ>¦¦€Y8ô°¸ìçFÁÖïœF´ëQÂ{âì.¡åŠ8¦ÍdÏŽ=¬}¾vÎ2ÆÒÉB¼(qºàé¤¹¡¯$»A`\0Â~H‘Ý“ùÏæ3OF”ÊtÿûG©³J4úT®ºãsÃšÍ8UI«Gÿà8ÉÀš›¿,{V>Eó	§0ôâÓä;O!·m{CI\"	O½àºõækÔÔy²fÕ>&°½w(ùz§Ø¿êºF…$V}h?ÄÒsÎ\"±óQR\nf^ân\nÒ×£X‚EkwÂ$ŒUî•À~pUg&€¢Çã1Ö_íø¥å]ÈÎõ{ðYzÆËlì3ñvxHºƒê\r-Ãÿ€Ö÷‡ÄÈbÛÇðµwàðOÃ?}6>_ŠÈ®ãqšÄéT¨L¤P+í\\ª &±™™®¼Ž­¸ÄµÈìù5æKLûÌï1} È8ÊŽG	%êiÐ%\'_rÛ·G1-F&¡\nˆ£Ø¦\"R4†Íô`K.—ëÊŸ½ÍH2káb¢Y³ný1ÿ7:†K“èfi&¶z°>h Ó¯ÿ¿Œ?Äl ×÷;ú6t¡Mn£P\'‰.¿Æôé¨1.Í”ð”	\'€ø`ã?}&öp(Ü@bÇ*”®sâ·\'}øiò¦dýÊ{PÜ\n/¦­MýYk0Œ­Ê#@ˆš¹ö\0Ý@/°·#Ø@!´‹ÄŽ4wª¬½ñZêu\r¤†Y2\0\Z\0ßQ2\r=0øÂ:Ptr§ü’Y§âƒ&á‚àôkþŠ&¿z1?Ž­²ÙJcÛ­ª\nVN›‘‘î;SÓêü^´¼h[>ÄÂ“ëñB”Åe‰Ë	¦$ý@B•¾\'¨…WÕ{Lù{¶AM0óúgh=çý`êhRrÓâ\n…-íT@<z@úgO?>8ÝÀ˜xÿÀÈOê A—’§¿M­°y€(6#‹Øê;FÍk§¦´ª$*0Gì¾É”çÒú‚|ŠÎùàªË…¬E\"\'™ZÕLd+×	j*Ué»XºÓ[ÎÇFfÅ\\žÖ€ÆèD	CZìí¸/è?\ZHSm¤lfQ<r±E)WÆ¯;˜ß\"È;t&Ë2AÍKO`«`h\n€Õ`¼\0Ïýç97w.\"ð¥‡Iffïêá‰«]0óã4/˜…iK+>w!]@ÍVcÒÉÊ}ª@&±R5k$s™X·W„	‚(–ÁdÂ¤%¨#@C\0À4ÚQrß=_AQ\\¤\'¢ µ°}£ÞâB*Õ­€î§2øª}¬N:‡Í\"`PË3ZKç–nh\n&)t=ÂŒkîb`W™suvÝwi÷qœ°ô\\’†à¿}†x\"o^e¨9­Tå½Á[r˜ªbÓ>À9W‹»µýòQ\\šÅdÁÄ,¿á¨Ý Ã9h g×Ë#J‚Ð«OÑ6ÓÇä\0`I<>…D_j¶1‰íI“•É•°YR¦¤i&¨÷Q/Þv\'êÉc¤ãzBcErÚñ¼þÊZ¤ezgÞºŸ\Z`ÕV²\nâŸ…0¢éŒ’%]ÌXþiÌp˜·}„±4øT¨°UÚYiïZ½\ZÈÉ¾q\Z;‰gð7×#-‹BV’+HêêÇOW¡Æ¾¶êU(y3S$€¢ÎÄÈP£O½\0ÏðÓŒþüûx#‚ÐÞDYP²–)¨ô“§fƒ«AaÊ=þLÊ8ÑÜ*†ê¥ó37Óµ)OÀ+Xñ³ŸbØ±¸Äf£ãíúØŸ4ñPÑ½qÒá]€U´0œÝ-PLÉC2V™T;ÄI2ÅVUºyãuï-ÓîÏŒuã¿b5}¿¾%3Âc›â¤œlÚ¦²kãÓ¨j=3šÏLšb³®š†›\Z«–x‡-	+Þ}¦ZNá(Œ±ïîcæLDn½ês¸üo8k{Ýý®ñ9h óq_ÇÃ 3°øˆ€¸DsA:\rwn2·c3ÐÀžtžý?a›ÎöÓŒB‚•w¢-½„äú9£M2ÒÆ¡k(c]Mã*)PcàTóP½—¹Ÿ{Ô&l„ÉGvCv7§þæeŒºNÆ³íu:ù|jê|tœMY8‘y7ÞV•¾A=(P]Šþzû#ÔÔ.+(Ê·4\0Y¿:»¼ôAÊ‘xi5Ùl‰9ç¸˜Ó)px%‰ŒEs»Ås±òÞÖ˜Ô˜þ¶*ýÆ„£¯ãvf‘J×/#Ü=LW!QÒhó”Á¶È#o#SãErƒÉˆä¸ÅN<NR’ÊI\\\rjjýF&\\¼Í$­-7Ê\\ë¥ßùIL¿“t2EÉ0èZ“eÉw‘ËA^*ÄS>ºÂr;µØó\rG5åúÎ@Š,Jn\0©ùA\n!iÓ%µHJøÀ¶â@±9h NäD\n%âa‹dªLª$A\n¤Y†šÑ/UÚ~U.q\'§XÑWYtågÈ$’ŒîLÓºÈÅk»\'y9¬qïŠki™ÙA8Ubï¾ªyj¶qª:WÙùŽ@–ò…¾Õˆ¦ÓÉ&c…‘4N†­3Z•£ÀHát:qµŠ³Þ‡*T¼TKƒ\\Y:±*û÷¢9^5•984Ö%:N¯ŽÇcàmYÁà¾†K01ø—Ù®«©mOXØ@NIßQ\\Ác°êÞG)3†Q¶pº`^§ÄRx|Î*&bõK%‘l÷Ì48šurRµ,RYØ““Ø¬©ªu‘ýxÒ±ïø¤\\Îx×fB+o¡ùŒ+ÉÆòôïván—KKý’×c&g´h8›<4{„‹šs)ðæ\0ÿ/J~ð5¬È*„êcrÂÂDÁëøÜ\ZÜ¨1Òâh„?Ò×Dz\"GÓñ.ÌÉõ.Wiß©ªÔR\r¾ß${¯o¿zÜ¼ˆœ{1Ã/÷Èµ‘éyç)\Z©tžúøƒÏ[œ=·•ÑL‡\"Èš&ÔT¹êÌÞåè¨G.ÀÈ(PL¡˜?Ýb¬à!—J°+4¶›‰GÈöé-0újœlÊ “xêÁ B{Ð]7e0U;ö¦A™ÙØ/œ2K‘\0¡ñC/¿Ä¸1À±çáD(Êª¤Ù%itMÐâÓðHƒRA@Õ¸ñÏ–‚û“\\zÝ&Õè¦î¦$c˜”¥$*Q×ÐÈŸúb«¨™ýUu¼­4‘m§U‘x?ò-,SâukÈ¬A§7_M×Ë·\\èÿæ1†±ð‘kYÊú¾Á@È¢wg„òàn‚ñ5øü‚Þ°Ä,JšüY¶È*:uó:‘æ]UÃ2ïD\0#7z|<4—|N }¨šB6\'%Õ\0;ëSíómíúþä l›\r–4Èš^ÿuõM‚ã–ˆºÈfÕ¾«e&o’Â²[µbçÉ¼ô“;ÊÚf+¸\Zþ Û{ÝŒ¹$u‚¤©c8%©œ‚Ð¼Œí!c\0¶›êÞÕ„u+…³eù¼›Ô®—ñøyÍç¥gp¨›åS³ùïZ>æ›aZŠÄSÎ ( ó\n=?Ž2©à÷–Á~¢bJSÑwó<Éx?‰Ý;˜}ÉE,Yñ)’a“2Ö‘1|¼¶¯L}”,&,X â-ÅÑ,ÒB@v&ÛÅ»ÌÒõî˜«¤w—:É´ ºs‚¼+àâÅÑäÔ\"€B¥½k9h Ÿïöu–MA<	…¯iš´¯3î_ÆK×Íú2µ5«ÐÇ¾â±^žÒrƒ¿º‘î‡bë/îg &é\\P‡ÑÀˆO0‘V¬9\';Ðóí­\né2”,…9óÚÉ”$Ë;”íØû+ÞE¸ÒâëÍäÎ!¶õA²1I>\Zg$l’ˆÆùöS½TÆiPÛW2ƒR^óÇ]cÙ¼I¼¬Sn	\",Ð¤À2Çè]$Û/¬~ÖÔæ>ó8Š‰Q¶Þ±‚ö‹—ó»î š2PuÁðºƒÛ\'I”à•¸õxÊícÉ	\Zºæbp³É,\rº^&f*œ;M={; \0ø±—uÕÉŸÉ}¿øé9=†t(¤‡GˆŽ—‰Äœ´£qê?~‘Ÿ_þ°íâÔ,Ò_Œ¦Ê¡ì\"Š¶Å3\\!K*f<™#\'\rFv—ZÍÃ÷ñÄ·ÏZÍFGßu¾\\¾ÆúÇ‰íbî|ž?½‚i\n\'}¸•M§®	~üšywÑ’]ã©K>ÿAëæâs~Íâ¤F…éŠÅ©ß¸\nh>l =¼Ã~ôò‹Ž_[èù;îº×nDK&Ã‰\0.W‰_½²o=5»XMùµíXyÆôêyC²kšNÅ²E	<01ÑÜ¸gt´5æ6\\÷J6ê`rW?Ç:˜s‚`p¬È¼E:Ù,¸sò™2mÓ¡`b\0\"Ÿ4ô%¦ÂüÏ 3 ™×\"™á(óøu×Í 6˜^l ÷«âÎ-Ÿeè‰=ÚÏ\'Ôm¢øÊ¨:”l|ðFsÆnìÀ>K-ã~@rÈ•Í\rM(ô®~œBBAóª$&MòI‰\'ý2¿ûúâoªd×y·rÚ÷~V×Lß·;@ºPF=ýv¾P¦1(¹æë*é6Õ´ðþ§>ÎÐ½/Ð¦›Ìj1ùÆÚG™4·æü:6~l0ÝÔV%o€YxêbqÜÄpÇrôò3ŒŒ[´M¯\'m¶÷JúÃ™4¶cÌag©â £9,@Î¼pùû›¼‚ÆÓ.£¾Î•¶–Dó”I—¦ÓÜ÷4ÙžêfŸÀ`ÿ(=›ÂD4Þþ‰!ƒ×ž}‰¤Pøý Û™’¬íÚ›P—cY\\à$wÆrz\'7Ÿ}	¥¬E<gÍB/ûg¥›Éð¶2#ÿõ²;w´3X—¢/¥Óy\\€§&x›9l6¦y—qéT9 äåþä¢[{æþå\nÉ®ÇÈ¤L¢£pæ¹N„+Ëô¦ed_\"-³õ–sÉæ4’BC\rm‚ü‰§±ä•\r:%{û¢¶ç’kœÓ¶#òè•³;Î¹–Ñ86ö9fvê4I©—a€ô\0Í•ïE+ ÈøêË¶ŽG.…t¢/\r\Zî¥¨JÍŒhÃŒ¦›Y\\Ÿ›)j…\niâ8Êa)}þÄc–H™¯[°p¡B®`Ða<ã`44È“7\\Ïà¤J¢(qh’—¿‡¡˜Ä(„I;+Ö‰uÔ6¯Š@éÞgÃ÷fGaï¦1Êf+içB‚>\'9Câ*áê…Žob«t=Ðt\0~¹ãò’•»Àµh|…ÝÛÇIÞŒN<4Ì%w<É4wžïo˜XIm×1Yi¥ƒÁà°Õ_·¡è*¹U´Å3é1\\ÔM»Œà’òôOÂ¸\"HY6 ¾E!´e+A?l}aÙyj¼ÕÍ²ÜÌ6Üöƒ[6¢¶-¦ì\"¼ÓÉ›2\nõªÅE-îOcÇ“-€S>ZÚúƒ×|}„¿x6ýct%x>ªc9=ÕÍ¯þ$¿ê\Z[‰ÍÀj­Pµêã GÎƒ@Å[6)§ôŽðþ™%‹ÓùÃ-_%¡9i¨$,X¸ÐO¬Pb\"\rîctÎ[ªÑŸQËUÓW ”Ú§¨7Ò~á\nŒ\\„†æ:¦5étçZH«P_–¼§¹Ð\0Xç¶‰÷Œ——÷ôyöç™Øó\néX‚Ðî]Ú\Z©¯÷“Ë&W½ä\r³€m§V}D+×ƒ’Ã}pGñ:”O\\àç·~E š&\rŠY‹¨Piö•èlHV0£S2ÿÄÙ¸\rŠ:Zn?^Éš\'{xÔPÀ­*?¬êÞ0Izæ?an½Ë3ÔÐ Ã	‹pR£O:9Å—¥ [üËçþ×‰aâù»xíÉ$Ix<Éd¾öÄ*þð“Î–	Ü´fì>jµ“û¨[åvâ‡ìlÞ\"VÖ°žUU\'“iUÈ¢Iª(˜ÖhPçŒ3—öcR¼ï?ºs¹á5ø›šðÍ_ÂÞ×t¾h<óüB.†XŠ•ë¥ôÜ­œxùg	»Ó#c&œÔ«bÑsM«NÒÑb#¥ûofÏöÍBÜP)£Ò|û£WÒä(ÐÖYÏMkÆ„7ÕRNVÞP’â­r$Îø;òE&Ê3u(ô§5âE(ÅûX,Q´šèüER‘:Rc–œF±ïU²=¡vá[‰îk¦í$ƒþ_\\Ì¬å+Úk‘WÊÉÓf{qºiE° ÓbÃ?æ¡\'·QwÙ·Ø]TøÀU—Ó+5æwª,h+¶ñýõ“¿Ç®=\ZÆ¶ØÕjñàè;»PWMM•JAJæ·8ðù$Žx™FŸäôN•lZ%“³ðé\nÛRäÕÏ6Ú›cÞ¹­4¿w27ŒþÞÛzî6ô‰.òÅNöùï^GÜÕD{y‚î¸—H>¿É\"3æÅ§äÙ‘RÈ–5\\V	¼>Þ»°žB\"nÜµ%ó(6hã•kµ0µw¹MñNr$Ïk`pBåZ÷õ“´ï˜HJÃ¿OÐ:OeÏ«&^7˜´	ŽY hÕqùx/\'á½€Ô“×’˜€hT\'§Í —Éà)-6L(’½Ã 8T4M¢¡ :Ü,žçæ\rã[FKr6€CØªÂ.<\rq@„ÃpÎæ/Hû‰G€üËcÖ¶ˆôNÎò”íˆ&Ã&E)p×	&’à(Á¬sý„vÙ»Ý¢”ê!_Žâ4boÏ0’Q˜˜ˆ\"­(c\nš¿EÚPÈæAÕ!]´ºàØNn9úDÚ$ŠÍ¾È”Ö­Þ”*{\'9j¿iíØ:€c=‚W,žöåBA’Q2f5ÂDLâ÷\n’Ë¾{;…õ+ˆ—1úÂ‹lé×P‘ \n&‹’‚®à7MÚ:{F^¯ j9B;#¹nìpªZ=‚ÍÄìûx›jµƒ•£	dUœØª^mÍ€~R{ýNó&—ä«H}{™PC“œÕ—(n^Éƒ²h…,C)‰Ë)ð8$NUaCÜØ‘*É860Õêàµ¢Ójqþ^l&f9Ì¿Jð×\0²zßjbÐŠ\rètìUJZžÑE¥çò3ç-uæ³3Ç>í‰>RP«¹¬žã©.ùªGEÆ±Y¸ÃÌÄ©úk‰˜rU°37~l`;±·¦c¯£«™jsRû‰Im»Z¹[-@c³±[µ«é±ÿV@Vï_=‡\rµ\\¢F­ØŒmÀÞZpb³T§¶›XÝ?¯ÖU´ÃØ,ŒS«:\"?4ò×ò­RUù©[¹Õ\r4Z·\n¤·Ò‚•ÏUÏôTý«ÇFŽ§üoM¦ª¼x›¿UÕÚ…ÍÐ\0¶	ðc3/‹\ræXåz@å\'‡2è¿5©ª|õõÛ}f*°:¶sÒ*ß5¨ÿqù[òdjuÅ[Ç/ÞòÿÞ2ø»ü•åÿU¾Gåê5E\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0);
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stock_corrections`
--

LOCK TABLES `stock_corrections` WRITE;
/*!40000 ALTER TABLE `stock_corrections` DISABLE KEYS */;
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
INSERT INTO `transactionitems` VALUES (5,1,1234567890124,1,0,'Pc',10,20,0,20,'Doritos Nacho',0,1,'',0,NULL,0),(5,2,1234567890125,1,0,'Pc',5,10,0,10,'Coca Cola',0,1,'',0,NULL,0),(5,3,1234567890123,1,0,'Pc',5,10,0,10,'Herashey bar',0,1,'',0,NULL,0),(6,1,1234567890124,2,0,'Pc',10,20,0,40,'Doritos Nacho',0,1,'',0,NULL,0),(6,2,1234567890125,2,0,'Pc',5,10,0,20,'Coca Cola',0,1,'',0,NULL,0),(6,3,1234567890123,2,0,'Pc',5,10,0,20,'Herashey bar',0,1,'',0,NULL,0),(6,4,1234567890126,1,0,'Pc',20,40,0,40,'Paq 1|  1   Doritos Nacho|  1   Coca Cola|  1   Herashey bar',0,1,'',1,NULL,0),(7,1,1234567890124,1,0,'Pc',10,20,0,20,'Doritos Nacho',0,1,'',0,NULL,0),(7,2,1234567890125,1,0,'Pc',5,10,0,10,'Coca Cola',0,1,'',0,NULL,0),(7,3,1234567890123,1,0,'Pc',5,10,0,10,'Herashey bar',0,1,'',0,NULL,0),(11,1,1234567890124,1,0,'Pc',10,20,0,20,'Doritos Nacho',0,1,'',0,NULL,0),(11,2,1234567890125,1,0,'Pc',5,10,0,10,'Coca Cola',0,1,'',0,NULL,0),(11,3,1234567890123,1,0,'Pc',5,10,0,10,'Herashey bar',0,1,'',0,NULL,0),(11,4,1234567890126,1,0,'Pc',20,40,0,40,'Paq 1|  1   Doritos Nacho|  1   Coca Cola|  1   Herashey bar',0,1,'',1,NULL,0),(20,1,1234567890124,2,0,'Pc',10,20,0,40,'Doritos Nacho',0,1,'',0,NULL,0),(20,2,1234567890125,2,0,'Pc',5,10,0,20,'Coca Cola',0,1,'',0,NULL,0),(20,3,1234567890123,2,0,'Pc',5,10,0,20,'Herashey bar',0,1,'',0,NULL,0),(20,4,1234567890126,1,0,'Pc',20,40,0,40,'Paq 1|  1   Doritos Nacho|  1   Coca Cola|  1   Herashey bar',0,1,'',1,NULL,0),(33,1,1234567890124,1,0,'Pc',10,20,0,20,'Doritos Nachos cheese',0,1,'',0,NULL,0),(33,2,1234567890125,1,0,'Pc',5,10,0,10,'Coca Cola',0,1,'',0,NULL,0),(33,3,1234567890123,1,0,'Pc',5,10,0,10,'Herashey bar',0,1,'',0,NULL,0),(33,4,1234567890126,1,0,'Pc',20,40,0,40,'Paq 1|  1   Doritos Nachos cheese|  1   Coca Cola|  1   Herashey bar',0,1,'',1,NULL,0);
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
) ENGINE=MyISAM AUTO_INCREMENT=36 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,1,2,500,'2016-01-16','09:28:00',0,0,1,7708704,2,1,'-NA-',100,'1234567890123/100',0,0,0,'-NA-',0,0,1,'',0,0),(2,1,2,10000,'2016-01-16','09:29:00',0,0,1,1970730888,2,1,'-NA-',1000,'1234567890124/1000',0,0,0,'-NA-',0,0,1,'',0,0),(3,1,2,5000,'2016-01-16','09:30:00',0,0,1,7708704,2,1,'-NA-',1000,'1234567890125/1000',0,0,0,'-NA-',0,0,1,'',0,0),(4,1,2,20,'2016-01-16','09:34:00',0,0,1,7708704,2,1,'-NA-',1,'1234567890126/1',0,0,0,'-NA-',0,0,1,'',0,0),(5,1,1,40,'2016-01-18','21:52:00',40,0,1,1,2,1,'',3,'1234567890124/1,1234567890125/1,1234567890123/1',0,0,0,'',20,1,1,NULL,3,0),(6,1,1,120,'2016-01-18','21:52:00',120,0,1,1,2,1,'',7,'1234567890124/2,1234567890125/2,1234567890123/2,1234567890126/1',0,0,0,'',60,1,1,NULL,3,0),(7,1,1,40,'2016-01-18','21:53:00',40,0,1,1,2,1,'',3,'1234567890124/1,1234567890125/1,1234567890123/1',0,0,0,'',20,1,1,NULL,3,0),(9,1,1,10,'2016-01-19','13:38:00',0,0,1,16424376,1,1,'NA',1,'1234567890123/1',0,0,0,'NA',5,1,1,NULL,4,2.1301104714e-314),(11,1,1,80,'2016-01-20','12:39:00',80,0,1,1,2,1,'',4,'1234567890124/1,1234567890125/1,1234567890123/1,1234567890126/1',0,0,0,'',40,1,1,NULL,7,0),(20,1,1,120,'2016-01-21','13:47:00',120,0,1,1,2,1,'',7,'1234567890124/2,1234567890125/2,1234567890123/2,1234567890126/1',0,0,0,'',60,1,1,NULL,15,0),(22,1,2,1200,'2016-01-21','13:56:00',0,0,1,0,2,1,'-NA-',100,'1234567890127/100',0,0,0,'-NA-',0,0,1,'',0,0),(35,1,2,2000,'2016-01-25','20:22:00',0,0,1,0,2,1,'-NA-',20,'1234567890130/20',0,0,0,'-NA-',0,0,1,'',0,160),(33,1,1,80,'2016-01-25','13:08:00',80,0,1,1,2,1,'',4,'1234567890124/1,1234567890125/1,1234567890123/1,1234567890126/1',0,0,0,'',40,1,1,NULL,24,0),(31,1,2,1000,'2016-01-24','21:40:00',0,0,1,0,2,1,'-NA-',100,'1234567890129/100',0,0,0,'-NA-',0,0,1,'',0,0);
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
INSERT INTO `users` VALUES (1,'admin','C07B1E799DC80B95060391DDF92B3C7EF6EECDCB','h60VK','Administrator',NULL,NULL,NULL,2,NULL);
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

-- Dump completed on 2016-01-25 20:26:25
