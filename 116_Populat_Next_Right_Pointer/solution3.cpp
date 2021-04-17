#include "header.h"

// Travel through the left most sub-tree, which is made of all the first nodes
// of each level. From the first node of each level, visit its siblings
// using next pointer. The next poit will be ready by the time we are visiting 
// the node because we set the next pointer in a top-down approach, which means
// the next pointer of the current node was set when we were visiting the parent
// of the current node.
Node* connect3(Node* root)
{
    Node* first_node_of_level = root;

    while (first_node_of_level)
    {
        Node* node_of_level = first_node_of_level;

        while (node_of_level)
        {
            if (node_of_level->left)
            {
                node_of_level->left->next = node_of_level->right;
            }

            if (node_of_level->next && node_of_level->right)
            {
                node_of_level->right->next = node_of_level->next->left;
            }

            node_of_level = node_of_level->next;
        }

        first_node_of_level = first_node_of_level->left;
    }
    return root;
}