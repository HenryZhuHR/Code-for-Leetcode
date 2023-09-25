#include <iostream>
#include <vector>
#include <sstream>
#include <string>
/**
 * cin以空格、tab、换行符作为分隔符
 * cin从第一个非空格字符开始读取，直到遇到分隔符结束读取
 */
int main(int argc, char const* argv[])
{
    std::string line;

    // 逐行读取输入
    while (std::getline(std::cin, line))
    {
        std::vector<int>   integers;
        std::istringstream iss(line);

        int num;
        while (iss >> num)
        {
            integers.push_back(num);
        }

        // 现在 integers 中包含了一行中的整数
        // 您可以在这里处理整数，例如计算它们的总和或执行其他操作
        int sum = 0;
        for (int i : integers)
        {
            sum += i;
        }

        std::cout << sum << std::endl;
    }
    return 0;
}
