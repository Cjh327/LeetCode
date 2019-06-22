#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> money(nums.size(), 0);
		for (int i = 0; i < money.size(); i++) {
			if (i - 2 < 0) {
				money[i] = nums[i];
			}
			else if (i - 3 < 0) {
				money[i] = money[i - 2] + nums[i];
			}
			else {
				money[i] = nums[i] + max(money[i - 2], money[i - 3]);
			}
		}
		if (money.size() >= 2) {
			return max(money[(int)money.size() - 1], money[(int)money.size() - 2]);
		}
		else if (money.size() >= 1) {
			return money.back();
		}
		else {
			return 0;
		}
	}
};

int main() {
	vector<int> nums{ 1,2,3,1 };
	Solution sol;
	cout << sol.rob(nums) << endl;
	return 0;
}