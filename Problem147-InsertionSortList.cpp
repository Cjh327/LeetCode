#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* p = head;
		while (p->next) {
			if (p->next->val < head->val) {
				ListNode* tmp = p->next;
				p->next = tmp->next;
				tmp->next = head;
				head = tmp;
				continue;
			}
			ListNode* q = head;
			while (q->next != p->next) {
				if (p->next->val < q->next->val) {
					ListNode* tmp = p->next;
					p->next = tmp->next;
					tmp->next = q->next;
					q->next = tmp;
					break;
				}
				else {
					q = q->next;
				}
			}
			if (q->next == p->next) {
				p = p->next;
			}
		}
		return head;
	}
};