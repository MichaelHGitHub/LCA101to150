#include "header.h"

bool isPalindrome2(string s)
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

        if (s[i] != s[j])
        {
            char ci = s[i], cj = s[j];

            if (ci >= 'A' && ci <= 'Z')
            {
                ci += 'a' - 'A';
            }
            if (cj >= 'A' && cj <= 'Z')
            {
                cj += 'a' - 'A';
            }

            if (ci != cj)
            {
                return false;
            }
        }

        ++i;
        --j;
    }

    return true;

}