#include "header.h"
#include <queue>
#include <unordered_set>
#include <unordered_map>

Node* cloneGraph_r(Node* node)
{
    Node* cp_of_node = nullptr;

    if (nullptr != node)
    {
        cp_of_node = new Node(node->val, vector<Node*>(node->neighbors.size()));

        std::queue<Node*> pending;
        pending.push(node);
        std::unordered_map<Node*, Node*> cp_of_nodes;
        cp_of_nodes[node] = cp_of_node;

        std::unordered_set<Node*> visited;

        while (!pending.empty())
        {
            Node* cur = pending.front();
            pending.pop();

            Node* cp_of_cur = cp_of_nodes[cur];

            for (int i = 0; i < cur->neighbors.size(); i++)
            {
                Node* child = nullptr;
                if (cp_of_nodes.find(cur->neighbors[i]) == cp_of_nodes.end())
                {
                    child = new Node(cur->neighbors[i]->val, vector<Node*>(cur->neighbors[i]->neighbors.size()));
                    cp_of_nodes[cur->neighbors[i]] = child;
                }
                else
                {
                    child = cp_of_nodes[cur->neighbors[i]];
                }

                if (visited.find(cur->neighbors[i]) == visited.end())
                {
                    pending.push(cur->neighbors[i]);
                }

                cp_of_cur->neighbors[i] = child;

            }
            visited.insert(cur);
        }
    }

    return cp_of_node;
}