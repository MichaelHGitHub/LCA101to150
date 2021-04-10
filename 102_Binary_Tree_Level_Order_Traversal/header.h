#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_VVI>& testData);

vector<vector<int>> levelOrder(TreeNode* root);
vector<vector<int>> levelOrder2(TreeNode* root);