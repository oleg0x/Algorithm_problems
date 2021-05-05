/******************************************************************************
 * Given an array of integers nums and an integer target, return indices of 
 * the two numbers such that they add up to target. You may assume that each 
 * input would have exactly one solution, and you may not use the same element 
 * twice. You can return the answer in any order.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



vector<int> TwoSum(vector<int>& nums, int target)
{
	unordered_multimap<int, int> m;
	for ( int i = 0; i < static_cast<int>(nums.size()); ++i )
	{
		int complement = target - nums[i];
		if ( m.count(complement) > 0  )  return {m.find(complement)->second, i};
		m.emplace(nums[i], i);
	}
	return {};
}



int main()
{
	vector<int> v;
	int target;
	vector<int> res;
	
	v = {2, 7, 11, 15};
	target = 9;
	res = TwoSum(v, target);
	cout << res[0] << ", " << res[1] << '\n';
	assert ( (res == vector<int> {0, 1}) );
	
	v = {3, 2, 4};
	target = 6;
	res = TwoSum(v, target);
	cout << res[0] << ", " << res[1] << '\n';
	assert ( (res == vector<int> {1, 2}) );
	
	v = {3, 3};
	target = 6;
	res = TwoSum(v, target);
	cout << TwoSum(v, target)[0] << ", " << TwoSum(v, target)[1] << '\n';
	assert ( (res == vector<int> {0, 1}) );
	
	v = {8, 2, 6, 3, 1};
	target = 5;
	res = TwoSum(v, target);
	cout << TwoSum(v, target)[0] << ", " << TwoSum(v, target)[1] << '\n';
	assert ( (res == vector<int> {1, 3}) );
}
