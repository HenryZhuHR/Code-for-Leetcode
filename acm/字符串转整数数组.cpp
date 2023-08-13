#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const* argv[])
{
    /**
     * 字符串转整数数组
     * 1. 读取字符串
     * 2. 读取整数数组
     * 示例
     * 1,2,3,4,5
     */
    string str;
    getline(cin, str);

    vector<int> strs;

    int left = 0;
    for (int right = 0; right < str.size(); right++)
    {
        left = right;
        while (str[left] != ',' && left < str.size())
        {
            left++;
        }
        string tmp = str.substr(right, left - right);
        strs.push_back(stoi(tmp));
        right = left;
    }


    return 0;
}
