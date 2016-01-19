-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (armv7l)
--
-- Host: localhost    Database: iotposdb
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
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `balances`
--

LOCK TABLES `balances` WRITE;
/*!40000 ALTER TABLE `balances` DISABLE KEYS */;
INSERT INTO `balances` VALUES (1,'2016-01-16 09:18:35','2016-01-16 09:18:35',1,'admin',0,0,0,0,0,'',1,'',0),(2,'2016-01-16 09:34:55','2016-01-16 09:34:55',1,'admin',0,0,0,0,0,'',1,'',0),(3,'2016-01-18 21:51:59','2016-01-18 21:53:57',1,'admin',100,200,0,300,0,'5,6,7',1,NULL,1),(4,'2016-01-19 13:38:41','2016-01-19 13:38:42',1,'admin',100,0,0,100,0,'',1,NULL,0);
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
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `logs`
--

LOCK TABLES `logs` WRITE;
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
INSERT INTO `logs` VALUES (1,1,'2016-01-16','09:28','[SQUEEZE] Purchase #1 - 100 x Herashey bar (1234567890123)'),(2,1,'2016-01-16','09:29','[SQUEEZE] Purchase #2 - 1000 x Doritos Nacho (1234567890124)'),(3,1,'2016-01-16','09:30','[SQUEEZE] Purchase #3 - 1000 x Coca Cola (1234567890125)'),(4,1,'2016-01-16','09:34','[SQUEEZE] Purchase #4 - 1 x Paq 1 (1234567890126)'),(5,1,'2016-01-18','21:51','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1'),(6,1,'2016-01-19','13:38','[ IOTPOS ] Operaciones iniciadas por Administrator en terminal 1');
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
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `measures`
--

