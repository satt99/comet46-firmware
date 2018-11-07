#!/bin/bash
echo
echo '============================= PROGRAMMING ============================='
HEX=`readlink -f precompiled/precompiled-basic-right.hex`
du -b $HEX
{
	echo "reset halt";
	sleep 0.1;
	echo "flash write_image erase $HEX";
	sleep 10;
	echo "reset";
	sleep 0.1;
	exit;

} | telnet localhost 4444

echo
echo '============================== FINISHED ==============================='
