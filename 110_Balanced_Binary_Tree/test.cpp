#include "header.h"


void PrepareTestData(vector<TD_T_B>& testData)
{
    TD_T_B data;

    data.input = GenerateTree({ 3,9,20,NULL_NODE_VALUE,NULL_NODE_VALUE,15,7 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,2,3,3,NULL_NODE_VALUE,NULL_NODE_VALUE,4,4 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({});
    data.output = true;
    testData.push_back(data);
}