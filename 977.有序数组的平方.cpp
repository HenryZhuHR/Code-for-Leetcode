/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (67.98%)
 * Likes:    819
 * Dislikes: 0
 * Total Accepted:    543.2K
 * Total Submissions: 799.1K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 10^4
 * -10^4
 * nums 已按 非递减顺序 排序
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
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
    vector<int> sortedSquares(vector<int>& nums)
    {
        // 左右双指针，向中间逼近
        // 新建立一个数组
        int         len = nums.size();
        vector<int> new_nums(len);
        int         pl = 0, pr = len - 1;
        int         index = pr;

        int lval = nums[pl] * nums[pl];
        int rval = nums[pr] * nums[pr];

        while (pl < pr) // = 会报错，在长度为1 的时候
        {
            if (lval >= rval)
            {
                new_nums[index] = lval;
                pl++;
                lval = nums[pl] * nums[pl];
            }
            else
            {
                new_nums[index] = rval;
                pr--;
                rval = nums[pr] * nums[pr];
            }
            index--;
        }
        new_nums[index] = lval;
        return new_nums;
    }
};
// @lc code=end
