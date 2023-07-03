/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 *
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (72.36%)
 * Likes:    536
 * Dislikes: 0
 * Total Accepted:    240.5K
 * Total Submissions: 332.4K
 * Testcase Example:  '"abbaca"'
 *
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 *
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 *
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 *
 *
 * 示例：
 *
 * 输入："abbaca"
 * 输出："ca"
 * 解释：
 * 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串
 * "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= S.length <= 20000
 * S 仅由小写英文字母组成。
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
  public:
    string removeDuplicates(string s)
    {
        stack<char> stack_char;
        for (auto c : s)
        {
            if (!stack_char.empty())
            {
                if (stack_char.top() == c)
                {
                    stack_char.pop();
                    continue;
                }
            }
            stack_char.push(c);
        }
        string res;
        res.resize(stack_char.size());
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res[i] = stack_char.top();
            stack_char.pop();
        }
        return res;
    }
};
// @lc code=end
