/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (79.67%)
 * Likes:    778
 * Dislikes: 0
 * Total Accepted:    756.7K
 * Total Submissions: 949.7K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 *
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
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
    void reverseString(vector<char>& s)
    {
        // 遍历结束的位置
        /**
         * (len-1)/2
         * a b c d e (5)
         * 0 1 2 3 4
         *     |
         * a b c d e f (6)
         * 0 1 2 3 4 5
         *     |
         */

        for (int i = 0; i <= (s.size() - 1) / 2; i++)
        {
            int j = s.size() - i - 1;
            // s[i] ^= s[j]; // 字符串用异或有问题 自己和自己交换的时候
            // s[j] ^= s[i];
            // s[i] ^= s[j];
            char tmp = s[i];
            s[i]    = s[j];
            s[j]    = tmp;
        }
    }
};
// @lc code=end
