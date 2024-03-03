// Note: This solution takes two pass to solve this problem 

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int list_size=0;
    while(temp!=NULL){
        temp = temp->next;
        list_size++;
    }
    temp = head;
    if(list_size==n) return head->next;
    for(int i=0; i<(list_size-n-1); i++) temp=temp->next;
    temp->next = temp->next->next;
    return head;
}