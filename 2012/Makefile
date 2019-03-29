CXX=g++
CXXFLAGS=--std=c++17 -Wall
all: zad4

zad4.o: zad4.cpp
	$(CXX) $(CXXFLAGS) -c -o zad4.o zad4.cpp
zad4: zad4.o
	$(CXX) $(CXXFLAGS) -o zad4 zad4.o
clean:
	rm -f *.o
