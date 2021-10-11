#include "header.h"
#include <stack>

TreeNode* buildTree_r2(vector<int>& inorder, vector<int>& postorder)
{
    std::stack<TreeNode*> pending;
    TreeNode* root = new TreeNode(postorder[postorder.size() - 1], nullptr, nullptr);
    pending.push(root);
    int posInInorder = inorder.size() - 1;
    TreeNode* wait_for_left = nullptr;

    for (int i = postorder.size() - 2; i >= 0; i--)
    {
        TreeNode* curNode = new TreeNode(postorder[i], nullptr, nullptr);

        while (!pending.empty() && pending.top()->val == inorder[posInInorder])
        {
            wait_for_left = pending.top();
            --posInInorder;
            pending.pop();
        }

        if (wait_for_left)
        {
            wait_for_left->left = curNode;
            wait_for_left = nullptr;
        }
        else
        {
            pending.top()->right = curNode;
        }

        pending.push(curNode);
    }

    return root;
}