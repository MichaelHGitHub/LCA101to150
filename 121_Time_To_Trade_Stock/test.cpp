#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 7,1,5,3,6,4 };
    data.output = 5;
    testData.push_back(data);

    data.input = { 7,6,4,3,1 };
    data.output = 0;
    testData.push_back(data);

}