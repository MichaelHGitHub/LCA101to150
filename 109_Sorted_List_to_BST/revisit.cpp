#include "header.h"
#include <unordered_map>

TreeNode* helper(std::unordered_map<int, int>& nodes, int begin, int end);

TreeNode* sortedListToBST_r(ListNode* head)
{
    std::unordered_map<int, int> nodes;

    int i = 0;
    while(head)
    {
        nodes[i++] = head->val;
        head = head->next;
    }
    return helper(nodes, 0, i - 1);
}

TreeNode* helper(std::unordered_map<int, int>& nodes, int begin, int end)
{
    if (begin > end)
    {
        return nullptr;
    }

    int mid = (begin + end) / 2;
    TreeNode* node = new TreeNode(nodes[mid], nullptr, nullptr);

    node->left = helper(nodes, begin, mid - 1);
    node->right = helper(nodes, mid + 1, end);

    return node;
}