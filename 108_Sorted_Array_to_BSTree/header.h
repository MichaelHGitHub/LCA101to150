#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VI_T>& testData);

TreeNode* sortedArrayToBST(vector<int>& nums);
TreeNode* sortedArrayToBST2(vector<int>& nums);

TreeNode* sortedArrayToBST_r(vector<int>& nums);