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
    // Assign topdown and leftright values to each node and store them in a map
    void solve(TreeNode* root, int topdown, int leftright, map<int, vector<pair<int, int>>>& mp) {
        if(root==NULL) return;
        mp[leftright].push_back({topdown, root->val});
        solve(root->left, topdown+1, leftright-1, mp);
        solve(root->right, topdown+1, leftright+1, mp);
        return;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;

        map<int, vector<pair<int, int>>> mp;  // first = leftright and second = pair = {topdown, root->val} 
        mp[0].push_back({0, root->val});

        // Assign topdown and leftright values to each node and store them in a map
        solve(root->left, 1, -1, mp);
        solve(root->right, 1, 1, mp);

        for(auto ptr=mp.begin(); ptr!=mp.end(); ptr++) {
            // Sort the nodes in the same column by topdown and then by value
            auto comparator = [](const pair<int, int>&a, const pair<int, int>&b) {
                if(a.first != b.first) return a.first < b.first;
                else return a.second < b.second;
            };
            sort(ptr->second.begin(), ptr->second.end(), comparator);
            vector<int> temp;
            for(int i=0; i<(ptr->second.size()); i++) {
                temp.push_back(ptr->second[i].second);
            }
            res.push_back(temp);
        }

        return res;
    }
};