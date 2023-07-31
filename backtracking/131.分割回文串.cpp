/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.40%)
 * Likes:    1576
 * Dislikes: 0
 * Total Accepted:    308.3K
 * Total Submissions: 420K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 *
 * 回文串 是正着读和反着读都一样的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
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
  private:
    /**
     * 回文串判断
     */
    bool isPalindrome(const string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

  private:
    vector<vector<string>> res;
    vector<string>         temp;

  public:
    vector<vector<string>> partition(string s)
    {
        bt(s, 0);
        return res;
    }
    void bt(const string& s, int start)
    {
        if (start >= s.size())// 起始下标，超过原始字符串长度
        {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i)) // 回文串添加
            {
                temp.push_back(s.substr(start, i - start + 1));
                bt(s, i + 1);
                temp.pop_back();
            }
        }
    }
};
// @lc code=end
