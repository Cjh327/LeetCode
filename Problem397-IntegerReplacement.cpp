class Solution {
public:
    int integerReplacement(int n) {
        unsigned int nn = n;
        int cnt = 0;
        while (nn > 1) {
            if (nn & 1) {
                if ((nn + 1) & 3 || nn == 3) {
                    nn = (nn - 1) >> 1;
                    cnt += 2;
                } else {
                    nn = (nn + 1) >> 2;
                    cnt += 3;
                } 
            } else {
                nn >>= 1;
                cnt++;
            }
        }
        return cnt;
    }
};

static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
