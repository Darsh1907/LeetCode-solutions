                                
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Initialize a global variable 'prev' to keep track of the previously processed node.
    TreeNode* prev = NULL;
    // Function to flatten a binary tree to a right next Linked List structure
    void flatten(TreeNode* root) {
        // Base case: If the current node is NULL, return.
        if(root == NULL) return;
        // Use a stack for iterative traversal.
        stack<TreeNode*> st;
        // Push the root node onto the stack.
        st.push(root);  
        // Continue the loop until the stack is empty.
        while (!st.empty()) {  
            // Get the top node from the stack.
            TreeNode* cur = st.top(); 
            // Pop the top node.
            st.pop();  
            if (cur->right != NULL) { // Push the right child onto the stack.
                st.push(cur->right); 
            }
            if (cur->left != NULL) { // Push the left child onto the stack.
                st.push(cur->left); 
            }
            if (!st.empty()) {
                // Connect the right child to the next node in the stack.
                cur->right = st.top();  
            }
            // Set the left child to NULL to form a right-oriented linked list.
            cur->left = NULL;  
        }
    }
};

// Print the preorder traversal of the Orignal Binary Tree
void printPreorder(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the Right Pointers after Flattening
void printFlattenTree(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    sol.flatten(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    return 0;
}