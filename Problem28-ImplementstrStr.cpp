#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		vector<int> next(needle.size(), -1);
		int i = 0, j = -1;
		while (i < (int)next.size() - 1) {
			if (j == -1 || needle[i] == needle[j]) {
				next[++i] = ++j;
			}
			else {
				j = next[j];
			}
		}
		i = 0, j = 0;
		while (i < (int)haystack.size() && j < (int)needle.size()) {
			if (j == -1 || haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else {
				j = next[j];
			}
		}
		if (j == needle.size()) {
			return i - j;
		}
		return -1;
	}
};

int main() {
	Solution sol;
	string s1 = "abccab", s2 = "caab";
	cout << sol.strStr(s1, s2) << endl;
	return 0;
}