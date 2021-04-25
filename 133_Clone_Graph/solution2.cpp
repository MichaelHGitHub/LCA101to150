#include <stack>
#include <unordered_set>
#include <map>

#include "header.h"

Node* cloneGraph2(Node* node) {

    if (node == nullptr)
    {
        return nullptr;
    }

    map<Node*, Node*> new_visited;
    stack<Node*> pending_vertices;

    Node* new_node = new Node(node->val);

    pending_vertices.push(node);
    new_visited[node] = new_node;

    while (!pending_vertices.empty())
    {
        Node* cur_node = pending_vertices.top();
        pending_vertices.pop();

        Node* new_cur_node = new_visited[cur_node];

        for (int i = 0; i < cur_node->neighbors.size(); i++)
        {
            if (new_visited.find(cur_node->neighbors[i]) == new_visited.end())
            {

                Node* new_child = new Node(cur_node->neighbors[i]->val);
                new_cur_node->neighbors.push_back(new_child);

                pending_vertices.push(cur_node->neighbors[i]);

                new_visited[cur_node->neighbors[i]] = new_child;

            }
            else
            {
                new_cur_node->neighbors.push_back(new_visited[cur_node->neighbors[i]]);
            }
        }
    }

    return new_node;
}