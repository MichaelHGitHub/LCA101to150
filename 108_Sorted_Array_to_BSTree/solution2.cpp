#include <queue>
#include "header.h"

// Non-recursive:
// Create a node and save the node, its index, low-bound and up-bound of its sub tree
// in a queue, then get each saved node from the queue and build its left and right node
// according to the saved information.
TreeNode* sortedArrayToBST2(vector<int>& nums)
{
    struct NodeInfo
    {
        TreeNode* Node;
        int Index;
        int LowBound;
        int UpBound;

        NodeInfo(TreeNode* node, int index, int low_bound, int up_bound)
        {
            Node = node;
            Index = index;
            LowBound = low_bound;
            UpBound = up_bound;
        }
    };

    queue<NodeInfo*> nodes;
    int index = (nums.size() - 1) / 2;
    TreeNode* root = new TreeNode(nums[index]);
    nodes.push(new NodeInfo(root, index, 0, nums.size() - 1));

    while (!nodes.empty())
    {
        NodeInfo* node_info = nodes.front();
        nodes.pop();

        if (node_info->LowBound > node_info->Index - 1)
        {
            node_info->Node->left = nullptr;
        }
        else
        {
            int left_index = (node_info->LowBound + node_info->Index - 1) / 2;
            node_info->Node->left = new TreeNode(nums[left_index]);
            nodes.push(new NodeInfo(node_info->Node->left, left_index, node_info->LowBound, node_info->Index - 1));
        }

        if (node_info->Index + 1 > node_info->UpBound)
        {
            node_info->Node->right = nullptr;
        }
        else
        {
            int right_index = (node_info->Index + 1 + node_info->UpBound) / 2;
            node_info->Node->right = new TreeNode(nums[right_index]);
            nodes.push(new NodeInfo(node_info->Node->right, right_index, node_info->Index + 1, node_info->UpBound));
        }

        delete node_info;
    }

    return root;
}

