#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Node {
   public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<Node *, Node *> nodeMap;
    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }
        Node *copyNode = new Node();
        copyNode->val = node->val;
        nodeMap.insert(pair<Node *, Node *>(node, copyNode));
        for (Node *&neighbor : node->neighbors) {
            map<Node *, Node *>::iterator iter = nodeMap.find(neighbor);
            if (iter == nodeMap.end()) {
                Node *copyNeighbor = cloneGraph(neighbor);
                copyNode->neighbors.push_back(copyNeighbor);
            } else {
                copyNode->neighbors.push_back(iter->second);
            }
        }
        return copyNode;
    }
};