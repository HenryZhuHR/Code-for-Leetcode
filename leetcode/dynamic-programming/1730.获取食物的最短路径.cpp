#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
using namespace std;

// 你现在很饿，想要尽快找东西吃。你需要找到最短的路径到达一个食物所在的格子。

// 给定一个 m x n 的字符矩阵 grid ，包含下列不同类型的格子：

// '*' 是你的位置。矩阵中有且只有一个 '*' 格子。
// '#' 是食物。矩阵中可能存在多个食物。
// 'O' 是空地，你可以穿过这些格子。
// 'X' 是障碍，你不可以穿过这些格子。
// 返回你到任意食物的最短路径的长度。如果不存在你到任意食物的路径，返回 -1。

#define BIRT '*'
#define FOOD '#'
#define FREE 'O'
#define WALL 'X'
class Solution {
  public:
    int getFood(vector<vector<char>>& grid) {
        queue<pair<int, int>> que;
        int                   m = grid.size();
        int                   n = grid[0].size();
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j] == BIRT) {
                    que.push({i, j});  // 出生点入队
                    grid[i][j] = WALL; // 标记出生点为墙，不可访问
                    break;
                }
            }
        }
        int step            = 0;
        int direction[4][2] = {
            {1, 0},  // 右
            {0, 1},  // 下
            {-1, 0}, // 左
            {0, -1}  // 上
        };
        while (!que.empty()) {
            int que_size = que.size();
            while (que_size--) {
                auto point = que.front();
                que.pop();
                auto x = point.first;
                auto y = point.second;
                for (auto d_i = 0; d_i < 4; d_i++) { // d_i : direction id
                    int i = x + direction[d_i][0];
                    int j = y + direction[d_i][1];
                    if ((i < 0) || (i >= m) || (j < 0) || (j >= n) || (grid[i][j] == WALL)) // 如果越界或遇到墙
                        continue;
                    if (grid[i][j] == FOOD) // 如果到达食物
                        return step + 1;
                    grid[i][j] = WALL; // 标记为墙，表示已访问，省下 visited 空间
                    que.push(std::pair<int, int>{i, j});
                }
            }
            step += 1;
        }
        return -1;
    }
};