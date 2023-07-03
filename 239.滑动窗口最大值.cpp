/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.68%)
 * Likes:    2356
 * Dislikes: 0
 * Total Accepted:    454.1K
 * Total Submissions: 914.2K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <deque>
using namespace std;

// @lc code=start
class MonotonicQueue
{
  private:
    /** deque双端队列的操作（可以在队头队尾进行入队出队操作）
     * deque<int> dq;   创建一个数双端队列dq
     * dq.empty();      判断队列是否为空，为空返回true
     * dq.push_front(s);将s从队头入队
     * dq.push_back(s); 将s从队尾入队，和普通队列方式一样
     * dq.front();      只返回队头元素
     * dq.back();       只返回队尾元素
     * dq.pop_front();  将队头元素弹出
     * dq.pop_back;     将队尾元素弹出
     * dq.clear();      将队列清空
     */
    deque<int> q; // 队头是大数字
};

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        /**
         * 单调队列
         *
         * https://leetcode.cn/problems/sliding-window-maximum/solutions/10025/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-2/comments/1530235
         */

        /**
         * 长度 8 k=3 有6个数
         * i>
         * 1  3 -1 -3  5  3  6  7
         * 0  1  2  3  4  5  6  7
         * -------
         *       --------------
         *                -------
         */
        deque<int>  dq; // 保存下标
        vector<int> res;
        for (int j = 0; j < nums.size(); j++)
        {
            /**
             * 新加入元素 n_j ，判断一下最左侧的 n_i (i=j-k) 是不是还在单调队列里
             * 如果在就踢出去
             *
             * 这是因为，即使最左侧的是最大值，那么一定有一个比他小、在窗口里的排在队列里
             */
            if (!dq.empty() && dq.front() == j - k)
            {
                dq.pop_front();
            }

            /**
             * 新加入元素 n_j ，把 n_j 入 单调队列
             *
             * 这里和上一个不矛盾，因为如果最左侧的是最大值，那么新加进来的比他小，直接加入，不踢出去
             */
            while (!dq.empty() && nums[j] > nums[dq.back()])
            {
                dq.pop_back();
            }
            // 入 单调队列
            dq.push_back(j);

            /**
             * 取最大值，但是
             * 窗口要大于 k
             */
            if (j >= k - 1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end


/**
 * 超时了，因为每次找最大值会遍历 k 次
 */
vector<int> ___maxSlidingWindow(vector<int>& nums, int k)
{
    /**
     * 1  3 -1 -3  5  3  6  7
     * 0  1  2  3  4  5  6  7
     * -------
     *                -------
     */
    int         len = nums.size() - k + 1;
    vector<int> res(len);
    for (int i = 0; i < len; i++)
    {
        int max = nums[i];
        for (int j = i; j < i + k; j++)
        {
            if (nums[j] > max)
            {
                max = nums[j];
            }
        }
        res[i] = max;
    }
    return res;
}