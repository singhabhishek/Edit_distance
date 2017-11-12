#include <iostream>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	//editDistance editD("azced", "abcdef");
	editDistance editD("Abhishek", "111Abhishek");
	int diff = editD.calculateEditDistanceIterative();
	std::cout << "Number of edits = " << diff << std::endl;
	return 0;	
}
