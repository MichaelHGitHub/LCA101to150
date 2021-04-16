#include "header.h"

void PrepareTestData(vector<TD_T_I>& testData)
{
    TD_T_I data;

    data.input = GenerateTree({ 3,9,20,NULL_NODE_VALUE,NULL_NODE_VALUE,15,7 });
    data.output = 2;
    testData.push_back(data);

    data.input = GenerateTree({ 2,NULL_NODE_VALUE,3,NULL_NODE_VALUE,4,NULL_NODE_VALUE,5,NULL_NODE_VALUE,6 });
    data.output = 5;
    testData.push_back(data);
}