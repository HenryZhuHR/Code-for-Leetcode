/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.79%)
 * Likes:    1597
 * Dislikes: 0
 * Total Accepted:    459.6K
 * Total Submissions: 668.3K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 *
 *
 * 示例 2:
 *
 *
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 *
 *
 * 示例 3:
 *
 *
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {

        auto        len = temperatures.size();
        vector<int> res(len, 0);
        if (len <= 0)
            return res;
        using id_t = decltype(len);
        stack<id_t> stk; // 存放下标
        stk.push(0);
        for (id_t i = 0; i < len; ++i)
        {

            if (temperatures[i] <= temperatures[stk.top()]) // 存放的是下标，所以要取数值比较
            {
                stk.push(i);
            }
            else // 不会升高，说明找到必须大于，不含等于
            {
                while (!stk.empty()                                  //
                       && (temperatures[i] > temperatures[stk.top()] // 存放的是下标，所以要取数值比较
                           ))
                {
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }

        return res;
    }
};
// @lc code=end
vector<int> dailyTemperatures(vector<int>& T)
{
    vector<int> res(T.size(), 0);
    stack<int>  stk; // 存放下标
    stk.push(0);
    for (int i = 0; i < T.size(); ++i)
    {

        if (T[i] <= T[stk.top()]) // 存放的是下标，所以要取数值比较
        {
            stk.push(i);
        }
        else // 不会升高，说明找到必须大于，不含等于
        {
            while (!stk.empty()            //
                   && (T[i] > T[stk.top()] // 存放的是下标，所以要取数值比较
                       ))
            {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
    }
    return res;
}