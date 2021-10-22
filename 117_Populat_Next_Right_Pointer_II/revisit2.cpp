#include "header.h"

void helper(Node* node);

Node* connect_r2(Node* root)
{
    helper(root);
    return root;
}

void helper(Node* node)
{
    if (nullptr == node)
    {
        return;
    }

    if (nullptr != node->left || nullptr != node->right)
    {
        Node* next = node->next;
        while (nullptr != next && nullptr == next->left && nullptr == next->right)
        {
            next = next->next;
        }

        if (nullptr != node->left && nullptr != node->right)
        {
            node->left->next = node->right;
            if (nullptr != next)
            {
                node->right->next = next->left ? next->left : next->right;
            }
        }
        else if (nullptr != node->left)
        {
            if (nullptr != next)
            {
                node->left->next = next->left ? next->left : next->right;
            }
        }
        else if (nullptr != node->right)
        {
            if (nullptr != next)
            {
                node->right->next = next->left ? next->left : next->right;
            }
        }
    }

    helper(node->left);
    helper(node->right);

    // There might be some broken links in the chain,
    // once more will fix them.
    helper(node->left);
}