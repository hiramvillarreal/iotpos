# Fixes to migrate from 0.9.3 to 0.9.4 database version
# (C) Miguel Chavez Gamboa 2009-2010 [GPL v2 or later]
#
# run this as: cat fix_0.9.3.sql | mysql -u root -p
# ------
# NOTE: Please read the README-TAXMODELS. You need to add your own tax models and populate its elements.
# ------


use lemondb;

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

ALTER TABLE products ADD `taxmodel` bigint(20) unsigned NOT NULL default 1 after groupPriceDrop;




