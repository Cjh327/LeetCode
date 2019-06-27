#include <iostream>
#include <vector>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> v;
		if (!root) {
			return v;
		}
		queue<TreeNode*> nodeQ;
		nodeQ.push(root);
		while (!nodeQ.empty()) {
			TreeNode* node = nodeQ.front();
			nodeQ.pop();
			if (node->left) {
				nodeQ.push(node->left);
			}
			if (node->right) {
				nodeQ.push(node->right);
			}

		}
	}

};