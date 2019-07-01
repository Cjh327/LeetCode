#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += ('a' - 'A');
		}
		return str;
	}
};

int main() {
	Solution sol;
	cout << sol.toLowerCase("HellO") << endl;
	return 0;
}