PROJDIR = ..
INCLUDEDIR = ${PROJDIR}/include
LIBDIR = ${PROJDIR}/lib
PROJLIB = ${LIBDIR}/libutility.a
CC = gcc
LD = gcc
CXX = g++
CXXFLAGS = -std=c++11 -Wall
CFLAGS = -Wall -g -I${INCLUDEDIR}
LDLIBS = ${PROJLIB}
RM = rm -f
