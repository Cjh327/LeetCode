class Solution {
public:
    bool checkRecord(string s) {
        bool absent = false;
        int late = 0;
        for (char ch : s) {
            if (ch == 'A') {
                if (absent == false) {
                    absent = true;
                    late = 0;
                } else {
                    return false;
                }
            } else if (ch == 'L') {
                late++;
                if (late > 2) {
                    return false;
                }
            } else if (ch == 'P') {
                late = 0;
            }
        }
        return true;
    }
};

static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
