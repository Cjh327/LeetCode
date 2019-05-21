#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < (int) paths.size(); i++) {
            if (obstacleGrid[i][0] == 0) {
                paths[i][0] = 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < (int) paths[0].size(); i++) {
            if (obstacleGrid[0][i] == 0) {
                paths[0][i] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i < (int) paths.size(); i++) {
            for (int j = 1; j < (int) paths[0].size(); j++) {
                if (obstacleGrid[i][j] == 0) {
                    paths[i][j] = (long long)paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }
        return paths[(int) paths.size() - 1][(int) paths[0].size() - 1];
    }
};
