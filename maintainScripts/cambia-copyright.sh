#grep -Rl --exclude-dir=.svn "2007 by Miguel Chavez Gamboa" *

sed -i 's/2007 by Miguel Chavez Gamboa/2007-2009 by Miguel Chavez Gamboa/g'  *.*
sed -i 's/by Miguel Chavez Gamboa     /by Miguel Chavez Gamboa/g'  *.*
