#include "header.h"

void helper(vector<vector<int>>& result, TreeNode* node, int level);

vector<vector<int>> levelOrderBottom_r(TreeNode* root)
{
    vector<vector<int>> result;
    helper(result, root, 0);

    reverse(result.begin(), result.end());

    return result;
}

void helper(vector<vector<int>>& result, TreeNode* node, int level)
{
    if (!node)
    {
        return;
    }

    if (level >= result.size())
    {
        result.push_back(vector<int>());
    }

    result[level].push_back(node->val);

    helper(result, node->left, level + 1);
    helper(result, node->right, level + 1);
}