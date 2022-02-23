#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    int maxSubArray(vector<int>& nums)
    {

        int max = 0;
        for (int winwidth = 1; winwidth <= nums.size(); winwidth++)
        {
            for (int i = 0; i < winwidth; i++)
            {
                int sum = 0;
                for (int j = i; j < i + winwidth; j++)
                    sum += nums[j];
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

int main(int argc, char const* argv[])
{
    Solution sln = Solution();

    {
        std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};


        auto ret = sln.maxSubArray(nums);

        // for (auto x : nums)
        //     std::cout << x << " ";
        // std::cout << std::endl;
        std::cout << " output:" << ret << std::endl;
    }
}

/*
g++ main.cpp
a.exe
*/