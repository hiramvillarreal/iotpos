#!/bin/bash
sudo apt-get update
sudo apt-get install kdebase-runtime libqt4-dev build-essential g++ cmake gettext libqt4-sql-mysql kdelibs5-dev
sudo apt-get install mysql-client mysql-server 
cd ~
git clone https://github.com/hiramvillarreal/iotpos
cd iotpos 
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix`
make
sudo make install
cd ~/iotpos/database_resources

cat iotpos_mysql.sql | sudo mysql -u root -p