/**
 * ��Ŀ����
 * ��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
 * �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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