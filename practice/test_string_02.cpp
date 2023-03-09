#include <iostream>
#include <string>

using namespace std;

// 写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

int main()
{
  string input_str;
  char c;

  while (getline(cin, input_str))
  {
    if (input_str.length() <= 0)
      continue;

    cin >> c;
    c = tolower(c);

    int count = 0;

    for (int i = 0; i < input_str.length(); i++)
    {
      if (tolower(input_str[i]) == c)
        count++;
    }

    cout << count << endl;
  }
}
