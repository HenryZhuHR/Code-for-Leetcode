
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int min_str_len = strs.at(0).length();
        for (auto str : strs)
        {
            if (str.length() < min_str_len)
            {
                min_str_len = str.length();
            }
        }

        std::string str_common_prefix = "";
        for (int i = 0; i < min_str_len; i++)
        {
            char c = strs.at(0)[i];
            bool is_same = true;
            for (auto str : strs)
            {
                if (c != str[i])
                {
                    is_same = false;
                    break;
                }
            }
            if (is_same == true)
                str_common_prefix += c;
            else
            {
                break;
            }
        }

        return str_common_prefix;
    }
};
int main(int argc, char const *argv[])
{
    {
        auto now_date = std::chrono::system_clock::now(); // steady_clock
        time_t c_now_time = std::chrono::system_clock::to_time_t(now_date);
        auto time_tm = localtime(&c_now_time);
        char *str_now_time = new char[1]; // 这里应该怎么初始化？// char str_now_time[17];
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
    {
        std::vector<string> strs;
        strs.push_back("flower");
        strs.push_back("flow");
        strs.push_back("flight");
        for (auto str : strs)
            std::cout << str << ",";
        std::cout << std::endl;
        auto sln = new Solution();
        std::cout << sln->longestCommonPrefix(strs) << std::endl;
    }
    return 0;
}
