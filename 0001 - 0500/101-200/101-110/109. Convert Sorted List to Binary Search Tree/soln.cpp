// Reference Video: https://www.youtube.com/watch?v=cN823mo1r4k

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class Solution {
    TreeNode* convertToBST(ListNode* start, ListNode* end) {
        if(start==end) return NULL;
        // finding mid node using slow and fast pointer
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast!=end && fast->next!=end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow now points to the mid element
        TreeNode* root = new TreeNode(slow->val);
        root->left = convertToBST(start, slow); // note: new end is not part of the search space for the next function call
        root->right = convertToBST(slow->next, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        return convertToBST(head, NULL);
    }
};