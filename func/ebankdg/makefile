all : libebankdg.a
	
libebankdg.a : ebankdg.o
	ar ruv libebankdg.a ebankdg.o
	cp libebankdg.a /home/netbank_mid/lib

ebankdg.o : ebankdg.c
	cc -c ebankdg.c

rm :
	rm ebankdg.o
