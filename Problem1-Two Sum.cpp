#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = m.find(nums[i]);
            if (iter != m.end()) {
                result.push_back(iter->second);
                result.push_back(i);
            }
            m.insert(pair<int,int>(target - nums[i], i));
        }
        return result;
    }
};


int main() {
    Solution solution;
    int a[5] = {2, 7, 8, 9, 33};
    vector<int> nums(a, a + 5);
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
