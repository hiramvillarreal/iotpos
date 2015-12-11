# (C) 2007-2010, Miguel Chavez Gamboa [GPL v2 or later]
# run this as: cat lemon_mysql.sql | mysql -u root -p

CREATE DATABASE lemondb;
USE lemondb;

CREATE TABLE IF NOT EXISTS `transactions` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `clientid` int(10) unsigned NOT NULL,
  `type` smallint(5) unsigned default NULL,
  `amount` double unsigned NOT NULL default '0',
  `date` date NOT NULL default '2009-01-01',
  `time` time NOT NULL default '00:00',
  `paidwith` double unsigned NOT NULL default '0.0',
  `changegiven` double unsigned NOT NULL default '0.0',
  `paymethod` int(10) NOT NULL default '0',
  `cardtype` int(10) NOT NULL default '1', #since March 19 2012.
  `state` int(10) NOT NULL default '0',
  `userid` int(10) NOT NULL default '0',
  `cardnumber` varchar(20) character set utf8 collate utf8_general_ci,
  `itemcount` int(10) unsigned NOT NULL default '0',
  `itemslist` varchar(1000) character set utf8 collate utf8_general_ci NOT NULL,
  `points` bigint(20) unsigned NOT NULL default '0',
  `discmoney` double NOT NULL default '0',
  `disc` double NOT NULL default '0',
  `cardauthnumber` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  `utility` double NOT NULL default '0',
  `terminalnum` int(10) unsigned NOT NULL default '1',
  `providerid` int(10) unsigned NOT NULL default 1 , #for Purchase orders
  `specialOrders` varchar(1000) collate utf8_general_ci default '',
  `balanceId` bigint(20) unsigned NOT NULL default '1',
  `totalTax` double NOT NULL default '0',
  PRIMARY KEY (`id`),
  KEY  `SEC` (`clientid`, `type`, `date`, `time`, `state`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE TABLE IF NOT EXISTS `products` (
  `code` bigint(20) unsigned NOT NULL default '0',
  `name` varchar(255) NOT NULL collate utf8_general_ci default 'unknown',
  `price` double unsigned NOT NULL default '0.0',
  #stock changed on aug 11 2011 for 0.9.4rc9. Allows NEGATIVE STOCK. Requested feature.
  `stockqty` double NOT NULL default '0', 
  `cost` double unsigned NOT NULL default '0',
  `soldunits` double unsigned NOT NULL default '0',
  `datelastsold` date default '2009-01-01', 
  `units` int(10) unsigned collate utf8_general_ci NOT NULL default '0',
  `taxpercentage` double unsigned NOT NULL default '15',
  `extrataxes` double unsigned NOT NULL default '0',
  `photo` blob default NULL,
  `department` int(10) unsigned NOT NULL default 1,
  `category` int(10) unsigned NOT NULL default 1,
  `subcategory` int(10) unsigned default 1,
  `points` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `alphacode` VARCHAR( 30 ) NULL,
  `vendorcode` VARCHAR( 30 ) NULL,
  `lastproviderid` int(10) unsigned NOT NULL default '1',
  # for grouped and on-demand-made products (special orders)
  `isARawProduct` bool NOT NULL default false,
  `isAGroup` bool NOT NULL default false, #this is not necesary, with groupElements we can know if its a group
  `groupElements` varchar(1000) collate utf8_general_ci default '',
  `groupPriceDrop` double unsigned NOT NULL default 0,
  #The next fields are in preparation for the taxmodels... it will be included in the near future.
  `taxmodel` bigint(20) unsigned NOT NULL default 1,
  #Added on Aug 11 2011, for 0.9.4rc9
  `hasUnlimitedStock` bool NOT NULL default false,
  `isNotDiscountable` bool NOT NULL default false,
  PRIMARY KEY  (`code`),
  KEY `SEC` (`department`, `category`, `subcategory`, `name`, `alphacode`, `vendorcode`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE TABLE IF NOT EXISTS `bundle_same` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `product_id` bigint(20) unsigned NOT NULL,
  `qty` double NOT NULL default 2,
  `price` double NOT NULL default 2,
  PRIMARY KEY  (`id`),
  KEY `SEC` (`product_id`, `qty`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

#One credit per customer. Accepts +/- amounts for credit/debit.
CREATE TABLE IF NOT EXISTS `credits` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `customerid` bigint(20) unsigned NOT NULL,
  `total` double NOT NULL default '0.0',
  PRIMARY KEY  (`id`),
  KEY `SEC` (`customerid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

#One credit_history to have a record of each credit applied.
# + for credit given to customer
# - for credit payments or deposits.
CREATE TABLE IF NOT EXISTS `credit_history` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `customerid` bigint(20) unsigned NOT NULL,
  `saleid` bigint(20) unsigned NOT NULL DEFAULT 0,
  `amount` double NOT NULL default '0.0',
  `date` date NOT NULL,
  `time` time NOT NULL, 
  PRIMARY KEY  (`id`),
  KEY `SEC` (`customerid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


# special orders are special products, each order is a product containing one or more rawProducts
# each time its sold one, it is created. If you want predefined products use instead grouped product.
# TODO: Implement offers for special orders

CREATE TABLE IF NOT EXISTS `special_orders` (
  `orderid` bigint(20) unsigned NOT NULL auto_increment,
  `name` varchar(255) NOT NULL collate utf8_general_ci default 'unknown',
  # group elements are each products code/qty ['1/3,9/1']
  `groupElements` varchar(1000) collate utf8_general_ci default '',
  `qty` double unsigned NOT NULL default 1,
  `price` double unsigned NOT NULL default '0.0',
  `cost` double unsigned NOT NULL default '0',
  `units` int(10) unsigned collate utf8_general_ci NOT NULL default '0',
  `status` int(10) default 0, # 0: pending, 1: inprogress, 2:ready, 3:delivered, 4: cancelled
  `saleid` bigint(20) unsigned NOT NULL default 1,
  `notes` varchar(800) collate utf8_general_ci default '', #MCH CHANGED from 255 to 800. March 22 2010.
  `payment` double unsigned NOT NULL default '0',
  `completePayment` bool default false,
  `dateTime` datetime NOT NULL default '2009-01-01',
  `deliveryDateTime` datetime NOT NULL default '2009-01-01',
  `clientId` bigint(20) unsigned NOT NULL default 1,
  `userId` bigint(20) unsigned NOT NULL default 1,
  PRIMARY KEY  (`orderid`),
  KEY `SEC` (`saleid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `offers` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `discount` double NOT NULL,
  `datestart` date NOT NULL default '2009-01-01',
  `dateend` date NOT NULL default '2009-01-01',
  `product_id` bigint(20) unsigned NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `measures` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

#For the way to manage taxes, the config option "taxIsIncludedInPrice" is taken into account.
#If this option is TRUE, the tax is going to be added to the product price, like in the USA.
#If this option is FALSE, the tax is not added, just calculated for informative use. Like in Mexico.

CREATE TABLE IF NOT EXISTS `taxmodels` (
`modelid` bigint(20) unsigned NOT NULL auto_increment,
`tname` VARCHAR(50) NOT NULL,
`elementsid` VARCHAR(50) NOT NULL,
PRIMARY KEY  (`modelid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `taxelements` (
`elementid` bigint(20) unsigned NOT NULL auto_increment,
`ename` VARCHAR(50) NOT NULL,
`rate` double unsigned NOT NULL,
PRIMARY KEY  (`elementid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `balances` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `datetime_start` datetime NOT NULL default '2009-01-01',
  `datetime_end` datetime NOT NULL default '2009-01-01',
  `userid` bigint(20) unsigned NOT NULL,
  `usern` varchar(50) collate utf8_general_ci NOT NULL,
  `initamount` double NOT NULL,
  `in` double NOT NULL,
  `out` double NOT NULL,
  `cash` double NOT NULL,
  `card` double NOT NULL,
  `transactions` varchar(1000) collate utf8_general_ci NOT NULL,
  `terminalnum` bigint(20) unsigned NOT NULL,
  `cashflows` varchar(1000) collate utf8_general_ci default '',
  `done` bool NOT NULL default false,
  PRIMARY KEY  (`id`),
  KEY `SEC` (`datetime_start`,`datetime_end`, `userid` )
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE TABLE IF NOT EXISTS `departments` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `categories` (
  `catid` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`catid`),
  KEY `SEC` (`text` )
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `subcategories` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`id`),
  KEY `SEC` (`text` )
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


#-- intermediary table for m2m relations
CREATE TABLE IF NOT EXISTS `m2m_department_category` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `department` int(10) unsigned default '0',
  `category` int(10) unsigned default '0',
  PRIMARY KEY  (`id`),
  KEY `SEC` (`department`,`category` )
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `m2m_category_subcategory` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `category` int(10) unsigned default '0',
  `subcategory` int(10) unsigned default '0',
  PRIMARY KEY  (`id`),
  KEY `SEC` (`subcategory`,`category` )
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `users` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `username` varchar(50) collate utf8_general_ci NOT NULL default '',
  `password` varchar(50) collate utf8_general_ci default NULL,
  `salt` varchar(5) collate utf8_general_ci default NULL,
  `name` varchar(255) collate utf8_general_ci default '',
  `address` varchar(255) collate utf8_general_ci default NULL,
  `phone` varchar(50) character set utf8 collate utf8_general_ci default NULL,
  `phone_movil` varchar(50) collate utf8_general_ci default NULL,
  `role` int(10) unsigned default '0',
  `photo` blob default NULL,
  PRIMARY KEY  (`id`),
  KEY `SEC` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `clients` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `code` varchar(13) collate utf8_general_ci default '000001',
  `name` varchar(255) collate utf8_general_ci default '',
  `since` date NOT NULL default '2009-01-01',
  `address` varchar(255) collate utf8_general_ci default NULL,
  `phone` varchar(50) character set utf8 collate utf8_general_ci default NULL,
  `phone_movil` varchar(50) collate utf8_general_ci default NULL,
  `points` bigint(20) unsigned default '0',
  `discount` double NOT NULL,
  `photo` blob default NULL,
  PRIMARY KEY  USING BTREE (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `cardtypes` (
`typeid` int(10) unsigned NOT NULL auto_increment,
`text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
PRIMARY KEY  (`typeid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `paytypes` (
  `typeid` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`typeid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `transactionstates` (
  `stateid` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`stateid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `transactiontypes` (
  `ttypeid` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`ttypeid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `so_status` (
  `id` int(10) unsigned NOT NULL default 0,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `bool_values` (
  `id` int(10) unsigned NOT NULL default 0,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE TABLE IF NOT EXISTS `transactionitems` (
 `transaction_id` bigint(20) unsigned NOT NULL,
 `position` int(10) unsigned NOT NULL,
 `product_id` bigint(20) unsigned NOT NULL,
 `qty` double default NULL,
 `points` double default NULL,
 `unitstr` varchar(50) default NULL,
 `cost` double default NULL,
 `price` double default NULL,
 `disc` double default NULL,
 `total` double default NULL,
 `name` varchar(255) default NULL,
 `payment` double default 0,
 `completePayment` bool default false,
 `soId` varchar(255) default "",
 `isGroup` bool default false,
 `deliveryDateTime` datetime default '2009-01-01',
 `tax` double default 0,
 UNIQUE KEY `transaction_id` (`transaction_id`,`position`),
 KEY `product_id` (`product_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `cashflow` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `type` smallint(5) unsigned NOT NULL default '1',
  `userid` bigint(20) NOT NULL default '1',
  `reason` varchar(255) default '',
  `amount` double unsigned NOT NULL default '0',
  `date` date NOT NULL default '2009-01-01',
  `time` time NOT NULL default '00:00',
  `terminalnum` int(10) unsigned NOT NULL default '1',
  PRIMARY KEY  (`id`),
  KEY SEC (`date`, `time`, `type`, `userid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `cashflowtypes` (
  `typeid` int(10) unsigned NOT NULL auto_increment,
  `text` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  PRIMARY KEY  (`typeid`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;



CREATE TABLE IF NOT EXISTS `providers` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `name` VARCHAR( 255 ) collate utf8_general_ci default '',
  `address` varchar(255) collate utf8_general_ci default NULL,
  `phone` varchar(50) character set utf8 collate utf8_general_ci default NULL,
  `cellphone` varchar(50) collate utf8_general_ci default NULL,
  PRIMARY KEY  (`id`, `name`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

#CREATE TABLE IF NOT EXISTS `products_providers` (
#  `id` bigint(20) unsigned NOT NULL auto_increment,
#  `provider_id` int(10) unsigned NOT NULL,
#  `product_id` bigint(20) unsigned NOT NULL,
#  `price` double unsigned NOT NULL default '0.0', #price?? implement later if decided
#  PRIMARY KEY  (`product_id`, `provider_id`)
#) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


# Introduced on Sept 7 2009. #Fix on Feb 25 2012: changed new stock and old stock to double, because stock is double, not int.
CREATE TABLE IF NOT EXISTS `stock_corrections` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `product_id` bigint(20) unsigned NOT NULL,
  `new_stock_qty` double NOT NULL,
  `old_stock_qty` double NOT NULL,
  `reason` varchar(255) collate utf8_general_ci NOT NULL,
  `date` varchar(20) NOT NULL default '2009-01-01',
  `time` varchar(20) NOT NULL default '00:00',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

# Some general config that is gonna be taken from azahar. For shared configuration
CREATE TABLE IF NOT EXISTS `config` (
  `firstrun` varchar(30) character set utf8 collate utf8_general_ci NOT NULL,
  `taxIsIncludedInPrice` bool NOT NULL default true,
  `storeLogo` blob default NULL,
  `storeName` varchar(255) character set utf8 collate utf8_general_ci NULL,
  `storeAddress` varchar(255) character set utf8 collate utf8_general_ci NULL,
  `storePhone` varchar(100) character set utf8 collate utf8_general_ci NULL,
  `logoOnTop` bool NOT NULL default true,
  `useCUPS` bool NOT NULL default true,
  `smallPrint` bool NOT NULL default true,
  `db_version` varchar(10),
  PRIMARY KEY  (`firstrun`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `logs` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `userid` bigint(20) unsigned NOT NULL,
  `date` varchar(20) NOT NULL default '2009-01-01',
  `time` varchar(20) NOT NULL default '00:00',
  `action` varchar(512) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `random_msgs` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `message` varchar(512),
  `season` int(10) unsigned NOT NULL default 1,
  `count` bigint(20) unsigned NOT NULL default 0,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE TABLE IF NOT EXISTS `currencies` (
`id` bigint(20) unsigned NOT NULL auto_increment,
`name` varchar(512),
`factor` double NOT NULL default 1,
PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `reservations` (
`id` bigint(20) unsigned NOT NULL auto_increment,
`transaction_id` bigint(20) unsigned NOT NULL,
`client_id` bigint(20) unsigned NOT NULL,
`date` date NOT NULL default '2010-01-01',
`status` int(5) unsigned NOT NULL default 1,
`payment` double unsigned NOT NULL default '0',
`total` double unsigned NOT NULL default '0',
`totaltaxes` double unsigned NOT NULL default '0',
`profit` double unsigned NOT NULL default '0',
`discount` double NOT NULL default '0',
`item_discounts` varchar(1000) collate utf8_general_ci default '',
PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `reservation_payments` (
 `id` bigint(20) unsigned NOT NULL auto_increment,
 `reservation_id` bigint(20) unsigned NOT NULL,
 `date` date NOT NULL default '2010-01-01',
 `amount` double unsigned NOT NULL default '0',
 PRIMARY KEY  (`id`),
 KEY `SEC` (`reservation_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE TABLE IF NOT EXISTS `folios_cbb` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `pool_id` varchar(100) collate utf8_general_ci NOT NULL,
  `numero` varchar(100) collate utf8_general_ci NOT NULL UNIQUE,
  `usado` bool NOT NULL default true,
  `valido` bool NOT NULL default true,
  PRIMARY KEY  (`id`,`numero`),
  KEY `SEC` (`pool_id`, `usado`, `valido`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `folios_pool` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `fecha_aprobacion` date NOT NULL,
  `num_aprobacion` varchar(100) collate utf8_general_ci NOT NULL UNIQUE,
  `folio_inicial` varchar(100) collate utf8_general_ci NOT NULL,
  `folio_final` varchar(100) collate utf8_general_ci NOT NULL,
  `cbb` blob default NULL,
  `cantidad` bigint(10) UNSIGNED NOT NULL default 0,
  PRIMARY KEY  (`id`,`num_aprobacion`),
  KEY `SEC` (`fecha_aprobacion`, `num_aprobacion` )
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `facturas_cbb` (
  `fecha` date NOT NULL default '2012-01-01',
  `folio` varchar(100) collate utf8_general_ci NOT NULL,
  `folio_num_autorizacion` varchar(100) collate utf8_general_ci NOT NULL,
  `folio_fecha_autorizacion` date NOT NULL,
  `valida` bool NOT NULL default true,
  `nombre_cliente` varchar(100) collate utf8_general_ci default '',
  `rfc_cliente` varchar(100) collate utf8_general_ci default '',
  `direccion_cliente` varchar(255) collate utf8_general_ci default '',
  `transaction_id` bigint(20) unsigned NOT NULL default 0,
  `subtotal` double unsigned NOT NULL default 0,
  `impuestos` double unsigned NOT NULL default 0,
  `impuestos_tasa` double unsigned NOT NULL default 0,
  #--POR el momento concentra los impuestos en una sola linea. Tendra que soportar varias (IVA mas otros impuestos como al tabaco, etc..)
  `descuentos` double unsigned NOT NULL default 0,
  `total` double unsigned NOT NULL default 0,
  PRIMARY KEY  (`folio`),
  KEY `SEC` (`nombre_cliente`, `rfc_cliente`, `valida`, `fecha`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;


CREATE OR REPLACE VIEW `v_transactions` AS
select
concat( DATE_FORMAT( t.date, '%d/%m/%Y' ) , ' ', TIME_FORMAT( t.time, '%H:%i' ) ) AS datetime,
t.id AS id,
t.clientid AS clientid,
t.userid AS userid,
t.itemcount AS itemcount,
t.disc AS disc,
t.amount AS amount,
t.date AS date
from transactions t
where t.type = 1 and t.state=2 order by datetime; #group by hides some transactions

CREATE OR REPLACE VIEW `v_transactionitems` AS
select
concat( DATE_FORMAT( t.date, '%d/%m/%Y' ) , ' ', TIME_FORMAT( t.time, '%H:%i' ) ) AS datetime,
t.id AS id,
ti.points AS points,
ti.name AS name,
ti.price AS price,
ti.disc AS disc,
ti.total AS total,
t.clientid AS clientid,
t.userid AS userid,
t.date AS date,
t.time AS time,
ti.position AS position,
ti.product_id AS product_id,
ti.cost AS cost
from (transactions t join transactionitems ti)
where ((t.id = ti.transaction_id) and (t.type = 1) and (t.state=2));


CREATE OR REPLACE VIEW `v_transactionsbydate` AS
select `transactions`.`date` AS `date`,
count(1) AS `transactions`,
sum(`transactions`.`itemcount`) AS `items`,
sum(`transactions`.`amount`) AS `total`
from `transactions`
where ((`transactions`.`type` = 1) and (`transactions`.`itemcount` > 0) and (`transactions`.`state`=2))
group by `transactions`.`date`;

CREATE OR REPLACE VIEW `v_groupedSO` AS
select * from `special_orders`
group by `special_orders`.`saleid`;

CREATE OR REPLACE VIEW `v_transS` AS
select
 `transactions`.`id`,
 `transactions`.`userid`,
 `transactions`.`clientid`,
 `transactions`.`date`,
 `transactions`.`time`,
 `transactions`.`state`,
 `transactions`.`itemslist`,
 `transactions`.`terminalnum`,
 `transactions`.`itemcount`
 from `transactions` WHERE (`transactions`.`state`= 1) AND (`transactions`.`type` = 1) AND (`transactions`.`itemcount` > 0)
order by `transactions`.`id`;

# ---------------------------------------------
# -- Create the database user for lemon...   --

# This user is for connecting to mysql... which makes queries to mysql.
#If setting up a network of POS add each host (@box1, @box2, @box3)
#Here are only 'localhost' to ensure nobody else can do any changes from other host.

# Note: if you change the password to the lemonclient user (which is a must),
# also re-grant it again with the new password. see the grant clause below.

#CREATE USER 'lemonclient'@'localhost' IDENTIFIED BY 'xarwit0721';
GRANT ALL ON lemondb.* TO 'lemonclient'@'localhost' IDENTIFIED BY 'xarwit0721';


# CREATE lemon users (users using lemon, cashiers... )
#With password 'linux'. Note that this password is salt-hashed (SHA56).

INSERT INTO lemondb.users (id, username, password, salt, name, role) VALUES (1, 'admin', 'C07B1E799DC80B95060391DDF92B3C7EF6EECDCB', 'h60VK', 'Administrator', 2);

##You may change the string values for the next fields


#Insert a default measure (very important to keep this id)
INSERT INTO lemondb.measures (id, text) VALUES(1, 'Pc');
#Insert a default client
INSERT INTO lemondb.clients (id, code, name, points, discount) VALUES (1, '000001', 'General', 0, 0);

#Insert a default department/category/subcategory
-- INSERT INTO lemondb.categories (catid, text) VALUES (1, 'None'); --This is used as a root category. Used ONLY for pointing to a root category at subcategories.
INSERT INTO lemondb.categories (catid, text) VALUES (1, 'General');
INSERT INTO lemondb.departments (id, text) VALUES (1, 'General');
INSERT INTO lemondb.subcategories (id, text) VALUES (1, 'General');

#Insert default card types (very important to keep these ids)
INSERT INTO lemondb.cardtypes (typeid, text) VALUES(1, 'None');
INSERT INTO lemondb.cardtypes (typeid, text) VALUES(2, 'Credit VISA');
INSERT INTO lemondb.cardtypes (typeid, text) VALUES(3, 'Credit MC');
INSERT INTO lemondb.cardtypes (typeid, text) VALUES(4, 'Debit VISA');
INSERT INTO lemondb.cardtypes (typeid, text) VALUES(5, 'Debit MC');
#Insert default payment types (very important to keep these ids)
INSERT INTO lemondb.paytypes (typeid, text) VALUES(1, 'Cash');
INSERT INTO lemondb.paytypes (typeid, text) VALUES(2, 'Card');
INSERT INTO lemondb.paytypes (typeid, text) VALUES(3, 'Internal Credit');
#Insert default transactions states (very important to keep these ids)
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(1, 'Not Completed');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(2, 'Completed');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(3, 'Cancelled');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(4, 'PO Pending');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(5, 'PO Completed');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(6, 'PO Incomplete');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(7, 'Reservation');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(8, 'Internal Credit');
INSERT INTO lemondb.transactionstates (stateid, text) VALUES(9, 'Internal Credit');

#Insert default transactions types (very important to keep these ids)
INSERT INTO lemondb.transactiontypes (ttypeid, text) VALUES(1, 'Sell');
INSERT INTO lemondb.transactiontypes (ttypeid, text) VALUES(2, 'Purchase');
INSERT INTO lemondb.transactiontypes (ttypeid, text) VALUES(3, 'Change');
INSERT INTO lemondb.transactiontypes (ttypeid, text) VALUES(4, 'Return');
#Insert default cashFLOW types
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(1, 'Normal cash OUT');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(2, 'Money return on ticket cancel');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(3, 'Money return on product return');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(4, 'Normal Cash IN');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(5, 'Cash IN Reservation');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(6, 'Cash OUT Reservation');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(7, 'Cash IN Credit Payment');
INSERT INTO lemondb.cashflowtypes (typeid, text) VALUES(8, 'Cash IN Debit');

#Insert default provider
INSERT INTO lemondb.providers (id,name,address,phone,cellphone) VALUES(1,'No provider', '-NA-', '-NA-', '-NA-');

INSERT INTO lemondb.so_status (id, text) VALUES(0, 'Pending');
INSERT INTO lemondb.so_status (id, text) VALUES(1, 'In Progress');
INSERT INTO lemondb.so_status (id, text) VALUES(2, 'Ready');
INSERT INTO lemondb.so_status (id, text) VALUES(3, 'Delivered');
INSERT INTO lemondb.so_status (id, text) VALUES(4, 'Cancelled');

INSERT INTO lemondb.bool_values (id, text) VALUES(0, 'NO');
INSERT INTO lemondb.bool_values (id, text) VALUES(1, 'YES');

INSERT INTO lemondb.config (firstrun, taxIsIncludedInPrice, storeLogo, storeName, storeAddress, storePhone, logoOnTop, useCUPS, smallPrint, db_version) VALUES ('yes, it is February 6 1978', true, '', '', '', '', true, true, true, '0950');


#--The next data is ignored by lemon, but required to work properly.
#--mexico_taxes.sql moved here to avoid common problems due to not running it.
INSERT INTO lemondb.taxmodels (modelid,tname,elementsid) VALUES(1,"Exento", "1");
INSERT INTO lemondb.taxelements (elementid, ename, rate) VALUES (1,"Exento de impuestos", 0);

INSERT INTO lemondb.taxmodels (modelid,tname,elementsid) VALUES(2,"General","2");
INSERT INTO lemondb.taxelements (elementid, ename, rate) VALUES (2,"IVA", 16);

INSERT INTO lemondb.taxmodels (modelid,tname,elementsid) VALUES(3,"Cigarros", "2,3");
INSERT INTO lemondb.taxelements (elementid, ename, rate) VALUES (3,"Impuesto al tabaco", 5);

INSERT INTO lemondb.taxmodels (modelid,tname,elementsid) VALUES(4,"Comunicaciones","3,4");
INSERT INTO lemondb.taxelements (elementid, ename, rate) VALUES (4,"Impuesto a las comunicaciones", 2);


