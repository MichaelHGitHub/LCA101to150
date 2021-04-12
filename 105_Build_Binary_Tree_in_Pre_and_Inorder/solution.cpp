#include <map>
#include "header.h"

static TreeNode* buildTreeHelper(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2, map<int, int>& pre_map, map<int,int>& in_map);

// Try to divid the pre-order(actually not necessary, but anyway, it is my first thought)
// and in-order array into left and right sub-tree, and recursively build the nodes
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    map<int, int> preorder_map;
    map<int, int> inorder_map;

    for (int i = 0; i < inorder.size(); i++)
    {
        preorder_map[preorder[i]] = i;
    }

    for (int i = 0; i < inorder.size(); i++)
    {
        inorder_map[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() -1, preorder_map, inorder_map);
}

TreeNode* buildTreeHelper(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2, map<int, int>& pre_map, map<int, int>& in_map)
{
    if (start2 > end2 || start1 > end1)
    {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[start1]);

    if (start2 == end2)
    {
        return node;
    }

    int root_inorder_pos = in_map[preorder[start1]];

    int left_in_start = start2;
    int left_in_end = root_inorder_pos - 1;
    int right_in_start = root_inorder_pos + 1;
    int right_in_end = end2;

    int left_pre_start = 0;
    int left_pre_end = 0;
    int right_pre_start = 0;
    int right_pre_end = 0;

    if (root_inorder_pos == start2)
    {
        left_pre_start = -1;
        left_pre_end = -2;

        right_pre_start = start1 + 1;
        right_pre_end = end1;
    }
    else if (root_inorder_pos == end2)
    {
        left_pre_start = start1 + 1;
        left_pre_end = pre_map[inorder[left_in_end]];

        right_pre_start = -1;
        right_pre_end = -2;
    }
    else
    {
        left_pre_start = start1 + 1;

        // Here is the tricky part: 
        // The next node of the current node is on the right sub-tree of the current root,
        // but its previous node in preorder array might not be on left sub-tree, we need
        // to search backward to find the last node on the left sub-tree in pre-order array.
        // the previous node of current root in inorder is on the 
        left_pre_end = pre_map[inorder[root_inorder_pos + 1]] - 1;
        while (in_map[preorder[left_pre_end]] > root_inorder_pos)
        {
            --left_pre_end;
        }

        right_pre_start = left_pre_end + 1;
        right_pre_end = end1;
    }

    // Once all the ranges are determined, the rest of thing is simple.

    node->left = buildTreeHelper(preorder, left_pre_start, left_pre_end, inorder, left_in_start, left_in_end, pre_map, in_map);
    node->right = buildTreeHelper(preorder, right_pre_start, right_pre_end, inorder, right_in_start, right_in_end, pre_map, in_map);

    return node;
}