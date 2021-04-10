#include <queue>
#include "header.h"

// Traditional breadth-first traversal plus level and direction tracking
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> result;

    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);

    // Need a variable to track direction
    bool to_right = true;

    while (!pending_nodes.empty())
    {
        int num_of_cur_lev = pending_nodes.size();
        result.push_back(vector<int>(num_of_cur_lev, 0));

        // Just use the result size to track level
        int level = result.size() - 1;

        for (int i = 0; i < num_of_cur_lev; i++)
        {
            TreeNode* node = pending_nodes.front();
            pending_nodes.pop();

            if (to_right)
            {
                result[level][i] = node->val;
            }
            else
            {
                result[level][num_of_cur_lev - 1 - i] = node->val;
            }

            if (node->left != nullptr)
            {
                pending_nodes.push(node->left);
            }
            if (node->right != nullptr)
            {
                pending_nodes.push(node->right);
            }
        }

        to_right = !to_right;
    }

    return result;
}