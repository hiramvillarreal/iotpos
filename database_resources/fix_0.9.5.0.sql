# Fixes to migrate from 0.9.5.0 to 0.9.5.1 database version
# (C) Miguel Chavez Gamboa 2009-2011 [GPL v2 or later]
#
# run this as: cat fix_0.9.5.0.sql | mysql -u root -p


use lemondb;

ALTER TABLE reservations ADD `profit` double unsigned NOT NULL default '0';
ALTER TABLE reservations ADD `discount` double NOT NULL default '0';
ALTER TABLE reservations ADD `item_discounts` varchar(1000) collate utf8_general_ci default '';


