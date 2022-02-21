#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            printf("i=%d : ", i);

            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
            }
            for (auto x : nums)
                std::cout << x << " ";
            std::cout << std::endl;
            i++;
        }
        return n;
    }
};

int main(int argc, char const *argv[])
{
    {
        auto now_date = std::chrono::system_clock::now(); // steady_clock
        time_t c_now_time = std::chrono::system_clock::to_time_t(now_date);
        auto time_tm = localtime(&c_now_time);
        char *str_now_time = new char[1]; // XXX: 这里应该怎么初始化？// char str_now_time[17];
        sprintf(str_now_time,
                "%d-%02d-%02d %02d:%02d:%02d",
                time_tm->tm_year + 1900,
                time_tm->tm_mon + 1,
                time_tm->tm_mday,
                time_tm->tm_hour,
                time_tm->tm_min,
                time_tm->tm_sec);
        std::cout << str_now_time << std::endl;
        delete[] str_now_time;
    }
    Solution sln = Solution();
    {
        std::vector<int> nums{3, 2, 2, 3};
        int val = 3;
        int len = sln.removeElement(nums, val);
        std::cout << len << ": " ;
        for (int i = 0; i < len; i++)
        {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
