/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode.cn/problems/path-sum/description/
 *
 * algorithms
 * Easy (53.53%)
 * Likes:    1203
 * Dislikes: 0
 * Total Accepted:    557.8K
 * Total Submissions: 1M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点
 * 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * 输出：true
 * 解释：等于目标和的根节点到叶节点路径如上图所示。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：false
 * 解释：树中存在两条根节点到叶子节点的路径：
 * (1 --> 2): 和为 3
 * (1 --> 3): 和为 4
 * 不存在 sum = 5 的根节点到叶子节点的路径。
 *
 * 示例 3：
 *
 *
 * 输入：root = [], targetSum = 0
 * 输出：false
 * 解释：由于树是空的，所以不存在根节点到叶子节点的路径。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 5000] 内
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        /**
         * 判断该树中是否存在 根节点到[叶子节点] 的路径
         * KMP ?
         */
        // return hasPathSum_BFS(root, targetSum);
        return hasPathSum_DFS(root, targetSum);
    }
    bool hasPathSum_DFS(TreeNode* root, const int& targetSum)
    {
        stack<TreeNode*> nodeSt;
        stack<int>       nodeSumSt;

        if (root == nullptr)
            return false;
        else
        {
            nodeSt.emplace(root);
            nodeSumSt.emplace(root->val);
        }

        while (!nodeSt.empty())
        {
            root = nodeSt.top();
            nodeSt.pop();
            int val = nodeSumSt.top();
            nodeSumSt.pop();

            if (val == targetSum && root->left == nullptr && root->right == nullptr)
                return true;

            if (root->left)
            {
                nodeSt.emplace(root->left);
                nodeSumSt.emplace(val + root->left->val);
            }
            if (root->right)
            {
                nodeSt.emplace(root->right);
                nodeSumSt.emplace(val + root->right->val);
            }
        }
        return false;
    }
    bool hasPathSum_BFS(TreeNode* root, const int& targetSum)
    {
        queue<TreeNode*> nodeQue;
        queue<int>       pathSumQue;

        if (root == nullptr)
            return false;
        else
        {
            nodeQue.emplace(root);
            pathSumQue.emplace(root->val);
        }

        while (!nodeQue.empty())
        {
            int size = nodeQue.size();
            for (int i = 0; i < size; i++)
            {
                root = nodeQue.front();
                nodeQue.pop();
                int val = pathSumQue.front();
                pathSumQue.pop();

                // 判断是否是叶子
                if (val == targetSum && root->left == nullptr && root->right == nullptr)
                    return true;

                if (root->left)
                {
                    nodeQue.emplace(root->left);
                    pathSumQue.emplace(val + root->left->val);
                }
                if (root->right)
                {
                    nodeQue.emplace(root->right);
                    pathSumQue.emplace(val + root->right->val);
                }
            }
        }
        return false;
    }
};
// @lc code=end
