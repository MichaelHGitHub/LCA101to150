#include "header.h"

void PrepareTestData(vector<TD_VI_VI_T>& testData)
{
    TD_VI_VI_T data;

    data.input = { 3, 2, 1, 4 };
    data.input2 = { 1, 2, 3, 4 };
    data.output = GenerateTree({ 3,2,4,1 });
    testData.push_back(data);

    data.input = { 7, -10, -4, 3, -1, 2, -8, 11 };
    data.input2 = { -4, -10, 3, -1, 7, 11, -8, 2 };
    data.output = GenerateTree({ 7,-10,2,-4,3,-8,NULL_NODE_VALUE,NULL_NODE_VALUE,NULL_NODE_VALUE,NULL_NODE_VALUE,-1,11 });
    testData.push_back(data);



    data.input = { 1, 2, 3 };
    data.input2 = { 2, 3, 1 };
    data.output = GenerateTree({ 1,2,NULL_NODE_VALUE, NULL_NODE_VALUE, 3 });
    testData.push_back(data);

    data.input = { 1, 2, 3 };
    data.input2 = { 3, 2, 1 };
    data.output = GenerateTree({ 1,2,NULL_NODE_VALUE,3 });
    testData.push_back(data);

    data.input = { 1, 2 };
    data.input2 = { 1, 2 };
    data.output = GenerateTree({ 1, NULL_NODE_VALUE, 2 });
    testData.push_back(data);

    data.input = { 3,9,20,15,7 };
    data.input2 = { 9,3,15,20,7 };
    data.output = GenerateTree({ 3,9,20,NULL_NODE_VALUE,NULL_NODE_VALUE,15,7 });
    testData.push_back(data);

    data.input = {-1};
    data.input2 = {-1};
    data.output = GenerateTree({-1});
    testData.push_back(data);

}