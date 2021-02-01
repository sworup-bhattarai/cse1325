 	
CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: Hello 

Hello: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o Hello
clean:
	rm -f *.o *.gch Hello
