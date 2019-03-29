CXX=g++
CXXFLAGS=--std=c++17 -Wall
all: zad6

zad6.o: zad6.cpp
	$(CXX) $(CXXFLAGS) -c -o zad6.o zad6.cpp
zad6: zad6.o
	$(CXX) $(CXXFLAGS) -o zad6 zad6.o
clean:
	rm -f *.o
