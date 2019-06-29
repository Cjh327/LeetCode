#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		vector<string> keyboard{ "qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM" };
		for (string word : words) {
			for (string str : keyboard) {
				if (str.find(word[0]) != str.npos) {
					bool find = true;
					for (int i = 1; i < word.size(); i++) {
						if (str.find(word[i]) == str.npos) {
							find = false;
							break;
						}
					}
					if (find) {
						res.push_back(word);
					}
					break;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	vector<string> words{ "Hello","Alaska","Dad","Peace"};
	sol.findWords(words);
	return 0;
}