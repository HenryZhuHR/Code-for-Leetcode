/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 *
 * https://leetcode.cn/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (68.34%)
 * Likes:    933
 * Dislikes: 0
 * Total Accepted:    361.5K
 * Total Submissions: 529.1K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
 *
 * 实现 MyQueue 类：
 *
 *
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 *
 *
 * 说明：
 *
 *
 * 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 1, 1, false]
 *
 * 解释：
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= x <= 9
 * 最多调用 100 次 push、pop、peek 和 empty
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class MyQueue
{
    stack<int> stack_in;
    stack<int> stack_out;

  public:
    MyQueue() {}

    void push(int x) { stack_in.push(x); }

    int pop()
    {
        /**
         * 如果 出栈 为空，那么把 入栈 的数据全部压入 出栈 再出
         * 如果 出栈 有数据，就出去
        */
        if (stack_out.empty())
        {
            while (!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int res = stack_out.top();
        stack_out.pop();
        return res;
    }

    int peek()
    {
        int res = this->pop();
        stack_out.push(res);
        return res;
    }

    bool empty() { return stack_in.empty() && stack_out.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
