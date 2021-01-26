#include <iostream>
 
struct DateStruct
{
    int year{};
    int month{};
    int day{};
};
 
void print(const DateStruct &date)
{
    std::cout << date.year << '/' << date.month << '/' << date.day << std::endl;
}
 
int main()
{
    DateStruct today { 0, 0, 0 }; // use uniform initialization
 
    today.day = 24;
	today.month = 01;
	today.year = 2021; // use member selection operator to select a member of the struct
    print(today);
 
    return 0;
}