#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}
		int size = prices.size();
		vector<int> sell(size, 0);		// 到第i天为止最后一个动作是卖
		vector<int> buy(size, 0);		// 到第i天为止最后一个动作是买
		vector<int> cooldown(size, 0);	// 到第i天为止最后一个动作是冻结
		buy[0] = -prices[0];
		for (int i = 1; i < size; i++) {
			sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
			buy[i] = max(cooldown[i - 1] - prices[i], buy[i - 1]);
			cooldown[i] = max(sell[i - 1], cooldown[i - 1]);
		}
		return max(sell.back(), cooldown.back());
	}
};

int main() {
	vector<int> prices{ 1,2,3,0,2 };
	Solution sol;
	cout << sol.maxProfit(prices) << endl;
	return 0;
}