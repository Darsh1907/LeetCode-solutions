class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        for(ListNode* node = dummy; node!=nullptr; node=node->next){
            sum = sum + node->val;
            mp[sum] = node;
        }
        sum = 0;
        for(ListNode* node = dummy; node!=nullptr; node=node->next){
            sum = sum + node->val;
            node->next = mp[sum]->next;
        }
        return dummy->next;
    }
};