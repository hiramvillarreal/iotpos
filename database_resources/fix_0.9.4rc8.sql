# Fixes to migrate from 0.9.4rc8 (or rc7,6,5,4,3,2) to 0.9.5.0 database version
# (C) Miguel Chavez Gamboa 2009-2011 [GPL v2 or later]
#
# run this as: cat fix_0.9.4rc8.sql | mysql -u root -p


use lemondb;

ALTER TABLE products CHANGE stockqty  stockqty double NOT NULL default '0';
ALTER TABLE products ADD `hasUnlimitedStock` bool NOT NULL default false AFTER `taxmodel`;
ALTER TABLE products ADD `isNotDiscountable` bool NOT NULL default false AFTER `hasUnlimitedStock`;
ALTER TABLE clients  ADD   `code` varchar(13) collate utf8_general_ci default '0000000000000' AFTER `id`;


CREATE TABLE IF NOT EXISTS `reservation_payments` (
 `id` bigint(20) unsigned NOT NULL auto_increment,
 `reservation_id` bigint(20) unsigned NOT NULL,
 `date` date NOT NULL default '2010-01-01',
 `amount` double unsigned NOT NULL default '0',
 PRIMARY KEY  (`id`),
 KEY `SEC` (`reservation_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
