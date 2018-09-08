class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        int start = 0;
        int i = 0;
        while (i < n) {
            int left = i;
            int right = i;
            while (right < n - 1 && s[right] == s[right + 1])
                right++;
            i = right + 1;
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if (maxlen < right - left + 1) {
                maxlen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxlen);
    }
};
