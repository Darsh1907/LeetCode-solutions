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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // creating mapping of node to its previous node
        unordered_map<ListNode*, ListNode*> umap;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr!=NULL) {
            umap[curr] = prev;
            curr = curr->next;
            prev = prev->next;
        }
        // now starting the traversal to check all the critical points and storing them in a vector.
        vector<int> points; // will be a sorted vector of integers (postions)
        ListNode* itr = head->next; // to skip the first node
        int i=2; // to calculate distance (initialized to 2 just cuz we start with the second node)
        while(itr->next != NULL) {
            // check if it is local maxima
            if(itr->next->val > itr->val && umap[itr]->val > itr->val) points.push_back(i);
            // check for local minima
            else if(itr->next->val < itr->val && umap[itr]->val < itr->val) points.push_back(i);
            // increment i and itr
            i++;
            itr = itr->next;
        }
        // if not enough elements in set.
        if(points.size() < 2) return {-1, -1};
        int maxDist = points.back() - points[0];
        int minDist = INT_MAX;
        for(int i=1; i<points.size(); i++) {
            minDist = min(minDist, points[i] - points[i-1]);
        }
        return {minDist, maxDist};
    }
};