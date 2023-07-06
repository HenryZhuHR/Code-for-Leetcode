/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 *
 * https://leetcode.cn/problems/split-with-minimum-sum/description/
 *
 * algorithms
 * Easy (76.85%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 7.9K
 * Testcase Example:  '4325'
 *
 * 给你一个正整数 num ，请你将它分割成两个非负整数 num1 和 num2 ，满足：
 *
 *
 * num1 和 num2 直接连起来，得到 num 各数位的一个排列。
 *
 *
 * 换句话说，num1 和 num2 中所有数字出现的次数之和等于 num 中所有数字出现的次数。
 *
 *
 * num1 和 num2 可以包含前导 0 。
 *
 *
 * 请你返回 num1 和 num2 可以得到的和的 最小 值。
 *
 * 注意：
 *
 *
 * num 保证没有前导 0 。
 * num1 和 num2 中数位顺序可以与 num 中数位顺序不同。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num = 4325
 * 输出：59
 * 解释：我们可以将 4325 分割成 num1 = 24 和 num2 = 35 ，和为 59 ，59 是最小和。
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = 687
 * 输出：75
 * 解释：我们可以将 687 分割成 num1 = 68 和 num2 = 7 ，和为最优值 75 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 10 <= num <= 10^9
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
  public:
    int splitNum(int num)
    {
        /**
         * string s = to_string(num);
         * 分割成字符串 
         * s[i]-'0'
        */
        vector<int> nums;
        /**
         * 45 % 10 = 5 ; 45 / 10 = 4
         * 4%10=4 ; 4/10=0
         *
         */
        while (num > 0)
        {
            nums.emplace_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end()); // 升序排列

        int num1 = 0;
        int num2 = 0;


        int size = nums.size();
        if (size & 1 == 1) // 奇数
            size--;

        int i = 0;

        while (i + 1 < size)
        {
            printf("(%d:%d) %d, %d\n ", i, size, num1, num2);
            num1 = num1 * 10 + nums[i];
            num2 = num2 * 10 + nums[i+1];
            i += 2;
        }
        if (i < nums.size())
            num1 = num1 * 10 + nums[i];

        return num1 + num2;
    }
};
// @lc code=end
