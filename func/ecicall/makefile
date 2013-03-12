.SUFFIXES:
.SUFFIXES: .cp .c .o

HOME=/home/netbank_mid

CFLAGS = -DCICS_AIX -c

INCL=-I. -I"/usr/lpp/cicscli/include"

ALL: lib

lib : ecicall.o
	ar ruv  $(HOME)/lib/libecicall.a ecicall.o

.c.o:
	xlc_r4 $(CFLAGS) $*.c $(INCL)
