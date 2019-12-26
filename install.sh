#!/bin/bash
echo "Update the package list"
sudo apt-get update
echo "installing required programs"
sudo apt-get install kdebase-runtime libqt4-dev build-essential g++ cmake gettext libqt4-sql-mysql kdelibs5-dev -y
echo "installing mysql"
sudo apt-get install mariadb-client mariadb-server -y
echo "begin build"
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix`
make
echo "installing IOTPOS"
sudo make install
echo "install complete now to setup database"
cd ..
cd database_resources
cat iotpos_mysql.sql | sudo mysql -u root -p
echo "all done :)"
