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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) s.insert(nums[i]);
        ListNode* dummyStart = new ListNode(0, head);
        ListNode* itr = dummyStart;
        while(itr->next != NULL) {
            if(s.find(itr->next->val) != s.end()) {
                itr->next = itr->next->next;
            }
            else itr = itr->next;
        }
        return dummyStart->next;
    }
};