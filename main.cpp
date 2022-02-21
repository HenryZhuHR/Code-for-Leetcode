#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int window_len = needle.length();
        if (window_len == 0)
            return window_len;
        int left = 0;
        for (; left + window_len <= haystack.length(); left++)
        {
            bool isSame = true;
            for (int i = left; i < left + window_len; i++)
            {
                if (haystack[i] !=needle[i-left])
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                return left;
        }

        return -1;
    }
};

int main(int argc, char const* argv[])
{
    Solution sln = Solution();

    std::string haystack = "a";
    std::string needle   = "a";

    int len = sln.strStr(haystack, needle);
    std::cout << len << std::endl;

    return 0;
}

/*
g++ main.cpp
a.exe
*/