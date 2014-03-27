DISK INIT
     NAME='sysprocsdev_ex3',
     PHYSNAME='/dev/rsybprocex3_lv',
     VDEVNO=28,
     SIZE=4090
go

alter database sybsystemprocs log on sysprocsdev_ex3=8
go
