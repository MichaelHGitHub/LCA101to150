#include "header.h"
#include <queue>

int maxDepth_r(TreeNode* root)
{
    int depth = 0;

    if (root)
    {
        std::queue<TreeNode*> pending;
        pending.push(root);

        while (!pending.empty())
        {
            size_t size = pending.size();
            ++depth;
            for (int i = 0; i < size; i++)
            {
                if (pending.front()->left)
                {
                    pending.push(pending.front()->left);
                }

                if (pending.front()->right)
                {
                    pending.push(pending.front()->right);
                }

                pending.pop();
            }
        }

    }

    return depth;
}