#include "header.h"

void PrepareTestData(vector<TD_VS_I>& testData)
{
    TD_VS_I data;

    data.input = { "2","1","+","3","*" };
    data.output = 9;
    testData.push_back(data);

    data.input = { "4","13","5","/","+" };
    data.output = 6;
    testData.push_back(data);

    data.input = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    data.output = 22;
    testData.push_back(data);
}