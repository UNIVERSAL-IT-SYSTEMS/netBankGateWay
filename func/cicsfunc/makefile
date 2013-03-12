.SUFFIXES:
.SUFFIXES: .c .o .ccs

HOME=/home/netbank_mid

INCL=-I/usr/lpp/cics/include -I$(HOME)/include

OBJS=cicsfunc.o
TARGET=libcicsfunc.a

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar ruv $(HOME)/lib/$(TARGET) $(OBJS)

.c.o:
	xlc_r -c $< $(INCL) 

.ccs.c:
	cicstran -lC $*
