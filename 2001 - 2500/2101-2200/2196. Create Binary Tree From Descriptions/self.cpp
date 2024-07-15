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
private:
    TreeNode* getParent(unordered_map<int, TreeNode*>& PointerMap, unordered_map<int, int>& ParentMap) {
        int i = (ParentMap.begin())->first;
        while(ParentMap[i]!=0) i=ParentMap[i];
        return PointerMap[i];
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> PointerMap;
        unordered_map<int, int> ParentMap;
        for(int i=0; i<descriptions.size(); i++) {
            // Get parent if already exists or create a new one
            auto searchParent = PointerMap.find(descriptions[i][0]);
            TreeNode* parent = NULL;
            if(searchParent == PointerMap.end()) {
                parent = new TreeNode(descriptions[i][0]);
                PointerMap[descriptions[i][0]] = parent;
            }
            else parent = searchParent->second;
            // Get child if already exists or create a new child
            auto searchChild = PointerMap.find(descriptions[i][1]);
            TreeNode* child = NULL;
            if(searchChild == PointerMap.end()) {
                child = new TreeNode(descriptions[i][1]);
                PointerMap[descriptions[i][1]] = child;
            }
            else child = searchChild->second;
            // Make connections
            if(descriptions[i][2]) parent->left = child;
            else parent->right = child;
            // Assign parent child relation in ParentMap
            ParentMap[descriptions[i][1]] = descriptions[i][0];
        }
        return getParent(PointerMap, ParentMap);
    }
};