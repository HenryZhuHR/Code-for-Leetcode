/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.55%)
 * Likes:    497
 * Dislikes: 0
 * Total Accepted:    193.1K
 * Total Submissions: 262.7K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 *
 * 假设二叉树中至少有一个节点。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: root = [2,1,3]
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * ⁠
 *
 *
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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
    int findBottomLeftValue(TreeNode* root)
    {
        int num = root->val;
        /**
         * 如果，深度的思路，记录树的深度; 回溯，递归
         */
        {
        }
        /**
         * 广度优先：每次遍历队列时候，队列第一个就是当前行最左侧的值
         */
        {
            queue<TreeNode*> que;
            que.emplace(root);
            while (!que.empty())
            {
                int n_layer_node = que.size();
                int i            = n_layer_node;
                while (i > 0)
                {
                    root = que.front();
                    que.pop();
                    if (i == n_layer_node)
                        num = root->val;

                    if (root->left)
                        que.emplace(root->left);
                    if (root->right)
                        que.emplace(root->right);

                    i--;
                }
            }
            return num;
        }
    }
};
// @lc code=end
