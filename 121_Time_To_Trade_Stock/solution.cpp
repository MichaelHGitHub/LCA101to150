#include "header.h"

// In one interation, we keep tracking the minimium price and max profit
int maxProfit(vector<int>& prices)
{
    int max_profit = 0;

    int min_price = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < min_price)
        {
            min_price = prices[i];
        }
        else
        {
            max_profit = max(prices[i] - min_price, max_profit);
        }
    }

    return max_profit;
}