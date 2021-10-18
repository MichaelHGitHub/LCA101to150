#include "header.h"

void helper(vector<vector<int>>& result, vector<int>& path, TreeNode* node, int targetSum);


vector<vector<int>> pathSum_r(TreeNode* root, int targetSum)
{
    vector<vector<int>> result;
    vector<int> path;
    helper(result, path, root, targetSum);
    return result;
}

void helper(vector<vector<int>>& result, vector<int>& path, TreeNode* node, int targetSum)
{
    if (nullptr == node)
    {
        return;
    }

    path.push_back(node->val);

    targetSum -= node->val;
    if (0 == targetSum && nullptr == node->left && nullptr == node->right)
    {
        result.push_back(path);
    }

    helper(result, path, node->left, targetSum);
    helper(result, path, node->right, targetSum);

    path.pop_back();
}