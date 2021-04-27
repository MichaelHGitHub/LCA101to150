#include "header.h"


void PrepareTestData(vector<TD_VI_VI_I>& testData)
{
    TD_VI_VI_I data;

    data.input = { 1,2,3,4,5 };
    data.input2 = { 3,4,5,1,2 };
    data.output = 3;
    testData.push_back(data);

    data.input = { 2,3,4 };
    data.input2 = { 3,4,3 };
    data.output = -1;
    testData.push_back(data);

}