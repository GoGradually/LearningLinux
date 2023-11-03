#Makefile

CC=gcc
CFLAGS=
OBJS=ch1_3_main.o ch1_3_subnum.o
LIBS=
all : sub.out

sub.out : $(OBJS)
	$(CC) $(CFLAGS) -o sub.out $(OBJS) $(LIBS)

ch1_3_main.o : ch1_3_main.c
	$(CC) $(CFLAGS) -c ch1_3_main.c
ch1_3_subnum.o : ch1_3_subnum.c
	$(CC) $(CFLAGS) -c ch1_3_subnum.c

clean:
	rm -f $(OBJS) sub.out *.o core
