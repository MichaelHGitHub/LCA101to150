#include "header.h"

void PrepareTestData(vector<TD_VVC_VVC>& testData)
{
    TD_VVC_VVC data;

    data.input = { {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'} };
    data.output = { {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'} };
    testData.push_back(data);

    data.input = { {'X'} };
    data.output = { {'X'} };
    testData.push_back(data);

    data.input = { {'O', 'X', 'O', 'O', 'O', 'X'}, {'O', 'O', 'X', 'X', 'X', 'O'}, {'X', 'X', 'X', 'X', 'X', 'O'}, {'O', 'O', 'O', 'O', 'X', 'X'}, {'X', 'X', 'O', 'O', 'X', 'O'}, {'O', 'O', 'X', 'X', 'X', 'X'} };
    data.output = { {'O', 'X', 'O', 'O', 'O', 'X'}, {'O', 'O', 'X', 'X', 'X', 'O'}, {'X', 'X', 'X', 'X', 'X', 'O'}, {'O', 'O', 'O', 'O', 'X', 'X'}, {'X', 'X', 'O', 'O', 'X', 'O'}, {'O', 'O', 'X', 'X', 'X', 'X'} };
    testData.push_back(data);

    data.input = { {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'} };
    data.output = {
        { 'X', 'O', 'X', 'O', 'X', 'O' },
        { 'O', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'X', 'X', 'O' },
        { 'O', 'X', 'O', 'X', 'O', 'X' }};

    testData.push_back(data);

}