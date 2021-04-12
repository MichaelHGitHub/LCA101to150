#include "header.h"

void PrepareTestData(vector<TD_VI_T>& testData)
{
    TD_VI_T data;

    data.input = { -10,-3,0,5,9 };
    data.output = GenerateTree({ 0,-10,5,NULL_NODE_VALUE,-3,NULL_NODE_VALUE,9 });
    testData.push_back(data);

    data.input = { 1,3 };
    data.output = GenerateTree({ 1,NULL_NODE_VALUE, 3 });
    testData.push_back(data);
}