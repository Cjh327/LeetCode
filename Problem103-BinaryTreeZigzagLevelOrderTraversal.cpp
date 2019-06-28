#include <iostream>
#include <vector>
#include <queue>
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
	struct Node {
		TreeNode* treeNode;
		int depth;
		Node(TreeNode* n, int d) :treeNode(n), depth(d) {}
	};

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> v;
		if (!root) {
			return v;
		}
		queue<Node*> nodeQ;
		nodeQ.push(new Node(root, 1));
		while (!nodeQ.empty()) {
			Node* node = nodeQ.front();
			nodeQ.pop();
			if (node->treeNode->left) {
				nodeQ.push(new Node(node->treeNode->left, node->depth + 1));
			}
			if (node->treeNode->right) {
				nodeQ.push(new Node(node->treeNode->right, node->depth + 1));
			}
			if (node->depth > v.size()) {
				v.push_back(vector<int>{});				
			}
			v[node->depth - 1].push_back(node->treeNode->val);
		}
		for (int i = 1; i < v.size(); i += 2) {
			reverse(v[i].begin(), v[i].end());
		}
		return v;
	}
};