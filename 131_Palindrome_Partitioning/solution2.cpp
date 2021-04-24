#include "header.h"

// An attempt that doens't work
vector<vector<string>> partition2(string s)
{
    vector<vector<string>> result;
    result.push_back(vector<string>(1, s.substr(0,1)));

    for (int i = 1; i < s.length(); i++)
    {
        vector<vector<string>> cur_result = result;

        for (int j = 0; j < result.size(); j++)
        {
            result[j].push_back(s.substr(i, 1));
        }

        // It's not enough to check up_to_now, there are strings in the midst
        // of the string. I could enumerate all, but there are lots of repeatation
        // I could add a set or 2-d array to remember the history, 
        // but it would be too much work, then there is no point to do this. 
        string up_to_now = s.substr(0, i + 1);
        if (up_to_now == string(up_to_now.rbegin(), up_to_now.rend()))
        {
            result.push_back(vector<string>(1, up_to_now));
        }

        for (int k = 0; k < cur_result.size(); k++)
        {
            vector<string> one_set = cur_result[k];

            string sub = one_set[one_set.size() - 1];

            sub += s.substr(i, 1);

            if (sub != up_to_now && sub == string(sub.rbegin(), sub.rend()))
            {
                vector<string> new_set;

                new_set.assign(one_set.begin(), one_set.end() - 1);

                new_set.push_back(sub);
                result.push_back(new_set);
            }
        }

    }

    return result;
}