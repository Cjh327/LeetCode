#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		queue<pair<int, int>> q;
		vector<vector<int>> dist(matrix.size(), vector<int>(matrix[0].size(), -1));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					q.push(pair<int, int>(i, j));
					dist[i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			pair<int, int> coord = q.front();
			q.pop();
			int i = coord.first, j = coord.second;
			if (i - 1 >= 0 && dist[i - 1][j] < 0) {
				q.push(pair<int, int>(i - 1, j));
				dist[i - 1][j] = dist[i][j] + 1;
			}
			if (i + 1 < matrix.size() && dist[i + 1][j] < 0) {
				q.push(pair<int, int>(i + 1, j));
				dist[i + 1][j] = dist[i][j] + 1;
			}
			if (j - 1 >= 0 && dist[i][j - 1] < 0) {
				q.push(pair<int, int>(i, j - 1));
				dist[i][j - 1] = dist[i][j] + 1;
			}
			if (j + 1 < matrix[0].size() && dist[i][j + 1] < 0) {
				q.push(pair<int, int>(i, j + 1));
				dist[i][j + 1] = dist[i][j] + 1;
			}
		}
		return dist;
	}
};

int main() {
	vector<vector<int>> matrix{ {0,1,1},{1,1,1},{1,1,0} };
	Solution sol;
	vector<vector<int>> dist = sol.updateMatrix(matrix);
	return 0;
}