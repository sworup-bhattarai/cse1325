CXXFLAGS = --std=c++17
all: smart

	
smart: person.o parent.o student.o main.o *.h
	$(CXX) $(CXXFLAGS) student.o person.o parent.o main.o -o smart
	
main.o: example.cpp *.h
	$(CXX) $(CXXFLAGS) -c example.cpp -o main.o
	
person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o
	
student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o
	
parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o


clean:       
	rm -f *.o *.gch *~ a.out  smart
