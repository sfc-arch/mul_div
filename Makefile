SHELL = /bin/sh

OBJS = mul_div.o
CFLAGS = -Wall -O0
CC = gcc
INCLUDE =

all: mul_div

mul_div: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}
clean:
	-rm -f *.o muldiv

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
