#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
  public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i]++;
            if (digits[i] > 9)
                digits[i] = 0;
            else
                return digits;
        }
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main(int argc, char const* argv[])
{
    Solution sln = Solution();

    {
        std::vector<int> nums{1,2,9};
        for (auto x : nums)
            std::cout << x << " ";
        std::cout << std::endl;

        auto ret = sln.plusOne(nums);

        for (auto x : nums)
            std::cout << x << " ";
        std::cout << std::endl;
        // std::cout << " output:" << ret << std::endl;
    }
}

/*
g++ main.cpp
a.exe
*/