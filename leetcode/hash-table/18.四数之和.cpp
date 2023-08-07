/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.82%)
 * Likes:    1616
 * Dislikes: 0
 * Total Accepted:    463.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
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
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        // 解题 https://programmercarl.com/0454.四数相加II.html#其他语言版本

        

        vector<vector<int>> result;
        if (nums.size() < 4) // 长度不够的特例
            return result;
        sort(nums.begin(), nums.end());

        for (int a = 0; a < nums.size()-3; a++)
        {
            // 如果某正数大于 target，那么再加正数就不可能减小了，所以可以直接结束
            // 如果某负数大于 target，再加入负数可能是变小的:
            /*
              -4>-5(target);
              -4+(-3)=-7 < -5
              -4+(-3)+2=-5 还是有可能的
            */
            if (nums[a] > target && nums[a] >= 0)
            {
                break; // return result;
            }

            // 去重复: [-1 0 0 2]
            if (a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }

            // 后面就类似于 15.三数之和
            for (int b = a + 1; b < nums.size()-2; b++)
            {
                long sum_ab = nums[a] + nums[b];
                if (sum_ab > target && sum_ab >= 0)
                {
                    break;
                }
                // 去重复: [-1 0 0 2] ; [2,2,2,2,2]
                //                      a b c   d
                if (b > a+1 && nums[b] == nums[b - 1])
                {
                    continue;
                }
                int c = b + 1;
                int d = nums.size() - 1;

                while (c < d)
                {
                    if (long(nums[c] + nums[d]+sum_ab) > target )// 越界问题 long
                    {
                        d--;
                    }
                    else if (long(nums[c] + nums[d]+sum_ab) < target )
                    {
                        c++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});

                        // 去重复 c / d
                        c++;
                        while (c < d && nums[c] == nums[c - 1])
                        {
                            c++;
                        }
                        d--;
                        while (c < d && nums[d] == nums[d + 1])
                        {
                            d--;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

