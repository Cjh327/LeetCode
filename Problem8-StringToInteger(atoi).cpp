#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0)
            return 0;
        double ans = 0;
        bool isNum = false;
        int flag = 1;
        int i = 0;
        while (i < str.size() && str[i] == ' ')
            i++;
        if (str[i] == '+') {
            flag = 1;
            i++;
            isNum = true;
        } else if (str[i] == '-') {
            flag = -1;
            i++;
            isNum = true;
        }
        while (i < str.size()) {
            if (str[i] <= '9' && str[i] >= '0') {
                ans = ans * 10 + str[i] - '0';
                if (ans > 2147483647) {
                    if (flag == 1)
                        return  2147483647;
                    else
                        return  -2147483648;
                }
                isNum = true;
            } else if (!isNum) {
                return 0;
            } else {
                return (int) ans * flag;
            }
            i++;
        }
        return (int) ans * flag;
    }
};

int main() {
    string str;
    cin >> str;
    Solution solution;
    cout << solution.myAtoi(str) << endl;
    return 0;
}