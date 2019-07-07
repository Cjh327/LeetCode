#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		int blv = 0;
		bool isLast = true;
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			if (isLast) {
				blv = node->val;
			}
			if (q.front() == NULL) {
				q.pop();
				isLast = true;
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
				if (q.empty()) {
					return blv;
				}
				q.push(NULL);
			}
			else {
				isLast = false;
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
		}
		return blv;
	}
};