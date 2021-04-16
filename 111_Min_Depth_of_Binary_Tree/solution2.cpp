#include "header.h"

static void helper(TreeNode* root, int& depth, int& min_depth);

// Recursive
// Count level in a top-down approach. When reaching a leaf node, that's the depth of the
// branch, save the smallest depth in the traversal.
int minDepth2(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int depth = 0;
    int min_depth = INT32_MAX;

    helper(root, depth, min_depth);

    return min_depth;
}

static void helper(TreeNode* root, int& depth, int& min_depth)
{
    if (root == nullptr)
    {
        return;
    }

    // count the current level before going down.
    ++depth;

    // If this is a leaf node, we've got the depth of this branch.
    if (root->left == nullptr && root->right == nullptr)
    {
        min_depth = min(min_depth, depth);
    }

    int left_depth = depth;
    int right_depth = depth;
    helper(root->left, left_depth, min_depth);
    helper(root->right, right_depth, min_depth);
}