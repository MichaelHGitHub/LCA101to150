#include "header.h"
#include <stack>

vector<int> preorderTraversal_r(TreeNode* root)
{
    vector<int> result;

    if (nullptr != root)
    {
        std::stack<TreeNode*> pending;
        pending.push(root);

        while (!pending.empty())
        {
            TreeNode* node = pending.top();
            pending.pop();
            result.push_back(node->val);

            if (nullptr != node->right)
            {
                pending.push(node->right);
            }

            if (nullptr != node->left)
            {
                pending.push(node->left);
            }
        }
    }

    return result;
}