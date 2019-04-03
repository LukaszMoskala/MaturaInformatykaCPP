CXX=g++
CXXFLAGS=--std=c++17 -Wall

#tu są 2 binarki więc uniwersalny makefile nie zadziała!

#Puste rozszerzenie dla GNU/Linux
EXTENSION=
#Dla windowsa .exe
ifeq ($(OS),Windows_NT)
    EXTENSION=.exe
endif


all: zad4$(EXTENSION) zad6$(EXTENSION)

zad4.o: zad4.cpp
	$(CXX) $(CXXFLAGS) -c -o zad4.o zad4.cpp
zad4$(EXTENSION): zad4.o
	$(CXX) $(CXXFLAGS) -o zad4$(EXTENSION) zad4.o

zad6.o: zad6.cpp
	$(CXX) $(CXXFLAGS) -c -o zad6.o zad6.cpp
zad6$(EXTENSION): zad6.o
	$(CXX) $(CXXFLAGS) -o zad6$(EXTENSION) zad6.o
clean:
	rm -f zad?.o
clean-bin:
	rm -f zad?$(EXTENSION)
