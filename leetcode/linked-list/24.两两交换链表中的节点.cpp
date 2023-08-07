/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (71.28%)
 * Likes:    1854
 * Dislikes: 0
 * Total Accepted:    644.2K
 * Total Submissions: 903.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
 *
 *
 */
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
    ListNode* swapPairs(ListNode* head)
    {
        // dummy->1->2->3->4->null
        //  👆    👆     👆
        // pre   cur.   tmp
        ListNode* dummyHead = new ListNode();
        dummyHead->next     = head;
        ListNode* p         = dummyHead;
        ListNode* tmp;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            tmp           = p->next->next;
            p->next->next = tmp->next;

            tmp->next = p->next;
            p->next   = tmp;

            p = p->next->next;// 前进两步
        }
        return dummyHead->next;
    }
};
// @lc code=end
