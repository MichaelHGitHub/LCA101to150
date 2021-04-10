#include "header.h"

void PrepareTestData(vector<TD_T_B>& testData)
{
    TD_T_B data;

    data.input = GenerateTree({ 1,2,2,3,4,4,3 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 1, 2, 2, NULL, 3, NULL, 3 });
    data.output = false;
    testData.push_back(data);

}