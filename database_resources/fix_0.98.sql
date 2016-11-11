# Fixes to migrate from 0.9.7  to 0.9.8.0 database version
# (C) Hiram R Villarreal 2015-2016 [GPL v2 or later]
#
# run this as: cat fix_0.98.sql | mysql -u root -p
use iotposdb;
ALTER TABLE products CHANGE stockqty stockqty double NOT NULL default '0';
ALTER TABLE clients ADD e_mail VARCHAR(60) AFTER phone;
ALTER TABLE users ADD e_mail VARCHAR(60) AFTER phone;