LOCK TABLES `measures` WRITE;
/*!40000 ALTER TABLE `measures` DISABLE KEYS */;
INSERT INTO `measures` VALUES (1,'Pc');
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
INSERT INTO `products` VALUES (1234567890123,'Herashey bar',10,95,5,5,'2016-01-18',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0–\0\0\0H\0\0\05½\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0‰\0\0‰7\ÉË­\0\0hIDATxœ\í}h$\ç}\Ç?*kx&(e”d.®7u\è\í\ÕKu \Ú\Æ4\'“ÀI\Ä!Z,\ê\Û&\à>\Z\ï\Ù49ÙqW‰‹-§p¶œö\ìu F\çrF2Øœ\îs{©`#\âj]rdLs0\Ì\Ðn;x@ýã™™·Õ½\îž\í\î\Ä\î\Î>;o\Ïw~/\ß\ßoF0À\00À\00À\00À\00À\0}\Ý\ì gø¬_›@´˜/\Þ%l¶L6¤Ó—9\Ïõc#ô\ÇEq×¸£€}\ÉBŒ¬_\Ü\ì\ë>üA_·6@¯¡.\íŠýE6×“û\nl]\ÚFJ‰ôú·#‹õñ…®C\Ù@›D? \ßV % ñþ&H‰6Ò“ØžT¿^û€±>Ú¸58\\€¿)!>g 2	¡!nËƒ\Ðh\\\ÚÆ–K:Y\Ãu ó‹‰±n>nðWÀ:£2	¡AN 0,\Ð†p%\Òs‘Ž­\Þï½½/\0=¸\Ä\ê=>\ìð\×Àƒ \È#\0- \rŠHB„\Ð(\äúˆŽ\æ\Çõ$RºH¤”¸m‰\åI\ØQ†G1\ÜY—\0\\$z†…\Ë\ç\Äý-OöœX¹\á\Æ@¾$\à)\àÏƒ\é\ÈL¶@9¼®£‘KÛ–[\ãùVHJ¤”\ê»`™§\Þˆa`\è:\"›Ò¡\Ù2C²&!&²\çó>°XWŽ\Ï\nøðC\n·e \\“† /š\ÐÐ…Ž\ÈB@\Î\é)‚8m—–”¸˜H)Ž5BP\Ð\r\È	\\)‘\Ò\îXªÌž\\\Ä\È\0Ã‚…\É\n†´q% t4\å2=‰Œ\ìc€\ì(\í\Æc`±\â¸UÀ1\àa@$-Ž\"QŒ<º\0¡)\ÒWJœ¶­,M\Û\'N—t\ßE¢!p‘H$=\ÈiTž^@Œ\è\àÁ\ât…c§\ëˆ\\6-gª†uŒaÓ“l:xR¹×Œñ[‹u\Ãqð³À£Á\ÂL\åú°²8B¨÷\ä@ó\'×•Gº˜­x‹“…€<Á{#_`ô\Ð\Åñq\Z/\Ô1µ\ÅÜ™\åpü\âLUÍŒ”‰\ìJ*€‰ªl½²‚+$\Âs9pú¨Ye\á“H¬O÷ø\äùVô‹ \ÖeyDNP\È	DN\Ã\Ðuôaõ\âñµ\ã`\íX\Ê\âxq\Ëµ8$’Ò\ãŒMOQ¸­ˆ\Ö\Õ\ïÚ’ú\Ñ\Z³\'Ã±•\'\æXš™Ez„ñ–¡\ë\á\Ì\Ø-›ÙŸt\Æ1\×\nP¾ÿ0?_ñ×¡2]a¿ðq%–Ü$OfÐœZ]\×\Õ\É\Ï\ÃN[\âJ‰\í8!¡¸€F\Úê€²^•ó!y§+hˆ˜õB]ƒ\î(\\d<ˆoKt=l;\Ô:#\"(\×X\Ø_¢ú\ä<\0\Òñe)/\Ø\Û=}J?\ÊÄºUÀðC\à\Ö\èQË£!\Ðs‚Â°  Œ˜\ÛÀG*²¸R\âî´’)\â\Ø8„r?ˆ\Ð\Z;]G=œ”Å™*®\')\î/ù\ÛQ1ˆ\î“\çIE\"]\ïe\á\ìcD\É\ÒsT\æ\ç\Çm¿Xfò±¹Øªœ‹fì³‹Dx‘S\çD\"S’CÄ‚õ\\$\í%±n\É\ç\Ä\ì\Ôí¥Ÿ\è8H\éb#YÃ™r`ˆ²,\àsÁTH\Ò\"_h}„zž†Ó¶•%\Z\îL¦\Ýv°§÷DRó\Ð\Òød‰¾–\ï¯Rþöd|›º\Î\Â7¦\0\å’\nûöv,cwc¾\ÛL“Jšo5\Ø<·À³“j§\ë\á\×\ÕG”8V\Å{+¡…\Ü~w‹\èžö—°\Þo\Æ~£\á“\Ù\Ó\Ð;cÿ‚½\Ï\ç\Ä_¶<ùO{\Ìu¢\'\ÙÁ8bWó¿\Âm*5f\Ä ÿ™<†\å`^4‘žÄ•.\02¤·\æ_¤Jð2¬Že‰\ÉIr$\ã\'ý\æ$FÞˆY„`ñ\ÞJ°Ejo,«@99Á\ât•\â%*Ot¬\Æ\æ[\r\Z/Ö™[]	\×k\ï\Ø\Ôš£ú´rgª±ý¨©\Ç6c;6†n„\ãƒ}Ž%\æ^s‚¥\é*\ìv+T\Ê4@X@S:™™¡Pò\Ço´[˜}À7=\énhÁkÐ¥\Ä}_™lwÇ¦õ;S	}ºŽ›Èœ†ƒ\"Š\ÓV)º\Óv‘\Ò\ÆlYX-“ÖŽ…Ó¶±\ÚN[‘\ÌEbû–¼t¨\Ì\ì\ÉEfO/1·ºBmUMÀÜ™e&¿7Ka_AeTQ+\"%sþ8ÙT\àÿNbþj+¶øÀÁ²\"Id\Ö4\Ý@š\Zñ±_-\Ç>»H¬„+\Ór\ØH&\ìµ¸\×\È>>¹€\Ûv0\Ð}²\Ê\Èøl#ŒŸ\î2ä†¡\'\Ä2‘ÿ=5öû&\Z`;Í¶…\å´|\Ù)}\' ™-µ|X0þ@…\Ùž§v¦\îJ0ÿ\ÆY\æ\Î,3ñÀ,F>BÏ$\Ä\Þn/= ¬\Åò\æcË²Æ‰œ²&v„ B¨e›o­\ÇÆŽNO§¬\êòó\ÉUv\Ö‰\í‚\×\åDŒe\äÌ­­¤~+=bNt\Ïû™!öªk3P¢ƒ\"ªy\ÑÄ‘Ç‘a0@\èjLñ`™Ú™:µ\Õe\æ\Î,«\àS7;4¶cw23»\ê M\éIŽŸ\Ú\â¾Rjœ¦ë˜—\âñK\é\ÎqR\Ó\â[\æ\ÛyŠÒ‹\Ç\ÅF¾é²£\Ã{O»s\ÑJ_,mIm-ž\Êð\â\ê^Œ\îG_V\Ï\Zý”]Q¨Bªë¸¸\ÒU\ïý\ÃvsP\Ã\Ì-¿6\Zq[NËŠ­wü\È, °.\Æ\'_Œm\Éúk+€`óõ\Õ\Ø÷gŸ~ž\Å\ÉJlYùþ\é\Ô~÷H\é\Õc‡¦ü\Ä\Ý@ó\í\ØX‰¡z:û6Ü‰•òw–\"\Ë\ã\ã’\ëI’qñ\Þj&¹¿°Hx¶= \r\Â\ëÄ¡!öYo4zF,þYžl«4Zz‘«É“L|G«8ñkL\"q–ª“É¸¥\0V;NýHõ\×VIã•¸›8pw™¤\Õ)œPzWd‚Ç\îð­ˆl\Û\ê2b1;A|•\æŸD)™;£¬p\Å×ž\\$õ£\ÇR\ë\Û\Z„IGÆˆÁ\Ä•p½n†­\n: ´Žó©«\ÚøU¢g\Ä*øq‚_)—«˜*~5¹þ\Ä%OHñö´«\n,…™ –²d\éqò_ò\×¹â¥§Hµ:†n ‘,\ÍÌ²8Yeif–³\ÏÕ•Æ• \Ñ|£‘C•\ÛLo¿³_·\Î%+sH\ÒM&±43‹ùN¼óe\ìÐ¤\"4ñ€œ@\Ë‚±Z¤\Ã\×ö\Ü\Èu¢g\Äð®›ö¦\Ñ\Ü\Øb\âA\åâ¢˜8\ê“%h,§[M\ï³`\ìS–Nˆ¸%\É\Ú3qe{þÌŠ÷E•5\Øz+ž\íÉ41\Ê3\Êr\Ø;YJ!\áB)!#\É\ØKF	^Wžy3¡e¸«’RÏ©’•¤C&%Õ¸\àø=DÏˆµ†st/REE\Ð\æ…²\íŠ¨x\ç(@*\æq}U<¶¾¶žø\Ì+\Þ_ó\ÂF\ê+\×KwÌžZ\Â\Èb“Ù¼°žúm\ÆmŠÀ\æ;ñ\í\Ô™cq¦\ZjT\Ö~òl|¹.ûŒš\àð\ÉŽ^f\â*k\'c\à\èL%V*\è\Ê\ÅKÏq=\ÕmaK‰žG/{0×žKÂ–£^Ãºd§¼v\Ëb\ë\Õ’Ùžl«  \Ë «ºÊºÁ\Ô\Ã5Š£÷ºþºR\Â5\Ï®¦\ÆÏž\\\äÀÁ‰\Î~¶[©1\æV3t\í€b­sq\ë$\nI\Òlÿ[š¬Y1’‹ŒH+p\àë“ŠD‘ø0\èÓŠ\É7€Äµa]vw\Õ7=½ý+~‚²{ƒ@Py|>ÛŒº@²y\îl\ì\ÆHQ\Å	7r\ìô2µ7–™||NmOg]¥»#BeN°þj<>JZ€\É\ï\ÍRü\ê˜q¤%‡•§07\"ñŽ?aV+.€¿<vY\É!ø}Ö¸¤H\ZX%ó½Ž;Œe™II!B¦~\ä†=%V4p\Ô\àh9P[¥ZC°\é[‘\0Ú° P:[6ùÀa%¸~q„\ß\ÃTøb˜\ï\Æ\Õò<™\n¼53\é¬kò‘Z\ç\"É¶±—:Î„N%ºK\æV<VÊŠ©\\V\Æ\'\ÖÖ›‘óIŠ\nû‹è¾šŸe{žß°\Z?¤.6\Ë\èT\ã­D\æU{¹ž*¿<†‹¤µ•M1¢&±ñr¼\×\ÜXO\ÕÕŸ,\Ä&P\äJh>³§ž\ïºÿf¢<#»X£nÁx\Ò\"gAC`;‘}÷ü$f+}_D\å\Ñ\ãL>Rƒ¶6ö›Z}¹ZMX\Új	ÿ\Ó\æ¹\åC“ª;ó\n}¿†`3Q“#\Ö%‹\å(Wh&DTû’Eý¡xi¤pG)\Ó5-N\Ç-WP ¶/¥u«\ä>ô¼ ië–…V‚˜\Ý`¾¿jk\ËÌžZJ[~\æÇª\0­n+\ìEªžiY=\'V\Ðt—|\ßù¬–•\îž@:!.‡\\v!!XþÁ<\ÖEU›L)\èßžJ¯\Ë/jÏ¯\rKIó«g‘QúHg{\Å}¥”u*ß§²3¹/\ít_\Üv|œ¦g»\ÍÆ‹qdº,ŸôµS/a\ÜV¤|´šº:ûþ$ó\Ë€žË‚Çƒ8«\ÛU\ãAè¯›>!\âd¡\ë,\ÎT÷L´³:¹:Pn![;j^ht¬Š\ßÑt3\Z‚\×\âŠþ\äc5\\\âsñ J¶7\â_\åû\Çy\ßX‰—a˜Nœ£X:R\Ë\\\ÞxuÅ·\Ôpú\è‹÷VX9± iâŠœ¤¯u\Ý\Ðu¢§\Äj!OB\'ˆ:ùAšP²ùöz,; \Û\Z‚\æ»W.9\ì™uA¬{3Àú««©e›o\Æ	\ÕHEPbrv:RD \Â6’Ci¼¬H+e(\Øf¡x\×h\×xŒ¶;0\Z¯,³t¤\Æ\âL•fD:‰ž\Ã\è\É\\XBüq\æ\Ü\0ô\ÚþoðFÒ©”ª¼±òÔ‚\"Ñ…¸\ä\à\"\Ù\\¸…|¶\äDRr\0hœŠ»‰Äº”ŽsR\ÊöWË™’D\n\èþ>©.‰øF\ãÍŠä”¥¶;ž\é%Œ·.™4\ßl¤\Üh\0Íb5¡š“ƒsJ‹\ËvT\\úþ#™ø\Â\É	®¶\Í\×\Ò\'¶õA|\â•\à(³ƒ\é’\rz\0›¿LX’ý£)\ë6õýZX0/•Hõz’Ã¹\ËKQòl¾Õ‘X\\$‹\Ó–\î­R?zŒ\ÆsõÔº®\Z G\Å\Ò\ÄE(†/s\ã\Åu\à¦\ÞL!„†ð\\uÿœ²Š³n\Â}•\î.sö—h½³…ñõŽ:n\èy\\\Ç	\'lý\ËTN\Ä	’œð©\'\æ¨·¦\ã[’\Òx¼\ë`\íÅ¥TKL€Prð\×!Q\í3KGjaûð^õ?¸²\Z\á^¿ ¾Rfû—\ëa¼HJ ç´žJ}Ö±\âP®@KY­(´,“\í\ë8›‰.‡ G\ßW x\ç(\Í÷\âk\ì›qM:ýRAð›ë’…\Ëö¬KŸ+\ë¢yJ¹_ºW\Õƒ±´\åeI \×B*‡\âWÆ¨>½ÀØ¡	\\ ø\åQu¹\à\ê\à»?=§©§\Öôý°X¿>\Ó\íK³ebä‹ˆ6¡\ÕJº¥ñû*4~žh\Ãõ%7•\î.‡¥\ë3\å\n\Ë÷U\Ø|³¿EËƒÊ“ó¬œX\È\ÜÇ•\'0\ß3C®~¤\ÖõŽ\ë…DªB´we\ä¾p\Ú8Y\ÇjYJ\êh\'/LeeÃŠGj:ý°X¯wûNC¨›)r\êS€\ä$}{Z\éR#+ƒ€I¨\Ì+1¬£›o®Â°@¶%\æ;›l®žEC¨>,¿aqFõc™\ï5‰Þ´\Ú\íõZ,\ÎñSK4l‹©g9¿kSo¬3‘aU÷:‡†n¨Š…\'iž;\ËÆ«\Ëº\ãÍ¼:%„ež\à\Ò#‘´\ç\Ä2‘ÿ¼\×÷p#7\0¨{y³\Ë!\Ö\Å\í\Ø2gOr¡½c³þú\ZõG\æX˜V\"i\ã\ç\Ë,NV¨©±òÌ³´~ÕŒ¹$È¾ÿðJÝ™D†ûw\ÜWÇƒ\ï\'¾Sa}\×U\Â\ì\Ñ*B\×9ë‹Ÿ£\ÇYX]¾\"X¼£D\íL\íw7UMu‰\â\Ýe¦Ÿ˜gô¾\nµS/ù²Œ>D\Üú[ø³\Ën\è\Z\ÐW¸\èW\Ý\àx.…=,VPok0q¼\Ô´ŽX›4\ß^§ùöV\Ë\ì\Ä8À\é‡\æ\ÂI\î\×Dƒ\"v°\ê\Ã5j\'\Zb\í7¿¥ñú*¥»\Ê,=1ù\ëM$\ì~ñ\å!\Ù\'\ç©û\îWC\Ðxõ4ó‡g)\ìÛ»i1\ØÇ©\Ç\æ°wl*\'\æ°ga|¾€¹±Nsck«I\ë¢Iiÿ(N\ËROŒ\ÂO”Š#úß›;\Î\×.»Á«\ÄM\Í\ncd\Ë\á\Ç2T²e \ÑøYy¡Á\Ú\ï[lÿru¼rk“S±‰&ûzcŸ¨t\á\â?¬°‡\í\Ý]6\Î5\È*£cŒš¤<¤a “¿½\Èó©Lt}×¥òùó\ÅNk³Çž^`úÁY\ê\'ŽjRüñwk¸k”õw7\ÐS®5Ø\Î8\Û:±b\á‹%š\ëlžk„#\Ì<(\Þ^D·\Óy„¿—\Ò\Ä_\\ó	\Ú}y>V	±¼O*Ác$\Ï(\Z²\íú7¤‚ôŸ¡\0Wï’®þ7jo´a\ÛV\Ë\Î\ï\Úl]\Ø@7k//³ðÜ³@\í\á\ã¡e2\Ð9ÿ¡\Í\Ø-C,­g~R\Õ\×w]æ§«Œœ`ýõU¶.¬s~\×F:F#_Hõ\Ïw\ÎN\äþ\0\âYu·K$\ÚD<Å¯‰DŒ\èü8S=ð$¹E.s§u\Ãyp\Ó\n%š\Èuz´¢)úµ\"\Z\ëqT¬±\ê\ß \á\"©>zœ\Ú\Ó”‡´0…_zlž\åg–TÒ70m›\Õ\ëŒ}‚¹‰)WW˜›®@t¬‹&\çwm\îù´Á=C\Ã\ê\ë§C\ËS\ÒÂ£\rH•¬\ß]®¹%+œˆ\ïTù\Ó-\äo\ØiÑŒ”šPWù\Ï+<}×…›n±l$\ÚHžRNC´ÁiwzŽ®W0\\\ßu)iö©¿Ó \\(°pò%–NÌ“\ÏÂ’\Íú®²Y÷©\ß6l‹)£\ÈñSK<{´\ÆùmÊ·Hœ”›u!$À\Ñcƒ\ìDEty\ïÀ)ùS Cž(úB¬\"b·[ðn¡”\á#ô68Ž}\î,\í\n\Ïh\ÇlryHcõ7\ÛL|ñr!œ\×w]\r±½»Z-\É\Ôwªœ}e9#¨‡n.+x,Ižä¹ˆ|þ/+\Çß¶<ù/Àÿð\'\Ï^¸©\Ä\n,–‚¢^  \ÕÍ¡v—¾ï«µXÕ‡k¬þ¬Ž\ëÁú®\Í=Cgm“	£€6RÀ\Ú1\Ñý@!\Ù4\Ýù”EH÷—e½p\à5ù”„ÿ Rœÿ¤¢_Äº( Õ¢\ïºO¬¢‡ÿ´™k/qdY;HZ›`\ëik\Ó-¦»`\Â\ã-\äË¨\ÇS}l­Í@_‚wùlñ\Â^cœ\à	D\îFG:s\é4ºµ\"ËºA#}7Qô³›ò\\}!–„XOII\â–z\é¢ù\ÏÌº²\Öÿ4yœPy\Ê~~A€ÀúdY	\ïXÈ¿s\à_ù\à²z…~\É\r¿\r\"˜‚\Âoø\ë@—J\n\è´gY³<QM¦[\ì“e}\ä\é=úE¬AY*…L=YUõ\Ð5l,Ÿ@Q•9@\Ö\r\ê5N!ù1J\Í?‰\è»@*Pª°\ë“KcX\Çu$nNbJ\'$R40ŽZ X\ÈÅ–\'Ÿ,\äùH¡o\Ä*ú\îO\"b\ÈQ2ƒ™“¸þÿ\×3:ö\ç÷vŽJ\×Iüó½>þS\Ç®}µX*%W„0*Ø–.\ÛmG\Ê—p‡\Z!\ÍMþ\×\\úv3\Å6\ÐÃ»t$\ê>?}X£%\åuH5À\'}½KÇ\íòE\áñø\Ö\æ}*Œ0À\00À\00À\00À\00À\0Dñ (`¬WS\0\0\0\0IEND®B`‚',1,1,1,0,'chocolate','',1,0,0,'',0,1,0,0),(1234567890124,'Doritos Nacho',20,995,10,5,'2016-01-18',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0h\0\0\0–\0\0\02„\Í\È\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0\Ã\0\0\Ã\Ço¨d\0\0 \0IDATxœ\ì½¬\\\×}\Øù\áóy\Ê÷¶\Ãô\Üô±˜Û’\r§•Rjµz‚\Ùú\ÕzYí®¨õ&a‘YºÁ¦T\\\ÄÒº‹0°]:YT\ÒM$›˜ñ¶e4†d ^\Ñ\Ø~ZD)i€.ŸZªn\Èz^Ë‡\Üiø\ê{Vœ\ê~C¿\Ù?Î¹w\îÌ›\Ç÷$\Ù\Ûò%†óf\æ\Þs\Ïùþþ~\Ï÷œÿy`\Ï\îü0 s°ó—J_‚‡D\nW8\ç\Üü\ÏÝ·÷\n{º\î>\ÜY\ëÿï¨’Y›2T¬‘ÃŸAu` \ÄxP4|€ †=øðI\ßS_a„t\Zþ\Î,”J¾–‡\r@B\"PR¥• ®D½Rµ+\ÒvŠ´„|£€¡‚\"	Iõ \ÒT\ã}†ð^½\0|	\Õ&²‰IFu\ß\rF\Ö\ÜP\ß.¤F†½Aÿ\ß^uú¯;û\Û$’ -‹:G9,\èˆü5Ty\àÁ\î_(óIKRœ`\Û6 AõC\"ò£x%IlÊ»c|ª†kO¼\Ùûó{Ž>ºü¿do¬œÁ\Ö¬\Ð\ÞÞ¹&aj¨£>|\ï‘\ÐR\ÚNA›\n˜|‰\ÞÖºS\"±F@U¥ŒHMD!O½\áZ-tü\ìx¿m	ê«¾4,cÂ©×‰N—‘1*\Â$&	c3\á€Òƒú2ô\ÕHý=&<KZ	‰H`šù\ZC™#.\0\Ä$¡Ýº_\Ô}T-\ë6O½¶z\Ô\È\í\â/NÃ„F1cÕ‡¥\íd<IÐ\" }\nŠA\Úh	\ÙBJ±ž7\Z‘\ïi\î\r„Ml\n¢\è°z$µh©\áQFÀ+\Ò\Ù\Û øBFi—5£Ø–À<ˆ’8–w\ã\Ø\"Dd,Q‘(””5q\0\Ô\0fÌ„\á]^³c¸FÂµ\0²W“ ”>3r\Å\0bA\ãC`‘$2PI\ÇðÈž“÷v®\ÉZþW\è\ì\Ïe#ò1B\ÚN±VpG9,AŒ Iè”»\åÀCö`§\æür¨$-©\ÕKÅ¹¥*(¸<\Ç\î³$û³€,IÂ»\æ\ÞUtP÷ú¤Y:%\Ê21Pi\Éù\0^)yÀŸWô]ÁÏ©\î\Ó[E\ÂR‘½ñ·È½Zµ\ç57™\Ò%­„$JD1(Hfu»\ÅÀ†«\Û\Õ\Û\á9i;„R5h*# ›R]ª²r\éòÚžgÿÖ²&ß¹ð#¶eI\ÆzYD\ÐaT1Z•¤%:T\Ä\nY·:º`A¡X\Ï\Éû}\Òv†®;J-\Éö§\Û|¥\Æ\0_R\Æ~dûS\Òû²ñÈP-\nÜµ`Ÿ\n¯Q\Õ$%J8k%Xk‘)	Pº-·Tz\ÛCÆªj‚ u—\íÏ°m‹º¨Z‡a¬êƒ„Ø–\í\Ï2	ªYAC\ÚU(6rú‡óŠ52ýD’&s5ìª´d’@>\ì¬\á\ä\àžo=¾ô\ÇýÞ€þz\ZCY7>õ¹’Ž¨£Ki%\â¦Á…fÚ–U\È¤¶yM(ý\Ö\ï¶BD¿a\ÂI¨ ðŠ\ÓI$•±_Z©”Šð\ç*\á÷bªIx\Z™\ÍQ•(®²u•„úð¬°fl‹\\£Íª‰¿g6HX\ç\Ð\"¥Wžø­óY@³$tuPW\à†JÓ§	ÞšP®\âf\0\ß\è`p…ŠB\Ç\Z:it¥BJi4v\\P£u[¡š\Äqªujb\Ïtbª~=³h?Í˜k°T\Ì\ÓT\á	A\â*Æt\n\Ù^J\Ä1”ñ÷q¿¤\Z)	P\Ô\ã	\íVŒ qü	A[‰º‡ ±–r\è\è¯öQ\Ð=\0§[2Zzü0	Bq3\'«¸\Èk\íiT\Úy’\Ç$A¶º\×ñ½’¨\Ê\çªf ­\re…­¹O¦~H\rý¨®i·l-:…°±KZ\Ã\É#¼\Z¯6)þ^\ÝSK£	\í\Õ\Ò`¨&“5Ÿú@mk\Å´Ò¶%\ëv\Â=.Ø¯\Õ\×V¹\ì•W\àC \×\à	%÷uHd\ä\×r\ÄGW²r½R\"5r¦õhMŒY*\Úß©=\Ã$~V¯\ä(\â+)‹’7\åõL\Ú\âƒj)<\Ñ\í#%´S©Ü†\Z4[—D„\Ö\Ì\åe\Ë8Pa\ÂN4q@³ÏŒ¥k…¤‚j\íÔ¨‡ö}\àLA°½®\Ä\år_\Âfpðv¾\áÛ«:²/%1\Â=Lq3G£GRF—´\â\Î\Â\ÃÀ‡À*«\Ý\Ð)o\Ê4Öª«\rnV CÉ½T|?™Š±šˆªþH#Qs\ï\Â\Ý*5$Œu{\Ò\èS\ÓnNô­™Á6c‚Zy_]$T`»\Ô\ÖCŸ´“±\çJE\èõšx‹I¢—‰3p¸[9ù*ycœ l\Ù<¹[¤B\ÒJI;\È(ò;\Ôq€\çJ¬W:>j~š\ã\ÏBð\ÄÐ\î\"ÁSÙž8[Ú#HJ.f7$ª ™\É\éµh¾Gg%‰mO¨\ÕÈ I\ìs‹óJ\áq\Ú-Kz0­c\æ\0`^j¦“€HT!ôôsŠ\"xS\Ã\Ü`[ò\ËC½vX\ìi	Ù½)6\ËBT\\¸À-\å°\îe\áPUòY\ÇN\á	1A%\ÑÁ\Øâ©™”	!ò&ª\Ò\á\Ø\î¡Az	®u­ž$Ü«Z\"’ 6´—„\ïVñ\Äx¸\Úð(U5üQ}gÆº1Ø†f¬•4\Ôm´‡1\ÝU\Ì:t5KÕJªºð®\Âüø\Þ*‹´„üJŸbPà¢Š®\ìô\åœ\ßy\Åó#&vþ?\ÔÑ¬B±^„¦6\Ä5•\rò´’±À\Üv!bV„‰ƒŒfU|£SM˜F\ÎT¤^Iz©m¡­³\Zcd‰	\É)I¢‰Qx--{C\àl\Ö8%d÷Jh\ÈkýžHƒ‘ªþšÀ$H:&^#&«˜7¨l­ã½Š0u*§~²€‰.Š‡þµ¼\"\Ë8ß\È\nCdQýyhñW\åZÿ5¦ZP\Ü(H?–R·\àË±ûŠ\"©%5Š¶„B•¢\âh\0\ßp°D¨‰‚Ž±=?\Ç\ÔN%õ=\r\×S1Â˜Q*›&•„Œ•K\í)V\ÈJ*•\\1EC\ÙOz ñ[e(\ÓOU¶A=´¹AOð¬P§\Å8@°ƒR@trª˜²©V/õNtge­ÿ—\rÿ`\ì:*\ÙÁuAd\ËÛ•\r\n†/\Éq\Ì TÔ—œó	Ë”¤$‘o—\Õ\éœ()\É|ƒp‘K\ë\ÈId¢\Ãc\Â2œð¹\áòŽQþn¢\æüqµn\É\ÏÄŠ÷…$iÓ«\Ò\ÒhE\Óe\Êd¶ú»\Ôh„\Ä4\Â\Ä`_è¹¡þë‰®9\çþ­1·\Ô\\\çTˆ\\¢ƒ5 \ÉT\êd5¬\0|\ÂiS†Ä£\Èn1Í¸i–sÕŠ@ƒ\å+\ÒO\Þ[ÙšY*õS«¤ØŽgBmMô¡dnù¾RýZ†+\Þ\Õ`C§2\ãý¨»?f\î\é\0¸§úÏ«[&&\ìN\Z63#{\ÚFH[‚,¤ˆŽ\Â0qT	O\r	ÕŠ\Ó?Žœ§+#	g¢\Ô$Q\n¬42I\Ó5\ì\ÛD r\ÅÇ†y¦\ÓBµ!\×zj¡¶±_\êÙŠD3I„I\ë0ý\Ì1!Š|€º€\æ\Ú\Ùi¾\Z}TÀ.¤8WP¸ • E\\\ì\Ã^õ«¡Ô\ìør-Ÿ¯ \Í4\"om¨€ð›­ôo´W§ž2PHBÇ¹1I¤nœBªKÐš\Û\r\èpõ\ä§>³•(Md\Õs=\rI€\Èd•\Zž¶…†\Ñc\ä_TŒ“L¶\íA›\Ú\'‚µ\ã\ëªqWö1X%¨ˆS´x°sø˜+~_”=YK°6	–¯\î\Ôñ€¢`º†‡\çj <Sq½µdû3Š\ã˜/y\Õ$œ $S%³i˜oŠ\ÓRKT2‰˜&öºYj¨º\Þ3¡“‚)\Üg‚»\Ìqž0S\ìA7JÊˆ\Ï\\‡’\Ç\Ø\î¥]&±ºÖ¿pü¡\Å«\×z÷\âek*`X®J\äTi\è\í\Ú\àiK8»^pR”U9¡ .I\Ó*G%IH\ÙXâ½!ô|ODš¶Aw#Ä¬k*\Çù¡\ÒiMd†œ\ßúYªIÂ¦·¢Tµ_…f²%\"ÿ®¿m-\Z1\ÜóB\ËþqJ˜³¶\áf\Ç8	\ÆbYu\Â\rKJ\Ò\î\Õo\çô¢û|tÁ\Ò=˜ð\ÒZI0v\â\Â\áø9‹6F¦‘\\\ÇX„8%{ˆ)O\0I¶\\¿#\Ô\Ï(Q…²pè†† ¸ú©jWˆL\Äø3À|3«\Õzú¯9Ž2šñax^\á•\Õ\r§k`E\ä¿\é\rõÿ\Ú~ž;c™FP\Ã^VnhŒ™\Ð!a<ñt\èxe\Õ\Ã)…‡L8\îb=A¼\î”Bæ«¸ $C\'¸¯Ê³,+¯û8Fd•–Û“f:ùW¼W{¢•\Ô3i/&\Þ}›\Ãj¹Š\ËÛ•U¾¯\é\Í\rÇ·f-;\ì\r\Ýÿ\Ýl\îCÌ€¿ñ@÷¿4\ß\Ûø‹ós†\Ö=	\É\Ìo‚76=\Ì5ú3Wõižyós\Ýô˜9\ØÀ°ŠÇ½3\ä“\í”#ÿôÏ¤}Ž3ÏŠƒ(\Îñü.ž¡‡\ìŽ\â7\áû›™£~\Þvšª†M^w\æñwJ¼\îÁ¿\ãñC\Û\ã\ßVü\Û\Êðm=úŽ\Ço6?7^T¯ª\ÝÉ—i\ZþM˜Ÿ#\è¢9`.þhLüó÷00oþû?\ÆÌ£›w\Ç3\Ô0·t\å>wýÿ/v$\Ð\ÕM¾õ_yóósÐ’$t i\ÞûÐ·\Í\É{\Ì\è¦\Ço\Z¼\×q¶X‰Ÿ~\Â\íÏ®\Ñzú÷\Ø÷\È>þ\æ\n+wLp46\Ã5}<¿‡\çðfÀAb~3´_i–‡<	\r›ˆ¸\Íð·Vý6\r¤\Ïmma&\ÄvLó3\à\ç\â\Óö4¾Ÿ3“Ï÷úM\Ù~ôŽg\ã\í@ \ìO	ÿt¨\Ûoò\Ç\ÍGn[¸ør»ý}<sbCAG\Ò\ï†[ZM!CðT(¢úª4b\å\ÍÙ–\åôA\á\äj>~\Ð\ï?…û\íN~-ç¼‚:šp&f¦Ó˜P½{–»9Û€\ên\×^´IH£®$a† \ã„*oj|õn–ôŽ®±dž¸6\ØBmy§XH\×\ï\ÚA#`bŠ¾¡w\Æ\Õ*–\"\Ê\ÜP9¿¸‹€?€ž\Æþ\âYž,\ã\ì‚ -K\ÅÏ ¬¢!\×\×HFü$„É…êµ£\Óùƒif­²^žP\Ô\Ú\Ç÷4>W1XT\ï™el?§`¦Šø?\Úø\Ç?õ|V\Þñ?b\Ä0O\ãÇ¹ñC‚®5\Ì\ß\ãÁ\Ï\ã½Ÿñ}\ÉÀM(\×\Õó?\Üù=Z‹\Ü\âß†?ü\ç˜{z´žúŸ\èþýŸ\â™\ïqâž„\ßûC\Ï\0À{V7=\ç7•›@\ç$s3>ª±Z@š\ê¤ùúa@¥6=$•ó\ï7A>$°©¨÷õwós0o¿\é\é­+ûŒa\ï\î\åúfy\áwÿhø›ÓÙ±6û\Õvg”.4¼¡¦wWe¥+\ç4fl\Ë:\0kr\ÒS•w\×ns\îc)´„\ÎWútPN‹ððƒ)\íŸ\ïÀ}\è÷\Ñ§3\ç\Ån¢:\ç„R39±g›\Ó¦k¦«”\î\Õ}3ï™•gƒ±\Û\É\ï\Ëh“¨…~¿$µ	\âùþñký?£\Êš\îÃŽü¥Íº\åŠii¼ª“:÷\ÖTu\\P\å\Âk\ÒMqª¬•C\å\ÄjA\ïŸôÑ¯]ŒpoÊ©£)\Í&rpg½ò<Jg55¦^&\ë‘\"b˜Dl\Â\îˆS]»\í=~\Æ\ç\æK\Ç\ïe¥ú\Z\×iÙœ\á?ªòÎ¬>\ì(AO\ì\È/¿•ÿ4bž\æ\Í\äâº«\ç<\0œ\Å\ïEt*\Î£µ,ùs]v•‹\ÍüZloQ„\ã\"œüxKN¡€\ìWú\Ò$Àc¹``9~\ê$’™õv\ï	\Þ\ïý•ó@”¾F\ì“DJ—\"ô®¤\Ç\ß\ZüpgVS;JPÿVñ¯Šu\ršŽsPNˆ™ùW\ß3–´\ãÀq0Tô¢\ãYHð°ª\Ê3\Îñ\ÄWû¬~!‡›@ý\Ç\ã\Æ<\å3^y€ BÈ½\â\â\ä\â‚÷}¿\Ä ˜­’UBù.¤®\á3‰» vKº§\Å^\íH¨D;•\á­\â¹B\ÑõIÏ¥$¨W)T\Î\Î3\êÀÀ™ƒm–[°¼¦õ¼ü]ÁÀ«\í6Ë¦¨‡3¯\ç<\ï&\í\ÜÎ«rT,Gˆ\ÒS5»Um³ž{7ˆjj|mU£>ñ]x9NJ”‚mñÇŸ¾6\Ø\ÖùÜ…\r\â\çu\ä|¨\Ýj&òª¢tAÐq\\\Ô4ªÁý?¿Že<¼\ì!K:\ï!oö\Äú€§¾‘Ó¿¤<s(£ÿP6¡rÏ«bExE=B†\Ý5RB[­\Ôƒ	\â\Ôýœv±ƒ´8\r\ëŸr§¸¡‚Wž¸ÿún\í\ï5F=ô‡E,\ÜH‘–’´ƒ›¢(”\áÁb’º8°\êXU…ƒu\0‡EXQ\å\âú\0¤\ÃI+|zc=‰mŸ:\Î¬…¦\Ïl\Óm%¿‘³ª\ãz\ì\ç5H\å²\Ëq\Þj‘*IŸ°e\Ôû´9\Í9\Þiµ\è|p´Š\Æ3lL¨\Æz\î?}·¶w” {\n¯{\n¯ôU\éú%…WŠwƒ>-†J®\Ê@ò™º?™\àr\ë\áD,\éº\0³\í\Ð.Ack–¯õyfAxva«¶XQåª‡¶*+uuOI\á\ËM\àØœ\0[ž\Ü NjÆ“s¯†J¡°l\í/Ý­\Ím\ÐÉ,¾j\ß\ê™\æŽT„W[‚\î\ï CG~£·¥«¡\î:xd\ËFH\Z+\æV^tDøV\Ûò“kƒº2	w!ª\0}?­~„E˜ãœ‡\'$J”1TRe±w\Å0Û™\Æ\"<\Ùj\áÁ´*¬\Ò>_ºm\é°m&¡‚Ÿš\ã·ü;º§J:¯ô7=ÿôŽ²¦Cž\Øÿ,`0\ß²oö\Î\Ò9Hc6û–‡‹\ïùw†\èt\ã\è3¿ãƒ›³¾\é\éW\Ñ6Œ™wƒ»È¾66¡e@7…fnf°iX\Ùôœš3\\÷o\Ù½\Çã™Ÿ›\Ç\ì*ºý˜7\áVL‡*k?!¤Nß¸£ÿóûf§sg¥Ñµ¶&«À_¢‹ÀGº\èC‹\Ðx\éý]œŒ½¾\ã6\ã‹^ù\"\Ê@•e\àÙ–%×\\<½\Ðnôü.8h^3,\ÂÛŽkqbÜ…`ž”0_õi\r³ºâ•¾‡“±¾;×’Ü—[\ÖaV\ÆoZN\'û¯õ÷Õ¿\0özØ¥ö—X‘º<)–«z8û\Ü\ìÂŒ¿œÿ\Æyž8úm„*§M\èø\Â\Îz·5\0žFRó»»ô\Üb¨g­\åy\çj9\à%uœhY\Î\rC%÷SCeI\à¸Ž9\Ç9kc!bÉ ñ1Q\rV\Å(\rª¬˜˜e\ê+\Ø\íºV°—\é\Äñ\ï\äú\ïhƒ.\ïïŽ´\ÊÁ\èƒ£PO!\ì\ïÐ¿xaG\Õ\àa\Ïü¾¼\Ð\á\Ó}\ÚFx8JÙ‘X?·2T\Î\ëT\\\Ôðg~Oƒs[–²~\Ó‹Ó»Ö£\íA,E¦:þR÷ú7úõJ\Ç÷4\Â«Êž)8*\Â2B\'®\0W_\Ò÷\Ê)UºSD\Ó\Ú	L\Ü÷Ê“gÁ\Z¡Ó²d\ÚùÉµþ¶t\ØQ‚D\Æ\Ó\Ï!\Ðl¬¥ó Ã¢\æ\ÐÁ†GH$Á¶\ìx±¯¢(H³Œ%.z\åh\Ë2ø\ÌS¼ò‹§Yüù§9ÿK_œ\è\ÃrK\È=ôš1˜g[m^\Z:ú\rd@ŒM†\Ê\áÇ–é½µ\n\"€vc´^_!\ët¨7ˆ–ZÁºÉ¥Š\Õó6\Â¯œ\Z:Ž{\åE#œ±Nsø\é\ã%TUyÖ¹¯«§\Î\Ç+¼T\É\Ív\\>\Ø]¾·;º|0¼\Î\Ùö\èY‘&¼d¡=\Êo£\Ñh4*n££Ÿzr„a\âõÂ¯yT\Þ.GMxù•—G\Ï.´GÀ\èi\Û}·ÿ\Ý\Ñ\Óÿ\ãÓ£\Ñh4º|\éò\èò\ê\Õ\Ñ\å\ÕË£“¿ðô\È.´GGZvt\Â\Ú„6;FFÀ\È.\Ø\Ñw¯w¢mDFÒ’Qû`gô\Ý~>Zzty´\äy1Zü\È\âHDFOZ;\Â0:ú‰££/ÿ\æ¹\Ñ\Õ+WGW¯\\}\ë£3¿|f„‘Q[ddEF\"2zv¡=²\"£Ë«—Cc\ïŽF£²•e9*‹bT\äùHZ2Zj…¾.\Â\èi#£g[2:\×n^\Ý\ß½º¿3ú`º·»yù\Þ\î\è\ÂÁ\î\è\Âþ\îè…–l eGyž\×zò§ŸÈ«~C@‘†Ñ’„\Î\ïÞ¸0BdôdËŽN\Úöˆ\íUHB¤A€t3-~diÔL··Ëš8ˆŒ¾ü›_žxv	T\Å\è»×¿;êˆŒFb\"qDFg¬k·G/·;£s\íö]	´›T\Ï\ä\ç-\ßM{÷[\Í\Þó\ÃO·Ú¼ôõW¶üvQ•¾ô\ÂN\Ý`\éo-ñòK\ç\0\êbü¦‚vÎ…W5eÞœõ$¨¼f¾¯º¾\Ú¦\çaé£‹;öÃ¶±6d2€\ãŸ8^?G\ã\î(ªJ±Qpñ\ÒENZ‹\Z8BÜ¼£Q®õ\Ö\0¾µ¿³y\á`gô­ý\Ñ\Ë\íö\èY#£4$Hd‹nKPó\ï&\×c]¸t¹þü\Ý\ë\ß\Ù;¡_þ\í—\'8¸úþË¿>\æ\Ü~ýË“ju†a\Ùv{ü¬þw£š÷T\êµ\Z\Ç\âG—Fˆui\í\èÉŸ9Qÿ^\Þ.G‹]\ZýÔ“\ã{Šb$-©\ï©L@\Õþi‘Ñ™–½°\Ð½°\Ð}9¾^j~[\'ag	b¼wÀn ûŽ¿˜rCš\ëf\0–>¸\Ö9G\ÒJp\ÎqÚ¶9·\Ð\á\Û\æ\Ø\'qñÛ«õõ\Õ6.<ø@ý]¯²gl›3¶½ËžŽL8õùS\ák\Ý\Å.«\ßY¥øT‡\ÑK\Ë\\]L\é¼þ2½ýZ\"òxý\\\0k-Å­¢n\ã\ÂÁ¯\îo\Ò!Ñµ®ž§\×\Ý\à=©¸\Ýi\Â\Ù|Š*œø\Ù´.£\ß\èó”°\Ü^øÒ™úº\î‡A¥µÕ­\Æ\rx\Æ\ÍN\Ù3»\Æt¢e\Ç\Õ7^O[Ë±o\ä¬|\î2ß½\Ì\é~Nú3?\ÉOf)§Ÿ;]H\é]\ëñ\Ôgžª\Ç*F(‹‚²(8\ê•\'\Öû,6U\Úûð\Øv\Î$˜†\Ý\Ù\î\Û}ÿ>“ +\Ã\Ý\Ê\ëlx¿LÒ„ó\êøòb\Êòo\í£ÿ\ä	¿UpA\ÇÒ¶l„ÿ\ÉÙ™\Ï\è­^\æ\äÏ$3\Ò\Ø<\ã½3ü®j\ZplMù19\í]ÿ5É±G\Är\äñ#\ãx\è.\àT·$S\Þ7l\Ë$³\Ís­\ÏÕ‡2®þ\êa:/†|•S\Ý#$Ÿ¹À\å~Ÿòv=q@\Ç\Ë\"\ìÙ›pñ\Í\Õ-5}§¿pš œö.D\Úõ\0w\'\ÓnŠ’F4m\Ð,Žœõ]#-³d„\ÌÀ©/œ\Ú\Å\ãÂ½\'g­\rý\ÂVoó\â\ï_\äÜ£‡\é>·Ÿxý\ÚÜ¯õù\âÀaM°3Ó°\â•\Ó6\ãð#‡9ö\äñ\É	M`ù\Ñe\Ûeúû­°7H]\0q7ð FY4aš¡m„‹ªt>wŠ¥.Õ—\r\Ö„m·-Oÿü\Ód&ûgl\ÊrË²2Tžxü‰úº\Þ[Áaø –µ-\Ö\n/\Ø6™–÷¥´\á8§¿¾7ú\èçž§ó\Ù\é}–…‰Ì‚·‘ó¤M\à´\ËBv\"Ù—q®N,?r8üa ÿ>ú¹sª§m\Ñõ<®\î\Ö\É\\n3ñ`l«\Ü\rG\Ö\É8Ú²{òx}\Ïòc\Ë\\¸U\à†Ž£÷u8¿?\ãò+/³üh¨\×\é]\ëoñw\âa°1v D„Ë«=Ž=²È‹žý|\0}¥\ÇS_\É9\ë”\ï^¿Jg\ç\ÜD®±w£\Ç3Ÿ?E8ü\Èa¾õ»\ß\Z\Ç[e—\0g~y\ì\àTŽŠL­­½\ì,Ai¶\Íï‡{\×údR\Ú\ç\Õñ\ÊW_båµ•q«-¡\ÝnÓ‹~\é«/Á6€Ž½¢÷\ËS¶o°>`õ\â\Îw–>V³k_q\ßP\Î:¥{o‡\ÎÁN˜^iG‡\ÊñŸ9\î\á\Ìsg¦Õ¸¶`°²\ç\0c¬I\ãÿ»Á®ü¬±ô„P\Z=ú\Ú\Ün£Oƒ¥‡Oÿ\ìqV^_\áˆ\Ø:[}\ÒZŽùI^üg\ç8òøl\Ì\Ë\ç_\åô\'a¿þ2§tø\â/žž(\Æ\èõzõz\Ùbª\"H\Õ7Ç±“\Þ.xe\èxa¡\Í>À¹¯œCþ\Þ1Ž|R\àA¯+zQYY+96pîŸ½\Ì\ÑOß¯ \ê(6\nžøø,\n2\ÜgNÐ½¿;–\êˆ\'*…+x\ês\Ïðt\Ëò¼°T\ï¥¦n&*~`\ÛtÏ®a\Ù|\Ê\Øð\å¤Sq¹*\ÅP¹ø\Æ\ng~õù›=žnµy~8 K˜Gyq\è8!–\ã\ç8{»\\xmŒ\Ð\étX*g÷g<üNa“­6_ÀÀ±O»Ë¤¦òð¡‡§úOm\ç_\æô:¡\ï\×À™_\Üc\È\×ûôoôHm\Ð\"Ð¿\Ñ\ç\á¥Ã=w`ù\Þ\î#\0”eImÀ§ÿþ	ðÊ…øýñ)\ÉO€]š\í<ô\ìÁÎ·3Wþ\Íj\ÕB>T\n”\ç\ã\ÜÍ“\Í\Í!¦PR¹”Ö„ÂATQ\'MXa\×ó\Êy 	\Ý¡sVýû;¬¾¹JñX—•+ø„c\ï\ÇÌŽ\áhK8÷ù°7\×\Ã3W\ßPŽrú\Í\Ú\ï–\r3ªSsP\ç5Lò-ŠÐ©.žb’¸\ë/\r\Çy‚£bY&HO(Ip”\ä>„-§6¶¯I\ØQ‚’– Ã²\Þ²Ú“-#x%/©\Î Œ‹\ê•j…õ¶M\Õ@\"B¦°ä•Ž‡=¯aM«‡gŽ^tB–\Û	\Ëo\å3ž±{xaÁrücY\èSA{Ê‘õ<”?5\àl­\r¦mDø¼\ê•Zn¶¨õÉ¶NŠ\å\È\'Žs…Ä³uß¢`g/\î@E\Ì#%tRðÊ™¨Ú‚òcUQbJµ\r±l%ž<Ò¬#ÐŽ{¾-Å¥\è}à¼\ç}N\Ù6ùÍ‚Îƒ)n-\ÖgoMŽoÀ\Ó–gSÚŸ°\è¸¨\è@9q¥\à•Õ¬g\Ì\Ô\î%„œ#\ä\ê\ê½òšansq\Û)pø\ï§^»k:½…\0\Ä7\×Ml;¨w½wùˆIþff\ï·S!\ÞË˜ƒš£j¨†Y(\Íb)n\á\\\\•×‘\à^9\â\Ã\ì\ã)7 c,E8Ú‚\çï¦´gŒ¤c…SŸÈ°‡\Ý Ø››J\á˜Iœ“b\É¬T‹\ÃT\è\Æm\ßÌ°l$ËÒ’~\"\Ã.=\Ì\àó§jd\Ôñ\ä.Ò€R&\ç\0\0 \0IDATP;\È\èl\Ò\ëKvk\ä˜©U	\ï1\ï•\Z nÀ\Ð6‚h \ÒùøœTYZSN-fô†\Êù»IQ\Õg#¼\ØžüRLŠ~»« }%}k¶;\'m\Ä\æÙ’/hH@f˜\\V3‹!¿tŸ_›œK¢£Q;[w\ã \ÖTG¶/›\ì\ì.¡2š\ÏZ2£¨\ï\ÃB\'Y\n\êj\Û\ç6\à\ÂýG?Û\ÅÃ89¸¾ò\Ìú´EP/ˆU;;¡k»ˆ8¬ª\ÑvŠ„v$P/\Ï/\ÕMU»\É×„jd\îF¼ 5µb¤\Þk´òFx\Å9dÁrø)‹\îL\ÞÜ\ÜW,\å\Ïu\é¾ñ4ò3\'Ð¯œG_WV¿Y½\Õ\çlCúž4B\×ÀY±dF\èHBº£¿:w3öXº&I‹]\ál\ç\Ú\ìZ”\ïž\Åþ 0¡ó	4@¨-ƒ\à„t-:(¶\Þl„£-aùó\ä3G\0‹\ç¡\ç¯ß˜´7#Œp\ÊØÝµgµ³mK\ÂHœz]U$\ÔN{³\îˆbm¼‹÷\ÎÑ¸b˜\Ø{\íýC\ã- 	nü²	« .[‹»\â°O.s\Îôi† \Ë\"¼ús\ä\ïûO€ï¡¿v\n®Ã©oôy~c©\ç\ÄBœ£“4¶OKc\rÔ†#óGÕšl8,\Û0\î°%hD´˜\èiZAc˜Å¹­š8-A(\Þ\ÕI›¾\r\ì(A—¿sñR\íTúH˜D\ÂK„ñúÑ»\î•_ñ`­\Ô\ÜP¹ü\ÍnöYüB†mY[Bñ©.\ßzýò\ÜUøð)x\í)ô\×Nqþ\×sŽ}µ7Aœ£b9\'k„¶IHe+q\0ø\Ù\ãœ\Ý\È9\ïýÇ—¹0,X^½\ÌÊ”W}A\î•~\ã,¯r\Î^\ë\Ñ\ïfœsGV/\Óy\î4‡/­ÀgO\Âc\Ë¹x™\"D\Ò\n/\Ù\Þ]\ÈÝ¥w\Ó\rR{\ë!÷5\Õ\àPÍ\É\Þ_©$•þPÑµ»œ8k-ö¹Sð‘3„`ø2úfŽªpf\à8?\å‹‹c©³*zø\Ã]’õ\ïo\Ó_\ï\ãô¾þ/^&\év\0Wû}dcÀ±V›\ÃKKœ½´\nF\è¿q±mÜ•Ùƒƒ9\Ëz\n ‘Z\ÅUÒ³\Ó:\Ú]My\ã;ŠTT7Œ\ç¼\ÌÎºtW\Ðt>€\å\Z/zGÿ›>r–oœd±ß‡ö“\áÚ¯.\ã>û§ž\ëqø—{\\T &cŸ®$G‚#°“\×\Ôþ\ØQ:\"tŽ<Aÿõc…ó—.s\ä\ï\à\ÉO\'?\Ø&³–#¿|±)\Ù\'ŽóL\'\ä\ì\ÎÿÆ‹\0t:\ÝÇ–YùúË¤Qr\Ø+5±Ô€\Î$ã³¶\ÝÌ¨ú\Æÿc¨½·\Ø\äô–g4\ësú^\è\ß\nûiq\ïijp¯0øÚ€¾\Â+XzSvüa‚3š‰\à\Öú´°–´m±ô~\éyŠ_y]\È\Ðõ>Y·\ËÃee#G†ŽŽ\Ü[=úNq7zdÁ\rr\Î?÷Å±\äL9À®´ÏŽ\ÉR+ò\ã§[¶\ß1Éž\Ô@»\Û@›\'¬ÿW§\ã\Ù\Þæƒ·\ÌÁ\ßr-q>lŠð\é(	Ò²œ\Äq\æ\ÖwÁW[¿ð\0«\ß(8½>`Eeb2O.t[\ÒÙ¶f\n\Ô@±´Šd\ÞXE»¤—z\\m[R§Á~<&õ\Ü\ÅU\äÁ.bÃ¡¬®Â¡Pm¤—V\ÃF6¥³\Þ«93^¶\Ó_WŠ\ÒûýP<¿\Þg@ú~¡m„A\Üµo€õ8x\Þ|žÞ·•Ë¢[ˆcN‹\Ô\Ù\ã\Ý@þ`‡£¿ý2\î\ÍU\Î|s™\Ó/ã¥¬\Ë\áOž\àü/Ÿ!û\ïO²ü±c\0œy,ü\înÄ¬Ä°€V\ØøðÅ-óô—^Å­‡\Ù\ÛŸ?J×¤“ñc“aw`\Þ]u¿>\Ä	\Â&ª&º\Û\ï\îÆ½®\Êôv	Ñ€WK%O	[\Èx\å‚X\Ü/>O±þEV.\åœ\Z÷ó·\ß6\Âó&§³ƒ‡Ô„#¿ð4¨²ò\è~tZ–\'o‡\ÌÃ‹_8\ÅÓ¿ð´,¨rx\é0´,ö¡E\ÎÿÆ‹,\êD½·\ëÒ¡‡‘…»q\á\ë¯\Ðmo%ŽB\Üy¤¤\Ú\0þ.\è¸;ˆ\áG¨T¡\È02>\áŽœh|†BŸ°$¤±`eÝ±\â•ÁstŒðl$\Î\îƒ\ÏK\Ë\èµI(\ÚÁ\è?µø\0/¼v\Ìˆ\å\Óihó\ÄÏœ\à\ÓûJ…ü¹\ç\éhsz\å\Úm<u_B\é\áÔ£­ƒŠH»Pý»\Ù\È\â\Ó-ûoÒ¸R;«öm1¹¾¥iƒht¨Q@±PEµùE\ãû\Ê0ð²m\ã\Z \Ö„\Ì@ö$§‚þcK\èBJ±O”ôJ²\ÚC?B\ï\ë¯\Ðýø‘Ð·A¨\àI\"W¾zŽ\åŸôÅµˆ\r‡zXyýež>”Ö¸‡‡„”7\ÃA%‰I8þ\Ö´AÃ­¤H\Ã\áO\ÛzF\Û\Ì\Ï\ì¦š+	\Õ\Û{Yl\Ø\"~\'Ž\áHœ·\Ù9Ÿ¶\r|c…\Ë\Ãx8l\Û\\8¶\Ða\åW^d\Éf\\ü•³TKÕ–m›.L½·põ+g\Ã.V\Ë÷e¬¼vžÒ„)‘\ê\\[Æ•¥~\Üÿ] c˜1c¨*ˆQ \é¦yšPª\Íø\êž6kÎ´,=RB\ïWr*\èHBG:\Ï\á\ï#\á\Î#í°£Iú™\'„Î—Î‘~\æxH \ß\ìC·ƒ,tÐµËœð\n½\Ð÷[ýx¦Cªa#Y-\ãIdwŸ´\Û9šROZ}\ç\Çï»©\ÒO0¥¯ñlYºóiKðÁ$\ç=€Vÿ	°\ßB\ÛR^¹L¹Ñ‡´}\ÏWa¡3v¢\Z¯R	g»F¦\ÞiÃ§mÐ‘.ý\Ý\ãkýÿ£\Úr²J“Ô§“T¡ðPgS\Él]r²(Pøñ¾\Ò<—\Ê9ž”\ÊTk»…\È0Rýs¤qø6N4QO•Œg+\é0\à¡(‚®¬CüôúÖ½J§½L\" ò@¶\Ô\"o÷¡þ‚:O‡!…6Q\å}Yl½\Ó\ân³š‚k	\Ç\Ùð{\Ò\Üf5^_\Æcj\ÐXW7TÊ²\"TY¯Ù‰uß³Š›(R¬^?H¦\Þ_õ\Êi±¤ºò*¨`¦þ®\Ò5I”3\Þ\â2\\#\ã:\éWIM°ò=\àmG	\ê\È\ÉzcÂ«ö\Îtò \Ù„ƒ\ÊÃ³N˜°Gi\å4\Ã\ß:¡ª‰5+8QMÎŠJm“+£¬\Zs¶^)‡\Õw\å˜8?	\ÚE‘\ÆLcúÁ\ÂüÿAjfôC¦%§‘[g\ßuBB´òœ¼†3:”\æ‹?8	’¢¸ûB™…{\ï[\î6\æqªß›\ï³\îõ\Û{\îQS¥U6§’œ&„†WK8\ÐhsjiŠ¸z/\É\ã	”e\é½\Z\ÇHF˜ðû\rJ\Ð$Lõœ\êBÈ\îõ÷\Ìö {L°h!ô\ËÍžJiN$û2=]\0\êª~Õ‰KÛœ\é\ëw	;\×$\\\ï\Ï\ÌÀVY„úø±÷ð\àYÄ˜þ·C~¿.´û ¤A\éÆ§ŠEº ý>b \ëÁ½¥\ä«ñ\é\r\âT#U5“T[MŸÑŒo¨lÎ»•í‰ƒŠek±\ãN’½#¬‘›]{ýþ\àn*jÞ‹DF\æ°û}‚´•t)$MuUaC\Ãq›\×y´¦DZ%\ìMQ£\Ø\Çd’@Mõ•L}7\ã¹e\Ã1ˆ;\é\Öó`w\rD§›K\î\nN\ç/»+½‰i\ìw­óý\Ö-º¦m\É\"qc\íÇ…t¿B\Ük!\î\Ú\ÈzX€Åº\"‡lœy\ÜÂ†ƒU\rÞµ’`À7}\ØîºŽóŠ† •\ÉR©eS•U±\Î\íøyH½\Ñz_õ}3ps7x¹¸\ÝÀsj›\æ£zz²CÀB¬¤¡M B+Àƒh£FÁ¤°P\"÷uÐ›«a\Òè€„Œûõ~¨@a@B­QmK$N2.\ì\ØBœª\Ñ[“Jz*G r\Z\Zã™µ+þn`g\Ô\ïÏ´¥Ÿ:A÷½2^/ûA\"JúX\\½\é-zÅù™\ÃHV€\Ë\Ñ<\ä±d¿€w\è%\àš\Ã~a)º¾\n«ý€¨žC{=ú7\np\Ý4Z9\ÜTt-Œ\á\â9¥Ž%5µ’°—g•Î™@5QðÀ\í\Æg”šú?©ùÆ§h\Æ\ßw À\Î4Ô¯\ÚÆ‹\ÛN­µ²Em¥\n÷Jx–\í‡R_U¦\æn_WdŸ…X‹¤]²\è\íb\Ú\è•< vk°EŸ \ï–Hf!W\Ô	\å€8e}§u\æ<A\ê\Ýy·T)US«6D	ÿg§n‡#¦ðôƒ°AL%T›\Ñ{\éœ\0\ÌZ»,:¿\Z½  ÷faô\Ö…k½E „µYX\ï£×k\Ðs%\Ý6\Èc‚,ú ­\Þ\ÌQ\ÓG\ß\éý„2§t\è.\è\r-P»_Û ðò\ë}ò\Øg‹’\"´\ç«Rà±š®žT\Ç@Wö¦r ¤x\"&šaBõWuy\ÕnóÌ¥»ÁûŽ^šAaØ‘1v«!MvI\É”`»\Öú¥^[´_\ÐU\È/9ôV‰\Ì\'d\äñhE¯€\ì³h\Û\Ñm%\È!`Ô¸`9E\ÜtÚ‚ö•|£DZ\Þ\î‡}¡\ïÍ‚\ç\ÖN`-‡½\Ê¿‘‡‰¿z*¼´Ápc\' V&\Ýndnx\íNO1gITof¬\Ö\ÂuÒ°k	\Í\Ý)gÁ/gC\Õ\Õl)r\à@ \ïÐµ`sðuv3L“g–¢‰Xd	$µ\è\ÍX$÷_c8( ·\\‰\í\Ü \Ä*mK±\áH3C\È¬+I;\è\Í^8‚3§MÔ§\ÅWmvšÆ¾-dC›b÷—0pa²\Î\Ã\ê?r³õ¹\âžpõ\Ï\æ½9P\ïƒ@\ãy”p\Âû\ØÝžºt¿–\ë\í\à\ßQhA²\0öA¹Cö)…Uôf®®Ž\ÝW¹\ß\"™¢}G\ïZI§•\Ðþû\ËP\\%Ûˆ’°\ÜÀÁ\ÐZ)’\nZ\ä òá‚³¿\ÝCZ V\È,¤K·\rY– ^B€\ê½	ò`t\Ù[\Z‹4ó šUƒ)ºQ\Ðý„pù+ºÕ¾W\ã™\Ø^c^©¬ñ°½›\Ê\ÒqE\Ï‘¦ÿš\ëÁ\èK—X4.$\í@\àþ\Òv8…ø\æ*Z”a`V\Ð\\\ÑB‘ý½6Å½®\è,$HIC†:vö)´-(È½‚tq¥\"{ð9½¯\çNI-t\î>`Y:”\Ò}0Ã¶…\ê\0$½-È¡vð«³N½\ÂÁÅ ²MŠ\Þ\ÈÁr JD\Ã\Ð\Æ{C+N\àQ*5wØ…‰\Ñø÷øAñô÷f*f\Â+Qz¿)t?K\àl+H+\Z\Ùuû}«Gq%¬ip.›cô\Æ\ÕA…v {H‘\Ûa°,Yô¶\"óAz¤\çP?—z…ƒ\ÞR´µŠõ%\îõ:€•U2\ãZ2 \ÝJHo+²\ìWqc\É\ß\Z\Ð\í`#L\Ð\éMGööÁj(Vü\è\"’%\èk—ø2œ\Ül’:°u¾\"Î”þ«BŒ1ö°\Íf»Sq³\\ÁHŒ¦W7\rº¡ô¿	E©9`\ë6‹+1\rsÐ¢—jb 8„d?a-M\'C{9²w‚\Â}I3dôF­Ô‘€,¸^öG†pŠ:¢{\r,\é½\rGö Eq\è‰\ÛI°÷	\ê40IK‚ûÿ†\"iP}j *••—r\n¯¤^Bq,Ö§‘YP´rv€]h‚þS\é\nõ%˜$N\Þ\Å\ß|;§%W¿©¤\íp}$E9\" \Ó=\Ì\àw.\Ã\r‡<Þ†›\Ø¶Aº] û-ö^Á½™BôZù×”\ì>E7@W\Ãñ8h‚(¤¢`2\ä¨Wòµ’•\Þ \ÆIJ\×(Y[\à¡!C¿\ÚŽs¶­Š×‚îƒ\Z‚\×v\'d!´@JE_\ï“÷+oB†€µa‚|X\Ö4‘Teœ&ƒÝ…÷tˆ\åv\ç,WQ©¼…•o\äˆ(ºVo\ì\Ö  û\Ò\Øp”-\ã;È‚E\î³0\ìÃ‚}«s›À\ÍG¢Š»ˆSn³e XµÒ­E˜½½›ÁÈ‹‰  F‘Ô†À\Ö;™î—\ßÛˆ\ãm\Å\r\Ð[ ¦„V¥\")\è\Ðqö«ýq2µJ®\Î\ç‚—~kŠh†\â›	;§z€\ê\Ø\ÍY¿U±P\\¯’UU”\æ\ëð\ÊWúù\éI¢A_\rOÚu ±\n­\"xoo(ƒ÷U®…Á¦\Ûð´Á.µ\É/:tX0::b‘d QE=Ú‚bH:›¥aUz\Ðo^„\Î]\Ê9\ÞÉ°u\à@\í¯\Òy$JE\×Á„Ë¾0\Î\Ó\Ïâˆ…lAH[iˆ|\Ø5²\"F}D¨\ã…œ\à~ \í6\Ç\æ:’Xf5v¹+.\É\Ñ\rmrPÐ±l	\èX7B\ä/)øPk–.Z´\ç\Âý÷Å²«.Ã„TÊ Ó«©a|r)\èºru­„Û‘\âžw\Å\r\È\Üu¥¼\Ç\Í\à]Aµ€~o5ø\ÛO°E@\ïRQ\ÇNI,‡¶{#\èP’2~Ÿ&…zÝ±¢`\ç)o¶ß•I¦Þ©\íPI9c\é\ì/õcÏû,r\0¸O\ã }Xƒ\Â\Òl\\\åû•\ÞWúœ¿>\à\é\ç–po8\ä£ø¶#}¬½‚ì€’¿Q mû³€(\×c\åKùP‘,œG¾\Ô\ÍHF§\Å\nöÀØ»”}‚¾\é(zaZ\ÛvÛ‚|\ì0ø½ÞƒKp\æ+q+´V\Ð\0¶m\É\Òñ™ç½¼¤·®<R­\ìˆ\ÎR•D\Íw([Û¥Š›MœÊ\ß2\ï\ã«UÛ‚L<U÷\'W8\î5…—/\æy<.\Ì\Ú(\Ð\ë‚^¯—…’e)\'>\ÖE\ßr\äƒ^³\í2¨+²û“ ‡}Š\ë%ýoR\çÚ’¶Köa…7«‚\Ây¤„\×\ãœ‚2 À†\âzŠ½¸Cp«!AQMK$6l“¥I½\ÇC\è.$¸Á¤Y¨\æ\Ëj\ç`óÛº\Ù\ï\ÉI\æ\ËT¨+’‰«gÃ¹\ß\ÊaCƒJ\Ç?w˜\Ô*Ù£–\ÎO?@\é¡@Q@µõ¦t ¸¤0H\ê<™n¸Àõ«Š=\Ô	A\ãôô\Õ{±¤+\Èõ|\Çt[-zÑ‘_¼ 7\ØÀ~A—Á)¶G<¹\ÃóWòH\Ë0q$I\ã¸\ê˜JªJ\ÜiQeÊ«\×N\ÌvVq&<¬\é\ÌD}K\Æ2eMH­\êÅ¦žzö\ë9ËYþ\Ô\çq•šÀº\Ãõz%v_Bç‘Œ\ÄC¹\æ\Ð+}Ê’®DÈ½1\Û²!È’	ƒóŠj‰óŠ\ÜPX¼?!\í´\ÃJ¸Aö*º\Ú#¿®Õ¡ À(òP‚®®à®ƒÊý%\å…/¬Ö„IDh§µ¯1]PFGD|À\Ä +;dfž-þv\\¬ÌŠ`3ZH$ž(Õ Cð8‰¶S“*	:,B®Ëƒ\Þ\Ô0%qP°>xZauŸ’|D½&ò†„Ý«Ä¡¹\"„¾ê­œþ·‹\ÚSr\ëŠm\ÅS¯,°Ñ‡–EpÁ\Ó[‹‹JJE\Úa¤æ† „\Ð =¿ñ&ñ \'|8@q<+G\í$ˆIH}Iq\ÒH‚·ûmP£”r\Ì\È	a\Ã?h&J\Ç¬öŒ\ÓQ`\å\ë96ƒ’\Î!$Dõ\ÖÙ½E\ÐU¥ü\Ð\n1OúQ– ¹Pn€}Tv‚{c…ü’=ƒ<¼Ø¦{\Zú2g¬Ú‡¤»\Ã|\Ã!”aº|u\0m	+¬\âp\Åk§%\çó\àY&l–\Ô\Ûj ·C\åh\Ò Î¤ýIH	G›Jœ7\n´Tòp\Ýû— ‡Ž/{f\îƒ \ã¬\ìv•?bªù\"\Ö\èü…‹¶%tþ\É#‹yX\0÷UTDKHD\É>\ÕFCl® (´B~®¸nù††”\ÎRF¶_‘A´´½x†¥\ÄL¡­\r®v#ŸÖXu´LU¸?]7qv÷VT‘\Z‰«5‚9‡\à\Þ]‚vtŠþ|F#Uñ8^)§v “L¨µ\ÄÈ¶.C\ïMÅ­‡Ü”<¶Nq«a\ç\\\Ý\×ÿeZ\äP\åô+\Ú/À(Ù§:\è:\äý~I~K‘˜—\ËZ‚-A¯ƒÞªœ\Ð\ßï“¿\á\è¿ù-e°V —\Â*»\ÔÆ½®°l/´¤w;X¢ô¤&	Lw›0…»Aˆ½ªiñjp¾©0Ni\Ñ[¥ö\Þ>0\Î_¿ú¿Mœ\Å\Ý\n¯:Y:\Í1\Û¶\áÌ¶\Ùd\êúŠöV\Ñ[Jq\rä¡˜E^\0ûQA\îOƒö‚j#{¨®\0$\Î^*½µñ€ÓŽ\Ý\'\Øûö\n]ð\Ü\np*8W\"™P*È£c—„üA@¢´\é÷•þ-\ë™y\êú…\æ<\ÂNõA\Å®¼¶\é@~;\Øñ [wÇ»ÿ\Âð\ç…=ÙŸß‹Þ \ïxü`ü˜Mð›±›\0«5s\à\ãA¯Ì™‰\ß\0¼3gðWöpýF\Ép\è\á\Ý=$\Î\Óù¹.\éC\×W®°÷ŽR\\…}YÌŸ3ø?X\ëñ\ßSü\Ðó;ÿ\ç\0\ï=øÐŸ\á\Ûp¸›À†ÿjH\ë\Ç!¿8dc\ã6¥¿ñ}öþ¹y\æñl\\¸\Î\Æ(˜½d{Ü¿q\\ÿ÷\Êz5\ÉfÀ~HH7øO`†À\Ûc\"U³\Ú\Ò3…\Ë\êšù9Ã†÷l\Üñüwxi\è¶=\èv\ç@Uõmùpw\Äz¾GöY(bkcrj6LnšZ\Ï}T3°f\Òõn8´­¤-H\ïµ\È>E7z\à„\ÎG\Ã>\×iQ\ÄJQ	ý†Ò¿R7÷€©f37\×WÊ‹\ZK:$ôa\Z\Ü\àƒ0¸Qb[),„i	Tqo\n$Bû;\ë½K\ZñÍ¥$ÉŽ%TM\\”^\ÉZ2°n\Ýª›«ð¥·Ê¯‘0\ÝxS›ñ\ç±^®Ì•1Á\â\Ë\raõ†\Â\ì\ÞPÃ¦—ý&°\ÞÇ½\ÕG7ù\ÍÈ¶7ò>¬^›a\'³_\ï“~\Ü\ÒùGG‘{ñ\Ý[ýK·V\Ò>˜’u@†J¾\Ç\ÛAR/Q°^‚\Íqex\rË¸#}#ec¼w\ßp¶úmÑ¦\Ñq	¥”³`W™„\\õ²*\ãCúL#U1‹P\Ût(@Eœ\Ùö\ÈvR+\à]8\Ø#W\ä\0¸× ¸…\ni\ZR1®nªs:3÷P:¸ð\Õ>zý<rŠ\r\è\ß\nµp¶• k\nrP\ÅM\Ç\Õ7cm^h\Ó\îLÙœñ“+1I&\Ò\\\Õ¶J9²`if\çÙ…\rø»õ¯ý¯\Ý\ï\rÿ\Òpm}[ñ\ÞcZ‚1ƒ\Ç\ÏEý\Z;\í7\Íp€ù,ðs>\Ú,¿Å®öÿh\È\ßø\ë)òg\r\æ\Ç\ÃK¿\ç¹\í=ûöó^1]¸õ\Í!\×ÿe\É\à‡üë«“\é\Üa\Ã<\á\æš\ç>6nÄ’¬9Ãž=ódV¾c\Øøe°z›\Âyò?P®\åC®W\Ù\ÌMhÝ‘\ã¼¢	m/>¾\Ï5mP8´= ~Œ\n\'e´\Ó\ì©\×<¥w8ty\Îÿ\ÖðŽß²\ß\çŽ:ó\èò•«W?ªÞ£x²\î>’\Ô\â75\È\ß³FcO\Å ³\ç\0\æ#QÁ@ƒH•KÝ»¡üDkP†¡\ÝùV‹\Ûÿ~\È\Þ%¡øŠ\Â`0¤xGq\ß?(‰j€–¾¿\é™7p\åÆ\Î_1\ì¹þHÿô<{Ô°ñÿd÷\í¥ó\ß\îÁ›y\Ö{ž››î„\È0\ï\æ+\é\Ùýñ›\r\Åõ¯þ›kHK\Ã\ZŸa6&`27\Ç\ï\É\îp\ì\âý•i\\\í¬\â.]þ«u\ãò\ëŽâ–«{¤q‘Rp#Çºw{÷q35•\\3Ž*†J\ÑŠ”o)ÅºR~GI[aP\Ü`]ÁZ³\íF8\Ð*+5\Üë…¾†j›’\ÞjA13¬\î&¸k%Eµ¸¥\rMõ\Ç|W˜²½\Í\ï\ë©\îø½Smº\ßa»\æ¶k\íY\ØS¢õü…:Etl\Z6_õc?@\ä\Ódj&	«§73¾‡¼ò\Õ>G\É\è|Ä†)\Ð<G¯÷±ÝŒ\Ìô\Ñ+p~m\ÒöTmW‡\à\Ö\ÇEú\ÊÒ¡ÝˆiªC‚}¤\\ø\Å	:t\Ï\ÐS©]gL\Z0Ë¦L[\Ö\Ú*ù\Ék\Õ+}UJ\Â>\á¦¶L;\ÜUÅ¾¿óo\Å\r÷6U•\'ˆøðŽ2¯UT•\é®bG\ë•\çó\Í{§ž\á7Mm‹|c~\Ó\ã6”}{\ç\Ãbƒ\Ì#\ÎC\ê\ÑU\èÿ¡§·6d\Þöš‰ŒZ\Ê ÷û\È=#L –1ö@67Oòc ª…9°®9®¯*½\ÍaP\Ùw<\æŽ`4\ÄSø`a\æ\Ù¶‹Û«\ï+|\é¦\Çy\ÏpÓ“š \'\×a\Åyÿ\ïš\ím+A\Ï~¸û/\åFžU\æ\×FnL:\Ýe©¡Œ\Öm\Ý\ÇZ§vªº[qcµ±JØˆ¯™ûV@ö\Û\à\Ê.\Ä\Ý@¸¼\æpe9^4V¹\î1ÃŒ\ÐXx§\á\çC?r\0+<,‚JqWrŠ ûR\ä]À•µT\Ë\×n¯\æ½\Þ4=Ì¦\n$HfO½<jø\í\ç\á/\0ß¯.\ßV‚~\êÿk\Þó!66=‚9\ÏÞ…½˜´…¾=DßŽžA|^%E··ñÞ¦!1\Â\Þ\ÝK\"I\èó\\œ\Ú;Ú„þUGú§÷<\Þn\Ï3ø7\×u¼2fÌœ\Ç\Ì\æ\ç\æÁ\Ä\ì†\î\æÁ\Ç\ï\0†C\ÏOü¹P‘ÿ\Üúžr³÷\ÍyDö¶\Âk\Ï=	ó<6£6xÓœ`Î…9Álz†x‚\ã\ß÷F\Ò\Z3!E\Û\îs\á\ãË£¼ŸS¬G	iAVV	¸\ëQ¶t,\Õê²™\ë2\\—\Út’}\à\Ï\ê(¶`\ï´1B°VH[\ãh³>†Y\â²I\Æû\ÌS—\à–ô\Ý)yn:•s\0@R/i\Ö\\¨Bó•\á¿\Ôvµ‘yI\äÿk\íjB\ä:Žð·\ÊÛ¸Œ _²‡÷@†¬ƒFQÀ;°|ˆ@‚„Œ}JL>\ç˜[\Îñ5\'\'\×}sN9œƒ@(h$4\"Y˜/\Ì@6y<\äV+Î¡ºº«û½™]‹4\ì\Î\Ìû\é®\îêª®ª®®2h‰°\è8ö¯\r\rs’ÿvC\ß¶´\Ø\Ã)\ê[3P\×zI\Ígyÿ¬ý\Ó\Û\\*•lSu+¥\Îÿ0Pô2m\Õ9~\0\0	\ØIDATÉ¾#¬2\ï•R”¼­B\íü\ê¶1²°SœX\Ì\Ö\é!\èúÔ©ö\à3Z„·¨+~R‰µ‚¥x¾‘wgP~ø\ÆÑ»\Çþ\Ó7\ç@Á3†Z¤Mœ½Zxhós™Y\í\å\ÄÀ\è`<Ç’ø5\"9Å§Ç‹¨ J‹TxoW\Ý\0<÷“\ÊSªPy‘:‡»w}2øüH\É!`\ÈL*<\ì…Ð7¼‘!\ÇK„•-QmxL|\n[\ÇÇ™ ¤¹QM	?k7s¼\àm`Ÿ\Ùp\é\"\îÀL5z¨O)$GŽ\Z’­Q94{	â´ž\Ñþ\ÛsýRŸPŽ°¬p L\ÚT#:³¼^µ™\ÃM\èD™\í\\\ÅG%–ð›’\Ïù÷Z\çp¢›IË“\Å=*\Úu‹r\ÃGBŒD›×€Ñ½7\'bSp<·04.EJŽ\Ð0£“YC¨ß…~z‰\Í\ÏV\rŸ\ë5¨\ë¢\\S\Öf€MË‡bgj	\Ã\×@n\0@\ïÝ°JI­\àR*8þ+À‡\Éde\ì\Ìü\îc‡{º©À=\æ\ã\"V\nrL\è@²a‡!r\éK‡\å^øgF\n\é:‚R—B*k˜Fz1\È\í*u©8n:\Ìû	ŒX\æ„&·3\é³\Æ($Ç¾\í\Ì/\ëfRò6¿z–\0X\Â]°„ýbAW\äA\ã\0x\ë–^\Ø¡\Írù\è\ÅBò\Ò\Ñ\È@€pžux\ï‚öŒz\ÇñQ:*¼€\ì§d\ã5\"½ QwƒŽ¨—Š»\Z·§)0ƒI¢&r\âEñº+aj‹\Ê\Öa:?˜\æðp€ ·o\Ì~ƒgök;0\Ã\Æ5y7W\ÍVf\éß™i\ç2%D‡S\Û¥ \Å±nJöp\à}ò\â\Ñy¨ýX!#\Ý\æCž\Õu”\åt¬2¨\ë öj\é\Ñ\íý–\áVœ¦\Þë€‡•«Ú´wd\Ñ-m©Æ¤\ì¤\0ª\Ã\åA\å%:\n,@AŸ\Éã«„\â’v‚@ \È£{7\ä d8Õ¶o¿\r”<¯¿mûR\Æ0cJ?¸EH\ÊJ\ßy*œŒ§0˜N\Ì÷¥ªPŽ\êú\ç8[\Û@sX\ÅÀ±ˆ\ÔN†w°\íüqE-»L;¥t(—‚¤6š]ƒBN¸G µ˜Œ\Z\È!HŸ\"Ì¬\Ä\ÃN)€\nò\çEaC\ÖÁ ,+X3ƒT$/¯j2\ìžUúc&½,AE0¸ù\æM\àþS,i&\Ù\Ð\r\Õu.ð­\Ð\Ù<û#Ff¨°œ‹BÃ…s\îUÕ‘Ø½r\ä\à\Å:&\Z\'‘\ÉGføó“\ZD¼\å\Å\ÚG\ç?\ì\É/$\×üBÌ¸%«a·&D±\Ölo\Ì0]µXt»b©\Ý>¨~Ù­\×h\n›°3\Ö/p\è\Î	\íY­—)A{NJ¦ƒ”BE\Éû‘}\Æ37}`¹;\Õ]\\sWQp1$g´HDg’·SŒ`7CVúsS¦00µ®¼§U‚ˆ`¯Z\Üü\é;Xž~\0œwI\ê\êAÝ“\Å\0\Ø:\Ú\Ê\Ì>\Îft\íºE÷’\È\É\Å×”¥ør»i¥¢\Zy_¬BEý%3W®y\éý”d-*\ê”\Âk6\à‰nz”`¯Ù£2û\n\Îv\r5¦G7AŸ<Â²£q\nj§{†z4³šc\à„ \å]TÂŒÁòñ+QP¼wCz\éÁË™B\Þù0ór%P\ænB¸”MÉeùž|\â\â’,ö\Ù;9;Ô¤~u$©‘…¯\×\083öª|´`+\Ò]\×\ÂP\é\Ý;¨®Y,ÿ–ü~\â•õ5;­\ÑL*4¯Ï°ú\Ë \0¦?~\Ý\ãG0“ŠOKŸ,Q6\rè”“5×§À¾ÁñŸ?gn\Þa“}Ž\Ê\ï{$\Év{n””x8\á}…˜¡\Í\å\ËE\ì0/c\'‡\\€`6„æ”ƒ6\×+`\ß2•M,OA\êa§34\Æb\Å9*^	:ª\ë·\Z[¡©6\ÑK|j\Ãv´vC\è\ÎWX|¶Bßµœ\Æ\Ì–=\Æô\ÖK\ì–\Þô½mƒ–KJÜ±t 4Â·\r\ä\Î\r\Â-Ÿc\Ëþ˜H­\Ëbrë¶¼+Jh\ë¥#¬žu¨N\ìÄ€nð‘€‰Á\Ñ\Ý9\èOPý( h^7\ïYk\ã\ÚS\0rX©=]¢s@ûy\Ë\×l…öŒE\ÂÙ­£QAa	ù3ù,ÿª,ilp·µ½\í]‘\"\Ç\Ú\ÞE\íÕ¿\íýÀU¼@\Ów\0\ÎV¨¨ò\Ü\r\Ê‹ºnÐ¬W÷ö\0 ¶öµw7\Ý?\æ¯\Ïö\ìUƒ\ê\ÚOc}¶\Â\Òò¤b1\î\rõy‘6¾AR\Òk‘ú¾\r¡n1žniŸu}!\æ„R»‹FxŽ\Ì1$”‡w\×$6\0¦Ö¢9¬`_­aŠ\ïÿ\ác¦—\ïÞš½\Õ|ºØ«_mPY‹\Å\ãŽO–Aw\0\"9K\ã6»®\ÙAUp\â#\0X\ì°\æ|/Á\çU\Ã3ú^.f»\ÈNd\à[—>6\Ä\nŒ+1\Çø÷e­J=!|û\á½n\ã\Û\É.r\æ q­®d:%Dèµ²`6\Ú\'„ù\ÄW™1¼\åýÁaý\ßùw\æ{OXž®°v”\Z>Y¦`©¤ò‰•$\Ã/Z¢l#X\Ãzô!sÖŠˆ‘x`\ÑT,©MüI¼M‡–\0ø3¦Í¤\n¢u¿\á:\Èw¸T\Ó:\ÂüZ¢\ÆVq#O\r8L*\"¯6>(”)£bì…“1®\ÐSR\'’r<©r¶\Z]¾4²·+¯¦c`\'U8»\n\âôp\Ö\Ìp{\0®üzb^¬ˆ°’Áž\Ì*L­\åltm*o7=–*Ã¼t^rý”S˜F.À”¥g\rÀ«M¦©•´mlM\ÄZ[Þœ°£{+»½™žb\n“Z\Ì\0`½±Wôº\\%0\à\ä\ï(\âD%x3QEý\ËHcl¿U÷+\Õ5*S¢6{¿ø\ÉÛ¿š\Þð>u\Ý ¨‚>Û¯\ïU\0\ê‰AG\áŒe2Û„T¾SÐˆ±³a/ÿ`vt(YŒº\æM#[\ÌLÂ¦L\Æ\ÈÈO =<Z§\Ô!°#®cÛ„\\úÜ¶fóñJ>ksÈ²]w(`:±¡‘\ÞCE\ì$œü\\UžwH\Ì\'\ÑK&]sò¢\'€^C\à\ëõz‹A^´D¨EÝ¸.Q@–Àª‘3†m¢|~MD\è\\‘£D ®\ß3\Ã\ËD\ÂN‰f¿Laÿ\Äc§R£Z\à|¹^ŸòŽfŒ_FROû„gZ¢¡”1¶4öL\ïx¢Á¹\í÷E’\é\Ø{Fý\å\ï\Ï\'–ýô\Å\Øøùk\\\ÑÖ¥©\Î\Å\ë 9¬Sž\Ã\Ö\'>=þ[u\Øü\ç\é\ÙòAs}öù\â\Ù\â198x‡\ç(ð%¾\0{¦|1\è\É.«÷EõÿR^¾¾\Ñeñ\n\n\ìK]¦À\×)~\0\È\á\Ë;o\Üþ\Þòd¾\ëöª‰¹\Ývskv[¨\ÛBm}¨I¸<Yü}u\Þý‹\0üM«FÑ¥Sb\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(1234567890125,'Coca Cola',10,995,5,5,'2016-01-18',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0–\0\0\0–\0\0\0<q\â\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0‰\0\0‰7\ÉË­\0\0 \0IDATxœ\í}ˆWž\ç\Çv9y5«¥9{‘nlfKCd\ÖGd’½\ífýG”ó€\åó€e˜¸tˆ\í¬	—\Ä\îrqfœ,8¶\ç&›\Î@B·—\r-\Ã\Ë0!Ê—Ö€k8­¹óÐ•;\çnÓ»ª\ÝhS\Ï\é²}¼÷ª^ý”ºã¶«|ú@µJ¯^•^W}\êûý¾\ïû¾\ïFa„Fa„Fa„Fa„Fa„Fa„[‡5wº_k\ïtV	7\ît¾.RK¬co»©e4@TE!P\0¢VA‘*\Û\0µ©\çÓ²-\çÀË¥úË…¸®\çû\n®\Õ\ëõP;S«Ÿ\Z\ç—ßŠ\ä@\\%™¨\ì¬ˆ¤*ªó…„’E&\ÔJ\ÉDm\Z¼¾\ï\ZcõHO¢q¡\ÑÇ§Ã·\'‰H-±¦Ÿ›DV\Í\n@¢\0P`S€RPJ\Ëb‘?dN)PùÁ*\0‘¾Rñw%\ä¸\ç|ù»\rPPP\0¥ý jYV_! ”\â\Ò\éiV\×TP\0/,\ä\ÍG[À…a\ïE‘Vb)e}+\Ôa*@U\Ù\Ë±)¨I9\É,Wýñ“\éJTa<\Äñ(\Þ\ã\Ôfe¦MQz ý‘²S·û\Û6´ö<{!(…J)¬>E‰Z\Ð7\æ_ªjü§\å·29H%±¦«öU\Ñržÿ‚(*`D¡®ô±	¯Cù1F€\å€HŸ4\ä»\\OU\0‹ÿ“ˆX4=\×\ë´ZL}¯Wañvª\n`)@–\Ð{–Ù¼\Ä!•½ª!÷:ö•B€õ*··\0²\\=‚v—¨¢¾B@øg\ÃÐ›£v5,_‡\0 \ì·\0¨\àõ;žÿ¡ó©²^\r\\[U€œBð\Ê#\å\Ö\ê\ß\É\ÕC\ê$Ö±•ÿ®‚«=a¨/“€M¹4‘d‰n\ï°pµh\ËjÍ«\à\ÂTž¿Œ2Y\äœ-$•k·GbR\Ó+±œ_U\äÖ²öª\n°uC\îÁÈ›¤JbM>X:^Ú msÔ‹Àúˆœ\×F\rR\å\ã’Ä \àò•ÁW&ÿ†*•©J\0z=o™\ï:TnT\äØ±Ôª\ÄT«²E^…·\×\åHþô\ç„œi\r–\Í6û‹ø\Êý$€G*¹‚H(`½T	Y\ÅU—rû…+B0ý\ØÄµA—N*RC¬\é½\Õ/5ñ(mÀ‘#6€%.lÀø\ÙI\èo¼.ÕƒC\Zl\ßqøöý\Ç\íˆs¢\Ê%¨\0\Ðvˆ¬\Ä9—Q5—:C\ÅEjˆ¥q‡£–\å%\0\Ø*(°/Añø1\äŸ|\"H\ZÇ¯\Åëƒ»%\ä\Í_VG*WÅµD›¢QF€my\Û!þ/BX‡Ã±°\Üvª60»·zóVÜ¿ÛT\ëÝ•\Ïò\\õÐ€$¡ e\Äö»?>\n\í\ÏÆ :\ì>\\‡ @@\Ò\È“na\Úa	\Â:„ç¤’%«s+\ÎQM!®\Ärê±¶\æ#~:\éH<±4B¾UðmÊ‡`ˆC\ËyªŸ(6…et`~Xy°ˆ\ìŽñPBYó\â6\ïX£\\µQ=Q)¨M¡>j`[\Þú6ð\î®J\ê¤V\â‰5µ£üYž»Ü‡Eƒl‰o€s¬sf\0{þ€[Î¥‰¦\Úb7ÿ\ïºûÎµ|ª•@&”\×\Æ\"qF\êH.\ÏbS\è\04B\n_ÿn\Þ>$žXlX\0u•$q¬\Å˜©[6\Ð~ü	\0@©6ËŽQÀ¢ðI&5Ä–}h\Üó]\Þüu©D0Á+*6§>‰\åüo|[²i¨>â²ª\'\Zÿ\Ý\ê\Þ\è[‹DkòôŸk\0,A‰\\ pÕ¡¤\Ö\Ô\Òv\èo¼Žü¿Ÿ`$ ’cR#]bX\0µÀL3¾•^{•_}\ì)“·ò_\Ïz\Ëøuœv:mô©M©g($¯‡˜’\Z´(…E\Ý\ëh°\Ö\ç2d\Çj\ßó[…DklC\îYG\Å-\ÖXp \Ø[N©K”\Ü&@ûd³Žbm¥÷§\Ý\ëýò°\Ð%‹I‰%Ô¶\0›}ŠM r\ác_<\ì9Fmô³*>v\Ï]’>E;E»91, ]>¬£€ÿ6I\åJ8\Ù\íÀ\ÚJj“÷?Z\å[~ËhO‰¹Ø…I|~l@Ÿðx(€f(òs½\ëdSò£Œ…”B?ôôL\0\n`š=&)De›	¿(\'§¾§}O\Æ\Ù:\Z‡^\0\0\Ì\î\ÝÀÄ•yÀ4136wp\Ût£À\ÖQZ§Nb\ì­c€B\Ð3M¨\noG\ß5-À4™ž¦=ÀL0\Ç*!´O\Ð{¿þ]½=H´\ÄbzŠz·>u\â­,\ËÝ§\Ô¥Œf\0\0ª¦9\Çn\ÄÀøO^g\çöù&TŽ´5~øB )úž\n&¯Ì»ˆRLm.€¨ž?\Ëi‡´Im…M\Ñû\rW\æË¹Ø§Eaõ{¬=}\é\ís	\Ý\è\ãO’M,	Ž„ c»g˜‘>V›\Å\ÖW™žv\ÜÈ‚Ü®\nŠOM\Æ^£|üj\ß}S›ƒ±Ic“W \ïd±U\ÓÛ¶35uu!¶\Ý4\ì`˜A/E\Äj„ˆB \Èf²±\íNRC,pR…Ä´û\Ðø\Þ>\0@no\ÅC‡AT\ï tûýiL^]@v‹<™_·Zÿ\00µ¹€\Úwwª•\ß{»¹$œ}\äQ\0À„N.©Õ¡C;È½A\Ê]}\Ö!tÀ¹	B¢‰%„\ÝÐ”¨ — º5\0\0ú3“ Ÿ÷¼Ô¦˜\Ò¨6>†šñ]IHP7h \0z\í6S{Ÿu=Us•\é%\Ôg\åô¬§Ž¿\Æ\'ø†Kña*·/IFce~{3ÁH4±d\ÈqK\0ˆ©?ÿ\ê´\ÄÃ¾|	´o¢ý‹)·‚Í¤\ÑD{“\íyª±S­Kx\â\ì¬slzlœ\Ì[U~\ï]”\0hZB~A‘ª¢\rª¦…7\Üq´²}@VŒ8Œ$Ö­‚*Eeº}oý¡-\0:\ZhÿôMvN.‡ü¶í¨•¶{\êLm.€RŠ’4½Í­£=X\ÂŸŠ›Þ¶3¾\ë\È{ÿ\Ý\è‰KD­¸5ºŽ£\î]‰EñK\×#\á\ÄrU¡¬—ƒü\Î2\ÚoŸ\0h•Pm]‚þý	O\é#Šl€{w…\çúžŠ#½¬ES›hó^\è ÿÁ¿/ŒoÏ•X\0s9d¹Í•$žX_L\âd\ï\×\ÑzùˆS>ö\Æ\ëõO\ÝÞ¢‰ö3\Ñ\äP>u•÷¼\Òh\î\å#Ž=G?5`þ¦…š?¬G»]\r9ok„\Ä\â¶Uvdc\Ý!øº\ï\å\Ö%\0\ÌÅ ?ù\Ì\ßÎ±\â3“0’´\Þ>‰\Éö¼S\î\'—¾³\Ìz”ÛŠNÙ¹§žf¿­eQß»/¾\nÐ¹x)†L¢5p\ë0Ÿ\ÃH®6ˆqƒ¥‡µ]D‘rhQ\ßù(f|\Òdò\êö}t\Îù>÷“7\Ñ>SH.ówm\Ïy\Õú9L^]Àd{ú#c }DÓ†r9t?ª{\Ê=9†K¨>“;J\Ã\'d$©$\Ö0\Ðñ\Ú0Í‰\'œ}?¹´ŠŒHœ˜s/ñQ»?œvlªÙ»Qû\î£Á\Ê”ßŸ‘zy~NÀ±Ï„\ë\Ãó‚ˆ2À¡ P}\Z\ÏK‘‰\èI&©$Vœ›\0¶>\ïPaœ®¡s±\é)›\Ú\\@\Ó7t3i,8½\Ã\ÆSO#÷\Ç%\Ôb¯m`js\Ý¾¨’OZ!\Ø\ê3\àE9\à\Æðp˜?†+ÁH%±!·§\âù\ÞzõHh½ù35Ô«A›H¨Ç©\âV C0\î#Ê¹\'Ÿ\Æ\Ô\0}¨iB{x<¾’\íS‰Q!\Ò	\Ä]G¬Ò©“ž\ï\ÍJp8FF\çbS›‚9\ê‘Ryd„\ÜÁ\Ú|‘I=\Ú\í”\Â8S\ì¸Ò–~j€l\Ðâ§Ž	U™ñöÓ€»ŽX$—s¿PŠžaDW– ¼ {˜“Fùü\é\ZZq$—\ÃLq+š‡†ÿ€\â\Ì/b¿w™õXÃ¥\åõ¸¤ê»±giÁ]G,1Y\Õ÷¶Om.ÀüMxÚ„É«\ÎÐŒKo½	\ãôL G\èœa^ñ>¬}ƒÜ“Š»–X\Æ/{Ä£0»g¦6`|4\Òõ½U\æf®†=¨ ‹l\n}œ»A@¢½\è\"©ˆ\\&££\Ü,	D\nß…\á`¼s\Â\Ù÷§\Z\Z§ž\0\ì;;\íÁR°B† |\êD ¸ÒœC},\Æ0WXL;\0¨@\ß_©B\Õ÷tFªp•\á¼Q\É@†€\Z2hG‚­®Ÿ\'\à!—<”B\ÓuXö`JÚJb-\ç!¬Dy8ªŽoO\\`Aýaœ­c¦´ô\Ó\èN\ív\Ãø‰L)²a’«B\ÇF\éšF½\Â\ÕElÝŸ‡J<”eþFýq&¥¦¶Ð¹\Øb»8}WÖ¢‰\é,t¹V~\ÔC¤ö\ÏN¢>6\îý½\é¨0o@!:N¶eAšImºQiA*‰V#Bd\Ê\Í9”[—P¾<Ê•y\èûƒ\éB%À&\ïR q\èLm. ñ\ÃN@ïŠ\Ú\Ø8fôfôZ?y3´]\ì÷¼’¨s¡1\ÜÀrŠ$•@*‰Eý\ÓÕ¥ý\âd\á0\Ý3u4J\Û\ÑØ¶Í‰\'Püó˜0 \ï‹¿8÷+…MŽ¨üõ,‹Áú\Å‹pø#o\Ì||Ü˜[\êL°ø¼\ç’\Æ	‰öõ\ndo$U½\ÂTk\Ð\ÐF³²¹½dw”ô.¶Pß²5½€\â\ËGºD\èñ\ä\Õlñ0\Æ_>ŒÉ«N\Ø\ÍÜ«G1µ¹€\Ê\Ù\Ù\È\Ù9^	A@Õ¦z‹ôJp\r~\Ó\ä\Ó\ÈF\Ñ\rw¹G\Êh={¥gfc\×n\Ôw<Š	cÁ‘ CM.=\0\Å\çÀø°\æ\ÌÆ‘\ëµ~ú\æP¾+rpŸxAø\n.|C8š6Šn¸\Ýón\ë?:Œ^»\Æ\Ø8\Êb\èD‚ù™½€j\ëRÀW$ð{¬Šì¦ ¡}ü$Z‘Rp€\êâ¿\ÛVô¤-pòÑ‹J#\ã}õ1hN°ðn7\Æ\ÆQ¹2¢\ç\Îl\Ù\Z+m\ZO>\íù^m\Îaûþ\àd\×öi\æ\å¯\Æ\\KJ\0\à=`Y.!\Õõ&¬†EÊ§©%V”º{¦\0\ã¾\'ô)Ú¯EùWç •|>#~üX¸Ao|\Ò@­\ìU¥—^q&V\È½Ñª¿†`\\…v¿\îù\îý\äû)#I-±€ð÷¸s\Ú\Í.#bÞ\ÓÓ¨oÙŠrmUc%\æ\à0o ò\Î\É\È\Åz†\Z{U>u“W0qu\ÆŠ\"¸_~%P?ªý´\Û2RøŒT„\ç­Kº\Ø#\é\í…\Ê\Ëaü…\ëK\Z—ˆV\Ó¨—¶C\ß[Å„Á¡Ý¯£þ\ä„)½€ö\ÏN¬°\Ù\×ÁV¹p\ÊÀ¼\Üö¥úvƒûD2\'lfdc\ÝNH¡%ü™RTù\ã\"ô§\\\âP\ÓD;3\Åf^öN”\Ð\Ç\ÆXò¾\í;ª\Â&ZL\é\\\Ý\Æ\"Nu9\Ç:}!:²\Ä\"|²®–õ\noøƒ‰{\Û\Ò<\Â\âK¯@\ß[‰©ÍŒk±•g¦>Emlõ\ê>P£ƒ‰+ŒdªB\Ð<ôfôº¿n†^«’)`¹°\Â \ç[¥\Þ\åñÒ€”™„<\Zs)\ÜõP˜š,\æ‰\Û%ÅŸCû\Ã!$\r÷mÕª»A»]\Ðný¬w¨=\\b\É\Öl`fK\ï3IH‚ü\Î2`\ê\ÜC¢C–K¡<dF%\èË½G¶R\r;/HÄŠ¶[Tw „«“æŽ²\'\ËL\ÕX@™§Š4ƒ¹×½ú«ƒ‡.¶0£P{x;&ŒT>\ä™elŠ\Îù::\Ò|Á˜xPØœA’q)e‰ÿAqÿ—4M¤\0RH¬ h¬—§\é¸\Ó,¡ze8Oyõ\Â\\ø/š&fô´‡J½\îB½\Êðz¨xoK‘\å-u~„:9²\0„®Ç“d¤žX½!\Þ\ä\Æ_f…I¯¨\î{\'Z#›rN\ï13z\í·O£¥•O­™¿k3U*.\n7!À}|\Éß‘ñ¾ºXI\æ™\0¹Àœ™a\ä2¯´\Ñý¯aE°\Ö[ÌµQ5–\×.‰\\½Ë—˜“t‰•;“U…»Á¢©3\ÞSI,?\Ì!#Ú›¾!\Z€‘«\â\Ðlü Ü·•ñÒ‹y„\Åc£>)\åñeµø˜+{ˆeñ†t\ËQ\îC‰“½fõ/zñ™I\æ,-=\å3zµm\Þk\å™\éÐ˜öÚ–­ÐŸ›D>\"oƒ·}¾VöMF¬õ^\Â\rLs”`¤›X1·iXi\ÔL\åJý&|†=\í3C½õc×›_mºF½ó;\\M…\åm\ÔN1\î©\âF4\È\Ó\êm²\Z&©\'–\èq™ƒ\×9õ ¦\Ðz1Ä‘©„\ÛS\íwNz¼õ¹ma“ ¶0y,œLžø0)-w\è\nb	G\ê‰\å@º\éq\ïvþ‘2ô½U\0€ña-qFÆ„±À\\!ª¨{9z‘y\íO„?ËTžö°¤vm\Ê\Èe \Þ\Å\ÕÓ€»‡X\0LŸ‘E°\Ò[\ÇP5 m)\Â8[cnƒŸ¾Z—l\Êa\âÊ‚#\Åô]Á¡!ý±‰\ÐX¬\ØijŽjs“Œ\çwU½uœ^ \Ï\ä\"?V\Â\ß\Ër_\×PT¸Kú‡\í¯qz­S\'aœ¯£\Òz\ÜeŒ:e\È#ü¡{Tú\0’ó­<¡@¡`Ù£©w\r\é„#\Ñ‹\Úøj¹ç˜‚X³¤;\Þt\00\r²˜›¸\Ü6üm´šŒ…\ß*¼\ïba©I¬Dk(8o±0\Þý“\Ã|°)\êz\Ên\'\ï”3¥\í˜6<&—¾\ß%&\Ï\Æ$¶µ\âr\Èp|Šz†‰&þ1\îx”Žô‡-{\êñ‡c¶\Ûh\Èp,\Âc\Z\0úY7\ÔOÀ\0u\í\Ì;”\'X\Ø\0R4ý+EZ;\â]¦\ÂjYr\Ëeš\åwŒ£ôÞ»h”…9dR¶\îÅ¦\'!®¾·\n}Wdsôjó?>\n\Ó0GŒ;î—®—\Å3‰•tbE\ÛX–‹G\ÂU\âz\ÄF–¹‘.œ¥ò#«\Zh¿}\í·\Â{Š35t\Â\Ô\ä×¹›6?Ÿ¨žˆÂ²&S89Ò€D«B+v–Wô\Ûf\ÃD\Í¬\Z\ÈûRw\×ôŠ\Ï@ñ\Å\Ã\Ã4\Ó\×&\Ö.ˆ\Ðó”ù\Òä½©.ü\îb@:%H4±Vöh%\Òn\nö\n\Ç\Þ{—ùµ¤\æš^€¾wóO­@i;ÆöÄ“\ËÈ—\ß%%\ã\åKÉ‘ŒÆ÷e7\ãŽ!\ÑÄ¢v¼ñ†A¾ž\Ê6\ï¯FSž™ö8:\ëc\ã0\ÓBõJü\\A?ô§&aÆ¸5\ÂÁ¤)Jsx¥\ÔhH\'°)jz!t@ºj,8k\ìÝ‡\æ³\Ù÷ˆ\\rVù\ì,\è\Õ!:I|ªP\Î`\Ã\ëÐ”­U$ŸX×—SYBU\Ðß²©^I2\Õô\ê!Ë™T\è?˜tbÙ«­`úž\n\ÈE\Ïô³a\àI\"™¢(\Ñ8$šXÔ™\Ã¾ ÷ö‡ì»’\Õ½b ¦\ÐøžwÁ\Òk¯x\ê\Å\Å\Ë\ß:†\î™ð<¥¡qXrXø“{-\Ä?±\"H4±–ƒ\å\ÜòúWýUO\îór;~½Á	8±¼\Ê\ÐP$R\Ù–\Íb\ÂF½\Â[ˆ•\ï\Ã\Âü­;ûylf\Z\åó\ç<\ÇkzÁSG†ö°7‹H‘§ƒ\Çó\"\ÆB{Žª˜=\ZÒ¹ýXÉ¨ÿÜž\ÝhH™d´Š\Ì\å e¤i\ì\Ù^\æ\ï\Ú0}\Ó\â\Ëu/)—‡õÀJap·k…ç™†\ã/½Ñž\å\Ú,\Æ?˜ö”	rµ^>‚Æ®øEŸcp¤«ªy}Vð®nŸ$šXÖ€Ah \ØŒ#™z\Ðz\ãh@*\åþl\Ìq9\ä¥À¾\Ò¯B[ô=\Þ\à¼A$\æ%\Ðw‡x°\Ì\ÊmÈ³“Dk¬\äVW.^B\ÅX¸\Â0vê„·W\èK=Y<\äKó½a¹î‚ \Ê\ï\Ù*b\ÝÅ‹CÓ•|-\Ñ\Ä2\ï+±­\Ê\ç\0Msz†Uc\ãï°•\ékz\í|Ij_J\îrs¹÷ \È¯“”ö\Ó\Õ#N¬A +‘W\Â{nmž -·³ŒñSŒ\\\íw¦\â\Ý\r\0´|>öø\Ør†€BŒr¢iž\\¤Ž*eôK>ˆ®\Ã8~\Æiþr\é5¯ÿ)Ž\\\æ•p7„ƒ!†_bk(¼†\Í\Ò0QŠ\ÔõM,\n\Z©\nWºZVƒ¯\Ã\\n|Œâ‹‡\Ñzù\ÔôB\è\ÂJ5½\àÄ¯‹q\ÅAÒ¬õ\ìA4}³§C!\ÆÃŽñœ£P›%\íL^M:L4±\â°b¥`š\Îd	ý¹ B–€“\Ðxl\Ìß¶Q&Z¡OÑ‹]\á>jñË˜2YŽ¤·qî†¯3ª.M­\\œCñ\Ù\àN2\Z{vƒl\Ê\rœ>\ß(\r!©ü°#ž\å©öTL^I¬\ÄCžôP|\é0s)\ÄÇ\Ên\è!	?\"\×&\\ü¬<±X\é!RbÝª\ÕHý3jª\íyT/‡÷\è\Ì63\Øý\Ñ\r‘.r9ð\áZ”¤S$|Šz„@Â‰5}+gŒñq½\î\Ò\êN,–\ï·Û§x\î÷eôØ¨\ç/X\ê°xOP¬¦`¿D+\n·ú\Ý\rK\È\0c\ÇO¸Ñ¤Rô¨f\ãD3ô‡›óJ\ã]\åqîªV)’Z‰&Ö 	«‘(\ÑŠ‡#Ï³\Ît.4\Ð=_ýl8{©6qY=6)÷U„¤òo)AŠFŸ†G±\æ\Ú=Æ³Ñ½\àº\0ô§&¡¿\äN\ë*ñuušO>±]\Ôô³£b\îL¨Á>\Ì¼þ\ë\0±«¦ª„0u(b±Fk1\àU\ÐgXÈ‹ÁW¦\Ð\ß9¢#HU\×¨s‡§ñ—S{Ÿ\×Qj[Xy@‚ñ\åRü0ÿ&|…ŠÁ ô”2˜Ä‚w6tJh‰µ\ÒR\ãÙ§ev@{¨„±shør¾´\Þ8Š\ÖG™=\ÅWž¨m) ¾#¼¾s\ÏL¢2`99\0n	ùÇ¢óGð\ÄL.RD®\ÔI¬a\\\rYžÀ¬õðx %‘X\Ï0\ï[o°ò\É\Çh\î?\È$\Õb—\ì\ÃÎ˜Y\é·¹|°3yBL³W0|{€DK,+f¬0\Ú\Þ\nð6‹\\h=RöÄ¡Ï¿x¹½U”ŽŸ@\é8³—Dw¿sžÍ°©s\É&\â°ð,­‘d\r€³\0S\ä\\²Y\à\Ï}\Ó\rQN	R\'±n…ùZ/º³ I.\Úí†’G”\Å-\É+\ÐzõôýñCCCÓ‚õ©Â°\Ïh,÷DŠ$V\êˆ5,Jq)}o>\É\å0~\êDhU‡\\l¨Î™\Zô?\'–À@‚‰‘¨-=A‰&V¨ñ>@yn’´\Ò\Åèˆ„º\0¹]6óyo5P·¦\0B†’\\¡W¦—Šõj¸\áN}žv\ÚgóG\Æûªbˆ\×Wz¥˜0–¹™È¨:\ÌD–¨[ô\Ø\ã\Ôf“6Baò\Å1¹¨\"6¿0M¢+\Ñ\Ä\nó¼skÛK„\Ñ4”\ÎF\Ïû«\é4B$G¥9\ç\çÈ’ª\ÓÞ§(½7\Ä\â6§Å€·:#\ÎI¬;ImûuŒ}“-¹\Õ\Z®\ç\'®§‡K%ãƒuvü\Ã6¼7HòÑ’­\'f`\Û\î\"\ã£^\á-\r\É63\ì­mUv{jNCyÀ$±\Êý@ô\Â\×q6\"¤U°\Í¥\ç£\rý\Î/Ï¹þ+\0D#P3$U™hM,\0!\Ùf† \'T+\Ä\Ó>ˆ\\b•û\æþƒ-¢ Qy\ày¹¶\Ó\rÜ‹lm\Ì\Ø\"\í› R¸]4a\Åýn‘hi(\äIœC UÚŽ’/¯U\å\Ê\ÂÀ´Ùóu7ñ\í&\Ù-:z­KC=\\ý‡\Ðò\ç\È«Òƒ$vš<\\\Æ\êS\r\Z`Rwq„ \éë– µ#˜T\Í?:ô3O\ZƒIÅ¥y 8°,K®±\×bb\ç…_Wt>G6Öªa%·–.v˜\Í‚•&¯\rƒ>`R\0F’¨ñA\0´\Ûa;<ÿ¨\ni&ôHb%\Ô0\"£ªW\æW\îü” ?7\é-ðÁªñöñ“®K…>“Ñ’\'«\å-w\éÃ¢º\è¸@\ÕX@µµ¼\É\Ë…þL¼T\ëµZ\ÞD k›µ\nH±n\äT‘hl\è¦òQüòr~x\ìµ>õ¼\0n\êG 5Õ‹ƒRÉ•!\Ât.«Mw\é#\Ö0o\î½\Æú€\Ì2\ä~\Ý\ãy/:pM:*\æ€fHr6€º)7°m\Ä\0\âYÙ‚–œU˜>w\Ã-„ñ\Î:\æ†JõX|þ\0Š1NM7À½j›¢ôFø\Ú<B¼ôžÑ£^az`¶Y–\äZ1\ÚöZ\ÂV¼ ¼GG6\Å`\Ó\Ï\æ¿\âßù“\Îgz$V*‰µ*\ï-e+U4\áqqd;E3u\Ô\Ýh&ôm\Â*+\ï\ÎY\æqoN·ø¥@cl<”ð¢lüýé£¾ß¾ô\Ö`N\Ó\Åb)µ±z6›S\ït\Í;\Í\æ\Ð\îR»<#WY”·…*ƒ\Õ \0À4\Ý\å\ï„ßŠòýQ\Ò[¿*\íŒ\ßhye\êasky\à\äw§n¤CŠ|Y\É\'–\"F	\Þh¿±{» –\å˜\ï3p©EÀ‘ Ûœc\íVU\æbØ˜ek*PT–BYÞ¢Uw\É\'–<\0+\æ\Úª¨!E¾p5\ã,~\ä;³\Ê|\àSLx~[–=•óÃ­\Ö9_gÿ+_\ËZ\Ä|Q›*kk\Ï\Æÿ\Z\êb	@’‰õ\r\0\Ì))O}R\0P\n‹Z®º\0œ}\Z\n¾\ÒC\È\ì\ä\Èób®K}¦»XGb(\Û\nlðY\Íû¸”\â½H\"õŸþ}û_\ru± \É\ÄúÀz\Ú7Ùƒ4Mn\ÌR€\0\ê}*Xl“°½\à‘$D¶\Éü\ÒI\\©O\êk\Ï9€{}R_¬u!\ÏZV\Ü#ùG†›¢\ï \Ì	jø¢‡\Ù\Å\Î]\Þ\Å\î,’L,\0Xz}±÷ý6!7œP“Œ•\Ê9\ÒÉ¦\0µx\r\Ö5§_H( \ê\äµj|\Ä\àE^²H\ä\á|r‰\ä¶Có16\Æs\ÇY:Á²X´ªÌ™\æ{³\Û}nY»\ÃHp¿Š¡iš\Õ4[uøG‡ošŸ\Z_\èW;÷Œ™½{Åƒ¥}D!,3^N\"X¢´\ßs¥œl‹\É>!›O~—\ãúÜž³Á¬o¹Ž\"•öI2\Z#”Â­¼>Eå“‡¿»}W%S˜§\Ý\Íyj\í,­?ú_Ž\Þ\à\Æ×º‰w\0\ë\ît†Es®ùŸ·ÿ›ñ-\Ù?ù“‡U›\Þ\Ô\0\0kIDAT.~+{£ý\ä«\ÍýkJö^\ÊZ¶M¡\Û4Ô¶\Ù0J6ºÀZöZ\0Š\å›\Ø÷0b\Ú\n…\É\îL†=\àom\0`÷dX\Ù\rø_Â¶ojÀZ\ä(\nc½P(U(_\Ù(.cALó\Òe\\½8‡OLs©ñ\Ü\Íþ¶½¶\Ý\ï¿þ\Î\Ï\ßù·\0n\Þú»¹úXs§°¬yýµ\×Y| ø\ï:\ÝL\ÓD¯×»A(ýj¼\ÛY—ÿ¼³ž•ÄŠ”K Ë“´_þ7a¿ppÚ’\Ôð8@E=ˆGm\Ê\"Aqÿ\è\Ïø‚þ|0»Ý›s\æ–j\ç\ëk5MSòù<4MCV\Ë.\í{|\ß\0_õo\"…+m\ÄZÃ·õ„Â¹ú¹y\Øl\Þ]g±s\ÑD\çó\0\\\Ïw;Kº\ÑUò*QðEõ$µ\08Ÿ `=Ð¾	h9\á7b\ä\éS\Þ;\å\Ç3\Zû$$\èuPñMÞ ¦	º\Ø\Ãô{SK¾	“µùyh4d3YÇ¾\Úý½\Ý[üX\ç\åK\Þ\âH™\äJ¼%Aj\0B)5›¿nþmyGù!õ>\Ùl\Ö&º©£\×\ï­37\æ\×\Í\å:\Ìþ¢´o^\'‹½›E\Ó\\“µ¬µ XC$¢y¼O²´\"€	€\ÛjB‚I6í›Žô*t\í_7o6ÞŸ¾aô) ‘µP\È\Z(@~c~½®\ëP3*ˆB i\Z(¥0û&zÝžx\ZÁöÖ€I¬I¬U… Õ½\04\0\ßð/ÿ\èðÏ·—¶G\Ó4…@\åžk\Ëb~.ñà¬¾“».(¥ „8\á,–e1•Éˆs6¥\Ô+!$\"k¸\Ô[#\ç¥6\á«ue\ï\ËB\Ó4F\"1ñ”ñ\èõ{¼\éú\àþƒÿÀ§\0º\0þ/€¿ð\Ïp	–\Z¤‰XkÁ¥\Ø[½€ w\âø‰·!k\0@Í¨\Ð2š\ëË²UUaY{¨\\QF\ç\âµ *,Ê²Y]¢¨D…eó=‰DvOØ€JT×‡\å\Ï\ç\Ù\ì\Úòu\ê\ç\ëÿp\é\â¥Ï»\Ý\îY\0ÿ\0\àè€‘«¦¿ÂˆX«A,^bý!€oi´±ü†üw´\rš2þð¸–ßœ¿O\Ëh\ë©M‰¡•Û„xŒ\0A!q	dQ_tE\ÙrN?\ÚW\Úÿ<}zºvôš¹hþJ\éÿ4ýL\ßþ#©þÀ\ßóÍ‚kg¥i$\Ö=\0²`ªð\Û\0þ˜jÌ‚I3À=\Ú­˜Õ²y\0kµŒvOvcV\É\årkTE]§iÚ½ÙÙŒ¦i\nl¬•%8\äR\Ë)£.I\ÆHt“Rz£÷E\Ï2M«³Ø±\ÌEóz¯×»nš\æ\r‹Z¦išÿ“Rú÷`j\í\Z˜º¦\ê,0ƒýŸÀ\Èdòý/xý\ëH™ñž&b9=B\0\0\à>\0\0|“\ï\ßF*Œ|÷òºb e€uP!„l$„ü!!\ä¼®¸\ÉY-«ÀÆº^¿·\à†JÔµœp7-j]—\ê6úÔ¦&\í\Ó\Ï)¥]0\ér\îH¤^¾\Æ?)ß¿&­®\å©øŒLß®ñ\ë¤JZ\é\"ÀÚ»Œ0\ëÁª	‰Tþy/Y\îKªõ`\ÄZWò‰OqMùÓ›¾M<h!I\ÄÃ¿.\íË„û\Â7uMú.ö\é¾ò]Güfª6b.Ádòø?\×A–Vl_œ+\È%J\Þ\ÄC½!}¿\áû$\Ûui³}ûvH\Ù\r\éS5•„H#±\0·Ý‚2A\ä\Í_&¢¿\ä\n“dqŸ\×}\ßýò¦i%–Œ5!Ÿk–ù]þô\ï\Þ\íß\"F\\¹ÿZ©\'’w±¢ö¿\rûÿ\Æk¢\ê\Þu\ä‰\Ã\ÝL¬\å`¹÷\áÿ+’Œ0\Â#\Ü\Ýø\ßÙ“óŒ7\Ò\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,0,'',0,1,0,0),(1234567890126,'Paq 1',40,1,20,0,'0000-00-00',1,0,0,'‰PNG\r\n\Z\n\0\0\0\rIHDR\0\0\0’\0\0\0–\0\0\05\êÑ˜\0\0\0sBIT|dˆ\0\0\0	pHYs\0\0\Ã\0\0\Ã\Ço¨d\0\0 \0IDATxœ\ì½Œ×\à÷nq÷Õ¡¹÷j3\Ü\í\ÂQ	K‘öØŒx§Øg`n¢1´\r¡4Œˆ	G6²\Zz‹\\!+q„;\Ò:Rl\Ò\Æi5vb)dŽ;\Z\ÖiˆDÎŒ93º£\ÂfŽŒ‹W\åd«rj\\}c\Örò\Ç{õ£{z~ò.\Ö}¥f÷ÔW¯\Þû¾\ï\ï÷ý\Â\'ð	|ŸÀ\'ð	|ŸÀ\'ð	|ŸÀ\'ð	|ŸÀ\'ð	|ŸÀ_\Ü\ÍMZ\ë\ßPŠ\ßôD\Z:c?\"\ì¬7H’\ßR¨ ^0\èÿ’\"\Ô÷ø¿	r³}-ZK3p•\å¯Fÿ·ªiùsA}D\Ýÿ·.·\àiý\ë~Mý½Td\'ù\r~“\êuý[® Püz*‚¯=¤£\0P¨\ÄüD„?\×u$‰ÿB÷V\ÜIÿ\\j\îÏ•\ÖÿOk%ü?ÂŽ\\Žkª\Õ^M®üâ†´?¨šú»º¦|\Zq;¡\r\ßÿ«~\æ_\'4h\×\ÃªÀõ”R\Z´$2 <\0•¸€rd‚@9qd¦±\â¸S>ÀôP5…ò5¤Bt=2\'\0×XÒ¢É„¼=USx\ÚE\Õ\áõ¨š‡›·\ï˜k¤#e›Rž£“bznþN³´\è—\ë¸\0k8\æ\\\ì¨\ëIGþM\ìð\ç\×\Â\ájE”ñ/ýºR\ZAH\ÛRÿ\0öhüC\â„TÀs3P5US5µ‘_QJý:™\àº\Ú#”döý˜øIk\Ç\ÝO\Û\ß<p\Z»ý\Çü+­O)J\ÄL’“#\nv\ÂU9i‰T‘\0A,’\Ù\ß(”2÷\à\05{­\ç\ìR\ÈGf¶E…Ÿ)p’$¤™™xW)”2PJ\Ñ<8„$1Il\îUJ!\"ö9\nE9I¶Çˆ£\Ì1\Ó\É,¢¦¤..\Ê/“ÀSP\ÏÀ\ßS˜Ì¼“H\n’‚º\îYjªPx\n…®(\Ç$_\n{L\Òbœþ¶\ã\Ç\ÑA()‰ù6ˆ\à\ïõŠÕ®jv\0\êñjðöz\æ˜c&Qk\Ú\í!IŠÄ‰9—±ó(x÷ø¸uƒX’$¤b\î\'v[d\Ì(\ÃöIQ5`\áY©¤ˆ\ÊW;)°\nI\r\ÂkW›\'\ßT\Ç\Îx>‘9%u”¡šŽ¡À¾£a§‚[®¥Â·Ìµj§\írñ´“|\ÑHIM\Ý|¼2@IyˆAÎ¿e\àÐ‘ºB\á:P¯ûH\'.#º\ìH\Ú	ñJŒ·\ÇC9\nÿþ\0RADð›`;\í®R¸{\Ô=C5,²$Q„Þ­\ru²2’ôÑ®\ÜT\ß[\Âó=òC†6\å\Ë\ÝP¯¡@&\Ä\í\ÈP›\éna\Éó‚ßŒQ»\Üø\æšNj\Øp\Î\ns„±OS\ÊP·\æ¯Ä¨š‡7¨\rl\'H\'EIJ¼ŠyÆ\å*”vq•&Á\íˆE¸ò\Ü\Òpþö!\Ò@óÆ¡‰•\è±\ì‰n9()vð’–K&%£\çª÷\ÙÁt@\Õ\\DL[’VvI³²\Í\ê=ù}…Ä£\\K±z\îC,{­@&›.´,ú\Û\ã®c\Úò•*ž\ï\Õ\\$ƒ¨JRP\Ë\Øö¥ ˆ\Åx”¿µ\Ó5\"xJ\Ñ|xWkF¾3{WŠ\Î\ßT\0v¼û\Ø\è_J^	‰:\å4HV\"W’I1`\n…‹™ØœiyŽ\"\ÍJ\Ûs\Ê)“R+°k\Ç\Ê[ù*+›«‘B\Î*Ymþ\\ó¯[™8ˆEº‘\Ç\Þ\'\Ð\Å\Ær5!¡Šn‚A€œNxhûœüXÁfm\ËI–¿—ˆT —v\Ì)¥ð\ïó©>®\Ö\\~o™ùk!\ç\ïRcþ›\n\0\Ó5µ6úøt„ðâ’™«Qp\ÏdY\È\Ùb>ñ\åqRP1Ÿ™\ìõ\\gb\'¡û8PhŠ)†ZQW\n(\ä»BQ(\Ûp+\Í”K\ÄöKŠ÷\ËF\"¥\ØEQr\Ù\Ç)Ûª¶Sj¥,%­¹xu\ßŒf\'B»r\á\Ã\æþ–!’\Ù¥¦\Ð{}\Ò+¡\ÑX\ÈWµRªþ9«S=”A­k\Þ@\Î\Â\\ò\Õ/D*³¬”\n\å\é¢>öù\Ö\ì\0vÀLX9‘ªòK\æŠõY}k\Ìó+ýV€(«MV¯·P¥„^ñ\Û(%\æ§*Þµ~`n0\ÊF\'%º›÷Wü\ï}W\å/18\0²7ø\Ë\èjø+ú\ï~\å{$—BDR£Ue%ù\íj®“³¯M\È\é&÷;´ˆ\é#D™\Ê\éI\Ñ\×Q\ëd\nº\ÚQ…l’d¢\nYYd\ÈYn®I\ì­r+Ó©i+,Ð™¢MBœIAƒ\n\ÏQh¥p\ëna’À1·+G¡\Üüo\× }—´¶B$‰‰\Å<{	Žms~~i`\0`x_c\âÐµðŸ\Õ5þÀhù@ˆ\Ã^*ˆ•]2ˆW\ãB†Úˆ­;q¹­*­\nõ\Ùzyc£ûÁ\"˜\É\í¥<ÅµeƒJ•†É‚\"Y¡ºª\ê+eM\"¨šG\Îør•]Ù¾‚1)°³´—\å\Ú¹M­.¶+\ÅPþ˜…ø‹­†\ë—	€\ÖJøþ($‚{£vê¸ºÔ²\Ðh‹PŽF‰ŠB:y+†õÈ‡\à¢\Ìô²?\å\æ:6\Z\ËF\Ìÿ¸\Ô\È\nC	óû+Ø¥\ë(E\à*£!Ý²È˜•\ÔMr\ê#b\î\Í)”cù¡c\r¤9\"9n\ÅZnYc~\ru\Ã\Ò;9R£eæ»U±ue\é\\Q+$n\ÇAÎ¦ù9ÉM\Ó\ß|p\0’Žü+±«=^‰I\Û)‰n7P5t¤T½\Ý^i\\KDRDÀS^E\Ö(-@JQ¬\Ð\â‚\\0¥b\èt€\ÚØ <f\Õ+ó·[P…›	dJcg,\Í\ÒBŽ3\æ!·‹TƒŠœWe«ù§jd$3H$H*%òf¹øoLi\",}\â9Ý¦ˆX†ÿ¸½Á|ü\ÒB1d\è\â\Å\ÅPƒD’\ÚÁ\â´\Z¯¦ˆ\0œ”˜•¹\Ö\'g\Î+k+lO¸;U÷“Àq\×«ÚŸz¨šùV\ë]\ri\r­£‹Ju?\Ï^\\\Õ2ówÏŸKnO³v¨Lˆ;1|dÿ1\ÙÊ‘¹Œ¥ö™k}¥Œƒµ\Ù13þ;þBuŠ\Ör —ÈŒ|D’\Ô\èš@ƒ4.’¥\Ì£¤x9•@Ð¨‰\Ö=U¹\Ý\í¨\nU\È)Y~½TXH\ÑN‰ª\Ñz\r«=P¥HòP.¨ü=ò\Å$¶MIR°¬Ý­\">\å5¹“¤|v¼¾¿üP¼^¼¯ñ_\'\×Â§\ëNE\ãˆc³\Ò:VŽY‘k¤\Ô	$-†{Ù9\\š\n&\í\'€Îª²R·H½!kÉ…øœš\Õ\Ô:+5”+½ÚŽˆ”¬¦Ji2)¬\×\\!¹5½[ý‰Œ\Ü\Ì\Ý1ö^»¨¤§IŒóØ˜7Œýl\ÝuË 0Š)¥\Ü{üÿW­\Ä;µRøuþa\Â1,\"u,e\ÊR\ëiW\Ö\ÈXN\Úñ¼Áš‡&eZ¹ˆc\r‰x»¬É 0 V4*Å¨\ÊH–­®\Ó\éz¨I¯\é¡zMÎžJ„*\ï]\'?\Ù\ëDR\â°]1PR8{¾èŸ¥Vz\Ð#Y‰­‡ É¤\Ð\Ö‡>Ÿñð¦3òK\n]\Ö\Õ\æ\Þ`\äp;úŸ\ëJ\ãº¥z,˜•Vñ‹™CF—LHÈ©‚\â86¼\Ãz»\'”\â-\Çe’\ß£)¥ðjÊ¨\ÜùDö\ÊJwU$\ì÷wN÷·\0i#7R¥úpÎ¼½’\ÊQ •\ÒÆ‡(«)©¯H„–e—óJýýD\ä_}¬wû\n]Ã»|=\\˜°,$¡\ÙhR®\åû–l\ÇJ\"h‹L3aJ	gE˜$B;\n±F=¥\\”V¸ZŒ§>×²¶û½Bwï½›P:ƒ)i\"E\è‹R=÷\ì\ìio\'¨\\»´–\ì\ÜNUAs\ä¬ô/¹ºÍ·ú¥ƒuþž3÷‰´\ã¿\Ôº\æ\Z\Ò/{ºd’Žq]FR\Ê/\çhÙ°SƒpM\ØnQ–c(F0\Å\ÜÁ\ÛË’Š¿\ÜZŒ	CñT— \Þ\éúQ%\0R$\âU±šWj}Ûžª Rþ\ÙYu¹¨\nòZù\'\\Eû\ÑI\"±}Wª\Ð8]§ê•³\æ‰,\×\nÍ±u¿·=‹(½•®;¾\Ýö”£˜oþ\\üñ\â¼ýX7\'V\ã\Æ)‡M†A š½\Ê\nŽ]!Xv–)´m\Û\á‰NXY#¸ü¥:gO\n\ç2XNÛ˜E˜¦õ2\Ù>¥¤‰ UH¯oô:¹\ëµ{\â6F•O²E€\Ü8ª ÷»˜\Örª\äØ³ö7v™Sû\Z4\î	z\Ú_¿øòw\ìU6¼\çN`#¤\Ézª\â‘(\æQ)öAmñÇ‹wü\Øuˆ”$I\ä\Ö Ÿ’4_U\ÕÀq\Ò.ûQ–Pg*9\Å\Ø\Å6‡—¡•”†\Ý£(\Æ\ÄX\Ãu;\Ý\Úý\ânøw×n‡U\æ\ï–#••\n\Ô\ì§yVÚû\'Ó ¼Š\Ås]Ç°\Ì4•BÆ„^JQ*E|wyf[\Z\ßFc%€ò}ö?1Qh§Ñ¥%ÂŸ.£µ6^	ŒO1ºþ\Æ<²€¾¡§l~¬Dÿø\Úz¶ÁÒ´Ÿ«´kqXöf\Î/`¨ÀÒ§š‹?3x‚\Å\'g8\×\Î&Òµ‚NaØqn\Üiµy,T„fE\×t÷…\êù®k;‹º=^XKË¸\0i¦\ÝÀ«y(­Q»\Ì\ÔH&\è45®’Nb¢3í¸¥•@¼;ž¹>P˜Kl7so„\ë@¬}\Æ^;S\\»ü\Æy\Â\Åü\Ý>|d£b“„°sê½…\Ã\Ë\íö\ì<»\ïN†\ã,?\0 2K‰òjºq”º\Å\n2‹žC7Û©9±’B²$°\ï(\Ã\ï·8suŽ\èñ€±Á:ªf,\Ñ\ÇŽf	óYB\Ø\ég3rYO*P1\nV¿7µÁ\ïbÑˆýt\ìG0+\ÈZ¶U\åú¤\ÖÀsJ%!wZG¥{§b\ëª^³ôQ‚ÖµQy£…\Ê*œ ¾¡”	N­,—R?8ra‹¬ƒ\r·\Ä(\Ç-;¶™\èPt\Ë8£ö{A¹x\n²ù\Î8\È(Eý•)fò83¨\ÌKY˜É„!Î„Dò¶»#¸»û\ÂÖƒ·õù\Ü\êù1,\è•òº)\ÕHóþ$\ÏPbU1÷}¿|\Üs¨\Ø\ßÄ¶Q¶Y\Þ\ãb»\ê\ØN¥”óò¾9\0\îºw\Øü\ÊF\'\Úû‚ÿ\åþ¤óŸy5—½rË¯‚\ã@¶øUv8\È\Ï\Å(8ŽƒÜ†\ìv†üˆaÿ{1þ~‹\Õo^\ãüß\Íü·x»o Ÿ›`\è\è\Çÿ½x—„u€\Û‹·3~	B\Æ=?‡ÀŽŒŒ‡\Æ\íÙ»~‘;\Åò÷½\r\îmóMVùv [s\ÈnQ­‰¯v\áX\ÇA¹;q…s;\Ãù¹\íw–\á\ÜÎ€8·3vÀNû\Év˜¶Àqœ\Û\ÅŽƒ³\Ã\Ë\0\Õó78xd·Í¢\ÎvÀ®0°\Ã!»\í˜ù»q\ÏÁ\ßÁ±¢\ÊÕ·€rw±\ëW2\Ôøy·3v\í\Èÿm\ç£ð/’mK\Ý\"Rø¯\Û×²ß¾ÿÿü\Ü\íl¼˜ VÜ¡`‡}A\ÇÁÙ‘‘upv\ì„·3²,\Ã´\ãp\é\çó;þÁÅˆ\Æ\Ñ\ßf\è¿ù§‘0ó\î*Þ…\Ü~	\ï\ï)~\ç\É{ù/þ}‡‰¿³‹™!\Ë2®\Þ\ÎøÁm\áþ\Û\Î\Ï3þò¶C\'\Ëpœ\çö\Îu\È\ãb¬ý¹m?yû9ü\Ü~g)\Z\ÏóqÛ—\nõ«ü\Ú.¼°óß½Ÿ\ÎÿÂ¿s>\Ë\ÈncE% ËŸQA\àv”\Ïvr%\àvù·s\Û\"âŽ²ÿyWw\Ú—‰°û?ú\Ô\àn\0V/þOd\î.\Üeb\Ú\Ì Ó°\Ï?úî‡—þ«ð£6]\Ãs,ÿ3•orª+kŸŠ\ï·$ÑŽb$7\Æ%	“A9)\ÃöòvGx\æZ\ÂþwB¼Zœ~j	n@ð˜&>ð\ÖÞº1j/e	\Ïd	o‘ð–µ[…nŠ-¤§\ÍaC6\Ò\ç\ÚJpQ\ìh’\ÝA\ìÖ«\Ñi«Eð¥I\Z¯AV¢\Â\0\Úeÿ\éq½¬3°ö^\Û\çœ\Û\ïùU™1\ãêª€_«°°ö\í\Ízý?e›°%3ˆW\ëÄ”Ò•¡Œ\Å6s\íµ]ä¡¯@—/«\Ýd1aŸ	Ž\'	‡\ÞYþj7`ôYŸð±À\Ê¦\Åó\"\ìŽZÿ^”	’¥…†ò\×\Æñ+»ƒ\"<¸\"}\0\àZ\ÂWO#+mü\'\Û\à@{iE\Ær\Éþc~ºd·²?’\ÄÝ’ƒp÷µ¥yb¢±ÿ¿\Ü\îˆl‰H¡¤¤«R„L°d§q\äJ[\nŠ`”^O©\"@þ”£\ÓÁÙ‹1S{4º–\ÇÑµ\Z\ç;\Â\ÈJ÷k-†^Xf\ábLúx@|\Ð\ç\ÅAs\Ï	IL˜CxFŒ†JL,)i\×Pl¶„\ëLø&AB*§2=B¸›\Z¬>ŒúGž8¹#\Ø\Æ;õ\è\ïú“›TL„²Ç•\éJX¾\Ê\"^\Ýu\×÷C„­\Ø\în‰HI&k¡¤Ä‰ «R¸r-CÚ¥i¿ª%h\ÇE\çQÀ‘šA¦\í„Àq9œ[\Ì7V‡\Úm\Ü7Z-†ø\ÄŒY’<gkG³„g$¡•	mII²”8£?•\Ú@uVYU‡\ê\Ò}\Ök^™6\Z&óIn;\Ë(X–Ê¯\Î ½…1z´žš@?6Nó½w‘0,\rž½HpŸ´¸Ÿ.\ÓEõ\0\È\Õ‘T•\nÝ²›B³´‚ˆ¦3\Þ\Üz¦¶H’™½^‘˜\Ð±û\à“LH>K\ÖÓ€\ÜÒG¶1H(6²p¸‹¤n\Ý\Õ0ƒ£\í„\ÉK!§öú4û¸æ‹\Ùý\Ñ\Ê!E\èfyŠ\n\ÂTYó&\Ï_g“²“¥¬¨d\'=ß·\ì\'+}_¶\Ëvw{ö\Þ6 L\Ò\çØ†”ª©lp²\Ú\'T<\ì8)Ü®ö\ÒL”\Z®×¿\ÔtJ\Ø‘\ÒL\âLhu„…$\âò•˜h%!\âDˆ2!\ì—;1‘¤eŠ\ZŒ³2—!ŽdŠie¨\ÒD’r¨*\Z÷¸^º^²\çøl\"\ìÿ0dY„†\ã=øtTNt–D˜±g\æ“\ïvXY?\Èj|¨ˆ&va¹\Æ1›f©qIt$‰a\'´¿3@s\î-\Ò0²d>\"•\ÏG‚\Ä1C\'O\\m•\í÷^S9–Ç—§™ù)	\Åf™‰«¬m\Â\n\nCQS)‘\ÒN4öŸ\Ýjl6§Ž9Ÿ“õ¶‹\Òf!_\ê\×\Â,\"_›E8,	\Ëö·v¬Œ„I0¿\ÚfB*^ô­&6\ë\ß\ÓVf>ùs’¬dB/‰Q\ÆX\ÆXl\Ëz´\ã\âmkªXjDJ\áeb\Ø}[8‚§R\ÈT\á¯s?=Dý‰#\ÐN ®Y;„ª\èGFñŽ_i™NªÒd@\'Af˜ñ«?cù«\'h½9‹\Ò\Æ\Z-\í„#W/›\ã\ß;\äVZnž \Ò70\éf\\i_\Êù‹\ÌÚ®ŽT@n¥\ÈN M©+õ¶Eþ×FjSŠ¤\n¿6…	Œ\Æ6…K¨ Ì„0¢Œ®O\à(&µ\ÆGq4+IjÓ©ZùUôn-\Óc\Ö\"žX\áVgt0\Ô\áh&h\à‚ˆI\á`d(\îÎ·•Zöœ¦©•)R¸•Re-Å–p¥5ÉY|tŒð[g	¾z‚\è½y\0üGÇ‘J;9‘œ\ÊU:\Ø<9\Í\Øçˆ¯\ÙJ\rj\æ\Æ\Ó<9\Í\èk¯“´.[\ëujµXû¹•’Þ¢¤|9ˆTØ¯\íwfžYd½³, \Ðz|³q\Ùtÿù\Øg‡Ÿù õ]°¾(K8¼>pø\ÒzPo\Ö\Þn•\íL\nÐ‹5]0“%œPš\ã«\í\Ù[6A¶µ\æt’nš60YSœ\ë$\ä^±×•¦\å³™0\í¬\ï·r,µ*\Ü9˜…’HJì˜…¨«••\Ùô »KAMÛ°axör¥\Åü#‡HV\"ôƒM\Æ\Þ_\0\à\ìÀ\0jO~V0\é\Ä~{Žúg†»Ž/\í,K_?tbd5¡ñ\Ø8c³8=0@°7Xï¬¶ù®$\Æ\Þ[0HøùÃ¨ºo\ìOI\"¤Qd¶—\ç–%¦\ÌIü/fW“7\ZÿM)’«£ƒ>£\Ú|\Z5»w­\ß\î\r ¾¥†–\Ñd0\Ó1\Z\ÖŠ\ã«mN\r\Ö\×#Q\çf¯ÁMª¦Y»µ\ÆôÍ˜\à&\',b¯\ÝJy=Žñ\ïk\0†õ\ÍNw„I’0\ÑIÌ·ý\î$œ•˜PR\"1¾¾…N\ÄñN\ÌñNÄ™LX°J¬§h\â¬G‡TYi£ö5z\åJ+dµºOa\è¹\ã\Èj\Ôu_²\Z\á\íkPÿ\Ì0/\r ‡kó+SL†?c\â¢A\Æð\í9\Î÷rlm\èzHš¬ß¨\"\0J]œ/\Úñ¬Fr\äc­j69ˆÖ¸JÔ¼\ß^\×h6E¤¥ª\É÷\äW’J@\×o€p¥Mx=,>\ív»+·c\Ç<Ó‰VŠ6\ÂxM1ò\ÂqN½rŠè‹“]\Ï­)\Z=\È\Z xQ×‹û8ÿ\æ,C\Ã#´>\\\æøj›v.Îƒcv³4­–v&¦\ìN\ß^Þ£8\ÜI˜\èDœHBDy,‰\à0ôôÁ¡u\æb³eŸ%·¦˜x”ðg©?>N\ã«Ó†=\å\ãö\Î<\ÑûKL¥)í•°\Èù„:0ArÍ§\'9\ëûœ |{®¸W?\Ð\à\Ø\Ú\ZS7cRfG?\Ç\Ô\Ú\ZC/œX·0¦ªß±÷oNñüº£Œ5<T–þ\åf—o­þ;E™.U¶Ž?Œ{ï¿·øŒ<4\Ê\Ì\çŠóZk.œ?Ç¨µ\'µŽ<q„ÆƒMN½<\Í\ÒòK\ËKL}\åKJôx¹\ÇjŠ—’6\Ó_fmm­øˆGµ\Ûü\ìjd(TZ\n­õzµ4%\n\Ë¸¦8+\Â\ècc,¼7\Ï\å\å%Þ½8Ï©—§9‘$L[c\é\"Š\é$B”\â\Ý½Ë™W\Ïp\è±ñ¢Oý\ìMý@ù>­WO\Ðøò#_?ƒ\\i\àj\å7\Î#I\Âð—§¶aóJk¢÷\Ït\ìµ\×\Í«=uf\ï0‰½·€šbbq\É\â@ó•\ZZ8 +f”\ã–ó\Ø\é\\eó;Ù„®ò6ƒ6gm\äöY³ú\ãLˆ³Ê™Šð¦C5Š¿¯‡„ÏŸ`ÿýÅ±ñ\Ç\Æy)i3¬§“6ÁÞ€±‡M°IóÁ&\Í›œyõñÍˆo\ÏQGq¤¦™ª\Õi}zˆµ[k¼ø\Ç/–´°vk(üY‘2°/Ø¾\0OL°–¦\\ø³f˜\Æ\rF?;Ì±¯c\íVÊ…½¾•\å4§¾y†´\âZ(‘¦\â{¬ŒA_P\nuÀ\\ÃŒE\ã\ËS$7\"Zß™!Mb\êõ:3¾\ßlrlm¤¡´‡¬\Æ$\×Bp\àÅµ5‚‡¡jŠs\Ã#¼40@\ë{\ç\ËGj\Æf\Ë0¢¡“\Ó\ëú ‘A$·^\ï¾{Á\ÊIž*´lr-[S¤Û’‰\ß\ÄU\ë5BvK­L8\Ýi\\XŸ\Zamm\r€ðZH²Z&.\Í½\á\Ï\ãª\ÉyI8\Ûió\î\Þ-VW»\Ýfù\Ã­Þ•‰icö‡%ùo¯´™ýþ\ï/±(¦_g¾n\"»ŸKÁŠ—\Þ_\â\Üùs¼\ÔI˜|ºd»I\Ú\Å\ÆÔ¨8“yn6¸¹Rx”\ÆÓ“&\ÂjU÷™þ§8f)ª$	gï¿·hiì»¯3ögH’=Xgþùcœõ<–¿vz\ÝS›ü¢±]õö\Æó\Õ}€t6q&\å ƒ>~M³i\È*[!’S\Úe\ÄÚ¯7\ÆË´\ïŠ,\ä\nœþÚ©\âw’$€w€w€¹\n\ÌW\ä\âú\ÕÿŸ¡\æ~ö7÷¯;/’pxüPÙ«,\åð\çsøó‡\0\á\ØWLj¢¶µòºž\ËÀ.\Ï÷˜üƒ£\Å}c­k\Û÷=Nœœ\Þ¶Š>HVBš_f\îÑ²‡Þ™\Ç\Û\×Àd\íu\Ñõ:sŸŸ`by	ý@“úž€\Å\çO\×2ü\Å)ƒ|–=\Í=wÜ°\Ä\ê8\\\Ë}‰\Õþ:Š\äJ¥½u\çº°3m5:I¤\×B\Õ›#R&·ò¼EG6z\î&g¥‡,ª	@»04<\Ä\á¬t—j‚g¾ð`,\ç\Í›wd‰>R\Ó=	»º§wÚ’üðJ\Ï÷‘Þ­k\Òhs¯L~ú^\î=°ŸsV¾kW\Ü\niœr\ì\Ë\Ç\éj²\å»OO<}„ñ\Öef\ï1”¦þ\ÙaŽ\\º\Ì\è\×Ï’\\M\ìû\â\"sŸ?\Ì\ä¥%\Üz¥\ï\Í0ÿl‰ä£¯\á\Ø\Ú\ZûŸB:	º¦™ñ}’[´¾vš³;]f›C\Ðk¢\0cP½8\ßl¢j\åù´r(\Ìj·\Ù\Ì\à\êµ\r^ØŽ°M·†Ô…=\ê8œ\Û2x«“qGÓ¡+SC\×\Ù;@¸ü	SZ1úÆ„1È½y‚\Ï]‹9urš‰\'\'\0ð}Ÿóoœ/\Úöƒz_ª¼•AD®†4_.\å–ñ?\ãô@)¿slm±o\Ï\Ð^	‰¯†¼40À‘÷P\Ú#|{Ž\Ó´R-ÿ\Ñ1Ž­­1yµEð\Ø8K/O\Óø\Ê1¦n¥¤S0E­Ë¨½‘“z!C»óEn\ZŠT÷\îwœº™¸U»»Ž»}Il\ï]g·0ln\îÀ:\ì\r~ Áô“|\ê8ò\Õ	\æ^½L¬ã•F\ÜQ¥˜ø\Âd\ïlœw7c¼O7»µ¾u=XgñKG»ŽŽ1úG/’\\\Ñ{f\Ç1±¸`™÷œ{h”^Põ:c³=_j\É\Þ\Þ\îýu]cc‘L\íö+{=\r\Ýq\ß8\êchm·\Ìnˆ\\\í—-W^a8t`\ØQ\Ì$\É&\\¶v¡\×eòW§ÿ\Éi¼\çGYx5@!ù\Ý\Üo„L®$\ÄQ·r0Ÿ	£p=\ÏýÞ¡»p\å(¼O1<Û½1cùÙ£¸5—ð9\Î\Ðz£\ÔÀ†_ž\æ\Ø\Ú\Z£¯L\Óz{Ž…¯N3>÷Éµ]7ö¤³]H°\Æº„iU¥\Ö9u} ±q9\Õ<ƒTJý›=oa»ü™öüM\Ï6d2PŽ\Ðt(B<EX»U²\ÖöJ»‹ý\Ô\ë†ûÌ‹0Z\Ó\Ìw„Ca\Ôu õ\áò¦]\Ü\nüºFkeýo0º\Ûcªvýl\0\×B\æŸ\Ã{/dT\åþ:E\éL¦\Â7§ž\Û@F\Ú\0\Ò(¤ù\Ír?™´fƒ{Q÷•“¨ö,<wŒó†hW,Ï\'Žð\âÚšvWBŽ­ž›%¡\0\0 \0IDAT­Ñ¶”J)—\Ó,ÿ\ã—ú?¸Ó£üT£VswNs\Èø\àú-Ž\ÜHÛ‰MH\É\ÇRÿ3n\å1=\ÒKª\á¢À…ó\çXú(5Ÿ4e\í–1–*{‚øŒ\×4‡LÍ¬\ÝZc\áf\Ì\ÐÁ.\Ô=Þ—#O`\êùc\ëõ\í@uõ)¥XZn1Sƒôdƒ…¯7@ ù\ÃÏ¼r¨³–®q!ŒX³û\æ“Õ„Öµ/\Ö4#GH\Ó\Ô|>J™ùfÿˆŠ46\ïÀP\×ß³y‹^Ž\ã’v.|~‚ó\Í\î{F_;cL\"L-/‘Xc£\Þ°ô\ÍN\Ðú\Ó\È`þÏ°ø\ìQf\ì·\Âv\ÍM)\äzˆ\Z\ÔH’ö\ï»S\\l¿7xAw¼g½ekh]	ñ\ïñ¨£˜“„\Ù7\Î3ÿN¹òTMñúk¯Á¯‡Ì¾yž\æøõr­•Z`{¥\Íò\âs\rMu\'–…‘#f1\ÆF‡.\ç³d0ñô$¾§^9µÁS¶ºY‘2Êý ¥\\¢[\Ì}\á¤\âJ@)ôƒM\Ô`½Ë¢÷\Ì}\éqž…oE\í	Ö·_	\â+}w,\Ô|1¡&›;ø·Ø–S#…k\ãqòl\î±\'¡mýoû\ÜË˜Ò´­³eJk}Žóoœ7\'3u§Wcô÷/p\âO^\â\Þ\Æ~N\é:\Ëv\å¶>l±üA‹°\Ý-\Ã°üÁ2\Ë,\Ùs³„w€\åŸ.?:\ÂØµ\èƒ\n™\Ü7CB\à\ÜwK\á\Ô(&	\áµ?ðm\Ç]Mh\ìkt“\ÝIP\\þðHñ\çÜ!T}s\Ù@\×}¢‹ó\ÌZG\0¦nF¼h5<·¦HV\"”£Œ–þŒc¥ˆ¥ZŠõ¬\Ëu\\\â\"\ìvO‰ô›²†-EGS¢A!³Õ¢6÷6‚#\ís\'m¼Î„3³VkXxvŠ‰§›{dœù$!z \àð«Óœ\Ñ>GW\ÍËŽ\Õ4\Ç+2¦4sb\Ús\'–šL\îLE\ãü|^A²‡/†\ÌwL\ê\Â&Š‰§3ñ…\Ê\0f0¦LLvl\'Àõº\rwMG1¹…•·kRrÖ’l\í,­ôEi4I8=0@\ãñ#=w´+¤$xdŒ\à‘õ†SjŠ\æ\'h}{†$±\ÔN\rz\Æ\è\ØN\åƒG6¥Hw¦ƒ8\n\åX\n!)G”\î\ã¯É‹\í_øŒ$4Å¨£\Ç\Äz„œM&µ69….\Î\ÔóS«ºAs¤\é{w\Ø¸Šq_’\"˜N2!\Ì`²¦ï°¢išöa\ãE:\Â\Ò\ÂlÀ–\Ö%\Ó)¢?\Í}\É{‹(­\ï\\\æËŒz\ßzó<\ág9|q~]|R?ž8B\ë›gL\î\Í>oMrµ\îHy¸m§\Þ¶D$S€Æ€?\èw„©,a^TŸœ‡¡šX%ÓQeBAŽ\×\â,¥-&£G3ShIH2hab“À´\ÓT\n>Æš\î;\áú\Îl	Š¥}\Z¿g\à*È¢p*‰y©ÝpC™°\Ô–+¡u`XFX\ÎLˆn•º‚	E™\Ü.Uq i…\Ô÷5+‘ý®«fÉ\Éj\Ì\È\É4žœ$Y^\"|gŽs\Ã#Œ?G\ã‰#´ºLýS\Íþmö³jW ]ms\Âý\Éõ°\È,U@Í„¨Ýž\r\Ñ\Ýü·D$\Ïqñ\ã£QZ\Ñ4Th²\Z˜\ÔÛš•«ªmx5\0—835LhfBS\"\à¼\Ë\"\Ì]‹\Ä\çX]qzeû«7ÐŠ¥\'ô#>r%†E!j	÷^Y\çT½R\ÃÄ–>µ}\Ïi©””®!q\î,¿qø\Æõ\Ç\ÆL4\ânŸdy	I#+m2ú\Éõ\ÆGh~\ågwy¨=et€¬¿Ú™O\áaBN†žœ øüª¦ˆ/µXü\Ò\ä\æò˜¤\È\Õ^c?\É\Ûó}\Îc\æ1Žóð\áM}m\Ûbm}H\n\ÚNˆl\\ªšƒï˜”+uLx\ì‚c“ƒ§WJjµYOj¦=ô\ç\ä½n\nû¯¬<x±¦Q€o‹–Ái\å»)Œ³¹\Ø\Ò\\Y B¼‘e»§\nˆmT\ã¤	I~ºLtqž\å“\Óf\Õ+wCÓ\Zô\r©“@Zo´ˆ–—™\\¾ÀþÏŽ¸dL\ß8\Ë\å\ïœ\ÃUŠ4Iðöl%Ô»Ä«	~˜’›a\Â6\æw\Û\ê¿\ê\Zu\ÖÙ‘¶+må“¨c\ãð•\"¨iŽ\Ú\Æ/d°´|^•®•MÚ¾ü@À¹ó#\ïŒ#C\ä=!Y¼\Â|o\ØH\îsª\ÎŠ@¹h6\"\Öwga/‚\åw–\ï	°ÿùÒ€y~`€¥ßŸ\"¹\Ô\â\ÈG1\ã\ËË¤\×CSNµ\Ô`ðû\çŒ\ÃôJ)ôž€ö•(ßœeø…cLÝˆðŽ˜\ØAUsq÷ø\ÜU+”\Ëõ½¯ÑŸ«X\Í\\y\Æi›\ç°\Ú¶?ýy2\Ð\êUAõÁs\ÌžDŒ|P·IJÛŽb6I8Uƒ™û–?\\Ïž\Þ\ZÔŒ>\î£^ž‚÷\æ\ï\Ì!…\Ñ÷£b+ÀG±œp4u\åV\ê¬mò®½°E4\×H%ä¶¼O°ü\Ô3 1\ã\áÏ˜A:	³»}¤\æ2¹¶\á\ì.µ·Ô‚U\ÍE\Ü\ä\Òe\Ú?^$¾a\Ø\Ý\ì\Ø!Â·\ç\Ð{\ê 0ú\ÚYF^>Å¹û\ï\Å\ïõ±mð~nMAn\"¦1”Y8\Ésª[§­d²iý”mQ¤¼Ò¢²uDz\ë\Ú\Þ-(J\Ëk±RDX\0$&\r½VY­™A¸\èá€±\ÖYÔ«\ç`qù~Hò¡ÑƒD¯+\Ía¥™V%}¬^÷	\î¯B_†×‰i¾rŠøjˆ´\Û4NNñ@\n³‹dö\àSkkF%¯„3«š\Ç\Ù\ÝFÕ©v˜\ÆGh}k\Æ\"Q\0¸Ps™ÿ\ÒK/¿\Ä\Ô\ÚZ±]©tW¼T¥Û£ª‘\å÷\æ\Ü \' JmJ.¶o\Ù\ÎWJNòz©\Ó]@o\ÓQK•\"G!¡ \ÖL\è\nIu\àÜ ¦þ\Ê8Ôš…\È!Q[8u=¢-U\íJ™RYT·•T<ª\ë\â\rj¢AM‚I>iˆ¡Q\Ýj¤ñ¼³™‘ÁS,=9Ið\ÅI†¿ùz±k\Ä\ß}°Œ$	Í§\'IzÔ”\Ö\Ýþ·ßŸ$ø\ì°q“\äÜ \æÒ²;x÷?9Ù,b ¬\í¬ª–íž°\ê~°x¤\ÒóÂ”¼r¨M\ÂC¶\Ë0\naþ·T®\Ý–ÞŽ\á\Ñ\ã4¿\ê£kšsZ?\Ñ`4œ‡NÀ;G‘oœ`îµˆý#N¯–/:®4\ÇM\Ýqñú±3F/\Î3³\Z1º¼\ÄB\'fty‰ù{<\Þ\Êb‚7Î°ÿOg˜mG„\rŸ\Ñ÷—E^™¦QqÀ®«¬‡\â9~\Ç\\|\å’\Ä\Ì\Ýs/Þ¾ýŒ½¿T\ì&ñö\Ìx£\ß~ñž(Uó¸0vˆ°9:þ\Þ\Ç\Ö\Ö#Y	‘\ÕooÀlsˆ\á\ï¾\Î\ÄÍ¸o˜m\ï\ä\\À\Ô]¦‡n{XÕ–¶1l\ËE’b].y\Ñ>ƒP¿pJªTU&,v\È|xršp\Ø\çÈôw/ƒÓ€\ï¦ý^\Ì\éWB·¥\Ë\ÈwNi;Š ¶9+k-/\áç¶¥‡G‘$\áø·\Ï1ô\Å)\êŸeé·˜r<ÿ\á‹F[{¤\Éù¯^g\éûŒ\rO®ªŒ^Z†,e\á©	–O¾\Ä\ä\Ú\ZþÁa\Ò\Õ¥\Ëÿø%‚\ÇÆ‘v\ØeYVuŸù§&L \\…2Œ~\ÝDJNE1\Í\çŽ1þž\Ù\ç¦5þC£]\âG/KV˜¼²š\Ù,•²ªxþ\ì¼Üª9öbmý\àÀ\âª=Rùf«—A¢¿>Ê†]t\æHÞ‰8õ­e\Îe”NE\à˜\Ò(L®\îM\Ñ\\)’Ÿ\Ì”\ê\Ð\Éœ}eš™WOÑ¼Ç¨\ÍÁ§Fˆž›\ßG>X„\ëñò\ÒË†j°NòS\n£\êõ\"<%ú\Þ9Z_;\Íðw\Ï1qi	ÿ\à/N™›ú=C{\èzó\Ã#\ë\Ï\Õ/OuY±ƒ/NöeG…›\ëmG(\Ï/÷\ÓA\Åg*•\ßlº¯mË’\ág\ë·\Çð¨7+;bøH )3pTj»®€83{ñ%3Lô\ëòjš\Ë\Ï¨?Z*/n\Ï\Ðzü%N|2›uóõi¥i8ª°mg\Û!cº\Î|\ÒF;Šý5MC¹œm‡4”¢%\Æ\×6¬4Ë’0Qxk5\ÂU\n]S4TI™\n\á\Ô\Ûmòl›\Õ\ìB–\"­WO¡mtc\ë«\'¿w\â\ë!\îÞ€\æ³S„\ç‰.\Î\ã\Öýb÷««\Íg§Ž_\r	¿dµMð\Ù\á‚õ…fw{\èAcøtm]µÛ‡º‡\Ò&dX\á*\Å\å—O\ãbj²¸™)J$\"Æ­“$,À¿<~¥õ7zÜQ¤%†nj\ç¼3¨N|Ý®\ÆP„\å?‹\àú $\Ï\ïgù©—˜¼1+H¤Qœ³Hl‰\Âf@ðöŽ¼2\Í\Â\Ø\×O1qò‘#´ž=Â©\å%\Z/£>¨9sõg~o]¯3þŒ\ã‹f\Ã\àFýwúknêž€%»¡ qr\Zÿ‘1\ÈÊ\Ø\åož%iµpskt\ãjÍ‘K—	ßž\'Z\\À­)&o˜\0·æ—Žò\ÒÀ\0s¿{ˆ\Ö7\Ö\ÇH-þ\Þ!c\Ð\ìÆ ¬³\ÛD‚¼˜Y\'lo2¨l\Ç\×f¿S@R1e\Éûv\ë\îÀ¥tI€\É\Í}Œ\\²*\Èûs(i³ðN\ÌÜµ6‹Y÷ó§mñ\Ý±¹¨‡F™øô:ƒ¡=u\ã&x\ì­$aòÁ!¦\Z†\êuf_>Á[o\Î\âuù`‘ãŒÑ¨\Ä:õ…\r˜»\' ù\É\"\Ú:\\›\ß<\ÃÒ·ð\î\ëA!I\Âþ\'[þ\á,Z)B.¿qŽCo\Î<y„ñ$f\îŽ¾3Gô\ÎÁ\ã¸5Eüa‹\è\â|wL’\Óó?\'ŽQƒ\Ú8o?ªdts¬\Ô\à¨\ÂºlM‘\n«mGL¢\ï[\Ý\Þ\àm\í€r\\rZ2\ê(»cW˜OZ\'8=<\ÍÄµ„³J8Š×•Æ·”hkC£\Ñ\ß?F#ƒ\ãõ€æ£‡i½¿DýÀ£ÐŒ\ã^#M°tq\Þ8“kš\é\'&xýfLp°ŒRã¾¦;´P®b\é\Ñ\î\Ì0“kk\Èõˆ´­£¤ª¦‰\Þ7l}ø‰#(­ñö¸\Ê\å­\'\Æ9;0@\Òj™\'\ç/þpŽ\ÅN°ð\Çi}{¦`[UdÕ„¶\èŠ!\ÓÜªW\Øþ9›À¶Y›€-L\Å\ë\ßwa\á\Î	jÕžô¢•7\æ•\æ\ìµ6\ÓJw\íòUŠi§D¢;¹g\'ú\Ê3«!¡\ÄD?]fö•i\Ø\ã3û\ÂQFŸžD9p¹2ô\èaS\Þ\ë\àû\ç\ì\ï}Ž(\Ù|\Ù\äÔ¹‹u÷Ì¹.\á·fŠcGn¥L\\ºÜ•XÀôˆ~j¶ž?\Çè«§A)\â•\×qñö„o\Ï1³\ÓE\Ú“·\ÖHWÂ¾›T]°1õ\Ý}Ä¡!Qö¯·\àgb\ä¼m([\n\Û\ç\êõ5i¢\0lR¥°ÁZR¤˜«\Æõ\ÜIÜ\0±¤D*÷LŸ8£:p\ÈÑŒ:(o\ã½öwß¡ÿ\ÜÀ%½\áh¾·€û\ÐªÿxŽ¹\×.t	\Û@YÄ°\æ\áz\Z­=Ó¦¤FS“\Ê/AV#†^›¡þhwP\Ú\Ì.S\Ù\Ü\í¡&GÂŸuý\Ýú\ÆYNN\ã\æ%¥ñ\Ä\ÍWOq~`\0}_c½-Ï—¾\ÛG\Õ}¤fD‚d%dø»\ç\Ì\æ\Ê/š¸ðT¯¦‘Nb„\íÕ„‡ÿ\íø•Ö§6\Z¾»Tÿ+!§}¶¹\Ü)\ä¬`3\Ú\ÒpÇ•f\ØÁd\ËýE\"Qµ/¤W­\íg—6û\Ð(\é›géª…\Û{_\å÷V»Þ”öXªl€\È\á\Ð;óx4¡’‡3¾®K´\ÞøòûŸ8\\i\Ðe\É\îÿ×Ÿjš\Ä›ö°V¶Tƒ^÷N‘¬\"ññ\Ò\ÚT¡•¬Á\ìy\ëw\Å\â¬\ßÍ¶?U)r3\æ(Ž¡Ð™I\ã\ë\ß!;»Sw\æ‰_›Afg‰ß˜!ý\Þi\ã\ä|ó\\\í»S¼\ÃöA\íñ9¿³û=\êŸf|y‰\Ñ\ïši\'\Æ\Ûpv—Køý\îªW\Ã_?\Ó\Å½ûŒe{\ìý%†\Ï\Ïl\é\Ò\Ès9)(¢0»r\r‰ö‹\"<‘zª1nS¼S#e¯œÔ´\íSš	G\á)EPSø\Û\Ô\Î\îœž\ß\ÊF;x 4¦Š¦û½us.\ät\ÉY0‘{\Î°ø¥gº®©?<\Ê\Ô\Ú\Z‡\ß[ ]‰ðö,þÁg˜\ê™bÂ»œ´È‡&;KðÄ‘u™FJ\ß~¨J¹\Þ9-(\Ò\Ö/}W¬M*Ti#¸cŠS²8€¶cŒP¨÷½µaÿJÀ<˜§¨m\Û‹µ¨L\Êf·ª=—ÿt¹\Þ^wN\ïkp\è¬\ÖÅ»/ ü\Þ³GY|\î8r=d\è‹S¤\ëW«©\ÉüJÆ“MÁÁ”µ —»ô°¹-\àŽ©\Ü~´Aú]	Š”£ŠÎ°FF\Ã\Êò],e\àXÄ©a(‘g~»öC:sl;\É6—–¤\Ñ|e\Z¯^g¶°øüñu\í\×crm\Ñ\ï¾N`w\Ë\Èõð\ÍYf‡G\ß<‡gSÔ¤I¹K¥ñü±nVe¡j<³H\å†\ÝQ¢ueŒ-k\Ûi\Þ{+KÒ–ˆ\Ô5yÕ¦>–ñ¨?¸y\Ñ9§”…¼\\ü«yd\é-H\ì\Ì\ÍY™²=\Ù~\'z\Ù%}‚ÁG\"†¿9Cø½sÌ¸.\Ë²~vý¡Q†¿ýºAª·\ç\ÐOORh5\è#’¢\r$gA\í	\Ù`mO?ó\ÜJ®õ3\ZsE´Hý¼i`\Û]\ë>l\êt—\à€›VVEž\êw?\ÊT\Õ\Þ\Ý3„©²³ü;\ÂvdÃ\Õ?\\$KûÄ…¯‡\à\é#,>7…·\×g\á«\'ð?;Jý!c¯´h/.¶B¢\ë!­\å%\ÂvÄ»E	:)\ê¾n“t’þšmŸc©emjÐƒ0\Ï=i-Ú®kµÆ¹©\èX\å[å¿²Š\ås\Ã)Þº\ÍR{ómmØº¾\Ù+\å€ÿ¸Bû ±\"ü^²	Šp	Ìž+G¡,rósU3‡X£\ì@>*ý(ªªû´^8A\ã…¥iÁú\ßæŒ·\ÛDºÿ@ƒðJËŒn\Ýg\ézX\Æc÷\Ëq„\'§M&‘^\è6œS$} I{\ÑX\Ó¥\Ê\î\"\é\Ç&«°5\"U30”\Ù&UªÞ³Q—\\¸+Z\Õ\êÁ\Ûª	ª\ÒR\è##Hh¬½Zß«9ó\ÎÔŒf¦Š\Ò$²\ï—\ne‘\äM (\ë^™°$+k\Þvw\\\Ñú\ÖY–¿q\Öì˜­hGK‰‹·w˜¤­k-†ö¤™0ÿ\á’1½@_¤\0H~²Hø\ÆCazÁö­´À+»Y\Òk\Ñ\ÎÎ–\ã“žÅ¤™l\ê\"\ÙEª SšU\â«7	Š\ïeI½¿·Ý›ŠQL\Z¼A\ï\ìY\ãZ™	®tt#,\ç\Õ\Û2ª\ËV\ì’Ð€§Œ|D÷»¥UV\Ö1\ÔH¶<,v\Ü:\ÝT(²brh‹µc\âÏŒ \×B\Þzs³÷#E\Õ}\Ô\íˆù[(¢¶a9\Õ1ºH`À²š~g†\Öó\ÇQƒõþH+\ÈÎ©`©MGÐŸj’\ælð?7sŠ´¹\âð±\ìÃ‚†­ò\ØÆ¤|\Û`\'O\0µG\á\íT\0\Ô\ëp\ÍP	Xõ†›bd“½\Zu-XÁd.EÁ»\Ù2¯|Y “\Û\è•#B‘\r¿º\">\Úú¥ú\ÑÓ¨#\Äq\Ê|»]V,ê¤€BýØ°Uø¿ü½>K«­N¹ñ¡wA*`öñ	š\ZF¸‘|¸lœ¯w.Q‘›s\Ää”\Ôü[\åB+Ò¬°lŽHŽ\Ík\ÛÃ¾ÒžÎ¬\Å;@\"\Ûvýa…wÀúðö)\ÄLþMÀ>\íJb^,õ°o^º\í\"Iˆjj’÷Û°º¡HV4HK`\ÂˆI½Zc¨¦JÁ\Úö\'§D’³³[ö…:ù‹U\âv0±S­NL$B\ëZ‹°\â\Òh 2­fd¬L\Õm&´š2\ÙisóF\ÑjL²\r]$)A«L­öôA¢~¬U\ï?\âQöwWtdî¤–ôc%‘\0›’•V™]\Ù\ÈGý† ~P\á75\Ô“’\Ä¸O”\"yG\àªÀ“6>\'¢6ø\Z²m+õP\ÓT`t\0Á=\Z	…øð\"\n%½/\Å\äÏ½¡h%øJ¡v¹\ëÃ„«$&þ*l›r¬aGXè˜¢‚9X\\4\á½\0Ž¢\áhF=´2NR¯\æ!vnSDÒ¢\ÆZ*	’¤\Å\Ø*eJ¸\êšFoCöL6»&‰q÷í‡•°\Æ[·øŒ\ÂT-Ö¬<C•ó\Ô\Øyü•óq\Ò\Úl&doj\Ð|\ÞÞ¸Ç¶wMlñ.\rx\È%#«=ö:IaUKV0¾” V(\ß3pQ\à¾\\\Ø#$—@û@ ñ]8«‚\Z®\ã\Õ@\Å$D\nv\ëU\å„\n%’LX¾—Wc\Â–ma\Ã*»ö)\'P\ZOy¨šÂ«)p\Ü2‚2/š,B\Ú1œ“Ž\å®$ƒ$‰I\íüxŽ†,¯\ähŽ©J\á\å~\ãutfš	Áó\Ç	_=…\ÛOsë‚œU\\:ýeß»§H\Êé¶ŠlÐ‚$W\roÁ\×d\nõ\é!\ä\ÍyCVÚjd%A\í’7BÒŽpõ\Ó|Áõ\"kø³rŒ¼\r\ê@]£\îk#\ïò~\ì6¯”hÖ¡&\ày¨0&\Ò0óý6(ˆ0»´’^Iˆ*‰³<\Ûo\Â\ÃP“‘š‡\Ö\Z\å(c=V¥D˜Ø¼Š\")I’µ³\Ä÷z\ÐÇ³\åV£\Õ‘”&–6Œ<2\Î\Èp™Dk\î\ä)¤c¨|¾\ë5úLtTŠ+D\"_$r=\Äx\ÔD-l•”½\Ôt‘\Z9úø¡¶Ž\ê‹H¹ê™¯—™ò\×\nžV@AÞ›7f\ãÈ²3ymE\ê\Þ…:hö–\Ë`Œ´Ø­ ô›\È!\ÜLE Brb­P®\ê\ÓuXl^¢a\î\ía¬Œ¬bù»T\ÇP\"É†2Tó\ÐZ™rR5\ÏTývs¢h¨Fl‘$M–WÂ²2”¤\n.Š˜¯¦q÷ú„?½\Ì\Ø\É\ãŒ\ìñ	šM&\ì\ç\Ô\ÞB\ïöHnT\é^¼8Ç‰G\ÆH;m´¸¸Ž2µ\Ô6u\Ù\ã$et\î-ôÃ£\Ì\í4Áo›\Îpõ~‹´®\ï_Špk6÷U¾yr³\Ì¬­ŸÉ°[\Ð\ìkÚ§\á\Ã6J)’\\\â_µ\ç4¨A\r>øû¸A¢\'GU T]!«!`\n÷©è€ºO\áy\Â\å\ÚI\ÊÂŸµXZ\ÂU!ùa\Ù)²c|xŠ@yø6¸\Ë\ÓØ¬$‰\r\äŠW#$\âNb\å\n\ÄI\\”E³dò\np•˜„\ÉWN\áÙ”5gŽL\ÐxtŒ$I\ÅT²T5vuY•\í‡¾8É…¯6®š*\Ù\Í6A\Úm´-´qnó>PAU\ÊD\å9³£f\Ó0’-X›¥H\ÌÝ–œt%Am¨J’÷1¤@=\Ú@>ˆA‰1> D“PP{Ñª®³\ÏGFJ„\Ðbjþ\ì.A\×Q9\Z=\è\á+R\à*\"\ZK’W\n\è$´V£\"‚Álƒ*—ANU\Ã\æ\ÜA¯|‚\á&þ¾ý\\ø“iü=“o\ÌU´£k!3\ÏE€\ÆC£$aH\Ü6ŒGn&(¥h]\\`â§IV£¢’¦ö}\äfl4&†Ÿš º¾³`d%\Ç-¶m’™\Ü\Ú\0\í\ï\ÏÁV¹*»¨Q‰xª\î–\ìPIž)½{_›Rj\ä\Ô&_V\Ëp6\Ê\ë#´¾­h<gYYjŒ~²¢`Ÿýt‰\Å¹D’Ò’·®%]%* l­—º\Ò4µgd•š2\å&·(“™kBqGh­†P‘}ªH\"]2…_@\à4\ZÎ½p‚©o¾\Îþƒ#\ÄQT‰¿2÷ú{–¯·Lm\\›\Í\Ãß·Ÿ¢\ài1\é–\å\ïR\ÈÍ”¹WO3þò‹\åBÐš\ãG˜zùÁgF\Õ¹|zˆ\Öç¡–«\ãyk[,\àN\\\ìP‰ß›\ß\ÂY«º=v\Ï€j4\Ì(\åF\É\ÝÆ²|\Ö6ô@cH®µ»Ž\Ä=KImužœLÇ™\Ñ\Ú®G$/C\ìÀ¼E\0~X†qo)ö+¶j²®\éÂ¦’[˜MVÝ”\Ä\n€q’ZÄ©®ª\ÔRƒ€\Ú\È*hË’&^>…w_€r~0e++Mý\éLù>°\Öû‹øûöw•ÿÌ¡qp„\Öõ\í•’¢•2e¸\ìv¤ä¦­¾¤5³\'§	\Û!\í\å\îÁ‘A´£/µ>c\Ò÷‰Á¾†A~\Ë^L1\ç\r&\ÈQ6Œ|»\ÜP ›\Ô!) \Úf\È\Å¢´loZ\Ôf#D\Ú &¸\ÒþO:)#¹Ši_.Ÿ°$KieF\nE˜«¹\0\\³}d=…QR\ZhŸ@kÃ†,\ä¦\ÛY[9º¿ [\n¸uF;„ a4¥s\ß:gGŠr\åñMƒ	˜\ç9X\ÕBV\ã.ùD2›‡\Û¯a¼\ìÑ•þ}\rÃ¦:	Á¾&‹,÷‰u),ýpŽ¥Î¡QÄ«	A>†™\à\Õ|¤õ°+ƒeFuQ$…¦\èM­“R¯döU5}g^…jñB\ß7FS›\Æ\Ë\Î\æ[b€:\ê\ä\è ÿ¼;XÿµB…÷=ôG WB.´#k\Ù8¢80\ä\Ô-¿\Í\Ë\\¦\à¸x6þ7µ\È\ÐNŒ\Ü\Ò^h·£n_ž©žr~=\0¥¯-\ãQ\Æs§\nN]\\B\â¸k%z{FŸ:\ÌñaC¢\Ö\å\"\0L2…§\ëH\Ò&YM\Ê	²÷\Â÷[$\ív!7\èAÍ‰\ßý\\Ñ¶f\î\åSL\Í^(\nÄŒ~a‚\Ö”•‹\Ô.s\î¹\ãÅž½$\Ë2\"4%|gÁÚŸLž\ïTl\á×¬\\€¥_l½{#”oµmdÒ¼Ÿ?LôýYkT,¯\í™™\ë\âº}\rT¯—Ou[¬MþN²\ZÿZ²j\Ð\Ä\ß\× ¾!\Ú#x¨‰w# •˜v’”;\Z2#+ë°‹vJûGl\rp\æ\å\ã.Òœb}ev°4\nW)\ê÷„´8ô‡S\Ô\ïo\à\Õ}“v\îPae~\às¬9T°¯öÉõ»&”Éˆ‘G\ÇYø\á,\íK-¼|s£$ø\Í!Â‹s\Ä\í?L3cŒ\Û!ñjŒoó0Š¾ºR\ÅÄ’B3@0<Bp_\ÃThLø(¥Hro\áòO¯½hª\0£OOrü®‹@\Ñ\0\0 \0IDAT{3)‘eJ8¶žˆ˜Võk\æe\ÛOôg†\Í~µM\î*\Å\ê\ÚÚ­”\Ùu3.\íG[j;l£Wó\Îi ]i\Ù\"‰	;I!¼¦\Ö*’\Ú,ø¦<©tbI‰“\Øø‰’˜X\â,1eL©”+p~½A\ãSÃŒqŠ‰“\Óyõ“\ß9‡ Ôƒ€ 9d0ŠŒjû@&DWC}ùXA¹´\ß=Xj\Ð/G (\×W\å”Mº.7“\Ò/›‰õšr³;Sœ®wO–’•vù¬L4‘,E‘\ÒDƒ`\ì1…»)‰}\Ä\ì¾5òœ.¯4/¬§%\ë\ØVU\è‡s¤¹p{ò(­+±Zù.w\ëÿ{\ç\Çy\æ÷½ä†º¼s \ïf\n	\Õ\Ü\ÉW/k¡&q¢E…\Ö4|€)Ø­%8€E¸@\Â$E,%ÀÙŒË±)\à\Ðm‘H> \'ùPÄ¾\01(1$6\ÄqCµÐ<T.iT*W¨t7BEtö*\æf\Z\íe\Þ\Øsfÿx\ßw\æ\åò‡7ÿ\Ô@\ìrwv~>\ïó\ãûü\Ê\à?\Ö>\í¦:ÿH¯\Ç,u\âµ\ÙZJ\ÖuF)I‘‘t;$]­\Ís­\'\'8üÇ™x\á$g®¬‘ ˜Y\\`\âÅ“ý\Ú4£\Þ\áK•$ø\r\Éò›ó¨;ª†U\Ñ\ÈcG±\ßu•RLŽµXxµ*\Ý	öGøB’´Wj¶@¸¯‰\â«+ŽÑ¬ˆF´\×_u\æ\åŠp¤>’\ÊC2ÿ\Êl\Él9·\Ò‘\éjŸ£\â¿X \ØS\r¶û\Â$§—œ\ÅfY÷dk\ÄyŸ÷±t\Ó7.TyUôa>»\ß\è]Œ‘\0\ZBOG”Ê·4»l\Îö_jÑª\Ã‚N\'¦s3&)Y–’¨¼\Â\\Œ<y””Œ£ÿz†“‹K\Ì\Ì/0³8\Ïñ\ïÏ’¡h=~„\æÁ\á\îôvRv‘\í\Ä1n\'ù²6®Á\ï5I\â¸.F…`þ•Y9\ØÕŸ#mD\Ê1\åP€$\×+¦ñeHpo“\ÎÕ¸\ÆH\Ñþa¼AI\Òn\×>—¦\Ê5¹\×%\Û^\ÝF\Øþ¬\\œ«N)\Â\Ý!Y\×8}‚‡\à\å¯Mqö\ë35IÖ¹3si$5†R=÷UÏ«µ›:=‡Šÿ\ä\×\În›Nb/wµ„)„\Ë\Ø\Û$Rur\Õ(­ª\ÊK¥˜X!\ÍC&¡\Ê45Wk	™[	\ÚN°7Kz¿=-\éd\"‡B­&º\n•ezúµ½(!Xxó<K¯Ÿ\ÓóUÑ’Ç—\Æ~q÷g\Ú\Ú(gØ ø¡O®²šB ýÚ¶€F¥A7Wp\Ï3K)\è9Á\Ôdy¹/¦ºý°@°tqy·_Eý\Ñjü\Øs3uDÚ‰q)*G\Ä\ÚRö¼S—\ÙnÆ´¿>½3&2\Ç\Ø0(¹\ÄhDýu*)A\ÑÁdo\r­\0µšRU\Õú’›1v\Ñ$\ï´K·\Z¥¡Y\Ñ\ím,c\\]\ÓT4»Õ©VTCp\æ3Lµ8ý¹	\â«m’N¬¥„½1[‰¯´QwŒk\ÝU„÷\é\ã¤k®-£\×Qr#F\î\Ñ^žö¾¤¾\"\Ï	HI42BÒ‰N„<lj–¬Õ§TûA\È\Éùf.\Ísüü,)Áü+\çj#º\ìu\å·ûû·ž1¦Ol!¥¬1¡„Ì¼5_Wsýº®	\r\Ìúƒº¿@\âl²ð\È\Ñ\r\ÛoEJ)“œåœ£Å‘º™ƒ¯\îÀ\Øp\Õ\n¸\ÞSWª±vwÉOH\â+\Ëu;\ÅHµ\Ä-ø+ :8ªm·—*_(F\Óø‡kh\Ö\ì¥\ï!¹\Ö&¹f¬A\Ó\Ø8‹Õ„\ÉlMÇºŠ©‘af=\Ì\é9É‚-w~*½#\Ëh=9ÁôÈœ†\éµFZ=.¯•ºBhµ\ê!PE¶Qú\ØÆ­[PˆdjüAò,­9Y’püÅ—J\é\ãŒû\ß\Ð^®Í¥xd\Ãg\×Ú°iƒ­òJ\Êwy?¬$‘n\Ô\ïAƒ\"Up\ê©	›Ÿ†¢õ\ÄÁ¾\ÕIIœ¦\êvJ8//•x(T\Ù\'‰\Û5Q\éÑ†{Þ¾´P=p º_‡ ²[I‰¥„û›€`ñ\Õ\Ù€\rm\Ë\Ì\\ZÀ”%²m\Ðlµn÷h\×Z\Õ¨ƒ~uT”Rj•\èû•ôGÐ¾¸±À\Öý¸•‘hp\ê©\Ïóü#\ãµ\Îú\áþ\áš\Ç9}”†¸\ê\æ¨\"\'-TY	\"v \Ò\Ü\'Ü§o\Z4D	·\è\Ô\àUl=f«Rm\rþ\ËVÀz‰X£o\ÞÂ«³\èÀ^V†\0³\Z=m{8b\Û3\Ñv•©šM\"\ï–:©\Ë=–\ãªt¼\n ]i¦_R•!üz\Ë?•$û\æI’š\'¤áŒt1±ûr%­‚\å\×\ç˜ýú4gž˜,\ÝrA|uyCŒ \Ý$\Ðj%M¸¯I\ë\á#DCI–\Õ§†![|®–\n¬j \ìbþ Yø}\Zr”™£e‘„G?Â¥’‘:…úa\êÜº\n \ëOi_[\Ö\çvM\×G\Í&ª“8.tt`”0H;ImÕ„÷5‘{CR²\Ò\îH×’º}²;¢õ\ÐM34!˜ÿö\nÉ©G&@ˆ\Ú9x\Òg\æ\ì¹\Ò\Þð\Úc\ìQW\éZZSMª›šAÊ¥*hÀ\Ò[st\Þn“Ýˆ\ë@\ã\Åy„«\ã±ÁX/\ï\Ãý#L\Ï_`ò›\'û\ìD	+$o;\ÇR9¾U\Ì\Íf* \êl»šj©Ì¿P[{6vv+Õ¦º„nŠBmksK¶ofðck\"\Ú\Õ\ËP®¡\Üzü˜f¤v\\³-¢C-Rq{©òL%r(,\ÞÒ†\Ë\ã_9\Îô÷\Ïqfy\Åt\ÞW¥‡z…Œ\éÎŠ6¶\Û7\ÛeÊ¬ZK™~ôpy³\ío0}þr¯¶\âw\Ú5hA…œy\êóº\Å_yYµýu÷\á*ü ;=d¤>ø¥\è¿\ã«mm\n›3\Ø™N\ÝÁ\îk–R*\ïªra•=°@üú9óýÎ£lªÐ*6~¡\ÊÙ»U‡\Þ0B\"…k›C_uòCŸ\Èô|\Îz¤Œ‚\È:UÙ°\0ü\È<ˆ<¯©Ÿö°R7j\Ý{\ÚE]ÍŒü\ÞÁš=\"yù\é\ã\Î\n\r`?û9™û\ÔTNn\Ôm\Ý\Ãò-\ÐU„²of¤@\ÜhW\æWž`½aK \ÈjªÛB\Â\Ä+l\Éóµ­–’i`q‹œ$f6{\ì5ù\0Pxa\Ã\ÜI³U]UÕ¸mA5F\ÊPÿÁ\â‚\Ê`\ì§\æ\Ôm\Å\ì³\Ó:¤\Ò\í\Ôts¸¯\ÉK——8ò\Õgª…Gt@\ç(»“h OT)\Èó\n¸ì‰Ÿ©®ª\ÔW¡˜ü\Ó3Lü\áLýÁ®)¦Ž\Ò^tŒõµoˆ¿;\"¹Ù®´R\n|\\©ƒ’\ÍC:­#¾¼\\1lT\ÆNZ^)Õ¦RŠ0\Ú\\zÅ—«\Þ\á\á^½ˆô9T\ÛE&´3ñ\Ü#ŒÑº_\ãvý(=7!\åŽ\Â\"–Q‚û6J¤\Üz\rª\n\äml¯\Z#)](dß—©–\\fZy{ž‰\ç¦Á\"Ìµ“Tdq\\Ï‹Q924P\Çh,j_m—F¹\\\n)9ù¹	¦=L`Pv+!:0R†drccœû\ãS´/9êª«h=qLÏ²]n\×>G†õù8ªY†!¹\ÑVB66¤\í6Ê„D¢û››\Z¨É­\neR2ù\Âc_9^¹&P*Ì½p\Zo“ö;‹È¡`SŸ:F¿r–ðV90g+RiÓƒ!º_’•l\ÖNÚ†={\Û\Úlºq\ï-ñF›K\Û&\Í@\n(\ÔöDÒ£2†$/e’Ù§Ow²6%H)E8hP®MV†7(‰ö59ú\ågý\'c,|g¶\æ\ê{ô±U\æ\Þde U;Oúø¿\Ú*\Ï\'\Ë\êx’\ìcÄ–\ÛÞ¬$¸\ê*Â½MšŸ®fÓŠF\ëK²Q3B¹\å”\ÇEvi92º¥\Z¬\'ö\'å¨²\Ò\æ*¶T¿\ÃF[.ö¢]Ž\"Mü!#!\Ü)ˆB°ô\æs\ß},¢T	¼%7\Ã»|’\ÕN	J\æ(\â\Å\ÊPG)„™ŠXV_\n!µ1õ\Æ9žycŽ‰ožd\ä‘qš‡Æˆ»\Zb\í»14\×k¼×¤–:F¸\Üšà­‹É»}2(=LW\Í$¸\Þ\Óq\È/\Ã-.ùH’NŒ4¨¿MŒ³v“*@\î	Yº¨GüL|õ¸ð½³Œ=<Nb\×À\è¿yŽ\è«„\Ü\×Ç€v~§\Ð\Ì\â÷\Ä\Ø\Ê\ín\'”4#\'t*\î\Îp$‡~ª\í$W½\ÕUB_Z@\îÖŒ’ÞŒI°øú–~0W»lu\'Õª\íJ›\Ì\Ü8ºû¼³Ar«\Þ3ºy`\ÔD\Õë¶“0\ça›E¨®Ž\à\ë:šQ]«íšºŠö\ë”[Ü 0Ú›cˆ›\í³$\á\ä÷\Ï\é\0õ¥\Æ>;Yg¸ž—C¢ý\'`û\è|m„\ÐjTJ\äž1(I;	\'¶J0õÂ·N\Ñþóy\æ^?«ï•³\ÛK,(Ù€\è©\ã}‹³}\ÞM‘ú7ŸWe¹±ŸnS€°‘2øOú€6H[‘@\Ça|sc‡\Z#[\Õ\ØOr½•RD†\r\Æ\ä<xó°’›q-\â\Æ\â,%W\Û\Úp4¤‘\ìº®²”pwD|µ\Øe¤©Å²¶Xyî»´dIUVá„±É’\â®r¢\Í\éj¼-Vk	Y’6\ë¨||e;ÿ\Õ¢ûG75Ž}$3f\êP‹™\ß?Ì‰ƒ£L?\È\ì\ÓS„N¨\Í\ÉM,.\Õ@÷øºW\ÒZFôN_\É~T€\'C\ÂM¦\äk©\ÉQ:ù_K¤-Sm70Rÿ½<I0†l\í\Ô5\ÒÙ\\ø\ãS¤k‰\Î+\îq_\å›*­\'Žù\Æ&q?×‰ca\ÏQT=\È*t†ôZER¢\îdµcca™\íÖŠN\å\ãq\Ê>Å \Ù6« \nU(<“§žu³¾v™@Êž¾PY†ô}’Õ˜ù\×\Î¿³´ñ‡ù{H\Ã0›\åˆZ\Ö\à \ÝJ\ß{\á‘]6“6\É>°$£°¶P«‹0\ÒÇš¦õ_¾M\ë¿>Iý¨¶_ôCMtJ•\ÒöDC\Ü\Ö~Š¯,\×ö\ã[ \íF=¬\Z:~\ÇI(+\áÁ>®u^±p¸¯It“8n\×6	£ˆøZ\ÛsVŠñ\'&‰\îsT‹\Ê1M5\ë!Ã¬\ÉõaW©\\L®Äˆ»Cy9¨£õ\éZ\Ê\Ò[ó,¾v¾\Ê{B’ÜŒ™:\Ô\â\å/ž`\îk\'i¿9¿)c”‡7±ÀÍ¶s%š,´Ù£¥B/!%Ò¤\ÐÄ¯ß¸“3YŠð¡ñ\Ûª“ g.nõúÁjÿ¼mm£>ß™T\Â\Ó+\×Z÷«&*nVBt`_\ê\àm\ëñ#%\Z¸Á[[©\0„A\ÄB\Í¬£´\Â÷ñ\ÃHHm}:0òð8óožg\éõŒ>~´ÄŽ>6^\æL\å†DYw¿¡\Ç(„\" ¹²‚z/\'\í$t\â˜tM«\ì\åWÏ±ð\êlM\É÷\æb[ÚŠ!¶£²™\ÄP¨÷öFdÁP asWD\ÃL\ÈV˜–8º-Ž:D\\^Ò¹\ç‡Z¨ë½¹\ì9’|-EöÁ\0²\åe\Ôjv\ÈMLóö\ÜDb\Ó\æv\íf¦fJ£¨`|Œ\ía°”¼uªD<#N\ÕZýsq·Vy]\á‘d\ÚJR¹B¾\Ò\n¯Ä¨BÓ„s\á\çûò‰C)\í5ô*^~}®T#y‘#„®ð—— 1³_™¦s­MZ\è}ûTH¶[¹òÿ‚<!ˆ¶H\ã10|°\ÅÊ¥…r1Y¸|bƒ¦Œ\Ý0…ö\Ü\"¥nqo³d$W0l‡y§\×\Úú¾wM\Æß•ú\ÅK¶û‘\ân‡hw³òŠ\n\'v	²Ž¢ýM\Úo-\ÔÊŽ-:œv’\Ú\ç\áî™ý\0\áyLj‘\\m\Ý?b’ÿs¢Qß­\'U–\Ñzhœ…·\æxù©\ãÿ\Î-}rž \Ón3ÿ\Ú,K?8oT1œq:\í»Ò¥c°¿\Ç\ØÝŽ\Ü*IB¦¿;L¾·÷P¡¶\ÙR\rï‰ˆ\ÛZ\Z¥f‘¹6Y­¿S¡‰Y–	¯•$¹¢i™……x°Ç”&©´\èM+wi#A°—\Î\æ¿h¦\É\ÐR\ÉM\Íb£2”B\îòˆ>=\Â\Â[sU‰TÁG\Âójq§K\é*¢{GH®·i>4¦W\å.pŸ¶»\Ú\ç‘{²N¦Ud®h\îm’]\Ó6J¹?L¹¢d\"øÅ¤‹­Üµd™\'Cqúü9†÷\ì‹`e}\ç¿x‚•K\Ä\×\Ú\Û2cŽŽ\àûA@z3\'Y‹I^i#†¢¡¥b\ë\á#Ä—´ò/\ï˜N8\ÓÔ€\å&Ž vús•\×@Y@W»|f\ã@ò:¯´u\ê­5Ö­—¼ñ¾‘F¥ÿ™xFªH^i‡´t‘\Ö+{„\ç¸\ä†\\WºV\åZž‘Ž\íø÷\è†ã¾”dI¢\åº:l\îß\Ô—J•5÷V²\Ô\Õ\Ñ³Wl\×{}1Š\0\íTDAD\ÒI\Ê\ïGh\Ñzdœ\ãOO\áII°/\â\Ô\ÓS(`ñ\ZLôÃøZ»\ï±z)\Ü±ò–.&ˆ\îk¢d«	\ã_:R\Úw\"ðuS‡š²2T\è\âUi*n\Å`O\Ì\Íxvù\Í\í#Ð‹\ØFþ)LE©msÀ70R3K§û\ri²dKˆ\Ó\"\ß0þ3]M¦\ï³\ÊR\Â}‘	‰8©¬wû\Îmð@hw3¾\Ö&¹¾Br%&\ëtt.vs¯ž-EÿB–\Ñ\éÍŒÛ­< û]bRù-£÷FL~}š¹Wg™{ó<\Ó\ß>Í±/§}u™\ÉZ\Ì^ü1­\æo\äý\ä\Ü\æ¾ó2KWV8¼˜•õuÔše\Ói11~\Øô¤\ÛZú¥dŒ=~Œxq™pÿ(\ÙZ†…¨6\È}\Æ\ÐôH\ã\Ø\\s9­¨\n³X†ixzº6\Z-\ï\×}Mm7 ›\"(¦Ì…\Ú:D²‘²NgWY\ê³		t\Ê\Òø3µ½¸ »z˜‹òC\ÍT\í\Å%\Ò\Õj-!‰\ãR\ÝLµœ}Ö™\Â+\çó‚lv¤Dî´kþ\âi^?\Ï\Âò+·×‰o\Äd·bŽ?z˜©oŸd\â÷$\ZŠ8}ö£´ö8ý½Y\î\äœý–ž‡›¹GÂŒ\ïTJ\Ñ\Ü‘­e|xœs¯¼\Ì\Ò\Åyf¾y’\ävÂ¹o\é{\rvŒŒBq\nÈ¤òB‡Mºº\ë¿\'©\0‘)¢Ý‘Nö/*ûT€\î\à\ì?»¼´!û1¢\Ï\ÔÇ¡\Ö(SUEIc³\Ç\Ùù¸ö`H\î=¼–\ÅyC°\ì\Ø>.)L^·”´\Z¾i¦©AKO€òIW\íz\×yBn\"û/J½mù™iu3þ…If\Í\Ã\ÎPZBtÃ»<.\\Z\àð¡I\ÂÊ¥%\Æ\' N½qgŽeò\ß\Îp\â\Ù)\Æ>n­0q¨\Å\ì¥N}eŠö\â2/]þ1ñÍ˜©C‡ñ\É\Ê\ÛË¥§iUl¥Z+[Ð½w\î«{m¶%³™Z‡@”-“cÑ¾ˆ \ÉÒ”\Ä\0­ªGÚ¤*\'1\Òqd´\ÊQj Sp²Œñži”.u^?\Ï\Ê\×gt>”Ð¶®uròfüoÎ¯už\Û\ì·5‰6\Ä?Ô£Â›aJ@%6Ó›Z)“W-6Àü”\ê]Òª\ím\ÖB‡Ÿœ`\ìñq><\Îì·ž§L>9\Éó\Ç&8÷\êY\0\æ4\ÏR’\"I\"1>\ÐšZ,ŠÉ¯>w\Ï>C´\Ë\ãÄ¡5==Å™?9E€`\âžQ–o,#Ä«\Êi›£¦\ßR\Ús¾Û¹Û–i”£v%†ø\ä\à\ãGñ£€ñÇŽ\"¤\äü«gyù\ÅÓ¤‰o´´M#\Ñ=U\ÆAzµ\Ø[\Ï@\ØZ9A\Ú\Î*\Ð»SE´\Õ©)¼\Ï’\Å\Õl\ÛÇ¯„1qL§‘_³d‹0§^8\Íô\Ó\'ûôA0õ\Â)’›1óß¿À\Ü+gu«>Ç¿9C|e	o`€\ÐsX\ã«1Ù˜ñ=!­‡\Æ99w`€8M‘ƒ’\Ïj\ÑB0<0@($§¾1\Í0’öŸ/\Ñ\Z\0a’ö¶‘>\0‚\Øa\Û£š\åT‘\èó>Ù€\ÑA\ß\Ì_A?n\Â\ã\ÈòR\ß\\¡#O\ãÈ“Ç¶¼‡‹\ÝÀD\ÙÍ˜\èK›s’‹óeó²Zò¿þ\ËX[©Ú‚!y\ßÑµ\ì¿É†\ï‹8óN\\^x//&\èÀhk0D(\ÈTºs¼d´BF²¾\Î\Ùobü³“Ì¿vŽôV\Ì\Ñg§˜<\Ø\Â’¥wI€d}\é\Ï}ž™?{I3ƒ\íRò\âKDû‡™<\Ô*\ãTy¡½¼^u\ë§Ýˆ:l\ì\Å\ÔK½Ÿ ”4!£aHd\ÔwL¡©üH\íjZK*\Óý†¿tœƒ/œ\Ü\è\Æ÷¡\ìZ›ù\æ0boT÷Ž öDŒ\Í]\Ø9œ»g\Øt\â5^š2±L¥8¹\Zÿ\áù,û÷›ý¶\Üm\ØÿðMñUi½LT»\ØF•†»ÿ ”­v8ö\ÕgX|sŽ\æQf0”:žuü\Ïf™‚\Ù\ï\è,g¾û2\Ñ\î¨T¦>’©§>¯ªµ§\nUJ—q\ÜB \Þ9Š½¶Ó€™-\×D\Òc$÷„z\Ê6h§«{\r}{$¤>+z†ty‰Ñ¯M#Œn:\r){{™ùGÆ‘ûš}>2¾3ø\Ù\æ\Ø7ôó\Ý)•›Žù/†Íˆ\ÑO\"}	oŸ\Úö\ÇyA”3û0(\ä\î€p`\08·¸Àü›\çyþ‹\'P\nžÿÜ¤•\0\ÃŒ\"9ûp$õ<­ú\Ù,ccµŒè«Šô¶Ú Ž¤\ä\ÈPXw¯\Ñ/vù•4øî‹¿7Bu:,<u¥rr\'£¡:/4)LuŽ‘(\åb¹\Óüò\Öj\r¥\êR\Ïvþ\ße°\Â\Æ\ÖI%#eWÛ¿>ú\Ø8\Â¨;ª\×dW³D\ÛH(j\r§>ò‘üöÀ\0\ÃFšLl\á!¹ðY\ïS\ÚW²jh\Å\í¿\ÔC–QüM$‹Àô«,ÕŠú]S\n”\ÖG£.‹m—µ’>\ÄÅ¥ñ=\Ä`ÿ^#AzÀ\Ã\èñ-\\~CKø¡©qµv™¶\È\ï¡C`··9=M²¡;­Š!•l‘e\È>Da.\à\ÃUn‘#]”q¯\íQ¶“.°¹\Z²N¹\çn³û®\Î \æ\Õ\æ@9aŠúk‰äª‹\Âì¹¡œÿ? \ÕÔc•\ÇPDOl±”ßŒ+w}\Ãy(\ÒB\Ý\Úö4)\'‚Î•e\È:å‰¸7\ß\ïñR˜\èsµ]½û\']¡Ž­¸L\Ò\Ë*ön-\í\\\Ì{=\nB\á7l\"›–\Zª4nû“{\Þnšq?\Élƒ¥\ÞP¨›0\Ø}¡‘òª¾¢ZnÓªf9\ØS–TN¢´{5&x¤\îQIJÑ¹¼¬\ç\Ö%¹Ž—¾‡3~L°\ÜU?\Üj\r€	\éÿ°õÀ4ó¯Ï±d ~û¸Z%IPµ‡!L²X™\"b>¯÷¶\Þ\è	¹\n¡WºTª¨N‘Q#´T(²B6Á $SŠ\ÈxJ\0e\Ç3\Ýlœ¤«}s\ÜiOú+§@)¥“÷\Z\èIE&öfº¥}¯Ø²Ÿ†\Æq¼]:GK7c\ÍMeŠ§%ŽÙ°¹D€01,\åz6V\ÍZif=>\Û]\ÖR9\ÞÁþ\ÆÄ­”+\êF›‘_b;ê¼½L\ÞIðºªª3”Fµ‰œ“7ã§¶\ÛG`tß™{uNwµÀ&û\ëó¶c–k­¾y¾‚´‘š\ÞJjƒ4©K5QS\'ö\Õk	…Àûx˜\ìn[T\ßatžÆ¶~®“\ZûI9U¹}\ró;÷:|S?\æ7Œ$²¿+ U:©>±Ÿ“?%%â±£ø\í%Z]\Ê\n‚µ%ÂœK9\ïiþ^¶|.Tep=2°T£\Õ\ïj\ßY¦3RW@\Ó\äÁ\ï\Ímƒ9¤——ô\ÔM)wr®r–¶’\ß}ù\ïo»sk\îŠo&+…\Ò\î¼„R\"\×t¬\'7A€\Äa\Ñø\r\íO\Ñc5S‡\Ñ*&©\0:\×+ò…N\Å\\°©O-§¡\ncÄŠ†(ó±u&¦(<˜¹=ŠÐ´[È†\î5”8¿I-iE¡½Å²S¬\Ù_\Ô\ÐÌ–Ôá´›\áwS8r”so\Í3v;!,L~U£’eÎ•p›J²8†¹\ÂH=+‘`\ÛJlü®!´T+(¥—”¨k\í1€ºk³«XP\Ùûí†¸«y\ì\è»S\ÏNý£\í\0x\æ‰#ßˆ..L×š4`nM!\Ì\êH\Ñ\Ý\ÜÚ‡\"<’µ¤d0\ßamSeQÞˆ:•%\áö¡\Û/z\â|\Ê~Ö°\Ê\Í/H\ÐÇ‹,Jk¥¤~\æúf\êªEa%Z\í»ûš~n†…«Kw\ÉRF³L\Ûh\ï\åå‚¨•cZ+6(­d8ËŒJ\ék„\ê}T†\nPk= GA`<Z„Œ]úñ\æ7\ÊP–e\ïŸ<6QdB¤Aø±Ö‘ŸN?;õ/²µ\ì?£\ë-»Xj¨’µ¬\ZÙ€^‰²\Ð\Æõ(’¶Q[Ô€e\\\ä¨\Êî±‹\\²*®œKu,0<•JsUHiCô\ZÍ®2°³h\í¾TQ§\ßyõû¼Àj“ù\ì÷\Òýý\Õ6\çŽ%¼·\É\ä+³Ä·b\æ;	IW¡n\ÅDYJX@p½­¥^O÷;÷ú\Ê*c+Ùª\×ZcR›\ÚÑ­ŒU`\ntÆ®¯\Ôv½®\ÔúÏ³Œ\å\å¥÷hßŒ¡\á\rD÷Dw~vò\ãB\Â0\\=0\ê¿avü.;e$÷\×F\Ð\"^•v\æ\ÆyBj#²›2f\ÔL¢\ê!.\Ãöƒ$K—ü d\å\åÿª\nÖ­Á\é5Bú,ÝŒ/{\r=7Mùxƒ’øfüWi–ý6b\Í~»\êŽ=c\Ñp&	ñI\Ñ\à.£*>\í‹ö«5!\Þ\È;2\Í}\Ñ=¾”ŸÊ•\"[¹wd„B\r¨nF\ÖIIlv&u\ÆtIõ¼÷{	gŠ7\Ã0DJI³«h\n’,#.r>Q7Et\Ñ\í\ì}º\é€¥d£ôúº «t9•™Nr\Î\ê*„¨ŽªŸRˆN‚°\æ;õl-eiyy}yyi=Uj \ë¦2\ï\Z94F(ýr¬–RŠ\é\ç¦\ß\0~\×\\Þ»h–Ý²\É\ÒV•Oð½’³3X•ƒò6…:\×Q\êù\àÿ\Z\0>ŽRƒÀ\ÏþWž\çxN]¤wR²µL7¶\ÏLe%º.”Ò‰ö*_º;\Ë\0…Z÷r \È\\u_»¼õ\î¯÷ˆ\0\0§IDAT\ÜTx¨†XWƒb@	O3w–ø{#¤–4„C¡\Îu2^m\Ç \ä¹\Êñ„G0ð\à\ï?øÏŸ¡…\ïÿ4¯\ï±©´e‰\ÉG´-\r˜¿¿ü&š™~WJù\Ï\Î|ûÌ¿ª‡gcXB\àýš1j\êö\Ê~®\êr0%U˜:;\ë\í¹Å N¿G+­…õ}R…*¡Žd-!I\æßšÿ\ëÅ¿X¼ü%ð7Àÿ\0~‚\îL“²Cõö#ýrd\É~­\íþ!ð[cŒ}9‚\ß\Þ?ü© ð„\ç\Ä\à¨\íYœ\ÊUo½\Öf¢G­7*¦ªEû­m\åþ¦P\äÝœøVLûZû\ç\í+\íN¼\Z\ßV]õ°ŠVaÿø+4}$‘~…d\éhuð€=h\éô1\àSh&”Rþf„CbPx¾\ï2\Úýº”ò.!\Ä]þ\ÝþÇ…%cy6¾aÔCK	„¤*En\æ\ï*¥Š<\Ï\×\ã\ÕøN§\ÓùYš¦?o\Ä?É²,î ™\åÿ \ä}t\ãO\Ñ\æ\Þ\Zð\×hõöó\Ùû|\ÄH¿\Z@3Œ‡f(ó¯_?Ž¶›<´|øºLþ.ó›\à“\èn\îŸg^\ï~¬S=\Ðw\Í\ë\Ï\Í_6\íÿ\ÖPþ;*Fx\×üo‘\ÍL‹fœw\Íû¿5¿ý¹\Ù~G^\ÛGŒô\á\Ð\0s|\Í0Ÿ bžO8\ßUR\å!\Ú\ß\ÚT\r\Ëdýž\Ï:s¬S=\ì÷\Í{÷\Ïz]ï™¿¿C3\Ì{hF±ß½k\Þ\Îþ\\\Æ\Ý\Ñ\røˆ>º‹Š¡\ZT\Ó\ïý€yÿ1ó\ê2\â@\ÏÔÁõž?—‘\Þwþ·\Ìd?³ªÌ†\Ý\ï\Þwþ\Ü\ã\ì˜>b¤ŸÜ‡\ß\ËsÞ»Œ‡ó\Úû—\Ö{\Þo\Æ\\P1†ýþý>Ûºÿ\ï\Å\îG1Ò¯†z\ïóf÷½\ß\ç\îgýôfÿƒ~þK\Ñÿ5ƒ\â\Õ%\\I\ß\0\0\0\0IEND®B`‚',1,1,1,0,'','',1,0,1,'1234567890124/1,1234567890125/1,1234567890123/1',0,1,0,0);
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
INSERT INTO `transactionitems` VALUES (5,1,1234567890124,1,0,'Pc',10,20,0,20,'Doritos Nacho',0,1,'',0,NULL,0),(5,2,1234567890125,1,0,'Pc',5,10,0,10,'Coca Cola',0,1,'',0,NULL,0),(5,3,1234567890123,1,0,'Pc',5,10,0,10,'Herashey bar',0,1,'',0,NULL,0),(6,1,1234567890124,2,0,'Pc',10,20,0,40,'Doritos Nacho',0,1,'',0,NULL,0),(6,2,1234567890125,2,0,'Pc',5,10,0,20,'Coca Cola',0,1,'',0,NULL,0),(6,3,1234567890123,2,0,'Pc',5,10,0,20,'Herashey bar',0,1,'',0,NULL,0),(6,4,1234567890126,1,0,'Pc',20,40,0,40,'Paq 1|  1   Doritos Nacho|  1   Coca Cola|  1   Herashey bar',0,1,'',1,NULL,0),(7,1,1234567890124,1,0,'Pc',10,20,0,20,'Doritos Nacho',0,1,'',0,NULL,0),(7,2,1234567890125,1,0,'Pc',5,10,0,10,'Coca Cola',0,1,'',0,NULL,0),(7,3,1234567890123,1,0,'Pc',5,10,0,10,'Herashey bar',0,1,'',0,NULL,0);
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
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,1,2,500,'2016-01-16','09:28:00',0,0,1,7708704,2,1,'-NA-',100,'1234567890123/100',0,0,0,'-NA-',0,0,1,'',0,0),(2,1,2,10000,'2016-01-16','09:29:00',0,0,1,1970730888,2,1,'-NA-',1000,'1234567890124/1000',0,0,0,'-NA-',0,0,1,'',0,0),(3,1,2,5000,'2016-01-16','09:30:00',0,0,1,7708704,2,1,'-NA-',1000,'1234567890125/1000',0,0,0,'-NA-',0,0,1,'',0,0),(4,1,2,20,'2016-01-16','09:34:00',0,0,1,7708704,2,1,'-NA-',1,'1234567890126/1',0,0,0,'-NA-',0,0,1,'',0,0),(5,1,1,40,'2016-01-18','21:52:00',40,0,1,1,2,1,'',3,'1234567890124/1,1234567890125/1,1234567890123/1',0,0,0,'',20,1,1,NULL,3,0),(6,1,1,120,'2016-01-18','21:52:00',120,0,1,1,2,1,'',7,'1234567890124/2,1234567890125/2,1234567890123/2,1234567890126/1',0,0,0,'',60,1,1,NULL,3,0),(7,1,1,40,'2016-01-18','21:53:00',40,0,1,1,2,1,'',3,'1234567890124/1,1234567890125/1,1234567890123/1',0,0,0,'',20,1,1,NULL,3,0),(9,1,1,10,'2016-01-19','13:38:00',0,0,1,16424376,1,1,'NA',1,'1234567890123/1',0,0,0,'NA',5,1,1,NULL,4,2.1301104714e-314);
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

-- Dump completed on 2016-01-19 15:38:30
