#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (prerequisites.empty()) {
			return true;
		}
		vector<vector<int>> preCourses(numCourses, vector<int>());
		vector<bool> rootCourses(numCourses, true);
		for (vector<int> prerequisite : prerequisites) {
			preCourses[prerequisite[0]].push_back(prerequisite[1]);
			rootCourses[prerequisite[1]] = false;
		}
		vector<int> flags(numCourses, 0);
		for (int i = 0; i < numCourses; i++) {
			if (rootCourses[i]) {
				if (!dfs(preCourses, flags, i)) {
					return false;
				}
			}
		}
		for (int flag : flags) {
			if (flag != 2) {
				return false;
			}
		}
		return true;
	}

	bool dfs(vector<vector<int>>& preCourses, vector<int>& flags, int curCourse) {
		flags[curCourse] = 1;
		for (int preCourse : preCourses[curCourse]) {
			if (flags[preCourse] == 0) {
				if (!dfs(preCourses, flags, preCourse)) {
					return false;
				}
			}
			else if (flags[preCourse] == 1) {
				return false;
			}
		}
		flags[curCourse] = 2;
		return true;
	}
};

int main() {
	vector<vector<int>> v{ {1,0} };
	Solution sol;
	cout << sol.canFinish(2, v) << endl;
	return 0;
}