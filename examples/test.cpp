#include <iostream>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	editDistance editD("azced", "abcdef");
	editD.calculateEditDistanceIterative();
	return 0;	
}
