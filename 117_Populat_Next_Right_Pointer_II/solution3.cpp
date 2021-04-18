#include "header.h"

// Iterative, no queue
// Find the first node of each level, and visit each node of the level and
// set the next pointer for their children.
// Use 3 pointers:
// 1. current node
// 2. the previous node of current node so that we can set next pointer of the previous node.
// 3. the head of the next level so that we can move to next level. 
Node* connect3(Node* root)
{
    Node* cur_node = root;

    Node* head_of_level = nullptr;
    Node* pre_cur_node = nullptr;

    while (cur_node)
    {
        if (cur_node->left)
        {
            if (pre_cur_node)
            {
                pre_cur_node->next = cur_node->left;
            }

            pre_cur_node = cur_node->left;
            if (!head_of_level)
            {
                head_of_level = cur_node->left;
            }
        }

        if (cur_node->right)
        {
            if (pre_cur_node)
            {
                pre_cur_node->next = cur_node->right;
            }
            pre_cur_node = cur_node->right;

            if (!head_of_level)
            {
                head_of_level = cur_node->right;
            }
        }

        cur_node = cur_node->next;

        if (!cur_node)
        {
            cur_node = head_of_level;
            head_of_level = nullptr;
            pre_cur_node = nullptr;
        }
    }
    return root;
}