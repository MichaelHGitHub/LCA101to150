#include "header.h"
#include <unordered_map>

Node* copyRandomList_r(Node* head)
{
    Node* new_head = nullptr;

    if (nullptr != head)
    {
        std::unordered_map<Node*, Node*> nodes;

        new_head = new Node(head->val);
        nodes[head] = new_head;

        Node* cur = head->next;
        Node* new_pre = new_head;
        Node* new_cur = nullptr;

        while (nullptr != cur)
        {
            new_cur = new Node(cur->val);
            nodes[cur] = new_cur;

            new_pre->next = new_cur;
            new_pre = new_pre->next;
            new_cur = nullptr;

            cur = cur->next;
        }

        cur = head;
        new_cur = new_head;
        while (nullptr != cur)
        {
            if (nullptr != cur->random)
            {
                new_cur->random = nodes[cur->random];
            }
            cur = cur->next;
            new_cur = new_cur->next;
        }
    }

    return new_head;

}