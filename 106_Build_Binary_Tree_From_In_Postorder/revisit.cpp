#include "header.h"
#include <unordered_map>

TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& curInPost, int begin, int end);

std::unordered_map<int, int> inorderPos;

TreeNode* buildTree_r(vector<int>& inorder, vector<int>& postorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderPos[inorder[i]] = i;
    }
    int curInPost = postorder.size() - 1;
    return helper(inorder, postorder, curInPost, 0, inorder.size() -1);
}

TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& curInPost, int begin, int end)
{
    if (curInPost < 0 || begin > end)
    {
        return nullptr;
    }

    int pos = inorderPos[postorder[curInPost]];
    TreeNode* node = new TreeNode(postorder[curInPost], nullptr, nullptr);
    --curInPost;

    // Build right sub stree first
    node->right = helper(inorder, postorder, curInPost, pos + 1, end);
    node->left = helper(inorder, postorder, curInPost, begin, pos - 1);

    return node;
}