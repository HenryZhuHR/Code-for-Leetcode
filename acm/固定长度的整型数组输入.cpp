#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    /**
     * 固定长度的整型数组输入
     * 示例输入：
     * 5
     * 1 2 3 4 5
    */
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }


    std::cout << "数组为：";
    for (int i = 0; i < n; ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
