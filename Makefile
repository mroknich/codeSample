# CSE 101 PA 2 Makefile
#
# DO NOT MODIFY

CC=g++
FLAGS=-std=c++0x -I./

HEADERS=$(wildcard *.hpp)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

TestDijkstra.o: testsrc/TestDijkstra.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestDijkstra.cpp

TestForex.o: testsrc/TestForex.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestForex.cpp

TestPrim.o: testsrc/TestPrim.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestPrim.cpp

TestPrimDijk.o: testsrc/TestPrimDijk.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestPrimDijk.cpp

TestDijkstra: TestDijkstra.o Dijkstra.o
	$(CC) $(FLAGS) -g -o TestDijkstra.out TestDijkstra.o Dijkstra.o

TestForex: TestForex.o Forex.o
	$(CC) $(FLAGS) -g -o TestForex.out TestForex.o Forex.o

TestPrim: TestPrim.o Prim.o
	$(CC) $(FLAGS) -g -o TestPrim.out TestPrim.o Prim.o

TestPrimDijk: TestPrimDijk.o PrimDijk.o
	$(CC) $(FLAGS) -g -o TestPrimDijk.out TestPrimDijk.o PrimDijk.o

TestAll: TestDijkstra TestForex TestPrim TestPrimDijk

%.o: %.cpp
	$(CC) $(FLAGS) -g -c -o $@ $<

clean:
	rm -f *.o
	rm -f *.out

clean_graphs:
	rm -f gen_graphs/*
