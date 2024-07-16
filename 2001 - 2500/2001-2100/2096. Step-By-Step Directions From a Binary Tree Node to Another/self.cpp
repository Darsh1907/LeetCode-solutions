// Hint1: The shortest path between any two nodes in a tree must pass through
// their Lowest Common Ancestor (LCA). The path will travel upwards from node s
// to the LCA and then downwards from the LCA to node t. Hint2: Find the path
// strings from root → s, and root → t. Can you use these two strings to prepare
// the final answer? Hint3: Remove the longest common prefix of the two path
// strings to get the path LCA → s, and LCA → t. Each step in the path of LCA →
// s should be reversed as 'U'.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
*/

class Solution {
    void customReverse(string& str) {
        for(int i=0; i<str.size(); i++) str[i]='U';
    }
    void removeLongestCommonPrefix(string& a, string& b) {
        int minsize = min(a.size(), b.size());
        for (int i = 0; i < minsize; i++) {
            if (a[i] != b[i]) {
                a = a.substr(i, (a.size() - i));
                b = b.substr(i, (b.size() - i));
                return;
            }
        }
        if (a.size() == minsize) {
            a = "";
            b = b.substr(minsize, (b.size() - minsize));
            return;
        } 
        else if (b.size() == minsize) {
            b = "";
            a = a.substr(minsize, (a.size() - minsize));
            return;
        }
    }
    void getString(TreeNode* root, int value, string& res, string& temp) {
        if (root->val == value) {
            res = temp;
            return;
        }
        if (root->left) {
            temp.push_back('L');
            getString(root->left, value, res, temp);
            temp.pop_back();
        }
        if (root->right) {
            temp.push_back('R');
            getString(root->right, value, res, temp);
            temp.pop_back();
        }
        return;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string toStart;
        string temp;
        getString(root, startValue, toStart, temp);
        string toDest;
        getString(root, destValue, toDest, temp);
        removeLongestCommonPrefix(toStart, toDest);
        customReverse(toStart);
        toStart += toDest;
        return toStart;
    }
};