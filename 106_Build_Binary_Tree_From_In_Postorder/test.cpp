#include "header.h"

void PrepareTestData(vector<TD_VI_VI_T>& testData)
{
    TD_VI_VI_T data;

    data.input = { 9,3,15,20,7 };
    data.input2 = { 9,15,7,20,3 };
    data.output = GenerateTree({ 3,9,20,NULL,NULL,15,7 });
    testData.push_back(data);

    data.input = { -1 };
    data.input2 = { -1 };
    data.output = GenerateTree({ -1 });
    testData.push_back(data);

}