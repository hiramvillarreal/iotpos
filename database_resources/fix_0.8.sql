# Fixes to migrate from 0.8 to 0.9 database version
# (C) Miguel Chavez Gamboa 2009-2010 [GPL v2 or later]

use lemondb; 

alter table transactions add `providerid` int(10) unsigned NOT NULL  default 1 after terminalnum;
alter table transactions add `specialOrders` varchar(255) collate utf8_general_ci default '' after providerid;
alter table transactions add `balanceId` bigint(20) unsigned NOT NULL default '1' after specialOrders;
alter table products add `isARawProduct` bool NOT NULL default false after lastproviderid;
alter table products add `isAGroup` bool NOT NULL default false after isARawProduct;
alter table products add `groupElements` varchar(255) collate utf8_general_ci default '' after isAGroup;
alter table transactionitems add `payment` double default 0 after name;
alter table transactionitems add `completePayment` bool default false after payment;
alter table transactionitems add `soId` varchar(255) default "" after payment;
alter table transactionitems add `isGroup` bool default false after soId;
alter table transactionitems add `deliveryDateTime` datetime default '2009-01-01' after isGroup;
alter table balances add `cashflows` varchar(250) collate utf8_general_ci default "" after terminalnum;
alter table balances add `done` bool NOT NULL default false after cashflows;

DROP TABLE IF EXISTS `group_elements`;
DROP TABLE IF EXISTS `groups`;
DROP TABLE IF EXISTS `lots`;

CREATE TABLE IF NOT EXISTS `special_orders` (
  `orderid` bigint(20) unsigned NOT NULL auto_increment,
  `name` varchar(255) NOT NULL collate utf8_general_ci default 'unknown',
  # group elements are each products code/qty ['1/3,9/1']
  `groupElements` varchar(255) collate utf8_general_ci default '',
  `qty` double unsigned NOT NULL default 1,
  `price` double unsigned NOT NULL default '0.0',
  `cost` double unsigned NOT NULL default '0',
  `units` int(10) unsigned collate utf8_general_ci NOT NULL default '0',
  `status` int(10) default 0, 
  `saleid` bigint(20) unsigned NOT NULL default 1,
  `notes` varchar(255) collate utf8_general_ci default '',
  `payment` double unsigned NOT NULL default '0',
  `completePayment` bool default false,
  `dateTime` datetime NOT NULL default '2009-01-01',
  `deliveryDateTime` datetime NOT NULL default '2009-01-01',
  `clientId` bigint(20) unsigned NOT NULL default 1,
  `userId` bigint(20) unsigned NOT NULL default 1,
  PRIMARY KEY  (`orderid`),
  KEY `SEC` (`saleid`)
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

CREATE TABLE IF NOT EXISTS `stock_corrections` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `product_id` bigint(20) unsigned NOT NULL,
  `new_stock_qty` bigint(20) unsigned NOT NULL,
  `old_stock_qty` bigint(20) unsigned NOT NULL,
  `reason` varchar(50) character set utf8 collate utf8_general_ci NOT NULL,
  `date` varchar(20) NOT NULL default '2009-01-01',
  `time` varchar(20) NOT NULL default '00:00',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

CREATE TABLE IF NOT EXISTS `providers` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `name` VARCHAR( 20 ) NULL,
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

#Some general config that is gonna be taken from azahar. For shared configuration
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


CREATE OR REPLACE VIEW `v_groupedSO` AS
select * from `special_orders`
group by `special_orders`.`saleid`;

CREATE OR REPLACE VIEW `v_transS` AS
select `transactions`.`id`,
  `transactions`.`userid`,
  `transactions`.`clientid`,
  `transactions`.`date`,
  `transactions`.`time`,
  `transactions`.`state`,
  `transactions`.`itemslist`,
  `transactions`.`terminalnum`
from `transactions` WHERE (`transactions`.`state`= 1) AND (`transactions`.`type` = 1)
order by `transactions`.`id`;

CREATE TABLE IF NOT EXISTS `random_msgs` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `message` varchar(512),
  `season` int(10) unsigned NOT NULL default 1, #can be the month of year (1,2,3,4..) in which display the msg
  `count` bigint(20) unsigned NOT NULL default 0,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

INSERT INTO lemondb.config (firstrun, taxIsIncludedInPrice, storeLogo, storeName, storeAddress, storePhone, logoOnTop, useCUPS, smallPrint) VALUES ('yes, it is February 6 1978', true, '', '', '', '', true, true, true);

INSERT INTO lemondb.so_status (id, text) VALUES(0, 'Pending');
INSERT INTO lemondb.so_status (id, text) VALUES(1, 'Ready');
INSERT INTO lemondb.so_status (id, text) VALUES(2, 'Delivered');
INSERT INTO lemondb.so_status (id, text) VALUES(3, 'Cancelled');

INSERT INTO lemondb.bool_values (id, text) VALUES(0, 'NO');
INSERT INTO lemondb.bool_values (id, text) VALUES(1, 'YES');


#--FIX THE providerid where not being an existent one.
update transactions set providerid=1 where transactions.providerid NOT IN (SELECT providers.id from providers);

update transactionitems set isGroup=false;
update transactions set balanceId=1;
