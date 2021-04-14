#include "header.h"

static TreeNode* helper(ListNode** cur_l_node, int start, int end);

// Simulate inorder traversal, create each node in the order of the tree node 
// that would have been visited, which is the exact order of the linked list 
// order.
TreeNode* sortedListToBST2(ListNode* head)
{
    ListNode* node = head;
    int count = 0;
    while (node != nullptr)
    {
        node = node->next;
        ++count;
    }

    return helper(&head, 0, count - 1);
}

TreeNode* helper(ListNode** cur_l_node, int start, int end)
{
    if (start > end || *cur_l_node == nullptr)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    TreeNode* left = helper(cur_l_node, start, mid - 1);

    TreeNode* t_node = new TreeNode((*cur_l_node)->val);
    *cur_l_node = (*cur_l_node)->next;

    t_node->left = left;
    t_node->right = helper(cur_l_node, mid + 1, end);

    return t_node;
}