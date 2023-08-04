/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (64.89%)
 * Likes:    1281
 * Dislikes: 0
 * Total Accepted:    330.9K
 * Total Submissions: 509.9K
 * Testcase Example:  '[10,15,20]'
 *
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
 *
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
 *
 * 请你计算并返回达到楼梯顶部的最低花费。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：cost = [10,15,20]
 * 输出：15
 * 解释：你将从下标为 1 的台阶开始。
 * - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
 * 总花费为 15 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 * 解释：你将从下标为 0 的台阶开始。
 * - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
 * 总花费为 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
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
    int minCostClimbingStairs(vector<int>& cost)
    {
        // n >= 2
        int n = cost.size();
        // 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
        // 所以起始不花费
        int dp0 = 0; // n-2 从 0 起步
        int dp1 = 0; // n-1 从 1 起步

        /**
         * idx    0  1  2
         * cost [10,15,20]
         * mcost  0  0 15
         * 到达 0 和 1 不花费
         *
         * 但长度为 3 的话
         * 到达 idx 1 或者 2 都可以
         * - 从 0 走，+10
         * - 从 1 走，+15
         */

        // 下标 + 1 因为默认要到达 cost[n]
        for (int i = 2; i <= n; i++)
        {
            int from_dp0_cost = dp0 + cost[i - 2]; // 前 2
            int from_dp1_cost = dp1 + cost[i - 1]; // 前 1
            int dpn           = from_dp0_cost < from_dp1_cost ? from_dp0_cost : from_dp1_cost;
            dp0               = dp1;
            dp1               = dpn;
        }
        return dp1;
    }
};
// @lc code=end
