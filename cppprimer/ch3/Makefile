
CXX = g++
CXXFLAGS = -std=c++11 -Wall
PROGS = fortest

all: $(PROGS)

$(PROGS): 
	$(CXX) $(CXXFLAGS) $@.cpp -o $@.out $(LDFLAGS) $(LDLIBS)

allrelease: $(PROGS)

$(PROGS): 
	$(CXX) $(CXXFLAGS) -O1 $@.cpp -o $@.out $(LDFLAGS) $(LDLIBS)

