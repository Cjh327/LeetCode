#include <iostream>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> v;
		levelOrder(root, 0, v);
		return v;
	}

	void levelOrder(TreeNode* root, int depth, vector<vector<int>>& v) {
		if (!root) {
			return;
		}
		if (depth == v.size()) {
			v.push_back(vector<int>{});
		}
		v[depth].push_back(root->val);
		if (root->left) {
			levelOrder(root->left, depth + 1, v);
		}
		if (root->right) {
			levelOrder(root->right, depth + 1, v);
		}
	}
};