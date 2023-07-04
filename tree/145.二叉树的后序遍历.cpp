/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (76.28%)
 * Likes:    1053
 * Dislikes: 0
 * Total Accepted:    639K
 * Total Submissions: 837.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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

class Solution
{
  public:
    void Traversal(TreeNode* node, vector<int>& nums)
    {
        if (node == nullptr)
            return;
        Traversal(node->left, nums);
        Traversal(node->right, nums);
        nums.push_back(node->val);
    }

    vector<int> postorderTraversal_Iteration(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int>      res;
        TreeNode*        prev = nullptr; // 用来记录上一节点
        while (!st.empty() || root)
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }


            /**
             * 主要就是判断出来的是不是右子树，是的话就可以把根节点=加入到list了
             *       root
             *      |    |
             *    left  [ ] (遍历到最下面的 left 结点)
             *   |    |
             * null1  null2
             */

            root = st.top(); // 这时候遍历到 null1， 所以取出上一层的 left ( root = left )
            st.pop();

            /**
             * prev 初始值为 null
             * 主要是这个避免重复的标记,
             *
             * root.right == null 表示当前节点为根节点
             * root.right == prev 如果右子树是上一次处理的节点则处理根节点
             *
             *  右结点空 或者 右结点已经处理过了
             */
            if (root->right == prev || root->right == nullptr)
            {
                res.emplace_back(root->val);
                prev = root; // 标记该结点，说明已经处理过了
                root = nullptr;
            }
            /**
             * 右子树不为空，左子树找到根, 根找到右子树，先处理右子树
             */
            else
            {
                st.push(root); // 重新把根节点入栈，处理完右子树还要回来处理根节点
                root = root->right;
            }
        }
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        return postorderTraversal_Iteration(root);
        vector<int> nums;
        Traversal(root, nums);
        return nums;
    }
};
// @lc code=end
