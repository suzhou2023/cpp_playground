#include <iostream>
#include <unordered_set>

using namespace std;

// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
// 满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false

// 示例 1：
// 输入：nums = [1,2,3,1], k = 3
// 输出：true
// 示例 2：
// 输入：nums = [1,0,1,1], k = 1
// 输出：true
// 示例 3：
// 输入：nums = [1,2,3,1,2,3], k = 2
// 输出：false

void my_func(const int num_arr[], const int len, const int k)
{
  int sum = 0;
  int l = 0, r = 0;
  unordered_set<int> set;

  while (r < len)
  {
    // 一开始窗口大小满足条件
    // 后续窗口大小也满足条件
    // 所有有相同元素直接返回true
    if (set.find(num_arr[r]) != set.end())
    {
      cout << "true" << endl;
      return;
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
  // const int k = 7;

  int num_arr[] = {1, 0, 1, 1};
  const int k = 1;

  // int num_arr[] = {1, 2, 3, 1, 2, 3};
  // const int k = 2;

  my_func(num_arr, sizeof(num_arr) / sizeof(int), k);
}
