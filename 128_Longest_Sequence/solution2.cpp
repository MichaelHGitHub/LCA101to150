#include "header.h"
#include <unordered_map>

int lenUpToMe(unordered_map<int, int>& record, vector<int>& nums, int value);

int longestConsecutive2(vector<int>& nums)
{
    std::unordered_map<int, int> record;

    for (int i = 0; i < nums.size(); i++)
    {
        record[nums[i]] = 1;
    }

    int max_len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        max_len = max(max_len, lenUpToMe(record, nums, nums[i]));
    }

    return max_len;
}

int lenUpToMe(unordered_map<int, int>& record, vector<int>& nums, int value)
{
    if (record[value] != 1)
    {
        return record[value];
    }

    record[value] = 1 + lenUpToMe(record, nums, value - 1);

    return record[value];
}