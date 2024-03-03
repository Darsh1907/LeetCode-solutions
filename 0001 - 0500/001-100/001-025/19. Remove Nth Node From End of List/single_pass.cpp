class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i=0; i<=n; i++) first = first->next; // first will point on (n+1)th node from head
        while (first != nullptr) { // second should point on (n-1)th node from end
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next; // return dummy->next cuz hed could be the element that we would have removed;
    }
};