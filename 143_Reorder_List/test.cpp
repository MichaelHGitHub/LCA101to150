#include "header.h"

#include "header.h"

void PrepareTestData(vector<TD_L_L>& testData)
{
    TD_L_L data;

    data.input = GenerateLinkedList({ 1,2,3,4 });
    data.output = GenerateLinkedList({ 1,4,2,3 });;
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,3,4,5 });;
    data.output = GenerateLinkedList({ 1,5,2,4,3 });;
    testData.push_back(data);
}