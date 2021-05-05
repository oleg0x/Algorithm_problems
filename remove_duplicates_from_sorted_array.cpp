/******************************************************************************
 * Given a sorted array nums, remove the duplicates in-place such that each 
 * element appears only once and returns the new length. Do this by modifying 
 * the input array in-place with O(1) extra memory.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;



int RemoveDuplicates(vector<int>& nums)
{
	if ( nums.empty() )  return 0;
	uint32_t i = 0;
	for ( uint32_t j = 1; j < nums.size(); ++j )
		// When nums[j]≠nums[i], the duplicate run has ended, so we copy its value to nums[i+1].
		if ( nums[j] != nums[i] )  nums[++i] = nums[j];
	return i + 1;
}



void PrintVector(const vector<int>& nums)
{
	for ( auto elem : nums )  cout << elem << ' ';
	cout << '\n';
}



int main()
{
	vector<int> v {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << RemoveDuplicates(v) << ": ";
	PrintVector(v);
}
