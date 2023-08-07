#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


void dp_2D_array_traverse_good_first(const std::vector<int>& weights, std::vector<int>& values, const int& bagWeight)
{

    std::vector<std::vector<int>> dp(      // 初始化背包-物品数组
        weights.size(),                    // 「 i 行 」 物品数量
        std::vector<int>(bagWeight + 1, 0) // 「 j 列 」 背包容量 [0, bagWeight] 闭区间
    );

    // 「初始化」 背包容量为0的一列装不下物品，均初始化为 0
    for (int i = 0; i < weights.size(); i++)
        dp[i][0] = 0;
    // 「初始化」 第 0 行上，背包只装物品 0
    // 物品重量最小为 1 ，所以从容量为 1 的背包列开始
    for (int j = weights[0]; j <= bagWeight; j++)
        dp[0][j] = values[0];

    for (int j = 0; j <= bagWeight; j++)         // 遍历背包 「 j 列 」
    {
        for (int i = 1; i < weights.size(); i++) // 遍历物品 「 i 行
        {
            if (j < weights[i])                  // j 列的背包容量不够装下当前物品
            {
                dp[i][j] = dp[i - 1][j];         // 不装当前物品的价值
            }
            else
            {

                dp[i][j] = max(   // 取最大值
                    dp[i - 1][j], // 不装当前物品的价值
                    // 装当前物品的价值 = 去除当前重量的背包中的最大价值 + 当前价值
                    dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    for (int i = 0; i < weights.size(); i++) // 遍历物品 「 i 行 」
    {
        for (int j = 0; j <= bagWeight; j++) // 遍历背包 「 j 列 」
        {
            printf("%3d, ", dp[i][j]);
        }
        printf("\n");
    }
}
void dp_2D_array_traverse_backpack_first(const std::vector<int>& weights, std::vector<int>& values, const int& bagWeight)
{

    std::vector<std::vector<int>> dp(      // 初始化背包-物品数组
        weights.size(),                    // 「 i 行 」 物品数量
        std::vector<int>(bagWeight + 1, 0) // 「 j 列 」 背包容量 [0, bagWeight] 闭区间
    );

    // 「初始化」 背包容量为0的一列装不下物品，均初始化为 0
    for (int i = 0; i < weights.size(); i++)
        dp[i][0] = 0;
    // 「初始化」 第 0 行上，背包只装物品 0
    // 物品重量最小为 1 ，所以从容量为 1 的背包列开始
    for (int j = weights[0]; j <= bagWeight; j++)
        dp[0][j] = values[0];

    for (int i = 1; i < weights.size(); i++) // 遍历物品 「 i 行 」
    {
        for (int j = 0; j <= bagWeight; j++) // 遍历背包 「 j 列 」
        {
            if (j < weights[i])              // j 列的背包容量不够装下当前物品
            {
                dp[i][j] = dp[i - 1][j];     // 不装当前物品的价值
            }
            else
            {

                dp[i][j] = max(   // 取最大值
                    dp[i - 1][j], // 不装当前物品的价值
                    // 装当前物品的价值 = 去除当前重量的背包中的最大价值 + 当前价值
                    dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    for (int i = 0; i < weights.size(); i++) // 遍历物品 「 i 行 」
    {
        for (int j = 0; j <= bagWeight; j++) // 遍历背包 「 j 列 」
        {
            printf("%3d, ", dp[i][j]);
        }
        printf("\n");
    }
}
void dp_1D_array_traverse_good_first(const std::vector<int>& weights, std::vector<int>& values, const int& bagWeight)
{

    std::vector<int> dp( // 初始化背包-物品数组
        bagWeight + 1, 0 //  背包容量 [0, bagWeight] 闭区间
    );
    /**
     * 先遍历物品嵌套遍历背包容量
     * 不可以反过来
     * 
     * 一维数组的本质是模拟二维数组，所以按行走，不然会被覆盖
     */
    for (int i = 0; i < weights.size(); i++)          // 遍历物品
    {
        for (int j = bagWeight; j >= weights[i]; j--) // 遍历背包
        {
            dp[j] = max(                              // 取最大值
                dp[j],                                // 不装当前物品的价值
                // 装当前物品的价值 = 去除当前重量的背包中的最大价值 + 当前价值
                dp[j - weights[i]] + values[i]);
        }
        {
            for (int j = 0; j <= bagWeight; j++) // 遍历背包 「 j 列 」
                printf("%3d, ", dp[j]);
            printf("\n");
        }
    }
}
int main(int argc, char const* argv[])
{
    /**
     *       重量  价值
     * 物品0    1	15
     * 物品1	3	20
     * 物品2	4	30
     */
    std::vector<int> weights   = {1, 3, 4};    // 物品重量
    std::vector<int> values    = {15, 20, 30}; // 物品价值
    int              bagWeight = 4;            // 背包容量

    std::cout << "-- 二维数组解法: 遍历物品优先 --" << std::endl;
    dp_2D_array_traverse_good_first(weights, values, bagWeight);

    std::cout << "-- 二维数组解法: 遍历背包优先 --" << std::endl;
    dp_2D_array_traverse_backpack_first(weights, values, bagWeight);

    std::cout << "-- 一维数组解法: 遍历物品优先 --" << std::endl;
    dp_1D_array_traverse_good_first(weights, values, bagWeight);
    return 0;
}
/*
g++ -std=c++11 -Wall dynamic-programming/_01背包问题.cpp -o dynamic-programming/_01背包问题.out
./dynamic-programming/_01背包问题.out
rm dynamic-programming/_01背包问题.out
*/
