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

        vector<int>      res;
        stack<TreeNode*> st;
        TreeNode*        prev = nullptr;


        while (!st.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                st.emplace(root);
                root = root->left;
            }
            /**
             * 找到最左侧的空
             * 返回上一层的结点，这时候，左已经遍历了
             * 然后先遍历右，再 中
             *  (0)
             *  / \
             * _   0
             */
            root = st.top();
            st.pop();

            /**
             * 但是右不知道是不是遍历过，所以之前定义一个 prev 判断
             * 如果 [右结点空] 或者 [右结点已经遍历过(标记 prev)]，就返回当前的结点
             *  (0)     (0)
             *  / \     / \
             * _   _   _  [p]
             * 如果没有，那就遍历右，
             */
            if (root->right == nullptr || root->right == prev)
            {
                res.emplace_back(root->val);
                prev = root; // 标记当前结点
                root = nullptr;
            }
            else
            {
                st.emplace(root); // 当前结点入st 先处理右
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
