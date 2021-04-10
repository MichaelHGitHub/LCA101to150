#include <queue>
#include "header.h"

// Non-recursive solution:

int maxDepth2(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);
    int depth = 0;

    while (!pending_nodes.empty())
    {
        ++depth;

        int num_of_cur_level = pending_nodes.size();

        for (int i = 0; i < num_of_cur_level; i++)
        {
            TreeNode* node = pending_nodes.front();
            pending_nodes.pop();

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

    return depth;
}