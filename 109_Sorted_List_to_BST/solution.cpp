#include "header.h"

static TreeNode* helper(ListNode* head, ListNode* tail);

// Two pointer:
// pointer1 points at the beginging of each phase
// pointer2 points at one node beyond the last node of each phase.
// the mid place is the root node of each sub-tree in inoder traversal array.
TreeNode* sortedListToBST(ListNode* head)
{
    return helper(head, nullptr);
}

TreeNode* helper(ListNode* head, ListNode* tail)
{
    if (head == tail)
    {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != tail)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast != tail)
        {
            fast = fast->next;
        }
    }

    TreeNode* node = new TreeNode(slow->val);
    node->left = helper(head, slow);
    node->right = helper(slow->next, tail);

    return node;
}