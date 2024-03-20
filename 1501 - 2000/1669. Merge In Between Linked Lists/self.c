/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int a_count=0;
    struct ListNode* ap = list1;
    while(a_count != a-1){
        ap = ap->next;
        a_count++;
    }
    int b_count = a_count;
    struct ListNode* bp = ap;
    while(b_count != b+1){
        bp = bp->next;
        b_count++;
    }
    ap->next = list2;
    while(list2->next != NULL) list2=list2->next;
    list2->next = bp;
    return list1;
}