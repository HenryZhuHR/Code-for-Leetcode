/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        ;
        int n = s.length();
        if (n <= 1)
            return s;
        std::string maxStr;

        for (int i = 0; i < n; i++)
        {

            if (n % 2 == 0)
            {
                int left = i, right = i;
            }
            else{
                int left = i, right = i + 1;
            }
        }
        return maxStr;
    }
};
// @lc code=end
