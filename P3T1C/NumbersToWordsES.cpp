#include "NumbersToWordsES.h"

const std::string NumbersToWordsES::units[30] = {"", "UNO ", "DOS ", "TRES ", "CUATRO ", "CINCO ", "SEIS ", "SIETE ", "OCHO ", "NUEVE ", "DIEZ ",
	"ONCE ", "DOCE ", "TRECE ", "CATORCE ", "QUINCE ", "DIECIS\220IS ", "DIECISIETE ", "DIECIOCHO ", "DIECINUEVE ", "VEINTE ", "VEINTIUNO ",
	"VEINTID\242S ", "VEINTITR\220S ", "VEINTICUATRO ", "VEINTICINCO ", "VEINTIS\220IS ", "VEINTISIETE ", "VEINTIOCHO ", "VEINTINUEVE "};

const std::string NumbersToWordsES::dozens[7] = {"TREINTA ", "CUARENTA ", "CINCUENTA ", "SESENTA ", "SETENTA ", "OCHENTA ", "NOVENTA "};

const std::string NumbersToWordsES::hundreds[9] = {"CIENTO ", "DOSCIENTOS ", "TRESCIENTOS ", "CUATROCIENTOS ", "QUINIENTOS ", "SEISCIENTOS ", "SETECIENTOS ", "OCHOCIENTOS ", "NOVECIENTOS "};

std::string NumbersToWordsES::billion(long long number) //from 1,000,000,000,000 to 999,999,999,999,999,999
{
	if (number >= 1000000000000LL)
	{
		if (number == 1000000000000LL)
			return "UN BILLÓN ";
		if (number < 2000000000000LL)
			return "UN BILLÓN " + million(number % 1000000000000LL);
		return thousand(number / 1000000000000LL) + "BILLONES " + million(number % 1000000000000LL);
	}
	return million(number);
}

std::string NumbersToWordsES::million(long long number) //from 1,000,000 to 999,999,999,999
{
	if (number >= 1000000)
	{
		if (number == 1000000)
			return "UN MILLÓN ";
		if (number < 2000000)
			return "UN MILLÓN " + thousand(number % 1000000);
		return thousand(number / 1000000) + "MILLONES " + thousand(number % 1000000);
	}
	return thousand(number);
}

std::string NumbersToWordsES::thousand(long long number) //from 1000 to 999,999
{
	if (number >= 1000)
	{
		if (number == 1000)
			return "UN MIL ";
		if (number < 2000)
			return "UN MIL " + hundred(number % 1000, false);
		return hundred(number / 1000, true) + "MIL " + hundred(number % 1000, false);
	}
	return hundred(number, false);
}

std::string NumbersToWordsES::hundred(long long number, bool boolean)
{
	if (number >= 100)
		for (int i = 9; i > 0; i--)
		{
			if (number == 100)
				return "CIEN ";
			if (number >= 100 * i)
				return hundreds[i - 1] + dozen(number % 100, boolean);
		}
	return dozen(number, boolean);
}

std::string NumbersToWordsES::dozen(long long number, bool boolean)
{
	for (int i = 9; i > 2; i--)
	{
		if (number < 30)
			return units[static_cast<int>(number)];
		if (number == 10 * i)
			return dozens[i - 3];
		if (boolean && number >= 10 * i && static_cast<int>(number) % 10 == 1)
			return dozens[i - 3] + "Y UN ";
		if (number >= 10 * i)
			return dozens[i - 3] + "Y " + units[static_cast<int>(number) % 10];
	}
	return "";
}

std::string NumbersToWordsES::convert(long long number)
{
	if (number == 0)
		return "CERO";
	if (number > 999999999999999999LL || number < -999999999999999999LL)
		throw; //throw exception
	return number < 0 ? "MENOS " + billion(number * -1) : billion(number);
}
