/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode.cn/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (79.15%)
 * Likes:    1250
 * Dislikes: 0
 * Total Accepted:    410.8K
 * Total Submissions: 519.1K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给你两棵二叉树： root1 和 root2 。
 *
 *
 * 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为
 * null 的节点将直接作为新二叉树的节点。
 *
 * 返回合并后的二叉树。
 *
 * 注意: 合并过程必须从两个树的根节点开始。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * 输出：[3,4,5,5,4,null,7]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root1 = [1], root2 = [1,2]
 * 输出：[2,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两棵树中的节点数目在范围 [0, 2000] 内
 * -10^4 <= Node.val <= 10^4
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
    /**
     * BFS
     */
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {

        // root1 == nullptr || root2 == nullptr
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        // root1 != nullptr && root2 != nullptr
        TreeNode*        root = new TreeNode(root1->val + root2->val);
        queue<TreeNode*> que;
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        que.emplace(root);
        que1.emplace(root1);
        que2.emplace(root2);


        /**
         * * 俩树都不为空
         *   0      0
         *  / \    / \
         * 0   0  0   0
         * root1 左空 右空
         *   0      0
         *    \      \
         *     0      0
         * root1 左空 右不空
         *   0      0
         *    \    / \
         *     0  0   0
         * root1 左不空 右空
         *   0      0
         *  / \      \
         * 0   0      0
         */
        while (!que1.empty() && !que2.empty())
        {

            auto node = que.front();
            que.pop();
            root1 = que1.front();
            que1.pop();
            root2 = que2.front();
            que2.pop();


            /**
             * 处理 left
             */
            auto r1left = root1->left; // 防止写错可以先提取结点
            auto r2left = root2->left;
            if (root1->left != nullptr && root2->left != nullptr)
            {
                // 俩树都不为空
                auto leftnode = new TreeNode(root1->left->val + root2->left->val);
                node->left    = leftnode;
                que.emplace(leftnode);
                que1.emplace(root1->left);
                que2.emplace(root2->left);
            }
            else if (root1->left == nullptr && root2->left != nullptr)
                node->left = root2->left;
            else if (root1->left != nullptr && root2->left == nullptr)
                node->left = root1->left;

            /**
             * 处理 right
             */
            if (root1->right != nullptr && root2->right != nullptr)
            {
                // 俩树都不为空
                auto rightnode = new TreeNode(root1->right->val + root2->right->val);
                node->right    = rightnode;
                que.emplace(rightnode);
                que1.emplace(root1->right);
                que2.emplace(root2->right);
            }
            else if (root1->right == nullptr && root2->right != nullptr)
                node->right = root2->right;
            else if (root1->right != nullptr && root2->right == nullptr)
                node->right = root1->right;
        }
        return root;
    }
};
// @lc code=end


class Solution_DFS_Re
{
  public:
    /**
     * DFS 递归 前序遍历
     */
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {

        // root1 == nullptr || root2 == nullptr
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        // root1 != nullptr && root2 != nullptr
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left     = mergeTrees(root1->left, root2->left);
        root->right    = mergeTrees(root1->right, root2->right);
        return root;
    }
};