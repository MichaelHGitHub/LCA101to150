#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 2,2,3,2 };
    data.output = 3;
    testData.push_back(data);

    data.input = { 0,1,0,1,0,1,99 };
    data.output = 99;
    testData.push_back(data);

}