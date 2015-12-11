# Fixes to migrate from 0.9.4rc1 to 0.9.4rc2+ database version
# (C) Miguel Chavez Gamboa 2009-2011 [GPL v2 or later]

use lemondb;


INSERT INTO lemondb.transactionstates (stateid, text) VALUES(7, 'Reservation');

CREATE TABLE IF NOT EXISTS `reservations` (
`id` bigint(20) unsigned NOT NULL auto_increment,
`transaction_id` bigint(20) unsigned NOT NULL,
`client_id` bigint(20) unsigned NOT NULL,
`date` date NOT NULL default '2010-01-01',
`status` int(5) unsigned NOT NULL default 1,
`payment` double unsigned NOT NULL default '0',
`total` double unsigned NOT NULL default '0',
`totaltaxes` double unsigned NOT NULL default '0',
PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
