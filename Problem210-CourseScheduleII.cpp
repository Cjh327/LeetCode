#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> order(numCourses, -1);
		if (prerequisites.empty()) {
			return vector<int>();
		}
		vector<vector<int>> preCourses(numCourses, vector<int>());
		vector<bool> rootCourses(numCourses, true);
		for (vector<int> prerequisite : prerequisites) {
			preCourses[prerequisite[0]].push_back(prerequisite[1]);
			rootCourses[prerequisite[1]] = false;
		}
		vector<int> flags(numCourses, 0);
		int num = 0;
		for (int i = 0; i < numCourses; i++) {
			if (rootCourses[i]) {
				if (!dfs(preCourses, flags, i, order, num)) {
					return vector<int>();
				}
			}
		}
		for (int flag : flags) {
			if (flag != 2) {
				return vector<int>();
			}
		}
		return order;
	}

	bool dfs(vector<vector<int>>& preCourses, vector<int>& flags, int curCourse, vector<int>& order, int& num) {
		flags[curCourse] = 1;
		for (int preCourse : preCourses[curCourse]) {
			if (flags[preCourse] == 0) {
				if (!dfs(preCourses, flags, preCourse, order, num)) {
					return false;
				}
			}
			else if (flags[preCourse] == 1) {
				return false;
			}
		}
		flags[curCourse] = 2;
		order[num++] = curCourse;
		return true;
	}
};

int main() {
	vector<vector<int>> v{ {1,0} };
	Solution sol;
	vector<int> order = sol.findOrder(2, v);
	for (int o : order) {
		cout << o << " ";
	}
	return 0;
}