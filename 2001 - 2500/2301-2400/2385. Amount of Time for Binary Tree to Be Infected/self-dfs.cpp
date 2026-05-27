#include <unordered_map>
#include <unordered_set>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void createMap_getPos(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* root, TreeNode*& pos, int& start) {
        if(root->val == start) pos = root;
        if(root->left) {
            parentMap[root->left] = root;
            createMap_getPos(parentMap, root->left, pos, start);
        }
        if(root->right) {
            parentMap[root->right] = root;
            createMap_getPos(parentMap, root->right, pos, start);
        }
        return;
    }
    int infect(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* pos, unordered_set<TreeNode*>& visited, int res) {
        if(pos==NULL) return res-1;
        if(visited.find(pos) != visited.end()) return res-1;
        visited.insert(pos);
        int p=res, l=res, r=res;
        p = infect(parentMap, parentMap[pos], visited, res+1);
        if(pos->left != NULL) l = infect(parentMap, pos->left, visited, res+1);
        if(pos->right != NULL) r = infect(parentMap, pos->right, visited, res+1);
        return max(max(l, r), p);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap; // root -> its parent
        TreeNode* pos;
        createMap_getPos(parentMap, root, pos, start);
        if(pos==NULL) return -1;
        unordered_set<TreeNode*> visited;
        int res = 0;
        res = infect(parentMap, pos, visited, res);
        return res;
    }
};