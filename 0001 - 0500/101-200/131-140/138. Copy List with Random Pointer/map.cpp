class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if list is empty
        if(head == NULL) return NULL;

        // map to store the mapping of each old node to its new duplicate
        unordered_map<Node*, Node*> old_to_new;

        // duplicate nodes without random pointers and update map
        Node* newhead = new Node(head->val);
        old_to_new[head] = newhead;
        Node* oldCurr = head->next;
        Node* newCurr = newhead;

        while (oldCurr != NULL) {
            newCurr->next = new Node(oldCurr->val);
            old_to_new[oldCurr] = newCurr->next;
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        // duplicate random pointers using map
        oldCurr = head;
        newCurr = newhead;
        while(oldCurr != NULL) {
            newCurr->random = old_to_new[oldCurr->random];
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        // return newly formed list
        return newhead;
    }
};
