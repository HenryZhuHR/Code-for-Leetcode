/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.11%)
 * Likes:    1044
 * Dislikes: 0
 * Total Accepted:    290.4K
 * Total Submissions: 402.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
     * 二叉树的定义
     *   3
     *  / \
     * 9  20
     *    / \
     *   15  7
     * inorder   = [9, 3,15,20, 7] 左中右
     *              左 中 右
     * postorder = [9,15, 7,20, 3] 左右中
     *              左 右       中
     *
     * 1 postorder 最后一个元素是 root
     * 2 在 inorder 中找到 root ，然后分割 leftInorder, rightInorder
     * 递归
     * 4 根据根节点的位置确定左子树和右子树在中序数组和后续数组中的左右边界位置
     * 5 递归构造左子树和右子树
     * 6 返回根节点结束
     */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0)
            return nullptr;
        else
            return buildSubTree(inorder, postorder);
    }

    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0)
            return nullptr;

        int       root_val = postorder[postorder.size() - 1];
        TreeNode* root     = new TreeNode(root_val);

        /**
         *              0  1  2  3  4
         * inorder   = [9, 3,15,20, 7] 左中右
         *              左 中 右
         * postorder = [9,15, 7,20, 3] 左右中
         *              左 右       中
         */
        int mid_i = 0;
        while (mid_i < postorder.size())
        {
            if (inorder[mid_i] == root_val)
                break;
            mid_i++;
        }

        // 分割左右子树 Inorder
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid_i);
        vector<int> rightInorder(inorder.begin() + mid_i + 1, inorder.end());

        // 分割左右子树  Postorder
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);

        root->left  = buildSubTree(leftInorder, leftPostorder);
        root->right = buildSubTree(rightInorder, rightPostorder);

        return root;
    }
};
// @lc code=end
