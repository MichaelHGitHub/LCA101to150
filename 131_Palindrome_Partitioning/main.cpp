#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_S_VVS> test_data;

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        vector<vector<string>> result = partition_r(test_data[i].input);

        CheckResults_Unoder(test_data[i], result);
    }

    return 0;
}
