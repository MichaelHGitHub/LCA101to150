
#include <map>
#include "header.h"

int singleNumber(vector<int>& nums)
{
    map<int, int> history;

    for (int i = 0; i < nums.size(); i++)
    {
        if (history.find(nums[i]) == history.end())
        {
            history[nums[i]] = i;
        }
        else
        {
            nums[history[nums[i]]] = INT32_MIN;
            nums[i] = INT32_MIN;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != INT32_MIN)
        {
            return nums[i];
        }
    }
}