#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int         n = a.length() > b.length() ? a.length() : b.length();
        std::string result;
        result.reserve(n);

        for (auto x : a)
            std::cout << x << " ";
        std::cout << std::endl;
    }
};

int main(int argc, char const* argv[])
{
    Solution sln = Solution();

    {
        std::vector<int> nums{1, 2, 9};
        // for (auto x : nums)
        //     std::cout << x << " ";
        // std::cout << std::endl;
        std::string a = "1010", b = "1011";

        auto ret = sln.addBinary(a, b);

        std::cout << " output:" << ret << std::endl;
    }
}

/*
g++ main.cpp
a.exe
*/