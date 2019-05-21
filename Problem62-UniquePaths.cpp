#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int M = m + n - 2, N = min(m, n) - 1;
        int res = 1;
        for (int i = 1; i <= N; i++) {
            res *= (M - N + i);
            res /= i;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.uniquePaths(3, 7) << std::endl;
    return 0;
}