#include "header.h"

vector<int> getRow_r2(int rowIndex)
{
    vector<int> result(rowIndex + 1 , 1);

    // Node need to do row 0, 1;
    for (int i = 2; i <= rowIndex; i++)
    {
        // Fill in from the back so that the needed value
        // won't get overwritten
        // no need to col first and last
        for (int j = i - 1; j > 0; j--)
        {
            result[j] = result[j - 1] + result[j];
        }
    }

    return result;
}