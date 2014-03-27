/* ============================================================ */
/*   Database name:  Model_1                                    */
/*   DBMS name:      Sybase SQL Server 11                       */
/*   Created on:     2003-07-03  12:29                          */
/* ============================================================ */

use middb
go

/* ============================================================ */
/*   Table: TRANS_SEQURE */
/* ============================================================ */
drop table TRANS_SEQURE 
go
create table TRANS_SEQURE 
(
	biz_date	char(14)	not null,
	biz_id		int 		not null,
	biz_step_id     int  		not null,
	biz_seq_no      char(60)	null,
	bank_seq_no	char(8)		null,
	card_no		char(20)	null,
	trans_amt	char(17)	null,
)
go
