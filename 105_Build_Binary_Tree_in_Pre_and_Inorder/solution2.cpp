#include <map>
#include "header.h"

static TreeNode* buildTreeHelper(vector<int>& preorder, int& pre_pos, vector<int>& inorder, int start, int end, map<int, int>& inorder_map);

// Create the nodes in the order of preorder traversal, find the same node in the inorder array
// then we will know the range of left and right sub-trees of the current node. then 
// recursively call the helper function to create next node and its left and right sub-trees.
TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder)
{
    // Use a map to save node value and its index of inorder traversal so that quickly find
    // each node's position in the inorder array.
    map<int, int> inorder_map;

    // Index of the current node(in preorder array)
    int pre_pos = 0;

    for (int i = 0; i < inorder.size(); i++)
    {
        inorder_map[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, pre_pos, inorder, 0, inorder.size() - 1, inorder_map);
}

static TreeNode* buildTreeHelper(vector<int>& preorder, int& pre_pos, vector<int>& inorder, int start, int end, map<int, int>& inorder_map)
{
    if (start > end || pre_pos >= preorder.size())
    {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[pre_pos++]);

    int root_in_pos = inorder_map[node->val];

    // Divid the inorder array into two parts, left and right sub-tree nodes of the current
    // nodes. and recursively build other nodes.
    node->left = buildTreeHelper(preorder, pre_pos, inorder, start, root_in_pos - 1, inorder_map);
    node->right = buildTreeHelper(preorder, pre_pos, inorder, root_in_pos + 1, end, inorder_map);

    return node;
}