#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int i = 0, j = 1;
		while (j < nums.size()) {
			if (nums[i] == nums[j]) {
				j++;
			}
			else {
				nums[++i] = nums[j++];
			}
		}
		nums.erase(nums.begin() + i + 1, nums.end());
		return i + 1;
	}
};

int main() {
	vector<int> nums{ 0,0,1,1,1,2,2,3,3,4 };
	Solution sol;
	cout << sol.removeDuplicates(nums) << endl;
	for (int x : nums) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}