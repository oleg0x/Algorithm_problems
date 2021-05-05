/******************************************************************************
 * Given a roman numeral, convert it to an integer.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



int RomanToInt(string str)
{
	unordered_map<char, uint16_t> roman_int = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
	                  {'C', 100}, {'D', 500}, {'M', 1000} }; 
	int res = 0;
	uint16_t i;
	for ( i = 0; i < str.size() - 1; ++i )
	{
		int16_t cur = roman_int[str[i]];
		if ( cur < roman_int[str[i+1]] )  cur *= -1;
		res += cur;
	}
	res += roman_int[str[i]];
	return res;
}
    


int main()
{
	cout << "I = " << RomanToInt("I") << '\n'
	     << "III = " << RomanToInt("III") << '\n'
	     << "IV = " << RomanToInt("IV") << '\n'
	     << "IX = " << RomanToInt("IX") << '\n'
	     << "XL = " << RomanToInt("XL") << '\n'
	     << "XC = " << RomanToInt("XC") << '\n'
	     << "CD = " << RomanToInt("CD") << '\n'
	     << "CM = " << RomanToInt("CM") << '\n'
	     << "LVIII = " << RomanToInt("LVIII") << '\n'
	     << "MCMXCIV = " << RomanToInt("MCMXCIV") << '\n';
	
	assert( RomanToInt("LVIII") == 58 );
	assert( RomanToInt("MCMXCIV") == 1994 );
}
