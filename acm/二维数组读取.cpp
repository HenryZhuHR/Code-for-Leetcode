#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
    /**
     * 二维数组读取
     * 1. 读取行数和列数
     * 2. 读取二维数组
     * 示例
     * 2 3
     * 1,2,3
     * 4,5,6
     */
    int m; // 接收行数
    int n; // 接收列数

    cin >> m >> n;
    vector<vector<int>> matrix(m);

    for (int l = 0; l < m; l++)
    {
        string s;
        std::cin >> s;
        vector<int> vec;
        int         left = 0, right = 0; // 用于接收每个字符
        while (left < s.size())
        {
            right = left;
            while (s[right] != ',' && right < s.size())
            { 
                right++;
            }
            // string 转 int #include <string>
            vec.push_back(std::stoi(s.substr(left, right - left)));
            left = right + 1;
        }
        matrix[l] = vec;
        vec.clear();
    }
    std::cout << "二维数组：" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;


    {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }


        std::cout << "数组为：" << std::endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
