/**
 * ��Ŀ����
 * ��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
 * ���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void replaceSpace(char* str, int length) {
		int cnt = 0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ') {
				cnt++;
			}
		}
		char* str1 = (char*)realloc(str, (length + 2 * cnt) * sizeof(char));
		int j = length + 2 * cnt - 1;
		for (int i = length - 1; i >= 0; i--) {
			if (str1[i] == ' ') {
				str1[j--] = '0';
				str1[j--] = '2';
				str1[j--] = '%';
			}
			else {
				str1[j--] = str1[i];
			}
		}
	}
};