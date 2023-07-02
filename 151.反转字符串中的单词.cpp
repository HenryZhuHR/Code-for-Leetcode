/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (51.81%)
 * Likes:    899
 * Dislikes: 0
 * Total Accepted:    402.8K
 * Total Submissions: 777.2K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 *
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 *
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 *
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 *
 *
 *
 *
 *
 *
 *
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。
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
    void reverseStr(string& s, int i, int j)
    {
        while (i < j)
        {
            s[i] = char(s[i] ^ s[j]);
            s[j] = char(s[j] ^ s[i]);
            s[i] = char(s[i] ^ s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s)
    {
        /**
         * the sky  is  blue
         * eulb  si  yks eht
         * eulb si yks eht
         * blue   is sky the
         * blue isis sky the
         */


        int i = 0;
        int j = 0;
        // 删除多余的空格
        while (j < s.length())
        {
            if (s[j] != ' ')
            {
                if (i > 0)
                    s[i++] = ' ';
                while (s[j] != ' ' && j < s.length())
                {
                    s[i++] = s[j++];
                }
            }
            j++;
        }
        s.resize(i);


        // 反转字符串
        reverseStr(s, 0, s.length() - 1);


        // 按照空格反转单词
        {
            i = 0;
            j = 0;
            while (j < s.length())
            {
                if (s[j] == ' ')
                {
                    reverseStr(s, i, j - 1);
                    i = j + 1;
                }
                j++;
            }
        }
        if (j - i > 1)
        {
            reverseStr(s, i, j - 1);
        }
        return s;
    }
};
// @lc code=end
