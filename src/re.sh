cd /tmp
>netbank_mid_log.log
>zxz1.log
>8087.log
>8082.log

kill -9 `ps -e|grep mid_server|awk '{print $1}'`
echo 'mid_server is offline!\n'

cd /home/netbank_mid/src/subtrans/
make clean
make
cd /home/netbank_mid/src
make clean
make
/home/netbank_mid/bin/mid_server
