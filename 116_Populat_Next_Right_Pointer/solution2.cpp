#include "header.h"

// Recursive
// Visit nodes in pre-order, for each of the node, there are two things to do:
// 1. populate left child's next
// 2. populate right child's next if current->next exists.
Node* connect2(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
 
    if (root->left)
    {
        root->left->next = root->right;
    }

    if (root->right && root->next)
    {
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
}