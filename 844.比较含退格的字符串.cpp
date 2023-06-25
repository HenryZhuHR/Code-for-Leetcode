/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode.cn/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.91%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    204K
 * Total Submissions: 425.8K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
 *
 * 注意：如果对空文本输入退格字符，文本继续为空。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ab#c", t = "ad#c"
 * 输出：true
 * 解释：s 和 t 都会变成 "ac"。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "ab##", t = "c#d#"
 * 输出：true
 * 解释：s 和 t 都会变成 ""。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a#c", t = "b"
 * 输出：false
 * 解释：s 会变成 "c"，但 t 仍然是 "b"。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length, t.length <= 200
 * s 和 t 只含有小写字母以及字符 '#'
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// 用栈解决 / 双指针从最后遍历
// @lc code=start
class Solution
{
  public:
    bool backspaceCompare(string s, string t)
    {
        int  l_s   = removeChar(s);
        int  l_t   = removeChar(t);
        bool is_eq = false;
        if (l_s == l_t)
        {
            is_eq = true;
            for (int i = 0; i < l_s; i++)
            {
                if (s[i] != t[i])
                {
                    is_eq = false;
                    break;
                }
            }
        }
        return is_eq;
    }


    int removeChar(string& str)
    {
        int sp = 0;

        for (int fp = 0; fp < str.size(); fp++)
        {
            if (str[fp] == '#')
            {   // keypoint: 如果碰到 # ，慢指针后退
                // 但是保证慢指针 >=0
                if (sp > 0)
                {
                    sp--;
                }
            }
            else
            {
                str[sp] = str[fp];
                sp++;
            }
        }
        return sp;
    }
};
// @lc code=end
