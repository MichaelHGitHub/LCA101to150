#include "header.h"

static bool helper(TreeNode* root, int& sum, int& targetSum);

// Recursive 
// Calculate the sum of a node(from root to the node) from top down, when 
// encountering a leaf node, that's the sum for the branch
bool hasPathSum(TreeNode* root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }

    int sum = 0;
    return helper(root, sum, targetSum);
}

bool helper(TreeNode* root, int& sum, int& targetSum)
{
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (sum == targetSum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int left_sum = sum;
    if (root->left != nullptr && helper(root->left, left_sum, targetSum))
    {
        return true;
    }

    int right_sum = sum;
    if (root->right != nullptr && helper(root->right, right_sum, targetSum))
    {
        return true;
    }

    return false;
}