#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		if (!root->left && !root->right) {
			return true;
		}
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if ((p && !q) || (!p && q)) {
			return false;
		}
		if (!p) {
			return true;
		}
		if ((p->left && !q->right) || (!p->left && q->right)) {
			return false;
		}
		if ((p->right && !q->left) || (!p->right && q->left)) {
			return false;
		}
		if (p->left) {
			if (!isSymmetric(p->left, q->right)) {
				return false;
			}
		}
		if (p->val != q->val) {
			return false;
		}
		if (p->right) {
			if (!isSymmetric(p->right, q->left)) {
				return false;
			}
		}
		return true;
	}
};