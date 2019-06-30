#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = -1, j = nums.size(), k = 0;
		while (k < nums.size() && k < j) {
			if (nums[k] == 0) {
				swap(nums[++i], nums[k]);
				if (k == i) {
					k++;
				}
			}
			else if (nums[k] == 2) {
				swap(nums[--j], nums[k]);
				if (k == j) {
					return;
				}
			}
			else {
				k++;
			}
		}
	}
};

int main() {
	vector<int> nums{ 2,0,2,1,1,0,2,1,0,1 };
	Solution sol;
	sol.sortColors(nums);
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}