#include "header.h"

static void helper(int& sum, int num, TreeNode* root);

// Recursive
// Build the number in pre-order traversal order, when meet a leaf node, a number is complete.
int sumNumbers(TreeNode* root)
{
    int sum = 0;
    helper(sum, 0, root);
    return sum;
}

static void helper(int& sum, int num, TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    num = (num * 10 + root->val);
    if (!root->left && !root->right)
    {
        sum += num;
        return;
    }

    helper(sum, num, root->left);
    helper(sum, num, root->right);
}