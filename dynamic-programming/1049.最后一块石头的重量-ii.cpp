/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 *
 * https://leetcode.cn/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (69.31%)
 * Likes:    718
 * Dislikes: 0
 * Total Accepted:    133.2K
 * Total Submissions: 192.2K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
 *
 * 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
 *
 *
 * 如果 x == y，那么两块石头都会被完全粉碎；
 * 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 *
 *
 * 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：stones = [2,7,4,1,8,1]
 * 输出：1
 * 解释：
 * 组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
 * 组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
 * 组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
 * 组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 *
 *
 * 示例 2：
 *
 *
 * 输入：stones = [31,26,33,21,40]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
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
    // 分为尽可能重量相等的两堆
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for (auto& n : stones)
            sum += n;
        int half_sum = sum >> 1;


        std::vector<int> dp(half_sum + 1, 0);

        for (int i = 0; i < stones.size(); i++) // 遍历石头
        {
            auto stone = stones[i];
            for (int j = half_sum; j >= 0; j--) // 遍历背包
            {
                if (j < stone)
                    break;

                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }

        return ((sum - dp[half_sum]) // 剩下一半石头的重量和
                - dp[half_sum]       // 当前一半石头重量和
        );
    }
};
// @lc code=end
