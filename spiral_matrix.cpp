/******************************************************************************
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;



vector<int> SpiralOrder(vector<vector<int>>& matrix)
{
	const int rows = matrix.size();
	const int cols = matrix[0].size();
	vector<int> res;
	res.reserve(rows * cols);
	int i1 = 0, i2 = rows - 1;
	int j1 = 0, j2 = cols - 1;

	while ( i1 <= i2 && j1 <= j2 )
	{
		for ( int j = j1; j <= j2; ++j )  res.push_back(matrix[i1][j]);
		++i1;
		for ( int i = i1; i <= i2; ++i )  res.push_back(matrix[i][j2]);
		--j2;
		if ( i1 <= i2 && j1 <= j2 )
		{
			for ( int j = j2; j >= j1; --j )  res.push_back(matrix[i2][j]);
			--i2;
			for ( int i = i2; i >= i1; --i )  res.push_back(matrix[i][j1]);
			++j1;
		}
	}
	return res;
}



void PrintVector(const vector<int>& nums)
{
	for ( auto elem : nums )  cout << elem << ' ';
	cout << '\n';
}



int main()
{
	{
		vector<vector<int>> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector<int> v = SpiralOrder(matrix);
		PrintVector(v);
		assert( v == vector<int>({1, 2, 3, 6, 9, 8, 7, 4, 5}) );
	}
	
	{
		vector<vector<int>> matrix {{1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}};
		vector<int> v = SpiralOrder(matrix);
		PrintVector(v);
		assert( v == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}) );
	}
	
	{
		vector<vector<int>> matrix {{2, 5}, {8, 4}, {0, -1}};
		vector<int> v = SpiralOrder(matrix);
		PrintVector(v);
		assert( v == vector<int>({2, 5, 4, -1, 0, 8}) );
	}
}
