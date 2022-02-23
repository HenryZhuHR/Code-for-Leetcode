/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <iostream>
#include <vector>
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Time complicate: O(log n)
        int pleft  = 0;
        int pright = nums.size() - 1;
        int index  = nums.size();

        while (pleft <= pright)
        {
            int pmid = ((pright - pleft) >> 1) + pleft;
            if (target <= nums[pmid])
            {
                index  = pmid;
                pright = pmid - 1;
            }
            else
            {
                pleft = pmid + 1;
            }
        }
        return index;
    }
};
// @lc code=end

