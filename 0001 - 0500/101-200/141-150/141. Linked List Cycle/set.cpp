class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head!=nullptr) {
            if(s.find(head)!=s.end()) return true;
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};