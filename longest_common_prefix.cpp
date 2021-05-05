/******************************************************************************
 * Write a function to find the longest common prefix string amongst an 
 * array of strings. If there is no common prefix, return an empty string.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



string LongestCommonPrefix(vector<string>& strs)
{
	if ( strs.size() == 0 )  return ""s;
	for ( uint16_t i = 0; i < strs[0].size(); ++i )
	{
		char ch = strs[0][i];
		for ( uint16_t j = 0; j < strs.size(); ++j )
			if ( strs[j][i] != ch || i == strs[j].size() )
				return strs[0].substr(0, i);
	}
	return strs[0];
}



int main()
{
	vector<string> v;
	v = {"flower", "flow", "flight"};
	cout << LongestCommonPrefix(v) << '\n';
	assert( LongestCommonPrefix(v) == "fl" );
	
	v = {"dog", "racecar", "car"};
	cout << LongestCommonPrefix(v) << '\n';
	assert( LongestCommonPrefix(v) == "" );
}
