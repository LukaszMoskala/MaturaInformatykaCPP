CXX=g++
CXXFLAGS=--std=c++17 -Wall

#Puste rozszerzenie dla GNU/Linux
EXTENSION=
#Dla windowsa .exe
ifeq ($(OS),Windows_NT)
    EXTENSION=.exe
endif

BINARKI=zad4$(EXTENSION)

all: $(BINARKI)

$(BINARKI).o: $(BINARKI).cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
$(BINARKI): $(BINARKI).o
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -f zad?.o
clean-bin:
	rm -f zad?$(EXTENSION)
