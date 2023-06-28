/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (54.91%)
 * Likes:    1263
 * Dislikes: 0
 * Total Accepted:    571.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1
 * 0
 *
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
    ListNode* removeElements(ListNode* head, int val)
    {

        ListNode* dummyHead = new ListNode(0); // 创建一个虚拟头结点
        dummyHead->next     = head;
        ListNode* p         = dummyHead;       // 创建一个遍历指针
        ListNode* p_tmp     = dummyHead;       // 创建一个遍历指针

        while (p->next != nullptr)
        {
            if (p->next->val == val)
            {
                p_tmp = p->next;
                p->next=p->next->next;
                delete p_tmp;
            }
            else{
                p=p->next;
            }
        }
        head=dummyHead->next;
        delete dummyHead;
        return head;
    }
};
// @lc code=end
