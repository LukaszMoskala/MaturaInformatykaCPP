CXX=g++
CXXFLAGS=--std=c++17 -Wall
all: zad5

zad5.o: zad5.cpp
	$(CXX) $(CXXFLAGS) -c -o zad5.o zad5.cpp
zad5: zad5.o
	$(CXX) $(CXXFLAGS) -o zad5 zad5.o
clean:
	rm -f *.o
