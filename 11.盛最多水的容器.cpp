/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode.cn/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (60.26%)
 * Likes:    4363
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 *
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 返回容器可以储存的最大水量。
 *
 * 说明：你不能倾斜容器。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 *
 * 示例 2：
 *
 *
 * 输入：height = [1,1]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
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
    int maxArea(vector<int>& height)
    {
        auto getArea = [&](int a, int b) -> int { return (b - a) * (height[a] > height[b] ? height[b] : height[a]); };

        int pl = 0, pr = height.size() - 1;
        int max_area = 0;
        int i, j = 0; // 记录最大面积情况
        while (pl <= pr)
        {

            // S(i,j) = (j - i) * min(h[i], h[j])
            // (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            // 面积取决于短板
            // 参看正确性证明： https://leetcode.cn/problems/container-with-most-water/solutions/11491/container-with-most-water-shuang-zhi-zhen-fa-yi-do/
            /**
             * 假设 h[i] < h[j]
             * 移动后底 = j-i-1 一定会少1
             * 1、移动短板:
             *  - 可能走向更长的情况，因此可以跳
             *  - 可能更短，但是此时最长的情况以及保存下来了
             * 2、移动长板: 可能会错过最长的情况
             *
             */
            int nowArea = (pr - pl) * (height[pl] > height[pr] ? height[pr] : height[pl]);
            if (nowArea > max_area)
            {
                max_area = nowArea;
                i        = pl;
                j        = pr;
            }

            if (height[pl] > height[pr])
            {
                pr--;
            }
            else
            {
                pl++;
            }
        }
        return max_area;
    }
};
// @lc code=end
