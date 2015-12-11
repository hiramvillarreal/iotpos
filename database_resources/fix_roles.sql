# This is a fix to set admin user with Administrator role

use lemondb;

#First we reset to everyone as a basic role (vendor)
update users set role=1;

#Then only to the admin username set the Administrator Role.
update users set role=2 where username='admin';