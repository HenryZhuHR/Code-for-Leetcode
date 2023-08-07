/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.54%)
 * Likes:    1594
 * Dislikes: 0
 * Total Accepted:    439.4K
 * Total Submissions: 691.5K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;


// @lc code=start
class pairGreater
{
  public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.second > rhs.second; }
};
class Solution
{
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) { return topKFrequent__minHeap(nums, k); }
    /**
     * 解法二：最小堆
     *
     *
     * 1 要统计元素出现频率
     * 2 对频率排序
     * 3 找出前K个高频元素
     *
     * 堆是一棵完全二叉树，树中每个结点的值都不小于（或不大于）其左右孩子的值。
     * 如果父亲结点是大于等于左右孩子就是大顶堆，小于等于左右孩子就是小顶堆。
     *
     * 所以大家经常说的大顶堆（堆头是最大元素），小顶堆（堆头是最小元素）
     * 如果懒得自己实现的话，就直接用priority_queue（优先级队列）就可以了，底层实现都是一样的
     *
     *
     * 从小到大排就是小顶堆 [ 0 1 2 3 ]
     * 从大到小排就是大顶堆 [ 3 2 1 0 ]
     */
    vector<int> topKFrequent__minHeap(vector<int>& nums, int k)
    {
        /**
         * HashMap 排序
         * map num:count
         */
        unordered_map<int, int> umap;
        for (auto n : nums)
        {
            umap[n]++;
        }


        /**
         * 对频率排序：遍历 HashMap，构建最小堆
         *
         * 值传递遍历   for (pair<int, int> kv : umap)
         * 引用传递遍历 for (const pair<int, int>& kv : umap)
         * 迭代器遍历   for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {*it}
         * 结构化绑定(c++17特性)
         * 值传递   for (auto [k, v] : umap)
         * 引用传递 for (auto& [k, v] : umap)
         *
         *
         * 优先队列 priority_queue (#include <queue>)
         * 底层是用堆来进行实现的
         */
        priority_queue<pair<int, int>,         // 元素类型
                       vector<pair<int, int>>, // 必须是容器类型，用来存储元素（element），其类型必须是第一个参数
                       pairGreater             // 比较方法
                       >
            pri_que;                           // 定义一个小顶堆，大小为k

        /**
         * 每一个元素排队入堆
         * 因为 优先队列 是按递减顺序的
         */
        // for (auto it : umap) pri_que.push(it);
        // for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) pri_que.push(*it);
        for (auto it : umap)
        {
            pri_que.push(it);
            /**
             * 如果堆的大小大于k，则队列弹出，保证堆的大小一直为k，
             * 弹出的是堆顶元素，因为我们设置的是「小顶堆」，所以出去的是小的元素
             */
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        /**
         * 取出全部 k 个元素
         */
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
    
    
    /**
     * 解法三：桶排序法
     */
};
// @lc code=end
