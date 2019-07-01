#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int curPos = nums[0], curNeg = nums[0];
		int res = nums[0];
		for (int i = 1; i < (int)nums.size(); i++) {
			int tmp = curPos;
			curPos = max(nums[i], max(nums[i] * curPos, nums[i] * curNeg));
			curNeg = min(nums[i], min(nums[i] * tmp, nums[i] * curNeg));
			res = max(curPos, res);
		}
		return res;
	}
};

int main() {
	vector<int> nums{ 7,-2,-4 };
	Solution sol;
	cout << sol.maxProduct(nums) << endl;
	return 0;
}