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
	bool isBalanced(TreeNode* root) {
		return (getTreeDepth(root) >= 0);
	}
	int getTreeDepth(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int leftDep = getTreeDepth(root->left), rightDep = getTreeDepth(root->right);
		if (leftDep < 0 || rightDep < 0) {
			return -1;
		}
		if (abs(leftDep - rightDep) > 1) {
			return -1;
		}
		return max(getTreeDepth(root->left), getTreeDepth(root->right)) + 1;
	}
};