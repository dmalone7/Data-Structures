#
#                Simple Explicit Makefile 
#
#  The main program is prog.c with functions in a.c and b.c
#  All files include the header files x.h and y.h.
#

#  c compiler to use
CC = cc 

#  flags to be used with CC
CFLAGS = -g

#  source files
SRC = driver.c tree23.c 

#  object files
OBJ = driver.o tree23.o 

#  header files
HDR = tree23.h

#  **IMPORTANT**   The commands to be executed after each   **IMPORTANT** 
#  **IMPORTANT** dependency MUST start with a tab character **IMPORTANT** 

#  The executable prog depends upon the object files prog.o, a.o, and b.o
#  If prog is out of date, get the object files up to date and then link
#  all to create the executable prog.

driver:		$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o driver -lm 

#  prog.o depends upon prog.c, x.h, and y.h
#  compile prog.c making the object file prog.o

driver.o:	driver.c $(HDR)
			$(CC) $(CFLAGS) -c driver.c

#  a.o depends upon a.c, x.h, and y.h
#  compile a.c making the object file a.o

tree23.o:	tree23.c $(HDR)
			$(CC) $(CFLAGS) -c tree23.c

#  "make install" will put the executable, prog, in ~/bin

install:	driver
			cp driver ~/bin

#  remove all object, executable, and core files
clean:		
			rm -f driver *.o core
