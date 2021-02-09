CXXFLAGS = --std=c++17
info:
	echo "Enter: make all \n	to compile everything \nEnter: make main \n	to compile main.cpp \nEnter: make test \n	to compile test.cpp"

all:
	make main
	make test
	make main_
	
main_: fraction.o main_.o *.h
	$(CXX) $(CXXFLAGS) fraction.o main_.o -o main_	
	
main: fraction.o main.o *.h
	$(CXX) $(CXXFLAGS) fraction.o main.o -o main

test: fraction.o test.o *.h
	$(CXX) $(CXXFLAGS) fraction.o test.o -o test

main_.o: main_.cpp *.h
	$(CXX) $(CXXFLAGS) -c main_.cpp -o main_.o
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
		
fracion.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o


clean:       
	rm -f *.o *.gch *~ a.out test main main_
