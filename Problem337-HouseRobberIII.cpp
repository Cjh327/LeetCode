#include <iostream>
#include <algorithm>
#include <map>
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
	map<TreeNode*, int> cache0;
	map<TreeNode*, int> cache1;
	int rob(TreeNode* root) {
		if (!root) {
			return 0;
		}
		return max(rob(root, false), rob(root, true));
	}
	int rob(TreeNode* root, bool isRobbed) {
		if (!root) {
			return 0;
		}
		if (isRobbed) {			
			return getRobVal(root->left, false) + getRobVal(root->right, false) + root->val;
		}
		else {
			return max(getRobVal(root->left, false), getRobVal(root->left, true)) + max(getRobVal(root->right, false), getRobVal(root->right, true));
		}
		return 0;
	}
	int getRobVal(TreeNode* node, bool isRobbed) {
		int val = 0;
		if (!isRobbed) {
			map<TreeNode*, int>::iterator it = cache0.find(node);
			if (it != cache0.end()) {
				return it->second;
			}
			val = rob(node, isRobbed);
			cache0.insert(pair<TreeNode*, int>(node, val));
		}
		else {
			map<TreeNode*, int>::iterator it = cache1.find(node);
			if (it != cache1.end()) {
				return it->second;
			}
			val = rob(node, isRobbed);
			cache1.insert(pair<TreeNode*, int>(node, val));
		}
		return val;
	}
};