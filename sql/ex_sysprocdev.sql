DISK INIT
     NAME='sysprocsdev_ex2',
     PHYSNAME='/dev/rsybprocex2_lv',
     VDEVNO=4,
     SIZE=16350
go

alter database sybsystemprocs on sysprocsdev_ex2=32
go
