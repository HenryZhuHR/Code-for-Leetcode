/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * 
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
    int lengthOfLongestSubstring(string s)
    {

        auto n = s.length();
        if (n <= 1)
            return n;

        // unordered set
        std::unordered_set<char> lookup(n);
        // left & right pointer
        int pleft = 0, pright = 0;
        int max_len = 0;
        while (pright < n)
        {
            while (lookup.find(s[pright]) != lookup.end())
            {
                lookup.erase(s[pleft]);
                pleft++;
            }
            max_len = (pright - pleft + 1) > max_len ? (pright - pleft + 1) : max_len;
            lookup.insert(s[pright]);
            pright++;
        }
        return max_len;
    }
};
// @lc code=end
