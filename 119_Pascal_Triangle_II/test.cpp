#include "header.h"

void PrepareTestData(vector<TD_I_VI>& testData)
{
    TD_I_VI data;

    data.input = 3;
    data.output = { 1,3,3,1 };
    testData.push_back(data);

    data.input = 0;
    data.output = {1};
    testData.push_back(data);

    data.input = 1;
    data.output = { 1,1 };
    testData.push_back(data);

}