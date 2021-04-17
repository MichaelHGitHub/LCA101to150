#include <stack>
#include "header.h"

void helper(TreeNode* tree_node, TreeNode** link_node);

// Recursive
// Typical pre-order traversal plus an extra pointer for linked list,
void flatten2(TreeNode* root)
{
    TreeNode* list_node = nullptr;
    helper(root, &list_node);
}

// Note: in order to move the linked list node across left 
// and right subtree, we use a pointer to pointer
void helper(TreeNode* tree_node, TreeNode** link_node)
{
    if (tree_node == nullptr)
    {
        return;
    }

    // Save children node before change the pointers.
    TreeNode* left_child = tree_node->left;
    TreeNode* right_child = tree_node->right;

    // Munipulate the pointers to make the linked list.
    if (*link_node != nullptr)
    {
        (*link_node)->left = nullptr;
        (*link_node)->right = tree_node;
    }
    (*link_node) = tree_node;

    helper(left_child, link_node);
    helper(right_child, link_node);
}