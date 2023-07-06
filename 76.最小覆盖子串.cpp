
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (m < n)
        {
            return "";
        }

        unordered_map<char, int> cmap;
        for (auto c : t)
        {
            cmap[c]++;
        }
        unordered_map<char, int> tmap;

        int pl=0,pr=0;
       for (;pr<s.size();pr++){
        
       }



        return "";
    }
};
// @lc code=end
