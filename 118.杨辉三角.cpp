/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    void PintList(vector<vector<int>> nums)
    {
        std::cout << "[";
        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < nums[i].size(); j++)
            {
                std::cout << nums[i][j];
                if (j < nums[i].size() - 1)
                    std::cout << ",";
            }
            std::cout << "]";
            if (i < nums.size() - 1)
                std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }


    vector<vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>>ans(numRows);
        ans[0] = std::vector<int>{1};
        this->PintList(ans);

        for (int i = 1; i < numRows; i++)
        {
            /**
             *  i  = 0, 1, 2, 3, 4
             * len = 1, 2, 3, 4, 5
            */
            ans[i] = std::vector<int>(i+1,1);
            for (int j = 1; j < i; j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                
            }
            this->PintList(ans);   
        }
        return ans;
    }
};
// @lc code=end
