/**
 * 28.找出字符串中第一个匹配项的下标.cpp
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * 求解 next https://www.bilibili.com/video/BV1AY4y157yL/?spm_id_from=333.337.search-card.all.click&vd_source=315df467e91f6e808c3c3aa7377cbfa7
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * 求解 next https://www.bilibili.com/video/BV16X4y137qw/?vd_source=315df467e91f6e808c3c3aa7377cbfa7
 */
void getNext(vector<int>& next, const string& s)
{
    /**
     * 初始化第一个值
     */
    int j   = 0; // j 表示上一个 i 子串的最长公共前后缀
    next[0] = j;
    // next[0]赋值过了，从1 开始
    for (int i = 1; i < s.length(); i++)
    {
        /**
         * 如果新增的不匹配
         *  0 1 2  3  4 5 6   7
         * (a b a) c (a b a) [b]
         *  0 0 1  0  1 2 3
         *  j = 3  表示上一个 next[i-1=6] 最长xxx
         *  i = 7
         *  next[3] c != next[7] b
         * 所以回退，也就是查找 (a b a)最长xx a ，然后再看 ab  ab 是否一样
         * j = next[3-1] = 1 ,下标从0 开始，所以 (长度 -1)  才是 next[2]
         * 查看 next[1] b  是不是和 next[7] b 一样，一样，结束循环，
         */
        while (j > 0 && s[i] != s[j])
        {
            j = next[j - 1]; // j 表示长度，那么下标从0 开始，所以 (长度 -1)  才是 next[2]
        }
        /**
         * j = next[3-1] = 1
         * 如果新增的是匹配的
         *  0 1  2 3 4 5  6 7
         * (a b) a c a b (a b)
         *  0 0 1  0  1 2 3
         * j++ ->  2 ，那么长度就是 2
         */
        if (s[i] == s[j])
        {
            j++;
        }
        /**
         * 更新 next[i]
         */
        next[i] = j;
    }
}

/**
 * KMP 算法 https://programmercarl.com/0028.实现strStr.html#其他语言版本
 *
 * next数组就是一个前缀表（prefix table）。
 */
int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }
    /**
     * 计算 needle 的前缀表
     */
    vector<int> next(needle.length()); // 前缀表
    getNext(next, needle);

    int j = 0; // 模式串索引
    for (int i = 0; i < haystack.length(); i++)
    {
        /**
         * a b a c a b a
         * 0 0 1 0 1 2 3
         *
         * c a b a b a c a b a
         *   a b a c a b a
         *       a b a c a b a
         * 其实是移动 needle
         */
        while (j > 0 && haystack[i] != needle[j]) // j > 0  如果 j=0 next[0]-0，也就是回到开头，就没有匹配的，所以不再匹配
        {
            /**
             * a b a c a b a
             * 0 0 1 0 1 2 3
             *
             * 如果遇到不匹配的情况，查看前一个最长 xxx
             * 0  1 2 3  4 5 6 7 8 9
             * c [a b a] b a c a b a
             *   [a b a] c a b a
             *    x   x
             *        a  b a c a b a 下一次比较，从 needle 的 b 开始比较
             * needle[4] 不匹配了，就需要查看跳过多少
             * 跳过的数值，就是匹配过 最长 也就是 j 回到 1-1 ,从 a 开始
             */
            j = next[j - 1];
        }
        if (haystack[i] == needle[j])
        {
            j++;
        }
        if (j == next.size()) // 匹配成功
            return i - next.size() + 1;
    }
    return -1;
}
