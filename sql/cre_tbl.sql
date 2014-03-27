/* ============================================================ */
/*   Database name:  Model_1                                    */
/*   DBMS name:      Sybase SQL Server 11                       */
/*   Created on:     2003-07-03  12:29                          */
/* ============================================================ */

use middb
go

/* ============================================================ */
/*   Table: TRANS_DEF */
/* ============================================================ */
drop table TRANS_DEF
go
create table TRANS_DEF
(
	biz_id		int		not null,
	biz_no		char(33)	not null,
	biz_memo	char(65)	not null,
	biz_detail	char(255)	null,
	ico_name	char(65)	null,
	state		char(2)		null,
    	constraint PK_TRANS_DEF unique (biz_id,biz_no)
)
go

/* ============================================================ */
/*   Table: TRANS_STEPS_DEF */
/* ============================================================ */
drop table TRANS_STEPS_DEF
go
create table TRANS_STEPS_DEF
(
	biz_id		int		not null,
	biz_step_id	int		not null,
	biz_next_step	char(255)	null,
    	constraint PK_TRANS_STEPS_DEF unique (biz_id,biz_step_id)
)
go

/* ============================================================ */
/*   Table: TRANS_VIEW_DEF */
/* ============================================================ */
drop table TRANS_VIEW_DEF
go
create table TRANS_VIEW_DEF
(
	biz_id		int		not null,
	biz_step_id	int		not null,
	serino		int		not null,
	input_lable	char(33)	not null,
	input_memo	char(65)	not null,
	input_name	char(33)	not null,
	input_type	char(33)	not null,
	input_size	int 		not null,
	input_value	char(255)	null,
	view_mod	int		not null,
	word_type	int		null,
	check_sign	int		null,
    	constraint PK_TRANS_DEF unique (biz_id,biz_step_id,serino)
)
go
