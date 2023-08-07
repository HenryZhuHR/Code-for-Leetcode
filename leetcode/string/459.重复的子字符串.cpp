/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode.cn/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (51.19%)
 * Likes:    988
 * Dislikes: 0
 * Total Accepted:    193.5K
 * Total Submissions: 377.9K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "aba"
 * 输出: false
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
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
    bool repeatedSubstringPattern(string s)
    {
        int len = s.length();
        if (len == 1)
            return false;
        /**
         * KMP 求 next 数组
         *
         * a b a b c
         * 0 1 2 3 4
         *
         */
        int next[len];
        {
            next[0] = 0;
            int j   = 0; // j 是前一个的 「最长公共前后缀」 的长度
            for (int i = 1; i < len; i++)
            {
                /**
                 * 0 1 2 3 4 5 6 7 (index)
                 * a b a c a b a b (str)
                 * 0 0 1 0 1 2 3    (next)
                 * a b a   a b a
                 * 当前的 j 是为新增时候的最长 「最长公共前后缀」 的长度。
                 * j=3, aba
                 *
                 * 现在需要新增一个，那么新增的和 j=3 的char看看匹配不匹配
                 *
                 * s[i] != s[j]
                 * 如果新增 n_7 不匹配，那么查看前一个 n_6 时候的 「最长公共前后缀」 的长度
                 * n_6 子串的最长 「最长公共前后缀」 的长度为 3 ( aba / aba )
                 */
                while (s[i] != s[j] && j > 0) // j>0是因为下面取 next[j - 1]保证有意义
                {
                    // j>0 是因为下面取 next[j - 1]保证有意义
                    // j-1 = 0 的时候，也就是第一个单字符 next[0]，这时候不存在匹配的
                    j = next[j - 1];
                }
                /**
                 * 如果匹配的话，  「最长公共前后缀」 的长度 ++
                 */
                if (s[i] == s[j])
                {
                    j++;
                }
                /**
                 * 更新 next[i]
                 */
                next[i] = j;
            }
        }

        /**
         * 找到 next 数组后，就看当前完整 str 最长有没有 匹配的
         *
         * a s d f  a s d f  a s d f
         * 0 0 0 0  1 2 3 4  5 6 7 8
         * next[len - 1] = 8
         *
         * 子串长度 = 4 , next[0] ~ next[3]
         * 12 % 4 = 0
         * 12 / 4 = 3 重复次数
         */
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
