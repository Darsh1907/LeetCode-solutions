/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* findMid(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;
}

struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    // Dummy node to which the sorted linked list would be connected to
    struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    ans->val = -1; // initialize the dummy node value

    struct ListNode* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left->val < right->val) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left!=NULL) temp->next = left;
    if(right != NULL) temp->next = right;
    ans = ans -> next;
    return ans;
}

struct ListNode* sortList(struct ListNode* head) {
    //base case
    if(head==NULL || head->next == NULL) return head;
    // break linked list into 2 halvs, after finding mid
    struct ListNode* mid = findMid(head);
    struct ListNode* left = head;
    struct ListNode* right = mid->next;
    mid -> next = NULL;
    //recursive calls to sort both halves
    left = sortList(left);
    right = sortList(right);
    //merge both left and right halves
    struct ListNode* result = merge(left, right);
    return result;
}