#include <chrono>
#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution
{
  public:
    bool isPerfectSquare(int x)
    {
        if (x == 1)
            return true;
        int pl = 1, pr = x;
        while (pl <= pr)
        {
            int pm = pl + (pr - pl) / 2;

            if (x / pm == pm)
            {
                if (x % pm == 0)
                {
                    return true;
                }
                else
                {
                    pl = pm + 1;
                }
            }
            else if (x / pm < pm)
            {
                pr = pm - 1;
            }
            else
            {
                pl = pm + 1;
            }
        }
        return false;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution    sln  = Solution();
    cout << sln.isPerfectSquare(4) << endl;
    cout << sln.isPerfectSquare(5) << endl;
    cout << sln.isPerfectSquare(6) << endl;
    cout << sln.isPerfectSquare(8) << endl;
    cout << sln.isPerfectSquare(16) << endl;
}
