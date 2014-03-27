disk init
name='middb',
physname='/dev/rmiddblv',
vdevno=8,
vstart=2,
size=32766
go

disk init
name='midlog',
physname='/dev/rmidloglv',
vdevno=10,
vstart=2,
size=16382
go

create database middb 
on middb = 64
log on midlog = 32
go

