#include <stack>
#include "header.h"

vector<int> preorderTraversal(TreeNode* root) {

    vector<int> result;
    if (!root)
    {
        return result;
    }

    stack<TreeNode*> pending_nodes;
    pending_nodes.push(root);

    while (!pending_nodes.empty())
    {
        TreeNode* node = pending_nodes.top();
        pending_nodes.pop();

        result.push_back(node->val);

        if (node->right)
        {
            pending_nodes.push(node->right);
        }

        if (node->left)
        {
            pending_nodes.push(node->left);
        }
    }
    return result;
}