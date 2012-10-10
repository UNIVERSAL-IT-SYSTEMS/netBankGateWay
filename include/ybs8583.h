/*
 * Name:	8583.h
 */

#ifndef _8583
#define _8583

/* ISO 8583 Message Structure Definitions */

struct  ISO_8583 {              

        int    len;             /* data element max length */
        unsigned char    type;  /* bit 0--x, bit 1--n×ó¶ÔÆë, bit 2--z bit 3--b*/
        unsigned char    flag;  /* length field length: 1--LLVARÐÍ 2--LLLVARÐÍ*/

};

struct len_str {
        short  len;
        char   *str;
};

struct data_element_flag {
        short bitf;
        short len;
        int   dbuf_addr;
};

typedef struct  {
        struct  data_element_flag f[128];
        short   off;
        char    dbuf[10240];
        char    message_id[10];
} ISO_data;

struct element_struc {
        short bitno;           /* element no */
        short type;            /* 0--default value, 1,2--process function */
        short len;             /* when type=0, len=length of defaule value */
        void  *pointer;        /* pointer of value or process function */
};

struct  trans_bitmap_struc {
        short trans_type;                /* transaction type */
        char  message_id[10];
        short element_number;            /* number of elememts */
        struct element_struc *element;   /* transaction element ally */

};


#endif
