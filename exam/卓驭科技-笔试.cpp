/**
 * 【卓驭科技】 2024秋季校园招聘-笔试邀请函
 * 
*/
#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string str;
  int left = 0;
  int right = 0;
  std::cin >> str;
  std::vector<int> nums;
  int i = 0;
  for (int j = 1; j < str.size() - 1; j++)
  {
    if (str[j] == ',')
    {
      std::string c = str.substr(i + 1, j - i + 1);
      int n = std::stoi(c);
      nums.push_back(n);
      i = j;
    }
    else
      continue;
  }

  for (auto n : nums)
    printf("%d ", n);
  printf("\n");

  return 0;
}
/*
rm a.out
g++ main.cpp -std=c++11
./a.out
[1,8,6,2,5,4,8,3,7]
*/