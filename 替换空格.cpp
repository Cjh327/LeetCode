/**
 * 题目描述
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
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