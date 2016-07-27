include ../Makefile.inc

all : ${PROJLIB}

${PROJLIB} : *.o
	${RM} ${PROJLIB}
	${AR} rs ${PROJLIB} *.o

%.o : %.c
	${CC} -c -g ${CFLAGS} $<

clean :
	${RM} *.o ${PROJLIB}
