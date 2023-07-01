/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (60.57%)
 * Likes:    740
 * Dislikes: 0
 * Total Accepted:    346.7K
 * Total Submissions: 572.1K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 *
 * 如果可以，返回 true ；否则返回 false 。
 *
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 *
 * 示例 2：
 *
 *
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
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
    bool canConstruct(string ransomNote, string magazine)
    {
        /**
         * magazine 包含 ransomNote 
         * 用 Hash Table 统计 magazine char，然后 ransomNote 对比
         */
        unordered_map<char, int> umap_char;

        bool ans = true;

        for (auto c : magazine)
        {
            umap_char[c]++;
        }
        for (auto c : ransomNote)
        {
            if (umap_char.find(c) != umap_char.end()) // 找到该字符
            {

                if (umap_char[c] > 0)
                {
                    umap_char[c]--;
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
