#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_VVC_VVC> test_data;

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        solve_r(test_data[i].input);

        CheckResults(test_data[i], test_data[i].input);
    }

    return 0;
}
