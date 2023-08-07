/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int window_len = needle.length();
        if (window_len == 0)
            return window_len;
        int left = 0;
        for (; left + window_len <= haystack.length(); left++)
        {
            bool isSame = true;
            for (int i = left; i < left + window_len; i++)
            {
                if (haystack[i] != needle[i - left])
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                return left;
        }

        return -1;
    }
};
// @lc code=end

class mySolution
{
  public:
    int strStr(string haystack, string needle)
    {
        int window_len = needle.length();
        if (window_len == 0)
            return window_len;
        int left = 0;
        for (; left + window_len <= haystack.length(); left++)
        {
            bool isSame = true;
            for (int i = left; i < left + window_len; i++)
            {
                if (haystack[i] != needle[i - left])
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                return left;
        }

        return -1;
    }
};
