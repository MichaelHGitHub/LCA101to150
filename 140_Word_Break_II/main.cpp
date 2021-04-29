#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_S_VS_VS> test_data;

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        vector<string> result = wordBreak(test_data[i].input, test_data[i].input2);

        CheckResults_Unorder(test_data[i], result);
    }

    return 0;
}
