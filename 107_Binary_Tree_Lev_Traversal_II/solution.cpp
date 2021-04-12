#include "header.h"

static void helper(vector<vector<int>>& result, TreeNode* root, int level);

// Recursive:
// Use traditional preorder recursive algorithm plus level tracking
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> result;

    helper(result, root, 0);

    reverse(result.begin(), result.end());

    return result;
}

static void helper(vector<vector<int>>& result, TreeNode* root, int level)
{
    if (root == nullptr)
    {
        return;
    }

    if (level >= result.size())
    {
        result.push_back(vector<int>());
    }

    result[level].push_back(root->val);

    helper(result, root->left, level+1);
    helper(result, root->right, level+1);
}
