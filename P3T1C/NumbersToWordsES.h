#pragma once
#ifndef NumbersToWordsES_H
#define NumbersToWordsES_H
#include <string>

class NumbersToWordsES
{
private:
	static const std::string units[30];
	static const std::string dozens[7];
	static const std::string hundreds[9];
	static std::string billion(long long number);
	static std::string million(long long number);
	static std::string thousand(long long number);
	static std::string hundred(long long number, bool boolean);
	static std::string dozen(long long number, bool boolean);
public:
	static std::string convert(long long number);
};
#endif
