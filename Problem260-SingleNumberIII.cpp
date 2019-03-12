class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        int x = 1;
        for (auto x : nums) {
            a ^= x;
        }
        int b = 1;
        while ((a & 1) == 0) { 
            a >>= 1;
            b <<= 1;
        }
        int c = 0, d = 0;
        for (auto x : nums) {
            if (x & b) {
                c ^= x;
            } else {
                d ^= x;
            }
        }
        vector<int> res;
        res.push_back(c);
        res.push_back(d);
        return res;
    }
};
