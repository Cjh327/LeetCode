/**
 * ��Ŀ����
 * ����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
 * ��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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