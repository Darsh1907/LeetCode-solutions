struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* nextNode = current->next;  // Store the next node
        current->next = prev;  // Reverse the link
        prev = current;
        current = nextNode;  // Move to the next node
    }
    return prev;  // Return the new head
}