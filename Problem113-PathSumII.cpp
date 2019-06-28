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
	vector<vector<int>> paths;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> v;
		getPathSum(root, sum, v);
		return paths;
	}

	void getPathSum(TreeNode* root, int sum, vector<int> v) {
		if (!root) {
			return;
		}
		sum -= root->val;
		v.push_back(root->val);
		if (!root->left && !root->right) {
			if (sum == 0) {
				paths.push_back(v);
			}
		}
		if (root->left) {
			getPathSum(root->left, sum, v);
		}
		if (root->right) {
			getPathSum(root->right, sum, v);
		}
	}
};