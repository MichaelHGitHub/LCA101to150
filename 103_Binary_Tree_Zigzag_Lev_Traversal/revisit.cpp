#include "header.h"
#include <queue>

vector<vector<int>> zigzagLevelOrder_r(TreeNode* root)
{
    vector<vector<int>> result;

    if (root)
    {
        std::queue<TreeNode*> pending;

        pending.push(root);
        bool left_to_right = true;

        while (!pending.empty())
        {
            size_t size = pending.size();
            vector<int> level(size, 0);

            int pos = 0;
            if (!left_to_right)
            {
                pos = size - 1;
            }

            while (pos >= 0 && pos < size)
            {

                TreeNode* node = pending.front();
                pending.pop();
                level[pos] = node->val;

                if (node->left)
                {
                    pending.push(node->left);
                }

                if (node->right)
                {
                    pending.push(node->right);
                }

                if (left_to_right)
                {
                    ++pos;
                }
                else
                {
                    --pos;
                }
            }
            left_to_right = !left_to_right;
            result.push_back(level);
        }
    }

    return result;
}