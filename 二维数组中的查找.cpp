/**
 * 题目描述
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int m = array.size(), n = array[0].size();
		int i = m - 1, j = 0;
		while (i >= 0 && j < n) {
			if (array[i][j] < target) {
				j++;
			}
			else if (array[i][j] > target) {
				i--;
			}
			else {
				return true;
			}
		}
		return false;
	}
};