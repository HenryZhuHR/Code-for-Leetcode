/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
  public:
    bool isValid(string s)
    {
        unordered_map<char, char> umap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char>               stack_char;
        for (auto c : s)
        {

            if (c == ')' || c == ']' || c == '}')
            {

                if (stack_char.empty())
                {
                    return false;
                }
                else
                {
                    if (c == umap[stack_char.top()])
                    {
                        stack_char.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                stack_char.push(c);
            }
        }
        return stack_char.empty();
    }
};
// @lc code=end
