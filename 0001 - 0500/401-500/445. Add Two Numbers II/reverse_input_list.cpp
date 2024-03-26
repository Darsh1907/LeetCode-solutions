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
private:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        int digit, sum, carry=0;
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            digit = sum%10;
            carry = sum/10;
            dummy->next = new ListNode(digit);
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr) {
            sum = l1->val + carry;
            digit = sum%10;
            carry = sum/10;
            dummy->next = new ListNode(digit);
            dummy = dummy->next;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            sum = l2->val + carry;
            digit = sum%10;
            carry = sum/10;
            dummy->next = new ListNode(digit);
            dummy = dummy->next;
            l2 = l2->next;
        }
        if(carry!=0) dummy->next = new ListNode(carry);
        return result->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newl1 = reverse(l1);
        ListNode* newl2 = reverse(l2);
        ListNode* temp = add(newl1, newl2);
        return reverse(temp);
    }
};