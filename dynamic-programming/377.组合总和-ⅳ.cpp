/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode.cn/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (52.83%)
 * Likes:    845
 * Dislikes: 0
 * Total Accepted:    152.2K
 * Total Submissions: 288.1K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 *
 * 题目数据保证答案符合 32 位整数范围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [9], target = 3
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * nums 中的所有元素 互不相同
 * 1
 *
 *
 *
 *
 * 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
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
    int combinationSum4(vector<int>& nums, int target)
    {
        /**
         * dp[j] 表示 和为 j 的方案数
         */
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        /**
         * 遍历顺序
         * 如果求 「组合数」 就是 外层for 遍历 「物品」 ，内层for 遍历 「背包」
         * 如果求 「排列数」 就是 外层for 遍历 「背包」 ，内层for 遍历 「物品」
         */
        for (int j = 0; j <= target; j++)         // 「排列数」 「背包」
        {
            for (int i = 0; i < nums.size(); i++) // 「排列数」 「物品」
            {
                // 测试用例有 dp[j] + dp[j - nums[i]] 超过 int_max 的，所以需要减法判断是否溢出
                bool is_not_overflow_int_max = dp[j] < INT_MAX - dp[j - nums[i]];
                if (nums[i] <= j && is_not_overflow_int_max)
                {
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
            }
        }
        return dp[target];
        /**
         * 时间复杂度 O(target*nums.size())
         * 空间复杂度 O(target+1)
         */
    }
};
// @lc code=end
