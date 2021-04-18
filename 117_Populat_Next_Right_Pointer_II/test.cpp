#include "header.h"

void PrepareTestData(vector<TD_N_VI>& testData)
{
    TD_N_VI data;

    data.input = GenerateTreeLinkedList({ 2, 1, 3, 0, 7, 9, 1, 2, NULL_NODE_VALUE, 1, 0, NULL_NODE_VALUE, NULL_NODE_VALUE, 8, 8, NULL_NODE_VALUE, NULL_NODE_VALUE, NULL_NODE_VALUE, NULL_NODE_VALUE, 7 });
    data.output = {2,NULL_NODE_VALUE,1,3,NULL_NODE_VALUE,0,7,9,1,NULL_NODE_VALUE,2,1,0,8,8,NULL_NODE_VALUE,7,NULL_NODE_VALUE};
    testData.push_back(data);


    data.input = GenerateTreeLinkedList({ 1,2,3,4,5,NULL_NODE_VALUE,7 });
    data.output = { 1,NULL_NODE_VALUE,2,3,NULL_NODE_VALUE,4,5,7,NULL_NODE_VALUE };
    testData.push_back(data);
}
