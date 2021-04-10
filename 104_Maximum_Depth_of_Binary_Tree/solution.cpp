#include "header.h"

// Recursive solution:

int maxDepth(TreeNode* root)
{
    return (root == nullptr ? 0 : (1 + max(maxDepth(root->left), maxDepth(root->right))));
}