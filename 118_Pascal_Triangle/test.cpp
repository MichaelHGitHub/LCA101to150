#include "header.h"

void PrepareTestData(vector<TD_I_VVI>& testData)
{
    TD_I_VVI data;

    data.input = 5;
    data.output = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    testData.push_back(data);

    data.input = 1;
    data.output = {{1}};
    testData.push_back(data);
}