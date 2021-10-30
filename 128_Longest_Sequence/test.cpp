#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 100,4,200,1,3,2 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 0,3,7,2,5,8,4,6,0,1 };
    data.output = 9;
    testData.push_back(data);
}