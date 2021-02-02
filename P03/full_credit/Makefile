CXXFLAGS = --std=c++17

test: fraction.o test.o *.h
	$(CXX) $(CXXFLAGS) fraction.o test.o -o test
	
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
		
fracion.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o


clean:       
	rm -f *.o *.gch *~ a.out test
