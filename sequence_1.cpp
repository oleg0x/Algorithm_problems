/******************************************************************************
 * Given a vector of 0 and 1 only, find the longest continuous sequence of 1.
 *****************************************************************************/

#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



int count1(vector<int16_t> v)
{
	int curr_count = 0;
	int max_count = 0;
	for ( int16_t k : v )
		if ( k == 1 )
		{
			++curr_count;
			max_count = std::max(max_count, curr_count);
		}
		else
			curr_count = 0;
	return max_count;
}



int main()
{
	cout << count1( vector<int16_t>() ) << '\n';
	cout << count1( vector<int16_t>({0}) ) << '\n';
	cout << count1( vector<int16_t>({1}) ) << '\n';
	cout << count1( vector<int16_t>({0, 1}) ) << '\n';
	cout << count1( vector<int16_t>({1, 0}) ) << '\n';
	cout << count1( vector<int16_t>({0, 0, 0, 0}) ) << '\n';
	cout << count1( vector<int16_t>({1, 1, 1}) ) << '\n';
	cout << count1( vector<int16_t>({1, 1, 1, 0, 0}) ) << '\n';
	cout << count1( vector<int16_t>({0, 0, 1, 1, 1}) ) << '\n';
	cout << count1( vector<int16_t>({0, 1, 1, 1, 1, 0, 1}) ) << '\n';
	cout << count1( vector<int16_t>({1, 1, 1, 1, 0, 0, 1, 1, 1, 1}) ) << '\n';
}
