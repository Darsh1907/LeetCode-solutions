/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy = new ListNode(111);
        dummy->next = head;
        ListNode* itr = dummy->next;
        ListNode* prev = dummy;
        while(itr!=NULL && itr->next!=NULL) {
            if(itr->val != itr->next->val) {
                prev = prev->next;
                itr = itr->next;
            }
            else {
                while(itr->next!=NULL && itr->val==itr->next->val) itr->next = itr->next->next;
                prev->next = prev->next->next;
                itr = prev->next;
            }
        }
        return dummy->next;
    }
};