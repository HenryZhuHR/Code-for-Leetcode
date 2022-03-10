/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
  public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if ((head == nullptr) || (head->next == nullptr))
            return head;
        ListNode* p = head;
        while (p != nullptr)
        {
            ListNode* tmp = p->next;
            if ((tmp != nullptr) && (tmp->val == p->val))
            {
                while ((tmp != nullptr) && (tmp->val == p->val))
                {
                    tmp = tmp->next;
                }

                p->next = tmp;
            }
            else{
                p=p->next;
            }
        }
        return head;
    }
};
// @lc code=end
