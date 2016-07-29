#include <iostream>
#include "NumbersToWordsES.h"

std::string getString()
{
	std::string line;
	while (true)
	{
		getline(std::cin, line);
		if (line.empty())
			continue;
		return line;
	}
}

long long getLongLong()
{
	std::string number = getString();
	std::string n;
	if (number[0] == 45)
		n.push_back(number[0]);
	for (unsigned int i = 0; i < number.length(); i++)
		if (number[i] > 47 && number[i] < 58)
			n.push_back(number[i]);
	return n.empty() ? getLongLong() : stoll(n);
}

void main()
{
	try
	{
		std::cout << NumbersToWordsES::convert(getLongLong());
	}
	catch (...)
	{
		std::cout << "Numero invalido";
	}
	std::cin.get();
}
