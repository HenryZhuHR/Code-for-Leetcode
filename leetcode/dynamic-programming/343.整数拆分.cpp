/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (62.20%)
 * Likes:    1241
 * Dislikes: 0
 * Total Accepted:    271.9K
 * Total Submissions: 437.2K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 *
 * 返回 你可以获得的最大乘积 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 *
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= n <= 58
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
    int integerBreak(int n)
    {
        int dp[n + 1]; // 下标和数字一一对应
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i / 2; j++)
            {

                dp[i] = max(dp[i],
                            max(j * (i - j),  // 拆分成两个数
                                j * dp[i - j] // 拆分后第二个数继续拆分成多个
                                ));
            }
        }


        return dp[n];
    }
};
// @lc code=end
