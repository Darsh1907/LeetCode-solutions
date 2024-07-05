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
        ListNode* prev = head; // points to prev node
        ListNode* curr = head->next; // points the current node which is supposed to be checked.
        vector<int> points; // vector to store the position of critical points (will always be sorted)
        int i=2; // to check position (initialised to 2 just cuz we start with the second node)
        while(curr->next != NULL) {
            // check for local maxima
            if(prev->val < curr->val && curr->next->val < curr->val) points.push_back(i);
            // check for local minima
            else if(prev->val > curr->val && curr->next->val > curr->val) points.push_back(i);
            // update
            i++;
            curr = curr->next;
            prev = prev->next;
        }
        // if there are not enough critical points
        if(points.size() < 2) return {-1, -1};
        // find maxDist and minDist
        int maxDist = points.back() - points[0];
        int minDist = INT_MAX;
        for(int i=1; i<points.size(); i++) minDist = min(minDist, points[i]-points[i-1]);
        return {minDist, maxDist};
    }
};