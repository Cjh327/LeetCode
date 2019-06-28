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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((p && !q) || (!p && q)) {
			return false;
		}
		if (!p) {
			return true;
		}
		if ((p->left && !q->left) || (!p->left && q->left)) {
			return false;
		}
		if ((p->right && !q->right) || (!p->right && q->right)) {
			return false;
		}
		if (p->left) {
			if (!isSameTree(p->left, q->left)) {
				return false;
			}
		}
		if (p->val != q->val) {
			return false;
		}
		if (p->right) {
			if (!isSameTree(p->right, q->right)) {
				return false;
			}
		}
		return true;
	}
};