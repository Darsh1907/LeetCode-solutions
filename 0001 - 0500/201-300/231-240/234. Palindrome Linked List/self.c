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
    while(curr){
        struct ListNode* after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* rev = reverse(slow); // reverse second list
    while(rev != NULL) {
        if(head->val != rev->val) return false;
        head = head->next;
        rev = rev->next;
    }
    return true;
}