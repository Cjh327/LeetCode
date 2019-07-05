#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		if (graph.empty()) {
			return true;
		}
		vector<int> flags(graph.size(), 0);
		vector<bool> colors(graph.size(), false);
		queue<int> q;
		int k = 0;
		while (true) {
			for (; k < flags.size(); k++) {
				if (flags[k] == 0) {
					break;
				}
			}
			if (k == flags.size()) {
				return true;
			}
			int i = k;
			colors[i] = false;
			flags[i] = 1;
			q.push(i);
			while (!q.empty()) {
				i = q.front();
				q.pop();
				for (int j : graph[i]) {
					if (flags[j] == 0) {
						colors[j] = !colors[i];
						flags[j] = 1;
						q.push(j);
					}
					else if (colors[i] == colors[j]) {
						return false;
					}
				}
				flags[i] = 2;
			}
		}
		return true;
	}
};