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
        if (s.size() % 2 != 0)
            return false;

        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        std::stack<char> char_stack;
        for (char c : s)
        {
            if (pairs.count(c) > 0)
            {
                if (char_stack.empty() || pairs[c] != char_stack.top())
                    return false;
                else
                    char_stack.pop();
            }
            else
            {
                char_stack.push(c);
            }
        }
        return char_stack.empty();
    }
};
// @lc code=end

