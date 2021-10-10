#include "header.h"
#include <unordered_map>

TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int& curPreIndex, int begin, int end);

std::unordered_map<int, int> inorder_pos;

TreeNode* buildTree_r(vector<int>& preorder, vector<int>& inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        inorder_pos[inorder[i]] = i;
    }

    int curPreIndex = 0;
    return buildSubTree(preorder, inorder, curPreIndex, 0, inorder.size() - 1);
}


TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int& curPreIndex, int begin, int end)
{
    if (curPreIndex >= preorder.size() || begin > end)
    {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[curPreIndex], nullptr, nullptr);
    int curInPos = inorder_pos[preorder[curPreIndex]];
    ++curPreIndex;
    node->left = buildSubTree(preorder, inorder, curPreIndex, begin, curInPos - 1);
    node->right = buildSubTree(preorder, inorder, curPreIndex, curInPos + 1, end);

    return node;
}