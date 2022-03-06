/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (prices.size() == 1)
            return 0;
        int max_profit = 0;
        int min_price  = prices[0];
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < min_price)
                min_price = prices[i];
            if ((prices[i + 1] - min_price) >= max_profit)
                max_profit = prices[i + 1] - min_price;
        }
        return max_profit;
    }
};
// @lc code=end
