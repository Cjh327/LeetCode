class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto x : nums) {
            a = (a ^ x) & ~b;
            b = (b ^ x) & ~a;
        }
        return a;
    }
};
