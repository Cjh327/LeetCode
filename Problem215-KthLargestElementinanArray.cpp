#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return findKthLargest(nums, k, 0, nums.size() - 1);
	}

	int findKthLargest(vector<int>& nums, int k, int begin, int end) {
		int j = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (nums[i] > nums[begin]) {
				swap(nums[++j], nums[i]);
			}
 		}
		swap(nums[begin], nums[j]);
		if (k < j + 1) {
			return findKthLargest(nums, k, begin, j - 1);
		}
		if (k > j + 1) {
			return findKthLargest(nums, k, j + 1, end);
		}
		return nums[j];
	}
};

int main() {
	vector<int> nums{ 5,4,6,7,1,2,9,8,3 };
	Solution sol;
	cout << sol.findKthLargest(nums, 3) << endl;
	return 0;
}