#include <stdbool.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int solve(struct TreeNode* root, bool isLeft) {
    if (root == NULL) return 0;
    if(!root->left && !root->right) {
        if(isLeft) return root->val;
        else return 0;
    }
    int leftSum = solve(root->left, true);
    int rightSum = solve(root->right, false);
    return leftSum + rightSum;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return solve(root, false);
}

int main() {
    // Create the tree nodes
    struct TreeNode node1, node2, node3, node4, node5;
    node1.val = 3;
    node2.val = 9;
    node3.val = 20;
    node4.val = 15;
    node5.val = 7;
    // Connect the tree nodes
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    node2.left = NULL;
    node2.right = NULL;
    node4.left = NULL;
    node4.right = NULL;
    node5.left = NULL;
    node5.right = NULL;
    // Calculate the sum of left leaves
    int sum = sumOfLeftLeaves(&node1);
    // Print the result
    printf("Sum of left leaves: %d\n", sum);
    return 0;
}