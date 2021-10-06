#include "header.h"

void helper(vector<vector<int>>& result, TreeNode* node, int level);

vector<vector<int>> levelOrder_r2(TreeNode* root)
{
    vector<vector<int>> result;

    helper(result, root, 0);

    return result;
}

void helper(vector<vector<int>>& result, TreeNode* node, int level)
{
    if (!node)
    {
        return;
    }

    if (result.size() == level)
    {
        result.push_back(vector<int>());
    }

    result[level].push_back(node->val);

    helper(result, node->left, level + 1);
    helper(result, node->right, level + 1);
}