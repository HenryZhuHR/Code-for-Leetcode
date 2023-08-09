/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (64.18%)
 * Likes:    1560
 * Dislikes: 0
 * Total Accepted:    267.6K
 * Total Submissions: 416.8K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 *
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *
 *
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 *
 *
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 *
 * 示例 2:
 *
 *
 * 输入: prices = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
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
    int maxProfit(vector<int>& prices)
    {
        // 1 <= prices.length <= 5000
        int s0 = 0;          // [不持 不冷冻]
        int s1 = -prices[0]; // [   持有   ] 不合法，设定一个不合法的值
        int s2 = 0;          // [不持 冷冻期]

        for (const auto& p : prices)
        {
            int s0_n = max( // s0 [不持 不冷冻] 当前状态
                s0,         // 0 不操作 状态保持
                s2          // 1 由冷冻期转移来
            );
            int s1_n = max( // s1 [   持有   ] 当前状态
                s1,         // 0 不操作 状态保持
                s0 - p      // 1 s0 [不持 不冷冻] 买入 转移来
            );
            int s2_n =      // s2 [不持 冷冻期] 当前状态
                s1 + p      // 只能由 s1 [   持有   ] 卖出转移来
                ;

            s0 = s0_n;
            s1 = s1_n;
            s2 = s2_n;
        }
        return max(s0, s2);
    }
};
// @lc code=end
