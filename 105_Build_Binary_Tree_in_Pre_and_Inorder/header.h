#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VI_VI_T>& testData);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder);

TreeNode* buildTree3(vector<int>& preorder, vector<int>& inorder);