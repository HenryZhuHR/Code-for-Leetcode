#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[])
{
    auto isCircleStr = [](std::string str)
    {
        std::string temp = str;
        reverse(temp.begin(), temp.end());
        return str == temp ? true : false;
    };

    std::cout<< isCircleStr("aas") <<std::endl;
    std::string temp;
    std::cout<<temp<<std::endl;
}

/*
g++ main.cpp
a.exe
*/