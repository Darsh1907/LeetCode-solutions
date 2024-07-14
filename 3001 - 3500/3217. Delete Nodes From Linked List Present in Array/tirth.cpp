class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (numSet.find(current->next->val) != numSet.end()) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } 
            else current = current->next;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};