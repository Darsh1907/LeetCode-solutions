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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;

        ListNode* dummy = new ListNode(); // Create a dummy node
        dummy->next = head;
        ListNode* prev = dummy;

        // Move prev to the node before the sublist to be reversed
        for(int i=0; i<left-1; i++) prev = prev->next;

        ListNode* curr = prev->next; // Start reversing from curr
        ListNode* next = nullptr;

        // Reverse the sublist
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        ListNode* newHead = dummy->next; // Updated head of the reversed sublist

        delete dummy; // Clean up the dummy node

        return newHead;
    }
};