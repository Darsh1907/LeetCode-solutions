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

// custom comparator for minHeap
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        // Initialize a minHeap
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        // step1: insert first elements of all lists
        for(int i=0; i<lists.size(); i++) {
            // insert only if it is not null
            if(lists[i]) minHeap.push(lists[i]);
        };
        // If Heap is empty then return a NULL
        if(minHeap.empty()) return NULL;
        // take first element and make it root. Add next element in Heap.
        ListNode* root = minHeap.top();
        minHeap.pop();
        if(root->next) minHeap.push(root->next);
        ListNode* curr = root;
        // step2: take top element from heap and insert new element again to always get the smallest element.
        while(!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();
            if(temp->next) minHeap.push(temp->next); // insert only if not null
            curr->next = temp;
            curr = curr->next;
        }
        // return is just to test the compilation
        return root;
    }
};