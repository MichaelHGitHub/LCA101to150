
#include <unordered_set>
#include "header.h"

int singleNumber2(vector<int>& nums)
{
    unordered_set<int> history;

    for (int i = 0; i < nums.size(); i++)
    {
        if (history.find(nums[i]) == history.end())
        {
            history.insert(nums[i]);
        }
        else
        {
            history.erase(nums[i]);
        }
    }

    return *(history.begin());

}