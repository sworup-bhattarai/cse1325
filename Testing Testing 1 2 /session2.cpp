#include <iostream>

class Elevator
{
   private:
	   bool _operating;
	   int _level;
	   int _population;

   public:
	   Elevator(int lev)
	   {
	      _level = lev;
	   }
	   friend std::ostream& operator<<(std::ostream& m, Elevator& elivator)
	   {
	   	m << elivator._level ;
	   	return m;
	   }
	   elivator operator+(Elivator& ad)
	   {
	   	
	   }
	   int get_level()
	   {
	      return _level;
	   }
};

int main()
{
   Elevator newElev{2};
   Elevator oldElev{3};
   std::cout << (newElev+oldElev) << std::endl;
}
