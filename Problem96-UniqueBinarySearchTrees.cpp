#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1, G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                G[i] += G[j] * G[i - 1 - j];
            }
        }
        return G[n];
    }
};

int main() {
    Solution s;
    std::cout << s.numTrees(4) << std::endl;
    return 0;
}