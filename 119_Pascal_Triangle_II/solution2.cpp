#include "header.h"

// DP
// We allocate the space for the rowIndex-th row, but we can store the result
// of every row in the same array. Just update them to the values of current row
// in each interation.
// When calculating the element of the current row, we start from the back,
// and leverage the values of the previous row which are currently stored in the array. 

vector<int> getRow2(int rowIndex)
{
    vector<int> row(rowIndex + 1);

    for (int i = 0; i <= rowIndex; i++)
    {
        for (int j = i; j >=0; j--)
        {
            // The first and last elements are 1
            if (j == 0 || j == i)
            {
                row[j] = 1;
            }
            else
            {
                row[j] = row[j] + row[j - 1];
            }
        }
    }

    return row;
}