#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> v(n);
		v[0] = 1;
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i < n; i++) {
			int tmp = min(2 * v[i2], min(3 * v[i3], 5 * v[i5]));
			if (tmp == 2 * v[i2]) i2++;
			if (tmp == 3 * v[i3]) i3++;
			if (tmp == 5 * v[i5]) i5++;
			v[i] = tmp;
		}
		return v[n - 1];
	}
};

int main() {
	Solution sol;
	cout << sol.nthUglyNumber(1600) << endl;
	return 0;
}