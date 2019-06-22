#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool> isBreak(n, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < wordDict.size(); j++) {
				string word = wordDict[j];
				int start = i - (int)word.size() + 1;
				if (start >= 0 && (start == 0 || isBreak[start - 1])) {
					bool same = true;
					for (int k = 0; k < word.size(); k++) {
						if (s[start + k] != word[k]) {
							same = false;
							break;
						}
					}
					if (same) {
						isBreak[i] = true;
					}
				}
			}
		}
		return isBreak[n - 1];
	}
};

int main() {
	Solution sol;
	string s = "applepenapple";
	vector<string> wordDict;
	wordDict.push_back("apple");
	wordDict.push_back("pn");
	cout << sol.wordBreak(s, wordDict);
	return 0;
}