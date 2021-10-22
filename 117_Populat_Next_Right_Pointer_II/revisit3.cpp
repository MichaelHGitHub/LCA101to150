
#include "header.h"


Node* connect_r3(Node* root)
{
    Node* current = root;
    Node* next_head = nullptr;
    Node* next_current = nullptr;

    while (nullptr != current)
    {
        if (nullptr != current->left)
        {
            if (nullptr != next_current)
            {
                next_current->next = current->left;
                next_current = next_current->next;
            }
           
            if(nullptr == next_head)
            {
                next_head = current->left;
                next_current = next_head;
            }
        }

        if (nullptr != current->right)
        {
            if (nullptr != next_current)
            {
                next_current->next = current->right;
                next_current = next_current->next;
            }

            if (nullptr == next_head)
            {
                next_head = current->right;
                next_current = next_head;
            }
        }
        current = current->next;

        // Current level is done, 
        if (nullptr == current)
        {
            current = next_head;
            next_head = nullptr;
            next_current = nullptr;
        }
    }

    return root;
}