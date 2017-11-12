#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H
#include <iostream>
#include <string>
#include <ctime>

class editDistance
{
	public:
		editDistance(std::string s1, std::string s2);
		~editDistance();
		int calculateEditDistanceIterative(void); // Using Dynamic Programming
		int calculateEditDistanceRecursively(std::string s1, std::string s2, int m, int n); // Using greedy way
		void startTimer(void);
		double getExecutionTimeInMS(void);
		void printEdits(void);
	private:
		int calculateMin(int a, int b, int c);
		void print2DMatrix(void);
		std::string str1, str2;
		int **a;
		clock_t time;
};

#endif //EDIT_DISTANCE_H
