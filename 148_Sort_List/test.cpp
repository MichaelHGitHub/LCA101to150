#include "header.h"

void PrepareTestData(vector<TD_L_L>& testData)
{
    TD_L_L data;

    data.input = GenerateLinkedList({ 2,1,3 });
    data.output = GenerateLinkedList({ 1,2,3 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 4,2,1,3 });
    data.output = GenerateLinkedList({ 1,2,3,4 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ -1,5,3,4,0 });
    data.output = GenerateLinkedList({ -1,0,3,4,5 });
    testData.push_back(data);
}