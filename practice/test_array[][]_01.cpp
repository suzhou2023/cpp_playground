#include <iostream>
using namespace std;

// 二维数组及其指针相关
int main()
{
  // 不要改变元素值，否则下面的用例答案就不对了
  int table[4][4] = {
      {11, 12, 13, 14},
      {15, 16, 17, 18},
      {21, 22, 23, 24},
      {31, 32, 33, 34},
  };

  cout << "table length: " << sizeof(table) / sizeof(int) << endl;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << " " << table[i][j];
    }
    cout << endl;
  }

  cout << "table[0] length: " << sizeof(table[0]) / sizeof(int) << endl;

  cout << "sizeof(*table): " << sizeof(*table) << endl;

  // 二维数组元素的指针
  int *ptr = &table[2][3];
  cout << *(ptr - 7) << endl; // 15

  // 指向长度为4的一维数组的指针
  int(*ptr2)[4] = &table[1];
  cout << (*++ptr2)[2] << endl; // 23

  // 指向4x4的二维数组的指针
  int(*ptr3)[4][4] = &table;
  cout << (**ptr3)[2] << endl; // 13
  // 二维数组名字相当于一维数组的指针
  cout << (*table)[3] << endl; // 14
  // 仔细看看为什么是33，有点绕
  cout << (**++ptr3 - 3)[1] << endl; // 33
}
