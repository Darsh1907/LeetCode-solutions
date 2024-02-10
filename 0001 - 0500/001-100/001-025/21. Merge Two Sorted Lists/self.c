/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* createNewNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct ListNode* head = NULL;
    struct ListNode* curr = NULL;
    // Create the first node
    curr = createNewNode(list1->val<=list2->val ? list1->val : list2->val);
    head = curr;
    if (list1->val<=list2->val) list1=list1->next;
    else list2=list2->next;
    // For rest all nodes
    while (list1 != NULL && list2 != NULL) {
        curr->next = createNewNode(list1->val<=list2->val ? list1->val : list2->val);
        curr = curr->next;
        if (list1->val<=list2->val) list1=list1->next;
        else list2=list2->next;
    }
    // Append remaining nodes from either list1 or list2
    curr->next = list1 != NULL ? list1 : list2;
    return head;
}