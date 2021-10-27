#include "header.h"

int maxProfit_r(vector<int>& prices)
{
    int profit = 0;

    int begin = 0;
    int end = 1;
    while (end < prices.size())
    {
        profit = max(profit, prices[end] - prices[begin]);

        if (prices[end] <= prices[begin])
        {
            begin = end;
        }
        ++end;
    }

    return profit;
}