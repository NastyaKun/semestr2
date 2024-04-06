#include <iostream>
#include "date.hpp"


int main() 
{
	std::string fileName = "input.txt";

	fDate::Number(fileName);
	fDate::timeCheck(fileName);
	std::cout << "All in file" << std::endl;

	return 0;
}
