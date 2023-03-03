#include "sort.h"

int sort_once(int arr[], int low, int high)
{
  int base = arr[low];
  while (low < high)
  {
    while (low < high && arr[high] >= base)
      high--;
    arr[low] = arr[high];
    while (low < high && arr[low] <= base)
      low++;
    arr[high] = arr[low];
  }
  arr[low] = base;
  return low;
}

void quick_sort_recurse(int arr[], int low, int high)
{
  if (low >= high)
    return;
  int index = sort_once(arr, low, high);
  quick_sort_recurse(arr, 0, index - 1);
  quick_sort_recurse(arr, index + 1, high);
}

void quick_sort(int arr[], int len)
{
  quick_sort_recurse(arr, 0, len - 1);
}