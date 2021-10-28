#include "header.h"

int maxProfit_r(vector<int>& prices)
{
    int day_to_buy = 0;
    int day_to_sell = 1;
    int max_profit = 0;

    while (day_to_sell < prices.size())
    {
        if (prices[day_to_sell] > prices[day_to_buy])
        {
            max_profit += (prices[day_to_sell] - prices[day_to_buy]);
        }
        day_to_buy = day_to_sell;
        day_to_sell = day_to_buy + 1;
    }

    return max_profit;
}