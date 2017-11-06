#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H
#include <iostream>
#include <string>
#define MAX_LEN 7

class editDistance
{
	public:
		editDistance(std::string s1, std::string s2);
		~editDistance();
		void calculateEditDistanceIterative(void);
	private:
		int calculateMin(int a, int b, int c);
		void printEdits(void);
		void print2DMatrix(void);
		std::string str1, str2;
		int **a;
};

#endif //EDIT_DISTANCE_H
