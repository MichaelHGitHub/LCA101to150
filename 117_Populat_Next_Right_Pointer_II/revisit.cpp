#include "header.h"

Node* connect_r(Node* root)
{
    if (nullptr != root)
    {
        Node* current = root;
        Node* next_begin = current->left ? current->left : current->right;
        Node* next_cur = next_begin;

        while (nullptr != current && nullptr != next_cur)
        {
            if (current->left == next_cur)
            {
                if (nullptr != current->right)
                {
                    next_cur->next = current->right;
                    next_cur = next_cur->next;
                    current = current->next;
                }
                else
                {
                    current = current->next;
                }
            }
            else if (current->right == next_cur)
            {
                current = current->next;
            }
            else
            {
                if (nullptr != current->left && nullptr != current->right)
                {
                    next_cur->next = current->left;
                    next_cur = next_cur->next;
                }
                else if (nullptr != current->left)
                {
                    next_cur->next = current->left;
                    next_cur = next_cur->next;
                    current = current->next;
                }
                else if (nullptr != current->right)
                {
                    next_cur->next = current->right;
                    next_cur = next_cur->next;
                    current = current->next;
                }
                else
                {
                    current = current->next;
                }
            }

            // The current level is done, move on to next level
            if (nullptr == current)
            {
                current = next_begin;
                while (nullptr != current && (nullptr == current->left && nullptr == current->right))
                {
                    current = current->next;
                }
                if (nullptr != current)
                {
                    next_begin = current->left ? current->left : current->right;
                    next_cur = next_begin;
                }
            }
        }
    }

    return root;
}