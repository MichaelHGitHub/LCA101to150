#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 1, 2, 11, 4, 7 };
    data.output = 10;
    testData.push_back(data);

    data.input = { 3, 2, 6, 5, 0, 3 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 7,1,5,3,6,4 };
    data.output = 5;
    testData.push_back(data);

    data.input = { 7,6,4,3,1 };
    data.output = 0;
    testData.push_back(data);

}