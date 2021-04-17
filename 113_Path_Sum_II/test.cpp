#include "header.h"

void PrepareTestData(vector<TD_T_I_VVI>& testData)
{
    TD_T_I_VVI data;

    data.input = GenerateTree({ 5,4,8,11,NULL_NODE_VALUE,13,4,7,2,NULL_NODE_VALUE,NULL_NODE_VALUE,5,1 });
    data.input2 = 22;
    data.output = {{5, 4, 11, 2}, {5, 8, 4, 5}};
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3 });
    data.input2 = 5;
    data.output = { };
    testData.push_back(data);

    data.input = GenerateTree({ 1,2 });
    data.input2 = 0;
    data.output = { };
    testData.push_back(data);
}