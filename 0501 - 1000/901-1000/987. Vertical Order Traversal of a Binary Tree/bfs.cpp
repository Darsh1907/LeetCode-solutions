// BFS solution for vertical order traversal of a binary tree

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        map<int, vector<int>> temp;
        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            TreeNode* t = a.first;
            int x = a.second;
            temp[x].push_back(t->val);
            if (t->left) q.push({t->left, x - 1});
            if (t->right) q.push({t->right, x + 1});
        }
        for (auto a : temp) {
            sort(a.second.begin(), a.second.end());
            m[a.first].insert(m[a.first].end(), a.second.begin(), a.second.end());
        }
    }
    for (auto a : m) {
        res.push_back(a.second);
    }
    return res;
}

int main() {
    // Create a binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = verticalTraversal(root);
    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time complexity: O(nlogn)
// Space complexity: O(n)