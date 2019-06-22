#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) {
			return 0;
		}
		int n = matrix[0].size();
		int maxl = 0;
		vector<vector<int>> square(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == '1') {
				maxl = square[i][0] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			if (matrix[0][i] == '1') {
				maxl = square[0][i] = 1;
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				int k = 0;
				for (; k < square[i - 1][j - 1] + 1; k++) {
					if (matrix[i - k][j] == '0' || matrix[i][j - k] == '0') {
						break;
					}
				}
				square[i][j] = k;
				if (square[i][j] > maxl) {
					maxl = square[i][j];
				}
			}
		}
		return maxl * maxl;
	}
};

int main() {
	vector<vector<char>> v;
	vector<char> v1{ '0','0','0','1' };
	vector<char> v2{ '1','1','0','1' };
	vector<char> v3{ '1','1','1','1' };
	vector<char> v4{ '0','1','1','1' };
	vector<char> v5{ '0','1','1','1' };
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	Solution sol;
	cout << sol.maximalSquare(v) << endl;
	return 0;
}