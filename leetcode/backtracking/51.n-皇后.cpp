/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.99%)
 * Likes:    1891
 * Dislikes: 0
 * Total Accepted:    332K
 * Total Submissions: 448.6K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *

 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
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
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>>   res;
        vector<string>           chessboard(n, string(n, '.'));
        std::function<void(int)> backtracking = [&](int i)
        {
            if (i == n)
            {
                res.push_back(chessboard);
                return;
            }
            for (auto j = 0; j < n; j++)
            {
                auto isValid = [=]()
                {
                    // 检查当前列
                    for (auto _i = 0; _i < i; _i++)
                    {
                        if (chessboard[_i][j] == 'Q')
                            return false;
                    }

                    // 检查45对角线
                    for (auto _i = 0; _i < i; _i++)
                    {
                        auto _j = i + j - _i;
                        if (chessboard[_i][_j] == 'Q')
                            return false;
                    }

                    // 检查 135 对角线
                    for (auto _i = i, _j = j; _i >=0 && _j >=0; _i--, _j--)
                    {
                        if (chessboard[_i][_j] == 'Q')
                            return false;
                    }
                    return true;
                };
                if (isValid())
                {
                    chessboard[i][j] = 'Q'; // 处理
                    backtracking(i + 1);    // 回溯
                    chessboard[i][j] = '.'; // 撤销
                }
            }
        };
        backtracking(0);
        return res;
    }
};
// @lc code=end
