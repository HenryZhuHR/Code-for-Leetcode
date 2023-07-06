/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.82%)
 * Likes:    2458
 * Dislikes: 0
 * Total Accepted:    850.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
    /**
     * 只能是“后序遍历”，判断两个子树的内侧节点和外侧节点是否相等。
     */
    bool compareLR(TreeNode* left, TreeNode* right)
    {
        /**
         * 三种空结点的情况
         *    root
         *       null
         *
         *    root
         * null
         *
         *    root
         * null  null
         */
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        /**
         * 数值不等的情况也 false
         */
        else if (left->val != right->val)
            return false;
        else
        {
            /**
             * 左右都不是空结点，并且数值相等的情况
             * 继续递归接下来的结点
             */
            bool outSide = compareLR(left->left, right->right);
            bool in_Side = compareLR(left->right, right->left);
            return outSide && in_Side;
        }
    }
    bool isSymmetric(TreeNode* root)
    {
        {
            /**
             * 迭代解法
             */
            queue<TreeNode*> que;
            if (root == nullptr)
                return true;
            que.emplace(root->left);
            que.emplace(root->right);

            while (!que.empty())
            {

                TreeNode* lnode = que.front();
                que.pop();
                TreeNode* rnode = que.front();
                que.pop();

                /**
                 * 三种空结点的情况
                 *    root
                 * node  ____
                 *
                 *    root
                 * ____  node
                 *
                 *    root
                 * ____  ____
                 *
                 * 两种数值情况
                 *    root
                 *   2    4
                 *
                 *    root
                 *   2    2
                 */
                if (lnode != nullptr && rnode == nullptr)
                    return false;
                else if (lnode == nullptr && rnode != nullptr)
                    return false;
                else if (lnode == nullptr && rnode == nullptr)
                    continue;
                else if (lnode->val != rnode->val)
                    return false;
                else
                {
                    /**
                     *    1
                     *  2   2
                     * 4 4 4 4
                     */
                    que.emplace(lnode->left);
                    que.emplace(rnode->right);

                    que.emplace(lnode->right);
                    que.emplace(rnode->left);
                }
            }
            return true;
        }


        {
            /**
             * 递归的方法
             * 因为 树中节点数目在范围 [1, 1000] 内，所以 root 一定不是空
             */
            return compareLR(root->left, root->right);
        }
    }
};
// @lc code=end
