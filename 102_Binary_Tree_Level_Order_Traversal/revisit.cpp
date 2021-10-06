#include "header.h"
#include <queue>

vector<vector<int>> levelOrder_r(TreeNode* root)
{
    vector<vector<int>> result;

    if (root)
    {
        std::queue<TreeNode*> pending;
        pending.push(root);

        while (!pending.empty())
        {
            size_t size = pending.size();
            vector<int> level(size, 0);
            for (size_t i = 0; i < size; i++)
            {
                TreeNode* node = pending.front();
                level[i] = node->val;
                pending.pop();

                if (node->left)
                {
                    pending.push(node->left);
                }

                if (node->right)
                {
                    pending.push(node->right);
                }
            }

            result.push_back(level);
        }
    }

    return result;
}