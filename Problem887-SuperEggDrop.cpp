#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
		for (int i = 1; i <= K; i++) {
			dp[1][i] = 1;
		}
		for (int j = 1; j <= N; j++) {
			dp[j][1] = j;
		}
		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= K; i++) {
				dp[j][i] = dp[j - 1][i] + dp[j - 1][i - 1] + 1;
				if (dp[j][i] >= N) {
					return j;
				}
			}
		}
		return N;
	}
};

int main() {
	int K, N;
	Solution sol;
	while (cin >> K >> N) {
		cout << sol.superEggDrop(K, N) << endl;
	}
	return 0;
}