#include <iostream>
#include <vector>
#include <fstream>
#include "../inc/edit_distance.h"

int main(int argc, char *argv[])
{
	std::vector <std::string> input_data = {"Abhishek", "Jerry", "Pseudo", "hypo", "para", "thyroidism", "parathyroidism", "hypoparathyroidism", "pseudohypoparathyroidism", "thyroiidism", "P", "Pseudopseudohypoparathyroidism"};
	//std::string s1 = "Abhishek";
	std::string s2 = "Pseudopseudohypoparathyroidism";
	
	std::ofstream myfile;
	myfile.open ("greedy_dynamic.csv");
	for(int i = 0; i < 12; i++)
	{
	
		std::cout << "Str1: " << input_data[i] << std::endl;
		std::cout << "Str2: " << s2 << std::endl;
		
		editDistance editD(input_data[i], s2);
		editD.startTimer();
		int edit = editD.calculateEditDistanceIterative();
		double time1 = editD.getExecutionTimeInMS();
		//std::cout << "DP::Number of edits required = " << edit << " Computed in " << time1 << " milliseconds" << std::endl;

		editD.startTimer();
		edit = editD.calculateEditDistanceRecursively(input_data[i], s2, input_data[i].size(), s2.size());
		double time2 = editD.getExecutionTimeInMS();
		//std::cout << "Greedy::Number of edits required = " << edit << " Computed in " << time2 << " milliseconds" << std::endl;
		//std::cout << "Edits ::" << std::endl;
		myfile << input_data[i] << "," << s2 << "," << edit << "," << time1 << "," << time2 << std::endl;
		//editD.printEdits();
	}
	return 0;	
}
