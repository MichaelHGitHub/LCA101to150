#pragma once

#define  TREE_LINK_NODE

#include "../common/common.h"

void PrepareTestData(vector<TD_N_VI>& testData);

Node* connect(Node* root);
Node* connect2(Node* root);
Node* connect3(Node* root);

Node* connect_r(Node* root);