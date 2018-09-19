class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int n = s.size();
        int sum = 0;
        int last = 1001, cur = 0;
        while (i < n) {
            switch (s[i]) {
                case 'I' :
                    cur = 1;
                    break;
                case 'V' :
                    cur = 5;
                    break;
                case 'X' :
                    cur = 10;
                    break;
                case 'L' :
                    cur = 50;
                    break;
                case 'C' :
                    cur = 100;
                    break;
                case 'D' :
                    cur = 500;
                    break;
                case 'M' :
                    cur = 1000;
                    break;
                default :
                    break;
            }
            sum += cur;
            if (cur > last) {
                sum -= 2 * last;
            }
            last = cur;
            i++;
        }
        return sum;
    }
};
static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
