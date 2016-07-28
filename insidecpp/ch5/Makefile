SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
RM = rm -rf
PROGS = $(patsubst %.cpp,%.out,$(SRC))


all: $(PROGS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

clean: 
	${RM} ${OBJ} ${PROGS} *.dSYM
