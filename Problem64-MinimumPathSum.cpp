#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
        v[0][0] = grid[0][0];
        int m = v.size(), n = v[0].size();
        for (int i = 1; i < m; i++) {
            v[i][0] = v[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++) {
            v[0][i] = v[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
            }
        }
        return v[m - 1][n - 1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}