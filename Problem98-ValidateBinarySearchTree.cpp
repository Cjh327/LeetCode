#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) {
			return true;
		}
		int last = 0;
		bool init = true;
		return isValidBST(root, last, init);
	}

	bool isValidBST(TreeNode* root, int& last, bool& init) {
		if (!root->left && !root->right) {
			if (init) {
				init = false;
			}
			else if (root->val <= last) {
				return false;
			}
			last = root->val;
			return true;
		}
		if (root->left) {
			if (!isValidBST(root->left, last, init)) {
				return false;
			}
		}
		if (init) {
			init = false;
		}
		else if (root->val <= last) {
			return false;
		}
		last = root->val;
		if (root->right) {
			return isValidBST(root->right, last, init);
		}
		return true;
	}
};

