#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_VVI>& testData);

vector<vector<int>> levelOrder(TreeNode* root);
vector<vector<int>> levelOrder2(TreeNode* root);

vector<vector<int>> levelOrder_r(TreeNode* root);

vector<vector<int>> levelOrder_r2(TreeNode* root);