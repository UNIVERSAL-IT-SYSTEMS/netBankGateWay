.SUFFIXES: .cp .c .o

HOME=/home/netbank_mid

CFLAGS = -DCICS_AIX -c

INCL	=	-I. -I"/usr/lpp/cics/include" -I"/sybcl/include" \
		-I"$(HOME)/include" 

HEADFILE=

CFILE= dbconn.c
OBJFILE= dbconn.o

TARGET=libdbfunc.a

ALL: 	$(TARGET)

$(TARGET) : $(OBJFILE)
	ar ruv  $(HOME)/lib/$(TARGET) $(OBJFILE)

.cp.c:
	cpre -y -m -a $<

.c.o:
	xlc_r $(CFLAGS) $(INCL) $<
