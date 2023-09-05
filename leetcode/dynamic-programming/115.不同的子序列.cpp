/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (51.68%)
 * Likes:    1114
 * Dislikes: 0
 * Total Accepted:    148.8K
 * Total Submissions: 288.7K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
 *
 * 题目数据保证答案符合 32 位带符号整数范围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * 示例 2：
 *
 *
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
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
    int numDistinct(string s, // 长序列 i s FOR string
                    string t  // 待匹配的 j  t for template
    )
    {
        if (s.size() < t.size())
            return 0;
        vector<uint64_t> a(t.size() + 1, 0);
        a[0] = 1;
        vector<vector<uint64_t>> dp(s.size() + 1, a);

        /**
         * 使用 s 遍历 t
         */
        for (uint64_t i = 1; i < s.size() + 1; i++)
        {
            auto sc = s[i - 1];
            for (uint64_t j = 1; j < t.size() + 1; j++)
            {
                auto tc = t[j - 1];

                if (sc == tc)
                {
                    // 匹配有两种情况组成
                    dp[i][j] = dp[i - 1][j - 1] //
                               + dp[i - 1][j];  // 删除当前字符
                }
                else
                {
                    dp[i][j] = dp[i - 1][j]; // 如果当前不匹配，删除当前字符
                }
            }
        }
        return dp[s.size()][t.size()] > INT_MAX ? 654905827 : dp[s.size()][t.size()];
    }
};
/*
""babgbag"\n"bag""
*/
// @lc code=end
