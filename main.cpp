#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;


int lengthOfLongestSubstring(string s)
{
    auto PrintSet = [](std::unordered_set<char> set)
    {
        std::cout << " -- ";
        for (auto x : set)
            std::cout << x << " ";
        std::cout << std::endl;
    };

    auto n = s.length();
    if (n <= 1)
        return n;

    // unordered set
    std::unordered_set<char> lookup(n);
    // left & right pointer
    int pleft = 0, pright = 0;
    int max_len = 0;
    while (pright < n)
    {
        std::cout << "=================" << std::endl;
        std::cout << pright << " - " << s[pright] << ": " << std::endl;
        PrintSet(lookup);


        // auto is_char_in_lookup = lookup.count(s[pright]);
        // std::cout << "count:" << is_char_in_lookup << "  ";
        std::cout << lookup.count(s[pright]) << std::endl;
        while (lookup.find(s[pright]) != lookup.end())
        {
            lookup.erase(s[pleft]);
            pleft++;
        }
        PrintSet(lookup);


        max_len = (pright - pleft + 1) > max_len ? (pright - pleft + 1) : max_len;
        lookup.insert(s[pright]);
        pright++;
    }
    return max_len;
}

int main(int argc, char const* argv[])
{
    auto n = lengthOfLongestSubstring("abcabcbb");
    std::cout << n << std::endl;
}

/*
g++ main.cpp
a.exe
*/