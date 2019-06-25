#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> v;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> ap(m, vector<int>(n, 0));
		for (int j = 0; j < n; j++) {
			if (ap[0][j] != 1) {
				search(matrix, ap, 0, j, -1);
			}
		}
		for (int i = 0; i < m; i++) {
			if (ap[i][0] != 1) {
				search(matrix, ap, i, 0, -1);
			}
		}
		for (int j = 0; j < n; j++) {
			if (ap[m - 1][j] < 2) {
				search2(matrix, ap, m - 1, j, -1);
			}
		}
		for (int i = 0; i < m; i++) {
			if (ap[i][n - 1] < 2) {
				search2(matrix, ap, i, n - 1, -1);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (ap[i][j] == 3) {
					v.push_back(vector<int>{i, j});
				}
			}
		}
		return v;
	}

	void search(vector<vector<int>>& matrix, vector<vector<int>>& ap, int i, int j, int last) {
		if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
			return;
		}
		if (ap[i][j] == 1) {
			return;
		}
		if (matrix[i][j] >= last) {
			ap[i][j] = 1;
			last = matrix[i][j];
			search(matrix, ap, i, j + 1, last);
			search(matrix, ap, i, j - 1, last);
			search(matrix, ap, i + 1, j, last);
			search(matrix, ap, i - 1, j, last);
		}
	}
	
	void search2(vector<vector<int>>& matrix, vector<vector<int>>& ap, int i, int j, int last) {
		if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
			return;
		}
		if (ap[i][j] >= 2) {
			return;
		}
		if (matrix[i][j] >= last) {
			if (ap[i][j] == 1) {
				ap[i][j] = 3;
			}
			else {
				ap[i][j] = 2;
			}
			last = matrix[i][j];
			search2(matrix, ap, i, j + 1, last);
			search2(matrix, ap, i, j - 1, last);
			search2(matrix, ap, i + 1, j, last);
			search2(matrix, ap, i - 1, j, last);
		}
	}
};

int main() {
	vector<int> v1{ 1,2,2,3,5 };
	vector<int> v2{ 3,2,3,4,4 };
	vector<int> v3{ 2,4,5,3,1 };
	vector<int> v4{ 6,7,1,4,5 };
	vector<int> v5{ 5,1,1,2,4 };
	vector<vector<int>> matrix{ v1,v2,v3,v4,v5 };
	Solution sol;
	vector<vector<int>> res = sol.pacificAtlantic(matrix);
	for (int i = 0; i < res.size(); i++) {
		for (int x : res[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}