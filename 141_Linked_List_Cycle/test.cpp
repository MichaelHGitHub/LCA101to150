#include "header.h"

void PrepareTestData(vector<TD_CL_B>& testData)
{
    TD_CL_B data;

    data.input = GenerateLoopLinkedList({ 1,2 }, 0);
    data.loop_index = 0;
    data.output = true;
    testData.push_back(data);

    data.input = GenerateLoopLinkedList({ 3,2,0,-4 }, 1);
    data.loop_index = 1;
    data.output = true;
    testData.push_back(data);

    data.input = GenerateLoopLinkedList({ 1 }, -1);;
    data.loop_index = -1;
    data.output = false;
    testData.push_back(data);
}