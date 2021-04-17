#include <queue>
#include "header.h"

// Iterative:
// Typical level traversal plus setting each node's next pointer.
Node* connect(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    queue<Node*> pending_nodes;
    pending_nodes.push(root);

    while (!pending_nodes.empty())
    {
        // So far, all the nodes in the queue are at the same level.
        int width_of_level = pending_nodes.size();

        Node* node = nullptr;
        for (int i = 0; i < width_of_level; i++)
        {
            if (node)
            {
                node->next = pending_nodes.front();
            }

            node = pending_nodes.front();
            pending_nodes.pop();

            if (node->left)
            {
                pending_nodes.push(node->left);
            }

            if (node->right)
            {
                pending_nodes.push(node->right);
            }
        }

        // Handle last node of the level
        node->next = nullptr;
    }

    return root;
}