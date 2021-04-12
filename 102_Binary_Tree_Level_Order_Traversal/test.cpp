#include "header.h"

void PrepareTestData(vector<TD_T_VVI>& testData)
{
    TD_T_VVI data;

    data.input = GenerateTree({ 3,9,20,NULL_NODE_VALUE,NULL_NODE_VALUE,15,7 });
    data.output = {{3}, {9, 20}, {15, 7}};
    testData.push_back(data);

    data.input = GenerateTree({1});
    data.output = { {1} };
    testData.push_back(data);

    data.input = GenerateTree({});
    data.output = {};
    testData.push_back(data);
}