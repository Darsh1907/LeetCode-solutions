struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *head2 = head;
    int total_count = 0;
    while(head2 != NULL){
        head2 = head2->next;
        total_count++;
    }
    int req = (total_count/2) + 1;
    for(int i=1; i!=req; i++) head=head->next;
    return head;
}