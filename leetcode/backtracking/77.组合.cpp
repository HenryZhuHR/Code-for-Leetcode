/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.07%)
 * Likes:    1438
 * Dislikes: 0
 * Total Accepted:    564.3K
 * Total Submissions: 732.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
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
    // private:
    // vector<vector<int>>result;
    // vector<int>path;
    // private:
    // void backtracking(int start, int n, int k)
    // {
    //     // 剪枝 路径长度 + 剩下能取的数字 < k 那么不可能组成 k 个数字
    //     if (path.size() + n - start + 1 < k)
    //     {
    //         return;
    //     }
    //     if (path.size() == k)
    //     {
    //         // 终止递归，存放结果
    //         result.emplace_back(path);
    //         return;
    //     }
    //     for (int i = start; i <= n; i++)
    //     {
    //         path.emplace_back(i);
    //         backtracking(i + 1, n, k);
    //         path.pop_back(); // [回溯核心] 撤销本次操作，用于下一次的遍历，不然数组会重复
    //     }
    // }

  public:
    /**
     * 实际上解决 C_n_k 的问题
     * 每次树深度+1 获取的数+1 每次取1个数 深度优先 DFS
     */
    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> result; // 最终的结果 由 temp 组成
        std::vector<int>              path;   // 每次结果 实际上是一个 stack

        std::function<void(int)> backtracking = [&](int start_id)
        {
            if (path.size() + n - start_id + 1 < k)
                return;
            if (path.size() == k)
            { // 遇到叶子节点，个数满足要求
                result.push_back(path);
                return;
            }
            for (int i = start_id; i <= n; i++)
            {
                path.push_back(i);   // 处理节点
                backtracking(i + 1); // 递归
                // [回溯核心] 撤销本次操作，用于下一次的遍历，不然数组会重复
                path.pop_back();
            }
        };
        backtracking(1);
        return result;
    }
};
// @lc code=end
