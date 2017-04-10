# Makefile for Roving robots
CXXFLAGS = -std=c++11

all: main

debug: CXXFLAGS += -g
debug: Robot_parts.o


main: Robot_parts.h Utils.h Customer.h Sales_associate.h Order.h Robot_test.cpp
	$(CXX) $(CXXFLAGS) Robot_test.cpp

clean:
	rm -f *.o a.out
