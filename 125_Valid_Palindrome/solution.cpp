#include "header.h"

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (j > i)
    {
        if (!((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z')))
        {
            ++i;
            continue;
        }

        if (!((s[j] >= '0' && s[j] <= '9') ||
            (s[j] >= 'A' && s[j] <= 'Z') ||
            (s[j] >= 'a' && s[j] <= 'z')))
        {
            --j;
            continue;
        }

        // The requirement doesn't say we can't use toupper or tolower
        if (std::tolower(s[i]) != std::tolower(s[j]))
        {
            return false;
        }

        ++i;
        --j;
    }

    return true;

}

