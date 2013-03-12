.SUFFIXES:
.SUFFIXES: .c .o

HOME=/home/netbank_mid

CC=cc
CFLAG=-c
AR=ar
ARFLAG=ruv

INCL=-I$(HOME)/include
OBJS=fstring.o ftcp.o ffile.o ftime.o flog.o fipc.o fmoney.o fconfig.o sockcomm.o
TARGET=libmisc.a
TARGET_DIR=$(HOME)/lib/

all : $(TARGET)

new : clean $(TARGET)

$(TARGET) : $(OBJS)
	$(AR) $(ARFLAG) $(TARGET_DIR)$(TARGET) $(OBJS)

.c.o :
	$(CC) $(CFLAG) $< $(INCL)

clean :
	@rm -f $(OBJS)
