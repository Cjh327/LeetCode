/**
 * 题目描述
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
**/


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		if (!head) {
			return vector<int>();
		}
		vector<int> v = printListFromTailToHead(head->next);
		v.push_back(head->val);
		return v;
	}
};