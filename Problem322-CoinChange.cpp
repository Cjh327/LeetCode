#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> v(amount + 1, -1);
		v[0] = 0;
		for (int i = 1; i <= amount; i++) {
			int minNum = 2147483647;
			for (int coin : coins) {
				if (i - coin >= 0 && v[i - coin] >= 0) {
					minNum = min(v[i - coin] + 1, minNum);
				}
			}
			if (minNum < 2147483647) {
				v[i] = minNum;
			}
		}
		return v[amount];
	}
};