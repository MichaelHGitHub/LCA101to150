#include "header.h"

void PrepareTestData(vector<TD_S_VS_B>& testData)
{
    TD_S_VS_B data;

    data.input = "cars";
    data.input2 = { "car", "ca", "rs" };
    data.output = true;
    testData.push_back(data);

    data.input = "catsandog";
    data.input2 = { "cats","dog","sand","and","cat" };
    data.output = false;
    testData.push_back(data);

    data.input = "aaaaaaa";
    data.input2 = { "aaaa", "aaa" };
    data.output = true;
    testData.push_back(data);

    data.input = "leetcode";
    data.input2 = { "leet","code" };
    data.output = true;
    testData.push_back(data);

    data.input = "applepenapple";
    data.input2 = { "apple","pen" };
    data.output = true;
    testData.push_back(data);



    data.input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    data.input2 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
    data.output = false;
    testData.push_back(data);
}