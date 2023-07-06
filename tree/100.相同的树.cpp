/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode.cn/problems/same-tree/description/
 *
 * algorithms
 * Easy (59.98%)
 * Likes:    1035
 * Dislikes: 0
 * Total Accepted:    466.3K
 * Total Submissions: 777.3K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 *
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：p = [1,2,3], q = [1,2,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：p = [1,2], q = [1,null,2]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：p = [1,2,1], q = [1,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两棵树上的节点数目都在范围 [0, 100] 内
 * -10^4
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        /**
         * 和 101 对称二叉树一样，迭代比较各个结点
         */
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty())
        {
            TreeNode* nl = que.front();
            que.pop();
            TreeNode* nr = que.front();
            que.pop();

            /**
             * 空结点情况 ( 最后一种是叶子结点， continue)
             *  r  |  r   |  r
             * l _ |  _ r | _ _
             * 数值情况
             *    _     |    _
             *  1   2   |  2   2
             */
            if (nl != nullptr && nr == nullptr)
                return false;
            else if (nl == nullptr && nr != nullptr)
                return false;
            else if (nl == nullptr && nr == nullptr)
                continue;
            else if (nl->val != nr->val)
                return false;

            /**
             *    1
             *  2   2
             * 4 4 4 4
             */
            que.emplace(nl->left);
            que.emplace(nr->left);

            que.emplace(nl->right);
            que.emplace(nr->right);
        }
        return true;
    }
};
// @lc code=end
