#include "header.h"

void PrepareTestData(vector<TD_S_VVS>& testData)
{
    TD_S_VVS data;

    data.input = "abbab";
    data.output = {{"a", "b", "b", "a", "b"}, {"a", "b", "bab"}, {"a", "bb", "a", "b"}, {"abba", "b"}};
    testData.push_back(data);


    data.input = "cbbbcc";
    data.output = {{"c", "b", "b", "b", "c", "c"}, {"c", "b", "b", "b", "cc"}, {"c", "b", "bb", "c", "c"}, {"c", "b", "bb", "cc"}, {"c", "bb", "b", "c", "c"}, {"c", "bb", "b", "cc"}, {"c", "bbb", "c", "c"}, {"c", "bbb", "cc"}, {"cbbbc", "c"}};
    testData.push_back(data);

    data.input = "efe";
    data.output = { {"e", "f", "e"},{"efe"} };
    testData.push_back(data);

    data.input = "cdd";
    data.output = { {"c", "d", "d"},{"c", "dd"} };
    testData.push_back(data);

    data.input = "aab";
    data.output = {{"a", "a", "b"}, {"aa", "b"}};
    testData.push_back(data);

    data.input = "a";
    data.output = {{"a"}};
    testData.push_back(data);

}