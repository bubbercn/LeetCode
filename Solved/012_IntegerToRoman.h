#pragma once
#include "Common.h"

class Solution
{
public:
	string intToRoman(int num)
	{
		const string thousands[10] = {"", "M", "MM", "MMM"};
		const string hundreds[10] = {"", "C", "CC", "CCC", "CD",
			"D", "DC", "DCC", "DCCC", "CM"};
		const string decades[10] = {"", "X", "XX", "XXX", "XL",
			"L", "LX", "LXX", "LXXX", "XC"};
		const string units[10] = {"", "I", "II", "III", "IV",
			"V", "VI", "VII", "VIII", "IX"};
		
		return thousands[num / 1000] + hundreds[num % 1000 / 100]
			+ decades[num % 100 / 10] + units[num % 10];
	}
};

void Test()
{
	Solution lSolution;
	assert(lSolution.intToRoman(1) == "I");
	assert(lSolution.intToRoman(4) == "IV");
	assert(lSolution.intToRoman(5) == "V");
	assert(lSolution.intToRoman(9) == "IX");
	assert(lSolution.intToRoman(10) == "X");
	assert(lSolution.intToRoman(11) == "XI");
	assert(lSolution.intToRoman(40) == "XL");
	assert(lSolution.intToRoman(50) == "L");
	assert(lSolution.intToRoman(90) == "XC");
	assert(lSolution.intToRoman(100) == "C");
	assert(lSolution.intToRoman(400) == "CD");
	assert(lSolution.intToRoman(500) == "D");
	assert(lSolution.intToRoman(900) == "CM");
	assert(lSolution.intToRoman(1000) == "M");
	assert(lSolution.intToRoman(3999) == "MMMCMXCIX");
}