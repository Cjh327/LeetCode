#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) {
			return 0;
		}
		int i = 0, j = 0;
		while (j < nums.size()) {
			if (val == nums[j]) {
				j++;
			}
			else {
				nums[i++] = nums[j++];
			}
		}
		nums.erase(nums.begin() + i, nums.end());
		return i;
	}
};

int main() {
	vector<int> nums{ 3,2,2,3 };
	Solution sol;
	cout << sol.removeElement(nums, 3) << endl;
	for (int x : nums) {
		cout << x << " ";
	}
	return 0;
}