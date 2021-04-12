#include "header.h"

void PrepareTestData(vector<TD_T_VVI>& testData)
{
    TD_T_VVI data;

    data.input = GenerateTree({ 3,9,20,NULL_NODE_VALUE,NULL_NODE_VALUE,15,7 });
    data.output = {{15, 7}, {9, 20}, {3}};
    testData.push_back(data);

    data.input = GenerateTree({ 1 });;
    data.output = { {1} };
    testData.push_back(data);

    data.input = GenerateTree({});
    data.output = {};
    testData.push_back(data);
}