#include "header.h"

static void helper(TreeNode* node, TreeNode** lastVisit);

void flatten_r(TreeNode* root)
{
    TreeNode* lastVisit = nullptr;
    helper(root, &lastVisit);
}

void helper(TreeNode* node, TreeNode** lastVisit)
{
    if (nullptr == node)
    {
        return;
    }

    *lastVisit = node;

    // Swap left and right sub-branches
    if (nullptr != node->left)
    {
        TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }

    // current right was left
    helper(node->right, lastVisit);
    if (nullptr != *lastVisit)
    {
        (*lastVisit)->right = node->left;
    }

    // current left was right
    helper(node->left, lastVisit);
    node->left = nullptr;
}