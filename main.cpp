
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

template <typename T, typename... U>
void print(T t, U... u)
{
    std::cout << t << " ";
    print(u...);
}

template <typename T, typename... U>
void println(T t, U... u)
{
    // constexpr sizeof...(u) dynamically evaluates to the number of arguments in run-time
    if (sizeof...(u) == 0) // keyword constexpr only in C++17
    {
        std::cout << t << std::endl;
    }
    else
    {
        std::cout << t << " ";
        println(u...);
    }
}

class Solution
{
public:
    bool isValid(string s)
    {
        auto print_stack = [](std::stack<int> stk)
        {
            std::cout << "stack:";
            while (!stk.empty())
            {
                std::cout << " " << stk.top();
                stk.pop();
            }
            std::cout << std::endl;
        };
        if (s.size() % 2 != 0)
            return false;

        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        std::stack<int> char_stack;
        print_stack(char_stack);
        char_stack.emplace(1);
        char_stack.emplace(1);
        char_stack.emplace(2);
        print_stack(char_stack);

        return true;
        for (char c : s)
        {
            if (pairs.count(c) > 0)
            {
                if (char_stack.empty() || pairs[c] != char_stack.top())
                    return false;
                else
                    char_stack.pop();
            }
            else
            {
                char_stack.push(c);
            }
        }
        return char_stack.empty();
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
        string s = "(){}}{";
        auto sln = Solution();
        bool is_match = sln.isValid(s);
        std::cout << "isValid:" << is_match << std::endl;
    }
    return 0;
}
