/******************************************************************************
 * Given an integer array nums of unique elements, return all possible subsets 
 * (the power set). The solution set must not contain duplicate subsets. 
 * Return the solution in any order.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<vector<int>> Subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	res.push_back(vector<int>());
	
	for ( int num : nums )
	{
		vector<vector<int>> new_subsets;
		for ( vector<int> curr : res )
		{
			curr.push_back(num);
			new_subsets.push_back(move(curr));
		}
		for ( const vector<int>& curr : new_subsets )
			res.push_back(move(curr));
	}
	return res;
}



void PrintVV(const vector<vector<int>>& v)
{
	cout << "[ ";
	for ( const vector<int>& curr : v )
	{
		cout << "[ ";
		for ( int x : curr )  cout << x << ' ';
		cout << "], ";
	}
	cout << "]\n";
}



int main()
{
	vector<int> nums {1, 2, 3};
	PrintVV(Subsets(nums));
}
