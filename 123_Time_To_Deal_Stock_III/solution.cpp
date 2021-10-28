#include "header.h"

int maxProfit(vector<int>& prices)
{
    int buy_1 = prices[0];
    int profit_1 = 0;
    int buy_2 = prices[0];
    int profit_2 = 0;;

    for(int i = 1; i < prices.size(); i++)
    {
        buy_1 = min(buy_1, prices[i]);
        profit_1 = max(profit_1, prices[i] - buy_1);

        buy_2 = min(buy_2, prices[i] - profit_1);
        profit_2 = max(profit_2, prices[i] - buy_2);
    }

    return profit_2;
}