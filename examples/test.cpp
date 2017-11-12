#include <iostream>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	std::string s1 = "Abhishek";
	std::string s2 = "Abhishew";
	
	std::cout << "Str1: " << s1 << std::endl;
	std::cout << "Str2: " << s2 << std::endl;
	
	editDistance editD(s1, s2);
	editD.startTimer();
	int edit = editD.calculateEditDistanceIterative();
	double time = editD.getExecutionTimeInMS();
	std::cout << "DP::Number of edits required = " << edit << " Computed in " << time << " milliseconds" << std::endl;
	editD.startTimer();
	edit = editD.calculateEditDistanceRecursively(s1, s2, s1.size(), s2.size());
	time = editD.getExecutionTimeInMS();
	std::cout << "Greedy::Number of edits required = " << edit << " Computed in " << time << " milliseconds" << std::endl;
	std::cout << "Edits ::" << std::endl;
	editD.printEdits();
	return 0;	
}
