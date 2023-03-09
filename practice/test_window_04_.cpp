#include <iostream>
#include <set>

using namespace std;

// 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，
// 使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
// 如果存在则返回 true，不存在返回 false。

// 示例 1：
// 输入：nums = [1,2,3,1], k = 3, t = 0
// 输出：true
// 示例 2：
// 输入：nums = [1,0,1,1], k = 1, t = 2
// 输出：true
// 示例 3：
// 输入：nums = [1,5,9,1,5,9], k = 2, t = 3
// 输出：false

void my_func(const int num_arr[], const int len, const int k, const int t)
{
  int l = 0, r = 0;
  set<int> set;

  while (r < len)
  {
    int min, max;
    if (set.size() > 0)
    {
      min = *set.begin();
      max = *set.rbegin();
      if (num_arr[r] <= min - t || num_arr[r] > max + t)
      {
        cout << "true" << endl;
        return;
      }
    }

    set.insert(num_arr[r]);

    // 缩小窗口
    while (r - l >= k)
    {
      set.erase(num_arr[l]);
      l++;
    }

    r++;
  }

  cout << "false" << endl;
}

int main()
{
  // int num_arr[] = {1, 2, 3, 1};
  // const int k = 3;
  // const int t = 0;

  // int num_arr[] = {1, 0, 1, 1};
  // const int k = 1;
  // const int t = 2;

  int num_arr[] = {1, 5, 9, 1, 5, 9};
  const int k = 2;
  const int t = 3;

  my_func(num_arr, sizeof(num_arr) / sizeof(int), k, t);
}
