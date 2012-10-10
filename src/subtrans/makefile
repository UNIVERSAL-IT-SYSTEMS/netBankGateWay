.SUFFIXES: .cp .c .o

HOME=/home/netbank_mid
WORKDIR= $(HOME)

CC=cc
CFLAG=-c -g -DDEBUG $(CPSRC) $(INCL) $(LIBDIR) $(SYBLIB) $(SYBLIB1)

AR=ar
ARFLAG=ruv

ESQL=cpre
ECFLAGS= -V CS_VERSION_100 $(INCL)

INCL=-I$(HOME)/include -I$(SYBASE)/include -I/usr/include

LIBDIR= -L$(WORKDIR)/lib -L$(SYBASE)/lib  -L/usr/lib
CPSRC=$(SYBASE)/include/sybesql.c

SYBLIB1 = -lct -lcs -lcomn -ltcl -lintl  
SYBLIB =-lcs_r.so -lct_r.so -ltcl_dce.so -lcomn_dce.so -lintl_r.so  

OBJS=	subtrans482101.o  \
	subtrans482102.o  \
	subtrans482101_tc.o  \
	subtrans482102_tc.o  \
	subtrans482103_tc.o  \
	subtrans928460.o  \
	subtrans461191.o  \
	subtrans482108.o  \
	subtrans482110.o  \
	subtrans482111.o  \
	subtrans482112.o  \
	subtrans482115.o  \
	subtrans482116.o  \
	subtrans482171.o  \
	subtrans482172.o  \
	subtrans482173.o  \
	subtrans482131.o  \
	subtrans482132.o  \
	subtrans482133.o  \
	subtrans482134.o  \
	subtrans482135.o  \
	subtrans481152.o  \
    	subtrans481143.o\
    	subtrans482145.o\
    	subtrans482147.o\
   	subtrans482149.o\
    	subtrans482138.o\
	subtrans482139.o\
	subtrans482136.o\
    	subtrans482140.o\
    	subtrans482159.o\
    	subtrans482180.o\
    	subtrans482181.o\
    	subtrans482182.o\
    	subtrans482183.o\
    	subtrans482184.o\
    	subtrans482999.o\
        subtrans460244_df.o\
        subtrans460245_df.o
 
	
TARGET=libsubtrans.a
TARGET_DIR=$(HOME)/lib/

all : $(TARGET)

new : clean $(TARGET)

$(TARGET) : $(OBJS)
	$(AR) $(ARFLAG) $(TARGET_DIR)$(TARGET) $(OBJS)

.cp.o:
	$(ESQL) $(ECFLAGS) $<
	$(CC) $(CFLAG) $(?:.cp=.c)
	@rm $(?:.cp=.c)

.c.o :
	$(CC) $(CFLAG) $< $(INCL)

clean :
	@rm -f $(OBJS)
