#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		else if (nums.size() == 1) {
			return nums[0];
		}
		else if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}
		vector<int> money(nums.size() - 1, 0);
		vector<int> money0(nums.size(), 0);
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
		for (int i = 1; i < money0.size(); i++) {
			if (i - 2 < 1) {
				money0[i] = nums[i];
			}
			else if (i - 3 < 1) {
				money0[i] = money0[i - 2] + nums[i];
			}
			else {
				money0[i] = nums[i] + max(money0[i - 2], money0[i - 3]);
			}
		}
		int m1 = max(money[(int)money.size() - 1], money[(int)money.size() - 2]);
		int m2 = max(money0[(int)money0.size() - 1], money0[(int)money0.size() - 2]);
		return max(m1, m2);
	}
};

int main() {
	vector<int> nums{ 1,2,3,1 };
	Solution sol;
	cout << sol.rob(nums) << endl;
	return 0;
}