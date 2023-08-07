/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int sorted[m + n];
        int i = 0, j = 0;
        int s = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                sorted[s] = nums1[i];
                i++;
            }
            
            else
            {
                sorted[s] = nums2[j];
                j++;
            }
            s++;
        }
        if (i < m)
        {
            while (i < m)
            {
                sorted[s] = nums1[i];
                i++;
                s++;
            }
        }
        else
        {
            while (j < n)
            {
                sorted[s] = nums2[j];
                j++;
                s++;
            }
        }

        for (s = 0; s < m + n; s++)
        {
            nums1[s] = sorted[s];
        }
    }
};
// @lc code=end
