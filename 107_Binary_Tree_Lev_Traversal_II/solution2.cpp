#include <queue>
#include "header.h"

// Non-recursive:
// Use traditional level traversal plus level tracking
vector<vector<int>> levelOrderBottom2(TreeNode* root)
{
    vector<vector<int>> result;
    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);

    while (!pending_nodes.empty())
    {
        // So far, the nodes in the queue are all on the same level
        // we only handle these many and leave newly add nodes to next
        // iteration.
        int num_at_the_level = pending_nodes.size();
        result.push_back(vector<int>(num_at_the_level));
        for (int i = 0; i < num_at_the_level; i++)
        {
            TreeNode* node = pending_nodes.front();
            pending_nodes.pop();

            result[result.size() - 1][i] = node->val;

            if (node->left != nullptr)
            {
                pending_nodes.push(node->left);
            }

            if (node->right != nullptr)
            {
                pending_nodes.push(node->right);
            }
        }
    }

    reverse(result.begin(), result.end());

    return result;
}