class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head!=nullptr) {
            if(s.find(head)!=s.end()) return head;
            s.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};