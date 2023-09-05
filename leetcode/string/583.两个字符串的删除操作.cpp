/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (66.76%)
 * Likes:    619
 * Dislikes: 0
 * Total Accepted:    134.3K
 * Total Submissions: 201.2K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
 *
 * 每步 可以删除任意一个字符串中的一个字符。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: word1 = "sea", word2 = "eat"
 * 输出: 2
 * 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
 *
 *
 * 示例  2:
 *
 *
 * 输入：word1 = "leetcode", word2 = "etco"
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 * 1 <= word1.length, word2.length <= 500
 * word1 和 word2 只包含小写英文字母
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
    int minDistance(string word1, string word2)
    {
        using id_t = uint32_t;
        vector<vector<id_t>> dp(word1.size() + 1, vector<id_t>(word2.size() + 1, 0));
        for (id_t i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (id_t j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        for (id_t i = 1; i < word1.size() + 1; i++)
        {
            for (id_t j = 1; j < word2.size() + 1; j++)
            {
                if (word2[j - 1] == word1[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 相同的时候，不需要删减
                }
                else
                {
                    // dp[i][j] = min(dp[i][j - 1] + 1,    // 删除 word1
                    //                dp[i - 1][j] + 1,    // 删除 word2
                    //                dp[i - 1][j - 1] + 2 // 同时删除，当然可以优化
                    // );
                    dp[i][j] = min(dp[i][j - 1] + 1, // 删除 word1
                                   dp[i - 1][j] + 1  // 删除 word2
                    );
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
