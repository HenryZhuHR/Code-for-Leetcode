/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (54.24%)
 * Likes:    2227
 * Dislikes: 0
 * Total Accepted:    464.8K
 * Total Submissions: 856.6K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 *
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 *
 *
 * 示例 2：
 *
 *
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 *
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中的所有字符串 互不相同
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
    bool wordBreak(string s, vector<string>& wordDict)
    {

        /**
         * 单词能否组成字符串s，就是问物品能不能把背包装满
         * 拆分时可以重复使用字典中的单词，说明就是一个「完全背包」
         * 排列数 ，包括了顺序，外层for背包
         */

        /**
         * dp[j] 表示 长度为 j 时候，是否可以装满
         * dp[i] 表示 s[i,j] 是否匹配
         */
        std::vector<bool> dp(s.size() + 1, false);             // std::vector<bool> 不是STL容器，不可以乱操作
        dp[0] = true;
        for (int j = 1; j <= s.size(); j++)                    // 排列数 外层遍历背包 容量
        {
            for (int i = 0; i < j; i++)                        // 遍历单词长度 0~j 容量
            {
                string word_tobe_matched = s.substr(i, j - i); // 截取长度为 j-i 的单词
                // 到 wordDict 找是否有 该单词
                for (const auto& word : wordDict)
                {
                    if ((word == word_tobe_matched) // 找到匹配的单词
                        && dp[i]                    // 「！！重要！！」 长度为 i 是否装满
                        // 因为只有 dp[i] 装满背包，dp[j] 才可以继续匹配
                        /**
                         * 0 1 2 3 4 5 6 7
                         * l e e t c o d e
                         * j=4 i=0 , s[0,4] = l e e t (存在) && dp[0]=true 所以 dp[4] 可以继续
                         * j=8 i=4 , s[4,8] = c o d e (存在) && dp[4]=true 所以 dp[8] 可以继续
                         */
                    )
                    {
                        dp[j] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
