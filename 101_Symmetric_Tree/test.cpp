#include "header.h"

void PrepareTestData(vector<TD_T_B>& testData)
{
    TD_T_B data;

    data.input = GenerateTree({ 1, 2, 2, 3, 4, 4, 3 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 1, 0 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,2,3,4,4,3 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 1, 2, 2, NULL_NODE_VALUE, 3, NULL_NODE_VALUE, 3 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 2, 3, 3, 4, 5, NULL_NODE_VALUE, 4 });
    data.output = false;
    testData.push_back(data);
}