#include <iostream>
#include <fstream>
#include <climits>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	std::string s1 = "aaaaaaaaaaaaaaaaaaaaa";
	std::string s2;
	std::cout << "My DNA sequence: " << s1 << std::endl;
	int min = INT_MAX;
	std::string closestMatch;
	std::ifstream file("examples/sample_dna_sequence.txt");
	while(std::getline(file, s2))
	{
		//std::cout << "======================================== Compare With: " << s2 << std::endl;
		
		editDistance editD(s1, s2);
		editD.startTimer();
		int edit = editD.calculateEditDistanceIterative();
		double time = editD.getExecutionTimeInMS();
		//std::cout << "DP::Number of edits required = " << edit << " Computed in " << time << " milliseconds" << std::endl;
		
		/*editD.startTimer();
		edit = editD.calculateEditDistanceRecursively(s1, s2, s1.size(), s2.size());
		time = editD.getExecutionTimeInMS();
		std::cout << "Greedy::Number of edits required = " << edit << " Computed in " << time << " milliseconds"
		<< std::endl;*/
		//std::cout << "Edits ::" << std::endl;
		//editD.printEdits();
		
		if(edit < min)
		{
			min = edit;
			closestMatch = s2;
		}
	}
	std::cout << "Closest Match of MY DNA:" << s1 << " is " << closestMatch << " with " << min  << " edits" << std::endl; 
	
	return 0;	
}
