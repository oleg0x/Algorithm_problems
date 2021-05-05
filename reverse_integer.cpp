/******************************************************************************
 * Given a signed 32-bit integer x, return x with its digits reversed. 
 * If reversing x causes the value to go outside the signed 32-bit integer 
 * range [-2^31, 2^31 - 1], then return 0.
 *****************************************************************************/

#include <cassert>
#include <climits>
#include <iostream>

using namespace std;



int Reverse1(int x)  // int is sufficient for the result
{
	int res = 0;
	while ( x != 0 )
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}



int Reverse2(int x)  // int may not be sufficient for the result
{
//	if ( -8463847412 <= res && res <= 7463847421 )
	int res = 0;
	while ( x != 0 )
	{
		const int r = x % 10;
		// 7 and 8 are last difits in INT_MAX and INT_MIN corresp.
		if ( res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7) ||
		     res < INT_MIN / 10 || (res == INT_MIN / 10 && r < -8) )  return 0;
		res = res * 10 + r;
		x /= 10;
	}
	return res;
}



int main()
{
	cout << -1234 / 10 << ' ' << -1234 % 10 << '\n';  // Output: -123 -4
	// -1234 = -123*10 + (-4)
	cout << INT_MIN << ' ' << INT_MAX << '\n';  // Output: -2147483648 2147483647
	
	cout << Reverse1(0) << '\n' 
	     << Reverse1(5) << '\n' 
	     << Reverse1(34) << '\n'
	     << Reverse1(200) << '\n' 
	     << Reverse1(-789) << '\n'
	     << Reverse1(-101000) << '\n' 
	     << Reverse1(-123456789) << '\n';

	assert( Reverse1(0) == 0 );
	assert( Reverse1(101000) == 101 );
	assert( Reverse1(123456789) == 987654321 );
	
	cout << Reverse2(INT_MAX) << '\n';
}
