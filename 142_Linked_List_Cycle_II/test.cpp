#include "header.h"

void PrepareTestData(vector<TD_CL_L>& testData)
{
    TD_CL_L data;

    data.input = GenerateLoopLinkedList({ 3,2,0,-4 }, 1);
    data.loop_index = 1;
    data.output = GenerateLinkedList({ 2 });
    testData.push_back(data);

    data.input = GenerateLoopLinkedList({ 1 }, -1);;
    data.loop_index = -1;
    data.output = GenerateLinkedList({ });;
    testData.push_back(data);

    data.input = GenerateLoopLinkedList({ 1,2 }, 0);;
    data.loop_index = 0;
    data.output = GenerateLinkedList({ 1 });;
    testData.push_back(data);


}