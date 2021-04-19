#include "header.h"

// DP
// We allocate the space for the rowIndex-th row, but we can store the result
// of every row in the same array. Just update them to the values of current row
// in each interation.
// When calculating the element of the current row, we leverage the values
// of the previous row which are currently stored in the array. Jus need to 
// preserve them before we've finished using them.
vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1);

    for (int i = 0; i <= rowIndex; i++)
    {
        int pre = 0, cur = 0;
        for (int j = 0; j <= i; j++)
        {
            // The first and last elements are 1
            if (j == 0 || j == i)
            {
                row[j] = 1;
                if (j == 0)
                {
                    pre = row[0];
                }
            }
            else
            {
                // save the value of previous row before we update it to the value of 
                // current row.
                cur = row[j];
                row[j] = pre + cur;
                pre = cur;
            }
        }
    }

    return row;
}