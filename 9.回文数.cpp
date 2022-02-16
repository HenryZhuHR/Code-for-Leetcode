/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    // === using int === 
    long int x_reverse = 0;
    int temp = x;
    while (temp != 0) {
      x_reverse = x_reverse * 10 + temp % 10;
      temp /= 10;
    }
    return x_reverse == x;
  }
};
// @lc code=end
