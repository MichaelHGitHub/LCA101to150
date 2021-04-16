#include <queue>
#include "header.h"

// Interative
// Traditional level-first traversal plus the fact that the first leaf node we have reached
// is the end of the branch with smallest depth.
int minDepth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int level = 0;

    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);
    while (!pending_nodes.empty())
    {
        ++level;
        int num_of_leve = pending_nodes.size();

        for (int i = 0; i < num_of_leve; i++)
        {
            TreeNode* node = pending_nodes.front();
            pending_nodes.pop();

            // If a leaf node is reached, that's it.
            if (node->left == nullptr && node->right == nullptr)
            {
                return level;
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
    }

    return level;
}