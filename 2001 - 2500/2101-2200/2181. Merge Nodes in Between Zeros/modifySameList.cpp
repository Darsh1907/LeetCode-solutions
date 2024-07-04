/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = head->next;
        ListNode*curr = head->next;
        ListNode ans(0, curr);
        int sum = 0;
        for (; curr; curr=curr->next){
            if (curr->val != 0) sum += curr->val;
            else {
                prev->val = sum;
                prev->next = curr->next;
                prev = prev->next;
                sum = 0;
            }
        } 
        return ans.next;
    }
};