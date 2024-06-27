// Intuition
// The goal of this problem is to transform a given binary tree into a "flattened" binary tree where all nodes appear in a single right-skewed line (essentially converting it into a linked list using the right pointers). 
// The left child of every node should be null.

// Approach
// To achieve this transformation without using additional space, we use a method called Morris Traversal. 
// The idea is to use the tree itself to store the traversal state temporarily.

// Here’s the detailed approach:
// 1. Start from the root and traverse the tree using the current node.
// 2. For each node:
// - If it has a left child, find the rightmost node in the left subtree (this node will be the predecessor).
// - Link this predecessor's right pointer to the current node's right subtree.
// - Move the left subtree to the right and set the left child to null.
// - Move to the right child of the current node.
// 3. Repeat this process until the entire tree is flattened.
// - This approach ensures that we modify the tree in-place without using extra space for recursion or a stack.

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* current = root;
        while(current != nullptr){
            if(current->left) {
                TreeNode* prev = current->left;
                while(prev->right) prev = prev->right;
                prev->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }        
    }
};