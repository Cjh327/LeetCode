#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums) {
    int maxSum = nums[0];
    int curSum = 0;
    for (int num : nums) {
        if (curSum > 0) {
            curSum += num;
        } else {
            curSum = num;
        }
        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}

int main() {

    return 0;
}