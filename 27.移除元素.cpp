/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
      if (nums[left] == val) {
        nums[left] = nums[right-1];
        right--;
      } else {
        left++;
      }
    }

    return left;
  }
};
// @lc code=end
