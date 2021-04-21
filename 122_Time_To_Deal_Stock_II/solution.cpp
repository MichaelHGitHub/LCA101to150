#include "header.h"

// Key point:
// Assuming we bought some stock for price p1, then we see a higher price
// p2, should we sell it or wait until we see a even higher price p4?
// The bottom line is: if you sell it for p2 and buy it again for the 
// same price p2 and later sell it for p4. you wouldn't lose any money
// either way. However, if there is a price p3 appears between p2 and p4, 
// then you will definitely make more money if you sell it for p2 and buy it at p3,
// and the sell it for p4. The match equation is like this:
// (p4 - p1) = (p2 - p1 + p4 - p2) < (p2 - p1 + p4 - p3) because that p3 < p2.
// So, the code implementation of the above equation is what we want. 
int maxProfit(vector<int>& prices)
{
    int max_profit = 0;
    int cur_min_price = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        // If the current price is less than previous price, sell it for the previous
        // price. and and buy it for the current price. 
        if (prices[i] < prices[i - 1])
        {
            max_profit += max(prices[i -1] - cur_min_price, 0);
            cur_min_price = prices[i];
        }
        else if (i == prices.size() - 1)
        {
            // We have to somehow sell the stock at the last price if there is any
            // profit.
            max_profit += max(prices[i] - cur_min_price, 0);
        }
    }

    return max_profit;
}