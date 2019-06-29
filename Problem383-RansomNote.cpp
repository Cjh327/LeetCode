#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int> magMap;
		for (char ch : magazine) {
			map<char, int>::iterator iter = magMap.find(ch);
			if (iter != magMap.end()) {
				iter->second++;
			}
			else {
				magMap.insert(pair<char, int>(ch, 1));
			}
		}
		for (char ch : ransomNote) {
			map<char, int>::iterator iter = magMap.find(ch);
			if (iter != magMap.end() && iter->second > 0) {
				iter->second--;
			}
			else {
				return false;
			}
		}
		return true;
	}
};