#include "header.h"

void PrepareTestData(vector<TD_G_G>& testData)
{
    TD_G_G data;

    data.input = GenerateGraph({{2, 3}, {1}, {1}});
    data.output = GenerateGraph({ {2, 3}, {1}, {1} });
    testData.push_back(data);

    data.input = GenerateGraph({{2, 4}, {1, 3}, {2, 4}, {1, 3}});
    data.output = GenerateGraph({ {2, 4}, {1, 3}, {2, 4}, {1, 3} });
    testData.push_back(data);

    data.input = GenerateGraph({{}});
    data.output = GenerateGraph({{}});
    testData.push_back(data);

    data.input = GenerateGraph({});
    data.output = GenerateGraph({});
    testData.push_back(data);

}