#include "header.h"

void PrepareTestData(vector<TD_T_I>& testData)
{
    TD_T_I data;

    data.input = GenerateTree({ 3,9,20,NULL,NULL,15,7 });
    data.output = 3;
    testData.push_back(data);

    data.input = GenerateTree({ 1,NULL,2 });
    data.output = 2;
    testData.push_back(data);

    data.input = GenerateTree({});
    data.output = 0;
    testData.push_back(data);

    data.input = GenerateTree({0});
    data.output = 1;
    testData.push_back(data);
}