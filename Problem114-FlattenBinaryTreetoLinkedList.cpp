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
	void flatten(TreeNode* root) {
		if (!root) {
			return;
		}
		TreeNode* last = root;
		if (root->left) {
			flatten(root->left, last);
		}
		if (root->right) {
			flatten(root->right, last);
		}
		TreeNode* p = root;
		cout << p->val << " ";
		while (p->left) {
			cout << p->left->val << " ";
			p->right = p->left;
			p->left = NULL;
			p = p->right;
		}
	}
	void flatten(TreeNode* root, TreeNode* &last) {
		if (!root) {
			return;
		}
		last->left = root;
		last = root;
		if (root->left) {
			flatten(root->left, last);
		}
		if (root->right) {
			flatten(root->right, last);
		}
	}
};

int main() {
	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(2);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p4 = new TreeNode(4);
	TreeNode* p5 = new TreeNode(5);
	TreeNode* p6 = new TreeNode(6);
	p1->left = p2;
	p1->right = p5;
	p2->left = p3;
	p2->right = p4;
	p5->right = p6;
	Solution sol;
	sol.flatten(p1);
}