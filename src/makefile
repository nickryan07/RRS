# Makefile for Roving robots
CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm

all: main

debug: CXXFLAGS += -g
debug: main


main: Robot_parts.h Utils.h Customer.h Sales_associate.h Order.h Create_part.h Robot_test.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --cxxflags) Robot_test.cpp $(LDFLAGS)

clean:
	rm -f *.o a.out
