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
        int max_sum = INT_MIN;
        int sum     = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
            // 如果加完之后，还是负数，那么继续寻找能使得变正的数字
            /**
             * 如果 [-2, 1] 的情况，其实
             * 当前 和   最大和
             * -2   -2  -2
             * -2   0   -2  (和负数，找下一个正数)
             * 1    1   1
             */
            if (sum <= 0)
            {
                sum = 0;
            }
        }
        return max_sum;
    }
};
// @lc code=end
