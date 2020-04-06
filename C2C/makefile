CXX = g++
CFLAGS = -g -lrt

all: process1 process2

process1: process1.cpp
	$(CXX) $(CFLAGS) process1.cpp -o build/p1

process2: process2.cpp
	$(CXX) $(CFLAGS) process2.cpp -o build/p2

clean:
	-rm -r build/*