#include "header.h"

void PrepareTestData(vector<TD_T_I>& testData)
{
    TD_T_I data;

    data.input = GenerateTree({ 4,9,0,NULL_NODE_VALUE,1 });
    data.output = 531;
    testData.push_back(data);

    data.input = GenerateTree({ 0,1 });
    data.output = 1;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3 });
    data.output = 25;
    testData.push_back(data);

    data.input = GenerateTree({ 4,9,0,5,1 });
    data.output = 1026;
    testData.push_back(data);

}