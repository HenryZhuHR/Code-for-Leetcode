/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (57.53%)
 * Likes:    1349
 * Dislikes: 0
 * Total Accepted:    512.8K
 * Total Submissions: 891.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 *
 * 本题中，一棵高度平衡二叉树定义为：
 *
 *
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
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
     * 求高度，自底向上 ( 自底向上的递归就是及时止损; 自顶向下的递归就是不管三七二十一先把所有的高度算一遍 )
     * 
     * 迭代法效率很低
     *
     * 自底向上递归的做法类似于后序遍历，
     * 对于当前遍历到的节点，先递归地判断其左右子树是否平衡，
     * 再判断以当前节点为根的子树是否平衡。
     *
     * 如果一棵子树是平衡的，则返回其高度（高度一定是非负整数），否则返回 −1。
     * 如果存在一棵子树不平衡，则整个二叉树一定不平衡。
     */
    int getHeight(TreeNode* root)
    {
        if (root == nullptr)
            return 0; // 如果是空，那么高度为0

        /**
         *   0
         *  / \
         * 0   0
         * 如果是叶子结点，那么 leftHeight rightHeight 都是0
         */
        int leftHeight  = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) > 1)          // 如果高度差 >1 / >=2 ，返回 -1 ，表示 false
            return -1;
        else if (leftHeight == -1 || rightHeight == -1) // 如果子树存在高度差大于 1 的情况，返回 -1 ，表示 false
            return -1;
        else
        {
            /**
             *      0
             *    /   \
             *   0      0
             *  / \    / \
             * 0   0  0   0
             *
             * 返回 左子树 和 右子树 中最大高度
             *   0
             *  / \
             * 0   0
             * 因为如果 root 是 null ，那么上一个结点
             */
            // return max(lh,rh)+1
            return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // 三元运算符加括号
        }
    }

    bool isBalanced(TreeNode* root)
    {
        // printf("%d\n", getHeight(root));
        return getHeight(root) >= 0;
    }
};
// @lc code=end
