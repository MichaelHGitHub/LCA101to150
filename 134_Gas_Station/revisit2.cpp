#include "header.h"

int canCompleteCircuit_r2(vector<int>& gas, vector<int>& cost)
{
    int balance_pre = 0;
    int balance_cur = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance_cur += gas[i];
        balance_cur -= cost[i];

        if (balance_cur < 0)
        {
            balance_pre += balance_cur;
            balance_cur = 0;
            start = i + 1;
        }
    }

    if (balance_cur >= -balance_pre)
    {
        return start;
    }

    return -1;
}