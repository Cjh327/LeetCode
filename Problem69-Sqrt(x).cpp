class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        unsigned int xx = x;
        unsigned int r = xx;
        while (r > xx / r) {
            r = (r + xx / r) / 2;
        }
        return r;
    }
};

static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
