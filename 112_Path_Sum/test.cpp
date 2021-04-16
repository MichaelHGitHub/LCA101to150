#include "header.h"

void PrepareTestData(vector<TD_T_I_B>& testData)
{
    TD_T_I_B data;

    data.input = GenerateTree({ 5,4,8,11,NULL_NODE_VALUE,13,4,7,2,NULL_NODE_VALUE,NULL_NODE_VALUE,NULL_NODE_VALUE,1 });
    data.input2 = 22;
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3 });
    data.input2 = 5;
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2 });
    data.input2 = 0;
    data.output = false;
    testData.push_back(data);
}