/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * f(i) = max{ f(i-1) + nums[i], nums[i] }
 * ans = max{ f(i) }
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int maxSubArray(vector<int>& nums)
    {
        auto Max = [](int a, int b) { return a >= b ? a : b; };
        int  fi = 0;
        int  ans = nums[0];
        for (auto x : nums)
        {
            fi = Max(fi + x, x);
            ans = Max(ans, fi);
        }
        return ans;
    }
};
// @lc code=end
