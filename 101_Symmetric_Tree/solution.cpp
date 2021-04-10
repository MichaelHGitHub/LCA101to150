#include "header.h"

static bool isMirror(TreeNode* root, TreeNode* reflection);

bool isSymmetric(TreeNode* root)
{
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* root, TreeNode* reflection)
{
    if (root == nullptr && reflection == nullptr)
    {
        return true;
    }

    if ((root == nullptr && reflection != nullptr) ||
        (root != nullptr && reflection == nullptr))
    {
        return false;
    }

    if (root->val != reflection->val)
    {
        return false;
    }

    return isMirror(root->left, reflection->right) && isMirror(root->right, reflection->left);
}