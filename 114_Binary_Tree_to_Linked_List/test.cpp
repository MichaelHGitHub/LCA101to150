#include "header.h"

void PrepareTestData(vector<TD_T_T>& testData)
{
    TD_T_T data;

    data.input = GenerateTree({ 1,2,5,3,4,NULL_NODE_VALUE,6 });
    data.output = GenerateTree({ 1,NULL_NODE_VALUE,2,NULL_NODE_VALUE,3,NULL_NODE_VALUE,4,NULL_NODE_VALUE,5,NULL_NODE_VALUE,6 });
    testData.push_back(data);

    data.input = GenerateTree({});
    data.output = GenerateTree({});
    testData.push_back(data);

    data.input = GenerateTree({0});
    data.output = GenerateTree({0});
    testData.push_back(data);
}