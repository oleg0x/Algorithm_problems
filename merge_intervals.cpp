/******************************************************************************
 * Given an array of intervals where intervals[i] = [start_i, end_i], merge 
 * all overlapping intervals, and return an array of the non-overlapping 
 * intervals that cover all the intervals in the input.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintIntervals(const vector<vector<int>>& intervals);



vector<vector<int>> MergeIntervals(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> res;
	const uint32_t n = intervals.size();
	uint32_t i = 0;
	while ( i < n )
	{
		int left = intervals[i][0];
		int right = intervals[i][1];
		while ( i < n && intervals[i][0] <= right )
			right = max(right, intervals[i++][1]);
		res.push_back({left, right});
	}
	return res;
}



void PrintIntervals(const vector<vector<int>>& intervals)
{
	for ( const auto& v : intervals )
		cout << v[0] << ", " << v[1] << '\n';
}



int main()
{
	vector<vector<int>> v {{11, 15}, {1, 4}, {8, 11}, {1, 2}, {2, 3}};
	vector<vector<int>> res = MergeIntervals(v);
	PrintIntervals(res);
	
}
