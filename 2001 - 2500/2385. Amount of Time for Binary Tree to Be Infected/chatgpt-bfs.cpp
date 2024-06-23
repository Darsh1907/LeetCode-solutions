#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

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
public:
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) return 0;
        // Map to store parent pointers
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = nullptr;
        // Helper function to create parent pointers map and find the start node
        function<void(TreeNode*)> createParentMap = [&](TreeNode* node) {
            if (node->val == start) startNode = node;
            if (node->left) {
                parentMap[node->left] = node;
                createParentMap(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                createParentMap(node->right);
            }
        };
        createParentMap(root);
        if (startNode == nullptr) return -1; // Start node not found
        // BFS to spread the infection
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool infected = false;
            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // Check and push left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                    infected = true;
                }
                // Check and push right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                    infected = true;
                }
                // Check and push parent
                if (parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                    infected = true;
                }
            }
            if(infected) time++;
        }
        return time;
    }
};