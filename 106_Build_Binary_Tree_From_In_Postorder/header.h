#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VI_VI_T>& testData);

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder);