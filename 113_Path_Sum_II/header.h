#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_I_VVI>& testData);

vector<vector<int>> pathSum(TreeNode* root, int targetSum);
vector<vector<int>> pathSum2(TreeNode* root, int targetSum);