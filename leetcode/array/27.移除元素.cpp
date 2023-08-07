/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int removeElement(vector<int>& nums, int val)// 快慢双指针
    {
        int len = nums.size();

        int pfast,pslow=0;
        for(int pfast=0;pfast<nums.size();pfast++){
            if (nums[pfast]!=val){
                nums[pslow]=nums[pfast];
                pslow++;
            }
            
        }
        return pslow;
    }
};
// @lc code=end
