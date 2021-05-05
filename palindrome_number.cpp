/******************************************************************************
 * Given an integer x, return true if x is a palindrome integer. An integer is 
 * a palindrome when it reads the same backward as forward. 
 *****************************************************************************/

#include <cassert>
#include <iostream>

using namespace std;



bool IsPalindrome(int n)
{
	if ( n < 0 || (n % 10 == 0 && n != 0) )  return false;
	
	int revert_n = 0;
	while ( revert_n < n )
	{
		revert_n = revert_n * 10 + n % 10;
		n /= 10;
	}
	
	return n == revert_n || n == revert_n / 10;
}



int main()
{
	cout << boolalpha;
	cout << "-1221 " << IsPalindrome(-1221) << '\n'
	     << "0 " << IsPalindrome(0) << '\n'
	     << "1000 " << IsPalindrome(1000) << '\n'
	     << "12321 " << IsPalindrome(12321) << '\n'
	     << "555555 " << IsPalindrome(555555) << '\n';
}
