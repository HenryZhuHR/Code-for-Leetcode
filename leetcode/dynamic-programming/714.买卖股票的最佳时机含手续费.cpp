/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (75.32%)
 * Likes:    939
 * Dislikes: 0
 * Total Accepted:    223.7K
 * Total Submissions: 296.9K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
 *
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 *
 * 返回获得利润的最大值。
 *
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
 * 输出：8
 * 解释：能够达到的最大利润:
 * 在此处买入 prices[0] = 1
 * 在此处卖出 prices[3] = 8
 * 在此处买入 prices[4] = 4
 * 在此处卖出 prices[5] = 9
 * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
 *
 * 示例 2：
 *
 *
 * 输入：prices = [1,3,7,5,10,3], fee = 3
 * 输出：6
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= prices.length <= 5 * 10^4
 * 1 <= prices[i] < 5 * 10^4
 * 0 <= fee < 5 * 10^4
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int s0 = 0;          // [不持]
        int s1 = -prices[0]; // [持有] 不合法，设定一个不合法的值

        for (const auto& p : prices)
        {
            int s0_n = max(  // s0 [不持] 当前状态
                s0,          // 0 不操作 状态保持
                s1 + p - fee // 1 s1 卖出得到
            );
            int s1_n = max(  // s1 [持有] 当前状态
                s1,          // 0 不操作 状态保持
                s0 - p       // 1 s0 [不持] 买入 转移来
            );

            s0 = s0_n;
            s1 = s1_n;
        }
        return s0;
    }
};
// @lc code=end
