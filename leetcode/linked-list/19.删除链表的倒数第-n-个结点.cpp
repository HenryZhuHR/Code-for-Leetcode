/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (45.62%)
 * Likes:    2563
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 *
 * 进阶：你能尝试使用一趟扫描实现吗？
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// @lc code=start
class Solution
{
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode();
        dummyHead->next     = head;
        ListNode* pfast     = dummyHead;
        ListNode* pslow     = dummyHead;

        // 前进
        n++;
        while (n > 0)
        {
            pfast = pfast->next;
            n--;
            if (pfast == nullptr && n != 0)
            {
                return dummyHead->next;
            }
        }

        // 同时前进
        while (pfast != nullptr)
        {
            pfast = pfast->next;
            pslow = pslow->next;
        }
        pfast       = pslow->next;
        pslow->next = pfast->next;
        return dummyHead->next;
    }
};
// @lc code=end
