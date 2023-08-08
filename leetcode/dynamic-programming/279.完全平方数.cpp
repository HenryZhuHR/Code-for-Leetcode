/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (66.24%)
 * Likes:    1766
 * Dislikes: 0
 * Total Accepted:    421.9K
 * Total Submissions: 636.8K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 *
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 *
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
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
    int numSquares(int n)
    {
        /**
         * 1 <= n <= 10^4 = 10000
         */
        if (n == 1)
            return 1;

        /**
         * 背包容量 dp[j] 表示 和 为 j 的(最小)数量
         * 组合数
         */
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;                     // 和 为 0 不取
        for (int i = 1; i <= 100; i++) // 遍历 1 ~ sqrt( 100 * 100 )
        {
            if (i * i > n)
                break;


            for (int j = i * i; j <= n; j++) // 遍历背包 1 ~ n
            {
                /**
                 * 凑成 j (=5)
                 * i=1, dp[5-1]=dp[4]
                 * i=2, dp[5-2]=dp[3]
                 * i=4, dp[5-4]=dp[1]
                 */
                dp[j] = min(dp[j],            // 0
                            dp[j - i * i] + 1 // 1
                );
            }
        }
        return dp[n];
    }
};
// @lc code=end
