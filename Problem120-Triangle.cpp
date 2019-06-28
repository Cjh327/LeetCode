#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> minSum(triangle.back().size(), 0);
		minSum[0] = triangle[0][0];
		int m = triangle.size();
		for (int row = 1; row < m; row++) {
			int n = triangle[row].size();
			vector<int> tmp(n, 0);
			tmp[0] = triangle[row][0] + minSum[0];
			tmp[n - 1] = triangle[row][n - 1] + minSum[n - 2];
			for (int i = 1; i < n - 1; i++) {
				tmp[i] = triangle[row][i] + min(minSum[i - 1], minSum[i]);
			}
			for (int i = 0; i < n; i++) {
				minSum[i] = tmp[i];
			}
		}
		int res = minSum[0];
		for (int x : minSum) {
			if (res > x) {
				res = x;
			}
		}
		return res;
	}
};
