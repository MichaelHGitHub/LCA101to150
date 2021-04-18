#include <queue>
#include "header.h"

void PrepareTestData(vector<TD_N_VI>& testData)
{
    TD_N_VI data;

    data.input = GenerateTreeLinkedList({ 1,2,3,4,5,6,7 });
    data.output = { 1,NULL_NODE_VALUE,2,3,NULL_NODE_VALUE,4,5,6,7,NULL_NODE_VALUE };
    testData.push_back(data);
}
