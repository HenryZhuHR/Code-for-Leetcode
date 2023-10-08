/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.99%)
 * Likes:    2277
 * Dislikes: 0
 * Total Accepted:    551.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 *
 * 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j]
 * 处:
 *
 *
 * 0 <= j <= nums[i] 
 * i + j < n
 *
 *
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 nums[n-1]
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
    int jump(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;
        int cnt  = 0;
        int end  = 0; // 当前能跳跃到的位置的边界下标
        int maxp = 0; // 当前能覆盖的最大下标，不断更新

        for (auto i = 0; i < nums.size(); i++)
        {
            maxp = std::max(maxp, i + nums[i]);
            // 如果到达了边界，那么一定要跳了
            if (i == end)
            {
                end = maxp; // 下一跳的边界下标就是之前统计的最优情况
                cnt++;      // 步数加1
                if (end >= nums.size() - 1)
                    break;
            }
        }
        return cnt;
    }
};
// @lc code=end
