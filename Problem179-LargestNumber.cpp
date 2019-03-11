bool cmp(string s1, string s2) {
    bool change = false;
    if (s2.size() < s1.size()) {
        swap(s1, s2);
        change = true;
    }
    int i = 0, j = 0;
    while (i < s2.size() && j < s1.size()) {
        if (s1[j] < s2[i]) {
            return true ^ change;
        } else if (s1[j] > s2[i]) {
            return false ^ change;
        }
        ++i;
        ++j;
        if (j == s1.size() && i == s2.size()) {
            return true;
        }
        if (j == s1.size()) {
            j = 0;
        }
        if (i == s2.size()) {
            i = 0;
        }
    }
    return true;
    // return s1 + s2 < s2 + s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int i = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] != 0) {
                break;
            }
        }
        if (i == nums.size()) {
            return "0";
        }
        vector<string> nums_str;
        for(int i = 0; i < nums.size(); ++i) {
            nums_str.push_back(to_string(nums[i]));
        }
        sort(nums_str.begin(), nums_str.end(), cmp);
        string res;
        for (int i = nums_str.size() - 1; i >= 0; --i) {
            res += nums_str[i];
        }
        return res;
    }
    
    
};
