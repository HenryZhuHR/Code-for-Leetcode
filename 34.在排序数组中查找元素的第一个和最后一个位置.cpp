/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.39%)
 * Likes:    2343
 * Dislikes: 0
 * Total Accepted:    805K
 * Total Submissions: 1.9M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
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
    const int invalid = -8;

  public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int index_l = findLeft(nums, target);
        int index_r = findRight(nums, target);
        cout << index_l << " " << index_r << endl;

        if (index_l == this->invalid || index_r == this->invalid) // 边界不存在，也就是target 不存在
        {
            return {-1, -1};
        }
        else if (index_l <= index_r)
        {
            return {index_l, index_r};
        }
        else
        {
            return {-1, -1};
        }
    }

  private:
    int findLeft(vector<int>& nums, int target)
    {
        int pl = 0, pr = nums.size() - 1;
        int findidx = this->invalid;
        while (pl <= pr)
        {
            int pm = (pl + pr) / 2;
            if (nums[pm] >= target)
            {
                pr      = pm - 1;
                findidx = pm;
            }
            else
            {
                pl = pm + 1;
            }
        }
        return findidx;
    }
    int findRight(vector<int>& nums, int target)
    {
        int pl = 0, pr = nums.size() - 1;
        int findidx = this->invalid;
        while (pl <= pr)
        {
            int pm = (pl + pr) / 2;
            if (nums[pm] <= target)
            {
                pl      = pm + 1;
                findidx = pm;
            }
            else
            {
                pr = pm - 1;
            }
        }
        return findidx;
    }
};
// @lc code=end
