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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			return vector<TreeNode*>();
		}
		return generateTrees(1, n);
	}
	vector<TreeNode*> generateTrees(int begin, int end) {
		vector<TreeNode*> res;
		if (begin > end) {
			res.push_back(NULL);
			return res;
		}
		for (int i = begin; i <= end; i++) {
			vector<TreeNode*> leftV = generateTrees(begin, i - 1);
			vector<TreeNode*> rightV = generateTrees(i + 1, end);
			for (TreeNode* &node1 : leftV) {
				for (TreeNode* &node2 : rightV) {
					TreeNode* node = new TreeNode(i);
					node->left = node1;
					node->right = node2;
					res.push_back(node);
				}
			}
		}
		return res;
	}
};