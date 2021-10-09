#include "header.h"

int depth(TreeNode* root);

int maxDepth_r2(TreeNode* root)
{
    return depth(root);
}

int depth(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(depth(root->left), depth(root->right));
}