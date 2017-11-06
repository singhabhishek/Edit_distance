#include "../inc/edit_distance.h"

editDistance::editDistance(std::string s1, std::string s2)
{
	std::cout << "Inside Costructor" << std::endl;
	this->str1 = s1;
	this->str2 = s2;
}

editDistance::~editDistance()
{
	std::cout << "Inside Destructor" << std::endl;
}

void editDistance::calculateEditDistance(void)
{
	std::cout << "Inside calculate edit distance" << std::endl;	
}
