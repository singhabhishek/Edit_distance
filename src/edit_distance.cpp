#include <cstring>
#include "../inc/edit_distance.h"

editDistance::editDistance(std::string s1, std::string s2)
{
	this->str1 = s1;
	this->str2 = s2;

	// Allocate memory for 2D matrix
	a = new int*[this->str1.size() + 1];
	for(unsigned int i = 0; i <= this->str1.size(); i++)
	{
		a[i] = new int[this->str2.size() + 1];
		memset(a[i], 0, sizeof(a[i]));
	}
}

editDistance::~editDistance()
{
	// Delete Memory
	for(unsigned int i = 0; i <= this->str1.size(); i++)
	{
		delete a[i];
	}
	delete a;
}

int editDistance::calculateEditDistanceIterative(void)
{
	// Set first row as 0...sizeof(str1)
	for(unsigned int i = 0; i <= str2.size(); i++)
		a[0][i] = i;
	
	// Set first column as 0...sizeof(str2) 
	for(unsigned int j = 0; j <= str1.size(); j++)
		a[j][0] = j;

	for(unsigned int i = 1; i <= str1.size(); i++)
	{
		for(unsigned int j = 1; j <= str2.size(); j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				a[i][j] = a[i-1][j-1];
			}
			else
			{
				a[i][j] = calculateMin(a[i-1][j-1], a[i][j-1], a[i-1][j]) + 1;	
			}
		}
	}
	//print2DMatrix();
	//printEdits();
	return a[str1.size()][str2.size()];
}



int editDistance::calculateEditDistanceRecursively(std::string s1, std::string s2, int m, int n)
{
	if(m == 0 && n == 0)
		return 0;
	if(m == 0)
		return n;
	if(n == 0)
		return m;
	if(s1[m-1] == s2[n-1])
		return calculateEditDistanceRecursively(s1, s2, m-1, n-1);

	return (1 + calculateMin(calculateEditDistanceRecursively(s1, s2, m-1, n), 
			calculateEditDistanceRecursively(s1, s2, m-1, n-1),
			calculateEditDistanceRecursively(s1, s2, m, n-1)));
}

int editDistance::calculateMin(int a, int b, int c)
{
	int min = a;
	b < a ? (min = b) : min;
	c < a ? (min = c) : min;
	return min;
}

void editDistance::print2DMatrix(void)
{
	for(unsigned int i = 1; i <= str1.size(); i++)
	{
		for(unsigned int j = 1; j <= str2.size(); j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void editDistance::printEdits(void)
{
	unsigned int i = str1.size();
	unsigned int j = str2.size();
	while(true)
	{
		if(i == 0 || j == 0)
			break;
		if(str1[i-1] == str2[j-1])
		{
			i--;
			j--;
		}
		else if(a[i][j] == (a[i-1][j-1] + 1))
		{
			std::cout << "Replace " << str1[i-1] << " With " << str2[j-1] << std::endl;
			i--;
			j--;
		}
		else if(a[i][j] == (a[i-1][j] + 1))
		{
			std::cout << "Delete " << str1[i-1] << " in str1"<< std::endl;
			i--;
		}
		else if(a[i][j] == (a[i][j-1] + 1))
		{
			std::cout << "Add " << str2[j-1] << " in str1"<< std::endl;
			j--;
		}
	}
	while(j > 0)
	{
			std::cout << "Add " << str2[j-1] << " in str1"<< std::endl;
			j--;
	}
	while(i > 0)
	{
			std::cout << "Delete " << str1[i-1] << " in str1"<< std::endl;
			i--;
	}

}

void editDistance::startTimer(void)
{
	time = clock();
}

double editDistance::getExecutionTimeInMS(void)
{
	time = clock() - time;
	return ((double)time * 1000)/CLOCKS_PER_SEC;
}
