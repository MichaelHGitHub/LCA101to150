#include "header.h"

void PrepareTestData(vector<TD_S_B>& testData)
{
    TD_S_B data;

    data.input = "0P";
    data.output = false;
    testData.push_back(data);

    data.input = "A man, a plan, a canal: Panama";
    data.output = true;
    testData.push_back(data);

    data.input = "race a car";
    data.output = false;
    testData.push_back(data);
}