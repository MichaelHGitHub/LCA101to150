#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 2,2,1 };
    data.output = 1;
    testData.push_back(data);

    data.input = { 4,1,2,1,2 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 1 };
    data.output = 1;
    testData.push_back(data);
}