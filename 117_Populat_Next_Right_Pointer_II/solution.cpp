#include "header.h"

// Iterative, no queue
// Find the first node of each level, and visit each node of the level and
// set the next pointer for their children.
// The next pointer of node->child could be:
//  1. node->right(if the child is node->left and node->right exists)
//  2. node->next...->left(if exists)
//  3. node->next...->right
// One inportant thing to notice:
// In the search for children to set next pointer, the first
// child we find will be the first node in the next level. This is the key
// to reduce duplication and optimize code for performance.
Node* connect(Node* root)
{
    Node* first_node_of_level = root;

    while (first_node_of_level)
    {
        Node* node = first_node_of_level;

        // Reset the first node pointer to facilitate setting next one.
        first_node_of_level = nullptr;

        while (node)
        {
            Node* next = node->next;
            Node* child = node->left ? node->left : node->right;

            while (child)
            {
                // The first child we find will be the first node at next level.
                if (first_node_of_level == nullptr)
                {
                    first_node_of_level = child;
                }

                // Set next pointer for the child.

                if (child == node->left && node->right)
                {
                    child->next = node->right;
                }
                else
                {
                    // Search a next node who has children.
                    while (next)
                    {
                        if (next->left)
                        {
                            child->next = next->left;
                            break;
                        }
                        else if (next->right)
                        {
                            child->next = next->right;
                            break;
                        }
                        else
                        {
                            next = next->next;
                        }
                    }

                    if (next == nullptr)
                    {
                        child->next = nullptr;
                    }
                }

                // if the current child is left child, repeat the operation for right child.
                if (child == node->left)
                {
                    child = node->right;
                }
                else
                {
                    break;
                }
            }

            // Node, here node is set to next in stead of node->next to skip the siblings
            // who don't have children. 
            node = next;
        }
    }
    return root;
}