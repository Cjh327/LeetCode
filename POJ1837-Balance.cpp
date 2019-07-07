#include <iostream>
#include <vector>
using namespace std;

int balanceNum(vector<int>& hooks, vector<int>& weights) {
	vector<vector<int> > dp(weights.size() + 1, vector<int>(15001, 0));
	dp[0][7500] = 1;
	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j <= 15000; j++) {
			for (int k = 0; k < hooks.size(); k++) {
				int tmp = j - weights[i] * hooks[k];
				if (tmp >= 0 && tmp <= 15000 && dp[i][tmp] >= 1) {
					dp[i + 1][j] += dp[i][tmp];
				}
			}
		}
	}
	return dp.back()[7500];
}

int main() {
	int c, g;
	while (cin >> c >> g) {
		vector<int> hooks(c, 0);
		vector<int> weights(g, 0);
		for (int i = 0; i < c; i++) {
			cin >> hooks[i];
		}
		for (int i = 0; i < g; i++) {
			cin >> weights[i];
		}
		cout << balanceNum(hooks, weights) << endl;
	}
	return 0;
}