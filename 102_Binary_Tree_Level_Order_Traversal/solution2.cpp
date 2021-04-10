#include <queue>
#include "header.h"

// Non-Recursive solution:
// Traditional breadth-first traversal plus level tracking.
vector<vector<int>> levelOrder2(TreeNode* root)
{
    vector<vector<int>> result;

    if (root == nullptr)
    {
        return result;
    }
    
    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);
    int level = 0;

    while (!pending_nodes.empty())
    {
        // So far all the nodes in pending_nodes are at the same level
        int num_of_cur_lev = pending_nodes.size();

        // Handle all and only the nodes at this level so that
        // we can keep tracking level
        for (int i = 0; i < num_of_cur_lev; i++)
        {
            TreeNode* node = pending_nodes.front();
            pending_nodes.pop();

            if (level >= result.size())
            {
                result.push_back(vector<int>());
            }
            result[level].push_back(node->val);

            if (node->left != nullptr)
            {
                pending_nodes.push(node->left);
            }

            if (node->right != nullptr)
            {
                pending_nodes.push(node->right);
            }
        }
        // Prepare for next level
        ++level;
    }

    return result;
}

