#include "header.h"

int helper(TreeNode* node);

int minDepth_r(TreeNode* root)
{
    return helper(root);
}

int helper(TreeNode* node)
{
    int depth = 0;

    if (node)
    {
        int left = helper(node->left);
        int right = helper(node->right);

        if (left && right)
        {
            depth = 1 + min(left, right);
        }
        else if (left)
        {
            depth = 1 + left;
        }
        else
        {
            depth = 1 + right;
        }
    }

    return depth;
}