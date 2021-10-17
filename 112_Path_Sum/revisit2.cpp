#include "header.h"
#include <stack>
#include <unordered_map>

bool hasPathSum_r2(TreeNode* root, int targetSum)
{
    bool result = false;

    if (root)
    {
        std::stack<TreeNode*> pending;
        pending.push(root);

        unordered_map<TreeNode*, int> subSums;
        subSums[root] = root->val;

        while (!pending.empty())
        {
            TreeNode* node = pending.top();
            pending.pop();

            if (!node->right && !node->left)
            {
                if (subSums[node] == targetSum)
                {
                    result = true;
                    break;
                }
            }

            if (node->right)
            {
                subSums[node->right] = subSums[node] + node->right->val;
                pending.push(node->right);
            }

            if (node->left)
            {
                subSums[node->left] = subSums[node] + node->left->val;
                pending.push(node->left);
            }
        }
    }

    return result;
}