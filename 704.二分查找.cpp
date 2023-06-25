/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
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
    int search(vector<int>& nums, int target)
    {
        int pl = 0;
        int pr = nums.size() - 1;
        while (pl <= pr)
        {
            int pm = (pl + pr) / 2;
            if (nums[pm] > target)
            {
                pr = pm - 1;
            }
            else if (nums[pm] < target)
            {
                pl = pm + 1;
            }
            else
            {
                return pm;
            }
        }
        return -1;
    }
};
// @lc code=end
