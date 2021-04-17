#pragma once

#include "../common/common.h"

struct TD_N_VI
{
    Node* input;
    vector<int> output;
};

Node* GenerateTreeLinkedList(vector<int> values);
void PrepareTestData(vector<TD_N_VI>& testData);
void PrintInput(TD_N_VI data);
void CheckResults(TD_N_VI data, Node* node);
bool CheckResult(vector<int> output, Node* result);

Node* connect(Node* root);
Node* connect2(Node* root);
Node* connect3(Node* root);