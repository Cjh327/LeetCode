#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string cpre;
        int i = 0;
        while (i < strs[0].size()) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i < strs[j].size() && strs[j][i] == ch) {
                    continue;
                } else {
                    return cpre;
                }
            }
            i++;
            cpre.push_back(ch);
        }
        return cpre;
    }
};