.SUFFIXES:
.SUFFIXES: .c .o

HOME=/home/netbank_mid

SYBASEDIR=/home/sybnet

LIBPATH=-L$(SYBASEDIR)/lib -L$(HOME)/lib 
INCL=-I$(HOME)/include -I$(SYBASEDIR)/include 
LIBS=-lmisc -lmidtools -lsubtrans -lcclaix -ldbfunc -lhscomm -lencrypt\
	-lct -lcs -ltcl -lcomn -lintl 

CC=xlc_r4 -O -D_THREAD_SAFE -DMID_SERVER -c -bloadmap -bnoquiet
LINK=xlc_r4 -O -D_THREAD_SAFE -o

OBJECTS= mid_server.o \
	mid_process.o \
	mid_tcp.o \
	mid_dbop.o \
   	client.o \
   	s_tcpfunc.o \
	write_log.o 

TARGETS= mid_server

all : $(TARGETS) 

new : rm $(TARGETS)

$(TARGETS) : $(OBJECTS) 
	$(LINK) $(TARGETS) $(OBJECTS) $(LIBPATH) $(LIBS)
	mv $(TARGETS) $(HOME)/bin

.c.o:
	$(CC) $(INCL) $<

.cp.c:
	$(CPRE) -y -a $<

clean:
	rm -f $(OBJECTS)

