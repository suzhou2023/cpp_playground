#include <iostream>
using namespace std;
// 计算字符串最后一个单词长度
// 字符串不能为空字符结尾

int main()
{
  string input_str;

  while (getline(cin, input_str))
  {
    if (input_str.length() <= 0)
      continue;

    // c字符串首地址
    const char *const c_str = input_str.c_str();
    const char *p = c_str;
    // p移动到字符串结尾'\0'
    p += input_str.length();

    int len = 0;
    // p往左移动并计数
    while (*--p != ' ' && p >= c_str - 1)
    {
      len++;
    }
    cout << len << endl;
  }
}
