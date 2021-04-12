#include <stack>
#include "header.h"

// Create the nodes in preorder order. push the node to a stack and check if it meets its
// counterpart in inorder array, if yes, that means its left sub-tree is done, the next
// node in preorder array must be its right child. other wise the next node is the left 
// child of the top node in stack.
TreeNode* buildTree3(vector<int>& preorder, vector<int>& inorder)
{
    stack<TreeNode*> pending_nodes;

    int inorder_pos = 0;
    TreeNode* root = new TreeNode(preorder[0]);
    pending_nodes.push(root);
    TreeNode* pending_for_right = nullptr;

    for (int i = 1; i < preorder.size(); i++)
    {
        TreeNode* node = new TreeNode(preorder[i]);

        // Need to trace back to the last match node, the previous matches just mean their
        // right child is null.
        while (!pending_nodes.empty() && pending_nodes.top()->val == inorder[inorder_pos])
        {
            pending_for_right = pending_nodes.top();
            pending_nodes.pop();
            inorder_pos++;
        }

        // The current node must be the right child of the node that is waiting for it.
        if (pending_for_right != nullptr)
        {
            pending_for_right->right = node;
            pending_for_right = nullptr;
        }
        else
        {
            // Nobody is waiting for right child, the current node is the left child of 
            // the top node in the stack.
            pending_nodes.top()->left = node;
        }

        pending_nodes.push(node);
    }

    return root;
}

