#include <map>
#include "header.h"

static TreeNode* helper(map<int, int>& inorder_map, vector<int>& inorder, int start, int end, vector<int>& postorder, int& root_index);

// Recursive:
// Create the nodes in reverse order of postorder array. For each node,
// find its countrer part in inoder array, then divid the inorder array 
// into two parts, left and right sub-trres of the current node, 
// recursively build all the nodes. 
// Note: have to create right sub-tree before left subtree because
// while reversely enumerating the postorder array, you meet the right
// child of a root before the right child of the same root.
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    map<int, int> inorder_map;

    for (int i = 0; i < inorder.size(); i++)
    {
        inorder_map[inorder[i]] = i;
    }

    int root_index = postorder.size() - 1;
    return helper(inorder_map, inorder, 0, inorder.size() - 1, postorder, root_index);
}


TreeNode* helper(map<int, int>& inorder_map, vector<int>& inorder, int start, int end, vector<int>& postorder, int& root_index)
{
    if (start > end || root_index < 0)
    {
        return nullptr;
    }

    TreeNode* node = new TreeNode(postorder[root_index--]);

    int root_in_pos = inorder_map[node->val];

    // Have to build right sub-tree first.
    node->right = helper(inorder_map, inorder, root_in_pos + 1, end, postorder, root_index);
    node->left = helper(inorder_map, inorder, start, root_in_pos - 1, postorder, root_index);

    return node;
}