/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (l1 && l2){
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        if (l1){
            tail->next = l1;
        }
        if (l2){
            tail->next = l2;
        }
        head = head->next;
        return head;
    }
};

static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
