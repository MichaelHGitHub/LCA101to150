#include <stack>
#include "header.h"

// Iterative
// Typical pre-order traversal plus make the linked list at the same time
void flatten(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode*> pending_nodes;
    pending_nodes.push(root);

    // The head of the linked list
    TreeNode* cur = root;

    while (!pending_nodes.empty())
    {
        TreeNode* node = pending_nodes.top();
        pending_nodes.pop();

        // You already know to push right child first for preorder traversal
        if (node->right != nullptr)
        {
            pending_nodes.push(node->right);
        }

        if (node->left != nullptr)
        {
            pending_nodes.push(node->left);
            node->left = nullptr;
        }

        // Make our little linked list
        if (cur != node)
        {
            cur->right = node;
            cur = node;
        }
    }
}