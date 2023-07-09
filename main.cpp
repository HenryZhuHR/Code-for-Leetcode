#include <chrono>
#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;


void test()
{
    printf("size of data type:\n");
    printf("int         : %lu byte\n", sizeof(int));           // 4 byte
    printf("short       : %lu byte\n", sizeof(short int));     // 2 byte
    printf("long        : %lu byte\n", sizeof(long int));      // 8 byte
    printf("long long   : %lu byte\n", sizeof(long long int)); // 8 byte
}


vector<int> nextGreaterElement(vector<int>& nums)
{

    vector<int> ans(nums.size()); // 存放答案的数组
    vector<int> st(nums.size());
    int         top = -1;

    /**
     * 2, 1, 2, 4, 3
     */


    for (int i = nums.size() - 1; i >= 0; i--) // 倒着往栈里放
    {
        int n = nums[i];
        while (top >= 0 && n >= st[top]) // 栈 非空
        {
            top--;
        }
        if (top < 0)
            ans[i] = -1;
        else
            ans[i] = st[top];
        top++;
        st[top] = n;
    }

    return ans;
}

int main(int argc, char const* argv[])
{
    test();
    vector<int> nums = {2, 1, 2, 4, 3};

    for (auto n : nums)
        printf("%d, ", n);
    printf("\n");

    for (auto n : nextGreaterElement(nums))
        printf("%d, ", n);
    printf("\n");

    return 0;
}
