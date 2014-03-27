disk init
name='middb',
physname='/dev/rmiddblv',
vdevno=19,
vstart=2,
size=32700
go

disk init
name='midlog',
physname='/dev/rmidloglv',
vdevno=20,
vstart=2,
size=16320
go

create database middb 
on middb = 64
log on midlog = 32
go
