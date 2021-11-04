#include "header.h"

int singleNumber_r(vector<int>& nums)
{
    int result = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }

    return result;
}