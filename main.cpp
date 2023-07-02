#include <chrono>
#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;


void test()
{
    printf("size of data type:\n");
    printf("int         : %lu byte\n", sizeof(int));           // 4 byte
    printf("short       : %lu byte\n", sizeof(short int));     // 2 byte
    printf("long        : %lu byte\n", sizeof(long int));      // 8 byte
    printf("long long   : %lu byte\n", sizeof(long long int)); // 8 byte
}

/**
 * 求解 next https://www.bilibili.com/video/BV1AY4y157yL/?spm_id_from=333.337.search-card.all.click&vd_source=315df467e91f6e808c3c3aa7377cbfa7
 * 1 先检查前后缀不同的情况
 * 2 再检查前后缀相同的情况
 * 3 更新当前的 next[i]
 */
void getNext(vector<int>& next, const string& s)
{
    int j   = 0;
    next[0] = j;
    for (int i = 1; i < s.length(); i++) // 从 1 开始，因为 单个字符一定是0
    {
        /**
         * 前后缀不相同
         * idx:  0 1 2  3  4 5 6
         * str: (a b a) c (a b a）[b]
         * next:     1         3
         * 当前情况下，next[6]=3
         * 那么新增 b 进来，是和 next[3] 不一样，也就是说，新增的不能不能匹配，则需要回退
         * 我们可以知道 前一个步骤中， (a b a)/(a b a) 最长
         * 这时候基于上一次最长的结果 ，在前缀中找，因为 (a b a) 最长为 sublen=1 之前计算过了
         * 所以需要从 a (下标 sublen-1)开始找
         * 然后检查下一个是否相同 ，也就是 next[1] next[7]，其实就回到了
         * idx:  0  1 2 3 4 5  6  7
         * str: (a) b a c a b (a) [b]
         * next: 1
         */
        while (s[j] != s[i] && j > 0)
        {
            j = next[j - 1];
        }
        /**
         * 前后缀相同
         * idx:  0 1  2 3  4 5
         * str: (a b) a c (a b) [a]
         * next:             2
         * 当前情况下，next[5]=2
         * 那么新增 a 进来，是和 next[2] 一样，那么直接加
         *
         */
        if (s[j] == s[i])
        {
            j++;
        }
        /**
         * 更新 next[i]
        */
        next[i] = j;
    }
}
int main(int argc, char const* argv[])
{
    test();
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    string      s    = "aabaaf";
    vector<int> next(s.length());
    getNext(next, s);
    for (auto n : next)
        printf("%d,", n);
    printf("\n");
    return 0;
}
