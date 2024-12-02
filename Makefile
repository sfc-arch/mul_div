SHELL = /bin/sh

OBJS = mul_div.o
OBJS2 = mul_div_macchan.o
OBJS3 = mul_div_junpei.o
OBJS4 = mul_div_kota.o
OBJS5 = mul_div_ryota-iso.o
OBJS6 = mul_div_hotaka.o
OBJS7 = mul_div_kemuniku.o
OBJS8 = mul_div_fumi.o
CFLAGS = -Wall -O0
CC = gcc
INCLUDE =

all: mul_div mul_div_macchan mul_div_junpei mul_div_kota mul_div_ryota-iso mul_div_hotaka mul_div_kemuniku mul_div_fumi

mul_div_macchan: ${OBJS2}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS2} ${LIBS}

mul_div_junpei: ${OBJS3}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS3} ${LIBS}

mul_div_kota: ${OBJS4}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS4} ${LIBS}

mul_div_ryota-iso: ${OBJS5}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS5} ${LIBS}

mul_div_hotaka: ${OBJS6}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS6} ${LIBS}

mul_div_kemuniku: ${OBJS7}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS7} ${LIBS}

mul_div_fumi: ${OBJS8}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS8} ${LIBS}

clean:
	-rm -f *.o mul_div mul_div_macchan mul_div_junpei mul_div_kota mul_div_ryota-iso mul_div_hotaka mul_div_kemuniku mul_div_fumi

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
