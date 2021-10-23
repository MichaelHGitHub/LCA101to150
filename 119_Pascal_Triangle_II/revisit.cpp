#include "header.h"

vector<int> getRow_r(int rowIndex)
{
    vector<int> result(rowIndex + 1, 1);

    for (int i = 2; i <= rowIndex; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int offset = rowIndex - i + 1;
            result[offset - 1 + j] = result[offset + j - 1] + result[offset + j];
        }
    }

    return result;
}