#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
  public:
    vector<int> plusOne(vector<int>& digits) {}
};

int main(int argc, char const* argv[])
{
    Solution sln = Solution();

    {
        std::vector<int> digits{1, 2, 3};
        auto             ret = sln.plusOne(digits);

        // for (auto x : nums)
        //     std::cout << x << " ";
        // std::cout << std::endl;
        // std::cout << " output:" << ret << std::endl;
    }
}

/*
g++ main.cpp
a.exe
*/