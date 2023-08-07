/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.59%)
 * Likes:    1701
 * Dislikes: 0
 * Total Accepted:    367.7K
 * Total Submissions: 756.8K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个非负整数数组 nums 和一个整数 target 。
 *
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 *
 *
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 *
 *
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
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
    int findTargetSumWays(vector<int>& nums, int target)
    {
        /**
         *
         *
         * 数组分为两部分
         * - 第一部分全部 - ，和记为 negitive
         * - 第二部分全部 + ，和记为 positive
         * 需要满足：
         * 1. positive + negitive = sum
         * 2. positive - negitive = target
         *
         * 两式相减: negitive = (sum - target)/2
         * 所以可以确定 negitive 的和，找出和为 negitive 的全部可能
         */

        int sum = 0;
        for (auto& n : nums)
        {
            sum += n;
        }

        // 必须是 非负 偶数
        if ((sum - target < 0) || (sum - target) & 1 == 1)
            return 0;
        int negitive = (sum - target) / 2;

        // 转换成 01 背包问题，每个物品只用一次
        int bag_size = negitive; // 背包大小

        /**
         * dp[j] 0<=j<=bag_size 表示 和 为 j 的方案数量，所以边界条件 dp[0]=1
         * 当没有任何元素可以选取时，元素和只能是 0 ，对应的方案数是 1
         */
        std::vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) // 遍历物品
        {
            // 因为用到 j - nums[i] 所以，保证前面的不能被覆盖
            for (int j = bag_size; j >= nums[i]; j--) // 遍历背包，终止条件：物品重量不能超过背包重量
            {
                /**
                 * 当 1≤i≤n时，对于数组 nums 中的第 i，遍历 0≤j≤neg，计算 dp[i][j]：
                 * 如果 j<num，则不能选 num，  此时有 dp[i][j]=dp[i-1][j]；
                 * 如果 j≥num，
                 *  - 不选  num 方案数是 dp[i-1][j]
                 *  - 选    num 方案数是 dp[i-1][j-num]，
                 * 此时有 dp[i][j] = dp[i-1][j] + dp[i-1][j-num]
                 *
                 * 装满背包有几种方法的递推公式
                 */
                dp[j] = dp[j] + dp[j - nums[i]];

                /**
                 * 表示 已经 有 nums[i] 时，有 dp[j - nums[i]] 种方法凑成 j
                 * 例如：dp[j]，j 为5，
                 * nums[i] = 1 , 有 dp[5-1] = dp[4] 种方法凑成 5
                 * nums[i] = 2 , 有 dp[5-2] = dp[3] 种方法凑成 5
                 * ...
                 * dp[j] 定义就是凑成和为 j 有多少种方案
                 * 初始为 dp[0] = 1 ，因为不取任何数，和就是 0 (唯一方案)
                 */
            }
        }
        return dp[bag_size];
    }
};
// @lc code=end
