/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (66.83%)
 * Likes:    826
 * Dislikes: 0
 * Total Accepted:    203.6K
 * Total Submissions: 304.5K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
 * 下一个更大元素 。
 *
 * 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
 * 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数；
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1,2,3,4,3]
 * 输出: [2,3,4,-1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 循环单调栈 https://leetcode.cn/problems/next-greater-element-i/solutions/8877/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/

// @lc code=start
class Solution
{
  public:
    /**
     * 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
     * 下一个更大元素 。
     *
     * 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
     *
     *
     * 循环数组 ： 取模 % ； 数组长度双倍
     */
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int         size = nums.size();
        vector<int> ans(size);
        vector<int> stk(size); // 存储下标的队列
        int         top = -1;

        /**
         * [1,2,3,4,3], [1,2,3,4,3]
         *          i            i
         *      i            i
         */
        for (int i = 2 * size - 1; i >= 0; i--)
        {
            int n = nums[i % size];
            while (top >= 0 && n >= nums[stk[top]])
            {
                top--;
            }

            if (top < 0)
                ans[i % size] = -1;
            else
                ans[i % size] = nums[stk[top]];

            top++;
            stk[top] = i % size;
        }
        return ans;
    }
};
// @lc code=end
