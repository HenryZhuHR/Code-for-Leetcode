/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int min_str_len = strs.at(0).length();
        for (auto str : strs)
        {
            if (str.length() < min_str_len)
            {
                min_str_len = str.length();
            }
        }

        std::string str_common_prefix = "";
        for (int i = 0; i < min_str_len; i++)
        {
            char c = strs.at(0)[i];
            bool is_same = true;
            for (auto str : strs)
            {
                if (c != str[i])
                {
                    is_same = false;
                    break;
                }
            }
            if (is_same == true)
                str_common_prefix += c;
            else
            {
                break;
            }
        }

        return str_common_prefix;
    }
};
// @lc code=end

