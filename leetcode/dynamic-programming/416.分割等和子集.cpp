/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.18%)
 * Likes:    1831
 * Dislikes: 0
 * Total Accepted:    434.7K
 * Total Submissions: 833.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
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
    bool canPartition(vector<int>& nums)
    {
        /**
         * 背包问题
         *
         * 1. 背包体积为 sum/2
         * 2. 重量 和 价值 等于原始数组的值
         * 3. 不可以重复放入 (01背包)
         *
         * 1 <= nums.length <= 200
         * 1 <= nums[i] <= 100
         */

        int sum = 0;
        for (auto& num : nums)
            sum += num;
        if ((sum & 1) ^ 0)
            return false;
        int target = sum >> 1;

        // 存放 n-1 最大和
        std::vector<int> dp(static_cast<int>(target + 1), 0);
        /**
         * [1,5,11,5] 4个物品，价值就是本身
         *
         * 0  1  2  3  4  5  6  7  8  9 10 11
         * 0  1  1  1  1  5  5  6  6  6 10 11
         */

        for (int i = 0; i < nums.size(); i++)
        {
            int cur_num = nums[i];
            for (int j = target; j >= cur_num; j--)
            {
                dp[j] = max(dp[j], dp[j - cur_num] + cur_num);
            }
        }
        if (dp[target] == target)
            return true;
        else
            return false;
    }
};

// @lc code=end
