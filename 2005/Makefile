CXX=g++
CXXFLAGS=--std=c++17 -Wall

BINARKI=zad5

all: $(BINARKI)

$(BINARKI).o: $(BINARKI).cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
$(BINARKI): $(BINARKI).o
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -f *.o
