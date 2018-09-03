#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0);
        ListNode *p = result, *p1 = l1, *p2 = l2;
        int extra = 0;
        int val = 0;
        while (p1 && p2) {
            val = p1->val + p2->val + extra;
            extra = val / 10;
            val = val % 10;
            p1 = p1->next;
            p2 = p2->next;

            ListNode *node = new ListNode(val);
            p->next = node;
            p = p->next;
        }
        while (p1) {
            val = p1->val + extra;
            extra = val / 10;
            val = val % 10;
            p1 = p1->next;

            ListNode *node = new ListNode(val);
            p->next = node;
            p = p->next;
        }
        while (p2) {
            val = p2->val + extra;
            extra = val / 10;
            val = val % 10;
            p2 = p2->next;

            ListNode *node = new ListNode(val);
            p->next = node;
            p = p->next;
        }
        while (extra != 0) {
            val = extra;
            extra = val / 10;
            val = val % 10;
            ListNode *node = new ListNode(val);
            p->next = node;
            p = p->next;
        }
        result = result->next;
        return result;
    }
};

int main() {

    return 0;
}
