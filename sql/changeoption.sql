sp_dboption middb,"select into/bulkcopy", true
go
use middb
go
checkpoint
go
use master
go
sp_dboption middb,"trunc log on chkpt", true
go
use middb
go
checkpoint
go
use master
go
sp_dboption middb,"ddl in tran", true
go
checkpoint
go
