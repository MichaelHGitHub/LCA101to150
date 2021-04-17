#include <queue>
#include "header.h"

void PrepareTestData(vector<TD_N_VI>& testData)
{
    TD_N_VI data;

    data.input = GenerateTreeLinkedList({ 1,2,3,4,5,6,7 });
    data.output = { 1,NULL_NODE_VALUE,2,3,NULL_NODE_VALUE,4,5,6,7,NULL_NODE_VALUE };
    testData.push_back(data);

}

bool CheckResult(vector<int> v, Node* root)
{
    if (v.size() == 0 && root == nullptr)
    {
        return true;
    }

    if (root == nullptr)
    {
        return false;
    }

    queue<Node*> nodes;
    nodes.push(root);

    int count = 0;
    while (!nodes.empty())
    {
        int width_of_level = nodes.size();

        Node* cur = nodes.front();
        Node* next = cur;

        for (int i = 0; i < width_of_level; i++)
        {
            if (next->val != v[count++])
            {
                return false;
            }

            next = next->next;

            cur = nodes.front();
            nodes.pop();

            if (cur->left)
            {
                nodes.push(cur->left);
            }

            if (cur->right)
            {
                nodes.push(cur->right);
            }
        }

        if (next != nullptr || v[count++] != NULL_NODE_VALUE)
        {
            return false;
        }
    }

    return true;
}

void PrintData(Node* root)
{
    if (root == nullptr)
    {
        cout<< "#";
    }

    queue<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        int width_of_level = nodes.size();

        Node* cur = nodes.front();
        Node* next = cur;

        for (int i = 0; i < width_of_level; i++)
        {
            cout << next->val << " ,";
            next = next->next;

            cur = nodes.front();
            nodes.pop();

            if (cur->left)
            {
                nodes.push(cur->left);
            }

            if (cur->right)
            {
                nodes.push(cur->right);
            }
        }

        if (next == nullptr)
        {
            cout << "#";
        }

        if (!nodes.empty())
        {
            cout << " ,";
        }
    }
}

void PrintInput(TD_N_VI data)
{
    std::cout << "Input :";
    PrintTree(reinterpret_cast<TreeNode*>(data.input));
    std::cout << endl;
}

void CheckResults(TD_N_VI testData, Node* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (CheckResult(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


Node* GenerateTreeLinkedList(vector<int> v)
{
    if (v.size() == 0)
    {
        return nullptr;
    }
    queue<Node*> nodes;
    Node* root = new Node(v[0]);
    nodes.push(root);


    int count = 1;
    while (!nodes.empty())
    {
        Node* cur = nodes.front();
        nodes.pop();

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            Node* node = new Node(v[count]);
            cur->left = node;
            nodes.push(node);
        }
        else
        {
            cur->left = nullptr;
        }
        ++count;

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            Node* node = new Node(v[count]);
            cur->right = node;
            nodes.push(node);
        }
        else
        {
            cur->right = nullptr;
        }
        ++count;
    }

    return root;
}