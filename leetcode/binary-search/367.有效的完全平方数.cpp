/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode.cn/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (44.78%)
 * Likes:    505
 * Dislikes: 0
 * Total Accepted:    227.3K
 * Total Submissions: 507.6K
 * Testcase Example:  '16'
 *
 * 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
 *
 * 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
 *
 * 不能使用任何内置的库函数，如  sqrt 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num = 16
 * 输出：true
 * 解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = 14
 * 输出：false
 * 解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
  public:
    bool isPerfectSquare(int x)
    {
        if (x == 1)
            return true;
        int pl = 1, pr = x;
        while (pl <= pr)
        {
            int pm = pl + (pr - pl) / 2;

            if (x / pm == pm)
            {
                if (x % pm == 0)
                {
                    return true;
                }
                else
                {
                    pl = pm + 1;
                }
            }
            else if (x / pm < pm)
            {
                pr = pm - 1;
            }
            else
            {
                pl = pm + 1;
            }
        }
        return false;
    }
};
// @lc code=end
