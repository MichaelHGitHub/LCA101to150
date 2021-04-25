#include <stack>
#include <map>

#include "header.h"

static void cloneNode(Node* node, Node* new_node, map<Node*, Node*>& new_visited);

Node* cloneGraph3(Node* node) {

    if (node == nullptr)
    {
        return nullptr;
    }

    Node* new_node = new Node(node->val);

    map<Node*, Node*> new_visited;
    new_visited[node] = new_node;

    cloneNode(node, new_node, new_visited);

    return new_node;
}

void cloneNode(Node* node, Node* new_node, map<Node*, Node*>& new_visited)
{
    for (int i = 0; i < node->neighbors.size(); i++)
    {
        if (new_visited.find(node->neighbors[i]) == new_visited.end())
        {
            Node* new_child = new Node(node->neighbors[i]->val);
            new_node->neighbors.push_back(new_child);

            new_visited[node->neighbors[i]] = new_child;

            cloneNode(node->neighbors[i], new_child, new_visited);
        }
        else
        {
            new_node->neighbors.push_back(new_visited[node->neighbors[i]]);
        }
    }
}