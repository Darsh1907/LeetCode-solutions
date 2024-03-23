/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* reverse(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* after = NULL;
    while(curr){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

struct ListNode* cut_and_reverse(struct ListNode* head){
    struct ListNode* slow_prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow_prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slow_prev->next = NULL;
    // reverse second half of the list
    return reverse(slow);
}

void reorderList(struct ListNode* head) {
    if(head->next == NULL) return;
    struct ListNode* rev = cut_and_reverse(head); 
    struct ListNode* temp = head;
    while(temp!=NULL){
        struct ListNode* temp_next = temp->next;
        struct ListNode* rev_next = rev->next;
        temp->next = rev;
        if(temp_next != NULL) rev->next = temp_next;
        temp = temp_next;
        rev = rev_next;
    }
}