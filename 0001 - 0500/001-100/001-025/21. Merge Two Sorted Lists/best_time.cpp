class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode *head = new ListNode();
        ListNode *result = head;
        while(list1 && list2) {
            if (list1->val < list2->val) {
                result->next = list1;
                list1 = list1->next;
            }
            else {
                result->next = list2;
                list2 = list2->next;
            }
            result = result->next;
        }
        if(!list1) result->next = list2;
        else result->next = list1;
        return head->next;
    }
};