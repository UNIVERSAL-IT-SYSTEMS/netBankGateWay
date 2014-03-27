disk init
name='middb',
physname='/dev/rmiddblv',
vdevno=4,
vstart=,2
size=65536
go

disk init
name='midlog',
physname='/dev/rmidloglv',
vdevno=5,
vstart=2,
size=65536
go

create database middb 
on middb = 128
log on midlog = 128
go

