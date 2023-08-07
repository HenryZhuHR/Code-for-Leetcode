/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int removeDuplicates(vector<int>& nums)
    {
        int pslow = 0;
        for (int pfast = 1; pfast < nums.size(); pfast++)
        {
            if (nums[pfast] != nums[pslow])
            {
                pslow++;
                nums[pslow] = nums[pfast];
            }
        }

        return pslow + 1;
    }
};
// @lc code=end
