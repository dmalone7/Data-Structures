CC = cc
CFLAGS = -g -O0
SRC = driver.c sreplace.c strmatch.c
OBJ = driver.o sreplace.o strmatch.o

driver:		$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o driver

driver.o:	driver.c
		$(CC) -c $(CFLAGS) driver.c

sreplace.o:	sreplace.c
		$(CC) -c $(CFLAGS) sreplace.c

strmatch.o:	strmatch.c
		$(CC) -c $(CFLAGS) strmatch.c

install:	driver
		cp driver ~/bin

clean:
		rm -f driver *.o core
