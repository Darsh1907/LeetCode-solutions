/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* reverse(struct ListNode* head) {
    if(head==NULL) return head;
    struct ListNode* prev=NULL;
    struct ListNode* curr=head;
    struct ListNode* forward=NULL;
    while(curr!=NULL) {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    struct ListNode* prev=NULL;
    while(fast!=NULL) {
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=reverse(slow);
    struct ListNode* ptr1=head;
    struct ListNode* ptr2=prev->next;
    int sum=0;
    while(ptr2!=NULL) {
        int temp = ptr1->val + ptr2->val;
        if(temp>sum) sum=temp;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return sum;
}