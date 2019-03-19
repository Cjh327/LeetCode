class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pivot = 0;
        int kk = k;
        for (; pivot < arr.size(); pivot++) {
            if (arr[pivot] >= x) {
                break;
            }
        }
        int i = pivot - 1, j = pivot;
        while (i >= 0 && j < arr.size() && k > 0) {
            if ((x - arr[i]) <= (arr[j] - x)) {
                i--;
            } else {
                j++;
            }
            k--;
        }
        if (i < 0) {
            return vector<int>(&arr[0], &arr[kk]);
        } else if (j == arr.size()) {
            return vector<int>(&arr[arr.size() - kk], &arr[arr.size()]);
        } else {
            return vector<int>(&arr[i + 1], &arr[j]);
        }
        
    }
};
