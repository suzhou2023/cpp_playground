#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度
// 输入: s = "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3

int my_func(const string str)
{
  int l = 0, r = 0;
  unordered_set<char> set;
  int max_len = 0;

  while (r < str.length())
  {
    if (set.find(str[r]) == set.end())
    {
      set.insert(str[r]);
      max_len = max<int>(max_len, set.size());
    }

    while (set.size() < r - l + 1)
    {
      if (str[r] != str[l])
        set.erase(str[l]);
      l++;
    }

    r++;
  }

  return max_len;
}

int main()
{
  string str;
  unordered_set<char> window;
  int left, right = 0;
  int maxSubLen = 0;

  while (getline(cin, str))
  {
    cout << my_func(str) << endl;
  }
}