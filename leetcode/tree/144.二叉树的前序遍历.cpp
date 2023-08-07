/* [144] 二叉树的前序遍历
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
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
    /**
     * 递归遍历
     */
    vector<int> preorderTraversal_Recursive(TreeNode* root)
    {
        vector<int> nums;
        preorderTraversal_RecursiveProcess(root, nums);
        return nums;
    }
    void preorderTraversal_RecursiveProcess(TreeNode* node, vector<int>& nums)
    {
        if (node == nullptr)
        {
            return;
        }
        nums.push_back(node->val); // 中
        preorderTraversal_RecursiveProcess(node->left, nums);
        preorderTraversal_RecursiveProcess(node->right, nums);
    }

    /**
     * 迭代遍历 模拟栈
     *
     * 前序遍历： 中 左 右
     * 入栈顺序： 中 右 左
     */
    vector<int> preorderTraversal_Iteration(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        /**
         * 非递归遍历二叉树，我们一定要能“回到上一个节点“。
         * 模拟递归过程，我们使用栈存储我们已经遍历过的节点。
         */
        stack<TreeNode*> st;
        TreeNode*        node = root;
        /**
         * 循环条件需要注意，root为空时当前树完了，但不代表整棵树完了，栈中还有节点要访问。
         */
        while (node || !st.empty())
        {
            /**
             * 当前结点入栈
             * 不断遍历到达最左端的叶子结点
             */
            while (node)
            {
                res.push_back(node->val); // 中
                st.push(node);
                node = node->left;        // 左
            }
            node = st.top();
            st.pop();
            node = node->right; // 右
        }
        return res;
    }

    /**
     * Morris 遍历:  这种方法由 J. H. Morris 在 1979 年的论文「Traversing Binary Trees Simply and Cheaply」中首次提出，因此被称为 Morris 遍历。
     * Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其前序遍历规则总结如下：
     *
     * 1. 新建临时节点，令该节点为 root；
     * 2. 如果当前节点的左子节点为空，将当前节点加入答案，并遍历当前节点的右子节点；
     * 3. 如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点：
     *
     */
    vector<int> preorderTraversal(TreeNode* root)
    {
        // return preorderTraversal_Recursive(root);
        return preorderTraversal_Iteration(root);
    }
};
// @lc code=end
