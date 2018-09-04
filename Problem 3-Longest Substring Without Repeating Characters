#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 1)
            return 0;
        int maxn = 1;
        int n = 1;
        map<char, int> m;
        m.insert(pair<char, int>(s[0], 0));
        int begin = 0;
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            auto it = m.find(c);
            if (it == m.end() || it->second < begin) {
                if (it == m.end())
                    m.insert(m.end(), pair<char, int>(s[i], i));
                else
                    it->second = i;
                n++;
            } else {
                begin = it->second + 1;
                it->second = i;
                n = i - begin + 1;
            }
            if (n > maxn)
                maxn = n;
        }
        return maxn;
    }
};

int main() {
    Solution slt;
    string s;
    cin>>s;
    cout << slt.lengthOfLongestSubstring(s) << endl;
    return 0;
}
