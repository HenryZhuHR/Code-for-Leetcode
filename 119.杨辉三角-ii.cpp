/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (68.90%)
 * Likes:    496
 * Dislikes: 0
 * Total Accepted:    272.2K
 * Total Submissions: 395K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 *
 *
 * 示例 2:
 *
 *
 * 输入: rowIndex = 0
 * 输出: [1]
 *
 *
 * 示例 3:
 *
 *
 * 输入: rowIndex = 1
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
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
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> yh_tri(rowIndex + 1);
        for (int i = 0; i <rowIndex+1; i++)
        {
            yh_tri[i].resize(i + 1);
            yh_tri[i][0] = yh_tri[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                yh_tri[i][j] = yh_tri[i - 1][j - 1] + yh_tri[i - 1][j];
            }
        }
        return yh_tri[rowIndex];
    }
};
// @lc code=end
