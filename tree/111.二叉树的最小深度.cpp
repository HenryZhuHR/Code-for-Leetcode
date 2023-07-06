/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (52.18%)
 * Likes:    1027
 * Dislikes: 0
 * Total Accepted:    569.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 *
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * 说明：叶子节点是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000
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
    int minDepth(TreeNode* root)
    {
        /**
         * BFS
         * 第 n 层有 2^n 个结点 n=0,1,2 返回时 +1
         *
         * 最小深度是从根节点到最近「叶子节点」的最短路径上的节点数量。
         * 说明: 叶子节点是指没有子节点的节点。
         */
        if (!root)
            return 0;
        queue<TreeNode*> que;
        que.emplace(root);
        int depth = 0;
        while (!que.empty())
        {
            depth++;            // 遍历层数
            int i = que.size(); // 队列里有多少个元素，深度就是多少
            while (i > 0)
            {
                i--;
                root = que.front();
                que.pop();
                if (root->left == nullptr && root->right == nullptr)
                {
                    return depth;
                }

                if (root->left)
                    que.emplace(root->left);
                if (root->right)
                    que.emplace(root->right);
            }
        }
        return depth;
    }
};
// @lc code=end
