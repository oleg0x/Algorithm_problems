/******************************************************************************
 * Given an integer, convert it to a roman numeral.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <array>

using namespace std;



string IntToRoman(int num)
{
	struct Num
	{
		string roman;
		uint16_t arabic;
	};
	array<Num, 13> arr { {
		{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, 
	    {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, 
	    {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1} } };
	string res;
	for ( uint16_t i = 0; num > 0; ++i )
		while ( num >= arr[i].arabic )
		{
			num -= arr[i].arabic;
			res += arr[i].roman;
		}
	return res;
}



int main()
{
	cout << "1 = " << IntToRoman(1) << '\n'
	     << "2 = " << IntToRoman(2) << '\n'
	     << "3 = " << IntToRoman(3) << '\n'
	     << "4 = " << IntToRoman(4) << '\n'
	     << "5 = " << IntToRoman(5) << '\n'
	     << "7 = " << IntToRoman(7) << '\n'
	     << "9 = " << IntToRoman(9) << '\n'
	     << "40 = " << IntToRoman(40) << '\n'
	     << "90 = " << IntToRoman(90) << '\n'
	     << "400 = " << IntToRoman(400) << '\n'
	     << "900 = " << IntToRoman(900) << '\n'
	     << "1994 = " << IntToRoman(1994) << '\n';
	
	assert( IntToRoman(58) == "LVIII" );
	assert( IntToRoman(1994) == "MCMXCIV" );
}
