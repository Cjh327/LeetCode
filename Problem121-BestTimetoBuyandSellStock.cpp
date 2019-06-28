#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}
		int minPrice = prices[0];
		int maxPro = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] - minPrice > maxPro) {
				maxPro = prices[i] - minPrice;
			}
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
		}
		return maxPro;
	}
};