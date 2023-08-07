/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (65.31%)
 * Likes:    1012
 * Dislikes: 0
 * Total Accepted:    168.3K
 * Total Submissions: 257.7K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 *
 *
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 *
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1
 * ，大于 n 的值 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 <= m, n <= 100
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
typedef struct
{
    int zero = 0;
    int one  = 0;
} num01;

class Solution
{
  public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {

        /**
         * 01 背包 (背包大小 [m+1,n+1]) 最后取 dp[m][n]
         * dp[i][j] 放的是，背包容量为 i 个 0 / j 个 1 的最大子集
         */
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (const auto& str : strs)
        {
            int num_0 = 0;
            int num_1 = 0;
            for (const auto& c : str)
            {
                if (c == '0')
                    num_0++;
                else if (c == '1')
                    num_1++;
                else
                    throw std::invalid_argument("must 0 / 1");
            }

            for (int i = m; i >= num_0; i--)     // 遍历 0
            {
                for (int j = n; j >= num_1; j--) // 遍历 1
                {

                    dp[i][j] = max(                  // 选最大的
                        dp[i][j],                    // 不选当前的 ，选上一层
                        dp[i - num_0][j - num_1] + 1 // 选当前的， 去掉 0 1 数量，+ 1  当前数量
                    );
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
