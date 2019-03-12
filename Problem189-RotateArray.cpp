class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        int i = start, j = end - 1;
        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++i;
            --j;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // reverse 3 times
        k = k % nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }
    
    
    void rotate1(vector<int>& nums, int k) {
        vector<int> v(k);
        int size = nums.size();
        k = k % size;
        for(int i = size - k; i < size; ++i) {
            v[i - size + k] = nums[i]; 
        }
        for (int i = size - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = v[i];
        }
    }
};
