#include "header.h"


static bool getDepth(TreeNode* root, int& depth);

// It's easy to calculate the depth of each node, it's also easy to check the depth
// of left and right sub-tree and level, but how can we do these two things together/
// one way to do it is return value for one and a out parameter for the other. 
// Another way could be return nagetive number for one and postive for depth. 
bool isBalanced(TreeNode* root)
{
    int depth;
    return getDepth(root, depth);
}

bool getDepth(TreeNode* root, int& depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return true;
    }

    int left_depth = 0;
    int right_depth = 0;

    if (!getDepth(root->left, left_depth))
    {
        return false;
    }

    if (!getDepth(root->right, right_depth))
    {
        return false;
    }

    if (left_depth - right_depth > 1 || right_depth - left_depth > 1)
    {
        return false;
    }

    depth = max(left_depth, right_depth) + 1;

    return true;
}