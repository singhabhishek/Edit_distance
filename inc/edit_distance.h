#include <iostream>
#include <string>


class editDistance
{
	std::string str1, str2;
	public:
		editDistance(std::string s1, std::string s2);
		~editDistance();
		void calculateEditDistance(void);
};
