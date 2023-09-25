/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.94%)
 * Likes:    2694
 * Dislikes: 0
 * Total Accepted:    928K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;                   // 存放结果
        vector<int>         path;                     // 存放中间路径
        vector<bool>        used(nums.size(), false); // 存放中间路径

        function<void(void)> bt = [&]()
        {
            if (path.size() == nums.size())
            {
                result.push_back(path);
                return;
            }
            for (auto i = 0; i < nums.size(); i++)
            {
                if (used[i] == true)
                    continue;
                used[i] = true;
                path.push_back(nums[i]);
                bt();
                path.pop_back();
                used[i] = false;
            }
        };
        bt();
        return result;
    }
};
// @lc code=end
