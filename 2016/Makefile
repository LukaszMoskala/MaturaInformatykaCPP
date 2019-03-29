CXX=g++
CXXFLAGS=--std=c++17 -Wall

#tu są 2 binarki więc uniwersalny makefile nie zadziała!

all: zad4 zad6

zad4.o: zad4.cpp
	$(CXX) $(CXXFLAGS) -c -o zad4.o zad4.cpp
zad4: zad4.o
	$(CXX) $(CXXFLAGS) -o zad4 zad4.o

zad6.o: zad6.cpp
	$(CXX) $(CXXFLAGS) -c -o zad6.o zad6.cpp
zad6: zad6.o
	$(CXX) $(CXXFLAGS) -o zad6 zad6.o
clean:
	rm -f *.o
