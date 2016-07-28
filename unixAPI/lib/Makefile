include ../Makefile.inc
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

all : ${PROJLIB}

${PROJLIB} : ename.c.inc ${OBJ} 
	${RM} ${PROJLIB}
	${AR} rs ${PROJLIB} ${OBJ}

%.o : %.c
	${CC} -c -g ${CFLAGS} $<

ename.c.inc :
	sh Build_ename.sh > ename.c.inc
	echo 1>&2 "ename.c.inc built"

clean :
	${RM} ${OBJ} ${PROJLIB} ename.c.inc
