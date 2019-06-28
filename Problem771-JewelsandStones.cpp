#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		map<char, int> jewelMap;
		for (char ch : J) {
			jewelMap.insert(pair<char, int>(ch, 1));
		}
		int cnt = 0;
		for (char ch : S) {
			map<char, int>::iterator iter = jewelMap.find(ch);
			if (iter != jewelMap.end()) {
				cnt++;
			}
		}
		return cnt;
	}
};

int main() {
	Solution sol;
	cout << sol.numJewelsInStones("aA", "aAAbbbb") << endl;
	return 0;
}