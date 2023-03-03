#include "sort.h"

void bubble_sort(int arr[], int len)
{
  int tmp;
  // 以数组长度从len到2进行循环
  // 每冒泡一次，相当于数组长度减小了1
  // 数组长度>=2才需要排序
  for (int i = len; i >= 2; i--)
  {
    for (int j = 0; j <= i - 2; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

// 递归写法
void bubble_sort_recurse(int arr[], int len)
{
  if (len < 2)
    return;

  int tmp;
  for (int j = 0; j <= len - 2; j++)
  {
    if (arr[j] > arr[j + 1])
    {
      tmp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = tmp;
    }
  }
  bubble_sort_recurse(arr, len - 1);
}