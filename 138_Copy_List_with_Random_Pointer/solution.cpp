#include <map>
#include "header.h"

Node* copyRandomList(Node* head)
{
    map<Node*, Node*> nodes_map;

    Node* node = head;
    while (node)
    {
        nodes_map[node] = new Node(node->val);
        node = node->next;
    }
    nodes_map[nullptr] = nullptr;

    node = head;
    while (node)
    {
        nodes_map[node]->next = nodes_map[node->next];
        nodes_map[node]->random = nodes_map[node->random];
        node = node->next;
    }

    return nodes_map[head];
}