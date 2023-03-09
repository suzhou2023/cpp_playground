#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组

void my_func(const int num_arr[], const int len, const int target)
{
  int sum = 0;
  int l = 0, r = 0;
  int min_len = INT_MAX;
  while (r < len)
  {
    sum += num_arr[r];

    while (sum >= target)
    {
      min_len = min<int>(r - l + 1, min_len);
      sum -= num_arr[l];
      l++;
    }

    r++;
  }

  cout << (min_len == INT_MAX ? 0 : min_len) << endl;
}

int main()
{
  // int num_arr[] = {2, 3, 1, 2, 4, 3};
  // const int target = 7;

  // int num_arr[] = {1, 4, 4};
  // const int target = 4;

  int num_arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  const int target = 11;

  my_func(num_arr, sizeof(num_arr) / sizeof(int), target);
}
