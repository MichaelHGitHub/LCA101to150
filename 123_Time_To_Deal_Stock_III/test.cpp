#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 };
    data.output = 13;
    testData.push_back(data);

    data.input = { 3,3,5,0,0,3,1,4 };
    data.output = 6;
    testData.push_back(data);

    data.input = { 1,2,3,4,5 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 7,6,4,3,1 };
    data.output = 0;
    testData.push_back(data);

    data.input = { 1 };
    data.output = 0;
    testData.push_back(data);
}