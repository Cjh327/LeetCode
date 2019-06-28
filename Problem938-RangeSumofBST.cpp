#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (!root) {
			return 0;
		}
		if (root->val <= R && root->val >= L) {
			return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + root->val;
		}
		return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
	}
};