/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
  public:
    int maxSubArray(vector<int>& nums)
    {
        int max = INT_MIN;
        for (int winwidth = 1; winwidth <= nums.size(); winwidth++)
        {
            for (int i = 0; i < winwidth; i++)
            {
                int sum = 0;
                for (int j = i; j < winwidth; j++)
                    sum += nums[j];

                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};
// @lc code=end
