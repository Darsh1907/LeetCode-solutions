/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void postorder(Node* root, vector<int>& res) {
        if(!root) return;
        else {
            for(auto child: root->children) postorder(child, res);
            res.push_back(root->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};