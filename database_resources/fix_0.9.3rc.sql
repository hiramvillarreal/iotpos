# Fixes to migrate from 0.9.3 rc1 or rc2 to 0.9.3 final release database version
# (C) Miguel Chavez Gamboa 2009-2010 [GPL v2 or later]

use lemondb;

CREATE TABLE IF NOT EXISTS `currencies` (
`id` bigint(20) unsigned NOT NULL auto_increment,
`name` varchar(512),
`factor` double NOT NULL default 1,
PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;