/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode.cn/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (34.66%)
 * Likes:    853
 * Dislikes: 0
 * Total Accepted:    236.3K
 * Total Submissions: 681.8K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 你可以选择使用单链表或者双链表，设计并实现自己的链表。
 *
 * 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
 *
 * 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
 *
 * 实现 MyLinkedList 类：
 *
 *
 * MyLinkedList() 初始化 MyLinkedList 对象。
 * int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
 * void addAtHead(int val) 将一个值为 val
 * 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
 * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
 * void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果
 * index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
 * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * 输出
 * [null, null, null, null, 2, null, 3]
 *
 * 解释
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
 * myLinkedList.get(1);              // 返回 2
 * myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
 * myLinkedList.get(1);              // 返回 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= index, val <= 1000
 * 请不要使用内置的 LinkedList 库。
 * 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。
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
struct DoubleLinkedNode
{
    DoubleLinkedNode* next;
    int               val;
    DoubleLinkedNode() : val(0), next(nullptr) {}
    DoubleLinkedNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList
{
  private:
    DoubleLinkedNode* dummyHead;
    DoubleLinkedNode* dummyTail;
    int               size;

  public:
    MyLinkedList()
    {
        this->dummyHead = new DoubleLinkedNode();
        this->size      = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= this->size)
        {
            return -1;
        }
        DoubleLinkedNode* p = this->dummyHead;
        while (index > 0)
        {
            p = p->next;
            index--;
        }
        return p->next->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(size, val); }

    void addAtIndex(int index, int val)
    {
        if (index > this->size)
        {
            return;
        }
        if (index < 0)
        {
            index = 0;
        }
        DoubleLinkedNode* p       = this->dummyHead;
        DoubleLinkedNode* newNode = new DoubleLinkedNode(val);
        while (index > 0)
        {
            p = p->next;
            index--;
        } // [p|v|n] , [p|v|n] , [p|v|n]

        newNode->next = p->next;
        p->next       = newNode;

        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > (this->size - 1))
        {
            return;
        }
        DoubleLinkedNode* p     = this->dummyHead;
        DoubleLinkedNode* p_tmp = p;
        while (index > 0)
        {
            p = p->next;
            index--;
        }
        p_tmp   = p->next;
        p->next = p_tmp->next;

        delete p_tmp;

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
