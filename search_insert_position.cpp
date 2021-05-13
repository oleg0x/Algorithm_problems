/******************************************************************************
 * Given a sorted array of distinct integers and a target value, return the 
 * index if the target is found. If not, return the index where it would be if 
 * it were inserted in order. An algorithm with O(logN) runtime complexity.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



int SearchInsert(vector<int>& nums, int target)
{
	int low = 0;
	int high = nums.size() - 1;
	int mid;
	if ( target > nums.back() )  return nums.size();
	while ( low < high )
	{
		mid = low + (high - low) / 2;
		if  ( target > nums[mid] )  low  = mid + 1;
		else  high = mid;
    }
	return low;
}



int main()
{
	vector<int> nums {1, 3, 5, 6, 8};
	cout << 0 << ' ' << SearchInsert(nums, 0) << '\n'
	     << 1 << ' ' << SearchInsert(nums, 1) << '\n'
	     << 2 << ' ' << SearchInsert(nums, 2) << '\n'
	     << 3 << ' ' << SearchInsert(nums, 3) << '\n'
	     << 4 << ' ' << SearchInsert(nums, 4) << '\n'
	     << 5 << ' ' << SearchInsert(nums, 5) << '\n'
	     << 8 << ' ' << SearchInsert(nums, 8) << '\n'
	     << 9 << ' ' << SearchInsert(nums, 9) << '\n';
}
