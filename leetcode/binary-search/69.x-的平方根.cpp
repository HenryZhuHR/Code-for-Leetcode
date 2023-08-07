/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
  public:
    int mySqrt(int x) // 由于 x 平方根的整数部分 ans 是满足 k^2<=x 的最大 k 值，因此我们可以对 k 进行二分查找，从而得到答案。
    {
        if (x == 0 || x == 1)
            return x; // 特殊情况跳过
        int l   = 1;  // 0不用管，从1开始
        int r   = x;
        int ans = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2; // 防止溢出
            if (m <= x / m)          // 除法防止溢出
            {
                l   = m + 1;
                ans = m;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
