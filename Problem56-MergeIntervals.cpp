#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if (intervals.empty()) {
			return res;
		}
		sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2) -> bool {
			if (interval1[0] < interval2[0]) return true;
			if (interval1[0] > interval2[0]) return false;
			return interval1[1] < interval2[1];
		});
		vector<int> mergedInterval(intervals[0]);
		int i = 1;
		while (i < (int)intervals.size()) {
			vector<int>& interval = intervals[i];
			if (interval[0] <= mergedInterval[1]) {
				if (interval[1] > mergedInterval[1]) {
					mergedInterval[1] = interval[1];
				}
			}
			else {
				res.push_back(mergedInterval);
				mergedInterval = intervals[i];
			}
			i++;
		}
		res.push_back(mergedInterval);
		return res;
	}
};

int main() {
	vector<vector<int>> intervals{ {920,2080},{920,2080},{910,2090},{900,2100},{860,2140} };
	Solution sol;
	vector<vector<int>> res = sol.merge(intervals);
	for (vector<int> v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}