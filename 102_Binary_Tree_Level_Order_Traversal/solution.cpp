#include "header.h"

static void helper(vector<vector<int>>& nodes, TreeNode* root, int level);

// Recursive solution:
// Traditional recursive pre-order traversal plus level tracking.
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    helper(result, root, 0);

    return result;
}

static void helper(vector<vector<int>>& result, TreeNode* root, int level)
{
    if (root == nullptr)
    {
        return;
    }

    if (level == result.size())
    {
        result.push_back(vector<int>());
    }
    result[level].push_back(root->val);

    helper(result, root->left, level + 1);
    helper(result, root->right, level + 1);
}