#include "header.h"

static bool hasPathSum(TreeNode* root, int targetSum);

bool hasPathSum_r(TreeNode* root, int targetSum)
{
    return hasPathSum(root, targetSum);
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if (!root)
    {
        return false;
    }

    if (!root->left && !root->right && 0 == (targetSum - root->val))
    {
        return true;
    }

    if (root->left && hasPathSum(root->left, targetSum - root->val))
    {
        return true;
    }

    if (root->right && hasPathSum(root->right, targetSum - root->val))
    {
        return true;
    }

    return false;

}