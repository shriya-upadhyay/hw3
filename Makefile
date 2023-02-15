CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
#DEFS=-DDEBUG

OBJS=llrec-test.o llrec.o

all: llrec-test

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test.o: llrec-test.cpp 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp
	



clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 