#include "header.h"

void PrepareTestData(vector<TD_T_VI>& testData)
{
    TD_T_VI data;

    data.input = GenerateTree({ 1,NULL_NODE_VALUE,2,3 });
    data.output = { 1,2,3 };
    testData.push_back(data);

    data.input = GenerateTree({ });
    data.output = {};
    testData.push_back(data);

    data.input = GenerateTree({ 1 });
    data.output = { 1 };
    testData.push_back(data);
}