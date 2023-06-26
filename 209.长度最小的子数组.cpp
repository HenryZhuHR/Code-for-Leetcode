/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (46.76%)
 * Likes:    1737
 * Dislikes: 0
 * Total Accepted:    557.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
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
 * 1
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
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
    int minSubArrayLen(int target, vector<int>& nums)
    {
        // 滑动窗口
        int pl      = 0;
        int len     = INT32_MAX;
        int sum     = 0;
        int sub_len = 0;

        for (int pr = 0; pr < nums.size(); pr++)
        {
            sum += nums[pr];
            // 尝试收缩窗口 ，收缩的条件是 sum >= target
            while (sum >= target)
            {
                // if (sum >= target)
                {
                    sub_len = pr - pl + 1;
                    if (sub_len < len)
                    {
                        len = sub_len;
                    }
                }
                sum -= nums[pl];
                pl++;
            }
        }

        return len == INT32_MAX ? 0 : len;
    }
};
// @lc code=end
