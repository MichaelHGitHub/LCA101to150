#include "header.h"
#include <stack>
#include <unordered_set>

vector<int> postorderTraversal_r(TreeNode* root)
{
    vector<int> result;

    if (nullptr != root)
    {
        std::stack<TreeNode*> pending;
        pending.push(root);

        std::unordered_set<TreeNode*> visited;

        while (!pending.empty())
        {
            TreeNode* node = pending.top();
            bool keep = false;

            if (nullptr != node->right &&
                visited.find(node->right) == visited.end())
            {
                pending.push(node->right);
                keep = true;
            }

            if (nullptr != node->left &&
                visited.find(node->left) == visited.end())
            {
                pending.push(node->left);
                keep = true;
            }

            if (!keep)
            {
                result.push_back(node->val);
                pending.pop();
                visited.insert(node);
            }
        }
    }

    return result;
}