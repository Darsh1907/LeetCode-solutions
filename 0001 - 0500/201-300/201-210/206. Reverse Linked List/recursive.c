struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* h2 = reverseList(head->next);
    head->next->next = head;
    head->next=prev;
    return h2;
}