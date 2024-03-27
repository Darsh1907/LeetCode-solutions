/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if list is empty
        if(head == NULL) return NULL;

        // interleave the old and new list (without random pointers)
        Node* curr = head;
        while(curr!=NULL) {
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = curr->next->next;
        }

        // give correct values of random pointers for new list
        curr=head;
        while(curr!=NULL) {
            if(curr->random != NULL) curr->next->random=curr->random->next;
            curr = curr->next->next;
        }

        // Separate old nd new list
        Node* old_head = head;
        Node* new_head = head->next;
        Node* curr_old = old_head;
        Node* curr_new = new_head;
        while(curr_old!=NULL) {
            curr_old->next = curr_old->next->next;
            if(curr_new->next) curr_new->next = curr_new->next->next;
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }

        return new_head;
    }
};