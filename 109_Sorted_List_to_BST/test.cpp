#include "header.h"

void PrepareTestData(vector<TD_L_T>& testData)
{
    TD_L_T data;

    data.input = GenerateLinkedList({ -10, -3, 0, 5, 9 });
    data.output = GenerateTree({ 0,-3,9,-10, NULL_NODE_VALUE,5 });
    testData.push_back(data);


    data.input = GenerateLinkedList({ });
    data.output = GenerateTree({});
    testData.push_back(data);

    data.input = GenerateLinkedList({ 0 });
    data.output = GenerateTree({0});
    testData.push_back(data);
    
    data.input = GenerateLinkedList({ 1,3 });
    data.output = GenerateTree({ 3,1 });
    testData.push_back(data);
}