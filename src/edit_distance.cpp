#include <cstring>
#include "../inc/edit_distance.h"

editDistance::editDistance(std::string s1, std::string s2)
{
	this->str1 = s1;
	this->str2 = s2;

	a = new int*[this->str1.size() + 1];
	for(unsigned int i = 0; i <= this->str1.size(); i++)
	{
		a[i] = new int[this->str2.size() + 1];
		memset(a[i], 0, sizeof(a[i]));
	}
}

editDistance::~editDistance()
{
	for(unsigned int i = 0; i <= this->str1.size(); i++)
	{
		delete a[i];
	}
	delete a;
}

void editDistance::calculateEditDistanceIterative(void)
{
	std::cout << "Str1: " << str1 << std::endl;
	std::cout << "Str2: " << str2 << std::endl;
	
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
	print2DMatrix();
	printEdits();
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
			std::cout << a[i][j] << " ";
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
			std::cout << "Replace " << str2[j-1] << " With " << str1[i-1] << std::endl;
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
			std::cout << "Delete " << str2[j-1] << " in str1"<< std::endl;
			j--;
		}
	}
}
