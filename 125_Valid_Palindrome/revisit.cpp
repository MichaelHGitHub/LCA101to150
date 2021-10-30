#include "header.h"

static char converChar(char c);

bool isPalindrome_r(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        char l = converChar(s[left]);
        char r = converChar(s[right]);

        if (l != ' ' && r != ' ')
        {
            if (l != r)
            {
                break;
            }
            ++left;
            --right;
        }
        else
        {
            if (l == ' ')
            {
                ++left;
            }

            if (r == ' ')
            {
                --right;
            }
        }
    }

    return left >= right;
}

char converChar(char c)
{
    int new_c = ' ';
    if ((c >= '0' && c <= '9') ||
        (c >= 'a' && c <= 'z'))
    {
        new_c = c;
    }
    else if ((c >= 'A' && c <= 'Z'))
    {
        new_c =  c + 'a' - 'A';
    }

    return new_c;
}