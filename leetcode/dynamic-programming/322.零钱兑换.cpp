/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.51%)
 * Likes:    2503
 * Dislikes: 0
 * Total Accepted:    657.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
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
    int coinChange(vector<int>& coins, int amount)
    {
        /**
         * 最少的硬币个数 (min)
         * 你可以认为每种硬币的数量是无限的 (完全背包)
         * 1 <= coins[i] <= 2^31 - 1 (有溢出的数据)
         */
        /**
         * dp[j] 表示 和 为 j 的方案数量
         */
        std::vector<int> dp(amount + 1,
                            INT_MAX // 取最小，那么初始化为最大
        );

        dp[0] = 0;                                   // 不取硬币，和为0

        for (int i = 0; i < coins.size(); i++)       // 硬币
        {
            for (int j = coins[i]; j <= amount; j++) // 背包
            {
                if (dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j],               // 0 不取
                                dp[j - coins[i]] + 1 // 1 选取
                    );
                    /**
                     * dp[j - coins[i]] + 1 的解释
                     * 当前有硬币是 coins[i] ，那么凑成 j 为 dp[j - coins[i]]，然后选取的话加上 1
                     * 例如 j=5
                     * coins[i] = 1 , 凑成 5 需要 dp[5-1] = dp[4] ，然后选取了 +1
                     * coins[i] = 2 , 凑成 5 需要 dp[5-2] = dp[3] ，然后选取了 +1
                     */
                }
            }
        }
        if (dp[amount] != INT_MAX)// 表示没有被更新过
            return dp[amount];
        else
            return -1;
    }
};
// @lc code=end
