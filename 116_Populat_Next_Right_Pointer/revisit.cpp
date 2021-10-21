#include "header.h"

Node* connect_r(Node* root)
{
    if (nullptr != root)
    {
        root->next = nullptr;

        Node* up_level_current = root;
        Node* begin = up_level_current->left;
        Node* current = begin;

        while (nullptr != current)
        {
            if (up_level_current->left == current)
            {
                current->next = up_level_current->right;
                up_level_current = up_level_current->next;
            }
            else
            {
                current->next = up_level_current->left;
            }
            current = current->next;

            if (nullptr == up_level_current)
            {
                current->next = nullptr;
                up_level_current = begin;
                begin = up_level_current->left;
                current = begin;
            }
        }
    }
    return root;
}