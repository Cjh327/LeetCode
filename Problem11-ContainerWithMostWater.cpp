class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxarea = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                maxarea = max((j - i) * height[i], maxarea);
                i++;
            }
            else {
                maxarea = max((j - i) * height[j], maxarea);
                j--;
            }
        }
        return maxarea;
    }
};
