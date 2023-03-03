#include <iostream>
#include "../algorithm/sort/sort.h"

using namespace std;

int main()
{
  int arr[10] = {20, 34, 12, 98, 23, 56, 79, 100, 65, 23};
  quick_sort(arr, sizeof(arr) / sizeof(arr[0]));
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    cout << arr[i] << endl;
}
