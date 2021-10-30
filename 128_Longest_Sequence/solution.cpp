#include "header.h"
#include <unordered_map>
#include <unordered_set>

int longestConsecutive(vector<int>& nums)
{
    int max_length = 0;

    std::unordered_map<int, int> record;
    std::unordered_set<int> checked;

    for (int i = 0; i < nums.size(); i++)
    {
        record[nums[i]] = 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int len_from_me = 1;
        if (checked.find(nums[i]) == checked.end())
        {
            checked.insert(nums[i]);

            if (record[nums[i] + 1] > 1)
            {
                len_from_me += record[nums[i] + 1];
            }
            else
            {
                while (len_from_me)
                {
                    if (0 == record[nums[i] + len_from_me])
                    {
                        break;
                    }
                    checked.insert(nums[i] + len_from_me);
                    ++len_from_me;
                }
            }
            record[nums[i]] = len_from_me;
            max_length = max(max_length, len_from_me);
        }
    }

    return max_length;
}