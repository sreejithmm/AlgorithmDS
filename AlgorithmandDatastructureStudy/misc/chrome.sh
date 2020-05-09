#!/bin/sh
echo $1
if [ $1 == "web" ];
then
	open -a "Google Chrome" "http://$2"
else
	echo "Opening Local page"
	open -a "Google Chrome" $1
fi
