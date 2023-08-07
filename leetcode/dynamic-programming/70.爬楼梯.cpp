/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 * f(n) = f(n-1) + f(n-2)
 */
#include <vector>
// @lc code=start
class Solution
{
  public:
    int climbStairs(int n)
    {

        // std::vector<int> ans(n + 1);
        // ans[0] = 1;
        // ans[1] = 1;
        // for (int i = 2; i <= n; i++)
        // {
        //     ans[i] = ans[i - 1] + ans[i - 2];
        // }
        // return ans.at(n - 1);

        /**
         * 滚动数组
         * [a b ans] -> [a b ans (new)a] -> [a b ans]
         *  0 0  1         0 1   0+1         0 1  1
         */
        int a = 0, b = 0;
        int ans = 1;
        for (int i = 1; i < n + 1; i++)
        {
            int new_a = b + ans;
            a         = b;
            b         = ans;
            ans       = new_a;
        }
        return ans;
    }
};
// @lc code=end
