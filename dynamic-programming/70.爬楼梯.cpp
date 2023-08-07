/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (54.06%)
 * Likes:    3160
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.2M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 *
 *
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 45
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
    int climbStairs(int n)
    {
        string solution = "DP_01bag";
        if (solution == "DP")
        {
            if (n <= 1)
                return n;

            int dp_0 = 1; // 爬到1层
            int dp_1 = 2; // 爬到2层
            for (int i = 3; i <= n; i++)
            {
                // 每次只能 1 / 2 ，所以只能倒数第2 /1 前进
                // 也就是说，取 n-2 n-1
                int dp_n = dp_0 + dp_1;
                dp_0     = dp_1;
                dp_1     = dp_n;
            }
            return dp_1;
        }
        else if (solution == "DP_01bag")
        {
            // 修改为 每次可以爬 最多 m 个台阶，之前的题目是固定 最多两个
            // 最后总和为 n

            int m = 2; // 可以选的数 的数组  1,2,3,...,m
            /**
             * dp[j] 表示 爬到 j 阶 的方法
             * 排列数，背包 外层for
             */
            vector<int> dp(n + 1, 0);
            dp[0] = 1;                       // 爬0层仅一种方法
            for (int j = 1; j <= n; j++)     // 排列数 外层 背包
            {
                for (int i = 1; i <= m; i++) // 排列数 内层 物品
                {
                    if (j - i >= 0)
                    {
                        dp[j] = dp[j]        // 0 不取
                                + dp[j - i]; // 1 选取}
                    }
                }
            }
            return dp[n];
        }
        else
            return INT_MIN;
    }
};
// @lc code=end
