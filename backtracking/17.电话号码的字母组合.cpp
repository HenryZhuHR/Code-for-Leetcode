/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.10%)
 * Likes:    2547
 * Dislikes: 0
 * Total Accepted:    723.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
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
    vector<string> result;
    string         temp;
    const string   letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        bt(digits, 0);
        return result;
    }
    /**
     * 23
     * abc def
     */
    void bt(string digits, int start)
    {
        
        
        if (digits.size() == start)
        {
            result.emplace_back(temp);
            return;
        }

        // 取出当前对应的字符集 2 -> abc
        string letters = letterMap[digits[start] - '0'];

        for (int i = 0; i < letters.size(); i++)
        {
            // a
            temp.push_back(letters[i]);
            // 处理 3 def
            bt(digits, start + 1);
            // 撤销 a , 准备 b
            temp.pop_back();
        }
    }
};
// @lc code=end
