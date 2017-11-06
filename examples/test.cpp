#include <iostream>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello world" << std::endl;	
	editDistance editD("abc", "abd");
	editD.calculateEditDistance();
	return 0;	
}
