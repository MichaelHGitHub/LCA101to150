#include "header.h"

void PrepareTestData(vector<TD_VVI_I>& testData)
{
    TD_VVI_I data;

    data.input = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    data.output = 11;
    testData.push_back(data);

    data.input = {{-10}};
    data.output = -10;
    testData.push_back(data);

}