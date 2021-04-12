#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_VI_VI_T> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        TreeNode* result = buildTree3(test_data[i].input, test_data[i].input2);

        CheckResults(test_data[i], result);
    }

    return 0;
}
