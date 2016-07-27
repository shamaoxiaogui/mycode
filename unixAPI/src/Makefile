include ../Makefile.inc
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
PROGS = $(patsubst %.c,%.out,$(SRC))

all: ${PROGS}

${PROGS}: ${OBJ} ${PROJLIB}
	$(LD) ${OBJ} -o $@ $(LDFLAGS) $(LDLIBS)

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@ 

clean:
	${RM} ${PROGS} ${OBJ}

