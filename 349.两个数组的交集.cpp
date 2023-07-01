/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.26%)
 * Likes:    783
 * Dislikes: 0
 * Total Accepted:    450.9K
 * Total Submissions: 607.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> num_map;
        vector<int>             result;

        for (auto n : nums1)
        {
            num_map[n] += 1;
        }
        for (auto n : nums2)
        {
            if (num_map.find(n) != num_map.end() && num_map[n] != 0)
            {
                result.push_back(n);
                num_map[n] = 0;
            }
        }
        return result;
        
    }
};
// @lc code=end
