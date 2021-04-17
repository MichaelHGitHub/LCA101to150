#include "header.h"

static void helper(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int targetSum);

// Recursive
// Top down to build the path and deduct the target sum until it reaches 0.
vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    vector<vector<int>> result;
    vector<int> path;

    helper(result, path, root, targetSum);

    return result;
}

void helper(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int targetSum)
{
    if (root == nullptr)
    {
        return;
    }

    targetSum -= root->val;
    path.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr && targetSum == 0)
    {
        result.push_back(path);
    }
    else
    {
        helper(result, path, root->left, targetSum);
        helper(result, path, root->right, targetSum);
    }

    path.pop_back();
}