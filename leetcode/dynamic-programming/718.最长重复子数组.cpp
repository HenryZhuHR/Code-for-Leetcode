/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (56.90%)
 * Likes:    971
 * Dislikes: 0
 * Total Accepted:    200.7K
 * Total Submissions: 352.8K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
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
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        // 公共的 、长度最长的子数组的长度 。 需要连续出现
        // nums1 行方向 nums2 列方向，棋盘格 相交即重复
        vector<int> dp(nums2.size() + 1, 0);
        int         max_len = 0;


        for (int i = 1; i <= nums1.size(); i++)     // nums1[i-1]
        {
            int dp_j_1 = dp[0];                     // 记录状态，防止被覆盖
            for (int j = 1; j <= nums2.size(); j++) // nums2[i-1]
            {
                int cur_dp = dp[j];
                if (nums1[i - 1] == nums2[j - 1])
                {
                    if (dp_j_1 > 0)
                        dp[j] = dp_j_1 + 1;
                    else
                        dp[j] = 1;
                }
                else
                dp[j]=0;
                dp_j_1 = cur_dp;


                if (dp[j] > max_len)
                    max_len = dp[j];
            }

            // printf("[%d] %2d :", i, nums1[i - 1]);
            // for (int j = 1; j <= nums2.size(); j++)
            //     printf("%3d", dp[j]);
            // printf("\n");
        }
        return max_len;
    }
};
// @lc code=end