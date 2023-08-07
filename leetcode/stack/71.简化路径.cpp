/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 *
 * https://leetcode.cn/problems/simplify-path/description/
 *
 * algorithms
 * Medium (44.20%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    185.4K
 * Total Submissions: 419.3K
 * Testcase Example:  '"/home/"'
 *
 * 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。
 *
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..）
 * 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。
 * 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。
 *
 * 请注意，返回的 规范路径 必须遵循下述格式：
 *
 *
 * 始终以斜杠 '/' 开头。
 * 两个目录名之间必须只有一个斜杠 '/' 。
 * 最后一个目录名（如果存在）不能 以 '/' 结尾。
 * 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
 *
 *
 * 返回简化后得到的 规范路径 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：path = "/home/"
 * 输出："/home"
 * 解释：注意，最后一个目录名后面没有斜杠。
 *
 * 示例 2：
 *
 *
 * 输入：path = "/../"
 * 输出："/"
 * 解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
 *
 *
 * 示例 3：
 *
 *
 * 输入：path = "/home//foo/"
 * 输出："/home/foo"
 * 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
 *
 *
 * 示例 4：
 *
 *
 * 输入：path = "/a/./b/../../c/"
 * 输出："/c"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * path 由英文字母，数字，'.'，'/' 或 '_' 组成。
 * path 是一个有效的 Unix 风格绝对路径。
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
  public:
    string simplifyPath(string path)
    {
        path += "/";//如果最后没有 / 补上 统一一下
        int len = path.length();


        stack<string> path_stack;

        int i = 0;
        while (i < len && path[i] == '/')
            i++;
        i--;
        int j = i + 1;
        while (j < len)
        {
            if (path[j] == '/')
            {

                string sub_str = path.substr(i + 1,    // 起始位置
                                             j - i - 1 // 子串长度
                );
                printf("(%d, %d): %s\n", i, j, sub_str.c_str());
                if (sub_str == ".")
                {
                }
                else if (sub_str == "..")
                {
                    if (!path_stack.empty())
                        path_stack.pop();
                }
                else
                {
                    path_stack.push(sub_str);
                }
                while (path[j] == '/' && j < len)
                    j++;
                if (j == len - 1)
                    break;
                j--;
                i = j;
            }

            j++;
        }

        stack<string> new_path_stack;
        while (!path_stack.empty())
        {
            new_path_stack.push(path_stack.top());
            path_stack.pop();
        }


        
        string ans = "/";
        while (!new_path_stack.empty())
        {
            ans += new_path_stack.top();
            new_path_stack.pop();
            ans += "/";
        }
        printf("\n");
        if (ans.length() > 1)
            ans = ans.substr(0, ans.length() - 1);
        return ans;
    }
};
// @lc code=end
