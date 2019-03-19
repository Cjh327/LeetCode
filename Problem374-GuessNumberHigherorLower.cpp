// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1, high = n;
        int mid;
        while (1) {
            if (low < high) {
                mid = (low + high) / 2;
                int res = guess(mid);
                if (res == 0) {
                    return mid;
                } else if (res == -1) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                assert(low == high);
                return low;
            }
        }
    }
};
