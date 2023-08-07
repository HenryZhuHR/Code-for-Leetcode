/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.65%)
 * Likes:    1404
 * Dislikes: 0
 * Total Accepted:    446.8K
 * Total Submissions: 749K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。 
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
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
    vector<vector<int>> res;
    vector<int>         path;

  public:
  /**
   * 出现重复的原因
   * [2,2,3](5) 现有的sln [2,3] [2,3]
  */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // 去除重复，需要排序
        bt(candidates, target, 0, 0);
        return res;
    }
    void bt(vector<int>& candidates, int target, int sum, int si)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        for (int i = si; i < candidates.size(); i++)
        {
            // 去重最关键的一步 前提是排过序
            if (i > si && candidates[i] == candidates[i - 1])
                continue;
            int num = candidates[i];
            path.push_back(num);
            sum += num;
            bt(candidates, target, sum, i + 1);
            path.pop_back();
            sum -= num;
        }
    }
};
// @lc code=end
