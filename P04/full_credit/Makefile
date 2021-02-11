CXXFLAGS = --std=c++17
all: flash_cards

	
flash_cards: card.o deck.o flash_cards.o *.h
	$(CXX) $(CXXFLAGS) card.o deck.o flash_cards.o -o flash_cards
	
flash_cards.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o flash_cards.o
	
deck.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
	
card.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o


clean:       
	rm -f *.o *.gch *~ a.out  flash_cards
