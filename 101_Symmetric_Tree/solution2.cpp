#include <stack>
#include "header.h"

bool isSymmetric2(TreeNode* root)
{
    stack<TreeNode*> nodes, reflections;

    nodes.push(root->left);
    reflections.push(root->right);

    while (!nodes.empty() && !reflections.empty())
    {
        TreeNode* node = nodes.top();
        nodes.pop();

        TreeNode* reflection = reflections.top();
        reflections.pop();

        if (node == nullptr && reflection == nullptr)
        {
            continue;
        }

        if ((node == nullptr && reflection != nullptr) ||
            (node != nullptr && reflection == nullptr))
        {
            return false;
        }

        if (node->val != reflection->val)
        {
            return false;
        }

        nodes.push(node->right);
        nodes.push(node->left);
        reflections.push(reflection->left);
        reflections.push(reflection->right);
    }

    if (!nodes.empty() || !reflections.empty())
    {
        return false;
    }

    return true;
}
