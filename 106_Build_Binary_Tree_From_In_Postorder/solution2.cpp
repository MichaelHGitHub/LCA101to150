#include <stack>
#include "header.h"

// Non-recursive: 
// Create node in reverse order of the post-order array, also push 
// the node to a stack to wait for its left and right child. 
// If the top node of the array hasn't met its counter part in the 
// inorder array, that means the next(moving forward) node is its right
// child, if the top node matches its counter part in the inorder array,
// that means its right sub-tree is finished, waiting for left child.
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder)
{
    stack<TreeNode*> pending_nodes;
    TreeNode* waiting_for_left = nullptr;

    TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
    pending_nodes.push(root);

    int inorder_index = inorder.size() - 1;

    for (int i = postorder.size() - 2; i >= 0; i--)
    {
        TreeNode* node = new TreeNode(postorder[i]);

        // Need to sreach all the way to the last match, previous matches
        // just mean the left child of these nodes are nullptr. 
        while (!pending_nodes.empty() && inorder_index >= 0 && pending_nodes.top()->val == inorder[inorder_index])
        {
            waiting_for_left = pending_nodes.top();
            pending_nodes.pop();
            --inorder_index;
        }

        // If there is a node waiting for left child, the node is it.
        if (waiting_for_left != nullptr)
        {
            waiting_for_left->left = node;
            waiting_for_left = nullptr;
        }
        else
        {
            // Otherwise, node is the right child of the top node.
            pending_nodes.top()->right = node;
        }

        pending_nodes.push(node);
    }

    return root;
}