#include <iostream>
#include <vector>
int main(int argc, char const* argv[])
{
    /**
     * 不固定长度的整型数组输入
     * 示例输入：
     * 1 2 3 4 5
     */
    std::vector<int> nums;
    int              num;
    while (std::cin >> num)
    {
        nums.push_back(num);

        // 读到换行符，终止循环
        if (getchar() == '\n') // 或者 if (std::cin.get() == '\n')
            break;
    }


    std::cout << "数组为：";
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
