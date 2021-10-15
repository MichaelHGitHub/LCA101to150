#include "header.h"

bool helper(TreeNode* node, int& level);

bool isBalanced_r(TreeNode* root)
{
    int level = 0;
    return helper(root, level);
}

bool helper(TreeNode* node, int& level)
{
    if (!node)
    {
        return true;
    }
    ++level;
    int left_level = 0;
    int right_level = 0;

    if (!helper(node->left, left_level))
    {
        return false;
    }
    if (!helper(node->right, right_level))
    {
        return false;
    }
    level += max(left_level, right_level);

    return abs(left_level - right_level) < 2;
}