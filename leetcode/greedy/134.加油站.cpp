/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 *
 * https://leetcode.cn/problems/gas-station/description/
 *
 * algorithms
 * Medium (50.01%)
 * Likes:    1413
 * Dislikes: 0
 * Total Accepted:    287K
 * Total Submissions: 573.9K
 * Testcase Example:  '[1,2,3,4,5]\n[3,4,5,1,2]'
 *
 * 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 *
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 *
 * 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一
 * 的。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * 输出: 3
 * 解释:
 * 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
 * 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
 * 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
 * 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
 * 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
 * 因此，3 可为起始索引。
 *
 * 示例 2:
 *
 *
 * 输入: gas = [2,3,4], cost = [3,4,3]
 * 输出: -1
 * 解释:
 * 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
 * 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
 * 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
 * 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
 * 因此，无论怎样，你都不可能绕环路行驶一周。
 *
 *
 *
 * 提示:
 *
 *
 * gas.length == n
 * cost.length == n
 * 1 <= n <= 10^5
 * 0 <= gas[i], cost[i] <= 10^4
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        {
            int curSum   = 0;
            int totalSum = 0;
            int start    = 0;
            for (int i = 0; i < gas.size(); i++)
            {
                auto spase = gas[i] - cost[i];
                curSum += spase;
                totalSum += spase;
                if (curSum < 0)
                {                   // 当前累加rest[i]和 curSum一旦小于0
                    start  = i + 1; // 起始位置更新为i+1
                    curSum = 0;     // curSum从0开始
                }
            }
            if (totalSum < 0)
                return -1; // 说明怎么走都不可能跑一圈了
            return start;
        }

        {
            int minSpare = std::numeric_limits<int>::max(); // 初始化最小剩余汽油量为整型的最大值
            int spare    = 0;                               // 当前剩余汽油量
            int index    = 0;                               // 起始加油站下标
            for (auto i = 0; i < gas.size(); i++)
            {
                spare += gas[i] - cost[i]; // 更新剩余油
                if (spare < minSpare)      // 若当前剩余汽油量小于最小剩余汽油量
                {
                    minSpare = spare;
                    index    = i;
                }
            }
            if (spare < 0)
                return -1; // 如果总剩余汽油量小于零，则无法走完一圈，返回-1
            /**
             * 有一个存在不是唯一解的测试案例跑不通了。
             * 所以要添加一个判断，如果遍历后的 minSpare > 0，表示所有情况都是满足的，直接返回 0。
             */
            if (minSpare >= 0)
                return 0;                    // 如果最小剩余汽油量大于等于零，则从起始加油站开始能够走完一圈，返回0
            return (index + 1) % gas.size(); // 返回起始加油站下标加1除以数组长度的余数，表示从该加油站开始能够走完一圈
        }
    }
};
// @lc code=end
