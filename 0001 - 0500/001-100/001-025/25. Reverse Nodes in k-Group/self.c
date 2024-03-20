/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* reverse(struct ListNode* head, int k, int times){
    //base call
    if(times==0 || head==NULL) return head;
    // reverse first k node
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* after = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
        count++;
    }
    // recursion for the next nodes
    if(after != NULL) head->next = reverse(after, k, times-1);
    // return head of reversed list
    return prev;   
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* itr = head;
    int count = 1;
    while(itr->next != NULL) {
        itr = itr->next;
        count++;
    }
    int times = count/k; // the reverse should be done only for 'times' group.
    return reverse(head, k, times);
}