/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* itr = head;
    while(itr->next != NULL){
        if(itr->val == itr->next->val) itr->next = itr->next->next;
        else itr = itr->next;
    }
    return head;
}