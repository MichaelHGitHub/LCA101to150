#include "header.h"

static TreeNode* helper(vector<int>& nums, int start, int end);

// Recursive solution
// A typical binary search algorithm
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return helper(nums, 0, nums.size() - 1);
}

TreeNode* helper(vector<int>& nums, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (end + start) / 2;
    
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = helper(nums, start, mid - 1);
    node->right = helper(nums, mid + 1, end);

    return node;
}