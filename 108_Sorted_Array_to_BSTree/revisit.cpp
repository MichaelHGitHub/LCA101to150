#include "header.h"

TreeNode* helper(vector<int>& nums, int begin, int end);

TreeNode* sortedArrayToBST_r(vector<int>& nums)
{
    return helper(nums, 0, nums.size() - 1);
}


TreeNode* helper(vector<int>& nums, int begin, int end)
{
    if (begin > end)
    {
        return nullptr;
    }

    int mid = (begin + end) / 2;

    TreeNode* node = new TreeNode(nums[mid], nullptr, nullptr);

    node->left = helper(nums, begin, mid - 1);
    node->right = helper(nums, mid + 1, end);

    return node;
}