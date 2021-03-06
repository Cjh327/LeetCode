/**
 * 题目描述
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
**/

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
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int i = 0;
		return reConstructBinaryTree(pre, vin, i, 0, vin.size());
	}
	TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin, int& i, int begin, int end) {
		if (begin >= end || i >= pre.size()) {
			return NULL;
		}
		TreeNode* node = new TreeNode(pre[i]);
		int j = begin;
		while (j < end) {
			if (vin[j] == pre[i]) {
				break;
			}
			j++;
		}
		i++;
		node->left = reConstructBinaryTree(pre, vin, i, begin, j);
		node->right = reConstructBinaryTree(pre, vin, i, j + 1, end);
		return node;
	}
};

int main() {
	Solution sol;
	TreeNode* root = sol.reConstructBinaryTree(vector<int>{1, 2, 4, 7, 3, 5, 6, 8}, vector<int>{4, 7, 2, 1, 5, 3, 8, 6});
}