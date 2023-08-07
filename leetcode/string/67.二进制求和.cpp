/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b)
    {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        int n;
        n = a.length() > b.length() ? a.length() : b.length();
        std::string ans;

        int carry = 0;
        for (auto x : a)
            std::cout << x << " ";
        std::cout << std::endl;
        for (auto x : b)
            std::cout << x << " ";
        std::cout << std::endl;
        std::cout << std::endl;
        int i = 0;
        int j = 0;
        while (i < a.length() && j < b.length())
        {
            char temp = a[i] + b[j] + carry - '0';
            carry     = 0;
            if (temp > '1')
            {
                carry = 1;
                temp -= 2;
            }
            ans += temp;
            i++;
            j++;
        }
        while (i < a.length())
        {

            char temp = a[i] + carry;
            carry     = 0;
            if (temp > '1')
            {
                carry = 1;
                temp -= 2;
            }
            ans += temp;
            i++;
        }
        while (j < b.length())
        {
            char temp = b[j] + carry;
            carry     = 0;
            if (temp > '1')
            {
                carry = 1;
                temp -= 2;
            }
            ans += temp;
            j++;
        }
        if (carry)
            ans += '1';
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

