#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
	TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end) {
		if (begin > end) {
			return nullptr;
		}
		int mid = (begin + end) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		if (begin == end) {
			return node;
		}
		node->left = sortedArrayToBST(nums, begin, mid - 1);
		node->right = sortedArrayToBST(nums, mid + 1, end);
		return node;
	}
};