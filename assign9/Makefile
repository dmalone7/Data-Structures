CC = cc 
CFLAGS = -g
SRC = driver.c driver2.c fifo.c graph.c
OBJ = driver.o fifo.o graph.o
OBJ2 = driver2.o fifo.o graph.o
HDR = fifo.h graph.h

driver:		$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o driver  

driver2:	$(OBJ2)
			$(CC) $(CFLAGS) $(OBJ2) -o driver2

driver.o:	driver.c $(HDR)
			$(CC) $(CFLAGS) -c driver.c

driver2.o:	driver2.c $(HDR)
			$(CC) $(CFLAGS) -c driver2.c

fifo.o:		fifo.c $(HDR)
			$(CC) $(CFLAGS) -c fifo.c

graph.o:	graph.c $(HDR)
			$(CC) $(CFLAGS) -c graph.c

install:	driver
			cp driver ~/bin

			driver2
			cp driver2 ~bin
clean:		
			rm -f driver *.o core
			rm -f driver2 *.o core
