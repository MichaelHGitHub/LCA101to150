
#include <map>
#include "header.h"

int singleNumber(vector<int>& nums)
{
    map<int, int> history;

    for (int i = 0; i < nums.size(); i++)
    {
        if (history.find(nums[i]) != history.end())
        {
            history[nums[i]] = history[nums[i]] + 1;
        }
        else
        {
            history[nums[i]] = 1;
        }
    }

    for (map<int, int>::iterator it = history.begin(); it != history.end(); it++)
    {
        if (it->second == 1)
        {
            return it->first;
        }
    }

    return -1;
}