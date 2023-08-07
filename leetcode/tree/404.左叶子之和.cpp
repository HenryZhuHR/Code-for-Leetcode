/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (62.38%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    243.8K
 * Total Submissions: 390.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 *
 *
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
    int sumOfLeftLeaves(TreeNode* root)
    {
        /**
         * 给定二叉树的根节点 root ，返回所有[左叶子]之和。
         */

        // {
        //     /**
        //      * 递归
        //      */
        //     if (root == nullptr)
        //         return 0;
        //     int val = 0;
        //     if (root->left != nullptr)
        //         if (root->left->left == nullptr && root->left->right == nullptr)
        //             val = root->left->val;
        //     return val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        // }


        {
            int              sum = 0;
            stack<TreeNode*> st;
            while (!st.empty()||root)
            {
                while (root)
                {
                    st.emplace(root);
                    root = root->left;
                }
                root = st.top();
                st.pop();
                if (root->left != nullptr)
                    if (root->left->left == nullptr && root->left->right == nullptr)
                        sum += root->left->val;
                root = root->right;
            }
            return sum;
        }
    }
};
// @lc code=end
