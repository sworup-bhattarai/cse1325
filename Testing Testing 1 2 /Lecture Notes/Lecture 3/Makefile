CXXFLAGS += --std=c++17

class: class.o date.o
	$(CXX) $(CXXFLAGS)  class.o date.o -o class
	
class.o: class.cpp *.h
	$(CXX) $(CXXFLAGS) -c class.cpp -o class.o
	
date.o: date.cpp *.h
	$(CXX) $(CXXFLAGS) -c date.cpp -o date.o
	
clean:
	rm -f *~ a.out *.gch *.o class