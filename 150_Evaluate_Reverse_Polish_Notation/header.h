#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VS_I>& testData);

int evalRPN(vector<string>& tokens);

int evalRPN_r(vector<string>& tokens);