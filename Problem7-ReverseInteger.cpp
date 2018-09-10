class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)
            return 0;
        int flag = 1;
        if (x < 0) {
            flag = -1;
            x = -x;
        }
        double ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            if (ans > 2147483647)
                return 0;
            x /= 10;
        }
        return ans * flag;
    }
};
