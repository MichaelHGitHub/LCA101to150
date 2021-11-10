#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_VI>& testData);

vector<int> postorderTraversal(TreeNode* root);

vector<int> postorderTraversal_r(TreeNode* root);

//vector<int> inorderTraversal(TreeNode* root);
