/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (80.97%)
 * Likes:    963
 * Dislikes: 0
 * Total Accepted:    295.6K
 * Total Submissions: 365K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 *
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h
 * 层，则该层包含 1~ 2^h 个节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0
 * 题目数据保证输入的树是 完全二叉树
 *
 *
 *
 *
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
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
/**
 * 二叉树的定义
 *   0
 *  / \
 * 0   0
 */
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
    int countNodes(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        /**
         * DFS
         *
         * 满树 第 n 层 包含 2^(n-1) 个结点
         *
         * 完全二叉树的性质{根节点的左右子树至少有一个是满二叉树}，
         *
         * (1<<depth) - 1; // depth为子树的深度；为了加快幂的运算速度，可以使用移位操作符
         *           0
         *        /      \
         *       0         0
         *     /   \    /    \
         *   0      0  0      0
         *  / \    /
         * 0   0  0
         */

        TreeNode* lnode = root->left;
        TreeNode* rnode = root->right;

        int left_depth = 1;
        while (lnode)
        {
            lnode = lnode->left;
            left_depth++;
        }
        int right_depth = 1;
        while (rnode)
        {
            rnode = rnode->right;
            right_depth++;
        }
        /**
         * 如果最左侧深度 == 最右侧深度，说明是满二叉树
         * n 层满二叉树的结点总数为 2^n-1  n=1,2,3
         * 1   0
         *    / \
         * 2 0   0
         */
        if (left_depth == right_depth)
        {
            return (1 << left_depth) - 1;
        }
        /**
         * 如果满二叉树，那么就继续找
         */
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1; // +1 是根结点
        }
    }
};
// @lc code=end
