include ../Makefile.inc
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
PROGS = $(patsubst %.c,%.out,$(SRC))
.PRECIOUS: %.o

all: ${PROGS}

%.out:%.o 
	$(LD) $< -o $@ $(LDFLAGS) $(LDLIBS)

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@ 

clean:
	${RM} *.out *.o

