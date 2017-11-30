#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	std::vector <std::string> input_data = {"a", "aaaaa", "aaaaaaaaaa", "aaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
	
	std::ofstream myfile;
	myfile.open ("output.csv");
	for(int i = 0; i < 17; i++)
	{
		//std::string s1 = "aactttagacaaaccagatataggtgtgctaatccccaatcctgatcacaccccacattg";
		std::string s2;
		//std::cout << "My DNA sequence: " << input_data[i] << std::endl;
		int min = INT_MAX;
		double time;
		std::string closestMatch;
		std::ifstream file("examples/sample_dna_sequence.txt");
		while(std::getline(file, s2))
		{
			//std::cout << "======================================== Compare With: " << s2 << std::endl;
			
			editDistance editD(input_data[i], s2);
			editD.startTimer();
			int edit = editD.calculateEditDistanceIterative();
			time = editD.getExecutionTimeInMS();
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
		//std::cout << "Closest Match of MY DNA:" << input_data[i] << " is " << closestMatch << " with " << min  << " edits" << std::endl; 
		myfile << input_data[i] << "," << closestMatch << "," << time << "," << min << std::endl;
	}	
	return 0;	
}
