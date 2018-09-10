class Solution {
public:
    string convert(string s, int numRows) {
         if (numRows == 1)
            return s;
        string res;
        int n = 2 * (numRows - 1);
        int row = 0;
        int i = row;
        while (i < s.size()) {
            res.push_back(s[i]);
            i += n;
        }
        row++;
        while (row < numRows - 1) {
            i = row;
            int interval = n - row * 2;
            while (i < s.size()) {
                res.push_back(s[i]);
                i += interval;
                interval = n - interval;
            }
            row++;
        }
        i = row;
        while (i < s.size()) {
            res.push_back(s[i]);
            i += n;
        }
        return res;
    }
};
