#include <queue>
#include "header.h"

// Typical level traversal plus set next pointer for each node
Node* connect2(Node* root)
{
    if (root == nullptr)
    {
        return root;
    }

    queue<Node*> pending_nodes;
    pending_nodes.push(root);

    while (!pending_nodes.empty())
    {
        // So far the nodes in queue are all at the save level
        int width_of_level = pending_nodes.size();

        for (int i = 0; i < width_of_level; i++)
        {
            Node* node = pending_nodes.front();
            pending_nodes.pop();

            // Handle the last node of the level differently
            if (i < width_of_level - 1)
            {
                node->next = pending_nodes.front();
            }
            else
            {
                node->next = nullptr;
            }

            if (node->left)
            {
                pending_nodes.push(node->left);
            }

            if (node->right)
            {
                pending_nodes.push(node->right);
            }
        }

    }

    return root;
}