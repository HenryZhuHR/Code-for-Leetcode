/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (58.06%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    207.6K
 * Total Submissions: 357.8K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 *
 *
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
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
  public:
    void reverseSubStr(string& s, int start, int end)
    {
        int i = start;
        int j = end;
        /**
         * ()
         * a b c d e
         * 0 1 2 3 4
         *     i
         * a b c d e f
         * 0 1 2 3 4 5
         *     i
         */
        while (i < j)
        {
            s[i] = char(s[i] ^ s[j]);
            s[j] = char(s[j] ^ s[i]);
            s[i] = char(s[i] ^ s[j]);
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k)
    {

        int i = 0;
        while (i + 2 * k <= s.length())
        {

            /**
             * a b c d e f | g h i j
             * 0 1 2 3 4 5 | 6 7 8 9
             * i   i     i   ⬆
             * k=3
             * a b c d | e f g h | i j
             * 0 1 2 3 | 4 5 6 7 | 8 9
             * ⬆⬆  ⬆         ⬆  ⬆
             * k=2
             */
            reverseSubStr(s, i, i + k - 1);

            i += 2 * k;
        }


        int restLen = s.length() - i;
        if (restLen > 1 && restLen < k)
        {
            reverseSubStr(s, i, s.length() - 1);
        }
        else if (restLen >= k && restLen < 2 * k)
        {
            reverseSubStr(s, i, i + k - 1);
        }
        return s;
    }
};
// @lc code=end
