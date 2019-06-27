#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		if (!root) {
			return 0;
		}
		queue<Node*> nodeQ;
		nodeQ.push(root);
		nodeQ.push(NULL);
		int depth = 0;
		while (!nodeQ.empty()) {
			Node* node = nodeQ.front();
			nodeQ.pop();
			if (!nodeQ.front()) {
				depth++;
				nodeQ.pop();
				for (Node* child : node->children) {
					nodeQ.push(child);
				}
				if (nodeQ.empty()) {
					return depth;
				}
				nodeQ.push(NULL);
			}
			else {
				for (Node* child : node->children) {
					nodeQ.push(child);
				}
			}
		}
		return depth;
	}
};