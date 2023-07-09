/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (37.00%)
 * Likes:    2076
 * Dislikes: 0
 * Total Accepted:    739.1K
 * Total Submissions: 2M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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
class Solution
{
  public:
    /**
     * 中序遍历
     * 如果该二叉树的[左子树][不为空]，则[左子树]上[所有节点的值][均小于]它的[根节点的值]；
     * 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
     */
    bool isValidBST(TreeNode* root) { 
        
        // return helper(root, LONG_MIN, LONG_MAX);
         }
    /**
     * [mixval, maxVal]
     */
    bool helper(TreeNode* root, long long minVal, long long maxVal)
    {
        // 空结点
        if (root == nullptr)
            return true;

        if (!(root->val > minVal && root->val < maxVal))
            return false;

        return helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal);
    }
};
// @lc code=end
