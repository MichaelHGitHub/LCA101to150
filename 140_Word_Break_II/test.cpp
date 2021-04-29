#include "header.h"

void PrepareTestData(vector<TD_S_VS_VS>& testData)
{
    TD_S_VS_VS data;

    data.input = "catsanddog";
    data.input2 = { "cat","cats","and","sand","dog" };
    data.output = { "cats and dog","cat sand dog" };
    testData.push_back(data);

    data.input = "pineapplepenapple";
    data.input2 = { "apple","pen","applepen","pine","pineapple" };
    data.output = { "pine apple pen apple","pineapple pen apple","pine applepen apple" };
    testData.push_back(data);

    data.input = "catsandog";
    data.input2 = { "cats","dog","sand","and","cat" };
    data.output = {};
    testData.push_back(data);

}