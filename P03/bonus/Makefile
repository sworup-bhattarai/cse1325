CXXFLAGS = --std=c++17
all:
	make main
	make test
	
main: fraction.o main.o *.h
	$(CXX) $(CXXFLAGS) fraction.o main.o -o main

test: fraction.o test.o *.h
	$(CXX) $(CXXFLAGS) fraction.o test.o -o test
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
		
fracion.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o


clean:       
	rm -f *.o *.gch *~ a.out test main
