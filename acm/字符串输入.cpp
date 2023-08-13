
#include <iostream>
#include <string>
#include <vector>
int main()
{
    /**
     * 给定一行字符串，每个字符串用空格间隔，一个样例为一行
     * 例如：
     * hello world
     * world hello
    */
    std::string              str;
    std::vector<std::string> strs;
    while (std::cin >> str)
    {
        strs.push_back(str);
        if (getchar() == '\n')
        { // 控制测试样例
            for (auto& str : strs)
            {
                std::cout << "当前单词：" << str << " ";
            }
            std::cout << std::endl;
            strs.clear();
        }
    }
    return 0;
}