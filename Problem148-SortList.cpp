#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		if (head->next->next == NULL) {
			if (head->val > head->next->val) {
				swap(head->val, head->next->val);
			}
			return head;
		}
		ListNode* fast = head, * slow = head;
		while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* mid = slow->next;
		slow->next = NULL;
		ListNode* head1 = sortList(head);
		ListNode* head2 = sortList(mid);
		return merge(head1, head2);
	}
	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* head = new ListNode(0);
		ListNode* p1 = head1, * p2 = head2, * q = head;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				q->next = p1;
				p1 = p1->next;
				q = q->next;
			}
			else {
				q->next = p2;
				p2 = p2->next;
				q = q->next;
			}
		}
		while (p1 != NULL) {
			q->next = p1;
			p1 = p1->next;
			q = q->next;
		}
		while (p2 != NULL) {
			q->next = p2;
			p2 = p2->next;
			q = q->next;
		}
		q->next = NULL;
		return head->next;
	}
};

int main() {
	ListNode* p1 = new ListNode(4);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(1);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(0);
	ListNode* p6 = new ListNode(-10);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	Solution sol;
	ListNode* head = sol.sortList(p1);
	ListNode* p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}