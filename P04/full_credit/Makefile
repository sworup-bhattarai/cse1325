CXXFLAGS = --std=c++17
all: main

	
main: card.o deck.o main.o *.h
	$(CXX) $(CXXFLAGS) card.o deck.o main.o -o main
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	
deck.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
	
card.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o


clean:       
	rm -f *.o *.gch *~ a.out test main
